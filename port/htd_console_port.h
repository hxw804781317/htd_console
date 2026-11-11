// Copyright (c) 2026 Daven <804781317@qq.com>
// SPDX-License-Identifier: MIT
#ifndef _HTD_CONSOLE_PORT_H_
#define _HTD_CONSOLE_PORT_H_

#include "htd_task.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/


//////////////////////////////////////////////////////////////////////
// 是否支持命令输入
//#define HTD_CONSOLE_SUPPORT_CMD                 1
// 是否支持命令存储
//define HTD_CONSOLE_SUPPORT_CMD_HISTORY          1

// 命令行长度(可输入字符长度)
#ifndef HTD_CONSOLE_CMD_SIZE
    #define HTD_CONSOLE_CMD_SIZE                48
#endif
// 保存的命令行行数
#ifndef HTD_CONSOLE_HISTORY_LINES
    #define HTD_CONSOLE_HISTORY_LINES           5
#endif
// 命令行参数个数
#ifndef HTD_CONSOLE_ARG_MAX
    #define HTD_CONSOLE_ARG_MAX                 8
#endif
#ifndef HTD_CONSOLE_SERIAL_NAME
    #define HTD_CONSOLE_SERIAL_NAME             "segger_rtt"
#endif
#ifndef HTD_CONSOLE_SERIAL_TX_PINNUM
    #define HTD_CONSOLE_SERIAL_TX_PINNUM        0x09
#endif
#ifndef HTD_CONSOLE_SERIAL_RX_PINNUM
    #define HTD_CONSOLE_SERIAL_RX_PINNUM        0x0a
#endif
#ifndef HTD_CONSOLE_SERIAL_BAUDRATE
    #define HTD_CONSOLE_SERIAL_BAUDRATE         1000000
#endif



//////////////////////////////////////////////////////////////////////
#ifndef ASSERT
    #define ASSERT(a)                           
#endif
#ifndef MEMSET
    #define MEMSET(ptr, v, n)                   htd_memset(ptr, v, n)
#endif
#ifndef MEMCPY
    #define MEMCPY(dst, src, n)                 htd_memcpy(dst, src, n)
#endif
#ifndef MALLOC
    #define MALLOC(size)                        htd_malloc(size)
#endif
#ifndef FREE
    #define FREE(p_ptr)                         htd_free(p_ptr)
#endif




//////////////////////////////////////////////////////////////////////
#ifndef CONCAT_2
    #define CONCAT_2_(p1, p2)                   p1##p2
    #define CONCAT_2(p1, p2)                    CONCAT_2_(p1, p2)
#endif
#ifndef STR
    #define STR(s)                              #s
#endif 
#ifndef STRINGIFY
    #define STRINGIFY(val)                      STR(val)
#endif 



//////////////////////////////////////////////////////////////////////
// @brief 初始化控制台(打开字符输出)
int32_t app_console_init(void);
// @brief 控制台开始接收数据
void app_console_read_start(void);
// @brief 去初始化控制台
int32_t app_console_uninit(void);
// @brief 刷新
// @return 返回0说明已经刷新完毕，返回大于0，表示还有多长数据要发送
int32_t app_console_tx_flush(uint32_t waite_timeout_ms);



#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*_HTD_CONSOLE_PORT_H_*/

