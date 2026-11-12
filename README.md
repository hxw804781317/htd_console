# 1、介绍

htd_console 是一款开源的轻量级嵌入式控制台程序，方便开发者基于裸机系统和RTOS系统的开发和移植。资源占用低，集成方便，纯C语言开发，方便集合到各种MCU项目开发中，主要有以下几个功能。

## 1.1 下载方式

git clone https://github.com/hxw804781317/htd_console











# 2、使用方式

htd_console是面向函数的任务调度，将函数指针作为参数发送给任务调度器，任务调度器根据调用的先后关系进行执行。

## 2.1 编译选项

使用 Kconfig 配置选项，支持menuconfig配置，可查看目录下的 Kconfig，了解对应的配置选项。

## 2.1 系统对接

打开 port 文件，查看 htd_console_port.h 文件和 htd_console_port.c 文件，里面有详细说明。

## 2.3 开机调用





## 2.4 接口说明

详细阅读 htd_task_nos.h 和 htd_task_sch.h 两个文件。

## 2.5 样例工程

提供 example\stm32f103xx，开发板如下图所示：

![](C:\Users\Administrator\AppData\Roaming\marktext\images\11d96bdb94e2a3bda1549256253c7e2144f3c2c9.jpg)
