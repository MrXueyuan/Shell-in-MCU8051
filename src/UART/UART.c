/***************************************************************************** 
 * File name:       UART.c
 * Description:     ���ں����ļ������ڳ�ʼ�����ڼ��Դ��ں����ĵ��á�
 * Author:          Mr.Xueyuan
 * Version:         v0.0.01-Frame
 * Date:            2018/6/18
 * History:         none
 *****************************************************************************/ 

/* ����ͷ�ļ� */
#include "..\..\inc\UART\UART.h"
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
        SCON = 0xda;                //9λ�ɱ䲨����,У��λ��ʼΪ1
    #elif (PARITYBIT == SPACE_PARITY)
        SCON = 0xd2;                //9λ�ɱ䲨����,У��λ��ʼΪ0
    #endif

	AUXR |= 0x04;		            //���������ʷ�����ʱ��ΪFosc,��1T
	BRT = 255-INT(FOSC/BAUD/32);	//�趨���������ʷ�������װֵ
	AUXR |= 0x01;		            //����1ѡ����������ʷ�����Ϊ�����ʷ�����
	AUXR |= 0x10;		            //�������������ʷ�����
}

