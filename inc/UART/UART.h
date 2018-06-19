/***************************************************************************** 
 * File name:       UART.h
 * Description:     串口头文件，用于调用串口函数
 * Author:          Mr.Xueyuan
 * Version:         v0.0.01-Frame
 * Date:            2018/6/18
 * History:         none
 *****************************************************************************/ 

#ifndef UART_H_
#define UART_H_

/* 频率调整 */
#define FOSC 11059200L          //系统频率
#define BAUD 9600             //串口波特率

/* 奇偶校验位 */
#define NONE_PARITY     0       //无校验
#define ODD_PARITY      1       //奇校验
#define EVEN_PARITY     2       //偶校验
#define MARK_PARITY     3       //标记校验
#define SPACE_PARITY    4       //空白校验

/* 串口初始化函数 */
extern void UartInit(void);

#endif /* UART_H_ */