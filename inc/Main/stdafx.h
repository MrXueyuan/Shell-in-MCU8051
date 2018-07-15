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
#define STC12 1
#define STC15 2
#define IC_SET STC12 //STC12 or STC15

/* Ƶ�ʵ��� */
#define FOSC 11059200L //ϵͳƵ��
#define BAUD 9600      //���ڲ�����

/* ͷ�ļ����� */
#if (IC_SET == STC12) //оƬͷ�ļ�����
#include "STC12.h"
#elif (IC_SET == STC15)
#include "STC15.h"
#endif
#include <intrins.h>       //��Ƭ��ָ��ͷ�ļ�
#include "..\Shell\core.h" //Shell�ں�ͷ�ļ�����
#include "..\UART\UART.h"  //����ͷ�ļ�����

/* �������� */
extern data bit Con_Flag;        //����������־
extern xdata char Con_cache[80]; //����̨����
extern data u8 Con_C_cache;      //����ָ̨�뻺��
extern data u8 count_Stime;      //ʱ�����
extern xdata u32 SystemTime;     //ϵͳʱ��
extern bit Busy;                 //����æ��־

#endif /* STDAFX_H_ */
