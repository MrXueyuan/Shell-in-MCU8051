/***************************************************************************** 
 * File name:       core.c
 * Description:     shell内核函数，实现对其他shell工具的调用
 * Author:          Mr.Xueyuan
 * Version:         v0.0.03-Frame
 * Date:            2018/7/1
 * History:         git
 *****************************************************************************/

/* 链接头文件 */
#include "..\..\inc\Main\stdafx.h"

/* 变量调用 */

/* 显示文本 */
xdata char Boot_inf_UART[] = {
    "\r\n ...   ..."
    "\r\n"
    "\r\n UART init OK"}; //伪装代码

xdata char Boot_inf_sys[] = {
    "\r\n System Boot Now ..."}; //启动

xdata char Boot_inf_STime[] = {
    "\r\n System Time Boot Now ..."
    "\r\n STime init OK"}; //系统时钟初始化提示信息

xdata char Sys_inf_Head[] = {
    "\r\n User@STC12C5A60S2\t# "}; //默认提示信息

/*************************************************
 * Function:        InitShell
 * Description:     初始化Shell
 * Calls:           run
 * Called By:       main
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/
void InitShell(void)
{
    SendString(&Boot_inf_UART);
    SendString(&Boot_inf_sys);
    STimeInit();
    SendString(&Boot_inf_STime);
    SendString(&Sys_inf_Head);
    run();
}

/*************************************************
 * Function:        run
 * Description:     shell运行
 * Calls:           none
 * Called By:       main
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/
void run(void)
{
    if (Con_Flag == 1)
    {
        SendString(&Con_cache);
        Con_Flag = 0;
    }
}

/*************************************************
 * Function:        STimeInit
 * Description:     系统时间定时器初始化 (T1)
 * Calls:           none
 * Called By:       STimeInit
 * Input:           none
 * Output:          SystemTime
 * Return:          void
 *************************************************/
void STimeInit(void) //50毫秒@11.0592MHz
{
    AUXR &= 0xBF; //定时器时钟12T模式
    TMOD &= 0x0F; //设置定时器模式
    TMOD |= 0x10; //设置定时器模式
    TL1 = 0x00;   //设置定时初值
    TH1 = 0x4C;   //设置定时初值
    TF1 = 0;      //清除TF1标志
    TR1 = 1;      //定时器1开始计时
}
