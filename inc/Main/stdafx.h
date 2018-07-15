/***************************************************************************** 
 * File name:       stdafx.h
 * Description:     主调用头文件，在此头文件中调用其他头文件，并定义部分可更改常量。
 * Author:          Mr.Xueyuan
 * Version:         v0.0.02-Frame
 * Date:            2018/6/20
 * History:         git
 *****************************************************************************/

#ifndef STDAFX_H_
#define STDAFX_H_

/* 定义使用的芯片 */
#define STC12 1
#define STC15 2
#define IC_SET STC12 //STC12 or STC15

/* 频率调整 */
#define FOSC 11059200L //系统频率
#define BAUD 9600      //串口波特率

/* 头文件调用 */
#if (IC_SET == STC12) //芯片头文件设置
#include "STC12.h"
#elif (IC_SET == STC15)
#include "STC15.h"
#endif
#include <intrins.h>       //单片机指令头文件
#include "..\Shell\core.h" //Shell内核头文件调用
#include "..\UART\UART.h"  //串口头文件调用

/* 变量定义 */
extern data bit Con_Flag;        //输入待处理标志
extern xdata char Con_cache[80]; //控制台缓存
extern data u8 Con_C_cache;      //控制台指针缓存
extern data u8 count_Stime;      //时间计数
extern xdata u32 SystemTime;     //系统时间
extern bit Busy;                 //串口忙标志

#endif /* STDAFX_H_ */
