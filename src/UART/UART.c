/***************************************************************************** 
 * File name:       UART.c
 * Description:     ���ں����ļ������ڳ�ʼ�����ڼ��Դ��ں����ĵ��á�
 * Author:          Mr.Xueyuan
 * Version:         v0.0.03-Frame
 * Date:            2018/7/1
 * History:         git
 *****************************************************************************/ 

/* ����ͷ�ļ� */
#include "..\..\inc\Main\stdafx.h"



/*************************************************
 * Function:        UartInit
 * Description:     ���ڳ�ʼ��
                    ���������ʷ�����������1
 * Calls:           none
 * Called By:       Init
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/ 
void UartInit(void)	
{
	PCON &= 0x7F;		            //�����ʲ�����

    /* �����ʼ�У��λ���� */
    #if (PARITYBIT == NONE_PARITY)
        SCON = 0x50;                //8λ�ɱ䲨����
    #elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
        SCON = 0xDA;                //9λ�ɱ䲨����,У��λ��ʼΪ1
    #elif (PARITYBIT == SPACE_PARITY)
        SCON = 0xD2;                //9λ�ɱ䲨����,У��λ��ʼΪ0
    #endif

	AUXR |= 0x04;		            //���������ʷ�����ʱ��ΪFosc,��1T
	BRT = 255-INT(FOSC/BAUD/32);	//�趨���������ʷ�������װֵ
	AUXR |= 0x01;		            //����1ѡ����������ʷ�����Ϊ�����ʷ�����
	AUXR |= 0x10;		            //�������������ʷ�����
    ES = 1;                         //��������1�ж�
}

/*************************************************
 * Function:        SendData
 * Description:     ���ڷ��͵��ֽ�
 * Calls:           none
 * Called By:       main,SendString
 * Input:           Char:16λ��.���ڷ�������
 * Output:          void
 * Return:          void
 *************************************************/ 
void SendData(char dat)
{
    while (Busy);               //�ȴ�ǰ������ݷ������

    #if (PARITYBI != NONE_PARITY)
        ACC = dat;                  //��ȡУ��λP (PSW.0)
        if (P)                      //����P������У��λ
        {
            #if (PARITYBIT == ODD_PARITY)
                TB8 = 0;                //����У��λΪ0
            #elif (PARITYBIT == EVEN_PARITY)
                TB8 = 1;                //����У��λΪ1
            #endif
        }
        else
        {
            #if (PARITYBIT == ODD_PARITY)
                TB8 = 1;                //����У��λΪ1
            #elif (PARITYBIT == EVEN_PARITY)
                TB8 = 0;                //����У��λΪ0
            #endif
        }
    #endif

    Busy = 1;

    #if (PARITYBI != NONE_PARITY)
        SBUF = ACC;                 //���Ѿ�����У���9λ����д��UART���ݼĴ���
    #else 
        SBUF = dat;                 //д8λ���ݵ�UART���ݼĴ���
    #endif
}

/*************************************************
 * Function:        SendString
 * Description:     ���ڷ����ַ���
 * Calls:           SendData
 * Called By:       main
 * Input:           Char:�ַ���ָ��
 * Output:          void
 * Return:          void
 *************************************************/ 
void SendString(char *s)
{
    while (*s)                  //����ַ���������־
    {
        SendData(*s++);         //���͵�ǰ�ַ�
    }
}
