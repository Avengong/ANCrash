//
// Created by Avengong on 2022/9/17.
//

#ifndef ANCRASH_XCC_UNWIND_H
#define ANCRASH_XCC_UNWIND_H

#include <stdint.h>
#include <sys/types.h>
#include <ucontext.h>


void xcc_unwind_init(int api_level);

size_t xcc_unwind_get(int api_level, siginfo_t *si, ucontext_t *uc, char *buf, size_t len);


#endif //ANCRASH_XCC_UNWIND_H
