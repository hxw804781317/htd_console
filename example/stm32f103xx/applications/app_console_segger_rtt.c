// Copyright (c) 2026 Daven <804781317@qq.com>
// SPDX-License-Identifier: MIT
#include "app_console.h"

#if defined(LIB_SEGGER_RTT_ENABLE)
#include "SEGGER_RTT.h"

// @brief 控制台写句柄
static int32_t app_console_write(const uint8_t* p_data, int32_t data_len)
{
    SEGGER_RTT_Write(0, p_data, data_len);
    return data_len;
}

// @brief 控制台轮询句柄
static void app_console_loop_handle(void* arg)
{
    // 读数据
    uint8_t data[64];
    uint32_t retry_count = 2;
    int32_t read_len = 0;
    do {
        read_len = SEGGER_RTT_Read(0, data, sizeof(data));
        if (read_len) {
            break;
        }
        retry_count--;
        if (retry_count == 0) {
            break;
        }
    } while (1);

    // 将读到的数据喂给控制台
    uint8_t* p_data = data;
    while (read_len--) {
        htd_console_process_loop(p_data[0]);
        p_data++;
    }
}

// @brief 控制台初始化
void app_console_init(void)
{
    // 初始化控制台
    int32_t ret = htd_console_process_init(app_console_write);
    if (ret != 0) {
        app_console_write((const uint8_t*)"htd console process init failed.", 32);
    } else {
        app_console_write((const uint8_t*)"htd console process init success.", 33);
        htd_console_print("htd console init finish: %s\r\n", HTD_CONSOLE_SERIAL_NAME);
    }
    // 轮询给控制台喂数据
    htd_task_load_timer_function(true, 50, app_console_loop_handle, NULL);
}

// @brief 刷新控制台数据
// @brief 等待RTT缓冲区数据发送完毕, 此函数会阻塞CPU，直到数据被读走或超时
int32_t app_console_tx_flush(uint32_t timeout_ms)
{
    uint32_t buff_len;
    uint32_t start_ms = htd_time_ms_get();
    while (1) {
        buff_len = SEGGER_RTT_WriteBuffLen_Get(0);
        if (buff_len == 0) {
            return 0;
        }
        if (htd_time_ms_diff(htd_time_ms_get(), start_ms) > timeout_ms) {
            //print_warning("tx flush timeout. buff_len=%d", buff_len);
            break;
        }
        htd_delay_us(1);
    }
    return (int32_t)buff_len;
}
#endif

