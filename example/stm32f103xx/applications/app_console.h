// Copyright (c) 2026 Daven <804781317@qq.com>
// SPDX-License-Identifier: MIT
#ifndef _APP_CONSOLE_H_
#define _APP_CONSOLE_H_

#include "htd_task.h"
#include "htd_console_process.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/


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


// @brief 控制台初始化
void app_console_init(void);
// @brief 刷新控制台数据
// @brief 等待RTT缓冲区数据发送完毕, 此函数会阻塞CPU，直到数据被读走或超时
int32_t app_console_tx_flush(uint32_t timeout_ms);


#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /* _APP_CONSOLE_H_ */

