#include "ia32_insn.h"

#include "ia32_reg.h"

#include "ia32_opcode_tables.h"

static ia32_insn_t tbl_Main[] = {    /* One-byte Opcodes */
        {0,      INS_ADD,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,
                                                                                             ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "add",   "", 0, 0, 0,
                                                                                                                                                                             INS_SET_ALL,  0},
        {0,      INS_ADD,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "add",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_ADD,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "add",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_ADD,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "add",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_ADD,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "add",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_ADD,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "add",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RS |
                                                                                  OPTYPE_w |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     0,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RS |
                                                                                  OPTYPE_w |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     0,  0, 0,                                                                  0,                                33},
        {0,      INS_OR,        0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "or",    "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_OR,        0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "or",    "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_OR,        0,                                                ADDRMETH_G |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "or",    "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_OR,        0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "or",    "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_OR,        0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "or",    "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_OR,        0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "or",    "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RS |
                                                                                  OPTYPE_w |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     1,  0, 0,                                                                  0,                                33},
        {idx_0F, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
/* 0x10 */
        {0,      INS_ADD,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "adc",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_ADD,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "adc",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_ADD,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "adc",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_ADD,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "adc",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_ADD,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "adc",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_ADD,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "adc",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RS |
                                                                                  OPTYPE_w |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     2,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RS |
                                                                                  OPTYPE_w |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     2,  0, 0,                                                                  0,                                33},
        {0,      INS_SUB,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sbb",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_SUB,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sbb",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_SUB,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_SIGNED | OP_R,
                                                                                             ADDRMETH_E |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sbb",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_SUB,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sbb",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_SUB,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sbb",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_SUB,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sbb",   "", 0, 0, 0,                                INS_SET_ALL |
                                                                                                                                                                             INS_TEST_CARRY, 0},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RS |
                                                                                  OPTYPE_w |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     3,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RS |
                                                                                  OPTYPE_w |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     3,  0, 0,                                                                  0,                                33},
/* 0x20 */
        {0,      INS_AND,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "and",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_AND,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "and",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_AND,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "and",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_AND,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "and",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_AND,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "and",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_AND,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "and",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_FLAG_PREFIX |
                 PREFIX_ES,                                     0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_BCDCONV,   0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "daa",   "",      0,  0, 0, INS_SET_SIGN |
                                                                                                                                           INS_SET_ZERO |
                                                                                                                                           INS_SET_CARRY |
                                                                                                                                           INS_SET_PARITY |
                                                                                                                                           INS_TEST_CARRY,                   12},
        {0,      INS_SUB,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sub",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_SUB,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sub",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_SUB,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_b |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sub",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_SUB,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sub",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_SUB,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sub",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_SUB,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_SIGNED | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "sub",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_FLAG_PREFIX | PREFIX_CS |
                 PREFIX_NOTTAKEN,                               0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_BCDCONV,   0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "das",   "",      0,  0, 0, INS_SET_SIGN |
                                                                                                                                           INS_SET_ZERO |
                                                                                                                                           INS_SET_CARRY |
                                                                                                                                           INS_SET_PARITY |
                                                                                                                                           INS_TEST_CARRY,                   0},
/* 0x30 */
        {0,      INS_XOR,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xor",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_XOR,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xor",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_XOR,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xor",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_XOR,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xor",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_XOR,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xor",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_XOR,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xor",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_FLAG_PREFIX |
                 PREFIX_SS,                                     0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_BCDCONV,   0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "aaa",   "",      0,  0, 0, INS_SET_CARRY,  1},
        {0,      INS_CMP,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "cmp",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_CMP,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v | OP_R,
                                                                                             ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "cmp",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_CMP,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_E |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "cmp",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_CMP,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_R,
                                                                                             ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "cmp",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_CMP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "cmp",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_CMP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "cmp",   "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_FLAG_PREFIX | PREFIX_DS |
                 PREFIX_TAKEN,                                  0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_BCDCONV,   0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "aas",   "",      0,  0, 0, INS_SET_CARRY,  0},
/* 0x40 */
        {0,      INS_INC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "inc",              "",     0,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_INC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "inc",              "",     1,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_INC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "inc",              "",     2,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_INC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "inc",              "",     3,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_INC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "inc",              "",     4,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_INC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "inc",              "",     5,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_INC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "inc",              "",     6,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_INC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "inc",              "",     7,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_DEC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "dec",              "",     0,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_DEC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "dec",              "",     1,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_DEC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "dec",              "",     2,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_DEC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "dec",              "",     3,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_DEC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "dec",              "",     4,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_DEC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "dec",              "",     5,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_DEC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "dec",              "",     6,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_DEC,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "dec",              "",     7,  0, 0,                                                                                  INS_SET_OFLOW |
                                                                                                                                                           INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
/* 0x50 */
        {0,      INS_PUSH,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     0,  0, 0,                                                                  0,                                33},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     1,  0, 0,                                                                  0,                                33},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     2,  0, 0,                                                                  0,                                33},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     3,  0, 0,                                                                  0,                                33},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     4,  0, 0,                                                                  0,                                33},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     5,  0, 0,                                                                  0,                                33},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     6,  0, 0,                                                                  0,                                33},
        {0,      INS_PUSH,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     7,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     0,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     1,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     2,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     3,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     4,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     5,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     6,  0, 0,                                                                  0,                                33},
        {0,      INS_POP,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     7,  0, 0,                                                                  0,                                33},
/* 0x60 */
        {0,      INS_PUSHREGS,  0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "pusha", "",      0,  0, 0, 0,              36},
        {0,      INS_POPREGS,   0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "popa",  "",      0,  0, 0, 0,              34},
        {0,      INS_BOUNDS,                                    INS_NOTE_NONSWAP, ADDRMETH_G |
                                                                                  OPTYPE_v | OP_R,
                                                                                             ADDRMETH_M |
                                                                                             OPTYPE_a |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "bound", "", 0, 0, 0,              0,                              0},
        {0,      INS_SYSTEM,    0,                                                ADDRMETH_E |
                                                                                  OPTYPE_w | OP_R |
                                                                                  OP_W,      ADDRMETH_G |
                                                                                             OPTYPE_w |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "arpl",  "", 0, 0, 0,                                INS_SET_ZERO, 0},
        {0,      INS_FLAG_PREFIX |
                 PREFIX_FS,                                     0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_FLAG_PREFIX |
                 PREFIX_GS,                                     0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {idx_66, INS_FLAG_PREFIX |
                 PREFIX_OP_SIZE,                                0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_FLAG_PREFIX |
                 PREFIX_ADDR_SIZE,                              0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_PUSH,      0,                                                ADDRMETH_I |
                                                                                  OPTYPE_v |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     0,  0, 0,                                                                  0,                                33},
        {0,      INS_MUL,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v |
                                                                                  OP_SIGNED | OP_R |
                                                                                  OP_W,      ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ADDRMETH_I |
                                                                                                       OPTYPE_v |
                                                                                                       OP_SIGNED |
                                                                                                       OP_R,
                                    cpu_80386 |
                                    isa_GP,             "imul", "", 0, 0,                                                                  0,                                              INS_SET_OFLOW |
                                                                                                                                                                                           INS_SET_CARRY, 0},
        {0,      INS_PUSH,      0,                                                ADDRMETH_I |
                                                                                  OPTYPE_b |
                                                                                  OP_SIGNED |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "push",             "",     0,  0, 0,                                                                  0,                                33},
        {0,      INS_MUL,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v |
                                                                                  OP_SIGNED | OP_R |
                                                                                  OP_W,      ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_SIGNED |
                                                                                             OP_R,     ADDRMETH_I |
                                                                                                       OPTYPE_b |
                                                                                                       OP_SIGNED |
                                                                                                       OP_R,
                                    cpu_80386 |
                                    isa_GP,             "imul", "", 0, 0,                                                                  0,                                              INS_SET_OFLOW |
                                                                                                                                                                                           INS_SET_CARRY, 0},
        {0,      INS_IN,        0,                                                ADDRMETH_Y |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "ins",   "", 0, 2, 0,              0,                              0},
        {0,      INS_IN,        0,                                                ADDRMETH_Y |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "ins",   "", 0, 2, 0,              0,                              0},
        {0,      INS_OUT,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_X |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "outs",  "", 2, 0, 0,              0,                              0},
        {0,      INS_OUT,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R,
                                                                                             ADDRMETH_X |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "outs",  "", 2, 0, 0,              0,                              0},
/* 0x70 */
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jo",               "",     0,  0, 0,                                                                                  INS_TEST_OFLOW,   0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jno",              "",     0,  0, 0,                                                                                  INS_TEST_NOFLOW,  0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jc",               "",     0,  0, 0,                                                                                  INS_TEST_CARRY,   0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jnc",              "",     0,  0, 0,                                                                                  INS_TEST_NCARRY,  0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jz",               "",     0,  0, 0,                                                                                  INS_TEST_ZERO,    0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jnz",              "",     0,  0, 0,                                                                                  INS_TEST_NZERO,   0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jbe",              "",     0,  0, 0,                                                                                  INS_TEST_CARRY |
                                                                                                                                                           INS_TEST_OR |
                                                                                                                                                           INS_TEST_ZERO,                  0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "ja",               "",     0,  0, 0,                                                                                  INS_TEST_NCARRY |
                                                                                                                                                           INS_TEST_NZERO,                 0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "js",               "",     0,  0, 0,                                                                                  INS_TEST_SIGN,    0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jns",              "",     0,  0, 0,                                                                                  INS_TEST_NSIGN,   0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jpe",              "",     0,  0, 0,                                                                                  INS_TEST_PARITY,  0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jpo",              "",     0,  0, 0,                                                                                  INS_TEST_NPARITY, 0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jl",               "",     0,  0, 0,                                                                                  INS_TEST_SFNEOF,  0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jge",              "",     0,  0, 0,                                                                                  INS_TEST_SFEQOF,  0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jle",              "",     0,  0, 0,                                                                                  INS_TEST_ZERO |
                                                                                                                                                           INS_TEST_OR |
                                                                                                                                                           INS_TEST_SFNEOF,                0},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jg",               "",     0,  0, 0,                                                                                  INS_TEST_NZERO |
                                                                                                                                                           INS_TEST_SFEQOF,                0},
/* 0x80 */
        {idx_80, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b,  ADDRMETH_I |
                                                                                             OPTYPE_b, ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "",      "", 0, 0, 0,              0,                              0},
        {idx_81, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v,  ADDRMETH_I |
                                                                                             OPTYPE_v, ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "",      "", 0, 0, 0,              0,                              0},
        {idx_82, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b,  ADDRMETH_I |
                                                                                             OPTYPE_b, ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "",      "", 0, 0, 0,              0,                              0},
        {idx_83, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v,  ADDRMETH_I |
                                                                                             OPTYPE_b, ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "",      "", 0, 0, 0,              0,                              0},
        {0,      INS_TEST,      0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "test",  "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_TEST,      0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v | OP_R,
                                                                                             ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "test",  "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_XCHG,      0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_W |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xchg",  "", 0, 0, 0,              0,                              0},
        {0,      INS_XCHG,      0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_W |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xchg",  "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_G |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_G |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_E |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_E |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_w | OP_W,
                                                                                             ADDRMETH_S |
                                                                                             OPTYPE_w |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_M |
                                                                                             OPTYPE_m |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "lea",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_S |
                                                                                  OPTYPE_w | OP_W,
                                                                                             ADDRMETH_E |
                                                                                             OPTYPE_w |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_POP,       0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v |
                                                                                  OP_W,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "pop",              "",     0,  0, 0,                                                                  0,                                33},
