/***************************************************************************** 
 * File name:       UART.h
 * Description:     ����ͷ�ļ������ڵ��ô��ں���
 * Author:          Mr.Xueyuan
 * Version:         v0.0.01-Frame
 * Date:            2018/6/18
 * History:         v0.0.01��д����������(6.18)
 *****************************************************************************/ 

#ifndef UART_H_
    #define UART_H_

    /* Ƶ�ʵ��� */
    #define FOSC 11059200L          //ϵͳƵ��
    #define BAUD 9600             //���ڲ�����

    /* ��żУ��λ */
    #define NONE_PARITY     0       //��У��
    #define ODD_PARITY      1       //��У��
    #define EVEN_PARITY     2       //żУ��
    #define MARK_PARITY     3       //���У��
    #define SPACE_PARITY    4       //�հ�У��

    /* ���ڳ�ʼ������ */
    extern void UartInit(void);




#endif /* UART_H_ */