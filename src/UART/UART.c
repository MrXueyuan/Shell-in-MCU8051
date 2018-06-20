/***************************************************************************** 
 * File name:       UART.c
 * Description:     串口函数文件，用于初始化串口及对串口函数的调用。
 * Author:          Mr.Xueyuan
 * Version:         v0.0.01-Frame
 * Date:            2018/6/18
 * History:         git
 *****************************************************************************/ 

/* 链接头文件 */
#include "..\..\inc\UART\UART.h"
#include "..\..\inc\Main\stdafx.h"


/* 变量定义 */
bit Busy;

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
        SCON = 0xda;                //9位可变波特率,校验位初始为1
    #elif (PARITYBIT == SPACE_PARITY)
        SCON = 0xd2;                //9位可变波特率,校验位初始为0
    #endif

	AUXR |= 0x04;		            //独立波特率发生器时钟为Fosc,即1T
	BRT = 255-INT(FOSC/BAUD/32);	//设定独立波特率发生器重装值
	AUXR |= 0x01;		            //串口1选择独立波特率发生器为波特率发生器
	AUXR |= 0x10;		            //启动独立波特率发生器
}


void SendData(char dat)
{
    while (Busy);               //等待前面的数据发送完成
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
    Busy = 1;
    SBUF = ACC;                 //写数据到UART数据寄存器
}

