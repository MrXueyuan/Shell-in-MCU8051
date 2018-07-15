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

/* 变量调用初始化 */
data bit Con_Flag = 0;    //输入待处理标志
xdata char Con_cache[80]; //控制台缓存
data u8 Con_C_cache = 0;  //控制台指针缓存
data u8 count_Stime = 0;  //时间计数
xdata u32 SystemTime = 0; //系统时间

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
 * Function:        STime
 * Description:     系统时间定时器
 * Calls:           none
 * Called By:       STimeInit
 * Input:           none
 * Output:          SystemTime
 * Return:          void
 *************************************************/
void STime(void) interrupt 3 using 1
{
    TL1 = 0x00;            //复位定时初值
    TH1 = 0x4C;            //复位定时初值
    count_Stime++;         //时间计数递增
    if (count_Stime == 20) //时间计数置位
    {
        count_Stime = 0; //复位时间计数
        SystemTime += 1; //系统时间计时
    }
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
        ES = 0;           //暂停串口中断  停干扰
        if (SBUF != 0x0d) //判断回车
        {
            Con_Flag = 1;    //输入待处理标志为True
            Con_C_cache = 0; //指针置零
        }
        else
            Con_cache[Con_C_cache++] = SBUF; //将串口输入缓冲区的数值压入缓冲区指针
        RI = 0;                              //清除RI位
        ES = 1;                              //打开串口中断
    }
    if (TI)
    {
        TI = 0;   //清除TI位
        Busy = 0; //清忙标志
    }
}
