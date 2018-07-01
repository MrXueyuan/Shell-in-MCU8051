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

xdata char Boot_inf [] = {"
    /r/n:) System Boot Now ...
    /r/n/tInit All
    /r/n/t. . .  . . .
    /r/n
    /r/n
    /r/nWelcome to use the Geek system！
"};


/*************************************************
 * Function:        InitShell
 * Description:     初始化Shell
 * Calls:           Shell
 * Called By:       main
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/ 
void InitShell (void) 
{
    SendString (*Boot_inf);
}
