/***************************************************************************** 
 * File name:       stdafx.h
 * Description:     ������ͷ�ļ����ڴ�ͷ�ļ��е�������ͷ�ļ��������岿�ֿɸ��ĳ�����
 * Author:          Mr.Xueyuan
 * Version:         v0.0.02-Frame
 * Date:            2018/6/20
 * History:         git
 *****************************************************************************/ 

#ifndef STDAFX_H_
    #define STDAFX_H_

    /* ����ʹ�õ�оƬ */
    #define STC12  1
    #define STC15  2
    #define IC_SET STC12        //STC12 or STC15

    /* Ƶ�ʵ��� */
    #define FOSC 11059200L          //ϵͳƵ��
    #define BAUD 9600             //���ڲ�����

    /* ͷ�ļ����� */
    #if (IC_SET == STC12)       //оƬͷ�ļ�����
        #include "STC12.h" 
    #elif (IC_SET == STC15)
        #include "STC15.h"
    #endif
    #include <intrins.h>        //��Ƭ��ָ��ͷ�ļ�
    #include "..\Shell\core.h"  //Shell�ں�ͷ�ļ�����
    #include "..\UART\UART.h"   //����ͷ�ļ�����

    /* ����UARTУ��λ */
    #define PARITYBIT NONE_PARITY

    /* �������� */
    u8  code count_Stime = 0;   //ʱ�����
    u32 code SystemTime = 0;    //ϵͳʱ��
    bit Con_Flag = true;        //����������־
    char    Con_cache[80];      //����̨����

#endif /* STDAFX_H_ */
