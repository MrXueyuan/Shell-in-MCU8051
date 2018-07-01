/***************************************************************************** 
 * File name:       main.c
 * Description:     �������ļ���������ʼ����������ں�����
 * Author:          Mr.Xueyuan
 * Version:         v0.0.03-Frame
 * Date:            2018/7/1
 * History:         git
 *****************************************************************************/ 

/* ������ͷ�ļ� */
#include "..\..\inc\Main\stdafx.h"



/*************************************************
 * Function:        Init
 * Description:     ��Ƭ����ʼ������
 * Calls:           URATInit
 * Called By:       main
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/ 
void Init (void) 
{
    UartInit();
}


/*************************************************
 * Function:        main
 * Description:     ������
 * Calls:           All
 * Called By:       none
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/ 
int main (void) 
{
    /* ��Ƭ����ʼ�� */
    Init();

    /* ����Shell���� */
    InitShell();

    /* ��ѭ�� */
    while (1) 
    {
        
    }   //while
}


/*************************************************
 * Function:        Uart_Service
 * Description:     ���ڷ������
 * Calls:           none
 * Called By:       UartInit
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/ 
void Uart_Service () interrupt 4 using 1
{
    if (RI)
    {
        RI = 0;                 //���RIλ
    }
    if (TI)
    {
        TI = 0;                 //���TIλ
        Busy = 0;               //��æ��־
    }
}
