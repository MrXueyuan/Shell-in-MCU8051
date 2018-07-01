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
    #define STC12  1
    #define STC15  2
    #define IC_SET STC12        //STC12 or STC15

    /* 头文件调用 */
    #if (IC_SET == STC12)       //芯片头文件设置
        #include "STC12.h" 
    #elif (IC_SET == STC15)
        #include "STC15.h"
    #endif
    #include <intrins.h>        //单片机指令头文件
    #include "..\Shell\core.h"  //Shell内核头文件调用
    #include "..\UART\UART.h"   //串口头文件调用

    /* 定义UART校验位 */
    #define PARITYBIT NONE_PARITY

#endif /* STDAFX_H_ */
