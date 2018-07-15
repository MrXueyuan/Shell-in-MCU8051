/***************************************************************************** 
 * File name:       UART.h
 * Description:     串口头文件，用于调用串口函数
 * Author:          Mr.Xueyuan
 * Version:         v0.0.01-Frame
 * Date:            2018/6/18
 * History:         git
 *****************************************************************************/ 

#ifndef UART_H_
    #define UART_H_

    /* 变量定义 */
    bit Busy;                           //串口忙标志

    /* 奇偶校验位 */
    #define NONE_PARITY     0       //无校验
    #define ODD_PARITY      1       //奇校验
    #define EVEN_PARITY     2       //偶校验

    /* 串口初始化函数 */
    extern void UartInit(void);

    /* 串口发送函数 */
    extern void SendData(char dat);     //串口发送字节
    extern void SendString(char *s);    //串口发送字符串

#endif /* UART_H_ */