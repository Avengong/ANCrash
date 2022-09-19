//
// Created by Avengong on 2022/9/15.
//
#include "xcrash_xlog.h"

#ifndef ANCRASH_EXCEPTION_HANDLER_H
#define ANCRASH_EXCEPTION_HANDLER_H

//#define LOG_TAG "an_crash"
//
//#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
//#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
//#define ALOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
//#define ALOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
//#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)



int initAnCatch(const char *string);

void sig_handler(int sig, siginfo_t *siginfo, void *uc);


#endif //ANCRASH_EXCEPTION_HANDLER_H
