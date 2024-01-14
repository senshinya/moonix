#include "types.h"
#include "batch.h"
#include "context.h"
#include "def.h"

void initBatch() {
    extern void _num_app();
    usize *_num_app_ptr = (usize *)_num_app;
    APP_MANAGER.numApp = _num_app_ptr[0];
    APP_MANAGER.currentApp = 0l;
    for (int i = 0; i <= _num_app_ptr[0]; i ++) {
        APP_MANAGER.appStart[i] = _num_app_ptr[i+1];
    }
}

void printAppInfo() {
    printf("[kernel] num_app = %d\n", APP_MANAGER.numApp);
    for (int i = 0; i < APP_MANAGER.numApp; i ++) {
        printf("[kernel] app_%d [0x%x, 0x%x]", i, APP_MANAGER.appStart[i], APP_MANAGER.appStart[i+1]);
    }
}

usize getCurrentApp() {
    return APP_MANAGER.currentApp;
}

void moveToNextApp() {
    APP_MANAGER.currentApp += 1;
}

void loadApp(usize appID) {
    if (appID >= APP_MANAGER.numApp) {
        printf("All applications completed!\n");
        shutdown();
    }
    printf("[kernel] Loading app_%d\n", appID);
    // clear and app area
    for (usize i = APP_BASE_ADDRESS; i < APP_BASE_ADDRESS+APP_SIZE_LIMIT; i ++) {
        *(uint8 *)i = 0;
    }
    for (usize i = 0; i < APP_MANAGER.appStart[appID+1]-APP_MANAGER.appStart[appID]; i ++) {
        *(uint8 *)(APP_BASE_ADDRESS+i) = *(uint8 *)(APP_MANAGER.appStart[appID]+i);
    }
    asm("fence.i");
}

TrapContext *pushContextIntoKernelStack(TrapContext ctx) {
    TrapContext *ctx_ptr = (TrapContext *)(getKernelStackSp() - sizeof(TrapContext));
    *ctx_ptr = ctx;
    return ctx_ptr;
}

void runNextApp() {
    usize current = getCurrentApp();
    loadApp(current);
    moveToNextApp();

    extern void __restore(usize sp);
    TrapContext ctx;

    __restore((usize)pushContextIntoKernelStack(newAppInitContext(APP_BASE_ADDRESS, getUserStackSp())));
}