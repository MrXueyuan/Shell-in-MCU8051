/***************************************************************************** 
 * File name:       UART.c
 * Description:     串口函数文件，用于初始化串口及对串口函数的调用。
 * Author:          Mr.Xueyuan
 * Version:         v0.0.03-Frame
 * Date:            2018/7/1
 * History:         git
 *****************************************************************************/ 

/* 链接头文件 */
#include "..\..\inc\Main\stdafx.h"



/*************************************************
 * Function:        UartInit
 * Description:     串口初始化
                    独立波特率发生器，串口1
 * Calls:           none
 * Called By:       Init
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/ 
void UartInit(void)	
{
	PCON &= 0x7F;		            //波特率不倍速

    /* 波特率及校验位设置 */
    #if (PARITYBIT == NONE_PARITY)
        SCON = 0x50;                //8位可变波特率
    #elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
        SCON = 0xDA;                //9位可变波特率,校验位初始为1
    #elif (PARITYBIT == SPACE_PARITY)
        SCON = 0xD2;                //9位可变波特率,校验位初始为0
    #endif

	AUXR |= 0x04;		            //独立波特率发生器时钟为Fosc,即1T
	BRT = 255-INT(FOSC/BAUD/32);	//设定独立波特率发生器重装值
	AUXR |= 0x01;		            //串口1选择独立波特率发生器为波特率发生器
	AUXR |= 0x10;		            //启动独立波特率发生器
    ES = 1;                         //启动串口1中断
}

/*************************************************
 * Function:        SendData
 * Description:     串口发送单字节
 * Calls:           none
 * Called By:       main,SendString
 * Input:           Char:16位数.串口发送数据
 * Output:          void
 * Return:          void
 *************************************************/ 
void SendData(char dat)
{
    while (Busy);               //等待前面的数据发送完成

    #if (PARITYBI != NONE_PARITY)
        ACC = dat;                  //获取校验位P (PSW.0)
        if (P)                      //根据P来设置校验位
        {
            #if (PARITYBIT == ODD_PARITY)
                TB8 = 0;                //设置校验位为0
            #elif (PARITYBIT == EVEN_PARITY)
                TB8 = 1;                //设置校验位为1
            #endif
        }
        else
        {
            #if (PARITYBIT == ODD_PARITY)
                TB8 = 1;                //设置校验位为1
            #elif (PARITYBIT == EVEN_PARITY)
                TB8 = 0;                //设置校验位为0
            #endif
        }
    #endif

    Busy = 1;

    #if (PARITYBI != NONE_PARITY)
        SBUF = ACC;                 //将已经进行校验的9位数据写到UART数据寄存器
    #else 
        SBUF = dat;                 //写8位数据到UART数据寄存器
    #endif
}

/*************************************************
 * Function:        SendString
 * Description:     串口发送字符串
 * Calls:           SendData
 * Called By:       main
 * Input:           Char:字符串指针
 * Output:          void
 * Return:          void
 *************************************************/ 
void SendString(char *s)
{
    while (*s)                  //检测字符串结束标志
    {
        SendData(*s++);         //发送当前字符
    }
}
