/***************************************************************************** 
 * File name:       core.c
 * Description:     shell�ں˺�����ʵ�ֶ�����shell���ߵĵ���
 * Author:          Mr.Xueyuan
 * Version:         v0.0.03-Frame
 * Date:            2018/7/1
 * History:         git
 *****************************************************************************/ 

/* ����ͷ�ļ� */
#include "..\..\inc\Main\stdafx.h"

xdata char Boot_inf [] = {"
    /r/n:) System Boot Now ...
    /r/n/tInit All
    /r/n/t. . .  . . .
    /r/n
    /r/n
    /r/nWelcome to use the Geek system��
"};


/*************************************************
 * Function:        InitShell
 * Description:     ��ʼ��Shell
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
