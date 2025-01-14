//
// Created by dingjing on 1/14/25.
//

#ifndef lpb_TYPES_H
#define lpb_TYPES_H
#include "../3thrd/macros/macros.h"

C_BEGIN_EXTERN_C

typedef enum
{
    IPC_TYPE_NONE                           = 0,

    IPC_TYPE_NUM,
} RpcType;

/**
 * @brief 通信所使用的消息结构
 */
typedef struct __attribute__((packed)) _RpcMessage
{
    unsigned int        type;
    unsigned long       dataLen;
    char                data[];
} RpcMessage;

C_END_EXTERN_C
#endif // lpb_TYPES_H
