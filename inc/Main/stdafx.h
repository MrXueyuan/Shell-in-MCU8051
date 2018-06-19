/***************************************************************************** 
 * File name:       stdafx.h
 * Description:     主调用头文件，在此头文件中调用其他头文件，并定义部分可更改常量。
 * Author:          Mr.Xueyuan
 * Version:         v0.0.01-Frame
 * Date:            2018/6/18
 * History:         none
 *****************************************************************************/ 

#ifndef STDAFX_H_
    #define STDAFX_H_

    /* 头文件调用 */
    #include "STC12.h"          //单片机头文件
    #include <intrins.h>        //单片机指令头文件
    #include "..\Shell\core.h"  //Shell内核头文件调用
    #include "..\UART\UART.h"   //串口头文件调用

    /* 定义校验位 */
    #define PARITYBIT NONE_PARITY

#endif /* STDAFX_H_ */
