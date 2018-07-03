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

    /* �������� */
    bit Busy;                           //����æ��־

    /* Ƶ�ʵ��� */
    #define FOSC 11059200L          //ϵͳƵ��
    #define BAUD 9600             //���ڲ�����

    /* ��żУ��λ */
    #define NONE_PARITY     0       //��У��
    #define ODD_PARITY      1       //��У��
    #define EVEN_PARITY     2       //żУ��

    /* ���ڳ�ʼ������ */
    extern void UartInit(void);

    /* ���ڷ��ͺ��� */
    extern void SendData(char dat);     //���ڷ����ֽ�
    extern void SendString(char *s);    //���ڷ����ַ���

#endif /* UART_H_ */