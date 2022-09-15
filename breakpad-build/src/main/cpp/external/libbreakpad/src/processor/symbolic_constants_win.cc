// Copyright (c) 2015 Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// ntstatus_reason_win.h: Windows NTSTATUS code to string.
//
// Provides a means to convert NTSTATUS codes to strings.
//
// Author: Ben Wagner

#include <string>

#include "common/stdio_wrapper.h"
#include "google_breakpad/common/breakpad_types.h"
#include "google_breakpad/common/minidump_exception_win32.h"
#include "processor/symbolic_constants_win.h"

namespace google_breakpad {

    string NTStatusToString(uint32_t ntstatus) {
        string reason;
        // The content of this switch was created from ntstatus.h in the 8.1 SDK with
        //
        // egrep '#define [A-Z_0-9]+\s+\(\(NTSTATUS\)0xC[0-9A-F]+L\)' ntstatus.h
        // | tr -d '\r'
        // | sed -r 's@#define ([A-Z_0-9]+)\s+\(\(NTSTATUS\)(0xC[0-9A-F]+)L\).*@\2 \1@'
        // | sort
        // | sed -r 's@(0xC[0-9A-F]+) ([A-Z_0-9]+)@    case MD_NTSTATUS_WIN_\2:\n      reason = "\2";\n      break;@'
        //
        // With easy copy to clipboard with
        // | xclip -selection c  # on linux
        // | clip  # on windows
        // | pbcopy  # on mac
        //
        // and then the default case added.
        switch (ntstatus) {
            case MD_NTSTATUS_WIN_STATUS_UNSUCCESSFUL:
                reason = "STATUS_UNSUCCESSFUL";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_IMPLEMENTED:
                reason = "STATUS_NOT_IMPLEMENTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_INFO_CLASS:
                reason = "STATUS_INVALID_INFO_CLASS";
                break;
            case MD_NTSTATUS_WIN_STATUS_INFO_LENGTH_MISMATCH:
                reason = "STATUS_INFO_LENGTH_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCESS_VIOLATION:
                reason = "STATUS_ACCESS_VIOLATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_IN_PAGE_ERROR:
                reason = "STATUS_IN_PAGE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_PAGEFILE_QUOTA:
                reason = "STATUS_PAGEFILE_QUOTA";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_HANDLE:
                reason = "STATUS_INVALID_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_INITIAL_STACK:
                reason = "STATUS_BAD_INITIAL_STACK";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_INITIAL_PC:
                reason = "STATUS_BAD_INITIAL_PC";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_CID:
                reason = "STATUS_INVALID_CID";
                break;
            case MD_NTSTATUS_WIN_STATUS_TIMER_NOT_CANCELED:
                reason = "STATUS_TIMER_NOT_CANCELED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER:
                reason = "STATUS_INVALID_PARAMETER";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_DEVICE:
                reason = "STATUS_NO_SUCH_DEVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_FILE:
                reason = "STATUS_NO_SUCH_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_DEVICE_REQUEST:
                reason = "STATUS_INVALID_DEVICE_REQUEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_END_OF_FILE:
                reason = "STATUS_END_OF_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_WRONG_VOLUME:
                reason = "STATUS_WRONG_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_MEDIA_IN_DEVICE:
                reason = "STATUS_NO_MEDIA_IN_DEVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNRECOGNIZED_MEDIA:
                reason = "STATUS_UNRECOGNIZED_MEDIA";
                break;
            case MD_NTSTATUS_WIN_STATUS_NONEXISTENT_SECTOR:
                reason = "STATUS_NONEXISTENT_SECTOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_MORE_PROCESSING_REQUIRED:
                reason = "STATUS_MORE_PROCESSING_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_MEMORY:
                reason = "STATUS_NO_MEMORY";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONFLICTING_ADDRESSES:
                reason = "STATUS_CONFLICTING_ADDRESSES";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_MAPPED_VIEW:
                reason = "STATUS_NOT_MAPPED_VIEW";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNABLE_TO_FREE_VM:
                reason = "STATUS_UNABLE_TO_FREE_VM";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNABLE_TO_DELETE_SECTION:
                reason = "STATUS_UNABLE_TO_DELETE_SECTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_SYSTEM_SERVICE:
                reason = "STATUS_INVALID_SYSTEM_SERVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ILLEGAL_INSTRUCTION:
                reason = "STATUS_ILLEGAL_INSTRUCTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_LOCK_SEQUENCE:
                reason = "STATUS_INVALID_LOCK_SEQUENCE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_VIEW_SIZE:
                reason = "STATUS_INVALID_VIEW_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_FILE_FOR_SECTION:
                reason = "STATUS_INVALID_FILE_FOR_SECTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_ALREADY_COMMITTED:
                reason = "STATUS_ALREADY_COMMITTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCESS_DENIED:
                reason = "STATUS_ACCESS_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BUFFER_TOO_SMALL:
                reason = "STATUS_BUFFER_TOO_SMALL";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECT_TYPE_MISMATCH:
                reason = "STATUS_OBJECT_TYPE_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_NONCONTINUABLE_EXCEPTION:
                reason = "STATUS_NONCONTINUABLE_EXCEPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_DISPOSITION:
                reason = "STATUS_INVALID_DISPOSITION";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNWIND:
                reason = "STATUS_UNWIND";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_STACK:
                reason = "STATUS_BAD_STACK";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_UNWIND_TARGET:
                reason = "STATUS_INVALID_UNWIND_TARGET";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_LOCKED:
                reason = "STATUS_NOT_LOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PARITY_ERROR:
                reason = "STATUS_PARITY_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNABLE_TO_DECOMMIT_VM:
                reason = "STATUS_UNABLE_TO_DECOMMIT_VM";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_COMMITTED:
                reason = "STATUS_NOT_COMMITTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PORT_ATTRIBUTES:
                reason = "STATUS_INVALID_PORT_ATTRIBUTES";
                break;
            case MD_NTSTATUS_WIN_STATUS_PORT_MESSAGE_TOO_LONG:
                reason = "STATUS_PORT_MESSAGE_TOO_LONG";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_MIX:
                reason = "STATUS_INVALID_PARAMETER_MIX";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_QUOTA_LOWER:
                reason = "STATUS_INVALID_QUOTA_LOWER";
                break;
            case MD_NTSTATUS_WIN_STATUS_DISK_CORRUPT_ERROR:
                reason = "STATUS_DISK_CORRUPT_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECT_NAME_INVALID:
                reason = "STATUS_OBJECT_NAME_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECT_NAME_NOT_FOUND:
                reason = "STATUS_OBJECT_NAME_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECT_NAME_COLLISION:
                reason = "STATUS_OBJECT_NAME_COLLISION";
                break;
            case MD_NTSTATUS_WIN_STATUS_PORT_DISCONNECTED:
                reason = "STATUS_PORT_DISCONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_ALREADY_ATTACHED:
                reason = "STATUS_DEVICE_ALREADY_ATTACHED";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECT_PATH_INVALID:
                reason = "STATUS_OBJECT_PATH_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECT_PATH_NOT_FOUND:
                reason = "STATUS_OBJECT_PATH_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECT_PATH_SYNTAX_BAD:
                reason = "STATUS_OBJECT_PATH_SYNTAX_BAD";
                break;
            case MD_NTSTATUS_WIN_STATUS_DATA_OVERRUN:
                reason = "STATUS_DATA_OVERRUN";
                break;
            case MD_NTSTATUS_WIN_STATUS_DATA_LATE_ERROR:
                reason = "STATUS_DATA_LATE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_DATA_ERROR:
                reason = "STATUS_DATA_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_CRC_ERROR:
                reason = "STATUS_CRC_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECTION_TOO_BIG:
                reason = "STATUS_SECTION_TOO_BIG";
                break;
            case MD_NTSTATUS_WIN_STATUS_PORT_CONNECTION_REFUSED:
                reason = "STATUS_PORT_CONNECTION_REFUSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PORT_HANDLE:
                reason = "STATUS_INVALID_PORT_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SHARING_VIOLATION:
                reason = "STATUS_SHARING_VIOLATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_QUOTA_EXCEEDED:
                reason = "STATUS_QUOTA_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PAGE_PROTECTION:
                reason = "STATUS_INVALID_PAGE_PROTECTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUTANT_NOT_OWNED:
                reason = "STATUS_MUTANT_NOT_OWNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SEMAPHORE_LIMIT_EXCEEDED:
                reason = "STATUS_SEMAPHORE_LIMIT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PORT_ALREADY_SET:
                reason = "STATUS_PORT_ALREADY_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECTION_NOT_IMAGE:
                reason = "STATUS_SECTION_NOT_IMAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SUSPEND_COUNT_EXCEEDED:
                reason = "STATUS_SUSPEND_COUNT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREAD_IS_TERMINATING:
                reason = "STATUS_THREAD_IS_TERMINATING";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_WORKING_SET_LIMIT:
                reason = "STATUS_BAD_WORKING_SET_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INCOMPATIBLE_FILE_MAP:
                reason = "STATUS_INCOMPATIBLE_FILE_MAP";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECTION_PROTECTION:
                reason = "STATUS_SECTION_PROTECTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_EAS_NOT_SUPPORTED:
                reason = "STATUS_EAS_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_EA_TOO_LARGE:
                reason = "STATUS_EA_TOO_LARGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NONEXISTENT_EA_ENTRY:
                reason = "STATUS_NONEXISTENT_EA_ENTRY";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_EAS_ON_FILE:
                reason = "STATUS_NO_EAS_ON_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_EA_CORRUPT_ERROR:
                reason = "STATUS_EA_CORRUPT_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_LOCK_CONFLICT:
                reason = "STATUS_FILE_LOCK_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOCK_NOT_GRANTED:
                reason = "STATUS_LOCK_NOT_GRANTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DELETE_PENDING:
                reason = "STATUS_DELETE_PENDING";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTL_FILE_NOT_SUPPORTED:
                reason = "STATUS_CTL_FILE_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNKNOWN_REVISION:
                reason = "STATUS_UNKNOWN_REVISION";
                break;
            case MD_NTSTATUS_WIN_STATUS_REVISION_MISMATCH:
                reason = "STATUS_REVISION_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_OWNER:
                reason = "STATUS_INVALID_OWNER";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PRIMARY_GROUP:
                reason = "STATUS_INVALID_PRIMARY_GROUP";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_IMPERSONATION_TOKEN:
                reason = "STATUS_NO_IMPERSONATION_TOKEN";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_DISABLE_MANDATORY:
                reason = "STATUS_CANT_DISABLE_MANDATORY";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_LOGON_SERVERS:
                reason = "STATUS_NO_LOGON_SERVERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_LOGON_SESSION:
                reason = "STATUS_NO_SUCH_LOGON_SESSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_PRIVILEGE:
                reason = "STATUS_NO_SUCH_PRIVILEGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PRIVILEGE_NOT_HELD:
                reason = "STATUS_PRIVILEGE_NOT_HELD";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_ACCOUNT_NAME:
                reason = "STATUS_INVALID_ACCOUNT_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_USER_EXISTS:
                reason = "STATUS_USER_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_USER:
                reason = "STATUS_NO_SUCH_USER";
                break;
            case MD_NTSTATUS_WIN_STATUS_GROUP_EXISTS:
                reason = "STATUS_GROUP_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_GROUP:
                reason = "STATUS_NO_SUCH_GROUP";
                break;
            case MD_NTSTATUS_WIN_STATUS_MEMBER_IN_GROUP:
                reason = "STATUS_MEMBER_IN_GROUP";
                break;
            case MD_NTSTATUS_WIN_STATUS_MEMBER_NOT_IN_GROUP:
                reason = "STATUS_MEMBER_NOT_IN_GROUP";
                break;
            case MD_NTSTATUS_WIN_STATUS_LAST_ADMIN:
                reason = "STATUS_LAST_ADMIN";
                break;
            case MD_NTSTATUS_WIN_STATUS_WRONG_PASSWORD:
                reason = "STATUS_WRONG_PASSWORD";
                break;
            case MD_NTSTATUS_WIN_STATUS_ILL_FORMED_PASSWORD:
                reason = "STATUS_ILL_FORMED_PASSWORD";
                break;
            case MD_NTSTATUS_WIN_STATUS_PASSWORD_RESTRICTION:
                reason = "STATUS_PASSWORD_RESTRICTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOGON_FAILURE:
                reason = "STATUS_LOGON_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCOUNT_RESTRICTION:
                reason = "STATUS_ACCOUNT_RESTRICTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_LOGON_HOURS:
                reason = "STATUS_INVALID_LOGON_HOURS";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_WORKSTATION:
                reason = "STATUS_INVALID_WORKSTATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_PASSWORD_EXPIRED:
                reason = "STATUS_PASSWORD_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCOUNT_DISABLED:
                reason = "STATUS_ACCOUNT_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NONE_MAPPED:
                reason = "STATUS_NONE_MAPPED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_LUIDS_REQUESTED:
                reason = "STATUS_TOO_MANY_LUIDS_REQUESTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LUIDS_EXHAUSTED:
                reason = "STATUS_LUIDS_EXHAUSTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_SUB_AUTHORITY:
                reason = "STATUS_INVALID_SUB_AUTHORITY";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_ACL:
                reason = "STATUS_INVALID_ACL";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_SID:
                reason = "STATUS_INVALID_SID";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_SECURITY_DESCR:
                reason = "STATUS_INVALID_SECURITY_DESCR";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROCEDURE_NOT_FOUND:
                reason = "STATUS_PROCEDURE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMAGE_FORMAT:
                reason = "STATUS_INVALID_IMAGE_FORMAT";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_TOKEN:
                reason = "STATUS_NO_TOKEN";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_INHERITANCE_ACL:
                reason = "STATUS_BAD_INHERITANCE_ACL";
                break;
            case MD_NTSTATUS_WIN_STATUS_RANGE_NOT_LOCKED:
                reason = "STATUS_RANGE_NOT_LOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DISK_FULL:
                reason = "STATUS_DISK_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_SERVER_DISABLED:
                reason = "STATUS_SERVER_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SERVER_NOT_DISABLED:
                reason = "STATUS_SERVER_NOT_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_GUIDS_REQUESTED:
                reason = "STATUS_TOO_MANY_GUIDS_REQUESTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GUIDS_EXHAUSTED:
                reason = "STATUS_GUIDS_EXHAUSTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_ID_AUTHORITY:
                reason = "STATUS_INVALID_ID_AUTHORITY";
                break;
            case MD_NTSTATUS_WIN_STATUS_AGENTS_EXHAUSTED:
                reason = "STATUS_AGENTS_EXHAUSTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_VOLUME_LABEL:
                reason = "STATUS_INVALID_VOLUME_LABEL";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECTION_NOT_EXTENDED:
                reason = "STATUS_SECTION_NOT_EXTENDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_MAPPED_DATA:
                reason = "STATUS_NOT_MAPPED_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESOURCE_DATA_NOT_FOUND:
                reason = "STATUS_RESOURCE_DATA_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESOURCE_TYPE_NOT_FOUND:
                reason = "STATUS_RESOURCE_TYPE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESOURCE_NAME_NOT_FOUND:
                reason = "STATUS_RESOURCE_NAME_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_ARRAY_BOUNDS_EXCEEDED:
                reason = "STATUS_ARRAY_BOUNDS_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOAT_DENORMAL_OPERAND:
                reason = "STATUS_FLOAT_DENORMAL_OPERAND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOAT_DIVIDE_BY_ZERO:
                reason = "STATUS_FLOAT_DIVIDE_BY_ZERO";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOAT_INEXACT_RESULT:
                reason = "STATUS_FLOAT_INEXACT_RESULT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOAT_INVALID_OPERATION:
                reason = "STATUS_FLOAT_INVALID_OPERATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOAT_OVERFLOW:
                reason = "STATUS_FLOAT_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOAT_STACK_CHECK:
                reason = "STATUS_FLOAT_STACK_CHECK";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOAT_UNDERFLOW:
                reason = "STATUS_FLOAT_UNDERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_INTEGER_DIVIDE_BY_ZERO:
                reason = "STATUS_INTEGER_DIVIDE_BY_ZERO";
                break;
            case MD_NTSTATUS_WIN_STATUS_INTEGER_OVERFLOW:
                reason = "STATUS_INTEGER_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_PRIVILEGED_INSTRUCTION:
                reason = "STATUS_PRIVILEGED_INSTRUCTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_PAGING_FILES:
                reason = "STATUS_TOO_MANY_PAGING_FILES";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_INVALID:
                reason = "STATUS_FILE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_ALLOTTED_SPACE_EXCEEDED:
                reason = "STATUS_ALLOTTED_SPACE_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INSUFFICIENT_RESOURCES:
                reason = "STATUS_INSUFFICIENT_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_DFS_EXIT_PATH_FOUND:
                reason = "STATUS_DFS_EXIT_PATH_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_DATA_ERROR:
                reason = "STATUS_DEVICE_DATA_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_NOT_CONNECTED:
                reason = "STATUS_DEVICE_NOT_CONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_POWER_FAILURE:
                reason = "STATUS_DEVICE_POWER_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FREE_VM_NOT_AT_BASE:
                reason = "STATUS_FREE_VM_NOT_AT_BASE";
                break;
            case MD_NTSTATUS_WIN_STATUS_MEMORY_NOT_ALLOCATED:
                reason = "STATUS_MEMORY_NOT_ALLOCATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_WORKING_SET_QUOTA:
                reason = "STATUS_WORKING_SET_QUOTA";
                break;
            case MD_NTSTATUS_WIN_STATUS_MEDIA_WRITE_PROTECTED:
                reason = "STATUS_MEDIA_WRITE_PROTECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_NOT_READY:
                reason = "STATUS_DEVICE_NOT_READY";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_GROUP_ATTRIBUTES:
                reason = "STATUS_INVALID_GROUP_ATTRIBUTES";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_IMPERSONATION_LEVEL:
                reason = "STATUS_BAD_IMPERSONATION_LEVEL";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_OPEN_ANONYMOUS:
                reason = "STATUS_CANT_OPEN_ANONYMOUS";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_VALIDATION_CLASS:
                reason = "STATUS_BAD_VALIDATION_CLASS";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_TOKEN_TYPE:
                reason = "STATUS_BAD_TOKEN_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_MASTER_BOOT_RECORD:
                reason = "STATUS_BAD_MASTER_BOOT_RECORD";
                break;
            case MD_NTSTATUS_WIN_STATUS_INSTRUCTION_MISALIGNMENT:
                reason = "STATUS_INSTRUCTION_MISALIGNMENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INSTANCE_NOT_AVAILABLE:
                reason = "STATUS_INSTANCE_NOT_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PIPE_NOT_AVAILABLE:
                reason = "STATUS_PIPE_NOT_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PIPE_STATE:
                reason = "STATUS_INVALID_PIPE_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PIPE_BUSY:
                reason = "STATUS_PIPE_BUSY";
                break;
            case MD_NTSTATUS_WIN_STATUS_ILLEGAL_FUNCTION:
                reason = "STATUS_ILLEGAL_FUNCTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_PIPE_DISCONNECTED:
                reason = "STATUS_PIPE_DISCONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PIPE_CLOSING:
                reason = "STATUS_PIPE_CLOSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_PIPE_CONNECTED:
                reason = "STATUS_PIPE_CONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PIPE_LISTENING:
                reason = "STATUS_PIPE_LISTENING";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_READ_MODE:
                reason = "STATUS_INVALID_READ_MODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_TIMEOUT:
                reason = "STATUS_IO_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_FORCED_CLOSED:
                reason = "STATUS_FILE_FORCED_CLOSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROFILING_NOT_STARTED:
                reason = "STATUS_PROFILING_NOT_STARTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROFILING_NOT_STOPPED:
                reason = "STATUS_PROFILING_NOT_STOPPED";
                break;
            case MD_NTSTATUS_WIN_STATUS_COULD_NOT_INTERPRET:
                reason = "STATUS_COULD_NOT_INTERPRET";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_IS_A_DIRECTORY:
                reason = "STATUS_FILE_IS_A_DIRECTORY";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_SUPPORTED:
                reason = "STATUS_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_REMOTE_NOT_LISTENING:
                reason = "STATUS_REMOTE_NOT_LISTENING";
                break;
            case MD_NTSTATUS_WIN_STATUS_DUPLICATE_NAME:
                reason = "STATUS_DUPLICATE_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_NETWORK_PATH:
                reason = "STATUS_BAD_NETWORK_PATH";
                break;
            case MD_NTSTATUS_WIN_STATUS_NETWORK_BUSY:
                reason = "STATUS_NETWORK_BUSY";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_DOES_NOT_EXIST:
                reason = "STATUS_DEVICE_DOES_NOT_EXIST";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_COMMANDS:
                reason = "STATUS_TOO_MANY_COMMANDS";
                break;
            case MD_NTSTATUS_WIN_STATUS_ADAPTER_HARDWARE_ERROR:
                reason = "STATUS_ADAPTER_HARDWARE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_NETWORK_RESPONSE:
                reason = "STATUS_INVALID_NETWORK_RESPONSE";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNEXPECTED_NETWORK_ERROR:
                reason = "STATUS_UNEXPECTED_NETWORK_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_REMOTE_ADAPTER:
                reason = "STATUS_BAD_REMOTE_ADAPTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_PRINT_QUEUE_FULL:
                reason = "STATUS_PRINT_QUEUE_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SPOOL_SPACE:
                reason = "STATUS_NO_SPOOL_SPACE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PRINT_CANCELLED:
                reason = "STATUS_PRINT_CANCELLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NETWORK_NAME_DELETED:
                reason = "STATUS_NETWORK_NAME_DELETED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NETWORK_ACCESS_DENIED:
                reason = "STATUS_NETWORK_ACCESS_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_DEVICE_TYPE:
                reason = "STATUS_BAD_DEVICE_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_NETWORK_NAME:
                reason = "STATUS_BAD_NETWORK_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_NAMES:
                reason = "STATUS_TOO_MANY_NAMES";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_SESSIONS:
                reason = "STATUS_TOO_MANY_SESSIONS";
                break;
            case MD_NTSTATUS_WIN_STATUS_SHARING_PAUSED:
                reason = "STATUS_SHARING_PAUSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_REQUEST_NOT_ACCEPTED:
                reason = "STATUS_REQUEST_NOT_ACCEPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_REDIRECTOR_PAUSED:
                reason = "STATUS_REDIRECTOR_PAUSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NET_WRITE_FAULT:
                reason = "STATUS_NET_WRITE_FAULT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROFILING_AT_LIMIT:
                reason = "STATUS_PROFILING_AT_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_SAME_DEVICE:
                reason = "STATUS_NOT_SAME_DEVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_RENAMED:
                reason = "STATUS_FILE_RENAMED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIRTUAL_CIRCUIT_CLOSED:
                reason = "STATUS_VIRTUAL_CIRCUIT_CLOSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SECURITY_ON_OBJECT:
                reason = "STATUS_NO_SECURITY_ON_OBJECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_WAIT:
                reason = "STATUS_CANT_WAIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PIPE_EMPTY:
                reason = "STATUS_PIPE_EMPTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_ACCESS_DOMAIN_INFO:
                reason = "STATUS_CANT_ACCESS_DOMAIN_INFO";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_TERMINATE_SELF:
                reason = "STATUS_CANT_TERMINATE_SELF";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_SERVER_STATE:
                reason = "STATUS_INVALID_SERVER_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_DOMAIN_STATE:
                reason = "STATUS_INVALID_DOMAIN_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_DOMAIN_ROLE:
                reason = "STATUS_INVALID_DOMAIN_ROLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_DOMAIN:
                reason = "STATUS_NO_SUCH_DOMAIN";
                break;
            case MD_NTSTATUS_WIN_STATUS_DOMAIN_EXISTS:
                reason = "STATUS_DOMAIN_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DOMAIN_LIMIT_EXCEEDED:
                reason = "STATUS_DOMAIN_LIMIT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_OPLOCK_NOT_GRANTED:
                reason = "STATUS_OPLOCK_NOT_GRANTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_OPLOCK_PROTOCOL:
                reason = "STATUS_INVALID_OPLOCK_PROTOCOL";
                break;
            case MD_NTSTATUS_WIN_STATUS_INTERNAL_DB_CORRUPTION:
                reason = "STATUS_INTERNAL_DB_CORRUPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INTERNAL_ERROR:
                reason = "STATUS_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_GENERIC_NOT_MAPPED:
                reason = "STATUS_GENERIC_NOT_MAPPED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_DESCRIPTOR_FORMAT:
                reason = "STATUS_BAD_DESCRIPTOR_FORMAT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_USER_BUFFER:
                reason = "STATUS_INVALID_USER_BUFFER";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNEXPECTED_IO_ERROR:
                reason = "STATUS_UNEXPECTED_IO_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNEXPECTED_MM_CREATE_ERR:
                reason = "STATUS_UNEXPECTED_MM_CREATE_ERR";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNEXPECTED_MM_MAP_ERROR:
                reason = "STATUS_UNEXPECTED_MM_MAP_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNEXPECTED_MM_EXTEND_ERR:
                reason = "STATUS_UNEXPECTED_MM_EXTEND_ERR";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_LOGON_PROCESS:
                reason = "STATUS_NOT_LOGON_PROCESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOGON_SESSION_EXISTS:
                reason = "STATUS_LOGON_SESSION_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_1:
                reason = "STATUS_INVALID_PARAMETER_1";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_2:
                reason = "STATUS_INVALID_PARAMETER_2";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_3:
                reason = "STATUS_INVALID_PARAMETER_3";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_4:
                reason = "STATUS_INVALID_PARAMETER_4";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_5:
                reason = "STATUS_INVALID_PARAMETER_5";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_6:
                reason = "STATUS_INVALID_PARAMETER_6";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_7:
                reason = "STATUS_INVALID_PARAMETER_7";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_8:
                reason = "STATUS_INVALID_PARAMETER_8";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_9:
                reason = "STATUS_INVALID_PARAMETER_9";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_10:
                reason = "STATUS_INVALID_PARAMETER_10";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_11:
                reason = "STATUS_INVALID_PARAMETER_11";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PARAMETER_12:
                reason = "STATUS_INVALID_PARAMETER_12";
                break;
            case MD_NTSTATUS_WIN_STATUS_REDIRECTOR_NOT_STARTED:
                reason = "STATUS_REDIRECTOR_NOT_STARTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_REDIRECTOR_STARTED:
                reason = "STATUS_REDIRECTOR_STARTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_STACK_OVERFLOW:
                reason = "STATUS_STACK_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_PACKAGE:
                reason = "STATUS_NO_SUCH_PACKAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_FUNCTION_TABLE:
                reason = "STATUS_BAD_FUNCTION_TABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VARIABLE_NOT_FOUND:
                reason = "STATUS_VARIABLE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_DIRECTORY_NOT_EMPTY:
                reason = "STATUS_DIRECTORY_NOT_EMPTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_CORRUPT_ERROR:
                reason = "STATUS_FILE_CORRUPT_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_A_DIRECTORY:
                reason = "STATUS_NOT_A_DIRECTORY";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_LOGON_SESSION_STATE:
                reason = "STATUS_BAD_LOGON_SESSION_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOGON_SESSION_COLLISION:
                reason = "STATUS_LOGON_SESSION_COLLISION";
                break;
            case MD_NTSTATUS_WIN_STATUS_NAME_TOO_LONG:
                reason = "STATUS_NAME_TOO_LONG";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILES_OPEN:
                reason = "STATUS_FILES_OPEN";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONNECTION_IN_USE:
                reason = "STATUS_CONNECTION_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_MESSAGE_NOT_FOUND:
                reason = "STATUS_MESSAGE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROCESS_IS_TERMINATING:
                reason = "STATUS_PROCESS_IS_TERMINATING";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_LOGON_TYPE:
                reason = "STATUS_INVALID_LOGON_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_GUID_TRANSLATION:
                reason = "STATUS_NO_GUID_TRANSLATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANNOT_IMPERSONATE:
                reason = "STATUS_CANNOT_IMPERSONATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_IMAGE_ALREADY_LOADED:
                reason = "STATUS_IMAGE_ALREADY_LOADED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ABIOS_NOT_PRESENT:
                reason = "STATUS_ABIOS_NOT_PRESENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_ABIOS_LID_NOT_EXIST:
                reason = "STATUS_ABIOS_LID_NOT_EXIST";
                break;
            case MD_NTSTATUS_WIN_STATUS_ABIOS_LID_ALREADY_OWNED:
                reason = "STATUS_ABIOS_LID_ALREADY_OWNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ABIOS_NOT_LID_OWNER:
                reason = "STATUS_ABIOS_NOT_LID_OWNER";
                break;
            case MD_NTSTATUS_WIN_STATUS_ABIOS_INVALID_COMMAND:
                reason = "STATUS_ABIOS_INVALID_COMMAND";
                break;
            case MD_NTSTATUS_WIN_STATUS_ABIOS_INVALID_LID:
                reason = "STATUS_ABIOS_INVALID_LID";
                break;
            case MD_NTSTATUS_WIN_STATUS_ABIOS_SELECTOR_NOT_AVAILABLE:
                reason = "STATUS_ABIOS_SELECTOR_NOT_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ABIOS_INVALID_SELECTOR:
                reason = "STATUS_ABIOS_INVALID_SELECTOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_LDT:
                reason = "STATUS_NO_LDT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_LDT_SIZE:
                reason = "STATUS_INVALID_LDT_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_LDT_OFFSET:
                reason = "STATUS_INVALID_LDT_OFFSET";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_LDT_DESCRIPTOR:
                reason = "STATUS_INVALID_LDT_DESCRIPTOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMAGE_NE_FORMAT:
                reason = "STATUS_INVALID_IMAGE_NE_FORMAT";
                break;
            case MD_NTSTATUS_WIN_STATUS_RXACT_INVALID_STATE:
                reason = "STATUS_RXACT_INVALID_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_RXACT_COMMIT_FAILURE:
                reason = "STATUS_RXACT_COMMIT_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_MAPPED_FILE_SIZE_ZERO:
                reason = "STATUS_MAPPED_FILE_SIZE_ZERO";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_OPENED_FILES:
                reason = "STATUS_TOO_MANY_OPENED_FILES";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANCELLED:
                reason = "STATUS_CANCELLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANNOT_DELETE:
                reason = "STATUS_CANNOT_DELETE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_COMPUTER_NAME:
                reason = "STATUS_INVALID_COMPUTER_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_DELETED:
                reason = "STATUS_FILE_DELETED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SPECIAL_ACCOUNT:
                reason = "STATUS_SPECIAL_ACCOUNT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SPECIAL_GROUP:
                reason = "STATUS_SPECIAL_GROUP";
                break;
            case MD_NTSTATUS_WIN_STATUS_SPECIAL_USER:
                reason = "STATUS_SPECIAL_USER";
                break;
            case MD_NTSTATUS_WIN_STATUS_MEMBERS_PRIMARY_GROUP:
                reason = "STATUS_MEMBERS_PRIMARY_GROUP";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_CLOSED:
                reason = "STATUS_FILE_CLOSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_THREADS:
                reason = "STATUS_TOO_MANY_THREADS";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREAD_NOT_IN_PROCESS:
                reason = "STATUS_THREAD_NOT_IN_PROCESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOKEN_ALREADY_IN_USE:
                reason = "STATUS_TOKEN_ALREADY_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PAGEFILE_QUOTA_EXCEEDED:
                reason = "STATUS_PAGEFILE_QUOTA_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_COMMITMENT_LIMIT:
                reason = "STATUS_COMMITMENT_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMAGE_LE_FORMAT:
                reason = "STATUS_INVALID_IMAGE_LE_FORMAT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMAGE_NOT_MZ:
                reason = "STATUS_INVALID_IMAGE_NOT_MZ";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMAGE_PROTECT:
                reason = "STATUS_INVALID_IMAGE_PROTECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMAGE_WIN_16:
                reason = "STATUS_INVALID_IMAGE_WIN_16";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOGON_SERVER_CONFLICT:
                reason = "STATUS_LOGON_SERVER_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TIME_DIFFERENCE_AT_DC:
                reason = "STATUS_TIME_DIFFERENCE_AT_DC";
                break;
            case MD_NTSTATUS_WIN_STATUS_SYNCHRONIZATION_REQUIRED:
                reason = "STATUS_SYNCHRONIZATION_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DLL_NOT_FOUND:
                reason = "STATUS_DLL_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_OPEN_FAILED:
                reason = "STATUS_OPEN_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_PRIVILEGE_FAILED:
                reason = "STATUS_IO_PRIVILEGE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ORDINAL_NOT_FOUND:
                reason = "STATUS_ORDINAL_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_ENTRYPOINT_NOT_FOUND:
                reason = "STATUS_ENTRYPOINT_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONTROL_C_EXIT:
                reason = "STATUS_CONTROL_C_EXIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOCAL_DISCONNECT:
                reason = "STATUS_LOCAL_DISCONNECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_REMOTE_DISCONNECT:
                reason = "STATUS_REMOTE_DISCONNECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_REMOTE_RESOURCES:
                reason = "STATUS_REMOTE_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_LINK_FAILED:
                reason = "STATUS_LINK_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LINK_TIMEOUT:
                reason = "STATUS_LINK_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_CONNECTION:
                reason = "STATUS_INVALID_CONNECTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_ADDRESS:
                reason = "STATUS_INVALID_ADDRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DLL_INIT_FAILED:
                reason = "STATUS_DLL_INIT_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_MISSING_SYSTEMFILE:
                reason = "STATUS_MISSING_SYSTEMFILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNHANDLED_EXCEPTION:
                reason = "STATUS_UNHANDLED_EXCEPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_APP_INIT_FAILURE:
                reason = "STATUS_APP_INIT_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PAGEFILE_CREATE_FAILED:
                reason = "STATUS_PAGEFILE_CREATE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_PAGEFILE:
                reason = "STATUS_NO_PAGEFILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_LEVEL:
                reason = "STATUS_INVALID_LEVEL";
                break;
            case MD_NTSTATUS_WIN_STATUS_WRONG_PASSWORD_CORE:
                reason = "STATUS_WRONG_PASSWORD_CORE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ILLEGAL_FLOAT_CONTEXT:
                reason = "STATUS_ILLEGAL_FLOAT_CONTEXT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PIPE_BROKEN:
                reason = "STATUS_PIPE_BROKEN";
                break;
            case MD_NTSTATUS_WIN_STATUS_REGISTRY_CORRUPT:
                reason = "STATUS_REGISTRY_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_REGISTRY_IO_FAILED:
                reason = "STATUS_REGISTRY_IO_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_EVENT_PAIR:
                reason = "STATUS_NO_EVENT_PAIR";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNRECOGNIZED_VOLUME:
                reason = "STATUS_UNRECOGNIZED_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_SERIAL_NO_DEVICE_INITED:
                reason = "STATUS_SERIAL_NO_DEVICE_INITED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_ALIAS:
                reason = "STATUS_NO_SUCH_ALIAS";
                break;
            case MD_NTSTATUS_WIN_STATUS_MEMBER_NOT_IN_ALIAS:
                reason = "STATUS_MEMBER_NOT_IN_ALIAS";
                break;
            case MD_NTSTATUS_WIN_STATUS_MEMBER_IN_ALIAS:
                reason = "STATUS_MEMBER_IN_ALIAS";
                break;
            case MD_NTSTATUS_WIN_STATUS_ALIAS_EXISTS:
                reason = "STATUS_ALIAS_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOGON_NOT_GRANTED:
                reason = "STATUS_LOGON_NOT_GRANTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_SECRETS:
                reason = "STATUS_TOO_MANY_SECRETS";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECRET_TOO_LONG:
                reason = "STATUS_SECRET_TOO_LONG";
                break;
            case MD_NTSTATUS_WIN_STATUS_INTERNAL_DB_ERROR:
                reason = "STATUS_INTERNAL_DB_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FULLSCREEN_MODE:
                reason = "STATUS_FULLSCREEN_MODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_CONTEXT_IDS:
                reason = "STATUS_TOO_MANY_CONTEXT_IDS";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOGON_TYPE_NOT_GRANTED:
                reason = "STATUS_LOGON_TYPE_NOT_GRANTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_REGISTRY_FILE:
                reason = "STATUS_NOT_REGISTRY_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NT_CROSS_ENCRYPTION_REQUIRED:
                reason = "STATUS_NT_CROSS_ENCRYPTION_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DOMAIN_CTRLR_CONFIG_ERROR:
                reason = "STATUS_DOMAIN_CTRLR_CONFIG_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FT_MISSING_MEMBER:
                reason = "STATUS_FT_MISSING_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_ILL_FORMED_SERVICE_ENTRY:
                reason = "STATUS_ILL_FORMED_SERVICE_ENTRY";
                break;
            case MD_NTSTATUS_WIN_STATUS_ILLEGAL_CHARACTER:
                reason = "STATUS_ILLEGAL_CHARACTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNMAPPABLE_CHARACTER:
                reason = "STATUS_UNMAPPABLE_CHARACTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNDEFINED_CHARACTER:
                reason = "STATUS_UNDEFINED_CHARACTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOPPY_VOLUME:
                reason = "STATUS_FLOPPY_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOPPY_ID_MARK_NOT_FOUND:
                reason = "STATUS_FLOPPY_ID_MARK_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOPPY_WRONG_CYLINDER:
                reason = "STATUS_FLOPPY_WRONG_CYLINDER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOPPY_UNKNOWN_ERROR:
                reason = "STATUS_FLOPPY_UNKNOWN_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOPPY_BAD_REGISTERS:
                reason = "STATUS_FLOPPY_BAD_REGISTERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DISK_RECALIBRATE_FAILED:
                reason = "STATUS_DISK_RECALIBRATE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DISK_OPERATION_FAILED:
                reason = "STATUS_DISK_OPERATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DISK_RESET_FAILED:
                reason = "STATUS_DISK_RESET_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SHARED_IRQ_BUSY:
                reason = "STATUS_SHARED_IRQ_BUSY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FT_ORPHANING:
                reason = "STATUS_FT_ORPHANING";
                break;
            case MD_NTSTATUS_WIN_STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT:
                reason = "STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PARTITION_FAILURE:
                reason = "STATUS_PARTITION_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_BLOCK_LENGTH:
                reason = "STATUS_INVALID_BLOCK_LENGTH";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_NOT_PARTITIONED:
                reason = "STATUS_DEVICE_NOT_PARTITIONED";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNABLE_TO_LOCK_MEDIA:
                reason = "STATUS_UNABLE_TO_LOCK_MEDIA";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNABLE_TO_UNLOAD_MEDIA:
                reason = "STATUS_UNABLE_TO_UNLOAD_MEDIA";
                break;
            case MD_NTSTATUS_WIN_STATUS_EOM_OVERFLOW:
                reason = "STATUS_EOM_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_MEDIA:
                reason = "STATUS_NO_MEDIA";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SUCH_MEMBER:
                reason = "STATUS_NO_SUCH_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_MEMBER:
                reason = "STATUS_INVALID_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_KEY_DELETED:
                reason = "STATUS_KEY_DELETED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_LOG_SPACE:
                reason = "STATUS_NO_LOG_SPACE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_SIDS:
                reason = "STATUS_TOO_MANY_SIDS";
                break;
            case MD_NTSTATUS_WIN_STATUS_LM_CROSS_ENCRYPTION_REQUIRED:
                reason = "STATUS_LM_CROSS_ENCRYPTION_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_KEY_HAS_CHILDREN:
                reason = "STATUS_KEY_HAS_CHILDREN";
                break;
            case MD_NTSTATUS_WIN_STATUS_CHILD_MUST_BE_VOLATILE:
                reason = "STATUS_CHILD_MUST_BE_VOLATILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_CONFIGURATION_ERROR:
                reason = "STATUS_DEVICE_CONFIGURATION_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_INTERNAL_ERROR:
                reason = "STATUS_DRIVER_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_DEVICE_STATE:
                reason = "STATUS_INVALID_DEVICE_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_DEVICE_ERROR:
                reason = "STATUS_IO_DEVICE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_PROTOCOL_ERROR:
                reason = "STATUS_DEVICE_PROTOCOL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_BACKUP_CONTROLLER:
                reason = "STATUS_BACKUP_CONTROLLER";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_FILE_FULL:
                reason = "STATUS_LOG_FILE_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_LATE:
                reason = "STATUS_TOO_LATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_TRUST_LSA_SECRET:
                reason = "STATUS_NO_TRUST_LSA_SECRET";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_TRUST_SAM_ACCOUNT:
                reason = "STATUS_NO_TRUST_SAM_ACCOUNT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRUSTED_DOMAIN_FAILURE:
                reason = "STATUS_TRUSTED_DOMAIN_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRUSTED_RELATIONSHIP_FAILURE:
                reason = "STATUS_TRUSTED_RELATIONSHIP_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_EVENTLOG_FILE_CORRUPT:
                reason = "STATUS_EVENTLOG_FILE_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_EVENTLOG_CANT_START:
                reason = "STATUS_EVENTLOG_CANT_START";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRUST_FAILURE:
                reason = "STATUS_TRUST_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUTANT_LIMIT_EXCEEDED:
                reason = "STATUS_MUTANT_LIMIT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NETLOGON_NOT_STARTED:
                reason = "STATUS_NETLOGON_NOT_STARTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCOUNT_EXPIRED:
                reason = "STATUS_ACCOUNT_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_POSSIBLE_DEADLOCK:
                reason = "STATUS_POSSIBLE_DEADLOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_NETWORK_CREDENTIAL_CONFLICT:
                reason = "STATUS_NETWORK_CREDENTIAL_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_REMOTE_SESSION_LIMIT:
                reason = "STATUS_REMOTE_SESSION_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_EVENTLOG_FILE_CHANGED:
                reason = "STATUS_EVENTLOG_FILE_CHANGED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT:
                reason = "STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT:
                reason = "STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOLOGON_SERVER_TRUST_ACCOUNT:
                reason = "STATUS_NOLOGON_SERVER_TRUST_ACCOUNT";
                break;
            case MD_NTSTATUS_WIN_STATUS_DOMAIN_TRUST_INCONSISTENT:
                reason = "STATUS_DOMAIN_TRUST_INCONSISTENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FS_DRIVER_REQUIRED:
                reason = "STATUS_FS_DRIVER_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_IMAGE_ALREADY_LOADED_AS_DLL:
                reason = "STATUS_IMAGE_ALREADY_LOADED_AS_DLL";
                break;
            case MD_NTSTATUS_WIN_STATUS_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING:
                reason = "STATUS_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING";
                break;
            case MD_NTSTATUS_WIN_STATUS_SHORT_NAMES_NOT_ENABLED_ON_VOLUME:
                reason = "STATUS_SHORT_NAMES_NOT_ENABLED_ON_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECURITY_STREAM_IS_INCONSISTENT:
                reason = "STATUS_SECURITY_STREAM_IS_INCONSISTENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_LOCK_RANGE:
                reason = "STATUS_INVALID_LOCK_RANGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_ACE_CONDITION:
                reason = "STATUS_INVALID_ACE_CONDITION";
                break;
            case MD_NTSTATUS_WIN_STATUS_IMAGE_SUBSYSTEM_NOT_PRESENT:
                reason = "STATUS_IMAGE_SUBSYSTEM_NOT_PRESENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOTIFICATION_GUID_ALREADY_DEFINED:
                reason = "STATUS_NOTIFICATION_GUID_ALREADY_DEFINED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_EXCEPTION_HANDLER:
                reason = "STATUS_INVALID_EXCEPTION_HANDLER";
                break;
            case MD_NTSTATUS_WIN_STATUS_DUPLICATE_PRIVILEGES:
                reason = "STATUS_DUPLICATE_PRIVILEGES";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_ALLOWED_ON_SYSTEM_FILE:
                reason = "STATUS_NOT_ALLOWED_ON_SYSTEM_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_REPAIR_NEEDED:
                reason = "STATUS_REPAIR_NEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_QUOTA_NOT_ENABLED:
                reason = "STATUS_QUOTA_NOT_ENABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_APPLICATION_PACKAGE:
                reason = "STATUS_NO_APPLICATION_PACKAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NETWORK_OPEN_RESTRICTION:
                reason = "STATUS_NETWORK_OPEN_RESTRICTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_USER_SESSION_KEY:
                reason = "STATUS_NO_USER_SESSION_KEY";
                break;
            case MD_NTSTATUS_WIN_STATUS_USER_SESSION_DELETED:
                reason = "STATUS_USER_SESSION_DELETED";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESOURCE_LANG_NOT_FOUND:
                reason = "STATUS_RESOURCE_LANG_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_INSUFF_SERVER_RESOURCES:
                reason = "STATUS_INSUFF_SERVER_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_BUFFER_SIZE:
                reason = "STATUS_INVALID_BUFFER_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_ADDRESS_COMPONENT:
                reason = "STATUS_INVALID_ADDRESS_COMPONENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_ADDRESS_WILDCARD:
                reason = "STATUS_INVALID_ADDRESS_WILDCARD";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_ADDRESSES:
                reason = "STATUS_TOO_MANY_ADDRESSES";
                break;
            case MD_NTSTATUS_WIN_STATUS_ADDRESS_ALREADY_EXISTS:
                reason = "STATUS_ADDRESS_ALREADY_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_ADDRESS_CLOSED:
                reason = "STATUS_ADDRESS_CLOSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONNECTION_DISCONNECTED:
                reason = "STATUS_CONNECTION_DISCONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONNECTION_RESET:
                reason = "STATUS_CONNECTION_RESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_NODES:
                reason = "STATUS_TOO_MANY_NODES";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_ABORTED:
                reason = "STATUS_TRANSACTION_ABORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_TIMED_OUT:
                reason = "STATUS_TRANSACTION_TIMED_OUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_NO_RELEASE:
                reason = "STATUS_TRANSACTION_NO_RELEASE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_NO_MATCH:
                reason = "STATUS_TRANSACTION_NO_MATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_RESPONDED:
                reason = "STATUS_TRANSACTION_RESPONDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_INVALID_ID:
                reason = "STATUS_TRANSACTION_INVALID_ID";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_INVALID_TYPE:
                reason = "STATUS_TRANSACTION_INVALID_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_SERVER_SESSION:
                reason = "STATUS_NOT_SERVER_SESSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_CLIENT_SESSION:
                reason = "STATUS_NOT_CLIENT_SESSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANNOT_LOAD_REGISTRY_FILE:
                reason = "STATUS_CANNOT_LOAD_REGISTRY_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEBUG_ATTACH_FAILED:
                reason = "STATUS_DEBUG_ATTACH_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SYSTEM_PROCESS_TERMINATED:
                reason = "STATUS_SYSTEM_PROCESS_TERMINATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DATA_NOT_ACCEPTED:
                reason = "STATUS_DATA_NOT_ACCEPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_BROWSER_SERVERS_FOUND:
                reason = "STATUS_NO_BROWSER_SERVERS_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_VDM_HARD_ERROR:
                reason = "STATUS_VDM_HARD_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_CANCEL_TIMEOUT:
                reason = "STATUS_DRIVER_CANCEL_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_REPLY_MESSAGE_MISMATCH:
                reason = "STATUS_REPLY_MESSAGE_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_MAPPED_ALIGNMENT:
                reason = "STATUS_MAPPED_ALIGNMENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_IMAGE_CHECKSUM_MISMATCH:
                reason = "STATUS_IMAGE_CHECKSUM_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOST_WRITEBEHIND_DATA:
                reason = "STATUS_LOST_WRITEBEHIND_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLIENT_SERVER_PARAMETERS_INVALID:
                reason = "STATUS_CLIENT_SERVER_PARAMETERS_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_PASSWORD_MUST_CHANGE:
                reason = "STATUS_PASSWORD_MUST_CHANGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_FOUND:
                reason = "STATUS_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_TINY_STREAM:
                reason = "STATUS_NOT_TINY_STREAM";
                break;
            case MD_NTSTATUS_WIN_STATUS_RECOVERY_FAILURE:
                reason = "STATUS_RECOVERY_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_STACK_OVERFLOW_READ:
                reason = "STATUS_STACK_OVERFLOW_READ";
                break;
            case MD_NTSTATUS_WIN_STATUS_FAIL_CHECK:
                reason = "STATUS_FAIL_CHECK";
                break;
            case MD_NTSTATUS_WIN_STATUS_DUPLICATE_OBJECTID:
                reason = "STATUS_DUPLICATE_OBJECTID";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECTID_EXISTS:
                reason = "STATUS_OBJECTID_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONVERT_TO_LARGE:
                reason = "STATUS_CONVERT_TO_LARGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_RETRY:
                reason = "STATUS_RETRY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FOUND_OUT_OF_SCOPE:
                reason = "STATUS_FOUND_OUT_OF_SCOPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ALLOCATE_BUCKET:
                reason = "STATUS_ALLOCATE_BUCKET";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROPSET_NOT_FOUND:
                reason = "STATUS_PROPSET_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_MARSHALL_OVERFLOW:
                reason = "STATUS_MARSHALL_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_VARIANT:
                reason = "STATUS_INVALID_VARIANT";
                break;
            case MD_NTSTATUS_WIN_STATUS_DOMAIN_CONTROLLER_NOT_FOUND:
                reason = "STATUS_DOMAIN_CONTROLLER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCOUNT_LOCKED_OUT:
                reason = "STATUS_ACCOUNT_LOCKED_OUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_HANDLE_NOT_CLOSABLE:
                reason = "STATUS_HANDLE_NOT_CLOSABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONNECTION_REFUSED:
                reason = "STATUS_CONNECTION_REFUSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRACEFUL_DISCONNECT:
                reason = "STATUS_GRACEFUL_DISCONNECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_ADDRESS_ALREADY_ASSOCIATED:
                reason = "STATUS_ADDRESS_ALREADY_ASSOCIATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ADDRESS_NOT_ASSOCIATED:
                reason = "STATUS_ADDRESS_NOT_ASSOCIATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONNECTION_INVALID:
                reason = "STATUS_CONNECTION_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONNECTION_ACTIVE:
                reason = "STATUS_CONNECTION_ACTIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NETWORK_UNREACHABLE:
                reason = "STATUS_NETWORK_UNREACHABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HOST_UNREACHABLE:
                reason = "STATUS_HOST_UNREACHABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROTOCOL_UNREACHABLE:
                reason = "STATUS_PROTOCOL_UNREACHABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PORT_UNREACHABLE:
                reason = "STATUS_PORT_UNREACHABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_REQUEST_ABORTED:
                reason = "STATUS_REQUEST_ABORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONNECTION_ABORTED:
                reason = "STATUS_CONNECTION_ABORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_COMPRESSION_BUFFER:
                reason = "STATUS_BAD_COMPRESSION_BUFFER";
                break;
            case MD_NTSTATUS_WIN_STATUS_USER_MAPPED_FILE:
                reason = "STATUS_USER_MAPPED_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_AUDIT_FAILED:
                reason = "STATUS_AUDIT_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TIMER_RESOLUTION_NOT_SET:
                reason = "STATUS_TIMER_RESOLUTION_NOT_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONNECTION_COUNT_LIMIT:
                reason = "STATUS_CONNECTION_COUNT_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOGIN_TIME_RESTRICTION:
                reason = "STATUS_LOGIN_TIME_RESTRICTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOGIN_WKSTA_RESTRICTION:
                reason = "STATUS_LOGIN_WKSTA_RESTRICTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_IMAGE_MP_UP_MISMATCH:
                reason = "STATUS_IMAGE_MP_UP_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_INSUFFICIENT_LOGON_INFO:
                reason = "STATUS_INSUFFICIENT_LOGON_INFO";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_DLL_ENTRYPOINT:
                reason = "STATUS_BAD_DLL_ENTRYPOINT";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_SERVICE_ENTRYPOINT:
                reason = "STATUS_BAD_SERVICE_ENTRYPOINT";
                break;
            case MD_NTSTATUS_WIN_STATUS_LPC_REPLY_LOST:
                reason = "STATUS_LPC_REPLY_LOST";
                break;
            case MD_NTSTATUS_WIN_STATUS_IP_ADDRESS_CONFLICT1:
                reason = "STATUS_IP_ADDRESS_CONFLICT1";
                break;
            case MD_NTSTATUS_WIN_STATUS_IP_ADDRESS_CONFLICT2:
                reason = "STATUS_IP_ADDRESS_CONFLICT2";
                break;
            case MD_NTSTATUS_WIN_STATUS_REGISTRY_QUOTA_LIMIT:
                reason = "STATUS_REGISTRY_QUOTA_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PATH_NOT_COVERED:
                reason = "STATUS_PATH_NOT_COVERED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_CALLBACK_ACTIVE:
                reason = "STATUS_NO_CALLBACK_ACTIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_LICENSE_QUOTA_EXCEEDED:
                reason = "STATUS_LICENSE_QUOTA_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PWD_TOO_SHORT:
                reason = "STATUS_PWD_TOO_SHORT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PWD_TOO_RECENT:
                reason = "STATUS_PWD_TOO_RECENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PWD_HISTORY_CONFLICT:
                reason = "STATUS_PWD_HISTORY_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PLUGPLAY_NO_DEVICE:
                reason = "STATUS_PLUGPLAY_NO_DEVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNSUPPORTED_COMPRESSION:
                reason = "STATUS_UNSUPPORTED_COMPRESSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_HW_PROFILE:
                reason = "STATUS_INVALID_HW_PROFILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PLUGPLAY_DEVICE_PATH:
                reason = "STATUS_INVALID_PLUGPLAY_DEVICE_PATH";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_ORDINAL_NOT_FOUND:
                reason = "STATUS_DRIVER_ORDINAL_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_ENTRYPOINT_NOT_FOUND:
                reason = "STATUS_DRIVER_ENTRYPOINT_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESOURCE_NOT_OWNED:
                reason = "STATUS_RESOURCE_NOT_OWNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_LINKS:
                reason = "STATUS_TOO_MANY_LINKS";
                break;
            case MD_NTSTATUS_WIN_STATUS_QUOTA_LIST_INCONSISTENT:
                reason = "STATUS_QUOTA_LIST_INCONSISTENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_IS_OFFLINE:
                reason = "STATUS_FILE_IS_OFFLINE";
                break;
            case MD_NTSTATUS_WIN_STATUS_EVALUATION_EXPIRATION:
                reason = "STATUS_EVALUATION_EXPIRATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_ILLEGAL_DLL_RELOCATION:
                reason = "STATUS_ILLEGAL_DLL_RELOCATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_LICENSE_VIOLATION:
                reason = "STATUS_LICENSE_VIOLATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_DLL_INIT_FAILED_LOGOFF:
                reason = "STATUS_DLL_INIT_FAILED_LOGOFF";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_UNABLE_TO_LOAD:
                reason = "STATUS_DRIVER_UNABLE_TO_LOAD";
                break;
            case MD_NTSTATUS_WIN_STATUS_DFS_UNAVAILABLE:
                reason = "STATUS_DFS_UNAVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLUME_DISMOUNTED:
                reason = "STATUS_VOLUME_DISMOUNTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_WX86_INTERNAL_ERROR:
                reason = "STATUS_WX86_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_WX86_FLOAT_STACK_CHECK:
                reason = "STATUS_WX86_FLOAT_STACK_CHECK";
                break;
            case MD_NTSTATUS_WIN_STATUS_VALIDATE_CONTINUE:
                reason = "STATUS_VALIDATE_CONTINUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_MATCH:
                reason = "STATUS_NO_MATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_MORE_MATCHES:
                reason = "STATUS_NO_MORE_MATCHES";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_A_REPARSE_POINT:
                reason = "STATUS_NOT_A_REPARSE_POINT";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_REPARSE_TAG_INVALID:
                reason = "STATUS_IO_REPARSE_TAG_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_REPARSE_TAG_MISMATCH:
                reason = "STATUS_IO_REPARSE_TAG_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_REPARSE_DATA_INVALID:
                reason = "STATUS_IO_REPARSE_DATA_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_REPARSE_TAG_NOT_HANDLED:
                reason = "STATUS_IO_REPARSE_TAG_NOT_HANDLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PWD_TOO_LONG:
                reason = "STATUS_PWD_TOO_LONG";
                break;
            case MD_NTSTATUS_WIN_STATUS_STOWED_EXCEPTION:
                reason = "STATUS_STOWED_EXCEPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_REPARSE_POINT_NOT_RESOLVED:
                reason = "STATUS_REPARSE_POINT_NOT_RESOLVED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DIRECTORY_IS_A_REPARSE_POINT:
                reason = "STATUS_DIRECTORY_IS_A_REPARSE_POINT";
                break;
            case MD_NTSTATUS_WIN_STATUS_RANGE_LIST_CONFLICT:
                reason = "STATUS_RANGE_LIST_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SOURCE_ELEMENT_EMPTY:
                reason = "STATUS_SOURCE_ELEMENT_EMPTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_DESTINATION_ELEMENT_FULL:
                reason = "STATUS_DESTINATION_ELEMENT_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_ILLEGAL_ELEMENT_ADDRESS:
                reason = "STATUS_ILLEGAL_ELEMENT_ADDRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_MAGAZINE_NOT_PRESENT:
                reason = "STATUS_MAGAZINE_NOT_PRESENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_REINITIALIZATION_NEEDED:
                reason = "STATUS_REINITIALIZATION_NEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ENCRYPTION_FAILED:
                reason = "STATUS_ENCRYPTION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DECRYPTION_FAILED:
                reason = "STATUS_DECRYPTION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_RANGE_NOT_FOUND:
                reason = "STATUS_RANGE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_RECOVERY_POLICY:
                reason = "STATUS_NO_RECOVERY_POLICY";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_EFS:
                reason = "STATUS_NO_EFS";
                break;
            case MD_NTSTATUS_WIN_STATUS_WRONG_EFS:
                reason = "STATUS_WRONG_EFS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_USER_KEYS:
                reason = "STATUS_NO_USER_KEYS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_NOT_ENCRYPTED:
                reason = "STATUS_FILE_NOT_ENCRYPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_EXPORT_FORMAT:
                reason = "STATUS_NOT_EXPORT_FORMAT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_ENCRYPTED:
                reason = "STATUS_FILE_ENCRYPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_GUID_NOT_FOUND:
                reason = "STATUS_WMI_GUID_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_INSTANCE_NOT_FOUND:
                reason = "STATUS_WMI_INSTANCE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_ITEMID_NOT_FOUND:
                reason = "STATUS_WMI_ITEMID_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_TRY_AGAIN:
                reason = "STATUS_WMI_TRY_AGAIN";
                break;
            case MD_NTSTATUS_WIN_STATUS_SHARED_POLICY:
                reason = "STATUS_SHARED_POLICY";
                break;
            case MD_NTSTATUS_WIN_STATUS_POLICY_OBJECT_NOT_FOUND:
                reason = "STATUS_POLICY_OBJECT_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_POLICY_ONLY_IN_DS:
                reason = "STATUS_POLICY_ONLY_IN_DS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLUME_NOT_UPGRADED:
                reason = "STATUS_VOLUME_NOT_UPGRADED";
                break;
            case MD_NTSTATUS_WIN_STATUS_REMOTE_STORAGE_NOT_ACTIVE:
                reason = "STATUS_REMOTE_STORAGE_NOT_ACTIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_REMOTE_STORAGE_MEDIA_ERROR:
                reason = "STATUS_REMOTE_STORAGE_MEDIA_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_TRACKING_SERVICE:
                reason = "STATUS_NO_TRACKING_SERVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SERVER_SID_MISMATCH:
                reason = "STATUS_SERVER_SID_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_NO_ATTRIBUTE_OR_VALUE:
                reason = "STATUS_DS_NO_ATTRIBUTE_OR_VALUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_INVALID_ATTRIBUTE_SYNTAX:
                reason = "STATUS_DS_INVALID_ATTRIBUTE_SYNTAX";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED:
                reason = "STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS:
                reason = "STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_BUSY:
                reason = "STATUS_DS_BUSY";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_UNAVAILABLE:
                reason = "STATUS_DS_UNAVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_NO_RIDS_ALLOCATED:
                reason = "STATUS_DS_NO_RIDS_ALLOCATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_NO_MORE_RIDS:
                reason = "STATUS_DS_NO_MORE_RIDS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_INCORRECT_ROLE_OWNER:
                reason = "STATUS_DS_INCORRECT_ROLE_OWNER";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_RIDMGR_INIT_ERROR:
                reason = "STATUS_DS_RIDMGR_INIT_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_OBJ_CLASS_VIOLATION:
                reason = "STATUS_DS_OBJ_CLASS_VIOLATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_CANT_ON_NON_LEAF:
                reason = "STATUS_DS_CANT_ON_NON_LEAF";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_CANT_ON_RDN:
                reason = "STATUS_DS_CANT_ON_RDN";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_CANT_MOD_OBJ_CLASS:
                reason = "STATUS_DS_CANT_MOD_OBJ_CLASS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_CROSS_DOM_MOVE_FAILED:
                reason = "STATUS_DS_CROSS_DOM_MOVE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_GC_NOT_AVAILABLE:
                reason = "STATUS_DS_GC_NOT_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DIRECTORY_SERVICE_REQUIRED:
                reason = "STATUS_DIRECTORY_SERVICE_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_REPARSE_ATTRIBUTE_CONFLICT:
                reason = "STATUS_REPARSE_ATTRIBUTE_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_ENABLE_DENY_ONLY:
                reason = "STATUS_CANT_ENABLE_DENY_ONLY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOAT_MULTIPLE_FAULTS:
                reason = "STATUS_FLOAT_MULTIPLE_FAULTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOAT_MULTIPLE_TRAPS:
                reason = "STATUS_FLOAT_MULTIPLE_TRAPS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_REMOVED:
                reason = "STATUS_DEVICE_REMOVED";
                break;
            case MD_NTSTATUS_WIN_STATUS_JOURNAL_DELETE_IN_PROGRESS:
                reason = "STATUS_JOURNAL_DELETE_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_JOURNAL_NOT_ACTIVE:
                reason = "STATUS_JOURNAL_NOT_ACTIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOINTERFACE:
                reason = "STATUS_NOINTERFACE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_RIDMGR_DISABLED:
                reason = "STATUS_DS_RIDMGR_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_ADMIN_LIMIT_EXCEEDED:
                reason = "STATUS_DS_ADMIN_LIMIT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_FAILED_SLEEP:
                reason = "STATUS_DRIVER_FAILED_SLEEP";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUTUAL_AUTHENTICATION_FAILED:
                reason = "STATUS_MUTUAL_AUTHENTICATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CORRUPT_SYSTEM_FILE:
                reason = "STATUS_CORRUPT_SYSTEM_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DATATYPE_MISALIGNMENT_ERROR:
                reason = "STATUS_DATATYPE_MISALIGNMENT_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_READ_ONLY:
                reason = "STATUS_WMI_READ_ONLY";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_SET_FAILURE:
                reason = "STATUS_WMI_SET_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_COMMITMENT_MINIMUM:
                reason = "STATUS_COMMITMENT_MINIMUM";
                break;
            case MD_NTSTATUS_WIN_STATUS_REG_NAT_CONSUMPTION:
                reason = "STATUS_REG_NAT_CONSUMPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSPORT_FULL:
                reason = "STATUS_TRANSPORT_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_SAM_INIT_FAILURE:
                reason = "STATUS_DS_SAM_INIT_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ONLY_IF_CONNECTED:
                reason = "STATUS_ONLY_IF_CONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_SENSITIVE_GROUP_VIOLATION:
                reason = "STATUS_DS_SENSITIVE_GROUP_VIOLATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_PNP_RESTART_ENUMERATION:
                reason = "STATUS_PNP_RESTART_ENUMERATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_JOURNAL_ENTRY_DELETED:
                reason = "STATUS_JOURNAL_ENTRY_DELETED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_CANT_MOD_PRIMARYGROUPID:
                reason = "STATUS_DS_CANT_MOD_PRIMARYGROUPID";
                break;
            case MD_NTSTATUS_WIN_STATUS_SYSTEM_IMAGE_BAD_SIGNATURE:
                reason = "STATUS_SYSTEM_IMAGE_BAD_SIGNATURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PNP_REBOOT_REQUIRED:
                reason = "STATUS_PNP_REBOOT_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_POWER_STATE_INVALID:
                reason = "STATUS_POWER_STATE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_INVALID_GROUP_TYPE:
                reason = "STATUS_DS_INVALID_GROUP_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN:
                reason = "STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN:
                reason = "STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER:
                reason = "STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER:
                reason = "STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER:
                reason = "STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER:
                reason = "STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER:
                reason = "STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_HAVE_PRIMARY_MEMBERS:
                reason = "STATUS_DS_HAVE_PRIMARY_MEMBERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_NOT_SUPPORTED:
                reason = "STATUS_WMI_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INSUFFICIENT_POWER:
                reason = "STATUS_INSUFFICIENT_POWER";
                break;
            case MD_NTSTATUS_WIN_STATUS_SAM_NEED_BOOTKEY_PASSWORD:
                reason = "STATUS_SAM_NEED_BOOTKEY_PASSWORD";
                break;
            case MD_NTSTATUS_WIN_STATUS_SAM_NEED_BOOTKEY_FLOPPY:
                reason = "STATUS_SAM_NEED_BOOTKEY_FLOPPY";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_CANT_START:
                reason = "STATUS_DS_CANT_START";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_INIT_FAILURE:
                reason = "STATUS_DS_INIT_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SAM_INIT_FAILURE:
                reason = "STATUS_SAM_INIT_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_GC_REQUIRED:
                reason = "STATUS_DS_GC_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY:
                reason = "STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS:
                reason = "STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED:
                reason = "STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_MULTIPLE_FAULT_VIOLATION:
                reason = "STATUS_MULTIPLE_FAULT_VIOLATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CURRENT_DOMAIN_NOT_ALLOWED:
                reason = "STATUS_CURRENT_DOMAIN_NOT_ALLOWED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANNOT_MAKE:
                reason = "STATUS_CANNOT_MAKE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SYSTEM_SHUTDOWN:
                reason = "STATUS_SYSTEM_SHUTDOWN";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_INIT_FAILURE_CONSOLE:
                reason = "STATUS_DS_INIT_FAILURE_CONSOLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_SAM_INIT_FAILURE_CONSOLE:
                reason = "STATUS_DS_SAM_INIT_FAILURE_CONSOLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNFINISHED_CONTEXT_DELETED:
                reason = "STATUS_UNFINISHED_CONTEXT_DELETED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_TGT_REPLY:
                reason = "STATUS_NO_TGT_REPLY";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECTID_NOT_FOUND:
                reason = "STATUS_OBJECTID_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_IP_ADDRESSES:
                reason = "STATUS_NO_IP_ADDRESSES";
                break;
            case MD_NTSTATUS_WIN_STATUS_WRONG_CREDENTIAL_HANDLE:
                reason = "STATUS_WRONG_CREDENTIAL_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CRYPTO_SYSTEM_INVALID:
                reason = "STATUS_CRYPTO_SYSTEM_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_MAX_REFERRALS_EXCEEDED:
                reason = "STATUS_MAX_REFERRALS_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUST_BE_KDC:
                reason = "STATUS_MUST_BE_KDC";
                break;
            case MD_NTSTATUS_WIN_STATUS_STRONG_CRYPTO_NOT_SUPPORTED:
                reason = "STATUS_STRONG_CRYPTO_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_PRINCIPALS:
                reason = "STATUS_TOO_MANY_PRINCIPALS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_PA_DATA:
                reason = "STATUS_NO_PA_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_PKINIT_NAME_MISMATCH:
                reason = "STATUS_PKINIT_NAME_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_LOGON_REQUIRED:
                reason = "STATUS_SMARTCARD_LOGON_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_KDC_INVALID_REQUEST:
                reason = "STATUS_KDC_INVALID_REQUEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_KDC_UNABLE_TO_REFER:
                reason = "STATUS_KDC_UNABLE_TO_REFER";
                break;
            case MD_NTSTATUS_WIN_STATUS_KDC_UNKNOWN_ETYPE:
                reason = "STATUS_KDC_UNKNOWN_ETYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SHUTDOWN_IN_PROGRESS:
                reason = "STATUS_SHUTDOWN_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_SERVER_SHUTDOWN_IN_PROGRESS:
                reason = "STATUS_SERVER_SHUTDOWN_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_SUPPORTED_ON_SBS:
                reason = "STATUS_NOT_SUPPORTED_ON_SBS";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_GUID_DISCONNECTED:
                reason = "STATUS_WMI_GUID_DISCONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_ALREADY_DISABLED:
                reason = "STATUS_WMI_ALREADY_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_WMI_ALREADY_ENABLED:
                reason = "STATUS_WMI_ALREADY_ENABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_MFT_TOO_FRAGMENTED:
                reason = "STATUS_MFT_TOO_FRAGMENTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_COPY_PROTECTION_FAILURE:
                reason = "STATUS_COPY_PROTECTION_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CSS_AUTHENTICATION_FAILURE:
                reason = "STATUS_CSS_AUTHENTICATION_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CSS_KEY_NOT_PRESENT:
                reason = "STATUS_CSS_KEY_NOT_PRESENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CSS_KEY_NOT_ESTABLISHED:
                reason = "STATUS_CSS_KEY_NOT_ESTABLISHED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CSS_SCRAMBLED_SECTOR:
                reason = "STATUS_CSS_SCRAMBLED_SECTOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_CSS_REGION_MISMATCH:
                reason = "STATUS_CSS_REGION_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_CSS_RESETS_EXHAUSTED:
                reason = "STATUS_CSS_RESETS_EXHAUSTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PASSWORD_CHANGE_REQUIRED:
                reason = "STATUS_PASSWORD_CHANGE_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PKINIT_FAILURE:
                reason = "STATUS_PKINIT_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_SUBSYSTEM_FAILURE:
                reason = "STATUS_SMARTCARD_SUBSYSTEM_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_KERB_KEY:
                reason = "STATUS_NO_KERB_KEY";
                break;
            case MD_NTSTATUS_WIN_STATUS_HOST_DOWN:
                reason = "STATUS_HOST_DOWN";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNSUPPORTED_PREAUTH:
                reason = "STATUS_UNSUPPORTED_PREAUTH";
                break;
            case MD_NTSTATUS_WIN_STATUS_EFS_ALG_BLOB_TOO_BIG:
                reason = "STATUS_EFS_ALG_BLOB_TOO_BIG";
                break;
            case MD_NTSTATUS_WIN_STATUS_PORT_NOT_SET:
                reason = "STATUS_PORT_NOT_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEBUGGER_INACTIVE:
                reason = "STATUS_DEBUGGER_INACTIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_VERSION_CHECK_FAILURE:
                reason = "STATUS_DS_VERSION_CHECK_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_AUDITING_DISABLED:
                reason = "STATUS_AUDITING_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PRENT4_MACHINE_ACCOUNT:
                reason = "STATUS_PRENT4_MACHINE_ACCOUNT";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER:
                reason = "STATUS_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMAGE_WIN_32:
                reason = "STATUS_INVALID_IMAGE_WIN_32";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMAGE_WIN_64:
                reason = "STATUS_INVALID_IMAGE_WIN_64";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_BINDINGS:
                reason = "STATUS_BAD_BINDINGS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NETWORK_SESSION_EXPIRED:
                reason = "STATUS_NETWORK_SESSION_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_APPHELP_BLOCK:
                reason = "STATUS_APPHELP_BLOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_ALL_SIDS_FILTERED:
                reason = "STATUS_ALL_SIDS_FILTERED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_SAFE_MODE_DRIVER:
                reason = "STATUS_NOT_SAFE_MODE_DRIVER";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCESS_DISABLED_BY_POLICY_DEFAULT:
                reason = "STATUS_ACCESS_DISABLED_BY_POLICY_DEFAULT";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCESS_DISABLED_BY_POLICY_PATH:
                reason = "STATUS_ACCESS_DISABLED_BY_POLICY_PATH";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCESS_DISABLED_BY_POLICY_PUBLISHER:
                reason = "STATUS_ACCESS_DISABLED_BY_POLICY_PUBLISHER";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCESS_DISABLED_BY_POLICY_OTHER:
                reason = "STATUS_ACCESS_DISABLED_BY_POLICY_OTHER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FAILED_DRIVER_ENTRY:
                reason = "STATUS_FAILED_DRIVER_ENTRY";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_ENUMERATION_ERROR:
                reason = "STATUS_DEVICE_ENUMERATION_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_MOUNT_POINT_NOT_RESOLVED:
                reason = "STATUS_MOUNT_POINT_NOT_RESOLVED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_DEVICE_OBJECT_PARAMETER:
                reason = "STATUS_INVALID_DEVICE_OBJECT_PARAMETER";
                break;
            case MD_NTSTATUS_WIN_STATUS_MCA_OCCURED:
                reason = "STATUS_MCA_OCCURED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_BLOCKED_CRITICAL:
                reason = "STATUS_DRIVER_BLOCKED_CRITICAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_BLOCKED:
                reason = "STATUS_DRIVER_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_DATABASE_ERROR:
                reason = "STATUS_DRIVER_DATABASE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_SYSTEM_HIVE_TOO_LARGE:
                reason = "STATUS_SYSTEM_HIVE_TOO_LARGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMPORT_OF_NON_DLL:
                reason = "STATUS_INVALID_IMPORT_OF_NON_DLL";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SECRETS:
                reason = "STATUS_NO_SECRETS";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY:
                reason = "STATUS_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FAILED_STACK_SWITCH:
                reason = "STATUS_FAILED_STACK_SWITCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_HEAP_CORRUPTION:
                reason = "STATUS_HEAP_CORRUPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_WRONG_PIN:
                reason = "STATUS_SMARTCARD_WRONG_PIN";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_CARD_BLOCKED:
                reason = "STATUS_SMARTCARD_CARD_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_CARD_NOT_AUTHENTICATED:
                reason = "STATUS_SMARTCARD_CARD_NOT_AUTHENTICATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_NO_CARD:
                reason = "STATUS_SMARTCARD_NO_CARD";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_NO_KEY_CONTAINER:
                reason = "STATUS_SMARTCARD_NO_KEY_CONTAINER";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_NO_CERTIFICATE:
                reason = "STATUS_SMARTCARD_NO_CERTIFICATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_NO_KEYSET:
                reason = "STATUS_SMARTCARD_NO_KEYSET";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_IO_ERROR:
                reason = "STATUS_SMARTCARD_IO_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_DOWNGRADE_DETECTED:
                reason = "STATUS_DOWNGRADE_DETECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_CERT_REVOKED:
                reason = "STATUS_SMARTCARD_CERT_REVOKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ISSUING_CA_UNTRUSTED:
                reason = "STATUS_ISSUING_CA_UNTRUSTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_REVOCATION_OFFLINE_C:
                reason = "STATUS_REVOCATION_OFFLINE_C";
                break;
            case MD_NTSTATUS_WIN_STATUS_PKINIT_CLIENT_FAILURE:
                reason = "STATUS_PKINIT_CLIENT_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_CERT_EXPIRED:
                reason = "STATUS_SMARTCARD_CERT_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_FAILED_PRIOR_UNLOAD:
                reason = "STATUS_DRIVER_FAILED_PRIOR_UNLOAD";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMARTCARD_SILENT_CONTEXT:
                reason = "STATUS_SMARTCARD_SILENT_CONTEXT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PER_USER_TRUST_QUOTA_EXCEEDED:
                reason = "STATUS_PER_USER_TRUST_QUOTA_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ALL_USER_TRUST_QUOTA_EXCEEDED:
                reason = "STATUS_ALL_USER_TRUST_QUOTA_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_USER_DELETE_TRUST_QUOTA_EXCEEDED:
                reason = "STATUS_USER_DELETE_TRUST_QUOTA_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_NAME_NOT_UNIQUE:
                reason = "STATUS_DS_NAME_NOT_UNIQUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_DUPLICATE_ID_FOUND:
                reason = "STATUS_DS_DUPLICATE_ID_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_GROUP_CONVERSION_ERROR:
                reason = "STATUS_DS_GROUP_CONVERSION_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLSNAP_PREPARE_HIBERNATE:
                reason = "STATUS_VOLSNAP_PREPARE_HIBERNATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_USER2USER_REQUIRED:
                reason = "STATUS_USER2USER_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_STACK_BUFFER_OVERRUN:
                reason = "STATUS_STACK_BUFFER_OVERRUN";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_S4U_PROT_SUPPORT:
                reason = "STATUS_NO_S4U_PROT_SUPPORT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CROSSREALM_DELEGATION_FAILURE:
                reason = "STATUS_CROSSREALM_DELEGATION_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_REVOCATION_OFFLINE_KDC:
                reason = "STATUS_REVOCATION_OFFLINE_KDC";
                break;
            case MD_NTSTATUS_WIN_STATUS_ISSUING_CA_UNTRUSTED_KDC:
                reason = "STATUS_ISSUING_CA_UNTRUSTED_KDC";
                break;
            case MD_NTSTATUS_WIN_STATUS_KDC_CERT_EXPIRED:
                reason = "STATUS_KDC_CERT_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_KDC_CERT_REVOKED:
                reason = "STATUS_KDC_CERT_REVOKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PARAMETER_QUOTA_EXCEEDED:
                reason = "STATUS_PARAMETER_QUOTA_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HIBERNATION_FAILURE:
                reason = "STATUS_HIBERNATION_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DELAY_LOAD_FAILED:
                reason = "STATUS_DELAY_LOAD_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_AUTHENTICATION_FIREWALL_FAILED:
                reason = "STATUS_AUTHENTICATION_FIREWALL_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VDM_DISALLOWED:
                reason = "STATUS_VDM_DISALLOWED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HUNG_DISPLAY_DRIVER_THREAD:
                reason = "STATUS_HUNG_DISPLAY_DRIVER_THREAD";
                break;
            case MD_NTSTATUS_WIN_STATUS_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE:
                reason = "STATUS_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_CRUNTIME_PARAMETER:
                reason = "STATUS_INVALID_CRUNTIME_PARAMETER";
                break;
            case MD_NTSTATUS_WIN_STATUS_NTLM_BLOCKED:
                reason = "STATUS_NTLM_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_SRC_SID_EXISTS_IN_FOREST:
                reason = "STATUS_DS_SRC_SID_EXISTS_IN_FOREST";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_DOMAIN_NAME_EXISTS_IN_FOREST:
                reason = "STATUS_DS_DOMAIN_NAME_EXISTS_IN_FOREST";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_FLAT_NAME_EXISTS_IN_FOREST:
                reason = "STATUS_DS_FLAT_NAME_EXISTS_IN_FOREST";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_USER_PRINCIPAL_NAME:
                reason = "STATUS_INVALID_USER_PRINCIPAL_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_FATAL_USER_CALLBACK_EXCEPTION:
                reason = "STATUS_FATAL_USER_CALLBACK_EXCEPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_ASSERTION_FAILURE:
                reason = "STATUS_ASSERTION_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VERIFIER_STOP:
                reason = "STATUS_VERIFIER_STOP";
                break;
            case MD_NTSTATUS_WIN_STATUS_CALLBACK_POP_STACK:
                reason = "STATUS_CALLBACK_POP_STACK";
                break;
            case MD_NTSTATUS_WIN_STATUS_INCOMPATIBLE_DRIVER_BLOCKED:
                reason = "STATUS_INCOMPATIBLE_DRIVER_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HIVE_UNLOADED:
                reason = "STATUS_HIVE_UNLOADED";
                break;
            case MD_NTSTATUS_WIN_STATUS_COMPRESSION_DISABLED:
                reason = "STATUS_COMPRESSION_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_SYSTEM_LIMITATION:
                reason = "STATUS_FILE_SYSTEM_LIMITATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IMAGE_HASH:
                reason = "STATUS_INVALID_IMAGE_HASH";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_CAPABLE:
                reason = "STATUS_NOT_CAPABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_REQUEST_OUT_OF_SEQUENCE:
                reason = "STATUS_REQUEST_OUT_OF_SEQUENCE";
                break;
            case MD_NTSTATUS_WIN_STATUS_IMPLEMENTATION_LIMIT:
                reason = "STATUS_IMPLEMENTATION_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_ELEVATION_REQUIRED:
                reason = "STATUS_ELEVATION_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SECURITY_CONTEXT:
                reason = "STATUS_NO_SECURITY_CONTEXT";
                break;
            case MD_NTSTATUS_WIN_STATUS_PKU2U_CERT_FAILURE:
                reason = "STATUS_PKU2U_CERT_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_BEYOND_VDL:
                reason = "STATUS_BEYOND_VDL";
                break;
            case MD_NTSTATUS_WIN_STATUS_ENCOUNTERED_WRITE_IN_PROGRESS:
                reason = "STATUS_ENCOUNTERED_WRITE_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_PTE_CHANGED:
                reason = "STATUS_PTE_CHANGED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PURGE_FAILED:
                reason = "STATUS_PURGE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CRED_REQUIRES_CONFIRMATION:
                reason = "STATUS_CRED_REQUIRES_CONFIRMATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CS_ENCRYPTION_INVALID_SERVER_RESPONSE:
                reason = "STATUS_CS_ENCRYPTION_INVALID_SERVER_RESPONSE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CS_ENCRYPTION_UNSUPPORTED_SERVER:
                reason = "STATUS_CS_ENCRYPTION_UNSUPPORTED_SERVER";
                break;
            case MD_NTSTATUS_WIN_STATUS_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE:
                reason = "STATUS_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CS_ENCRYPTION_NEW_ENCRYPTED_FILE:
                reason = "STATUS_CS_ENCRYPTION_NEW_ENCRYPTED_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CS_ENCRYPTION_FILE_NOT_CSE:
                reason = "STATUS_CS_ENCRYPTION_FILE_NOT_CSE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_LABEL:
                reason = "STATUS_INVALID_LABEL";
                break;
            case MD_NTSTATUS_WIN_STATUS_DRIVER_PROCESS_TERMINATED:
                reason = "STATUS_DRIVER_PROCESS_TERMINATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_AMBIGUOUS_SYSTEM_DEVICE:
                reason = "STATUS_AMBIGUOUS_SYSTEM_DEVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SYSTEM_DEVICE_NOT_FOUND:
                reason = "STATUS_SYSTEM_DEVICE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESTART_BOOT_APPLICATION:
                reason = "STATUS_RESTART_BOOT_APPLICATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INSUFFICIENT_NVRAM_RESOURCES:
                reason = "STATUS_INSUFFICIENT_NVRAM_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_SESSION:
                reason = "STATUS_INVALID_SESSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREAD_ALREADY_IN_SESSION:
                reason = "STATUS_THREAD_ALREADY_IN_SESSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREAD_NOT_IN_SESSION:
                reason = "STATUS_THREAD_NOT_IN_SESSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_WEIGHT:
                reason = "STATUS_INVALID_WEIGHT";
                break;
            case MD_NTSTATUS_WIN_STATUS_REQUEST_PAUSED:
                reason = "STATUS_REQUEST_PAUSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_RANGES_PROCESSED:
                reason = "STATUS_NO_RANGES_PROCESSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DISK_RESOURCES_EXHAUSTED:
                reason = "STATUS_DISK_RESOURCES_EXHAUSTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NEEDS_REMEDIATION:
                reason = "STATUS_NEEDS_REMEDIATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_FEATURE_NOT_SUPPORTED:
                reason = "STATUS_DEVICE_FEATURE_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_UNREACHABLE:
                reason = "STATUS_DEVICE_UNREACHABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_TOKEN:
                reason = "STATUS_INVALID_TOKEN";
                break;
            case MD_NTSTATUS_WIN_STATUS_SERVER_UNAVAILABLE:
                reason = "STATUS_SERVER_UNAVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_NOT_AVAILABLE:
                reason = "STATUS_FILE_NOT_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_INSUFFICIENT_RESOURCES:
                reason = "STATUS_DEVICE_INSUFFICIENT_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_PACKAGE_UPDATING:
                reason = "STATUS_PACKAGE_UPDATING";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_READ_FROM_COPY:
                reason = "STATUS_NOT_READ_FROM_COPY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FT_WRITE_FAILURE:
                reason = "STATUS_FT_WRITE_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FT_DI_SCAN_REQUIRED:
                reason = "STATUS_FT_DI_SCAN_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECT_NOT_EXTERNALLY_BACKED:
                reason = "STATUS_OBJECT_NOT_EXTERNALLY_BACKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_EXTERNAL_BACKING_PROVIDER_UNKNOWN:
                reason = "STATUS_EXTERNAL_BACKING_PROVIDER_UNKNOWN";
                break;
            case MD_NTSTATUS_WIN_STATUS_DATA_CHECKSUM_ERROR:
                reason = "STATUS_DATA_CHECKSUM_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_INTERMIXED_KERNEL_EA_OPERATION:
                reason = "STATUS_INTERMIXED_KERNEL_EA_OPERATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRIM_READ_ZERO_NOT_SUPPORTED:
                reason = "STATUS_TRIM_READ_ZERO_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TOO_MANY_SEGMENT_DESCRIPTORS:
                reason = "STATUS_TOO_MANY_SEGMENT_DESCRIPTORS";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_OFFSET_ALIGNMENT:
                reason = "STATUS_INVALID_OFFSET_ALIGNMENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_FIELD_IN_PARAMETER_LIST:
                reason = "STATUS_INVALID_FIELD_IN_PARAMETER_LIST";
                break;
            case MD_NTSTATUS_WIN_STATUS_OPERATION_IN_PROGRESS:
                reason = "STATUS_OPERATION_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_INITIATOR_TARGET_PATH:
                reason = "STATUS_INVALID_INITIATOR_TARGET_PATH";
                break;
            case MD_NTSTATUS_WIN_STATUS_SCRUB_DATA_DISABLED:
                reason = "STATUS_SCRUB_DATA_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_REDUNDANT_STORAGE:
                reason = "STATUS_NOT_REDUNDANT_STORAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESIDENT_FILE_NOT_SUPPORTED:
                reason = "STATUS_RESIDENT_FILE_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_COMPRESSED_FILE_NOT_SUPPORTED:
                reason = "STATUS_COMPRESSED_FILE_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DIRECTORY_NOT_SUPPORTED:
                reason = "STATUS_DIRECTORY_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_OPERATION_TIMEOUT:
                reason = "STATUS_IO_OPERATION_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SYSTEM_NEEDS_REMEDIATION:
                reason = "STATUS_SYSTEM_NEEDS_REMEDIATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_APPX_INTEGRITY_FAILURE_CLR_NGEN:
                reason = "STATUS_APPX_INTEGRITY_FAILURE_CLR_NGEN";
                break;
            case MD_NTSTATUS_WIN_STATUS_SHARE_UNAVAILABLE:
                reason = "STATUS_SHARE_UNAVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_APISET_NOT_HOSTED:
                reason = "STATUS_APISET_NOT_HOSTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_APISET_NOT_PRESENT:
                reason = "STATUS_APISET_NOT_PRESENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_DEVICE_HARDWARE_ERROR:
                reason = "STATUS_DEVICE_HARDWARE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_TASK_NAME:
                reason = "STATUS_INVALID_TASK_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_TASK_INDEX:
                reason = "STATUS_INVALID_TASK_INDEX";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREAD_ALREADY_IN_TASK:
                reason = "STATUS_THREAD_ALREADY_IN_TASK";
                break;
            case MD_NTSTATUS_WIN_STATUS_CALLBACK_BYPASS:
                reason = "STATUS_CALLBACK_BYPASS";
                break;
            case MD_NTSTATUS_WIN_STATUS_UNDEFINED_SCOPE:
                reason = "STATUS_UNDEFINED_SCOPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_CAP:
                reason = "STATUS_INVALID_CAP";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_GUI_PROCESS:
                reason = "STATUS_NOT_GUI_PROCESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FAIL_FAST_EXCEPTION:
                reason = "STATUS_FAIL_FAST_EXCEPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_IMAGE_CERT_REVOKED:
                reason = "STATUS_IMAGE_CERT_REVOKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DYNAMIC_CODE_BLOCKED:
                reason = "STATUS_DYNAMIC_CODE_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PORT_CLOSED:
                reason = "STATUS_PORT_CLOSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_MESSAGE_LOST:
                reason = "STATUS_MESSAGE_LOST";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_MESSAGE:
                reason = "STATUS_INVALID_MESSAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_REQUEST_CANCELED:
                reason = "STATUS_REQUEST_CANCELED";
                break;
            case MD_NTSTATUS_WIN_STATUS_RECURSIVE_DISPATCH:
                reason = "STATUS_RECURSIVE_DISPATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_LPC_RECEIVE_BUFFER_EXPECTED:
                reason = "STATUS_LPC_RECEIVE_BUFFER_EXPECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LPC_INVALID_CONNECTION_USAGE:
                reason = "STATUS_LPC_INVALID_CONNECTION_USAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_LPC_REQUESTS_NOT_ALLOWED:
                reason = "STATUS_LPC_REQUESTS_NOT_ALLOWED";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESOURCE_IN_USE:
                reason = "STATUS_RESOURCE_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HARDWARE_MEMORY_ERROR:
                reason = "STATUS_HARDWARE_MEMORY_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREADPOOL_HANDLE_EXCEPTION:
                reason = "STATUS_THREADPOOL_HANDLE_EXCEPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREADPOOL_SET_EVENT_ON_COMPLETION_FAILED:
                reason = "STATUS_THREADPOOL_SET_EVENT_ON_COMPLETION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREADPOOL_RELEASE_SEMAPHORE_ON_COMPLETION_FAILED:
                reason = "STATUS_THREADPOOL_RELEASE_SEMAPHORE_ON_COMPLETION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREADPOOL_RELEASE_MUTEX_ON_COMPLETION_FAILED:
                reason = "STATUS_THREADPOOL_RELEASE_MUTEX_ON_COMPLETION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREADPOOL_FREE_LIBRARY_ON_COMPLETION_FAILED:
                reason = "STATUS_THREADPOOL_FREE_LIBRARY_ON_COMPLETION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_THREADPOOL_RELEASED_DURING_OPERATION:
                reason = "STATUS_THREADPOOL_RELEASED_DURING_OPERATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CALLBACK_RETURNED_WHILE_IMPERSONATING:
                reason = "STATUS_CALLBACK_RETURNED_WHILE_IMPERSONATING";
                break;
            case MD_NTSTATUS_WIN_STATUS_APC_RETURNED_WHILE_IMPERSONATING:
                reason = "STATUS_APC_RETURNED_WHILE_IMPERSONATING";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROCESS_IS_PROTECTED:
                reason = "STATUS_PROCESS_IS_PROTECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_MCA_EXCEPTION:
                reason = "STATUS_MCA_EXCEPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CERTIFICATE_MAPPING_NOT_UNIQUE:
                reason = "STATUS_CERTIFICATE_MAPPING_NOT_UNIQUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SYMLINK_CLASS_DISABLED:
                reason = "STATUS_SYMLINK_CLASS_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_IDN_NORMALIZATION:
                reason = "STATUS_INVALID_IDN_NORMALIZATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_UNICODE_TRANSLATION:
                reason = "STATUS_NO_UNICODE_TRANSLATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_ALREADY_REGISTERED:
                reason = "STATUS_ALREADY_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONTEXT_MISMATCH:
                reason = "STATUS_CONTEXT_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_PORT_ALREADY_HAS_COMPLETION_LIST:
                reason = "STATUS_PORT_ALREADY_HAS_COMPLETION_LIST";
                break;
            case MD_NTSTATUS_WIN_STATUS_CALLBACK_RETURNED_THREAD_PRIORITY:
                reason = "STATUS_CALLBACK_RETURNED_THREAD_PRIORITY";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_THREAD:
                reason = "STATUS_INVALID_THREAD";
                break;
            case MD_NTSTATUS_WIN_STATUS_CALLBACK_RETURNED_TRANSACTION:
                reason = "STATUS_CALLBACK_RETURNED_TRANSACTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CALLBACK_RETURNED_LDR_LOCK:
                reason = "STATUS_CALLBACK_RETURNED_LDR_LOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_CALLBACK_RETURNED_LANG:
                reason = "STATUS_CALLBACK_RETURNED_LANG";
                break;
            case MD_NTSTATUS_WIN_STATUS_CALLBACK_RETURNED_PRI_BACK:
                reason = "STATUS_CALLBACK_RETURNED_PRI_BACK";
                break;
            case MD_NTSTATUS_WIN_STATUS_CALLBACK_RETURNED_THREAD_AFFINITY:
                reason = "STATUS_CALLBACK_RETURNED_THREAD_AFFINITY";
                break;
            case MD_NTSTATUS_WIN_STATUS_DISK_REPAIR_DISABLED:
                reason = "STATUS_DISK_REPAIR_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_DOMAIN_RENAME_IN_PROGRESS:
                reason = "STATUS_DS_DOMAIN_RENAME_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DISK_QUOTA_EXCEEDED:
                reason = "STATUS_DISK_QUOTA_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CONTENT_BLOCKED:
                reason = "STATUS_CONTENT_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_CLUSTERS:
                reason = "STATUS_BAD_CLUSTERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLUME_DIRTY:
                reason = "STATUS_VOLUME_DIRTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_DISK_REPAIR_UNSUCCESSFUL:
                reason = "STATUS_DISK_REPAIR_UNSUCCESSFUL";
                break;
            case MD_NTSTATUS_WIN_STATUS_CORRUPT_LOG_OVERFULL:
                reason = "STATUS_CORRUPT_LOG_OVERFULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_CORRUPT_LOG_CORRUPTED:
                reason = "STATUS_CORRUPT_LOG_CORRUPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CORRUPT_LOG_UNAVAILABLE:
                reason = "STATUS_CORRUPT_LOG_UNAVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CORRUPT_LOG_DELETED_FULL:
                reason = "STATUS_CORRUPT_LOG_DELETED_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_CORRUPT_LOG_CLEARED:
                reason = "STATUS_CORRUPT_LOG_CLEARED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ORPHAN_NAME_EXHAUSTED:
                reason = "STATUS_ORPHAN_NAME_EXHAUSTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROACTIVE_SCAN_IN_PROGRESS:
                reason = "STATUS_PROACTIVE_SCAN_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_ENCRYPTED_IO_NOT_POSSIBLE:
                reason = "STATUS_ENCRYPTED_IO_NOT_POSSIBLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CORRUPT_LOG_UPLEVEL_RECORDS:
                reason = "STATUS_CORRUPT_LOG_UPLEVEL_RECORDS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_CHECKED_OUT:
                reason = "STATUS_FILE_CHECKED_OUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CHECKOUT_REQUIRED:
                reason = "STATUS_CHECKOUT_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_FILE_TYPE:
                reason = "STATUS_BAD_FILE_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_TOO_LARGE:
                reason = "STATUS_FILE_TOO_LARGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FORMS_AUTH_REQUIRED:
                reason = "STATUS_FORMS_AUTH_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIRUS_INFECTED:
                reason = "STATUS_VIRUS_INFECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIRUS_DELETED:
                reason = "STATUS_VIRUS_DELETED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_MCFG_TABLE:
                reason = "STATUS_BAD_MCFG_TABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANNOT_BREAK_OPLOCK:
                reason = "STATUS_CANNOT_BREAK_OPLOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_KEY:
                reason = "STATUS_BAD_KEY";
                break;
            case MD_NTSTATUS_WIN_STATUS_BAD_DATA:
                reason = "STATUS_BAD_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_KEY:
                reason = "STATUS_NO_KEY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_HANDLE_REVOKED:
                reason = "STATUS_FILE_HANDLE_REVOKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_WOW_ASSERTION:
                reason = "STATUS_WOW_ASSERTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_SIGNATURE:
                reason = "STATUS_INVALID_SIGNATURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HMAC_NOT_SUPPORTED:
                reason = "STATUS_HMAC_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_AUTH_TAG_MISMATCH:
                reason = "STATUS_AUTH_TAG_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_STATE_TRANSITION:
                reason = "STATUS_INVALID_STATE_TRANSITION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_KERNEL_INFO_VERSION:
                reason = "STATUS_INVALID_KERNEL_INFO_VERSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PEP_INFO_VERSION:
                reason = "STATUS_INVALID_PEP_INFO_VERSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_QUEUE_OVERFLOW:
                reason = "STATUS_IPSEC_QUEUE_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_ND_QUEUE_OVERFLOW:
                reason = "STATUS_ND_QUEUE_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_HOPLIMIT_EXCEEDED:
                reason = "STATUS_HOPLIMIT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PROTOCOL_NOT_SUPPORTED:
                reason = "STATUS_PROTOCOL_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FASTPATH_REJECTED:
                reason = "STATUS_FASTPATH_REJECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED:
                reason = "STATUS_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR:
                reason = "STATUS_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR:
                reason = "STATUS_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_XML_PARSE_ERROR:
                reason = "STATUS_XML_PARSE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_XMLDSIG_ERROR:
                reason = "STATUS_XMLDSIG_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_WRONG_COMPARTMENT:
                reason = "STATUS_WRONG_COMPARTMENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_AUTHIP_FAILURE:
                reason = "STATUS_AUTHIP_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS:
                reason = "STATUS_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_DS_OID_NOT_FOUND:
                reason = "STATUS_DS_OID_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_INCORRECT_ACCOUNT_TYPE:
                reason = "STATUS_INCORRECT_ACCOUNT_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HASH_NOT_SUPPORTED:
                reason = "STATUS_HASH_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HASH_NOT_PRESENT:
                reason = "STATUS_HASH_NOT_PRESENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECONDARY_IC_PROVIDER_NOT_REGISTERED:
                reason = "STATUS_SECONDARY_IC_PROVIDER_NOT_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GPIO_CLIENT_INFORMATION_INVALID:
                reason = "STATUS_GPIO_CLIENT_INFORMATION_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_GPIO_VERSION_NOT_SUPPORTED:
                reason = "STATUS_GPIO_VERSION_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GPIO_INVALID_REGISTRATION_PACKET:
                reason = "STATUS_GPIO_INVALID_REGISTRATION_PACKET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GPIO_OPERATION_DENIED:
                reason = "STATUS_GPIO_OPERATION_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GPIO_INCOMPATIBLE_CONNECT_MODE:
                reason = "STATUS_GPIO_INCOMPATIBLE_CONNECT_MODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANNOT_SWITCH_RUNLEVEL:
                reason = "STATUS_CANNOT_SWITCH_RUNLEVEL";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_RUNLEVEL_SETTING:
                reason = "STATUS_INVALID_RUNLEVEL_SETTING";
                break;
            case MD_NTSTATUS_WIN_STATUS_RUNLEVEL_SWITCH_TIMEOUT:
                reason = "STATUS_RUNLEVEL_SWITCH_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_RUNLEVEL_SWITCH_AGENT_TIMEOUT:
                reason = "STATUS_RUNLEVEL_SWITCH_AGENT_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_RUNLEVEL_SWITCH_IN_PROGRESS:
                reason = "STATUS_RUNLEVEL_SWITCH_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_APPCONTAINER:
                reason = "STATUS_NOT_APPCONTAINER";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_SUPPORTED_IN_APPCONTAINER:
                reason = "STATUS_NOT_SUPPORTED_IN_APPCONTAINER";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_PACKAGE_SID_LENGTH:
                reason = "STATUS_INVALID_PACKAGE_SID_LENGTH";
                break;
            case MD_NTSTATUS_WIN_STATUS_APP_DATA_NOT_FOUND:
                reason = "STATUS_APP_DATA_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_APP_DATA_EXPIRED:
                reason = "STATUS_APP_DATA_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_APP_DATA_CORRUPT:
                reason = "STATUS_APP_DATA_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_APP_DATA_LIMIT_EXCEEDED:
                reason = "STATUS_APP_DATA_LIMIT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_APP_DATA_REBOOT_REQUIRED:
                reason = "STATUS_APP_DATA_REBOOT_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_OFFLOAD_READ_FLT_NOT_SUPPORTED:
                reason = "STATUS_OFFLOAD_READ_FLT_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_OFFLOAD_WRITE_FLT_NOT_SUPPORTED:
                reason = "STATUS_OFFLOAD_WRITE_FLT_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_OFFLOAD_READ_FILE_NOT_SUPPORTED:
                reason = "STATUS_OFFLOAD_READ_FILE_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_OFFLOAD_WRITE_FILE_NOT_SUPPORTED:
                reason = "STATUS_OFFLOAD_WRITE_FILE_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_DBG_NO_STATE_CHANGE:
                reason = "DBG_NO_STATE_CHANGE";
                break;
            case MD_NTSTATUS_WIN_DBG_APP_NOT_IDLE:
                reason = "DBG_APP_NOT_IDLE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_STRING_BINDING:
                reason = "RPC_NT_INVALID_STRING_BINDING";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_WRONG_KIND_OF_BINDING:
                reason = "RPC_NT_WRONG_KIND_OF_BINDING";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_BINDING:
                reason = "RPC_NT_INVALID_BINDING";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_PROTSEQ_NOT_SUPPORTED:
                reason = "RPC_NT_PROTSEQ_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_RPC_PROTSEQ:
                reason = "RPC_NT_INVALID_RPC_PROTSEQ";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_STRING_UUID:
                reason = "RPC_NT_INVALID_STRING_UUID";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_ENDPOINT_FORMAT:
                reason = "RPC_NT_INVALID_ENDPOINT_FORMAT";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_NET_ADDR:
                reason = "RPC_NT_INVALID_NET_ADDR";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_ENDPOINT_FOUND:
                reason = "RPC_NT_NO_ENDPOINT_FOUND";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_TIMEOUT:
                reason = "RPC_NT_INVALID_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_OBJECT_NOT_FOUND:
                reason = "RPC_NT_OBJECT_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_ALREADY_REGISTERED:
                reason = "RPC_NT_ALREADY_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_TYPE_ALREADY_REGISTERED:
                reason = "RPC_NT_TYPE_ALREADY_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_ALREADY_LISTENING:
                reason = "RPC_NT_ALREADY_LISTENING";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_PROTSEQS_REGISTERED:
                reason = "RPC_NT_NO_PROTSEQS_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NOT_LISTENING:
                reason = "RPC_NT_NOT_LISTENING";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNKNOWN_MGR_TYPE:
                reason = "RPC_NT_UNKNOWN_MGR_TYPE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNKNOWN_IF:
                reason = "RPC_NT_UNKNOWN_IF";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_BINDINGS:
                reason = "RPC_NT_NO_BINDINGS";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_PROTSEQS:
                reason = "RPC_NT_NO_PROTSEQS";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_CANT_CREATE_ENDPOINT:
                reason = "RPC_NT_CANT_CREATE_ENDPOINT";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_OUT_OF_RESOURCES:
                reason = "RPC_NT_OUT_OF_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SERVER_UNAVAILABLE:
                reason = "RPC_NT_SERVER_UNAVAILABLE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SERVER_TOO_BUSY:
                reason = "RPC_NT_SERVER_TOO_BUSY";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_NETWORK_OPTIONS:
                reason = "RPC_NT_INVALID_NETWORK_OPTIONS";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_CALL_ACTIVE:
                reason = "RPC_NT_NO_CALL_ACTIVE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_CALL_FAILED:
                reason = "RPC_NT_CALL_FAILED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_CALL_FAILED_DNE:
                reason = "RPC_NT_CALL_FAILED_DNE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_PROTOCOL_ERROR:
                reason = "RPC_NT_PROTOCOL_ERROR";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNSUPPORTED_TRANS_SYN:
                reason = "RPC_NT_UNSUPPORTED_TRANS_SYN";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNSUPPORTED_TYPE:
                reason = "RPC_NT_UNSUPPORTED_TYPE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_TAG:
                reason = "RPC_NT_INVALID_TAG";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_BOUND:
                reason = "RPC_NT_INVALID_BOUND";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_ENTRY_NAME:
                reason = "RPC_NT_NO_ENTRY_NAME";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_NAME_SYNTAX:
                reason = "RPC_NT_INVALID_NAME_SYNTAX";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNSUPPORTED_NAME_SYNTAX:
                reason = "RPC_NT_UNSUPPORTED_NAME_SYNTAX";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UUID_NO_ADDRESS:
                reason = "RPC_NT_UUID_NO_ADDRESS";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_DUPLICATE_ENDPOINT:
                reason = "RPC_NT_DUPLICATE_ENDPOINT";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNKNOWN_AUTHN_TYPE:
                reason = "RPC_NT_UNKNOWN_AUTHN_TYPE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_MAX_CALLS_TOO_SMALL:
                reason = "RPC_NT_MAX_CALLS_TOO_SMALL";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_STRING_TOO_LONG:
                reason = "RPC_NT_STRING_TOO_LONG";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_PROTSEQ_NOT_FOUND:
                reason = "RPC_NT_PROTSEQ_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_PROCNUM_OUT_OF_RANGE:
                reason = "RPC_NT_PROCNUM_OUT_OF_RANGE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_BINDING_HAS_NO_AUTH:
                reason = "RPC_NT_BINDING_HAS_NO_AUTH";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNKNOWN_AUTHN_SERVICE:
                reason = "RPC_NT_UNKNOWN_AUTHN_SERVICE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNKNOWN_AUTHN_LEVEL:
                reason = "RPC_NT_UNKNOWN_AUTHN_LEVEL";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_AUTH_IDENTITY:
                reason = "RPC_NT_INVALID_AUTH_IDENTITY";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNKNOWN_AUTHZ_SERVICE:
                reason = "RPC_NT_UNKNOWN_AUTHZ_SERVICE";
                break;
            case MD_NTSTATUS_WIN_EPT_NT_INVALID_ENTRY:
                reason = "EPT_NT_INVALID_ENTRY";
                break;
            case MD_NTSTATUS_WIN_EPT_NT_CANT_PERFORM_OP:
                reason = "EPT_NT_CANT_PERFORM_OP";
                break;
            case MD_NTSTATUS_WIN_EPT_NT_NOT_REGISTERED:
                reason = "EPT_NT_NOT_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NOTHING_TO_EXPORT:
                reason = "RPC_NT_NOTHING_TO_EXPORT";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INCOMPLETE_NAME:
                reason = "RPC_NT_INCOMPLETE_NAME";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_VERS_OPTION:
                reason = "RPC_NT_INVALID_VERS_OPTION";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_MORE_MEMBERS:
                reason = "RPC_NT_NO_MORE_MEMBERS";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NOT_ALL_OBJS_UNEXPORTED:
                reason = "RPC_NT_NOT_ALL_OBJS_UNEXPORTED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INTERFACE_NOT_FOUND:
                reason = "RPC_NT_INTERFACE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_ENTRY_ALREADY_EXISTS:
                reason = "RPC_NT_ENTRY_ALREADY_EXISTS";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_ENTRY_NOT_FOUND:
                reason = "RPC_NT_ENTRY_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NAME_SERVICE_UNAVAILABLE:
                reason = "RPC_NT_NAME_SERVICE_UNAVAILABLE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_NAF_ID:
                reason = "RPC_NT_INVALID_NAF_ID";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_CANNOT_SUPPORT:
                reason = "RPC_NT_CANNOT_SUPPORT";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_CONTEXT_AVAILABLE:
                reason = "RPC_NT_NO_CONTEXT_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INTERNAL_ERROR:
                reason = "RPC_NT_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_ZERO_DIVIDE:
                reason = "RPC_NT_ZERO_DIVIDE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_ADDRESS_ERROR:
                reason = "RPC_NT_ADDRESS_ERROR";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_FP_DIV_ZERO:
                reason = "RPC_NT_FP_DIV_ZERO";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_FP_UNDERFLOW:
                reason = "RPC_NT_FP_UNDERFLOW";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_FP_OVERFLOW:
                reason = "RPC_NT_FP_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_CALL_IN_PROGRESS:
                reason = "RPC_NT_CALL_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_MORE_BINDINGS:
                reason = "RPC_NT_NO_MORE_BINDINGS";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_GROUP_MEMBER_NOT_FOUND:
                reason = "RPC_NT_GROUP_MEMBER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_EPT_NT_CANT_CREATE:
                reason = "EPT_NT_CANT_CREATE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_OBJECT:
                reason = "RPC_NT_INVALID_OBJECT";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_INTERFACES:
                reason = "RPC_NT_NO_INTERFACES";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_CALL_CANCELLED:
                reason = "RPC_NT_CALL_CANCELLED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_BINDING_INCOMPLETE:
                reason = "RPC_NT_BINDING_INCOMPLETE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_COMM_FAILURE:
                reason = "RPC_NT_COMM_FAILURE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_UNSUPPORTED_AUTHN_LEVEL:
                reason = "RPC_NT_UNSUPPORTED_AUTHN_LEVEL";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_PRINC_NAME:
                reason = "RPC_NT_NO_PRINC_NAME";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NOT_RPC_ERROR:
                reason = "RPC_NT_NOT_RPC_ERROR";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SEC_PKG_ERROR:
                reason = "RPC_NT_SEC_PKG_ERROR";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NOT_CANCELLED:
                reason = "RPC_NT_NOT_CANCELLED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_ASYNC_HANDLE:
                reason = "RPC_NT_INVALID_ASYNC_HANDLE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_ASYNC_CALL:
                reason = "RPC_NT_INVALID_ASYNC_CALL";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_PROXY_ACCESS_DENIED:
                reason = "RPC_NT_PROXY_ACCESS_DENIED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_COOKIE_AUTH_FAILED:
                reason = "RPC_NT_COOKIE_AUTH_FAILED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NO_MORE_ENTRIES:
                reason = "RPC_NT_NO_MORE_ENTRIES";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SS_CHAR_TRANS_OPEN_FAIL:
                reason = "RPC_NT_SS_CHAR_TRANS_OPEN_FAIL";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SS_CHAR_TRANS_SHORT_FILE:
                reason = "RPC_NT_SS_CHAR_TRANS_SHORT_FILE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SS_IN_NULL_CONTEXT:
                reason = "RPC_NT_SS_IN_NULL_CONTEXT";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SS_CONTEXT_MISMATCH:
                reason = "RPC_NT_SS_CONTEXT_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SS_CONTEXT_DAMAGED:
                reason = "RPC_NT_SS_CONTEXT_DAMAGED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SS_HANDLES_MISMATCH:
                reason = "RPC_NT_SS_HANDLES_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_SS_CANNOT_GET_CALL_HANDLE:
                reason = "RPC_NT_SS_CANNOT_GET_CALL_HANDLE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_NULL_REF_POINTER:
                reason = "RPC_NT_NULL_REF_POINTER";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_ENUM_VALUE_OUT_OF_RANGE:
                reason = "RPC_NT_ENUM_VALUE_OUT_OF_RANGE";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_BYTE_COUNT_TOO_SMALL:
                reason = "RPC_NT_BYTE_COUNT_TOO_SMALL";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_BAD_STUB_DATA:
                reason = "RPC_NT_BAD_STUB_DATA";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_ES_ACTION:
                reason = "RPC_NT_INVALID_ES_ACTION";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_WRONG_ES_VERSION:
                reason = "RPC_NT_WRONG_ES_VERSION";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_WRONG_STUB_VERSION:
                reason = "RPC_NT_WRONG_STUB_VERSION";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_PIPE_OBJECT:
                reason = "RPC_NT_INVALID_PIPE_OBJECT";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_INVALID_PIPE_OPERATION:
                reason = "RPC_NT_INVALID_PIPE_OPERATION";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_WRONG_PIPE_VERSION:
                reason = "RPC_NT_WRONG_PIPE_VERSION";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_PIPE_CLOSED:
                reason = "RPC_NT_PIPE_CLOSED";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_PIPE_DISCIPLINE_ERROR:
                reason = "RPC_NT_PIPE_DISCIPLINE_ERROR";
                break;
            case MD_NTSTATUS_WIN_RPC_NT_PIPE_EMPTY:
                reason = "RPC_NT_PIPE_EMPTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_PNP_BAD_MPS_TABLE:
                reason = "STATUS_PNP_BAD_MPS_TABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PNP_TRANSLATION_FAILED:
                reason = "STATUS_PNP_TRANSLATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PNP_IRQ_TRANSLATION_FAILED:
                reason = "STATUS_PNP_IRQ_TRANSLATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PNP_INVALID_ID:
                reason = "STATUS_PNP_INVALID_ID";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_REISSUE_AS_CACHED:
                reason = "STATUS_IO_REISSUE_AS_CACHED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_WINSTATION_NAME_INVALID:
                reason = "STATUS_CTX_WINSTATION_NAME_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_INVALID_PD:
                reason = "STATUS_CTX_INVALID_PD";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_PD_NOT_FOUND:
                reason = "STATUS_CTX_PD_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_CLOSE_PENDING:
                reason = "STATUS_CTX_CLOSE_PENDING";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_NO_OUTBUF:
                reason = "STATUS_CTX_NO_OUTBUF";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_MODEM_INF_NOT_FOUND:
                reason = "STATUS_CTX_MODEM_INF_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_INVALID_MODEMNAME:
                reason = "STATUS_CTX_INVALID_MODEMNAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_RESPONSE_ERROR:
                reason = "STATUS_CTX_RESPONSE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_MODEM_RESPONSE_TIMEOUT:
                reason = "STATUS_CTX_MODEM_RESPONSE_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_MODEM_RESPONSE_NO_CARRIER:
                reason = "STATUS_CTX_MODEM_RESPONSE_NO_CARRIER";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_MODEM_RESPONSE_NO_DIALTONE:
                reason = "STATUS_CTX_MODEM_RESPONSE_NO_DIALTONE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_MODEM_RESPONSE_BUSY:
                reason = "STATUS_CTX_MODEM_RESPONSE_BUSY";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_MODEM_RESPONSE_VOICE:
                reason = "STATUS_CTX_MODEM_RESPONSE_VOICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_TD_ERROR:
                reason = "STATUS_CTX_TD_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_LICENSE_CLIENT_INVALID:
                reason = "STATUS_CTX_LICENSE_CLIENT_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_LICENSE_NOT_AVAILABLE:
                reason = "STATUS_CTX_LICENSE_NOT_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_LICENSE_EXPIRED:
                reason = "STATUS_CTX_LICENSE_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_WINSTATION_NOT_FOUND:
                reason = "STATUS_CTX_WINSTATION_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_WINSTATION_NAME_COLLISION:
                reason = "STATUS_CTX_WINSTATION_NAME_COLLISION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_WINSTATION_BUSY:
                reason = "STATUS_CTX_WINSTATION_BUSY";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_BAD_VIDEO_MODE:
                reason = "STATUS_CTX_BAD_VIDEO_MODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_GRAPHICS_INVALID:
                reason = "STATUS_CTX_GRAPHICS_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_NOT_CONSOLE:
                reason = "STATUS_CTX_NOT_CONSOLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_CLIENT_QUERY_TIMEOUT:
                reason = "STATUS_CTX_CLIENT_QUERY_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_CONSOLE_DISCONNECT:
                reason = "STATUS_CTX_CONSOLE_DISCONNECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_CONSOLE_CONNECT:
                reason = "STATUS_CTX_CONSOLE_CONNECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_SHADOW_DENIED:
                reason = "STATUS_CTX_SHADOW_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_WINSTATION_ACCESS_DENIED:
                reason = "STATUS_CTX_WINSTATION_ACCESS_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_INVALID_WD:
                reason = "STATUS_CTX_INVALID_WD";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_WD_NOT_FOUND:
                reason = "STATUS_CTX_WD_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_SHADOW_INVALID:
                reason = "STATUS_CTX_SHADOW_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_SHADOW_DISABLED:
                reason = "STATUS_CTX_SHADOW_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_RDP_PROTOCOL_ERROR:
                reason = "STATUS_RDP_PROTOCOL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_CLIENT_LICENSE_NOT_SET:
                reason = "STATUS_CTX_CLIENT_LICENSE_NOT_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_CLIENT_LICENSE_IN_USE:
                reason = "STATUS_CTX_CLIENT_LICENSE_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_SHADOW_ENDED_BY_MODE_CHANGE:
                reason = "STATUS_CTX_SHADOW_ENDED_BY_MODE_CHANGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_SHADOW_NOT_RUNNING:
                reason = "STATUS_CTX_SHADOW_NOT_RUNNING";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_LOGON_DISABLED:
                reason = "STATUS_CTX_LOGON_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTX_SECURITY_LAYER_ERROR:
                reason = "STATUS_CTX_SECURITY_LAYER_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_TS_INCOMPATIBLE_SESSIONS:
                reason = "STATUS_TS_INCOMPATIBLE_SESSIONS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TS_VIDEO_SUBSYSTEM_ERROR:
                reason = "STATUS_TS_VIDEO_SUBSYSTEM_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUI_FILE_NOT_FOUND:
                reason = "STATUS_MUI_FILE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUI_INVALID_FILE:
                reason = "STATUS_MUI_INVALID_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUI_INVALID_RC_CONFIG:
                reason = "STATUS_MUI_INVALID_RC_CONFIG";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUI_INVALID_LOCALE_NAME:
                reason = "STATUS_MUI_INVALID_LOCALE_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUI_INVALID_ULTIMATEFALLBACK_NAME:
                reason = "STATUS_MUI_INVALID_ULTIMATEFALLBACK_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_MUI_FILE_NOT_LOADED:
                reason = "STATUS_MUI_FILE_NOT_LOADED";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESOURCE_ENUM_USER_STOP:
                reason = "STATUS_RESOURCE_ENUM_USER_STOP";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_INVALID_NODE:
                reason = "STATUS_CLUSTER_INVALID_NODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NODE_EXISTS:
                reason = "STATUS_CLUSTER_NODE_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_JOIN_IN_PROGRESS:
                reason = "STATUS_CLUSTER_JOIN_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NODE_NOT_FOUND:
                reason = "STATUS_CLUSTER_NODE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_LOCAL_NODE_NOT_FOUND:
                reason = "STATUS_CLUSTER_LOCAL_NODE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NETWORK_EXISTS:
                reason = "STATUS_CLUSTER_NETWORK_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NETWORK_NOT_FOUND:
                reason = "STATUS_CLUSTER_NETWORK_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NETINTERFACE_EXISTS:
                reason = "STATUS_CLUSTER_NETINTERFACE_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NETINTERFACE_NOT_FOUND:
                reason = "STATUS_CLUSTER_NETINTERFACE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_INVALID_REQUEST:
                reason = "STATUS_CLUSTER_INVALID_REQUEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_INVALID_NETWORK_PROVIDER:
                reason = "STATUS_CLUSTER_INVALID_NETWORK_PROVIDER";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NODE_DOWN:
                reason = "STATUS_CLUSTER_NODE_DOWN";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NODE_UNREACHABLE:
                reason = "STATUS_CLUSTER_NODE_UNREACHABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NODE_NOT_MEMBER:
                reason = "STATUS_CLUSTER_NODE_NOT_MEMBER";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_JOIN_NOT_IN_PROGRESS:
                reason = "STATUS_CLUSTER_JOIN_NOT_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_INVALID_NETWORK:
                reason = "STATUS_CLUSTER_INVALID_NETWORK";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NO_NET_ADAPTERS:
                reason = "STATUS_CLUSTER_NO_NET_ADAPTERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NODE_UP:
                reason = "STATUS_CLUSTER_NODE_UP";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NODE_PAUSED:
                reason = "STATUS_CLUSTER_NODE_PAUSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NODE_NOT_PAUSED:
                reason = "STATUS_CLUSTER_NODE_NOT_PAUSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NO_SECURITY_CONTEXT:
                reason = "STATUS_CLUSTER_NO_SECURITY_CONTEXT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NETWORK_NOT_INTERNAL:
                reason = "STATUS_CLUSTER_NETWORK_NOT_INTERNAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_POISONED:
                reason = "STATUS_CLUSTER_POISONED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_NON_CSV_PATH:
                reason = "STATUS_CLUSTER_NON_CSV_PATH";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_CSV_VOLUME_NOT_LOCAL:
                reason = "STATUS_CLUSTER_CSV_VOLUME_NOT_LOCAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_CSV_READ_OPLOCK_BREAK_IN_PROGRESS:
                reason = "STATUS_CLUSTER_CSV_READ_OPLOCK_BREAK_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_CSV_AUTO_PAUSE_ERROR:
                reason = "STATUS_CLUSTER_CSV_AUTO_PAUSE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_CSV_REDIRECTED:
                reason = "STATUS_CLUSTER_CSV_REDIRECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_CSV_NOT_REDIRECTED:
                reason = "STATUS_CLUSTER_CSV_NOT_REDIRECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_CSV_VOLUME_DRAINING:
                reason = "STATUS_CLUSTER_CSV_VOLUME_DRAINING";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_CSV_SNAPSHOT_CREATION_IN_PROGRESS:
                reason = "STATUS_CLUSTER_CSV_SNAPSHOT_CREATION_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_CLUSTER_CSV_VOLUME_DRAINING_SUCCEEDED_DOWNLEVEL:
                reason = "STATUS_CLUSTER_CSV_VOLUME_DRAINING_SUCCEEDED_DOWNLEVEL";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_OPCODE:
                reason = "STATUS_ACPI_INVALID_OPCODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_STACK_OVERFLOW:
                reason = "STATUS_ACPI_STACK_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_ASSERT_FAILED:
                reason = "STATUS_ACPI_ASSERT_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_INDEX:
                reason = "STATUS_ACPI_INVALID_INDEX";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_ARGUMENT:
                reason = "STATUS_ACPI_INVALID_ARGUMENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_FATAL:
                reason = "STATUS_ACPI_FATAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_SUPERNAME:
                reason = "STATUS_ACPI_INVALID_SUPERNAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_ARGTYPE:
                reason = "STATUS_ACPI_INVALID_ARGTYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_OBJTYPE:
                reason = "STATUS_ACPI_INVALID_OBJTYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_TARGETTYPE:
                reason = "STATUS_ACPI_INVALID_TARGETTYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INCORRECT_ARGUMENT_COUNT:
                reason = "STATUS_ACPI_INCORRECT_ARGUMENT_COUNT";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_ADDRESS_NOT_MAPPED:
                reason = "STATUS_ACPI_ADDRESS_NOT_MAPPED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_EVENTTYPE:
                reason = "STATUS_ACPI_INVALID_EVENTTYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_HANDLER_COLLISION:
                reason = "STATUS_ACPI_HANDLER_COLLISION";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_DATA:
                reason = "STATUS_ACPI_INVALID_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_REGION:
                reason = "STATUS_ACPI_INVALID_REGION";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_ACCESS_SIZE:
                reason = "STATUS_ACPI_INVALID_ACCESS_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_ACQUIRE_GLOBAL_LOCK:
                reason = "STATUS_ACPI_ACQUIRE_GLOBAL_LOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_ALREADY_INITIALIZED:
                reason = "STATUS_ACPI_ALREADY_INITIALIZED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_NOT_INITIALIZED:
                reason = "STATUS_ACPI_NOT_INITIALIZED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_MUTEX_LEVEL:
                reason = "STATUS_ACPI_INVALID_MUTEX_LEVEL";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_MUTEX_NOT_OWNED:
                reason = "STATUS_ACPI_MUTEX_NOT_OWNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_MUTEX_NOT_OWNER:
                reason = "STATUS_ACPI_MUTEX_NOT_OWNER";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_RS_ACCESS:
                reason = "STATUS_ACPI_RS_ACCESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_INVALID_TABLE:
                reason = "STATUS_ACPI_INVALID_TABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_REG_HANDLER_FAILED:
                reason = "STATUS_ACPI_REG_HANDLER_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ACPI_POWER_REQUEST_FAILED:
                reason = "STATUS_ACPI_POWER_REQUEST_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_SECTION_NOT_FOUND:
                reason = "STATUS_SXS_SECTION_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_CANT_GEN_ACTCTX:
                reason = "STATUS_SXS_CANT_GEN_ACTCTX";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_INVALID_ACTCTXDATA_FORMAT:
                reason = "STATUS_SXS_INVALID_ACTCTXDATA_FORMAT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_ASSEMBLY_NOT_FOUND:
                reason = "STATUS_SXS_ASSEMBLY_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_MANIFEST_FORMAT_ERROR:
                reason = "STATUS_SXS_MANIFEST_FORMAT_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_MANIFEST_PARSE_ERROR:
                reason = "STATUS_SXS_MANIFEST_PARSE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_ACTIVATION_CONTEXT_DISABLED:
                reason = "STATUS_SXS_ACTIVATION_CONTEXT_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_KEY_NOT_FOUND:
                reason = "STATUS_SXS_KEY_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_VERSION_CONFLICT:
                reason = "STATUS_SXS_VERSION_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_WRONG_SECTION_TYPE:
                reason = "STATUS_SXS_WRONG_SECTION_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_THREAD_QUERIES_DISABLED:
                reason = "STATUS_SXS_THREAD_QUERIES_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_ASSEMBLY_MISSING:
                reason = "STATUS_SXS_ASSEMBLY_MISSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_PROCESS_DEFAULT_ALREADY_SET:
                reason = "STATUS_SXS_PROCESS_DEFAULT_ALREADY_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_EARLY_DEACTIVATION:
                reason = "STATUS_SXS_EARLY_DEACTIVATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_INVALID_DEACTIVATION:
                reason = "STATUS_SXS_INVALID_DEACTIVATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_MULTIPLE_DEACTIVATION:
                reason = "STATUS_SXS_MULTIPLE_DEACTIVATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY:
                reason = "STATUS_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_PROCESS_TERMINATION_REQUESTED:
                reason = "STATUS_SXS_PROCESS_TERMINATION_REQUESTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_CORRUPT_ACTIVATION_STACK:
                reason = "STATUS_SXS_CORRUPT_ACTIVATION_STACK";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_CORRUPTION:
                reason = "STATUS_SXS_CORRUPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE:
                reason = "STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME:
                reason = "STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_IDENTITY_DUPLICATE_ATTRIBUTE:
                reason = "STATUS_SXS_IDENTITY_DUPLICATE_ATTRIBUTE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_IDENTITY_PARSE_ERROR:
                reason = "STATUS_SXS_IDENTITY_PARSE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_COMPONENT_STORE_CORRUPT:
                reason = "STATUS_SXS_COMPONENT_STORE_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_FILE_HASH_MISMATCH:
                reason = "STATUS_SXS_FILE_HASH_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT:
                reason = "STATUS_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_IDENTITIES_DIFFERENT:
                reason = "STATUS_SXS_IDENTITIES_DIFFERENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT:
                reason = "STATUS_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_FILE_NOT_PART_OF_ASSEMBLY:
                reason = "STATUS_SXS_FILE_NOT_PART_OF_ASSEMBLY";
                break;
            case MD_NTSTATUS_WIN_STATUS_ADVANCED_INSTALLER_FAILED:
                reason = "STATUS_ADVANCED_INSTALLER_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_XML_ENCODING_MISMATCH:
                reason = "STATUS_XML_ENCODING_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_MANIFEST_TOO_BIG:
                reason = "STATUS_SXS_MANIFEST_TOO_BIG";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_SETTING_NOT_REGISTERED:
                reason = "STATUS_SXS_SETTING_NOT_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_TRANSACTION_CLOSURE_INCOMPLETE:
                reason = "STATUS_SXS_TRANSACTION_CLOSURE_INCOMPLETE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SMI_PRIMITIVE_INSTALLER_FAILED:
                reason = "STATUS_SMI_PRIMITIVE_INSTALLER_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GENERIC_COMMAND_FAILED:
                reason = "STATUS_GENERIC_COMMAND_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SXS_FILE_HASH_MISSING:
                reason = "STATUS_SXS_FILE_HASH_MISSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTIONAL_CONFLICT:
                reason = "STATUS_TRANSACTIONAL_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_INVALID_TRANSACTION:
                reason = "STATUS_INVALID_TRANSACTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_NOT_ACTIVE:
                reason = "STATUS_TRANSACTION_NOT_ACTIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TM_INITIALIZATION_FAILED:
                reason = "STATUS_TM_INITIALIZATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_RM_NOT_ACTIVE:
                reason = "STATUS_RM_NOT_ACTIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_RM_METADATA_CORRUPT:
                reason = "STATUS_RM_METADATA_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_NOT_JOINED:
                reason = "STATUS_TRANSACTION_NOT_JOINED";
                break;
            case MD_NTSTATUS_WIN_STATUS_DIRECTORY_NOT_RM:
                reason = "STATUS_DIRECTORY_NOT_RM";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTIONS_UNSUPPORTED_REMOTE:
                reason = "STATUS_TRANSACTIONS_UNSUPPORTED_REMOTE";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_RESIZE_INVALID_SIZE:
                reason = "STATUS_LOG_RESIZE_INVALID_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_REMOTE_FILE_VERSION_MISMATCH:
                reason = "STATUS_REMOTE_FILE_VERSION_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_CRM_PROTOCOL_ALREADY_EXISTS:
                reason = "STATUS_CRM_PROTOCOL_ALREADY_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_PROPAGATION_FAILED:
                reason = "STATUS_TRANSACTION_PROPAGATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CRM_PROTOCOL_NOT_FOUND:
                reason = "STATUS_CRM_PROTOCOL_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_SUPERIOR_EXISTS:
                reason = "STATUS_TRANSACTION_SUPERIOR_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_REQUEST_NOT_VALID:
                reason = "STATUS_TRANSACTION_REQUEST_NOT_VALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_NOT_REQUESTED:
                reason = "STATUS_TRANSACTION_NOT_REQUESTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_ALREADY_ABORTED:
                reason = "STATUS_TRANSACTION_ALREADY_ABORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_ALREADY_COMMITTED:
                reason = "STATUS_TRANSACTION_ALREADY_COMMITTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_INVALID_MARSHALL_BUFFER:
                reason = "STATUS_TRANSACTION_INVALID_MARSHALL_BUFFER";
                break;
            case MD_NTSTATUS_WIN_STATUS_CURRENT_TRANSACTION_NOT_VALID:
                reason = "STATUS_CURRENT_TRANSACTION_NOT_VALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_GROWTH_FAILED:
                reason = "STATUS_LOG_GROWTH_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_OBJECT_NO_LONGER_EXISTS:
                reason = "STATUS_OBJECT_NO_LONGER_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_STREAM_MINIVERSION_NOT_FOUND:
                reason = "STATUS_STREAM_MINIVERSION_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_STREAM_MINIVERSION_NOT_VALID:
                reason = "STATUS_STREAM_MINIVERSION_NOT_VALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION:
                reason = "STATUS_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT:
                reason = "STATUS_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_CREATE_MORE_STREAM_MINIVERSIONS:
                reason = "STATUS_CANT_CREATE_MORE_STREAM_MINIVERSIONS";
                break;
            case MD_NTSTATUS_WIN_STATUS_HANDLE_NO_LONGER_VALID:
                reason = "STATUS_HANDLE_NO_LONGER_VALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_CORRUPTION_DETECTED:
                reason = "STATUS_LOG_CORRUPTION_DETECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_RM_DISCONNECTED:
                reason = "STATUS_RM_DISCONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_ENLISTMENT_NOT_SUPERIOR:
                reason = "STATUS_ENLISTMENT_NOT_SUPERIOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FILE_IDENTITY_NOT_PERSISTENT:
                reason = "STATUS_FILE_IDENTITY_NOT_PERSISTENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_BREAK_TRANSACTIONAL_DEPENDENCY:
                reason = "STATUS_CANT_BREAK_TRANSACTIONAL_DEPENDENCY";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANT_CROSS_RM_BOUNDARY:
                reason = "STATUS_CANT_CROSS_RM_BOUNDARY";
                break;
            case MD_NTSTATUS_WIN_STATUS_TXF_DIR_NOT_EMPTY:
                reason = "STATUS_TXF_DIR_NOT_EMPTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_INDOUBT_TRANSACTIONS_EXIST:
                reason = "STATUS_INDOUBT_TRANSACTIONS_EXIST";
                break;
            case MD_NTSTATUS_WIN_STATUS_TM_VOLATILE:
                reason = "STATUS_TM_VOLATILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_ROLLBACK_TIMER_EXPIRED:
                reason = "STATUS_ROLLBACK_TIMER_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TXF_ATTRIBUTE_CORRUPT:
                reason = "STATUS_TXF_ATTRIBUTE_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_EFS_NOT_ALLOWED_IN_TRANSACTION:
                reason = "STATUS_EFS_NOT_ALLOWED_IN_TRANSACTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTIONAL_OPEN_NOT_ALLOWED:
                reason = "STATUS_TRANSACTIONAL_OPEN_NOT_ALLOWED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE:
                reason = "STATUS_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_REQUIRED_PROMOTION:
                reason = "STATUS_TRANSACTION_REQUIRED_PROMOTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANNOT_EXECUTE_FILE_IN_TRANSACTION:
                reason = "STATUS_CANNOT_EXECUTE_FILE_IN_TRANSACTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTIONS_NOT_FROZEN:
                reason = "STATUS_TRANSACTIONS_NOT_FROZEN";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_FREEZE_IN_PROGRESS:
                reason = "STATUS_TRANSACTION_FREEZE_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NOT_SNAPSHOT_VOLUME:
                reason = "STATUS_NOT_SNAPSHOT_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_SAVEPOINT_WITH_OPEN_FILES:
                reason = "STATUS_NO_SAVEPOINT_WITH_OPEN_FILES";
                break;
            case MD_NTSTATUS_WIN_STATUS_SPARSE_NOT_ALLOWED_IN_TRANSACTION:
                reason = "STATUS_SPARSE_NOT_ALLOWED_IN_TRANSACTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TM_IDENTITY_MISMATCH:
                reason = "STATUS_TM_IDENTITY_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLOATED_SECTION:
                reason = "STATUS_FLOATED_SECTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANNOT_ACCEPT_TRANSACTED_WORK:
                reason = "STATUS_CANNOT_ACCEPT_TRANSACTED_WORK";
                break;
            case MD_NTSTATUS_WIN_STATUS_CANNOT_ABORT_TRANSACTIONS:
                reason = "STATUS_CANNOT_ABORT_TRANSACTIONS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_NOT_FOUND:
                reason = "STATUS_TRANSACTION_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_RESOURCEMANAGER_NOT_FOUND:
                reason = "STATUS_RESOURCEMANAGER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_ENLISTMENT_NOT_FOUND:
                reason = "STATUS_ENLISTMENT_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTIONMANAGER_NOT_FOUND:
                reason = "STATUS_TRANSACTIONMANAGER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTIONMANAGER_NOT_ONLINE:
                reason = "STATUS_TRANSACTIONMANAGER_NOT_ONLINE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION:
                reason = "STATUS_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_NOT_ROOT:
                reason = "STATUS_TRANSACTION_NOT_ROOT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_OBJECT_EXPIRED:
                reason = "STATUS_TRANSACTION_OBJECT_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION:
                reason = "STATUS_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_RESPONSE_NOT_ENLISTED:
                reason = "STATUS_TRANSACTION_RESPONSE_NOT_ENLISTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_RECORD_TOO_LONG:
                reason = "STATUS_TRANSACTION_RECORD_TOO_LONG";
                break;
            case MD_NTSTATUS_WIN_STATUS_NO_LINK_TRACKING_IN_TRANSACTION:
                reason = "STATUS_NO_LINK_TRACKING_IN_TRANSACTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_OPERATION_NOT_SUPPORTED_IN_TRANSACTION:
                reason = "STATUS_OPERATION_NOT_SUPPORTED_IN_TRANSACTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_INTEGRITY_VIOLATED:
                reason = "STATUS_TRANSACTION_INTEGRITY_VIOLATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTIONMANAGER_IDENTITY_MISMATCH:
                reason = "STATUS_TRANSACTIONMANAGER_IDENTITY_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT:
                reason = "STATUS_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_MUST_WRITETHROUGH:
                reason = "STATUS_TRANSACTION_MUST_WRITETHROUGH";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_NO_SUPERIOR:
                reason = "STATUS_TRANSACTION_NO_SUPERIOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_EXPIRED_HANDLE:
                reason = "STATUS_EXPIRED_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TRANSACTION_NOT_ENLISTED:
                reason = "STATUS_TRANSACTION_NOT_ENLISTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_SECTOR_INVALID:
                reason = "STATUS_LOG_SECTOR_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_SECTOR_PARITY_INVALID:
                reason = "STATUS_LOG_SECTOR_PARITY_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_SECTOR_REMAPPED:
                reason = "STATUS_LOG_SECTOR_REMAPPED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_BLOCK_INCOMPLETE:
                reason = "STATUS_LOG_BLOCK_INCOMPLETE";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_INVALID_RANGE:
                reason = "STATUS_LOG_INVALID_RANGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_BLOCKS_EXHAUSTED:
                reason = "STATUS_LOG_BLOCKS_EXHAUSTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_READ_CONTEXT_INVALID:
                reason = "STATUS_LOG_READ_CONTEXT_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_RESTART_INVALID:
                reason = "STATUS_LOG_RESTART_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_BLOCK_VERSION:
                reason = "STATUS_LOG_BLOCK_VERSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_BLOCK_INVALID:
                reason = "STATUS_LOG_BLOCK_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_READ_MODE_INVALID:
                reason = "STATUS_LOG_READ_MODE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_METADATA_CORRUPT:
                reason = "STATUS_LOG_METADATA_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_METADATA_INVALID:
                reason = "STATUS_LOG_METADATA_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_METADATA_INCONSISTENT:
                reason = "STATUS_LOG_METADATA_INCONSISTENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_RESERVATION_INVALID:
                reason = "STATUS_LOG_RESERVATION_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_CANT_DELETE:
                reason = "STATUS_LOG_CANT_DELETE";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_CONTAINER_LIMIT_EXCEEDED:
                reason = "STATUS_LOG_CONTAINER_LIMIT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_START_OF_LOG:
                reason = "STATUS_LOG_START_OF_LOG";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_POLICY_ALREADY_INSTALLED:
                reason = "STATUS_LOG_POLICY_ALREADY_INSTALLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_POLICY_NOT_INSTALLED:
                reason = "STATUS_LOG_POLICY_NOT_INSTALLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_POLICY_INVALID:
                reason = "STATUS_LOG_POLICY_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_POLICY_CONFLICT:
                reason = "STATUS_LOG_POLICY_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_PINNED_ARCHIVE_TAIL:
                reason = "STATUS_LOG_PINNED_ARCHIVE_TAIL";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_RECORD_NONEXISTENT:
                reason = "STATUS_LOG_RECORD_NONEXISTENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_RECORDS_RESERVED_INVALID:
                reason = "STATUS_LOG_RECORDS_RESERVED_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_SPACE_RESERVED_INVALID:
                reason = "STATUS_LOG_SPACE_RESERVED_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_TAIL_INVALID:
                reason = "STATUS_LOG_TAIL_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_FULL:
                reason = "STATUS_LOG_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_MULTIPLEXED:
                reason = "STATUS_LOG_MULTIPLEXED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_DEDICATED:
                reason = "STATUS_LOG_DEDICATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_ARCHIVE_NOT_IN_PROGRESS:
                reason = "STATUS_LOG_ARCHIVE_NOT_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_ARCHIVE_IN_PROGRESS:
                reason = "STATUS_LOG_ARCHIVE_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_EPHEMERAL:
                reason = "STATUS_LOG_EPHEMERAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_NOT_ENOUGH_CONTAINERS:
                reason = "STATUS_LOG_NOT_ENOUGH_CONTAINERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_CLIENT_ALREADY_REGISTERED:
                reason = "STATUS_LOG_CLIENT_ALREADY_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_CLIENT_NOT_REGISTERED:
                reason = "STATUS_LOG_CLIENT_NOT_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_FULL_HANDLER_IN_PROGRESS:
                reason = "STATUS_LOG_FULL_HANDLER_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_CONTAINER_READ_FAILED:
                reason = "STATUS_LOG_CONTAINER_READ_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_CONTAINER_WRITE_FAILED:
                reason = "STATUS_LOG_CONTAINER_WRITE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_CONTAINER_OPEN_FAILED:
                reason = "STATUS_LOG_CONTAINER_OPEN_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_CONTAINER_STATE_INVALID:
                reason = "STATUS_LOG_CONTAINER_STATE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_STATE_INVALID:
                reason = "STATUS_LOG_STATE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_PINNED:
                reason = "STATUS_LOG_PINNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_METADATA_FLUSH_FAILED:
                reason = "STATUS_LOG_METADATA_FLUSH_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_INCONSISTENT_SECURITY:
                reason = "STATUS_LOG_INCONSISTENT_SECURITY";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_APPENDED_FLUSH_FAILED:
                reason = "STATUS_LOG_APPENDED_FLUSH_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_LOG_PINNED_RESERVATION:
                reason = "STATUS_LOG_PINNED_RESERVATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD:
                reason = "STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_NO_HANDLER_DEFINED:
                reason = "STATUS_FLT_NO_HANDLER_DEFINED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_CONTEXT_ALREADY_DEFINED:
                reason = "STATUS_FLT_CONTEXT_ALREADY_DEFINED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_INVALID_ASYNCHRONOUS_REQUEST:
                reason = "STATUS_FLT_INVALID_ASYNCHRONOUS_REQUEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_DISALLOW_FAST_IO:
                reason = "STATUS_FLT_DISALLOW_FAST_IO";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_INVALID_NAME_REQUEST:
                reason = "STATUS_FLT_INVALID_NAME_REQUEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_NOT_SAFE_TO_POST_OPERATION:
                reason = "STATUS_FLT_NOT_SAFE_TO_POST_OPERATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_NOT_INITIALIZED:
                reason = "STATUS_FLT_NOT_INITIALIZED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_FILTER_NOT_READY:
                reason = "STATUS_FLT_FILTER_NOT_READY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_POST_OPERATION_CLEANUP:
                reason = "STATUS_FLT_POST_OPERATION_CLEANUP";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_INTERNAL_ERROR:
                reason = "STATUS_FLT_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_DELETING_OBJECT:
                reason = "STATUS_FLT_DELETING_OBJECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_MUST_BE_NONPAGED_POOL:
                reason = "STATUS_FLT_MUST_BE_NONPAGED_POOL";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_DUPLICATE_ENTRY:
                reason = "STATUS_FLT_DUPLICATE_ENTRY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_CBDQ_DISABLED:
                reason = "STATUS_FLT_CBDQ_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_DO_NOT_ATTACH:
                reason = "STATUS_FLT_DO_NOT_ATTACH";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_DO_NOT_DETACH:
                reason = "STATUS_FLT_DO_NOT_DETACH";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_INSTANCE_ALTITUDE_COLLISION:
                reason = "STATUS_FLT_INSTANCE_ALTITUDE_COLLISION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_INSTANCE_NAME_COLLISION:
                reason = "STATUS_FLT_INSTANCE_NAME_COLLISION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_FILTER_NOT_FOUND:
                reason = "STATUS_FLT_FILTER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_VOLUME_NOT_FOUND:
                reason = "STATUS_FLT_VOLUME_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_INSTANCE_NOT_FOUND:
                reason = "STATUS_FLT_INSTANCE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_CONTEXT_ALLOCATION_NOT_FOUND:
                reason = "STATUS_FLT_CONTEXT_ALLOCATION_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_INVALID_CONTEXT_REGISTRATION:
                reason = "STATUS_FLT_INVALID_CONTEXT_REGISTRATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_NAME_CACHE_MISS:
                reason = "STATUS_FLT_NAME_CACHE_MISS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_NO_DEVICE_OBJECT:
                reason = "STATUS_FLT_NO_DEVICE_OBJECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_VOLUME_ALREADY_MOUNTED:
                reason = "STATUS_FLT_VOLUME_ALREADY_MOUNTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_ALREADY_ENLISTED:
                reason = "STATUS_FLT_ALREADY_ENLISTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_CONTEXT_ALREADY_LINKED:
                reason = "STATUS_FLT_CONTEXT_ALREADY_LINKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_NO_WAITER_FOR_REPLY:
                reason = "STATUS_FLT_NO_WAITER_FOR_REPLY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FLT_REGISTRATION_BUSY:
                reason = "STATUS_FLT_REGISTRATION_BUSY";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_NO_DESCRIPTOR:
                reason = "STATUS_MONITOR_NO_DESCRIPTOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT:
                reason = "STATUS_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_INVALID_DESCRIPTOR_CHECKSUM:
                reason = "STATUS_MONITOR_INVALID_DESCRIPTOR_CHECKSUM";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_INVALID_STANDARD_TIMING_BLOCK:
                reason = "STATUS_MONITOR_INVALID_STANDARD_TIMING_BLOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED:
                reason = "STATUS_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK:
                reason = "STATUS_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK:
                reason = "STATUS_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA:
                reason = "STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_INVALID_DETAILED_TIMING_BLOCK:
                reason = "STATUS_MONITOR_INVALID_DETAILED_TIMING_BLOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_MONITOR_INVALID_MANUFACTURE_DATE:
                reason = "STATUS_MONITOR_INVALID_MANUFACTURE_DATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER:
                reason = "STATUS_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER:
                reason = "STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER:
                reason = "STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ADAPTER_WAS_RESET:
                reason = "STATUS_GRAPHICS_ADAPTER_WAS_RESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_DRIVER_MODEL:
                reason = "STATUS_GRAPHICS_INVALID_DRIVER_MODEL";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PRESENT_MODE_CHANGED:
                reason = "STATUS_GRAPHICS_PRESENT_MODE_CHANGED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PRESENT_OCCLUDED:
                reason = "STATUS_GRAPHICS_PRESENT_OCCLUDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PRESENT_DENIED:
                reason = "STATUS_GRAPHICS_PRESENT_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CANNOTCOLORCONVERT:
                reason = "STATUS_GRAPHICS_CANNOTCOLORCONVERT";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_DRIVER_MISMATCH:
                reason = "STATUS_GRAPHICS_DRIVER_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PRESENT_REDIRECTION_DISABLED:
                reason = "STATUS_GRAPHICS_PRESENT_REDIRECTION_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PRESENT_UNOCCLUDED:
                reason = "STATUS_GRAPHICS_PRESENT_UNOCCLUDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_WINDOWDC_NOT_AVAILABLE:
                reason = "STATUS_GRAPHICS_WINDOWDC_NOT_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_WINDOWLESS_PRESENT_DISABLED:
                reason = "STATUS_GRAPHICS_WINDOWLESS_PRESENT_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_VIDEO_MEMORY:
                reason = "STATUS_GRAPHICS_NO_VIDEO_MEMORY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CANT_LOCK_MEMORY:
                reason = "STATUS_GRAPHICS_CANT_LOCK_MEMORY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ALLOCATION_BUSY:
                reason = "STATUS_GRAPHICS_ALLOCATION_BUSY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_TOO_MANY_REFERENCES:
                reason = "STATUS_GRAPHICS_TOO_MANY_REFERENCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_TRY_AGAIN_LATER:
                reason = "STATUS_GRAPHICS_TRY_AGAIN_LATER";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_TRY_AGAIN_NOW:
                reason = "STATUS_GRAPHICS_TRY_AGAIN_NOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ALLOCATION_INVALID:
                reason = "STATUS_GRAPHICS_ALLOCATION_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE:
                reason = "STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED:
                reason = "STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION:
                reason = "STATUS_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_ALLOCATION_USAGE:
                reason = "STATUS_GRAPHICS_INVALID_ALLOCATION_USAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION:
                reason = "STATUS_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ALLOCATION_CLOSED:
                reason = "STATUS_GRAPHICS_ALLOCATION_CLOSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_ALLOCATION_INSTANCE:
                reason = "STATUS_GRAPHICS_INVALID_ALLOCATION_INSTANCE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_ALLOCATION_HANDLE:
                reason = "STATUS_GRAPHICS_INVALID_ALLOCATION_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_WRONG_ALLOCATION_DEVICE:
                reason = "STATUS_GRAPHICS_WRONG_ALLOCATION_DEVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ALLOCATION_CONTENT_LOST:
                reason = "STATUS_GRAPHICS_ALLOCATION_CONTENT_LOST";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE:
                reason = "STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY:
                reason = "STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDPN:
                reason = "STATUS_GRAPHICS_INVALID_VIDPN";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE:
                reason = "STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET:
                reason = "STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET:
                reason = "STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET:
                reason = "STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_FREQUENCY:
                reason = "STATUS_GRAPHICS_INVALID_FREQUENCY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_ACTIVE_REGION:
                reason = "STATUS_GRAPHICS_INVALID_ACTIVE_REGION";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_TOTAL_REGION:
                reason = "STATUS_GRAPHICS_INVALID_TOTAL_REGION";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE:
                reason = "STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE:
                reason = "STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET:
                reason = "STATUS_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY:
                reason = "STATUS_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET:
                reason = "STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET:
                reason = "STATUS_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET:
                reason = "STATUS_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_SOURCE_ALREADY_IN_SET:
                reason = "STATUS_GRAPHICS_SOURCE_ALREADY_IN_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_TARGET_ALREADY_IN_SET:
                reason = "STATUS_GRAPHICS_TARGET_ALREADY_IN_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDPN_PRESENT_PATH:
                reason = "STATUS_GRAPHICS_INVALID_VIDPN_PRESENT_PATH";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY:
                reason = "STATUS_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET:
                reason = "STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE:
                reason = "STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET:
                reason = "STATUS_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET:
                reason = "STATUS_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_STALE_MODESET:
                reason = "STATUS_GRAPHICS_STALE_MODESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET:
                reason = "STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_MONITOR_SOURCE_MODE:
                reason = "STATUS_GRAPHICS_INVALID_MONITOR_SOURCE_MODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN:
                reason = "STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MODE_ID_MUST_BE_UNIQUE:
                reason = "STATUS_GRAPHICS_MODE_ID_MUST_BE_UNIQUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION:
                reason = "STATUS_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES:
                reason = "STATUS_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY:
                reason = "STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE:
                reason = "STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET:
                reason = "STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_MONITORDESCRIPTORSET:
                reason = "STATUS_GRAPHICS_INVALID_MONITORDESCRIPTORSET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_MONITORDESCRIPTOR:
                reason = "STATUS_GRAPHICS_INVALID_MONITORDESCRIPTOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET:
                reason = "STATUS_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET:
                reason = "STATUS_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE:
                reason = "STATUS_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE:
                reason = "STATUS_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_RESOURCES_NOT_RELATED:
                reason = "STATUS_GRAPHICS_RESOURCES_NOT_RELATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE:
                reason = "STATUS_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE:
                reason = "STATUS_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET:
                reason = "STATUS_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER:
                reason = "STATUS_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_VIDPNMGR:
                reason = "STATUS_GRAPHICS_NO_VIDPNMGR";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_ACTIVE_VIDPN:
                reason = "STATUS_GRAPHICS_NO_ACTIVE_VIDPN";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_STALE_VIDPN_TOPOLOGY:
                reason = "STATUS_GRAPHICS_STALE_VIDPN_TOPOLOGY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MONITOR_NOT_CONNECTED:
                reason = "STATUS_GRAPHICS_MONITOR_NOT_CONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY:
                reason = "STATUS_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE:
                reason = "STATUS_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VISIBLEREGION_SIZE:
                reason = "STATUS_GRAPHICS_INVALID_VISIBLEREGION_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_STRIDE:
                reason = "STATUS_GRAPHICS_INVALID_STRIDE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_PIXELFORMAT:
                reason = "STATUS_GRAPHICS_INVALID_PIXELFORMAT";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_COLORBASIS:
                reason = "STATUS_GRAPHICS_INVALID_COLORBASIS";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_PIXELVALUEACCESSMODE:
                reason = "STATUS_GRAPHICS_INVALID_PIXELVALUEACCESSMODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_TARGET_NOT_IN_TOPOLOGY:
                reason = "STATUS_GRAPHICS_TARGET_NOT_IN_TOPOLOGY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT:
                reason = "STATUS_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE:
                reason = "STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN:
                reason = "STATUS_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL:
                reason = "STATUS_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION:
                reason = "STATUS_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_GAMMA_RAMP:
                reason = "STATUS_GRAPHICS_INVALID_GAMMA_RAMP";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MODE_NOT_IN_MODESET:
                reason = "STATUS_GRAPHICS_MODE_NOT_IN_MODESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON:
                reason = "STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_PATH_CONTENT_TYPE:
                reason = "STATUS_GRAPHICS_INVALID_PATH_CONTENT_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_COPYPROTECTION_TYPE:
                reason = "STATUS_GRAPHICS_INVALID_COPYPROTECTION_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS:
                reason = "STATUS_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_SCANLINE_ORDERING:
                reason = "STATUS_GRAPHICS_INVALID_SCANLINE_ORDERING";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED:
                reason = "STATUS_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS:
                reason = "STATUS_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT:
                reason = "STATUS_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM:
                reason = "STATUS_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN:
                reason = "STATUS_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT:
                reason = "STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MAX_NUM_PATHS_REACHED:
                reason = "STATUS_GRAPHICS_MAX_NUM_PATHS_REACHED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION:
                reason = "STATUS_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_CLIENT_TYPE:
                reason = "STATUS_GRAPHICS_INVALID_CLIENT_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CLIENTVIDPN_NOT_SET:
                reason = "STATUS_GRAPHICS_CLIENTVIDPN_NOT_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED:
                reason = "STATUS_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NOT_A_LINKED_ADAPTER:
                reason = "STATUS_GRAPHICS_NOT_A_LINKED_ADAPTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_LEADLINK_NOT_ENUMERATED:
                reason = "STATUS_GRAPHICS_LEADLINK_NOT_ENUMERATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CHAINLINKS_NOT_ENUMERATED:
                reason = "STATUS_GRAPHICS_CHAINLINKS_NOT_ENUMERATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ADAPTER_CHAIN_NOT_READY:
                reason = "STATUS_GRAPHICS_ADAPTER_CHAIN_NOT_READY";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CHAINLINKS_NOT_STARTED:
                reason = "STATUS_GRAPHICS_CHAINLINKS_NOT_STARTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_CHAINLINKS_NOT_POWERED_ON:
                reason = "STATUS_GRAPHICS_CHAINLINKS_NOT_POWERED_ON";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE:
                reason = "STATUS_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NOT_POST_DEVICE_DRIVER:
                reason = "STATUS_GRAPHICS_NOT_POST_DEVICE_DRIVER";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED:
                reason = "STATUS_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_OPM_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_COPP_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_COPP_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_UAB_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_UAB_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS:
                reason = "STATUS_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_NO_PROTECTED_OUTPUTS_EXIST:
                reason = "STATUS_GRAPHICS_OPM_NO_PROTECTED_OUTPUTS_EXIST";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_INTERNAL_ERROR:
                reason = "STATUS_GRAPHICS_OPM_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_INVALID_HANDLE:
                reason = "STATUS_GRAPHICS_OPM_INVALID_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH:
                reason = "STATUS_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_SPANNING_MODE_ENABLED:
                reason = "STATUS_GRAPHICS_OPM_SPANNING_MODE_ENABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_THEATER_MODE_ENABLED:
                reason = "STATUS_GRAPHICS_OPM_THEATER_MODE_ENABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PVP_HFS_FAILED:
                reason = "STATUS_GRAPHICS_PVP_HFS_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_INVALID_SRM:
                reason = "STATUS_GRAPHICS_OPM_INVALID_SRM";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP:
                reason = "STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP:
                reason = "STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA:
                reason = "STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_HDCP_SRM_NEVER_SET:
                reason = "STATUS_GRAPHICS_OPM_HDCP_SRM_NEVER_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_RESOLUTION_TOO_HIGH:
                reason = "STATUS_GRAPHICS_OPM_RESOLUTION_TOO_HIGH";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE:
                reason = "STATUS_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_NO_LONGER_EXISTS:
                reason = "STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_NO_LONGER_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS:
                reason = "STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST:
                reason = "STATUS_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR:
                reason = "STATUS_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS:
                reason = "STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST:
                reason = "STATUS_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_I2C_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_I2C_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST:
                reason = "STATUS_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA:
                reason = "STATUS_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_I2C_ERROR_RECEIVING_DATA:
                reason = "STATUS_GRAPHICS_I2C_ERROR_RECEIVING_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_DDCCI_INVALID_DATA:
                reason = "STATUS_GRAPHICS_DDCCI_INVALID_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE:
                reason = "STATUS_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_DDCCI_INVALID_CAPABILITIES_STRING:
                reason = "STATUS_GRAPHICS_DDCCI_INVALID_CAPABILITIES_STRING";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MCA_INTERNAL_ERROR:
                reason = "STATUS_GRAPHICS_MCA_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND:
                reason = "STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH:
                reason = "STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM:
                reason = "STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE:
                reason = "STATUS_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MONITOR_NO_LONGER_EXISTS:
                reason = "STATUS_GRAPHICS_MONITOR_NO_LONGER_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED:
                reason = "STATUS_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME:
                reason = "STATUS_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP:
                reason = "STATUS_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED:
                reason = "STATUS_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INVALID_POINTER:
                reason = "STATUS_GRAPHICS_INVALID_POINTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE:
                reason = "STATUS_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL:
                reason = "STATUS_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_INTERNAL_ERROR:
                reason = "STATUS_GRAPHICS_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS:
                reason = "STATUS_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_LOCKED_VOLUME:
                reason = "STATUS_FVE_LOCKED_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NOT_ENCRYPTED:
                reason = "STATUS_FVE_NOT_ENCRYPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_BAD_INFORMATION:
                reason = "STATUS_FVE_BAD_INFORMATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_TOO_SMALL:
                reason = "STATUS_FVE_TOO_SMALL";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_FAILED_WRONG_FS:
                reason = "STATUS_FVE_FAILED_WRONG_FS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_BAD_PARTITION_SIZE:
                reason = "STATUS_FVE_BAD_PARTITION_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_FS_NOT_EXTENDED:
                reason = "STATUS_FVE_FS_NOT_EXTENDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_FS_MOUNTED:
                reason = "STATUS_FVE_FS_MOUNTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NO_LICENSE:
                reason = "STATUS_FVE_NO_LICENSE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_ACTION_NOT_ALLOWED:
                reason = "STATUS_FVE_ACTION_NOT_ALLOWED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_BAD_DATA:
                reason = "STATUS_FVE_BAD_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_VOLUME_NOT_BOUND:
                reason = "STATUS_FVE_VOLUME_NOT_BOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NOT_DATA_VOLUME:
                reason = "STATUS_FVE_NOT_DATA_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_CONV_READ_ERROR:
                reason = "STATUS_FVE_CONV_READ_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_CONV_WRITE_ERROR:
                reason = "STATUS_FVE_CONV_WRITE_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_OVERLAPPED_UPDATE:
                reason = "STATUS_FVE_OVERLAPPED_UPDATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_FAILED_SECTOR_SIZE:
                reason = "STATUS_FVE_FAILED_SECTOR_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_FAILED_AUTHENTICATION:
                reason = "STATUS_FVE_FAILED_AUTHENTICATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NOT_OS_VOLUME:
                reason = "STATUS_FVE_NOT_OS_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_KEYFILE_NOT_FOUND:
                reason = "STATUS_FVE_KEYFILE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_KEYFILE_INVALID:
                reason = "STATUS_FVE_KEYFILE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_KEYFILE_NO_VMK:
                reason = "STATUS_FVE_KEYFILE_NO_VMK";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_TPM_DISABLED:
                reason = "STATUS_FVE_TPM_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_TPM_SRK_AUTH_NOT_ZERO:
                reason = "STATUS_FVE_TPM_SRK_AUTH_NOT_ZERO";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_TPM_INVALID_PCR:
                reason = "STATUS_FVE_TPM_INVALID_PCR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_TPM_NO_VMK:
                reason = "STATUS_FVE_TPM_NO_VMK";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_PIN_INVALID:
                reason = "STATUS_FVE_PIN_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_AUTH_INVALID_APPLICATION:
                reason = "STATUS_FVE_AUTH_INVALID_APPLICATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_AUTH_INVALID_CONFIG:
                reason = "STATUS_FVE_AUTH_INVALID_CONFIG";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_DEBUGGER_ENABLED:
                reason = "STATUS_FVE_DEBUGGER_ENABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_DRY_RUN_FAILED:
                reason = "STATUS_FVE_DRY_RUN_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_BAD_METADATA_POINTER:
                reason = "STATUS_FVE_BAD_METADATA_POINTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_OLD_METADATA_COPY:
                reason = "STATUS_FVE_OLD_METADATA_COPY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_REBOOT_REQUIRED:
                reason = "STATUS_FVE_REBOOT_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_RAW_ACCESS:
                reason = "STATUS_FVE_RAW_ACCESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_RAW_BLOCKED:
                reason = "STATUS_FVE_RAW_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NO_AUTOUNLOCK_MASTER_KEY:
                reason = "STATUS_FVE_NO_AUTOUNLOCK_MASTER_KEY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_MOR_FAILED:
                reason = "STATUS_FVE_MOR_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NO_FEATURE_LICENSE:
                reason = "STATUS_FVE_NO_FEATURE_LICENSE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_POLICY_USER_DISABLE_RDV_NOT_ALLOWED:
                reason = "STATUS_FVE_POLICY_USER_DISABLE_RDV_NOT_ALLOWED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_CONV_RECOVERY_FAILED:
                reason = "STATUS_FVE_CONV_RECOVERY_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_VIRTUALIZED_SPACE_TOO_BIG:
                reason = "STATUS_FVE_VIRTUALIZED_SPACE_TOO_BIG";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_INVALID_DATUM_TYPE:
                reason = "STATUS_FVE_INVALID_DATUM_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_VOLUME_TOO_SMALL:
                reason = "STATUS_FVE_VOLUME_TOO_SMALL";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_ENH_PIN_INVALID:
                reason = "STATUS_FVE_ENH_PIN_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE:
                reason = "STATUS_FVE_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_WIPE_NOT_ALLOWED_ON_TP_STORAGE:
                reason = "STATUS_FVE_WIPE_NOT_ALLOWED_ON_TP_STORAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NOT_ALLOWED_ON_CSV_STACK:
                reason = "STATUS_FVE_NOT_ALLOWED_ON_CSV_STACK";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NOT_ALLOWED_ON_CLUSTER:
                reason = "STATUS_FVE_NOT_ALLOWED_ON_CLUSTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING:
                reason = "STATUS_FVE_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_WIPE_CANCEL_NOT_APPLICABLE:
                reason = "STATUS_FVE_WIPE_CANCEL_NOT_APPLICABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_EDRIVE_DRY_RUN_FAILED:
                reason = "STATUS_FVE_EDRIVE_DRY_RUN_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_SECUREBOOT_DISABLED:
                reason = "STATUS_FVE_SECUREBOOT_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_SECUREBOOT_CONFIG_CHANGE:
                reason = "STATUS_FVE_SECUREBOOT_CONFIG_CHANGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_DEVICE_LOCKEDOUT:
                reason = "STATUS_FVE_DEVICE_LOCKEDOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT:
                reason = "STATUS_FVE_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_NOT_DE_VOLUME:
                reason = "STATUS_FVE_NOT_DE_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_PROTECTION_DISABLED:
                reason = "STATUS_FVE_PROTECTION_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FVE_PROTECTION_CANNOT_BE_DISABLED:
                reason = "STATUS_FVE_PROTECTION_CANNOT_BE_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_CALLOUT_NOT_FOUND:
                reason = "STATUS_FWP_CALLOUT_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_CONDITION_NOT_FOUND:
                reason = "STATUS_FWP_CONDITION_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_FILTER_NOT_FOUND:
                reason = "STATUS_FWP_FILTER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_LAYER_NOT_FOUND:
                reason = "STATUS_FWP_LAYER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_PROVIDER_NOT_FOUND:
                reason = "STATUS_FWP_PROVIDER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_PROVIDER_CONTEXT_NOT_FOUND:
                reason = "STATUS_FWP_PROVIDER_CONTEXT_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_SUBLAYER_NOT_FOUND:
                reason = "STATUS_FWP_SUBLAYER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_NOT_FOUND:
                reason = "STATUS_FWP_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_ALREADY_EXISTS:
                reason = "STATUS_FWP_ALREADY_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_IN_USE:
                reason = "STATUS_FWP_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_DYNAMIC_SESSION_IN_PROGRESS:
                reason = "STATUS_FWP_DYNAMIC_SESSION_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_WRONG_SESSION:
                reason = "STATUS_FWP_WRONG_SESSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_NO_TXN_IN_PROGRESS:
                reason = "STATUS_FWP_NO_TXN_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_TXN_IN_PROGRESS:
                reason = "STATUS_FWP_TXN_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_TXN_ABORTED:
                reason = "STATUS_FWP_TXN_ABORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_SESSION_ABORTED:
                reason = "STATUS_FWP_SESSION_ABORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INCOMPATIBLE_TXN:
                reason = "STATUS_FWP_INCOMPATIBLE_TXN";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_TIMEOUT:
                reason = "STATUS_FWP_TIMEOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_NET_EVENTS_DISABLED:
                reason = "STATUS_FWP_NET_EVENTS_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INCOMPATIBLE_LAYER:
                reason = "STATUS_FWP_INCOMPATIBLE_LAYER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_KM_CLIENTS_ONLY:
                reason = "STATUS_FWP_KM_CLIENTS_ONLY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_LIFETIME_MISMATCH:
                reason = "STATUS_FWP_LIFETIME_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_BUILTIN_OBJECT:
                reason = "STATUS_FWP_BUILTIN_OBJECT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_TOO_MANY_CALLOUTS:
                reason = "STATUS_FWP_TOO_MANY_CALLOUTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_NOTIFICATION_DROPPED:
                reason = "STATUS_FWP_NOTIFICATION_DROPPED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_TRAFFIC_MISMATCH:
                reason = "STATUS_FWP_TRAFFIC_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INCOMPATIBLE_SA_STATE:
                reason = "STATUS_FWP_INCOMPATIBLE_SA_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_NULL_POINTER:
                reason = "STATUS_FWP_NULL_POINTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_ENUMERATOR:
                reason = "STATUS_FWP_INVALID_ENUMERATOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_FLAGS:
                reason = "STATUS_FWP_INVALID_FLAGS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_NET_MASK:
                reason = "STATUS_FWP_INVALID_NET_MASK";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_RANGE:
                reason = "STATUS_FWP_INVALID_RANGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_INTERVAL:
                reason = "STATUS_FWP_INVALID_INTERVAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_ZERO_LENGTH_ARRAY:
                reason = "STATUS_FWP_ZERO_LENGTH_ARRAY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_NULL_DISPLAY_NAME:
                reason = "STATUS_FWP_NULL_DISPLAY_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_ACTION_TYPE:
                reason = "STATUS_FWP_INVALID_ACTION_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_WEIGHT:
                reason = "STATUS_FWP_INVALID_WEIGHT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_MATCH_TYPE_MISMATCH:
                reason = "STATUS_FWP_MATCH_TYPE_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_TYPE_MISMATCH:
                reason = "STATUS_FWP_TYPE_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_OUT_OF_BOUNDS:
                reason = "STATUS_FWP_OUT_OF_BOUNDS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_RESERVED:
                reason = "STATUS_FWP_RESERVED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_DUPLICATE_CONDITION:
                reason = "STATUS_FWP_DUPLICATE_CONDITION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_DUPLICATE_KEYMOD:
                reason = "STATUS_FWP_DUPLICATE_KEYMOD";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_ACTION_INCOMPATIBLE_WITH_LAYER:
                reason = "STATUS_FWP_ACTION_INCOMPATIBLE_WITH_LAYER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_ACTION_INCOMPATIBLE_WITH_SUBLAYER:
                reason = "STATUS_FWP_ACTION_INCOMPATIBLE_WITH_SUBLAYER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_LAYER:
                reason = "STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_LAYER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_CALLOUT:
                reason = "STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_CALLOUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INCOMPATIBLE_AUTH_METHOD:
                reason = "STATUS_FWP_INCOMPATIBLE_AUTH_METHOD";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INCOMPATIBLE_DH_GROUP:
                reason = "STATUS_FWP_INCOMPATIBLE_DH_GROUP";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_EM_NOT_SUPPORTED:
                reason = "STATUS_FWP_EM_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_NEVER_MATCH:
                reason = "STATUS_FWP_NEVER_MATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_PROVIDER_CONTEXT_MISMATCH:
                reason = "STATUS_FWP_PROVIDER_CONTEXT_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_PARAMETER:
                reason = "STATUS_FWP_INVALID_PARAMETER";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_TOO_MANY_SUBLAYERS:
                reason = "STATUS_FWP_TOO_MANY_SUBLAYERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_CALLOUT_NOTIFICATION_FAILED:
                reason = "STATUS_FWP_CALLOUT_NOTIFICATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_AUTH_TRANSFORM:
                reason = "STATUS_FWP_INVALID_AUTH_TRANSFORM";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_CIPHER_TRANSFORM:
                reason = "STATUS_FWP_INVALID_CIPHER_TRANSFORM";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INCOMPATIBLE_CIPHER_TRANSFORM:
                reason = "STATUS_FWP_INCOMPATIBLE_CIPHER_TRANSFORM";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_TRANSFORM_COMBINATION:
                reason = "STATUS_FWP_INVALID_TRANSFORM_COMBINATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_DUPLICATE_AUTH_METHOD:
                reason = "STATUS_FWP_DUPLICATE_AUTH_METHOD";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_TUNNEL_ENDPOINT:
                reason = "STATUS_FWP_INVALID_TUNNEL_ENDPOINT";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_L2_DRIVER_NOT_READY:
                reason = "STATUS_FWP_L2_DRIVER_NOT_READY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_KEY_DICTATOR_ALREADY_REGISTERED:
                reason = "STATUS_FWP_KEY_DICTATOR_ALREADY_REGISTERED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_KEY_DICTATION_INVALID_KEYING_MATERIAL:
                reason = "STATUS_FWP_KEY_DICTATION_INVALID_KEYING_MATERIAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_CONNECTIONS_DISABLED:
                reason = "STATUS_FWP_CONNECTIONS_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INVALID_DNS_NAME:
                reason = "STATUS_FWP_INVALID_DNS_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_STILL_ON:
                reason = "STATUS_FWP_STILL_ON";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_IKEEXT_NOT_RUNNING:
                reason = "STATUS_FWP_IKEEXT_NOT_RUNNING";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_TCPIP_NOT_READY:
                reason = "STATUS_FWP_TCPIP_NOT_READY";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INJECT_HANDLE_CLOSING:
                reason = "STATUS_FWP_INJECT_HANDLE_CLOSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_INJECT_HANDLE_STALE:
                reason = "STATUS_FWP_INJECT_HANDLE_STALE";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_CANNOT_PEND:
                reason = "STATUS_FWP_CANNOT_PEND";
                break;
            case MD_NTSTATUS_WIN_STATUS_FWP_DROP_NOICMP:
                reason = "STATUS_FWP_DROP_NOICMP";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_CLOSING:
                reason = "STATUS_NDIS_CLOSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_BAD_VERSION:
                reason = "STATUS_NDIS_BAD_VERSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_BAD_CHARACTERISTICS:
                reason = "STATUS_NDIS_BAD_CHARACTERISTICS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_ADAPTER_NOT_FOUND:
                reason = "STATUS_NDIS_ADAPTER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_OPEN_FAILED:
                reason = "STATUS_NDIS_OPEN_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_DEVICE_FAILED:
                reason = "STATUS_NDIS_DEVICE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_MULTICAST_FULL:
                reason = "STATUS_NDIS_MULTICAST_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_MULTICAST_EXISTS:
                reason = "STATUS_NDIS_MULTICAST_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_MULTICAST_NOT_FOUND:
                reason = "STATUS_NDIS_MULTICAST_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_REQUEST_ABORTED:
                reason = "STATUS_NDIS_REQUEST_ABORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_RESET_IN_PROGRESS:
                reason = "STATUS_NDIS_RESET_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_INVALID_PACKET:
                reason = "STATUS_NDIS_INVALID_PACKET";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_INVALID_DEVICE_REQUEST:
                reason = "STATUS_NDIS_INVALID_DEVICE_REQUEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_ADAPTER_NOT_READY:
                reason = "STATUS_NDIS_ADAPTER_NOT_READY";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_INVALID_LENGTH:
                reason = "STATUS_NDIS_INVALID_LENGTH";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_INVALID_DATA:
                reason = "STATUS_NDIS_INVALID_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_BUFFER_TOO_SHORT:
                reason = "STATUS_NDIS_BUFFER_TOO_SHORT";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_INVALID_OID:
                reason = "STATUS_NDIS_INVALID_OID";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_ADAPTER_REMOVED:
                reason = "STATUS_NDIS_ADAPTER_REMOVED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_UNSUPPORTED_MEDIA:
                reason = "STATUS_NDIS_UNSUPPORTED_MEDIA";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_GROUP_ADDRESS_IN_USE:
                reason = "STATUS_NDIS_GROUP_ADDRESS_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_FILE_NOT_FOUND:
                reason = "STATUS_NDIS_FILE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_ERROR_READING_FILE:
                reason = "STATUS_NDIS_ERROR_READING_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_ALREADY_MAPPED:
                reason = "STATUS_NDIS_ALREADY_MAPPED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_RESOURCE_CONFLICT:
                reason = "STATUS_NDIS_RESOURCE_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_MEDIA_DISCONNECTED:
                reason = "STATUS_NDIS_MEDIA_DISCONNECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_INVALID_ADDRESS:
                reason = "STATUS_NDIS_INVALID_ADDRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_PAUSED:
                reason = "STATUS_NDIS_PAUSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_INTERFACE_NOT_FOUND:
                reason = "STATUS_NDIS_INTERFACE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_UNSUPPORTED_REVISION:
                reason = "STATUS_NDIS_UNSUPPORTED_REVISION";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_INVALID_PORT:
                reason = "STATUS_NDIS_INVALID_PORT";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_INVALID_PORT_STATE:
                reason = "STATUS_NDIS_INVALID_PORT_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_LOW_POWER_STATE:
                reason = "STATUS_NDIS_LOW_POWER_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_REINIT_REQUIRED:
                reason = "STATUS_NDIS_REINIT_REQUIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_NOT_SUPPORTED:
                reason = "STATUS_NDIS_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_OFFLOAD_POLICY:
                reason = "STATUS_NDIS_OFFLOAD_POLICY";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_OFFLOAD_CONNECTION_REJECTED:
                reason = "STATUS_NDIS_OFFLOAD_CONNECTION_REJECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_OFFLOAD_PATH_REJECTED:
                reason = "STATUS_NDIS_OFFLOAD_PATH_REJECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_DOT11_AUTO_CONFIG_ENABLED:
                reason = "STATUS_NDIS_DOT11_AUTO_CONFIG_ENABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_DOT11_MEDIA_IN_USE:
                reason = "STATUS_NDIS_DOT11_MEDIA_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_DOT11_POWER_STATE_INVALID:
                reason = "STATUS_NDIS_DOT11_POWER_STATE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_PM_WOL_PATTERN_LIST_FULL:
                reason = "STATUS_NDIS_PM_WOL_PATTERN_LIST_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL:
                reason = "STATUS_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_ERROR_MASK:
                reason = "STATUS_TPM_ERROR_MASK";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_AUTHFAIL:
                reason = "STATUS_TPM_AUTHFAIL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BADINDEX:
                reason = "STATUS_TPM_BADINDEX";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_PARAMETER:
                reason = "STATUS_TPM_BAD_PARAMETER";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_AUDITFAILURE:
                reason = "STATUS_TPM_AUDITFAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_CLEAR_DISABLED:
                reason = "STATUS_TPM_CLEAR_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DEACTIVATED:
                reason = "STATUS_TPM_DEACTIVATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DISABLED:
                reason = "STATUS_TPM_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DISABLED_CMD:
                reason = "STATUS_TPM_DISABLED_CMD";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_FAIL:
                reason = "STATUS_TPM_FAIL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_ORDINAL:
                reason = "STATUS_TPM_BAD_ORDINAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INSTALL_DISABLED:
                reason = "STATUS_TPM_INSTALL_DISABLED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INVALID_KEYHANDLE:
                reason = "STATUS_TPM_INVALID_KEYHANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_KEYNOTFOUND:
                reason = "STATUS_TPM_KEYNOTFOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INAPPROPRIATE_ENC:
                reason = "STATUS_TPM_INAPPROPRIATE_ENC";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_MIGRATEFAIL:
                reason = "STATUS_TPM_MIGRATEFAIL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INVALID_PCR_INFO:
                reason = "STATUS_TPM_INVALID_PCR_INFO";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOSPACE:
                reason = "STATUS_TPM_NOSPACE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOSRK:
                reason = "STATUS_TPM_NOSRK";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOTSEALED_BLOB:
                reason = "STATUS_TPM_NOTSEALED_BLOB";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_OWNER_SET:
                reason = "STATUS_TPM_OWNER_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_RESOURCES:
                reason = "STATUS_TPM_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_SHORTRANDOM:
                reason = "STATUS_TPM_SHORTRANDOM";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_SIZE:
                reason = "STATUS_TPM_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_WRONGPCRVAL:
                reason = "STATUS_TPM_WRONGPCRVAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_PARAM_SIZE:
                reason = "STATUS_TPM_BAD_PARAM_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_SHA_THREAD:
                reason = "STATUS_TPM_SHA_THREAD";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_SHA_ERROR:
                reason = "STATUS_TPM_SHA_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_FAILEDSELFTEST:
                reason = "STATUS_TPM_FAILEDSELFTEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_AUTH2FAIL:
                reason = "STATUS_TPM_AUTH2FAIL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BADTAG:
                reason = "STATUS_TPM_BADTAG";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_IOERROR:
                reason = "STATUS_TPM_IOERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_ENCRYPT_ERROR:
                reason = "STATUS_TPM_ENCRYPT_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DECRYPT_ERROR:
                reason = "STATUS_TPM_DECRYPT_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INVALID_AUTHHANDLE:
                reason = "STATUS_TPM_INVALID_AUTHHANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NO_ENDORSEMENT:
                reason = "STATUS_TPM_NO_ENDORSEMENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INVALID_KEYUSAGE:
                reason = "STATUS_TPM_INVALID_KEYUSAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_WRONG_ENTITYTYPE:
                reason = "STATUS_TPM_WRONG_ENTITYTYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INVALID_POSTINIT:
                reason = "STATUS_TPM_INVALID_POSTINIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INAPPROPRIATE_SIG:
                reason = "STATUS_TPM_INAPPROPRIATE_SIG";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_KEY_PROPERTY:
                reason = "STATUS_TPM_BAD_KEY_PROPERTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_MIGRATION:
                reason = "STATUS_TPM_BAD_MIGRATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_SCHEME:
                reason = "STATUS_TPM_BAD_SCHEME";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_DATASIZE:
                reason = "STATUS_TPM_BAD_DATASIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_MODE:
                reason = "STATUS_TPM_BAD_MODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_PRESENCE:
                reason = "STATUS_TPM_BAD_PRESENCE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_VERSION:
                reason = "STATUS_TPM_BAD_VERSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NO_WRAP_TRANSPORT:
                reason = "STATUS_TPM_NO_WRAP_TRANSPORT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_AUDITFAIL_UNSUCCESSFUL:
                reason = "STATUS_TPM_AUDITFAIL_UNSUCCESSFUL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_AUDITFAIL_SUCCESSFUL:
                reason = "STATUS_TPM_AUDITFAIL_SUCCESSFUL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOTRESETABLE:
                reason = "STATUS_TPM_NOTRESETABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOTLOCAL:
                reason = "STATUS_TPM_NOTLOCAL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_TYPE:
                reason = "STATUS_TPM_BAD_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INVALID_RESOURCE:
                reason = "STATUS_TPM_INVALID_RESOURCE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOTFIPS:
                reason = "STATUS_TPM_NOTFIPS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INVALID_FAMILY:
                reason = "STATUS_TPM_INVALID_FAMILY";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NO_NV_PERMISSION:
                reason = "STATUS_TPM_NO_NV_PERMISSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_REQUIRES_SIGN:
                reason = "STATUS_TPM_REQUIRES_SIGN";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_KEY_NOTSUPPORTED:
                reason = "STATUS_TPM_KEY_NOTSUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_AUTH_CONFLICT:
                reason = "STATUS_TPM_AUTH_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_AREA_LOCKED:
                reason = "STATUS_TPM_AREA_LOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_LOCALITY:
                reason = "STATUS_TPM_BAD_LOCALITY";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_READ_ONLY:
                reason = "STATUS_TPM_READ_ONLY";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_PER_NOWRITE:
                reason = "STATUS_TPM_PER_NOWRITE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_FAMILYCOUNT:
                reason = "STATUS_TPM_FAMILYCOUNT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_WRITE_LOCKED:
                reason = "STATUS_TPM_WRITE_LOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_ATTRIBUTES:
                reason = "STATUS_TPM_BAD_ATTRIBUTES";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INVALID_STRUCTURE:
                reason = "STATUS_TPM_INVALID_STRUCTURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_KEY_OWNER_CONTROL:
                reason = "STATUS_TPM_KEY_OWNER_CONTROL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_COUNTER:
                reason = "STATUS_TPM_BAD_COUNTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOT_FULLWRITE:
                reason = "STATUS_TPM_NOT_FULLWRITE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_CONTEXT_GAP:
                reason = "STATUS_TPM_CONTEXT_GAP";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_MAXNVWRITES:
                reason = "STATUS_TPM_MAXNVWRITES";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOOPERATOR:
                reason = "STATUS_TPM_NOOPERATOR";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_RESOURCEMISSING:
                reason = "STATUS_TPM_RESOURCEMISSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DELEGATE_LOCK:
                reason = "STATUS_TPM_DELEGATE_LOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DELEGATE_FAMILY:
                reason = "STATUS_TPM_DELEGATE_FAMILY";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DELEGATE_ADMIN:
                reason = "STATUS_TPM_DELEGATE_ADMIN";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_TRANSPORT_NOTEXCLUSIVE:
                reason = "STATUS_TPM_TRANSPORT_NOTEXCLUSIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_OWNER_CONTROL:
                reason = "STATUS_TPM_OWNER_CONTROL";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DAA_RESOURCES:
                reason = "STATUS_TPM_DAA_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DAA_INPUT_DATA0:
                reason = "STATUS_TPM_DAA_INPUT_DATA0";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DAA_INPUT_DATA1:
                reason = "STATUS_TPM_DAA_INPUT_DATA1";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DAA_ISSUER_SETTINGS:
                reason = "STATUS_TPM_DAA_ISSUER_SETTINGS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DAA_TPM_SETTINGS:
                reason = "STATUS_TPM_DAA_TPM_SETTINGS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DAA_STAGE:
                reason = "STATUS_TPM_DAA_STAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DAA_ISSUER_VALIDITY:
                reason = "STATUS_TPM_DAA_ISSUER_VALIDITY";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DAA_WRONG_W:
                reason = "STATUS_TPM_DAA_WRONG_W";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_HANDLE:
                reason = "STATUS_TPM_BAD_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_DELEGATE:
                reason = "STATUS_TPM_BAD_DELEGATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BADCONTEXT:
                reason = "STATUS_TPM_BADCONTEXT";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_TOOMANYCONTEXTS:
                reason = "STATUS_TPM_TOOMANYCONTEXTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_MA_TICKET_SIGNATURE:
                reason = "STATUS_TPM_MA_TICKET_SIGNATURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_MA_DESTINATION:
                reason = "STATUS_TPM_MA_DESTINATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_MA_SOURCE:
                reason = "STATUS_TPM_MA_SOURCE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_MA_AUTHORITY:
                reason = "STATUS_TPM_MA_AUTHORITY";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_PERMANENTEK:
                reason = "STATUS_TPM_PERMANENTEK";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_BAD_SIGNATURE:
                reason = "STATUS_TPM_BAD_SIGNATURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOCONTEXTSPACE:
                reason = "STATUS_TPM_NOCONTEXTSPACE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_COMMAND_BLOCKED:
                reason = "STATUS_TPM_COMMAND_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INVALID_HANDLE:
                reason = "STATUS_TPM_INVALID_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DUPLICATE_VHANDLE:
                reason = "STATUS_TPM_DUPLICATE_VHANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_EMBEDDED_COMMAND_BLOCKED:
                reason = "STATUS_TPM_EMBEDDED_COMMAND_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_EMBEDDED_COMMAND_UNSUPPORTED:
                reason = "STATUS_TPM_EMBEDDED_COMMAND_UNSUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_RETRY:
                reason = "STATUS_TPM_RETRY";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NEEDS_SELFTEST:
                reason = "STATUS_TPM_NEEDS_SELFTEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DOING_SELFTEST:
                reason = "STATUS_TPM_DOING_SELFTEST";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_DEFEND_LOCK_RUNNING:
                reason = "STATUS_TPM_DEFEND_LOCK_RUNNING";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_COMMAND_CANCELED:
                reason = "STATUS_TPM_COMMAND_CANCELED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_TOO_MANY_CONTEXTS:
                reason = "STATUS_TPM_TOO_MANY_CONTEXTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_NOT_FOUND:
                reason = "STATUS_TPM_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_ACCESS_DENIED:
                reason = "STATUS_TPM_ACCESS_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_INSUFFICIENT_BUFFER:
                reason = "STATUS_TPM_INSUFFICIENT_BUFFER";
                break;
            case MD_NTSTATUS_WIN_STATUS_TPM_PPI_FUNCTION_UNSUPPORTED:
                reason = "STATUS_TPM_PPI_FUNCTION_UNSUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_ERROR_MASK:
                reason = "STATUS_PCP_ERROR_MASK";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_DEVICE_NOT_READY:
                reason = "STATUS_PCP_DEVICE_NOT_READY";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_INVALID_HANDLE:
                reason = "STATUS_PCP_INVALID_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_INVALID_PARAMETER:
                reason = "STATUS_PCP_INVALID_PARAMETER";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_FLAG_NOT_SUPPORTED:
                reason = "STATUS_PCP_FLAG_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_NOT_SUPPORTED:
                reason = "STATUS_PCP_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_BUFFER_TOO_SMALL:
                reason = "STATUS_PCP_BUFFER_TOO_SMALL";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_INTERNAL_ERROR:
                reason = "STATUS_PCP_INTERNAL_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_AUTHENTICATION_FAILED:
                reason = "STATUS_PCP_AUTHENTICATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_AUTHENTICATION_IGNORED:
                reason = "STATUS_PCP_AUTHENTICATION_IGNORED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_POLICY_NOT_FOUND:
                reason = "STATUS_PCP_POLICY_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_PROFILE_NOT_FOUND:
                reason = "STATUS_PCP_PROFILE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_VALIDATION_FAILED:
                reason = "STATUS_PCP_VALIDATION_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_PCP_DEVICE_NOT_FOUND:
                reason = "STATUS_PCP_DEVICE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_HYPERCALL_CODE:
                reason = "STATUS_HV_INVALID_HYPERCALL_CODE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_HYPERCALL_INPUT:
                reason = "STATUS_HV_INVALID_HYPERCALL_INPUT";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_ALIGNMENT:
                reason = "STATUS_HV_INVALID_ALIGNMENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_PARAMETER:
                reason = "STATUS_HV_INVALID_PARAMETER";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_ACCESS_DENIED:
                reason = "STATUS_HV_ACCESS_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_PARTITION_STATE:
                reason = "STATUS_HV_INVALID_PARTITION_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_OPERATION_DENIED:
                reason = "STATUS_HV_OPERATION_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_UNKNOWN_PROPERTY:
                reason = "STATUS_HV_UNKNOWN_PROPERTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_PROPERTY_VALUE_OUT_OF_RANGE:
                reason = "STATUS_HV_PROPERTY_VALUE_OUT_OF_RANGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INSUFFICIENT_MEMORY:
                reason = "STATUS_HV_INSUFFICIENT_MEMORY";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_PARTITION_TOO_DEEP:
                reason = "STATUS_HV_PARTITION_TOO_DEEP";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_PARTITION_ID:
                reason = "STATUS_HV_INVALID_PARTITION_ID";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_VP_INDEX:
                reason = "STATUS_HV_INVALID_VP_INDEX";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_PORT_ID:
                reason = "STATUS_HV_INVALID_PORT_ID";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_CONNECTION_ID:
                reason = "STATUS_HV_INVALID_CONNECTION_ID";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INSUFFICIENT_BUFFERS:
                reason = "STATUS_HV_INSUFFICIENT_BUFFERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_NOT_ACKNOWLEDGED:
                reason = "STATUS_HV_NOT_ACKNOWLEDGED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_ACKNOWLEDGED:
                reason = "STATUS_HV_ACKNOWLEDGED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_SAVE_RESTORE_STATE:
                reason = "STATUS_HV_INVALID_SAVE_RESTORE_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_SYNIC_STATE:
                reason = "STATUS_HV_INVALID_SYNIC_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_OBJECT_IN_USE:
                reason = "STATUS_HV_OBJECT_IN_USE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_PROXIMITY_DOMAIN_INFO:
                reason = "STATUS_HV_INVALID_PROXIMITY_DOMAIN_INFO";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_NO_DATA:
                reason = "STATUS_HV_NO_DATA";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INACTIVE:
                reason = "STATUS_HV_INACTIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_NO_RESOURCES:
                reason = "STATUS_HV_NO_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_FEATURE_UNAVAILABLE:
                reason = "STATUS_HV_FEATURE_UNAVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INSUFFICIENT_BUFFER:
                reason = "STATUS_HV_INSUFFICIENT_BUFFER";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INSUFFICIENT_DEVICE_DOMAINS:
                reason = "STATUS_HV_INSUFFICIENT_DEVICE_DOMAINS";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_INVALID_LP_INDEX:
                reason = "STATUS_HV_INVALID_LP_INDEX";
                break;
            case MD_NTSTATUS_WIN_STATUS_HV_NOT_PRESENT:
                reason = "STATUS_HV_NOT_PRESENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_BAD_SPI:
                reason = "STATUS_IPSEC_BAD_SPI";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_SA_LIFETIME_EXPIRED:
                reason = "STATUS_IPSEC_SA_LIFETIME_EXPIRED";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_WRONG_SA:
                reason = "STATUS_IPSEC_WRONG_SA";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_REPLAY_CHECK_FAILED:
                reason = "STATUS_IPSEC_REPLAY_CHECK_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_INVALID_PACKET:
                reason = "STATUS_IPSEC_INVALID_PACKET";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_INTEGRITY_CHECK_FAILED:
                reason = "STATUS_IPSEC_INTEGRITY_CHECK_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_CLEAR_TEXT_DROP:
                reason = "STATUS_IPSEC_CLEAR_TEXT_DROP";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_AUTH_FIREWALL_DROP:
                reason = "STATUS_IPSEC_AUTH_FIREWALL_DROP";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_THROTTLE_DROP:
                reason = "STATUS_IPSEC_THROTTLE_DROP";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_DOSP_BLOCK:
                reason = "STATUS_IPSEC_DOSP_BLOCK";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_DOSP_RECEIVED_MULTICAST:
                reason = "STATUS_IPSEC_DOSP_RECEIVED_MULTICAST";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_DOSP_INVALID_PACKET:
                reason = "STATUS_IPSEC_DOSP_INVALID_PACKET";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_DOSP_STATE_LOOKUP_FAILED:
                reason = "STATUS_IPSEC_DOSP_STATE_LOOKUP_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_DOSP_MAX_ENTRIES:
                reason = "STATUS_IPSEC_DOSP_MAX_ENTRIES";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_DOSP_KEYMOD_NOT_ALLOWED:
                reason = "STATUS_IPSEC_DOSP_KEYMOD_NOT_ALLOWED";
                break;
            case MD_NTSTATUS_WIN_STATUS_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES:
                reason = "STATUS_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_DUPLICATE_HANDLER:
                reason = "STATUS_VID_DUPLICATE_HANDLER";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_TOO_MANY_HANDLERS:
                reason = "STATUS_VID_TOO_MANY_HANDLERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_QUEUE_FULL:
                reason = "STATUS_VID_QUEUE_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_HANDLER_NOT_PRESENT:
                reason = "STATUS_VID_HANDLER_NOT_PRESENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_INVALID_OBJECT_NAME:
                reason = "STATUS_VID_INVALID_OBJECT_NAME";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_PARTITION_NAME_TOO_LONG:
                reason = "STATUS_VID_PARTITION_NAME_TOO_LONG";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MESSAGE_QUEUE_NAME_TOO_LONG:
                reason = "STATUS_VID_MESSAGE_QUEUE_NAME_TOO_LONG";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_PARTITION_ALREADY_EXISTS:
                reason = "STATUS_VID_PARTITION_ALREADY_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_PARTITION_DOES_NOT_EXIST:
                reason = "STATUS_VID_PARTITION_DOES_NOT_EXIST";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_PARTITION_NAME_NOT_FOUND:
                reason = "STATUS_VID_PARTITION_NAME_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MESSAGE_QUEUE_ALREADY_EXISTS:
                reason = "STATUS_VID_MESSAGE_QUEUE_ALREADY_EXISTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_EXCEEDED_MBP_ENTRY_MAP_LIMIT:
                reason = "STATUS_VID_EXCEEDED_MBP_ENTRY_MAP_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MB_STILL_REFERENCED:
                reason = "STATUS_VID_MB_STILL_REFERENCED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_CHILD_GPA_PAGE_SET_CORRUPTED:
                reason = "STATUS_VID_CHILD_GPA_PAGE_SET_CORRUPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_INVALID_NUMA_SETTINGS:
                reason = "STATUS_VID_INVALID_NUMA_SETTINGS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_INVALID_NUMA_NODE_INDEX:
                reason = "STATUS_VID_INVALID_NUMA_NODE_INDEX";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_NOTIFICATION_QUEUE_ALREADY_ASSOCIATED:
                reason = "STATUS_VID_NOTIFICATION_QUEUE_ALREADY_ASSOCIATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_INVALID_MEMORY_BLOCK_HANDLE:
                reason = "STATUS_VID_INVALID_MEMORY_BLOCK_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_PAGE_RANGE_OVERFLOW:
                reason = "STATUS_VID_PAGE_RANGE_OVERFLOW";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_INVALID_MESSAGE_QUEUE_HANDLE:
                reason = "STATUS_VID_INVALID_MESSAGE_QUEUE_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_INVALID_GPA_RANGE_HANDLE:
                reason = "STATUS_VID_INVALID_GPA_RANGE_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_NO_MEMORY_BLOCK_NOTIFICATION_QUEUE:
                reason = "STATUS_VID_NO_MEMORY_BLOCK_NOTIFICATION_QUEUE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MEMORY_BLOCK_LOCK_COUNT_EXCEEDED:
                reason = "STATUS_VID_MEMORY_BLOCK_LOCK_COUNT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_INVALID_PPM_HANDLE:
                reason = "STATUS_VID_INVALID_PPM_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MBPS_ARE_LOCKED:
                reason = "STATUS_VID_MBPS_ARE_LOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MESSAGE_QUEUE_CLOSED:
                reason = "STATUS_VID_MESSAGE_QUEUE_CLOSED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_VIRTUAL_PROCESSOR_LIMIT_EXCEEDED:
                reason = "STATUS_VID_VIRTUAL_PROCESSOR_LIMIT_EXCEEDED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_STOP_PENDING:
                reason = "STATUS_VID_STOP_PENDING";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_INVALID_PROCESSOR_STATE:
                reason = "STATUS_VID_INVALID_PROCESSOR_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_EXCEEDED_KM_CONTEXT_COUNT_LIMIT:
                reason = "STATUS_VID_EXCEEDED_KM_CONTEXT_COUNT_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_KM_INTERFACE_ALREADY_INITIALIZED:
                reason = "STATUS_VID_KM_INTERFACE_ALREADY_INITIALIZED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MB_PROPERTY_ALREADY_SET_RESET:
                reason = "STATUS_VID_MB_PROPERTY_ALREADY_SET_RESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MMIO_RANGE_DESTROYED:
                reason = "STATUS_VID_MMIO_RANGE_DESTROYED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_INVALID_CHILD_GPA_PAGE_SET:
                reason = "STATUS_VID_INVALID_CHILD_GPA_PAGE_SET";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_RESERVE_PAGE_SET_IS_BEING_USED:
                reason = "STATUS_VID_RESERVE_PAGE_SET_IS_BEING_USED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_RESERVE_PAGE_SET_TOO_SMALL:
                reason = "STATUS_VID_RESERVE_PAGE_SET_TOO_SMALL";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MBP_ALREADY_LOCKED_USING_RESERVED_PAGE:
                reason = "STATUS_VID_MBP_ALREADY_LOCKED_USING_RESERVED_PAGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_MBP_COUNT_EXCEEDED_LIMIT:
                reason = "STATUS_VID_MBP_COUNT_EXCEEDED_LIMIT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_SAVED_STATE_CORRUPT:
                reason = "STATUS_VID_SAVED_STATE_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_SAVED_STATE_UNRECOGNIZED_ITEM:
                reason = "STATUS_VID_SAVED_STATE_UNRECOGNIZED_ITEM";
                break;
            case MD_NTSTATUS_WIN_STATUS_VID_SAVED_STATE_INCOMPATIBLE:
                reason = "STATUS_VID_SAVED_STATE_INCOMPATIBLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DATABASE_FULL:
                reason = "STATUS_VOLMGR_DATABASE_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_CONFIGURATION_CORRUPTED:
                reason = "STATUS_VOLMGR_DISK_CONFIGURATION_CORRUPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_CONFIGURATION_NOT_IN_SYNC:
                reason = "STATUS_VOLMGR_DISK_CONFIGURATION_NOT_IN_SYNC";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_CONFIG_UPDATE_FAILED:
                reason = "STATUS_VOLMGR_PACK_CONFIG_UPDATE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_CONTAINS_NON_SIMPLE_VOLUME:
                reason = "STATUS_VOLMGR_DISK_CONTAINS_NON_SIMPLE_VOLUME";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_DUPLICATE:
                reason = "STATUS_VOLMGR_DISK_DUPLICATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_DYNAMIC:
                reason = "STATUS_VOLMGR_DISK_DYNAMIC";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_ID_INVALID:
                reason = "STATUS_VOLMGR_DISK_ID_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_INVALID:
                reason = "STATUS_VOLMGR_DISK_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_LAST_VOTER:
                reason = "STATUS_VOLMGR_DISK_LAST_VOTER";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_LAYOUT_INVALID:
                reason = "STATUS_VOLMGR_DISK_LAYOUT_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_LAYOUT_NON_BASIC_BETWEEN_BASIC_PARTITIONS:
                reason = "STATUS_VOLMGR_DISK_LAYOUT_NON_BASIC_BETWEEN_BASIC_PARTITIONS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_LAYOUT_NOT_CYLINDER_ALIGNED:
                reason = "STATUS_VOLMGR_DISK_LAYOUT_NOT_CYLINDER_ALIGNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_LAYOUT_PARTITIONS_TOO_SMALL:
                reason = "STATUS_VOLMGR_DISK_LAYOUT_PARTITIONS_TOO_SMALL";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_LAYOUT_PRIMARY_BETWEEN_LOGICAL_PARTITIONS:
                reason = "STATUS_VOLMGR_DISK_LAYOUT_PRIMARY_BETWEEN_LOGICAL_PARTITIONS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_LAYOUT_TOO_MANY_PARTITIONS:
                reason = "STATUS_VOLMGR_DISK_LAYOUT_TOO_MANY_PARTITIONS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_MISSING:
                reason = "STATUS_VOLMGR_DISK_MISSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_NOT_EMPTY:
                reason = "STATUS_VOLMGR_DISK_NOT_EMPTY";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_NOT_ENOUGH_SPACE:
                reason = "STATUS_VOLMGR_DISK_NOT_ENOUGH_SPACE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_REVECTORING_FAILED:
                reason = "STATUS_VOLMGR_DISK_REVECTORING_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_SECTOR_SIZE_INVALID:
                reason = "STATUS_VOLMGR_DISK_SECTOR_SIZE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_SET_NOT_CONTAINED:
                reason = "STATUS_VOLMGR_DISK_SET_NOT_CONTAINED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_MEMBERS:
                reason = "STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_MEMBERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_PLEXES:
                reason = "STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_PLEXES";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DYNAMIC_DISK_NOT_SUPPORTED:
                reason = "STATUS_VOLMGR_DYNAMIC_DISK_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_EXTENT_ALREADY_USED:
                reason = "STATUS_VOLMGR_EXTENT_ALREADY_USED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_EXTENT_NOT_CONTIGUOUS:
                reason = "STATUS_VOLMGR_EXTENT_NOT_CONTIGUOUS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_EXTENT_NOT_IN_PUBLIC_REGION:
                reason = "STATUS_VOLMGR_EXTENT_NOT_IN_PUBLIC_REGION";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_EXTENT_NOT_SECTOR_ALIGNED:
                reason = "STATUS_VOLMGR_EXTENT_NOT_SECTOR_ALIGNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_EXTENT_OVERLAPS_EBR_PARTITION:
                reason = "STATUS_VOLMGR_EXTENT_OVERLAPS_EBR_PARTITION";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_EXTENT_VOLUME_LENGTHS_DO_NOT_MATCH:
                reason = "STATUS_VOLMGR_EXTENT_VOLUME_LENGTHS_DO_NOT_MATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_FAULT_TOLERANT_NOT_SUPPORTED:
                reason = "STATUS_VOLMGR_FAULT_TOLERANT_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_INTERLEAVE_LENGTH_INVALID:
                reason = "STATUS_VOLMGR_INTERLEAVE_LENGTH_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_MAXIMUM_REGISTERED_USERS:
                reason = "STATUS_VOLMGR_MAXIMUM_REGISTERED_USERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_MEMBER_IN_SYNC:
                reason = "STATUS_VOLMGR_MEMBER_IN_SYNC";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_MEMBER_INDEX_DUPLICATE:
                reason = "STATUS_VOLMGR_MEMBER_INDEX_DUPLICATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_MEMBER_INDEX_INVALID:
                reason = "STATUS_VOLMGR_MEMBER_INDEX_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_MEMBER_MISSING:
                reason = "STATUS_VOLMGR_MEMBER_MISSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_MEMBER_NOT_DETACHED:
                reason = "STATUS_VOLMGR_MEMBER_NOT_DETACHED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_MEMBER_REGENERATING:
                reason = "STATUS_VOLMGR_MEMBER_REGENERATING";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_ALL_DISKS_FAILED:
                reason = "STATUS_VOLMGR_ALL_DISKS_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NO_REGISTERED_USERS:
                reason = "STATUS_VOLMGR_NO_REGISTERED_USERS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NO_SUCH_USER:
                reason = "STATUS_VOLMGR_NO_SUCH_USER";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NOTIFICATION_RESET:
                reason = "STATUS_VOLMGR_NOTIFICATION_RESET";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NUMBER_OF_MEMBERS_INVALID:
                reason = "STATUS_VOLMGR_NUMBER_OF_MEMBERS_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NUMBER_OF_PLEXES_INVALID:
                reason = "STATUS_VOLMGR_NUMBER_OF_PLEXES_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_DUPLICATE:
                reason = "STATUS_VOLMGR_PACK_DUPLICATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_ID_INVALID:
                reason = "STATUS_VOLMGR_PACK_ID_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_INVALID:
                reason = "STATUS_VOLMGR_PACK_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_NAME_INVALID:
                reason = "STATUS_VOLMGR_PACK_NAME_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_OFFLINE:
                reason = "STATUS_VOLMGR_PACK_OFFLINE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_HAS_QUORUM:
                reason = "STATUS_VOLMGR_PACK_HAS_QUORUM";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_WITHOUT_QUORUM:
                reason = "STATUS_VOLMGR_PACK_WITHOUT_QUORUM";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PARTITION_STYLE_INVALID:
                reason = "STATUS_VOLMGR_PARTITION_STYLE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PARTITION_UPDATE_FAILED:
                reason = "STATUS_VOLMGR_PARTITION_UPDATE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_IN_SYNC:
                reason = "STATUS_VOLMGR_PLEX_IN_SYNC";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_INDEX_DUPLICATE:
                reason = "STATUS_VOLMGR_PLEX_INDEX_DUPLICATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_INDEX_INVALID:
                reason = "STATUS_VOLMGR_PLEX_INDEX_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_LAST_ACTIVE:
                reason = "STATUS_VOLMGR_PLEX_LAST_ACTIVE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_MISSING:
                reason = "STATUS_VOLMGR_PLEX_MISSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_REGENERATING:
                reason = "STATUS_VOLMGR_PLEX_REGENERATING";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_TYPE_INVALID:
                reason = "STATUS_VOLMGR_PLEX_TYPE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_NOT_RAID5:
                reason = "STATUS_VOLMGR_PLEX_NOT_RAID5";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_NOT_SIMPLE:
                reason = "STATUS_VOLMGR_PLEX_NOT_SIMPLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_STRUCTURE_SIZE_INVALID:
                reason = "STATUS_VOLMGR_STRUCTURE_SIZE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_TOO_MANY_NOTIFICATION_REQUESTS:
                reason = "STATUS_VOLMGR_TOO_MANY_NOTIFICATION_REQUESTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_TRANSACTION_IN_PROGRESS:
                reason = "STATUS_VOLMGR_TRANSACTION_IN_PROGRESS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_UNEXPECTED_DISK_LAYOUT_CHANGE:
                reason = "STATUS_VOLMGR_UNEXPECTED_DISK_LAYOUT_CHANGE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_VOLUME_CONTAINS_MISSING_DISK:
                reason = "STATUS_VOLMGR_VOLUME_CONTAINS_MISSING_DISK";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_VOLUME_ID_INVALID:
                reason = "STATUS_VOLMGR_VOLUME_ID_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_VOLUME_LENGTH_INVALID:
                reason = "STATUS_VOLMGR_VOLUME_LENGTH_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_VOLUME_LENGTH_NOT_SECTOR_SIZE_MULTIPLE:
                reason = "STATUS_VOLMGR_VOLUME_LENGTH_NOT_SECTOR_SIZE_MULTIPLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_VOLUME_NOT_MIRRORED:
                reason = "STATUS_VOLMGR_VOLUME_NOT_MIRRORED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_VOLUME_NOT_RETAINED:
                reason = "STATUS_VOLMGR_VOLUME_NOT_RETAINED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_VOLUME_OFFLINE:
                reason = "STATUS_VOLMGR_VOLUME_OFFLINE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_VOLUME_RETAINED:
                reason = "STATUS_VOLMGR_VOLUME_RETAINED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NUMBER_OF_EXTENTS_INVALID:
                reason = "STATUS_VOLMGR_NUMBER_OF_EXTENTS_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_DIFFERENT_SECTOR_SIZE:
                reason = "STATUS_VOLMGR_DIFFERENT_SECTOR_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_BAD_BOOT_DISK:
                reason = "STATUS_VOLMGR_BAD_BOOT_DISK";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_CONFIG_OFFLINE:
                reason = "STATUS_VOLMGR_PACK_CONFIG_OFFLINE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_CONFIG_ONLINE:
                reason = "STATUS_VOLMGR_PACK_CONFIG_ONLINE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NOT_PRIMARY_PACK:
                reason = "STATUS_VOLMGR_NOT_PRIMARY_PACK";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PACK_LOG_UPDATE_FAILED:
                reason = "STATUS_VOLMGR_PACK_LOG_UPDATE_FAILED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NUMBER_OF_DISKS_IN_PLEX_INVALID:
                reason = "STATUS_VOLMGR_NUMBER_OF_DISKS_IN_PLEX_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NUMBER_OF_DISKS_IN_MEMBER_INVALID:
                reason = "STATUS_VOLMGR_NUMBER_OF_DISKS_IN_MEMBER_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_VOLUME_MIRRORED:
                reason = "STATUS_VOLMGR_VOLUME_MIRRORED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PLEX_NOT_SIMPLE_SPANNED:
                reason = "STATUS_VOLMGR_PLEX_NOT_SIMPLE_SPANNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NO_VALID_LOG_COPIES:
                reason = "STATUS_VOLMGR_NO_VALID_LOG_COPIES";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_PRIMARY_PACK_PRESENT:
                reason = "STATUS_VOLMGR_PRIMARY_PACK_PRESENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_NUMBER_OF_DISKS_INVALID:
                reason = "STATUS_VOLMGR_NUMBER_OF_DISKS_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_MIRROR_NOT_SUPPORTED:
                reason = "STATUS_VOLMGR_MIRROR_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLMGR_RAID5_NOT_SUPPORTED:
                reason = "STATUS_VOLMGR_RAID5_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BCD_TOO_MANY_ELEMENTS:
                reason = "STATUS_BCD_TOO_MANY_ELEMENTS";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_DRIVE_FOOTER_MISSING:
                reason = "STATUS_VHD_DRIVE_FOOTER_MISSING";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_DRIVE_FOOTER_CHECKSUM_MISMATCH:
                reason = "STATUS_VHD_DRIVE_FOOTER_CHECKSUM_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_DRIVE_FOOTER_CORRUPT:
                reason = "STATUS_VHD_DRIVE_FOOTER_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_FORMAT_UNKNOWN:
                reason = "STATUS_VHD_FORMAT_UNKNOWN";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_FORMAT_UNSUPPORTED_VERSION:
                reason = "STATUS_VHD_FORMAT_UNSUPPORTED_VERSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_SPARSE_HEADER_CHECKSUM_MISMATCH:
                reason = "STATUS_VHD_SPARSE_HEADER_CHECKSUM_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_SPARSE_HEADER_UNSUPPORTED_VERSION:
                reason = "STATUS_VHD_SPARSE_HEADER_UNSUPPORTED_VERSION";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_SPARSE_HEADER_CORRUPT:
                reason = "STATUS_VHD_SPARSE_HEADER_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_BLOCK_ALLOCATION_FAILURE:
                reason = "STATUS_VHD_BLOCK_ALLOCATION_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_BLOCK_ALLOCATION_TABLE_CORRUPT:
                reason = "STATUS_VHD_BLOCK_ALLOCATION_TABLE_CORRUPT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_INVALID_BLOCK_SIZE:
                reason = "STATUS_VHD_INVALID_BLOCK_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_BITMAP_MISMATCH:
                reason = "STATUS_VHD_BITMAP_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_PARENT_VHD_NOT_FOUND:
                reason = "STATUS_VHD_PARENT_VHD_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_CHILD_PARENT_ID_MISMATCH:
                reason = "STATUS_VHD_CHILD_PARENT_ID_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_CHILD_PARENT_TIMESTAMP_MISMATCH:
                reason = "STATUS_VHD_CHILD_PARENT_TIMESTAMP_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_METADATA_READ_FAILURE:
                reason = "STATUS_VHD_METADATA_READ_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_METADATA_WRITE_FAILURE:
                reason = "STATUS_VHD_METADATA_WRITE_FAILURE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_INVALID_SIZE:
                reason = "STATUS_VHD_INVALID_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_INVALID_FILE_SIZE:
                reason = "STATUS_VHD_INVALID_FILE_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIRTDISK_PROVIDER_NOT_FOUND:
                reason = "STATUS_VIRTDISK_PROVIDER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIRTDISK_NOT_VIRTUAL_DISK:
                reason = "STATUS_VIRTDISK_NOT_VIRTUAL_DISK";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_PARENT_VHD_ACCESS_DENIED:
                reason = "STATUS_VHD_PARENT_VHD_ACCESS_DENIED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_CHILD_PARENT_SIZE_MISMATCH:
                reason = "STATUS_VHD_CHILD_PARENT_SIZE_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED:
                reason = "STATUS_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT:
                reason = "STATUS_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIRTUAL_DISK_LIMITATION:
                reason = "STATUS_VIRTUAL_DISK_LIMITATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_INVALID_TYPE:
                reason = "STATUS_VHD_INVALID_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_INVALID_STATE:
                reason = "STATUS_VHD_INVALID_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIRTDISK_UNSUPPORTED_DISK_SECTOR_SIZE:
                reason = "STATUS_VIRTDISK_UNSUPPORTED_DISK_SECTOR_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIRTDISK_DISK_ALREADY_OWNED:
                reason = "STATUS_VIRTDISK_DISK_ALREADY_OWNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_VIRTDISK_DISK_ONLINE_AND_WRITABLE:
                reason = "STATUS_VIRTDISK_DISK_ONLINE_AND_WRITABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTLOG_TRACKING_NOT_INITIALIZED:
                reason = "STATUS_CTLOG_TRACKING_NOT_INITIALIZED";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTLOG_LOGFILE_SIZE_EXCEEDED_MAXSIZE:
                reason = "STATUS_CTLOG_LOGFILE_SIZE_EXCEEDED_MAXSIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTLOG_VHD_CHANGED_OFFLINE:
                reason = "STATUS_CTLOG_VHD_CHANGED_OFFLINE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTLOG_INVALID_TRACKING_STATE:
                reason = "STATUS_CTLOG_INVALID_TRACKING_STATE";
                break;
            case MD_NTSTATUS_WIN_STATUS_CTLOG_INCONSISTENT_TRACKING_FILE:
                reason = "STATUS_CTLOG_INCONSISTENT_TRACKING_FILE";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_METADATA_FULL:
                reason = "STATUS_VHD_METADATA_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_RKF_KEY_NOT_FOUND:
                reason = "STATUS_RKF_KEY_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_RKF_DUPLICATE_KEY:
                reason = "STATUS_RKF_DUPLICATE_KEY";
                break;
            case MD_NTSTATUS_WIN_STATUS_RKF_BLOB_FULL:
                reason = "STATUS_RKF_BLOB_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_RKF_STORE_FULL:
                reason = "STATUS_RKF_STORE_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_RKF_FILE_BLOCKED:
                reason = "STATUS_RKF_FILE_BLOCKED";
                break;
            case MD_NTSTATUS_WIN_STATUS_RKF_ACTIVE_KEY:
                reason = "STATUS_RKF_ACTIVE_KEY";
                break;
            case MD_NTSTATUS_WIN_STATUS_RDBSS_RESTART_OPERATION:
                reason = "STATUS_RDBSS_RESTART_OPERATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_RDBSS_CONTINUE_OPERATION:
                reason = "STATUS_RDBSS_CONTINUE_OPERATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_RDBSS_POST_OPERATION:
                reason = "STATUS_RDBSS_POST_OPERATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_INVALID_HANDLE:
                reason = "STATUS_BTH_ATT_INVALID_HANDLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_READ_NOT_PERMITTED:
                reason = "STATUS_BTH_ATT_READ_NOT_PERMITTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_WRITE_NOT_PERMITTED:
                reason = "STATUS_BTH_ATT_WRITE_NOT_PERMITTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_INVALID_PDU:
                reason = "STATUS_BTH_ATT_INVALID_PDU";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_INSUFFICIENT_AUTHENTICATION:
                reason = "STATUS_BTH_ATT_INSUFFICIENT_AUTHENTICATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_REQUEST_NOT_SUPPORTED:
                reason = "STATUS_BTH_ATT_REQUEST_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_INVALID_OFFSET:
                reason = "STATUS_BTH_ATT_INVALID_OFFSET";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_INSUFFICIENT_AUTHORIZATION:
                reason = "STATUS_BTH_ATT_INSUFFICIENT_AUTHORIZATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_PREPARE_QUEUE_FULL:
                reason = "STATUS_BTH_ATT_PREPARE_QUEUE_FULL";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_ATTRIBUTE_NOT_FOUND:
                reason = "STATUS_BTH_ATT_ATTRIBUTE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_ATTRIBUTE_NOT_LONG:
                reason = "STATUS_BTH_ATT_ATTRIBUTE_NOT_LONG";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE:
                reason = "STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH:
                reason = "STATUS_BTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_UNLIKELY:
                reason = "STATUS_BTH_ATT_UNLIKELY";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION:
                reason = "STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_UNSUPPORTED_GROUP_TYPE:
                reason = "STATUS_BTH_ATT_UNSUPPORTED_GROUP_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_INSUFFICIENT_RESOURCES:
                reason = "STATUS_BTH_ATT_INSUFFICIENT_RESOURCES";
                break;
            case MD_NTSTATUS_WIN_STATUS_BTH_ATT_UNKNOWN_ERROR:
                reason = "STATUS_BTH_ATT_UNKNOWN_ERROR";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECUREBOOT_ROLLBACK_DETECTED:
                reason = "STATUS_SECUREBOOT_ROLLBACK_DETECTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECUREBOOT_POLICY_VIOLATION:
                reason = "STATUS_SECUREBOOT_POLICY_VIOLATION";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECUREBOOT_INVALID_POLICY:
                reason = "STATUS_SECUREBOOT_INVALID_POLICY";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND:
                reason = "STATUS_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECUREBOOT_POLICY_NOT_SIGNED:
                reason = "STATUS_SECUREBOOT_POLICY_NOT_SIGNED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SECUREBOOT_FILE_REPLACED:
                reason = "STATUS_SECUREBOOT_FILE_REPLACED";
                break;
            case MD_NTSTATUS_WIN_STATUS_AUDIO_ENGINE_NODE_NOT_FOUND:
                reason = "STATUS_AUDIO_ENGINE_NODE_NOT_FOUND";
                break;
            case MD_NTSTATUS_WIN_STATUS_HDAUDIO_EMPTY_CONNECTION_LIST:
                reason = "STATUS_HDAUDIO_EMPTY_CONNECTION_LIST";
                break;
            case MD_NTSTATUS_WIN_STATUS_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED:
                reason = "STATUS_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HDAUDIO_NO_LOGICAL_DEVICES_CREATED:
                reason = "STATUS_HDAUDIO_NO_LOGICAL_DEVICES_CREATED";
                break;
            case MD_NTSTATUS_WIN_STATUS_HDAUDIO_NULL_LINKED_LIST_ENTRY:
                reason = "STATUS_HDAUDIO_NULL_LINKED_LIST_ENTRY";
                break;
            case MD_NTSTATUS_WIN_STATUS_VOLSNAP_BOOTFILE_NOT_VALID:
                reason = "STATUS_VOLSNAP_BOOTFILE_NOT_VALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_IO_PREEMPTED:
                reason = "STATUS_IO_PREEMPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_ERROR_STORED:
                reason = "STATUS_SVHDX_ERROR_STORED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_ERROR_NOT_AVAILABLE:
                reason = "STATUS_SVHDX_ERROR_NOT_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_UNIT_ATTENTION_AVAILABLE:
                reason = "STATUS_SVHDX_UNIT_ATTENTION_AVAILABLE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED:
                reason = "STATUS_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED:
                reason = "STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED:
                reason = "STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED:
                reason = "STATUS_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED:
                reason = "STATUS_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_RESERVATION_CONFLICT:
                reason = "STATUS_SVHDX_RESERVATION_CONFLICT";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_WRONG_FILE_TYPE:
                reason = "STATUS_SVHDX_WRONG_FILE_TYPE";
                break;
            case MD_NTSTATUS_WIN_STATUS_SVHDX_VERSION_MISMATCH:
                reason = "STATUS_SVHDX_VERSION_MISMATCH";
                break;
            case MD_NTSTATUS_WIN_STATUS_VHD_SHARED:
                reason = "STATUS_VHD_SHARED";
                break;
            case MD_NTSTATUS_WIN_STATUS_SPACES_RESILIENCY_TYPE_INVALID:
                reason = "STATUS_SPACES_RESILIENCY_TYPE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_SPACES_DRIVE_SECTOR_SIZE_INVALID:
                reason = "STATUS_SPACES_DRIVE_SECTOR_SIZE_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_SPACES_INTERLEAVE_LENGTH_INVALID:
                reason = "STATUS_SPACES_INTERLEAVE_LENGTH_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_SPACES_NUMBER_OF_COLUMNS_INVALID:
                reason = "STATUS_SPACES_NUMBER_OF_COLUMNS_INVALID";
                break;
            case MD_NTSTATUS_WIN_STATUS_SPACES_NOT_ENOUGH_DRIVES:
                reason = "STATUS_SPACES_NOT_ENOUGH_DRIVES";
                break;
            default: {
                char reason_string[11];
                snprintf(reason_string, sizeof(reason_string), "0x%08x", ntstatus);
                reason = reason_string;
                break;
            }
        }
        return reason;
    }

}  // namespace google_breakpad
