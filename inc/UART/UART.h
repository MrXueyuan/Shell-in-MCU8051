/***************************************************************************** 
 * File name:       UART.h
 * Description:     ����ͷ�ļ������ڵ��ô��ں���
 * Author:          Mr.Xueyuan
 * Version:         v0.0.01-Frame
 * Date:            2018/6/18
 * History:         git
 *****************************************************************************/

#ifndef UART_H_
#define UART_H_

/* ���ڳ�ʼ������ */
extern void UartInit(void);

/* ���ڷ��ͺ��� */
extern void SendData(char dat);  //���ڷ����ֽ�
extern void SendString(char *s); //���ڷ����ַ���

#endif /* UART_H_ */