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

/* �������ó�ʼ�� */
data bit Con_Flag = 0;    //����������־
xdata char Con_cache[80]; //����̨����
data u8 Con_C_cache = 0;  //����ָ̨�뻺��
data u8 count_Stime = 0;  //ʱ�����
xdata u32 SystemTime = 0; //ϵͳʱ��

/*************************************************
 * Function:        Init
 * Description:     ��Ƭ����ʼ������
 * Calls:           URATInit
 * Called By:       main
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/
void Init(void)
{
    UartInit(); //���ڳ�ʼ��
    EA = 1;     //�����ж�
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
int main(void)
{
    /* ��Ƭ����ʼ�� */
    Init();

    /* ����Shell���� */
    InitShell();

    /* ��ѭ�� */
    while (1)
    {
    } //while
}

/*************************************************
 * Function:        STime
 * Description:     ϵͳʱ�䶨ʱ��
 * Calls:           none
 * Called By:       STimeInit
 * Input:           none
 * Output:          SystemTime
 * Return:          void
 *************************************************/
void STime(void) interrupt 3 using 1
{
    TL1 = 0x00;            //��λ��ʱ��ֵ
    TH1 = 0x4C;            //��λ��ʱ��ֵ
    count_Stime++;         //ʱ���������
    if (count_Stime == 20) //ʱ�������λ
    {
        count_Stime = 0; //��λʱ�����
        SystemTime += 1; //ϵͳʱ���ʱ
    }
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
void Uart_Service() interrupt 4 using 1
{
    if (RI)
    {
        ES = 0;           //��ͣ�����ж�  ͣ����
        if (SBUF != 0x0d) //�жϻس�
        {
            Con_Flag = 1;    //����������־ΪTrue
            Con_C_cache = 0; //ָ������
        }
        else
            Con_cache[Con_C_cache++] = SBUF; //���������뻺��������ֵѹ�뻺����ָ��
        RI = 0;                              //���RIλ
        ES = 1;                              //�򿪴����ж�
    }
    if (TI)
    {
        TI = 0;   //���TIλ
        Busy = 0; //��æ��־
    }
}
