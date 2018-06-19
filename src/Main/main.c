/***************************************************************************** 
 * File name:       main.c
 * Description:     �������ļ���������ʼ����������ں�����
 * Author:          Mr.Xueyuan
 * Version:         v0.0.01-Frame
 * Date:            2018/6/18
 * History:         none
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
    runShell();

    /* ��ѭ�� */
    while (1) 
    {
        
    }   //while
}
