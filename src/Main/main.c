/***************************************************************************** 
 * File name:       main.c
 * Description:     主函数文件，包含初始化函数及入口函数。
 * Author:          Mr.Xueyuan
 * Version:         v0.0.03-Frame
 * Date:            2018/7/1
 * History:         git
 *****************************************************************************/

/* 主调用头文件 */
#include "..\..\inc\Main\stdafx.h"

/* 变量 */
u8  Con_C_cache = 0;        //控制台指针缓存

/*************************************************
 * Function:        Init
 * Description:     单片机初始化函数
 * Calls:           URATInit
 * Called By:       main
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/
void Init(void)
{
    UartInit(); //串口初始化
    EA = 1;     //打开总中断
}

/*************************************************
 * Function:        main
 * Description:     主函数
 * Calls:           All
 * Called By:       none
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/
int main(void)
{
    /* 单片机初始化 */
    Init();

    /* 运行Shell代码 */
    InitShell();

    /* 死循环 */
    while (1)
    {
    } //while
}

/*************************************************
 * Function:        Uart_Service
 * Description:     串口服务程序
 * Calls:           none
 * Called By:       UartInit
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/
void Uart_Service() interrupt 4 using 1
{
    if (RI)
    {
        ES=0;   //暂停串口中断
        if (SBUF!=0x0d) 
            Con_Flag = true;
        else
            Con_cache[Con_C_cache++] = SBUF;    //将串口输入缓冲区的数值压入缓冲区指针
        RI = 0; //清除RI位
        ES=1;   //打开串口中断
    }
    if (TI)
    {
        TI = 0;   //清除TI位
        Busy = 0; //清忙标志
    }
}