/* 0x90 */
        {0,      INS_NOP,       0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "nop",   "",      0,  0, 0, 0,              0},
        {0,      INS_XCHG,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_W |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xchg",  "", 0, 1, 0,              0,                              0},
        {0,      INS_XCHG,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_W |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xchg",  "", 0, 2, 0,              0,                              0},
        {0,      INS_XCHG,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_W |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xchg",  "", 0, 3, 0,              0,                              0},
        {0,      INS_XCHG,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_W |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xchg",  "", 0, 4, 0,              0,                              0},
        {0,      INS_XCHG,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_W |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xchg",  "", 0, 5, 0,              0,                              0},
        {0,      INS_XCHG,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_W |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xchg",  "", 0, 6, 0,              0,                              0},
        {0,      INS_XCHG,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W |
                                                                                  OP_R,      ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_W |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "xchg",  "", 0, 7, 0,              0,                              0},
        {0,      INS_SZCONV,    0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "cwde",  "",      0,  0, 0, 0,              5},
        {0,      INS_SZCONV,    0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "cdq",   "",      0,  0, 0, 0,              11},
        {0,      INS_CALL,      0,                                                ADDRMETH_A |
                                                                                  OPTYPE_p |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "callf",            "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_SYSTEM,    0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "wait",  "",      0,  0, 0, 0,              0},
        {0,      INS_PUSHFLAGS, 0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "pushf", "",      0,  0, 0, 0,              37},
        {0,      INS_POPFLAGS,  0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "popf",  "",      0,  0, 0, 0,              35},
        {0,      INS_MOV,       0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "sahf",  "",      0,  0, 0, INS_SET_SIGN |
                                                                                                                                           INS_SET_ZERO |
                                                                                                                                           INS_SET_PARITY |
                                                                                                                                           INS_SET_CARRY,                    43},
        {0,      INS_MOV,       0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "lahf",  "",      0,  0, 0, 0,              24},
/* 0xa0 */
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_O |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_O |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_O |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_O |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_STRMOV,    0,                                                ADDRMETH_Y |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_X |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "movs",  "", 0, 0, 0,              0,                              0},
        {0,      INS_STRMOV,    0,                                                ADDRMETH_Y |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_X |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "movs",  "", 0, 0, 0,              0,                              0},
        {0,      INS_STRCMP,    0,                                                ADDRMETH_Y |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_X |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "cmps",  "", 0, 0, 0,              0,                              0},
        {0,      INS_STRCMP,    0,                                                ADDRMETH_X |
                                                                                  OPTYPE_v | OP_R,
                                                                                             ADDRMETH_Y |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "cmps",  "", 0, 0, 0,              0,                              0},
        {0,      INS_TEST,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "test",  "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_TEST,      0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "test",  "", 0, 0, 0,                                INS_SET_ALL,  0},
        {0,      INS_STRSTOR,   0,                                                ADDRMETH_Y |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "stos",  "", 0, 0, 0,              0,                              0},
        {0,      INS_STRSTOR,   0,                                                ADDRMETH_Y |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "stos",  "", 0, 0, 0,              0,                              0},
        {0,      INS_STRLOAD,   0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_X |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "lods",  "", 0, 0, 0,              0,                              0},
        {0,      INS_STRLOAD,   0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_X |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "lods",  "", 0, 0, 0,              0,                              0},
        {0,      INS_STRCMP,    0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_Y |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "scas",  "", 0, 0, 0,              0,                              0},
        {0,      INS_STRCMP,    0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_R,
                                                                                             ADDRMETH_Y |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "scas",  "", 0, 0, 0,              0,                              0},
/* 0xb0 */
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 1, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 2, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 3, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 4, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 5, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 6, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 7, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 1, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 2, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 3, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 4, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 5, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 6, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "mov",   "", 7, 0, 0,              0,                              0},
/* 0xc0 */
        {idx_C0, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b,  ADDRMETH_I |
                                                                                             OPTYPE_b, ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "",      "", 0, 0, 0,              0,                              0},
        {idx_C1, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v,  ADDRMETH_I |
                                                                                             OPTYPE_b, ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "",      "", 0, 0, 0,              0,                              0},
        {0,      INS_RET,       0,                                                ADDRMETH_I |
                                                                                  OPTYPE_w |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "ret",              "",     0,  0, 0,                                                                  0,                                3},
        {0,      INS_RET,       0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "ret",   "",      0,  0, 0, 0,              3},
        {0,      INS_MOV,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_M |
                                                                                             OPTYPE_p |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "les",   "", 0, 0, 0,              0,                              0},
        {0,      INS_MOV,       0,                                                ADDRMETH_G |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_M |
                                                                                             OPTYPE_p |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "lds",   "", 0, 0, 0,              0,                              0},
        {idx_C6, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {idx_C7, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {0,      INS_ENTER,                                     INS_NOTE_NONSWAP, ADDRMETH_I |
                                                                                  OPTYPE_w | OP_R,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "enter", "", 0, 0, 0,              0,                              15},
        {0,      INS_LEAVE,     0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "leave", "",      0,  0, 0, 0,              26},
        {0,      INS_RET,       0,                                                ADDRMETH_I |
                                                                                  OPTYPE_w |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "retf",             "lret", 0,  0, 0,                                                                  0,                                3},
        {0,      INS_RET,       0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "retf",  "lret",  0,  0, 0, 0,              3},
        {0,      INS_DEBUG,     0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "int3",  "",      0,  0, 0, 0,              0},
        {0,      INS_TRAP,      0,                                                ADDRMETH_I |
                                                                                  OPTYPE_b |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "int",              "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_OFLOW,     0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "into",  "",      0,  0, 0, INS_TEST_OFLOW, 0},
        {0,      INS_TRET,      0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "iret",  "",      0,  0, 0, INS_SET_ALL |
                                                                                                                                           INS_SET_DIR,                      0},
/* 0xd0 */
        {idx_D0, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b,  ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  1, 0,                                                                  0,                                0},
        {idx_D1, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v,  ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  1, 0,                                                                  0,                                0},
        {idx_D2, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b,  ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  1, 0,                                                                  0,                                0},
        {idx_D3, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v,  ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  1, 0,                                                                  0,                                0},
        {0,      INS_BCDCONV,   0,                                                ADDRMETH_I |
                                                                                  OPTYPE_b |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "aam",              "",     0,  0, 0,                                                                                  INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 0},
        {0,      INS_BCDCONV,   0,                                                ADDRMETH_I |
                                                                                  OPTYPE_b |
                                                                                  OP_R,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "aad",              "",     0,  0, 0,                                                                                  INS_SET_SIGN |
                                                                                                                                                           INS_SET_ZERO |
                                                                                                                                                           INS_SET_PARITY,                 2},
        {0,      INS_SALC,      0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "salc",  "",      0,  0, 0, 0,              0},
        {0,      INS_XLAT,      0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "xlat",  "",      0,  0, 0, 0,              53},
        {idx_D8, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {idx_D9, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {idx_DA, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {idx_DB, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {idx_DC, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {idx_DD, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {idx_DE, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {idx_DF, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
/* 0xe0 */
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "loopnz",           "",     0,  0, 0,                                                                                  INS_TEST_NZERO,   31},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "loopz",            "",     0,  0, 0,                                                                                  INS_TEST_ZERO,    31},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "loop",             "",     0,  0, 0,                                                                  0,                                31},
        {0,      INS_BRANCHCC,  0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jcxz",             "",     0,  0, 0,                                                                  0,                                31},
        {0,      INS_IN,        0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "in",    "", 0, 0, 0,              0,                              0},
        {0,      INS_IN,        0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_I |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "in",    "", 0, 0, 0,              0,                              0},
        {0,      INS_OUT,       0,                                                ADDRMETH_I |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "out",   "", 0, 0, 0,              0,                              0},
        {0,      INS_OUT,       0,                                                ADDRMETH_I |
                                                                                  OPTYPE_b | OP_R,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "out",   "", 0, 0, 0,              0,                              0},
        {0,      INS_CALL,      0,                                                ADDRMETH_J |
                                                                                  OPTYPE_v | OP_X |
                                                                                  OP_SIGNED, ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "call",             "",     0,  0, 0,                                                                  0,                                3},
        {0,      INS_BRANCH,    0,                                                ADDRMETH_J |
                                                                                  OPTYPE_v | OP_X |
                                                                                  OP_SIGNED, ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jmp",              "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_BRANCH,    0,                                                ADDRMETH_A |
                                                                                  OPTYPE_p |
                                                                                  OP_X,      ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jmp",              "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_BRANCH,    0,                                                ADDRMETH_J |
                                                                                  OPTYPE_b | OP_X |
                                                                                  OP_SIGNED, ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "jmp",              "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_IN,        0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_b | OP_W,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_w |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "in",    "", 0, 2, 0,              0,                              0},
        {0,      INS_IN,        0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_v | OP_W,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_w |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "in",    "", 0, 2, 0,              0,                              0},
        {0,      INS_OUT,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_w | OP_R,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_b |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "out",   "", 2, 0, 0,              0,                              0},
        {0,      INS_OUT,       0,                                                ADDRMETH_RR |
                                                                                  OPTYPE_w | OP_R,
                                                                                             ADDRMETH_RR |
                                                                                             OPTYPE_v |
                                                                                             OP_R,     ARG_NONE,
                                                                                                               cpu_80386 |
                                                                                                               isa_GP,  "out",   "", 2, 0, 0,              0,                              0},
/* 0xf0 */
        {0,      INS_FLAG_PREFIX |
                 PREFIX_LOCK,                                   0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_ICEBP,     0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "icebp", "",      0,  0, 0, 0,              0},
        {idx_F2, INS_FLAG_PREFIX |
                 PREFIX_REPNZ,                                  0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {idx_F3, INS_FLAG_PREFIX |
                 PREFIX_REPZ,                                   0, ARG_NONE,                 ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_HALT,      0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "hlt",   "",      0,  0, 0, 0,              0},
        {0,      INS_TOGCF,     0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "cmc",   "",      0,  0, 0, INS_SET_CARRY,  0},
        {idx_F6, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_b,  ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {idx_F7, 0,             0,                                                ADDRMETH_E |
                                                                                  OPTYPE_v,  ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "",                 "",     0,  0, 0,                                                                  0,                                0},
        {0,      INS_CLEARCF,   0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "clc",   "",      0,  0, 0, INS_SET_NCARRY, 0},
        {0,      INS_SETCF,     0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "stc",   "",      0,  0, 0, INS_SET_CARRY,  0},
        {0,      INS_SYSTEM,    0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "cli",   "",      0,  0, 0, 0,              0},
        {0,      INS_SYSTEM,    0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "sti",   "",      0,  0, 0, 0,              0},
        {0,      INS_CLEARDF,   0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "cld",   "",      0,  0, 0, INS_SET_NDIR,   0},
        {0,      INS_SETDF,     0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "std",   "",      0,  0, 0, INS_SET_DIR,    0},
        {idx_FE, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0},
        {idx_FF, 0,             0,                                                ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                       cpu_80386 |
                                                                                                       isa_GP, "",      "",      0,  0, 0, 0,              0}
};


static ia32_insn_t tbl_66[] = {    /* SIMD 66 one-byte Opcodes */
        {idx_660F, 0, 0, ARG_NONE, ARG_NONE, ARG_NONE, cpu_80386 | isa_GP, "", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_F2[] = {    /* SIMD F2 one-byte Opcodes */
        {idx_F20F, 0, 0, ARG_NONE, ARG_NONE, ARG_NONE, cpu_80386 | isa_GP, "", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_F3[] = {    /* SIMD F3 one-byte Opcodes */
        {idx_F30F, 0,    0, ARG_NONE, ARG_NONE, ARG_NONE,
                                                          cpu_80386 |
                                                          isa_GP,                "",      "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ARG_NONE, ARG_NONE, ARG_NONE, cpu_PENTIUM4 |
                                                          isa_GP,                "pause", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_0F[] = {    /* Two-byte Opcodes */
        {idx_0F00, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                                   cpu_80386 |
                                                                                                   isa_GP,    "",         "",          0,  0, 0, 0, 0},
        {idx_0F01, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80386 |
                                                                                                   isa_GP,    "",         "",          0,  0, 0, 0, 0},
        {0,        INS_SYSTEM,      0,         ADDRMETH_G | OPTYPE_v | OP_W,             ADDRMETH_E |
                                                                                         OPTYPE_w |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "lar",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_SYSTEM,      0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_w |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "lsl",       "", 0, 0, 0,                   INS_SET_ZERO,     0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80386 |
                                                                                                   isa_GP,    "clts",     "",          0,  0, 0, 0, 6},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80486 |
                                                                                                   isa_GP,    "invd",     "",          0,  0, 0, 0, 0},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80486 |
                                                                                                   isa_GP,    "wbinvd",   "",          0,  0, 0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80386 |
                                                                                                   isa_GP,    "",         "",          0,  0, 0, 0, 0},
        {0,        INS_UNKNOWN,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTPRO |
                                                                                                   isa_GP,    "ud2",      "",          0,  0, 0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_SYSTEM,      0,         ADDRMETH_M | OPTYPE_b |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_K6 |
                                                                                                      isa_3DNOW, "prefetch",  "",       0,  0, 0, 0,                  0},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_K6 |
                                                                                                   isa_3DNOW, "femms",    "",          0,  0, 0, 0, 0},
        {idx_0F0F, INS_FLAG_SUFFIX, 0,         ADDRMETH_P | OPTYPE_pi | OP_R |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_K6 |
                                                                                                              isa_3DNOW,  "",          "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "movups",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_W | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_V |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "movups",    "", 0, 0, 0, 0,                                  0},
        {idx_0F12, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80386 |
                                                                                                   isa_GP,    "",         "",          0,  0, 0, 0, 0},
        {0,        INS_MOV, INS_NOTE_NOSUFFIX, ADDRMETH_V | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "movlps",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "unpcklps",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "unpckhps",  "", 0, 0, 0, 0,                                  0},
        {idx_0F16, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80386 |
                                                                                                   isa_GP,    "",         "",          0,  0, 0, 0, 0},
        {0,        INS_OTHER,       0,         ADDRMETH_W | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_V |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "movhps",    "", 0, 0, 0, 0,                                  0},
        {idx_0F18, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80386 |
                                                                                                   isa_GP,    "",         "",          0,  0, 0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_MOV,         0,         ADDRMETH_R | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_C |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "mov",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_R | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_D |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "mov",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_C | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_R |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "mov",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_D | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_R |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "mov",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_R | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_T |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "mov",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_MOV,         0,         ADDRMETH_T | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_R |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "mov",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_MOV,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "movaps",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_W | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_V |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "movaps",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "cvtpi2ps",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_W | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_V |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "movntps",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "cvttps2pi", "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "cvtps2pi",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_V | OPTYPE_ss |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ss |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "ucomiss",   "", 0, 0, 0,                   INS_SET_ALL,      0},
        {0,        INS_OTHER,       0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ss |
                                                                                         OP_W,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "comiss",    "", 0, 0, 0,                   INS_SET_ALL,      0},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM |
                                                                                                   isa_GP,    "wrmsr",    "",          0,  0, 0, 0, 52},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM |
                                                                                                   isa_GP,    "rdtsc",    "",          0,  0, 0, 0, 40},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM |
                                                                                                   isa_GP,    "rdmsr",    "",          0,  0, 0, 0, 38},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTPRO |
                                                                                                   isa_GP,    "rdpmc",    "",          0,  0, 0, 0, 39},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM2 |
                                                                                                   isa_GP,    "sysenter", "",          0,  0, 0, 0, 50},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM2 |
                                                                                                   isa_GP,    "sysexit",  "",          0,  0, 0, 0, 51},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovo",     "", 0, 0, 0,                   INS_TEST_OFLOW,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovno",    "", 0, 0, 0,                   INS_TEST_NOFLOW,  0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovc",     "", 0, 0, 0,                   INS_TEST_CARRY,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovnc",    "", 0, 0, 0,                   INS_TEST_NCARRY,  0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovz",     "", 0, 0, 0,                   INS_TEST_ZERO,    0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovnz",    "", 0, 0, 0,                   INS_TEST_NZERO,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovbe",    "", 0, 0, 0,                   INS_TEST_CARRY |
                                                                                                                                                                      INS_TEST_OR |
                                                                                                                                                                      INS_TEST_ZERO,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmova",     "", 0, 0, 0,                   INS_TEST_NZERO |
                                                                                                                                                                      INS_TEST_NCARRY, 0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovs",     "", 0, 0, 0,                   INS_TEST_SIGN,    0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovns",    "", 0, 0, 0,                   INS_TEST_NSIGN,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovp",     "", 0, 0, 0,                   INS_TEST_PARITY,  0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovnp",    "", 0, 0, 0,                   INS_TEST_NPARITY, 0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovl",     "", 0, 0, 0,                   INS_TEST_SFNEOF,  0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovge",    "", 0, 0, 0,                   INS_TEST_SFEQOF,  0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovle",    "", 0, 0, 0,                   INS_TEST_ZERO |
                                                                                                                                                                      INS_TEST_OR |
                                                                                                                                                                      INS_TEST_SFNEOF, 0},
        {0,        INS_MOVCC,       0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTPRO |
                                                                                                              isa_GP,     "cmovg",     "", 0, 0, 0,                   INS_TEST_NZERO |
                                                                                                                                                                      INS_TEST_SFEQOF, 0},
        {0,        INS_MOV,         0,         ADDRMETH_G | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "movmskps",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_ARITH,       0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "sqrtps",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_ARITH,       0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "rsqrtps",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "rcpps",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_AND,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "andps",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_AND,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "andnps",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_OR,          0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "orps",      "", 0, 0, 0, 0,                                  0},
        {0,        INS_XOR,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "xorps",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "addps",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_MUL,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_R,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "mulps",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_V |
                                               OPTYPE_pd,                                ADDRMETH_W |
                                                                                         OPTYPE_q, ARG_NONE,  cpu_PENTIUM4 |
                                                                                                              isa_GP,     "cvtps2pd",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_dq |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM4 |
                                                                                                              isa_GP,     "cvtdq2ps",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_SUB,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "subps",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_ARITH,       0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "minps",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_DIV,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "divps",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_ARITH,       0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "maxps",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "punpcklbw", "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "punpcklwd", "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "punpckldq", "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "packsswb",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pcmpgtb",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pcmpgtw",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pcmpgtd",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "packuswb",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "punpckhbw", "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "punpckhwd", "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "punpckhdq", "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "packssdw",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_MOV,         0,         ADDRMETH_P | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "movd",      "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "movq",      "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ADDRMETH_I |
                                                                                                   OPTYPE_b |
                                                                                                   OP_R,         cpu_PENTIUM2 |
                                                                                                                 isa_GP,      "pshufw", "", 0, 0, 0,                  0,               0},
        {idx_0F71, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM |
                                                                                                   isa_MMX,   "",         "",          0,  0, 0, 0, 0},
        {idx_0F72, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM |
                                                                                                   isa_MMX,   "",         "",          0,  0, 0, 0, 0},
        {idx_0F73, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM |
                                                                                                   isa_MMX,   "",         "",          0,  0, 0, 0, 0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pcmpeqb",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_CMP,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pcmpeqw",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_CMP,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pcmpeqd",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM |
                                                                                                   isa_MMX,   "emms",     "",          0,  0, 0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_MOV,         0,         ADDRMETH_E | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_P |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "movd",      "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_Q | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_P |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "movq",      "", 0, 0, 0, 0,                                  0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jo",        "",       0,  0, 0,   INS_TEST_OFLOW,   0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jno",       "",       0,  0, 0,   INS_TEST_NOFLOW,  0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jc",        "",       0,  0, 0,   INS_TEST_CARRY,   0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jnc",       "",       0,  0, 0,   INS_TEST_NCARRY,  0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jz",        "",       0,  0, 0,   INS_TEST_ZERO,    0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jnz",       "",       0,  0, 0,   INS_TEST_NZERO,   0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jbe",       "",       0,  0, 0,   INS_TEST_CARRY |
                                                                                                                                                    INS_TEST_OR |
                                                                                                                                                    INS_TEST_ZERO,                      0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "ja",        "",       0,  0, 0,   INS_TEST_NCARRY |
                                                                                                                                                    INS_TEST_NZERO,                     0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "js",        "",       0,  0, 0,   INS_TEST_SIGN,    0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jns",       "",       0,  0, 0,   INS_TEST_NSIGN,   0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jpe",       "",       0,  0, 0,   INS_TEST_PARITY,  0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jpo",       "",       0,  0, 0,   INS_TEST_NPARITY, 0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jl",        "",       0,  0, 0,   INS_TEST_SFNEOF,  0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jge",       "",       0,  0, 0,   INS_TEST_SFEQOF,  0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jle",       "",       0,  0, 0,   INS_TEST_ZERO |
                                                                                                                                                    INS_TEST_OR |
                                                                                                                                                    INS_TEST_SFNEOF,                    0},
        {0,        INS_BRANCHCC,    0,         ADDRMETH_J | OPTYPE_v | OP_X |
                                               OP_SIGNED,                                ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "jg",        "",       0,  0, 0,   INS_TEST_NZERO |
                                                                                                                                                    INS_TEST_SFEQOF,                    0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "seto",      "",       0,  0, 0,   INS_TEST_OFLOW,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setno",     "",       0,  0, 0,   INS_TEST_OFLOW,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setc",      "",       0,  0, 0,   INS_TEST_CARRY,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setnc",     "",       0,  0, 0,   INS_TEST_NCARRY,  0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setz",      "",       0,  0, 0,   INS_TEST_ZERO,    0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setnz",     "",       0,  0, 0,   INS_TEST_NZERO,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setbe",     "",       0,  0, 0,   INS_TEST_CARRY |
                                                                                                                                                    INS_TEST_OR |
                                                                                                                                                    INS_TEST_ZERO,                      0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "seta",      "",       0,  0, 0,   INS_TEST_NCARRY |
                                                                                                                                                    INS_TEST_NZERO,                     0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "sets",      "",       0,  0, 0,   INS_TEST_SIGN,    0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setns",     "",       0,  0, 0,   INS_TEST_NSIGN,   0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setpe",     "",       0,  0, 0,   INS_TEST_PARITY,  0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setpo",     "",       0,  0, 0,   INS_TEST_NPARITY, 0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setl",      "",       0,  0, 0,   INS_TEST_SFNEOF,  0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setge",     "",       0,  0, 0,   INS_TEST_SFEQOF,  0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setle",     "",       0,  0, 0,   INS_TEST_ZERO |
                                                                                                                                                    INS_TEST_OR |
                                                                                                                                                    INS_TEST_SFNEOF,                    0},
        {0,        INS_MOVCC,       0,         ADDRMETH_E | OPTYPE_b |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "setg",      "",       0,  0, 0,   INS_TEST_NZERO |
                                                                                                                                                    INS_TEST_SFEQOF,                    0},
        {0,        INS_PUSH,        0,         ADDRMETH_RS | OPTYPE_w |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "push",      "",       4,  0, 0, 0,                  33},
        {0,        INS_POP,         0,         ADDRMETH_RS | OPTYPE_w |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "pop",       "",       4,  0, 0, 0,                  33},
        {0,        INS_CPUID,       0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM |
                                                                                                   isa_GP,    "cpuid",    "",          0,  0, 0, 0, 10},
        {0,        INS_BITTEST,     0,         ADDRMETH_E | OPTYPE_v |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "bt",        "", 0, 0, 0,                   INS_SET_CARRY,    0},
        {0,        INS_SHL,         0,         ADDRMETH_E | OPTYPE_v | OP_W |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ADDRMETH_I |
                                                                                                   OPTYPE_b |
                                                                                                   OP_R,         cpu_80386 |
                                                                                                                 isa_GP,      "shld",   "", 0, 0, 0,                                    INS_SET_SIGN |
                                                                                                                                                                                        INS_SET_ZERO |
                                                                                                                                                                                        INS_SET_PARITY |
                                                                                                                                                                                        INS_SET_CARRY, 0},
        //{ 0,   INS_SHL,  0,   ADDRMETH_E | OPTYPE_v | OP_W | OP_R,   ADDRMETH_G | OPTYPE_v | OP_R,   ADDRMETH_I | OP_R | OPTYPE_b | ADDRMETH_RR,   cpu_80386 | isa_GP,   "shld", "",   0,   0,   1,  INS_SET_SIGN|INS_SET_ZERO|INS_SET_PARITY|INS_SET_CARRY, 0 },
        {0,        INS_SHL,         0,         ADDRMETH_E | OPTYPE_v | OP_W |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ADDRMETH_RR |
                                                                                                   OP_R |
                                                                                                   OPTYPE_b,     cpu_80386 |
                                                                                                                 isa_GP,      "shld",   "", 0, 0, 1,                                    INS_SET_SIGN |
                                                                                                                                                                                        INS_SET_ZERO |
                                                                                                                                                                                        INS_SET_PARITY |
                                                                                                                                                                                        INS_SET_CARRY, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_PUSH,        0,         ADDRMETH_RS | OPTYPE_w |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "push",      "",       5,  0, 0, 0,                  33},
        {0,        INS_POP,         0,         ADDRMETH_RS | OPTYPE_w |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80386 |
                                                                                                      isa_GP,    "pop",       "",       5,  0, 0, 0,                  33},
        {0,        INS_SYSTEM,      0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80386 |
                                                                                                   isa_GP,    "rsm",      "",          0,  0, 0,  INS_SET_ALL |
                                                                                                                                                  INS_SET_DIR,        42},
        {0,        INS_BITTEST,     0,         ADDRMETH_E | OPTYPE_v |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "bts",       "", 0, 0, 0,                   INS_SET_CARRY,    0},
        {0,        INS_SHR,         0,         ADDRMETH_E | OPTYPE_v | OP_W |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ADDRMETH_I |
                                                                                                   OPTYPE_b |
                                                                                                   OP_R,         cpu_80386 |
                                                                                                                 isa_GP,      "shrd",   "", 0, 0, 0,                                    INS_SET_SIGN |
                                                                                                                                                                                        INS_SET_ZERO |
                                                                                                                                                                                        INS_SET_PARITY |
                                                                                                                                                                                        INS_SET_CARRY, 0},
        {0,        INS_SHR,         0,         ADDRMETH_E | OPTYPE_v | OP_W |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ADDRMETH_RR |
                                                                                                   OP_R |
                                                                                                   OPTYPE_b,     cpu_80386 |
                                                                                                                 isa_GP,      "shrd",   "", 0, 0, 1,                                    INS_SET_SIGN |
                                                                                                                                                                                        INS_SET_ZERO |
                                                                                                                                                                                        INS_SET_PARITY |
                                                                                                                                                                                        INS_SET_CARRY, 0},
        {idx_0FAE, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_PENTIUM2 |
                                                                                                   isa_GP,    "",         "",          0,  0, 0, 0, 0},
        {0,        INS_MUL,         0,         ADDRMETH_G | OPTYPE_v | OP_SIGNED | OP_R | OP_W,
                                                                                         ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_SIGNED |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "imul",      "", 0, 0, 0,                   INS_SET_OFLOW |
                                                                                                                                                                      INS_SET_CARRY,},
        {0,        INS_XCHGCC,      0,         ADDRMETH_E | OPTYPE_b | OP_W |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_b |
                                                                                         OP_W,     ARG_NONE,  cpu_80486 |
                                                                                                              isa_GP,     "cmpxchg",   "", 0, 0, 0,                   INS_SET_ALL,      8},
        {0,        INS_XCHGCC,      0,         ADDRMETH_E | OPTYPE_v | OP_W |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_W,     ARG_NONE,  cpu_80486 |
                                                                                                              isa_GP,     "cmpxchg",   "", 0, 0, 0,                   INS_SET_ALL,      7},
        {0,        INS_MOV,         0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_M |
                                                                                         OPTYPE_p |
                                                                                         OP_W,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "lss",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_BITTEST,     0,         ADDRMETH_E | OPTYPE_v |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "btr",       "", 0, 0, 0,                   INS_SET_CARRY,    0},
        {0,        INS_MOV,         0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_M |
                                                                                         OPTYPE_p |
                                                                                         OP_W,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "lfs",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_M |
                                                                                         OPTYPE_p |
                                                                                         OP_W,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "lgs",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_b |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "movzx",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_w |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "movzx",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_UNKNOWN,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80386 |
                                                                                                   isa_GP,    "ud1",      "",          0,  0, 0, 0, 0},
        {idx_0FBA, 0,               0,         ARG_NONE, ARG_NONE, ARG_NONE,                       cpu_80386 |
                                                                                                   isa_GP,    "",         "",          0,  0, 0, 0, 0},
        {0,        INS_BITTEST,     0,         ADDRMETH_E | OPTYPE_v |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "btc",       "", 0, 0, 0,                   INS_SET_CARRY,    0},
        {0,        INS_BITTEST,     0,         ADDRMETH_G | OPTYPE_v | OP_R |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "bsf",       "", 0, 0, 0,                   INS_SET_ZERO,     0},
        {0,        INS_BITTEST,     0,         ADDRMETH_G | OPTYPE_v | OP_R |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_v |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "bsr",       "", 0, 0, 0,                   INS_SET_ZERO,     0},
        {0,        INS_MOV,         0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_b |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "movsx",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_G | OPTYPE_v |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_w |
                                                                                         OP_R,     ARG_NONE,  cpu_80386 |
                                                                                                              isa_GP,     "movsx",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_E | OPTYPE_b | OP_W |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_b |
                                                                                         OP_W,     ARG_NONE,  cpu_80486 |
                                                                                                              isa_GP,     "xadd",      "", 0, 0, 0,                   INS_SET_ALL,      0},
        {0,        INS_ADD,         0,         ADDRMETH_E | OPTYPE_v | OP_W |
                                               OP_R,                                     ADDRMETH_G |
                                                                                         OPTYPE_v |
                                                                                         OP_W,     ARG_NONE,  cpu_80486 |
                                                                                                              isa_GP,     "xadd",      "", 0, 0, 0,                   INS_SET_ALL,      0},
        {0,        INS_CMP,         0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_R,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ADDRMETH_I |
                                                                                                   OPTYPE_b |
                                                                                                   OP_R,         cpu_PENTIUM4 |
                                                                                                                 isa_GP,      "cmpps",  "", 0, 0, 0,                  0,               0},
        {0,        INS_MOV,         0,         ADDRMETH_M | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_G |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM4 |
                                                                                                              isa_GP,     "movnti",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_E |
                                                                                         OPTYPE_d |
                                                                                         OP_R,     ADDRMETH_I |
                                                                                                   OPTYPE_b |
                                                                                                   OP_R,         cpu_PENTIUM2 |
                                                                                                                 isa_GP,      "pinsrw", "", 0, 0, 0,                  0,               0},
        {0,        INS_OTHER,       0,         ADDRMETH_G | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ADDRMETH_I |
                                                                                                   OPTYPE_b |
                                                                                                   OP_R,         cpu_PENTIUM2 |
                                                                                                                 isa_GP,      "pextrw", "", 0, 0, 0,                  0,               0},
        {0,        INS_OTHER,       0,         ADDRMETH_V | OPTYPE_ps |
                                               OP_W,                                     ADDRMETH_W |
                                                                                         OPTYPE_ps |
                                                                                         OP_R,     ADDRMETH_I |
                                                                                                   OPTYPE_b |
                                                                                                   OP_R,         cpu_PENTIUM2 |
                                                                                                                 isa_GP,      "shufps", "", 0, 0, 0,                  0,               0},
        {0,        INS_XCHGCC,      0,         ADDRMETH_M | OPTYPE_q | OP_R |
                                               OP_W,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_PENTIUM |
                                                                                                      isa_GP,    "cmpxchg8b", "",       0,  0, 0, 0,                  9},
        {0,        INS_XCHG,        0,         ADDRMETH_RR | OPTYPE_d | OP_W |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80486 |
                                                                                                      isa_GP,    "bswap",     "",       0,  0, 0, 0,                  0},
        {0,        INS_XCHG,        0,         ADDRMETH_RR | OPTYPE_d | OP_W |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80486 |
                                                                                                      isa_GP,    "bswap",     "",       1,  0, 0, 0,                  0},
        {0,        INS_XCHG,        0,         ADDRMETH_RR | OPTYPE_d | OP_W |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80486 |
                                                                                                      isa_GP,    "bswap",     "",       2,  0, 0, 0,                  0},
        {0,        INS_XCHG,        0,         ADDRMETH_RR | OPTYPE_d | OP_W |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80486 |
                                                                                                      isa_GP,    "bswap",     "",       3,  0, 0, 0,                  0},
        {0,        INS_XCHG,        0,         ADDRMETH_RR | OPTYPE_d | OP_W |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80486 |
                                                                                                      isa_GP,    "bswap",     "",       4,  0, 0, 0,                  0},
        {0,        INS_XCHG,        0,         ADDRMETH_RR | OPTYPE_d | OP_W |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80486 |
                                                                                                      isa_GP,    "bswap",     "",       5,  0, 0, 0,                  0},
        {0,        INS_XCHG,        0,         ADDRMETH_RR | OPTYPE_d | OP_W |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80486 |
                                                                                                      isa_GP,    "bswap",     "",       6,  0, 0, 0,                  0},
        {0,        INS_XCHG,        0,         ADDRMETH_RR | OPTYPE_d | OP_W |
                                               OP_R,                                     ARG_NONE, ARG_NONE,
                                                                                                      cpu_80486 |
                                                                                                      isa_GP,    "bswap",     "",       7,  0, 0, 0,                  0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psrlw",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psrld",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psrlq",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_P | OPTYPE_q | OP_R |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM4 |
                                                                                                              isa_GP,     "paddq",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pmullw",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_OTHER,       0,         ADDRMETH_G | OPTYPE_d |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "pmovmskb",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psubusb",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psubusw",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "pminub",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_AND,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pand",      "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "paddusb",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "paddusw",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_ARITH,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "pmaxub",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_AND,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pandn",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "pavgb",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psraw",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psrad",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "pavgw",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_MUL,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "pmulhuw",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_MUL,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pmulhw",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_MOV, INS_NOTE_NOSUFFIX, ADDRMETH_W | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_V |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "movntq",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_SUB,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psubsb",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_SUB,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psubsw",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_ARITH,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "pminsw",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_OR,          0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "por",       "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "paddsb",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "paddsw",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_ARITH,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "pmaxsw",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_XOR,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pxor",      "", 0, 0, 0, 0,                                  0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psllw",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pslld",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psllq",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_MUL,         0,         ADDRMETH_P | OPTYPE_q | OP_R |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM4 |
                                                                                                              isa_GP,     "pmuludq",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "pmaddwd",   "", 0, 0, 0, 0,                                  0},
        {0,        INS_OTHER,       0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "psadbw",    "", 0, 0, 0, 0,                                  0},
        {0,        INS_MOV,         0,         ADDRMETH_P | OPTYPE_pi |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_pi |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM2 |
                                                                                                              isa_GP,     "maskmovq",  "", 0, 0, 0, 0,                                  0},
        {0,        INS_SUB,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psubb",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_SUB,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psubw",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_SUB,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "psubd",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_SUB,         0,         ADDRMETH_P | OPTYPE_q | OP_R |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM4 |
                                                                                                              isa_GP,     "psubq",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "paddb",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "paddw",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_ADD,         0,         ADDRMETH_P | OPTYPE_q |
                                               OP_W,                                     ADDRMETH_Q |
                                                                                         OPTYPE_q |
                                                                                         OP_R,     ARG_NONE,  cpu_PENTIUM |
                                                                                                              isa_MMX,    "paddd",     "", 0, 0, 0, 0,                                  0},
        {0,        INS_INVALID,     0,         ARG_NONE, ARG_NONE, ARG_NONE,                       0, "",        "",          0,        0,  0, 0, 0}
};


static ia32_insn_t tbl_660F[] = {    /* SIMD 66 Two-byte Opcodes */
        {0,          INS_MOV,     0,             ADDRMETH_V | OPTYPE_pd | OP_R,
                                                                                ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movupd",     "", 0, 0, 0, 0, 0},
        {0,          INS_MOV,     0,             ADDRMETH_W | OPTYPE_pd | OP_R, ADDRMETH_V |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movupd",     "", 0, 0, 0, 0, 0},
        {0,          INS_MOV, INS_NOTE_NOSUFFIX, ADDRMETH_V | OPTYPE_q | OP_R,  ADDRMETH_M |
                                                                                OPTYPE_q |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movlpd",     "", 0, 0, 0, 0, 0},
        {0,          INS_MOV, INS_NOTE_NOSUFFIX, ADDRMETH_M | OPTYPE_q | OP_R,  ADDRMETH_V |
                                                                                OPTYPE_q |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movlpd",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "unpcklpd",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "unpckhpd",   "", 0, 0, 0, 0, 0},
        {0,          INS_MOV, INS_NOTE_NOSUFFIX, ADDRMETH_V | OPTYPE_q | OP_R,  ADDRMETH_M |
                                                                                OPTYPE_q |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movhpd",     "", 0, 0, 0, 0, 0},
        {0,          INS_MOV, INS_NOTE_NOSUFFIX, ADDRMETH_M | OPTYPE_q | OP_R,  ADDRMETH_V |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movhpd",     "", 0, 0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_MOV,     0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movapd",     "", 0, 0, 0, 0, 0},
        {0,          INS_MOV,     0,             ADDRMETH_W | OPTYPE_pd | OP_R, ADDRMETH_V |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movapd",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_Q |
                                                                                OPTYPE_q |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "cvtpi2pd",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_M | OPTYPE_pd | OP_R, ADDRMETH_V |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movntpd",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_P | OPTYPE_q | OP_R,  ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "cvttpd2pi",  "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_P | OPTYPE_q | OP_R,  ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "cvtpd2pi",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_sd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "ucomisd",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_sd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "comisd",     "", 0, 0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_G | OPTYPE_d | OP_R,  ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movmskpd",   "", 0, 0, 0, 0, 0},
        {0,          INS_FSQRT,   0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "sqrtpd",     "", 0, 0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_AND,     0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "andpd",      "", 0, 0, 0, 0, 0},
        {0,          INS_AND,     0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "andnpd",     "", 0, 0, 0, 0, 0},
        {0,          INS_OR,      0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "orpd",       "", 0, 0, 0, 0, 0},
        {0,          INS_XOR,     0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "xorpd",      "", 0, 0, 0, 0, 0},
        {0,          INS_ADD,     0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "addpd",      "", 0, 0, 0, 0, 0},
        {0,          INS_MUL,     0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "mulpd",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_ps | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "cvtpd2ps",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_ps |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "cvtps2dq",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "subpd",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "minpd",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "divpd",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "maxpd",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "punpcklbw",  "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "punpcklwd",  "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "punpckldq",  "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "packsswb",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pcmpgtb",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pcmpgtw",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pcmpgtd",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "packuswb",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "punpckhbw",  "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "punpckhwd",  "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "punpckhdq",  "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "packssdw",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "punpcklqdq", "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "punpckhqdq", "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_d | OP_R,  ADDRMETH_E |
                                                                                OPTYPE_d |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movd",       "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movdqa",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq | OP_R,
                                                                                      ADDRMETH_I |
                                                                                      OPTYPE_b |
                                                                                      OP_R,
                cpu_PENTIUM4 | isa_GP, "pshufd", "", 0, 0, 0, 0, 0},
        {idx_660F71, INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {idx_660F72, INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {idx_660F73, INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pcmpeqb",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pcmpeqw",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pcmpeqd",    "", 0, 0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "haddpd",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "hsubpd",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_E | OPTYPE_d | OP_R,  ADDRMETH_V |
                                                                                OPTYPE_d |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movd",       "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_W | OPTYPE_dq | OP_R, ADDRMETH_V |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movdqa",     "", 0, 0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd | OP_R,
                                                                                      ADDRMETH_I |
                                                                                      OPTYPE_b |
                                                                                      OP_R,
                cpu_PENTIUM4 | isa_GP, "cmppd",  "", 0, 0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_w | OP_R,  ADDRMETH_E |
                                                                                OPTYPE_d | OP_R,
                                                                                      ADDRMETH_I |
                                                                                      OPTYPE_b |
                                                                                      OP_R,
                cpu_PENTIUM4 | isa_GP, "pinsrw", "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_G | OPTYPE_d | OP_R,  ADDRMETH_W |
                                                                                OPTYPE_w | OP_R,
                                                                                      ADDRMETH_I |
                                                                                      OPTYPE_b |
                                                                                      OP_R,
                cpu_PENTIUM4 | isa_GP, "pextrw", "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd | OP_R,
                                                                                      ADDRMETH_I |
                                                                                      OPTYPE_b |
                                                                                      OP_R,
                cpu_PENTIUM4 | isa_GP, "shufpd", "", 0, 0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "addsubpd",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psrlw",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psrld",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psrlq",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "paddq",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pmullw",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_W | OPTYPE_q | OP_R,  ADDRMETH_V |
                                                                                OPTYPE_q |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movq",       "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_G | OPTYPE_d | OP_R,  ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pmovmskb",   "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psubusb",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psubusw",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pminub",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pand",       "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "paddusb",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "paddusw",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pmaxub",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pandn",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pavgb",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psraw",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psrad",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pavgw",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pmulhuw",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pmulhw",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_pd |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "cvttpd2dq",  "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_M | OPTYPE_dq | OP_R, ADDRMETH_V |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "movntdq",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psubsb",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psubsw",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pminsw",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "por",        "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "paddsb",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "paddsw",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pmaxsw",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pxor",       "", 0, 0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psllw",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pslld",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psllq",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pmuludq",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "pmaddwd",    "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psadbw",     "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "maskmovdqu", "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psubb",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psubw",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psubd",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "psubq",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "paddb",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "paddw",      "", 0, 0, 0, 0, 0},
        {0,          INS_UNKNOWN, 0,             ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W |
                                                                                OPTYPE_dq |
                                                                                OP_R, ARG_NONE,
                                                                                              cpu_PENTIUM4 |
                                                                                              isa_GP, "paddd",      "", 0, 0, 0, 0, 0},
        {0,          INS_INVALID, 0,             ARG_NONE, ARG_NONE, ARG_NONE,        cpu_PENTIUM4 |
                                                                                      isa_GP, "",     "",           0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_F20F[] = {    /* SIMD F2 Two-byte Opcodes */
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movsd",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_W | OPTYPE_sd | OP_R, ADDRMETH_V | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movsd",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_q | OP_R,  ADDRMETH_W | OPTYPE_q | OP_R,  ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movddup",   "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_E | OPTYPE_d | OP_R,  ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvtsi2sd",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_G | OPTYPE_d | OP_R,  ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvttsd2si", "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_G | OPTYPE_d | OP_R,  ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvtsd2si",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "sqrtsd",    "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "addsd",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "mulsd",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvtsd2ss",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "subsd",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "minsd",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "divsd",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_sd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "maxsd",     "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W | OPTYPE_dq |
                                                           OP_R,                          ADDRMETH_I |
                                                                                          OPTYPE_b |
                                                                                          OP_R,
                cpu_PENTIUM4 | isa_GP, "pshuflw", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ps | OP_R, ADDRMETH_W | OPTYPE_ps | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "haddps",    "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ps | OP_R, ADDRMETH_W | OPTYPE_ps | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "hsubps",    "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_sd |
                                                           OP_R,                          ADDRMETH_I |
                                                                                          OPTYPE_b |
                                                                                          OP_R,
                cpu_PENTIUM4 | isa_GP, "cmpsd",   "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ps | OP_R, ADDRMETH_W | OPTYPE_ps | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "addsubps",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_P | OPTYPE_q | OP_R,  ADDRMETH_W | OPTYPE_q | OP_R,  ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movdq2q",   "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W | OPTYPE_pd | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvtpd2dq",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_M | OPTYPE_dq | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "lddqu",     "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_F30F[] = {    /* SIMD F3 Two-byte Opcodes */
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movss",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_W | OPTYPE_ss | OP_R, ADDRMETH_V | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movss",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ps | OP_R, ADDRMETH_W | OPTYPE_ps | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movsldup",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ps | OP_R, ADDRMETH_W | OPTYPE_ps | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movshdup",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_E | OPTYPE_d | OP_R,  ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvtsi2ss",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_G | OPTYPE_d | OP_R,  ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvttss2si", "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_G | OPTYPE_d | OP_R,  ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvtss2si",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "sqrtss",    "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "rsqrtss",   "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "rcpss",     "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "addss",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "mulss",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_sd | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvtss2sd",  "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W | OPTYPE_ps | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvttps2dq", "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "subss",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "minss",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "divss",     "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "maxss",     "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W | OPTYPE_dq | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movdqu",    "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_W | OPTYPE_dq |
                                                           OP_R,                          ADDRMETH_I |
                                                                                          OPTYPE_b |
                                                                                          OP_R,
                cpu_PENTIUM4 | isa_GP, "pshufhw", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_q | OP_R,  ADDRMETH_W | OPTYPE_q | OP_R,  ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movq",      "", 0, 0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_W | OPTYPE_dq | OP_R, ADDRMETH_V | OPTYPE_dq | OP_R, ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movdqu",    "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_ss | OP_R, ADDRMETH_W | OPTYPE_ss |
                                                           OP_R,                          ADDRMETH_I |
                                                                                          OPTYPE_b |
                                                                                          OP_R,
                cpu_PENTIUM4 | isa_GP, "cmpss",   "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_dq | OP_R, ADDRMETH_Q | OPTYPE_q | OP_R,  ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "movq2dq",   "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_UNKNOWN, 0, ADDRMETH_V | OPTYPE_pd | OP_R, ADDRMETH_W | OPTYPE_q | OP_R,  ARG_NONE,
                                                                                                  cpu_PENTIUM4 |
                                                                                                  isa_GP, "cvtdq2pd",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                 cpu_PENTIUM4 |
                                                                                          isa_GP, "",     "",          0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_0F00[] = {    /* Group 6 */
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_R, ARG_NONE, ARG_NONE,
                                                                              cpu_80386 |
                                                                              isa_GP, "sldt", "", 0, 0, 0, 0,            46},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80386 |
                                                                              isa_GP, "str",  "", 0, 0, 0, 0,            49},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80386 |
                                                                              isa_GP, "lldt", "", 0, 0, 0, 0,            29},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80386 |
                                                                              isa_GP, "ltr",  "", 0, 0, 0, 0,            32},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_R, ARG_NONE, ARG_NONE, cpu_80386 |
                                                                              isa_GP, "verr", "", 0, 0, 0, INS_SET_ZERO, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_R, ARG_NONE, ARG_NONE, cpu_80386 |
                                                                              isa_GP, "verw", "", 0, 0, 0, INS_SET_ZERO, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",     0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_0F01[] = {    /* Group 7 */
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_R,    ARG_NONE, ARG_NONE,
                                                                                 cpu_80386 |
                                                                                 isa_GP, "sgdt",   "", 0, 0, 0, 0, 44},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_R,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "sidt",   "", 0, 0, 0, 0, 45},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lgdt",   "", 0, 0, 0, 0, 27},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lidt",   "", 0, 0, 0, 0, 28},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "smsw",   "", 0, 0, 0, 0, 47},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,              0,        "",     "",       0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lmsw",   "", 0, 0, 0, 0, 30},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_none | OP_R, ARG_NONE, ARG_NONE, cpu_80486 |
                                                                                 isa_GP, "invlpg", "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_R,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "sgdt",   "", 0, 0, 0, 0, 44},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_R,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "sidt",   "", 0, 0, 0, 0, 45},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lgdt",   "", 0, 0, 0, 0, 27},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lidt",   "", 0, 0, 0, 0, 28},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "smsw",   "", 0, 0, 0, 0, 47},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,              0,        "",     "",       0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lmsw",   "", 0, 0, 0, 0, 30},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_none | OP_R, ARG_NONE, ARG_NONE, cpu_80486 |
                                                                                 isa_GP, "invlpg", "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_R,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "sgdt",   "", 0, 0, 0, 0, 44},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_R,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "sidt",   "", 0, 0, 0, 0, 45},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lgdt",   "", 0, 0, 0, 0, 27},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_s | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lidt",   "", 0, 0, 0, 0, 28},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "smsw",   "", 0, 0, 0, 0, 47},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,              0,        "",     "",       0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lmsw",   "", 0, 0, 0, 0, 30},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_none | OP_R, ARG_NONE, ARG_NONE, cpu_80486 |
                                                                                 isa_GP, "invlpg", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,              0,        "",     "",       0,  0, 0, 0, 0},
        {idx_0F0111, 0,  0, ARG_NONE, ARG_NONE, ARG_NONE,              0,        "",     "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,              0,        "",     "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,              0,        "",     "",       0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "smsw",   "", 0, 0, 0, 0, 47},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,              0,        "",     "",       0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_w | OP_W,    ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "lmsw",   "", 0, 0, 0, 0, 30},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,              0,        "",     "",       0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_0F0111[] = {    /* Monitor/MWait opcode */
        {0, INS_SYSTEM, 0, ARG_NONE, ARG_NONE, ARG_NONE,
                                                         cpu_PENTIUM4 |
                                                         isa_GP,                "monitor", "", 0, 0, 0, 0, 54},
        {0, INS_SYSTEM, 0, ARG_NONE, ARG_NONE, ARG_NONE, cpu_PENTIUM4 |
                                                         isa_GP,                "mwait",   "", 0, 0, 0, 0, 55}
};


static ia32_insn_t tbl_0F12[] = {    /* Movlps Opcode */
        {0, INS_MOV, INS_NOTE_NOSUFFIX, ADDRMETH_V | OPTYPE_q | OP_W,
                                                                              ADDRMETH_M |
                                                                              OPTYPE_q |
                                                                              OP_R, ARG_NONE,
                cpu_PENTIUM2 | isa_GP, "movlps",  "", 0, 0, 0, 0, 0},
        {0, INS_MOV, INS_NOTE_NOSUFFIX, ADDRMETH_V | OPTYPE_q | OP_W,         ADDRMETH_M |
                                                                              OPTYPE_q |
                                                                              OP_R, ARG_NONE,
                cpu_PENTIUM2 | isa_GP, "movlps",  "", 0, 0, 0, 0, 0},
        {0, INS_MOV, INS_NOTE_NOSUFFIX, ADDRMETH_V | OPTYPE_q | OP_W,         ADDRMETH_M |
                                                                              OPTYPE_q |
                                                                              OP_R, ARG_NONE,
                cpu_PENTIUM2 | isa_GP, "movlps",  "", 0, 0, 0, 0, 0},
        {0, INS_MOV, 0,                 ADDRMETH_V | OPTYPE_ps | OP_R | OP_W, ADDRMETH_W |
                                                                              OPTYPE_ps |
                                                                              OP_R, ARG_NONE,
                cpu_PENTIUM4 | isa_GP, "movhlps", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_0F16[] = {    /* Movhps Opcode */
        {0, INS_OTHER, 0, ADDRMETH_V | OPTYPE_q | OP_W,         ADDRMETH_M | OPTYPE_q |
                                                                OP_R, ARG_NONE,
                                                                                cpu_PENTIUM2 |
                                                                                isa_GP, "movhps",  "", 0, 0, 0, 0, 0},
        {0, INS_OTHER, 0, ADDRMETH_V | OPTYPE_q | OP_W,         ADDRMETH_M | OPTYPE_q |
                                                                OP_R, ARG_NONE, cpu_PENTIUM2 |
                                                                                isa_GP, "movhps",  "", 0, 0, 0, 0, 0},
        {0, INS_OTHER, 0, ADDRMETH_V | OPTYPE_q | OP_W,         ADDRMETH_M | OPTYPE_q |
                                                                OP_R, ARG_NONE, cpu_PENTIUM2 |
                                                                                isa_GP, "movhps",  "", 0, 0, 0, 0, 0},
        {0, INS_MOV,   0, ADDRMETH_V | OPTYPE_ps | OP_R | OP_W, ADDRMETH_W | OPTYPE_ps |
                                                                OP_R, ARG_NONE, cpu_PENTIUM4 |
                                                                                isa_GP, "movlhps", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_0F18[] = {    /* Group 16 */
        {0, INS_SYSTEM,  0, OP_W | OPTYPE_b | ADDRMETH_M,  ARG_NONE, ARG_NONE,
                                                                               cpu_PENTIUM2 |
                                                                               isa_GP, "prefetchnta", "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_RT | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetcht0",  "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_RT | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetcht1",  "", 1, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_RT | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetcht2",  "", 2, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",     "",            0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",     "",            0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",     "",            0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",     "",            0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, OP_W | OPTYPE_b | ADDRMETH_M,  ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetchnta", "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_RT | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetcht0",  "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_RT | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetcht1",  "", 1, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_RT | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetcht2",  "", 2, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",     "",            0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",     "",            0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",     "",            0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",     "",            0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, OP_W | OPTYPE_b | ADDRMETH_M,  ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetchnta", "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_RT | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetcht0",  "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_RT | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetcht1",  "", 1, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_RT | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM2 |
                                                                               isa_GP, "prefetcht2",  "", 2, 0, 0, 0, 0}
};


static ia32_insn_t tbl_0F71[] = {    /* Group 12 */
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_q | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psrlw", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_q | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psraw", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_q | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psllw", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_660F71[] = {    /* Group 12 SSE */
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psrlw", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psraw", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psllw", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_0F72[] = {    /* Group 13 */
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_q | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psrld", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_q | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psrad", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_q | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "pslld", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_660F72[] = {    /* Group 13 SSE */
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_W | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psrld", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_W | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psrad", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_W | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "pslld", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_0F73[] = {    /* Group 14 */
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_q | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psrlq", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_P | OPTYPE_q | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psllq", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_660F73[] = {    /* Group 14 SSE */
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_W | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psrlq",  "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_W | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psrldq", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "", "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_W | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "psllq",  "", 0, 0, 0, 0, 0},
        {0, INS_OTHER,   0, ADDRMETH_W | OPTYPE_dq | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_PENTIUM | isa_MMX, "pslldq", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_0FAE[] = {    /* Group 15 */
        {0, INS_FPU,     0, ADDRMETH_E | OPTYPE_fx | OP_W, ARG_NONE, ARG_NONE,
                                                                               cpu_PENTIUM |
                                                                               isa_MMX,  "fxsave",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_E | OPTYPE_fx | OP_R, ARG_NONE, ARG_NONE, cpu_PENTIUM |
                                                                               isa_MMX,  "fxrstor", "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_d |
                            OP_R,                          ARG_NONE, ARG_NONE, cpu_PENTIUM2, "ldmxcsr", "", 0, 0, 0, 0, 25},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_d |
                            OP_W,                          ARG_NONE, ARG_NONE, cpu_PENTIUM2, "stmxcsr", "", 0, 0, 0, 0, 48},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_b | OP_R,  ARG_NONE, ARG_NONE, cpu_PENTIUM4 |
                                                                               isa_GP,   "clflush", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_E | OPTYPE_fx | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM |
                                                                               isa_MMX,  "fxsave",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_E | OPTYPE_fx | OP_R, ARG_NONE, ARG_NONE, cpu_PENTIUM |
                                                                               isa_MMX,  "fxrstor", "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_d |
                            OP_R,                          ARG_NONE, ARG_NONE, cpu_PENTIUM2, "ldmxcsr", "", 0, 0, 0, 0, 25},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_d |
                            OP_W,                          ARG_NONE, ARG_NONE, cpu_PENTIUM2, "stmxcsr", "", 0, 0, 0, 0, 48},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_b | OP_R,  ARG_NONE, ARG_NONE, cpu_PENTIUM4 |
                                                                               isa_GP,   "clflush", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_E | OPTYPE_fx | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM |
                                                                               isa_MMX,  "fxsave",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_E | OPTYPE_fx | OP_R, ARG_NONE, ARG_NONE, cpu_PENTIUM |
                                                                               isa_MMX,  "fxrstor", "", 0, 0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_d |
                            OP_R,                          ARG_NONE, ARG_NONE, cpu_PENTIUM2, "ldmxcsr", "", 0, 0, 0, 0, 25},
        {0, INS_SYSTEM,  0, ADDRMETH_E | OPTYPE_d |
                            OP_W,                          ARG_NONE, ARG_NONE, cpu_PENTIUM2, "stmxcsr", "", 0, 0, 0, 0, 48},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ADDRMETH_M | OPTYPE_b | OP_R,  ARG_NONE, ARG_NONE, cpu_PENTIUM4 |
                                                                               isa_GP,   "clflush", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "",       "",        0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "lfence", "",        0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "mfence", "",        0,  0, 0, 0, 0},
        {0, INS_SYSTEM,  0, ARG_NONE, ARG_NONE, ARG_NONE,            0,        "sfence", "",        0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_0FBA[] = {    /* Group 8 */
        {0, INS_BITTEST, 0, ADDRMETH_E | OPTYPE_v | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "bt",  "", 0, 0, 0, INS_SET_CARRY, 0},
        {0, INS_BITTEST, 0, ADDRMETH_E | OPTYPE_v | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "bts", "", 0, 0, 0, INS_SET_CARRY, 0},
        {0, INS_BITTEST, 0, ADDRMETH_E | OPTYPE_v | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "btr", "", 0, 0, 0, INS_SET_CARRY, 0},
        {0, INS_BITTEST, 0, ADDRMETH_E | OPTYPE_v | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "btc", "", 0, 0, 0, INS_SET_CARRY, 0}
};


static ia32_insn_t tbl_0FC7[] = {    /* Group 9 */
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_XCHGCC,  0, ADDRMETH_M | OPTYPE_q | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM |
                                                                              isa_GP, "cmpxch8b", "", 0, 0, 0, 0, 9},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_XCHGCC,  0, ADDRMETH_M | OPTYPE_q | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM |
                                                                              isa_GP, "cmpxch8b", "", 0, 0, 0, 0, 9},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,           0,        "",     "",         0,  0, 0, 0, 0},
        {0, INS_XCHGCC,  0, ADDRMETH_M | OPTYPE_q | OP_W, ARG_NONE, ARG_NONE, cpu_PENTIUM |
                                                                              isa_GP, "cmpxch8b", "", 0, 0, 0, 0, 9}
};


static ia32_insn_t tbl_0FB9[] = {    /* Group 10 */
        {0, INS_SYSTEM, 0, ARG_NONE, ARG_NONE, ARG_NONE, 0, "fxsave", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_C6[] = {    /* Group 11a */
        {0, INS_MOV, 0, ADDRMETH_E | OPTYPE_b | OP_W, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
         cpu_80386 | isa_GP, "mov", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_C7[] = {    /* Group 11b */
        {0, INS_MOV, 0, ADDRMETH_E | OPTYPE_v | OP_W, ADDRMETH_I | OPTYPE_v | OP_R, ARG_NONE,
         cpu_80386 | isa_GP, "mov", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_80[] = {    /* Group 1a */
        {0, INS_ADD, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,
                                                                         ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "add", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_OR,  0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_R,             ARG_NONE,
                cpu_80386 | isa_GP, "or",  "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_ADD, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "adc", "", 0, 0, 0, INS_SET_ALL | INS_TEST_CARRY, 0},
        {0, INS_SUB, 0, ADDRMETH_E | OPTYPE_b | OP_SIGNED | OP_W | OP_R, ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sbb", "", 0, 0, 0, INS_SET_ALL | INS_TEST_CARRY, 0},
        {0, INS_AND, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_R,             ARG_NONE,
                cpu_80386 | isa_GP, "and", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SUB, 0, ADDRMETH_E | OPTYPE_b | OP_SIGNED | OP_W | OP_R, ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sub", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_XOR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_R,             ARG_NONE,
                cpu_80386 | isa_GP, "xor", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_CMP, 0, ADDRMETH_E | OPTYPE_b | OP_R,                    ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "cmp", "", 0, 0, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_81[] = {    /* Group 1b */
        {0, INS_ADD, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,
                                                                         ADDRMETH_I | OPTYPE_v |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "add", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_OR,  0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,             ADDRMETH_I | OPTYPE_v |
                                                                         OP_R,             ARG_NONE,
                cpu_80386 | isa_GP, "or",  "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_ADD, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,             ADDRMETH_I | OPTYPE_v |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "adc", "", 0, 0, 0, INS_SET_ALL | INS_TEST_CARRY, 0},
        {0, INS_SUB, 0, ADDRMETH_E | OPTYPE_v | OP_SIGNED | OP_W | OP_R, ADDRMETH_I | OPTYPE_v |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sbb", "", 0, 0, 0, INS_SET_ALL | INS_TEST_CARRY, 0},
        {0, INS_AND, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,             ADDRMETH_I | OPTYPE_v |
                                                                         OP_R,             ARG_NONE,
                cpu_80386 | isa_GP, "and", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SUB, 0, ADDRMETH_E | OPTYPE_v | OP_SIGNED | OP_W | OP_R, ADDRMETH_I | OPTYPE_v |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sub", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_XOR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,             ADDRMETH_I | OPTYPE_v |
                                                                         OP_R,             ARG_NONE,
                cpu_80386 | isa_GP, "xor", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_CMP, 0, ADDRMETH_E | OPTYPE_v | OP_R,                    ADDRMETH_I | OPTYPE_v |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "cmp", "", 0, 0, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_82[] = {    /* Group 1c */
        {0, INS_ADD, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,
                                                                         ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "add", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_OR,  0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_R,             ARG_NONE,
                cpu_80386 | isa_GP, "or",  "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_ADD, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "adc", "", 0, 0, 0, INS_SET_ALL | INS_TEST_CARRY, 0},
        {0, INS_SUB, 0, ADDRMETH_E | OPTYPE_b | OP_SIGNED | OP_W | OP_R, ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sbb", "", 0, 0, 0, INS_SET_ALL | INS_TEST_CARRY, 0},
        {0, INS_AND, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_R,             ARG_NONE,
                cpu_80386 | isa_GP, "and", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SUB, 0, ADDRMETH_E | OPTYPE_b | OP_SIGNED | OP_W | OP_R, ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sub", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_XOR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_R,             ARG_NONE,
                cpu_80386 | isa_GP, "xor", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_CMP, 0, ADDRMETH_E | OPTYPE_b | OP_R,                    ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "cmp", "", 0, 0, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_83[] = {    /* Group 1d */
        {0, INS_ADD, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,
                                                                         ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "add", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_OR,  0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "or",  "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_ADD, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "adc", "", 0, 0, 0, INS_SET_ALL | INS_TEST_CARRY, 0},
        {0, INS_SUB, 0, ADDRMETH_E | OPTYPE_v | OP_SIGNED | OP_W | OP_R, ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sbb", "", 0, 0, 0, INS_SET_ALL | INS_TEST_CARRY, 0},
        {0, INS_AND, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "and", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SUB, 0, ADDRMETH_E | OPTYPE_v | OP_SIGNED | OP_W | OP_R, ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sub", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_XOR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,             ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "xor", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_CMP, 0, ADDRMETH_E | OPTYPE_v | OP_R,                    ADDRMETH_I | OPTYPE_b |
                                                                         OP_SIGNED | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "cmp", "", 0, 0, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_C0[] = {    /* Group 2a */
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "rol", "", 0, 0, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "ror", "", 0, 0, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "rcl", "", 0, 0, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "rcr", "", 0, 0, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "shl", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "shr", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sal", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sar", "", 0, 0, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_C1[] = {    /* Group 2b */
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "rol", "", 0, 0, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "ror", "", 0, 0, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "rcl", "", 0, 0, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "rcr", "", 0, 0, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "shl", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "shr", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sal", "", 0, 0, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_I | OPTYPE_b | OP_R, ARG_NONE,
                cpu_80386 | isa_GP, "sar", "", 0, 0, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_D0[] = {    /* Group 2c */
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,
                                                             ADDRMETH_II | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rol", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_II | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "ror", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_II | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rcl", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_II | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rcr", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_II | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "shl", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_II | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "shr", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_II | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "sal", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_II | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "sar", "", 0, 1, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_D1[] = {    /* Group 2d */
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,
                                                             ADDRMETH_II | OPTYPE_v |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rol", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_II | OPTYPE_v |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "ror", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_II | OPTYPE_v |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rcl", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_II | OPTYPE_v |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rcr", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_II | OPTYPE_v |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "shl", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_II | OPTYPE_v |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "shr", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_II | OPTYPE_v |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "sal", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_II | OPTYPE_v |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "sar", "", 0, 1, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_D2[] = {    /* Group 2e */
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,
                                                             ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rol", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "ror", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rcl", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rcr", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "shl", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "shr", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "sal", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "sar", "", 0, 1, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_D3[] = {    /* Group 2f */
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,
                                                             ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rol", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "ror", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW, 0},
        {0, INS_ROL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rcl", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_ROR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "rcr", "", 0, 1, 0, INS_SET_CARRY | INS_SET_OFLOW |
                                                        INS_TEST_CARRY,                0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "shl", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "shr", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHL, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "sal", "", 0, 1, 0, INS_SET_ALL, 0},
        {0, INS_SHR, 0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ADDRMETH_RR | OPTYPE_b |
                                                             OP_R,                          ARG_NONE,
                cpu_80386 | isa_GP, "sar", "", 0, 1, 0, INS_SET_ALL, 0}
};


static ia32_insn_t tbl_F6[] = {    /* Group 3a */
        {0, INS_TEST, 0, ADDRMETH_E | OPTYPE_b | OP_R,
                                                                           ADDRMETH_I | OPTYPE_b |
                                                                           OP_SIGNED |
                                                                           OP_R, ARG_NONE,
                                                                                           cpu_80386 |
                                                                                           isa_GP, "test", "", 0, 0, 0,
                                                                                                                                     INS_SET_ALL, 0},
        {0, INS_TEST, 0, ADDRMETH_E | OPTYPE_b | OP_R,                     ADDRMETH_I | OPTYPE_b |
                                                                           OP_SIGNED |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "test", "", 0, 0, 0,              INS_SET_ALL, 0},
        {0, INS_NOT,  0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,              ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "not", "", 0, 0, 0, 0,                                                                           0},
        {0, INS_NEG,  0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R,              ARG_NONE, ARG_NONE,
                cpu_80386 | isa_GP, "neg", "", 0, 0, 0,
                                                                                                                        INS_SET_ALL, 0},
        {0, INS_MUL,  0, OPTYPE_b | ADDRMETH_RR | OP_W | OP_R,             ADDRMETH_E | OPTYPE_b |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "mul",  "", 0, 0, 0,              INS_SET_OFLOW |
                                                                                                                                     INS_SET_CARRY, 22},
        {0, INS_MUL,  0, OPTYPE_b | ADDRMETH_RR | OP_W | OP_SIGNED | OP_R, ADDRMETH_E | OPTYPE_b |
                                                                           OP_SIGNED |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "imul", "", 0, 0, 0,              INS_SET_OFLOW |
                                                                                                                                     INS_SET_CARRY, 22},
        {0, INS_DIV,  0, ADDRMETH_RR | OPTYPE_b | OP_W | OP_R,             ADDRMETH_E | OPTYPE_b |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "div",  "", 0, 0, 0, 0,                        13},
        {0, INS_DIV,  0, ADDRMETH_RR | OPTYPE_b | OP_W | OP_R,             ADDRMETH_E | OPTYPE_b |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "idiv", "", 0, 0, 0, 0,                        13}
};


static ia32_insn_t tbl_F7[] = {    /* Group 3b */
        {0, INS_TEST, 0, ADDRMETH_E | OPTYPE_v | OP_R,
                                                                           ADDRMETH_I | OPTYPE_v |
                                                                           OP_SIGNED |
                                                                           OP_R, ARG_NONE,
                                                                                           cpu_80386 |
                                                                                           isa_GP, "test", "", 0, 0, 0,
                                                                                                                                     INS_SET_ALL, 0},
        {0, INS_TEST, 0, ADDRMETH_E | OPTYPE_v | OP_R,                     ADDRMETH_I | OPTYPE_v |
                                                                           OP_SIGNED |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "test", "", 0, 0, 0,              INS_SET_ALL, 0},
        {0, INS_NOT,  0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,              ARG_NONE, ARG_NONE,
                cpu_80386 |
                isa_GP,             "not", "", 0, 0, 0, 0,                                                                           0},
        {0, INS_NEG,  0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R,              ARG_NONE, ARG_NONE,
                cpu_80386 | isa_GP, "neg", "", 0, 0, 0,
                                                                                                                        INS_SET_ALL, 0},
        {0, INS_MUL,  0, ADDRMETH_RR | OPTYPE_v | OP_W | OP_R,             ADDRMETH_E | OPTYPE_v |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "mul",  "", 0, 0, 0,              INS_SET_OFLOW |
                                                                                                                                     INS_SET_CARRY, 23},
        {0, INS_MUL,  0, ADDRMETH_RR | OPTYPE_v | OP_SIGNED | OP_W | OP_R, ADDRMETH_E | OPTYPE_v |
                                                                           OP_SIGNED |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "imul", "", 0, 0, 0,              INS_SET_OFLOW |
                                                                                                                                     INS_SET_CARRY, 23},
        {0, INS_DIV,  0, ADDRMETH_RR | OPTYPE_v | OP_W | OP_R,             ADDRMETH_E | OPTYPE_v |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "div",  "", 0, 0, 0, 0,                        14},
        {0, INS_DIV,  0, ADDRMETH_RR | OPTYPE_v | OP_W | OP_R,             ADDRMETH_E | OPTYPE_v |
                                                                           OP_R, ARG_NONE, cpu_80386 |
                                                                                           isa_GP, "idiv", "", 0, 0, 0, 0,                        14}
};


static ia32_insn_t tbl_FE[] = {    /* Group 4 */
        {0, INS_INC, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ARG_NONE, ARG_NONE,
                                                                                 cpu_80386 |
                                                                                 isa_GP, "inc", "", 0, 0, 0,
                INS_SET_OFLOW | INS_SET_SIGN | INS_SET_ZERO | INS_SET_PARITY, 0},
        {0, INS_DEC, 0, ADDRMETH_E | OPTYPE_b | OP_W | OP_R, ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                 isa_GP, "dec", "", 0, 0, 0,
                INS_SET_OFLOW | INS_SET_SIGN | INS_SET_ZERO | INS_SET_PARITY, 0}
};


static ia32_insn_t tbl_FF[] = {    /* Group 5 */
        {0, INS_INC,    0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ARG_NONE, ARG_NONE,
                                                                                    cpu_80386 |
                                                                                    isa_GP, "inc",  "", 0, 0, 0,
                INS_SET_OFLOW | INS_SET_SIGN | INS_SET_ZERO | INS_SET_PARITY, 0},
        {0, INS_DEC,    0, ADDRMETH_E | OPTYPE_v | OP_W | OP_R, ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                    isa_GP, "dec",  "", 0, 0, 0,
                INS_SET_OFLOW | INS_SET_SIGN | INS_SET_ZERO | INS_SET_PARITY, 0},
        {0, INS_CALL,   0, ADDRMETH_E | OPTYPE_v | OP_X,        ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                    isa_GP, "call", "", 0, 0, 0, 0, 3},
        {0, INS_CALL,   0, ADDRMETH_M | OPTYPE_p | OP_X,        ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                    isa_GP, "call", "", 0, 0, 0, 0, 0},
        {0, INS_BRANCH, 0, ADDRMETH_E | OPTYPE_v | OP_X,        ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                    isa_GP, "jmp",  "", 0, 0, 0, 0, 0},
        {0, INS_BRANCH, 0, ADDRMETH_M | OPTYPE_p | OP_X,        ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                    isa_GP, "jmp",  "", 0, 0, 0, 0, 0},
        {0, INS_PUSH,   0, ADDRMETH_E | OPTYPE_v | OP_R,        ARG_NONE, ARG_NONE, cpu_80386 |
                                                                                    isa_GP, "push", "", 0, 0, 0, 0, 33}
};


static ia32_insn_t tbl_D8[] = {    /* FPU D8 */
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE,
                                                                           cpu_80387 |
                                                                           isa_FPU, "fadd",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fmul",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fcom",  "", 0, 0, 0,
                INS_SET_ZERO | INS_SET_PARITY | INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fcomp", "", 0, 0, 0,
                INS_SET_ZERO | INS_SET_PARITY | INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fsub",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fsubr", "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fdiv",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fdivr", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_D8C0[] = {    /* FPU D8 C0 */
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fadd",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fadd",  "", 0, 1, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fadd",  "", 0, 2, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fadd",  "", 0, 3, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fadd",  "", 0, 4, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fadd",  "", 0, 5, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fadd",  "", 0, 6, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fadd",  "", 0, 7, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fmul",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fmul",  "", 0, 1, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fmul",  "", 0, 2, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fmul",  "", 0, 3, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fmul",  "", 0, 4, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fmul",  "", 0, 5, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fmul",  "", 0, 6, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fmul",  "", 0, 7, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcom",  "", 0, 0, 0,
                                                           INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcom",  "", 0, 1, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcom",  "", 0, 2, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcom",  "", 0, 3, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcom",  "", 0, 4, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcom",  "", 0, 5, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcom",  "", 0, 6, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcom",  "", 0, 7, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcomp", "", 0, 0, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcomp", "", 0, 1, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcomp", "", 0, 2, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcomp", "", 0, 3, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcomp", "", 0, 4, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcomp", "", 0, 5, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcomp", "", 0, 6, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fcomp", "", 0, 7, 0, INS_SET_ZERO | INS_SET_PARITY |
                                                           INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsub",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsub",  "", 0, 1, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsub",  "", 0, 2, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsub",  "", 0, 3, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsub",  "", 0, 4, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsub",  "", 0, 5, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsub",  "", 0, 6, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsub",  "", 0, 7, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsubr", "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsubr", "", 0, 1, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsubr", "", 0, 2, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsubr", "", 0, 3, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsubr", "", 0, 4, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsubr", "", 0, 5, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsubr", "", 0, 6, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fsubr", "", 0, 7, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdiv",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdiv",  "", 0, 1, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdiv",  "", 0, 2, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdiv",  "", 0, 3, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdiv",  "", 0, 4, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdiv",  "", 0, 5, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdiv",  "", 0, 6, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdiv",  "", 0, 7, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdivr", "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdivr", "", 0, 1, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdivr", "", 0, 2, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdivr", "", 0, 3, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdivr", "", 0, 4, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdivr", "", 0, 5, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdivr", "", 0, 6, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp | OP_R, ARG_NONE,
                cpu_80387 | isa_FPU, "fdivr", "", 0, 7, 0, 0, 0}
};


static ia32_insn_t tbl_D9[] = {    /* FPU D9 */
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE,
                                                                               cpu_80387 |
                                                                               isa_FPU, "fld",     "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,
                cpu_80387 | isa_FPU, "", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fst",     "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fs | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fstp",    "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fv | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fldenv",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_w | OP_W,  ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fldcw",   "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fv | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fnstenv", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_w | OP_W,  ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fnstcw",  "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_D9C0[] = {    /* FPU D9 C0 */
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W,
                                                            ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fld",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fld",  "", 0, 1, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fld",  "", 0, 2, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fld",  "", 0, 3, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fld",  "", 0, 4, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fld",  "", 0, 5, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fld",  "", 0, 6, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fld",  "", 0, 7, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fxch", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fxch", "", 0, 1, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fxch", "", 0, 2, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fxch", "", 0, 3, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fxch", "", 0, 4, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fxch", "", 0, 5, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fxch", "", 0, 6, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,   "fxch", "", 0, 7, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fnop",    "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fchs",    "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fabs",    "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "ftst",    "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fxam",    "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fld1",    "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fldl2t",  "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fldl2e",  "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fldpi",   "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fldlg2",  "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fldln2",  "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fldz",    "",     0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "f2xm1",   "",     0,  0, 0, 0, 16},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fyl2x",   "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fptan",   "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fpatan",  "",     0,  0, 0, 0, 18},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fxtract", "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fprem1",  "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fdecstp", "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fincstp", "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fprem",   "",     0,  0, 0, 0, 19},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fyl2xp1", "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fsqrt",   "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fsincos", "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "frndint", "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fscale",  "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fsin",    "",     0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fcos",    "",     0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_DA[] = {    /* FPU DA */
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE,
                                                                          cpu_80387 |
                                                                          isa_FPU, "fiadd",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fimul",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "ficom",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "ficomp", "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fisub",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fisubr", "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fidiv",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_d | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fidivr", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_DAC0[] = {    /* FPU DA C0 */
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W,
                                                            ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovb",  "", 0, 0, 0, INS_TEST_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovb",  "", 0, 1, 0, INS_TEST_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovb",  "", 0, 2, 0, INS_TEST_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovb",  "", 0, 3, 0, INS_TEST_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovb",  "", 0, 4, 0, INS_TEST_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovb",  "", 0, 5, 0, INS_TEST_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovb",  "", 0, 6, 0, INS_TEST_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovb",  "", 0, 7, 0, INS_TEST_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmove",  "", 0, 0, 0, INS_TEST_ZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmove",  "", 0, 1, 0, INS_TEST_ZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmove",  "", 0, 2, 0, INS_TEST_ZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmove",  "", 0, 3, 0, INS_TEST_ZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmove",  "", 0, 4, 0, INS_TEST_ZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmove",  "", 0, 5, 0, INS_TEST_ZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmove",  "", 0, 6, 0, INS_TEST_ZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmove",  "", 0, 7, 0, INS_TEST_ZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovbe", "", 0, 0, 0, INS_TEST_CARRY |
                                                                                                                                        INS_TEST_OR |
                                                                                                                                        INS_TEST_ZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovbe", "", 0, 1, 0, INS_TEST_CARRY |
                                                                                                                                        INS_TEST_OR |
                                                                                                                                        INS_TEST_ZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovbe", "", 0, 2, 0, INS_TEST_CARRY |
                                                                                                                                        INS_TEST_OR |
                                                                                                                                        INS_TEST_ZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovbe", "", 0, 3, 0, INS_TEST_CARRY |
                                                                                                                                        INS_TEST_OR |
                                                                                                                                        INS_TEST_ZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovbe", "", 0, 4, 0, INS_TEST_CARRY |
                                                                                                                                        INS_TEST_OR |
                                                                                                                                        INS_TEST_ZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovbe", "", 0, 5, 0, INS_TEST_CARRY |
                                                                                                                                        INS_TEST_OR |
                                                                                                                                        INS_TEST_ZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovbe", "", 0, 6, 0, INS_TEST_CARRY |
                                                                                                                                        INS_TEST_OR |
                                                                                                                                        INS_TEST_ZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovbe", "", 0, 7, 0, INS_TEST_CARRY |
                                                                                                                                        INS_TEST_OR |
                                                                                                                                        INS_TEST_ZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovu",  "", 0, 0, 0, INS_TEST_PARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovu",  "", 0, 1, 0, INS_TEST_PARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovu",  "", 0, 2, 0, INS_TEST_PARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovu",  "", 0, 3, 0, INS_TEST_PARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovu",  "", 0, 4, 0, INS_TEST_PARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovu",  "", 0, 5, 0, INS_TEST_PARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovu",  "", 0, 6, 0, INS_TEST_PARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,    "fcmovu",  "", 0, 7, 0, INS_TEST_PARITY, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fucompp", "",        0,  0, 0, 0, 21},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",        "",        0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_DB[] = {    /* FPU DB */
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_d | OP_W,  ARG_NONE, ARG_NONE,
                                                                               cpu_80387 |
                                                                               isa_FPU, "fild",   "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_d | OP_W,  ARG_NONE, ARG_NONE, cpu_PENTIUM4 |
                                                                               isa_GP,  "fisttp", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_d | OP_W,  ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fist",   "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_d | OP_W,  ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fistp",  "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,
                                                          cpu_80387 |
                                                          isa_FPU,             "", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fe | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fld",    "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE, cpu_80387 |
                                                          isa_FPU,             "", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fe | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fstp",   "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_DBC0[] = {    /* FPU DB C0 */
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W,
                                                            ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnb",  "", 0, 0, 0, INS_TEST_NCARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnb",  "", 0, 1, 0, INS_TEST_NCARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnb",  "", 0, 2, 0, INS_TEST_NCARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnb",  "", 0, 3, 0, INS_TEST_NCARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnb",  "", 0, 4, 0, INS_TEST_NCARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnb",  "", 0, 5, 0, INS_TEST_NCARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnb",  "", 0, 6, 0, INS_TEST_NCARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnb",  "", 0, 7, 0, INS_TEST_NCARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovne",  "", 0, 0, 0, INS_TEST_NZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovne",  "", 0, 1, 0, INS_TEST_NZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovne",  "", 0, 2, 0, INS_TEST_NZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovne",  "", 0, 3, 0, INS_TEST_NZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovne",  "", 0, 4, 0, INS_TEST_NZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovne",  "", 0, 5, 0, INS_TEST_NZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovne",  "", 0, 6, 0, INS_TEST_NZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovne",  "", 0, 7, 0, INS_TEST_NZERO,   0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnbe", "", 0, 0, 0, INS_TEST_NCARRY |
                                                                                                                                        INS_TEST_NZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnbe", "", 0, 1, 0, INS_TEST_NCARRY |
                                                                                                                                        INS_TEST_NZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnbe", "", 0, 2, 0, INS_TEST_NCARRY |
                                                                                                                                        INS_TEST_NZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnbe", "", 0, 3, 0, INS_TEST_NCARRY |
                                                                                                                                        INS_TEST_NZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnbe", "", 0, 4, 0, INS_TEST_NCARRY |
                                                                                                                                        INS_TEST_NZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnbe", "", 0, 5, 0, INS_TEST_NCARRY |
                                                                                                                                        INS_TEST_NZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnbe", "", 0, 6, 0, INS_TEST_NCARRY |
                                                                                                                                        INS_TEST_NZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnbe", "", 0, 7, 0, INS_TEST_NCARRY |
                                                                                                                                        INS_TEST_NZERO, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnu",  "", 0, 0, 0, INS_TEST_NPARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnu",  "", 0, 1, 0, INS_TEST_NPARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnu",  "", 0, 2, 0, INS_TEST_NPARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnu",  "", 0, 3, 0, INS_TEST_NPARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnu",  "", 0, 4, 0, INS_TEST_NPARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnu",  "", 0, 5, 0, INS_TEST_NPARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnu",  "", 0, 6, 0, INS_TEST_NPARITY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fcmovnu",  "", 0, 7, 0, INS_TEST_NPARITY, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fnclex", "",         0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fninit", "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fucomi",   "", 0, 0, 0, 0,                0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fucomi",   "", 0, 1, 0, 0,                0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fucomi",   "", 0, 2, 0, 0,                0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fucomi",   "", 0, 3, 0, 0,                0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fucomi",   "", 0, 4, 0, 0,                0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fucomi",   "", 0, 5, 0, 0,                0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fucomi",   "", 0, 6, 0, 0,                0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fucomi",   "", 0, 7, 0, 0,                0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,   "fcomi",    "", 0, 0, 0, INS_SET_ZERO |
                                                                                                                                        INS_SET_PARITY |
                                                                                                                                        INS_SET_CARRY,  0,},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,   "fcomi",    "", 0, 1, 0, INS_SET_ZERO |
                                                                                                                                        INS_SET_PARITY |
                                                                                                                                        INS_SET_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,   "fcomi",    "", 0, 2, 0, INS_SET_ZERO |
                                                                                                                                        INS_SET_PARITY |
                                                                                                                                        INS_SET_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,   "fcomi",    "", 0, 3, 0, INS_SET_ZERO |
                                                                                                                                        INS_SET_PARITY |
                                                                                                                                        INS_SET_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,   "fcomi",    "", 0, 4, 0, INS_SET_ZERO |
                                                                                                                                        INS_SET_PARITY |
                                                                                                                                        INS_SET_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,   "fcomi",    "", 0, 5, 0, INS_SET_ZERO |
                                                                                                                                        INS_SET_PARITY |
                                                                                                                                        INS_SET_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,   "fcomi",    "", 0, 6, 0, INS_SET_ZERO |
                                                                                                                                        INS_SET_PARITY |
                                                                                                                                        INS_SET_CARRY,  0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_PENTPRO |
                                                                                                     isa_GP,   "fcomi",    "", 0, 7, 0, INS_SET_ZERO |
                                                                                                                                        INS_SET_PARITY |
                                                                                                                                        INS_SET_CARRY,  0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",         0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_DC[] = {    /* FPU DC */
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE,
                                                                           cpu_80387 |
                                                                           isa_FPU, "fadd",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fmul",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fcom",  "", 0, 0, 0,
                INS_SET_ZERO | INS_SET_PARITY | INS_SET_CARRY, 17},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fcomp", "", 0, 0, 0,
                INS_SET_ZERO | INS_SET_PARITY | INS_SET_CARRY, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fsub",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fsubr", "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fdiv",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fdivr", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_DCC0[] = {    /* FPU DC C0 */
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W,
                                                            ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fadd",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fadd",  "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fadd",  "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fadd",  "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fadd",  "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fadd",  "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fadd",  "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fadd",  "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fmul",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fmul",  "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fmul",  "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fmul",  "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fmul",  "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fmul",  "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fmul",  "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fmul",  "", 7, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",      0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsubr", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsubr", "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsubr", "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsubr", "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsubr", "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsubr", "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsubr", "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsubr", "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsub",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsub",  "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsub",  "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsub",  "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsub",  "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsub",  "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsub",  "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fsub",  "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdivr", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdivr", "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdivr", "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdivr", "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdivr", "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdivr", "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdivr", "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdivr", "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdiv",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdiv",  "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdiv",  "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdiv",  "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdiv",  "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdiv",  "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdiv",  "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fdiv",  "", 7, 0, 0, 0, 0}
};


static ia32_insn_t tbl_DD[] = {    /* FPU DD */
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE,
                                                                               cpu_80387 |
                                                                               isa_FPU, "fld",    "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_q | OP_W,  ARG_NONE, ARG_NONE, cpu_PENTIUM4 |
                                                                               isa_GP,  "fisttp", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fst",    "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_fd | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fstp",   "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_ft | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "frstor", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,
                cpu_80387 | isa_FPU, "", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_ft | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fnsave", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_M | OPTYPE_w | OP_W,  ARG_NONE, ARG_NONE, cpu_80387 |
                                                                               isa_FPU, "fnstsw", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_DDC0[] = {    /* FPU DD C0 */
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE,
                                                                                cpu_80387 |
                                                                                isa_FPU, "ffree", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "ffree", "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "ffree", "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "ffree", "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "ffree", "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "ffree", "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "ffree", "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "ffree", "", 7, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                            cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fst",   "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fst",   "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fst",   "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fst",   "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fst",   "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fst",   "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fst",   "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fst",   "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fstp",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fstp",  "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fstp",  "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fstp",  "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fstp",  "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fstp",  "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fstp",  "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                                isa_FPU, "fstp",  "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucom",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucom",  "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucom",  "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucom",  "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucom",  "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucom",  "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucom",  "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucom",  "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomp", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomp", "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomp", "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomp", "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomp", "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomp", "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomp", "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomp", "", 7, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",       0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_DE[] = {    /* FPU DE */
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE,
                                                                          cpu_80387 |
                                                                          isa_FPU, "fiadd",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fimul",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "ficom",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "ficomp", "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fisub",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fisubr", "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fidiv",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                          isa_FPU, "fidivr", "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_DEC0[] = {    /* FPU DE C0 */
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W,
                                                            ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "faddp",  "", 0, 0, 0, 0, 20},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "faddp",  "", 1, 0, 0, 0, 20},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "faddp",  "", 2, 0, 0, 0, 20},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "faddp",  "", 3, 0, 0, 0, 20},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "faddp",  "", 4, 0, 0, 0, 20},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "faddp",  "", 5, 0, 0, 0, 20},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "faddp",  "", 6, 0, 0, 0, 20},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "faddp",  "", 7, 0, 0, 0, 20},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fmulp",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fmulp",  "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fmulp",  "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fmulp",  "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fmulp",  "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fmulp",  "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fmulp",  "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fmulp",  "", 7, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "fcompp", "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",       "",       0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubrp", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubrp", "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubrp", "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubrp", "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubrp", "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubrp", "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubrp", "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubrp", "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubp",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubp",  "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubp",  "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubp",  "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubp",  "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubp",  "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubp",  "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fsubp",  "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivrp", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivrp", "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivrp", "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivrp", "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivrp", "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivrp", "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivrp", "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivrp", "", 7, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivp",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivp",  "", 1, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivp",  "", 2, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivp",  "", 3, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivp",  "", 4, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivp",  "", 5, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivp",  "", 6, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU,  "fdivp",  "", 7, 0, 0, 0, 0}
};


static ia32_insn_t tbl_DF[] = {    /* FPU DF */
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W,  ARG_NONE, ARG_NONE,
                                                                           cpu_80387 |
                                                                           isa_FPU, "fild",   "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W,  ARG_NONE, ARG_NONE, cpu_PENTIUM4 |
                                                                           isa_GP,  "fisttp", "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W,  ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fist",   "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_w | OP_W,  ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fistp",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fb | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fbld",   "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_q | OP_W,  ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fild",   "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_fb | OP_W, ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fbstp",  "", 0, 0, 0, 0, 0},
        {0, INS_FPU, 0, ADDRMETH_M | OPTYPE_q | OP_W,  ARG_NONE, ARG_NONE, cpu_80387 |
                                                                           isa_FPU, "fistp",  "", 0, 0, 0, 0, 0}
};


static ia32_insn_t tbl_DFC0[] = {    /* FPU DF C0 */
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                            cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RR | OPTYPE_w | OP_R,  ARG_NONE, ARG_NONE,
                cpu_80387 | isa_FPU, "fnstsw", "", 0, 0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomip", "", 0, 0, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomip", "", 0, 1, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomip", "", 0, 2, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomip", "", 0, 3, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomip", "", 0, 4, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomip", "", 0, 5, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomip", "", 0, 6, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fucomip", "", 0, 7, 0, 0, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fcomip",  "", 0, 0, 0,
                                                               INS_SET_ZERO | INS_SET_PARITY |
                                                               INS_SET_CARRY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fcomip",  "", 0, 1, 0,
                                                               INS_SET_ZERO | INS_SET_PARITY |
                                                               INS_SET_CARRY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fcomip",  "", 0, 2, 0,
                                                               INS_SET_ZERO | INS_SET_PARITY |
                                                               INS_SET_CARRY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fcomip",  "", 0, 3, 0,
                                                               INS_SET_ZERO | INS_SET_PARITY |
                                                               INS_SET_CARRY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fcomip",  "", 0, 4, 0,
                                                               INS_SET_ZERO | INS_SET_PARITY |
                                                               INS_SET_CARRY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fcomip",  "", 0, 5, 0,
                                                               INS_SET_ZERO | INS_SET_PARITY |
                                                               INS_SET_CARRY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fcomip",  "", 0, 6, 0,
                                                               INS_SET_ZERO | INS_SET_PARITY |
                                                               INS_SET_CARRY, 0},
        {0, INS_FPU,     0, ADDRMETH_RF | OPTYPE_fp | OP_W, ADDRMETH_RF | OPTYPE_fp |
                                                            OP_R,                           ARG_NONE,
                                                                                                     cpu_80387 |
                                                                                                     isa_FPU, "fcomip",  "", 0, 7, 0,
                                                               INS_SET_ZERO | INS_SET_PARITY |
                                                               INS_SET_CARRY, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0},
        {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,                                   cpu_80387 |
                                                                                            isa_FPU, "",      "",        0,  0, 0, 0, 0}
};


static ia32_insn_t tbl_0F0F[] = {    /* 3D Now! 0F Suffix */
        /* 00 */ {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,
                                                                                 cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_CONV,    0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W,
                                                                           ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pi2fd",    "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
        /* 10 */
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_CONV,    0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pf2id",    "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
        /* 20 */
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
        /* 30 */
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
        /* 40 */
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
        /* 50 */
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
        /* 60 */
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
        /* 70 */
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
        /* 80 */
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_CMP,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfcmpge",  "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_MIN,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfmin",    "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_ARITH,   0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfrcp",    "", 0, 0, 0, 0, 0},
                 {0, INS_ARITH,   0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfrsqrt",  "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_SUB,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfsub",    "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_ADD,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfadd",    "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_CMP,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfcmpgt",  "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_MAX,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfmax",    "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_ARITH,   0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfrcpit1", "", 0, 0, 0, 0, 0},
                 {0, INS_ARITH,   0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfrsqit1", "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_SUB,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfsubr",   "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_ADD,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfacc",    "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_CMP,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfcmpeq",  "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_MUL,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfmul",    "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_ARITH,   0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pfrcpit2", "", 0, 0, 0, 0, 0},
                 {0, INS_MUL,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pmulhrw",  "", 0, 0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_INVALID, 0, ARG_NONE, ARG_NONE, ARG_NONE,               cpu_K6 |
                                                                                 isa_3DNOW, "",        "",         0,  0, 0, 0, 0},
                 {0, INS_AVG,     0, ADDRMETH_P | OPTYPE_pi | OP_R | OP_W, ADDRMETH_Q | OPTYPE_q |
                                                                           OP_R, ARG_NONE,  cpu_K6 |
                                                                                            isa_3DNOW, "pavgusb",  "", 0, 0, 0, 0, 0}
};


/* ================== Table of Opcode Tables ================== */
ia32_table_desc_t ia32_tables[] = {
        /* table, prefix table, type, shift, mask, min, max */
        {tbl_Main,   tbl_opcode,    0x00, 0xFF, 0x00, 0xFF},
        {tbl_66,     tbl_prefix,    0x00, 0xFF, 0x0F, 0x0F},
        {tbl_F2,     tbl_prefix,    0x00, 0xFF, 0x0F, 0x0F},
        {tbl_F3,     tbl_prefix,    0x00, 0xFF, 0x0F, 0x90},
        {tbl_0F,     tbl_opcode,    0x00, 0xFF, 0x00, 0xFF},
        /* 5 */
        {tbl_660F,   tbl_prefix,    0x00, 0xFF, 0x10, 0xFF},
        {tbl_F20F,   tbl_prefix,    0x00, 0xFF, 0x10, 0xFF},
        {tbl_F30F,   tbl_prefix,    0x00, 0xFF, 0x10, 0xFF},
        {tbl_0F00,   tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_0F01,   tbl_extension, 0x03, 0x1F, 0x00, 0x1F},
        /* 10 */
        {tbl_0F0111, tbl_ext_ext,   0x00, 0x01, 0x00, 0x01},
        {tbl_0F12,   tbl_extension, 0x06, 0x03, 0x00, 0x03},
        {tbl_0F16,   tbl_extension, 0x06, 0x03, 0x00, 0x03},
        {tbl_0F18,   tbl_extension, 0x03, 0x1F, 0x00, 0x13},
        {tbl_0F71,   tbl_extension, 0x03, 0x1F, 0x00, 0x1F},
        /* 15 */
        {tbl_660F71, tbl_extension, 0x03, 0x1F, 0x00, 0x1F},
        {tbl_0F72,   tbl_extension, 0x03, 0x1F, 0x00, 0x1F},
        {tbl_660F72, tbl_extension, 0x03, 0x1F, 0x00, 0x1F},
        {tbl_0F73,   tbl_extension, 0x00, 0x00, 0x00, 0x00},
        {tbl_660F73, tbl_extension, 0x03, 0x1F, 0x00, 0x1F},
        /* 20 */
        {tbl_0FAE,   tbl_extension, 0x03, 0x1F, 0x00, 0x1F},
        {tbl_0FBA,   tbl_extension, 0x03, 0x07, 0x04, 0x07},
        {tbl_0FC7,   tbl_extension, 0x03, 0x1F, 0x00, 0x11},
        {tbl_0FB9,   tbl_extension, 0x03, 0x07, 0x00, 0x00},
        {tbl_C6,     tbl_extension, 0x03, 0x07, 0x00, 0x00},
        /* 25 */
        {tbl_C7,     tbl_extension, 0x03, 0x07, 0x00, 0x00},
        {tbl_80,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_81,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_82,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_83,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        /* 30 */
        {tbl_C0,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_C1,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_D0,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_D1,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_D2,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        /* 35 */
        {tbl_D3,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_F6,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_F7,     tbl_extension, 0x03, 0x07, 0x00, 0x07},
        {tbl_FE,     tbl_extension, 0x03, 0x07, 0x00, 0x01},
        {tbl_FF,     tbl_extension, 0x03, 0x07, 0x00, 0x06},
        /* 40 */
        {tbl_D8,     tbl_fpu,       0x03, 0x07, 0x00, 0xBF},
        {tbl_D8C0,   tbl_fpu_ext,   0x00, 0xFF, 0xC0, 0xFF},
        {tbl_D9,     tbl_fpu,       0x03, 0x07, 0x00, 0xBF},
        {tbl_D9C0,   tbl_fpu_ext,   0x00, 0xFF, 0xC0, 0xFF},
        {tbl_DA,     tbl_fpu,       0x03, 0x07, 0x00, 0xBF},
        /* 45 */
        {tbl_DAC0,   tbl_fpu_ext,   0x00, 0xFF, 0xC0, 0xFF},
        {tbl_DB,     tbl_fpu,       0x03, 0x07, 0x00, 0xBF},
        {tbl_DBC0,   tbl_fpu_ext,   0x00, 0xFF, 0xC0, 0xFF},
        {tbl_DC,     tbl_fpu,       0x03, 0x07, 0x00, 0xBF},
        {tbl_DCC0,   tbl_fpu_ext,   0x00, 0xFF, 0xC0, 0xFF},
        /* 50 */
        {tbl_DD,     tbl_fpu,       0x03, 0x07, 0x00, 0xBF},
        {tbl_DDC0,   tbl_fpu_ext,   0x00, 0xFF, 0xC0, 0xFF},
        {tbl_DE,     tbl_fpu,       0x03, 0x07, 0x00, 0xBF},
        {tbl_DEC0,   tbl_fpu_ext,   0x00, 0xFF, 0xC0, 0xFF},
        {tbl_DF,     tbl_fpu,       0x03, 0x07, 0x00, 0xBF},
        /* 55 */
        {tbl_DFC0,   tbl_fpu_ext,   0x00, 0xFF, 0xC0, 0xFF},
        {tbl_0F0F,   tbl_suffix,    0x00, 0xFF, 0x00, 0xBF}
};
/* ia32_opcode_tables.h */
/* Table index constants: 
#define idx_Main 0
#define idx_66 1
#define idx_F2 2
#define idx_F3 3
#define idx_0F 4
#define idx_660F 5
#define idx_F20F 6
#define idx_F30F 7
#define idx_0F00 8
#define idx_0F01 9
#define idx_0F0111 10
#define idx_0F12 11
#define idx_0F16 12
#define idx_0F18 13
#define idx_0F71 14
#define idx_660F71 15
#define idx_0F72 16
#define idx_660F72 17
#define idx_0F73 18
#define idx_660F73 19
#define idx_0FAE 20
#define idx_0FBA 21
#define idx_0FC7 22
#define idx_0FB9 23
#define idx_C6 24
#define idx_C7 25
#define idx_80 26
#define idx_81 27
#define idx_82 28
#define idx_83 29
#define idx_C0 30
#define idx_C1 31
#define idx_D0 32
#define idx_D1 33
#define idx_D2 34
#define idx_D3 35
#define idx_F6 36
#define idx_F7 37
#define idx_FE 38
#define idx_FF 39
#define idx_D8 40
#define idx_D8C0 41
#define idx_D9 42
#define idx_D9C0 43
#define idx_DA 44
#define idx_DAC0 45
#define idx_DB 46
#define idx_DBC0 47
#define idx_DC 48
#define idx_DCC0 49
#define idx_DD 50
#define idx_DDC0 51
#define idx_DE 52
#define idx_DEC0 53
#define idx_DF 54
#define idx_DFC0 55
#define idx_0F0F 56
*/ 
