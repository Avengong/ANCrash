//
// Created by Avengong on 2022/8/22.
//


#ifndef ANCRASH_AN_LOG_H
#define ANCRASH_AN_LOG_H

#include <android/log.h>


#define LOG_TAG "ANCrash"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#endif //ANCRASH_AN_LOG_H
