/***************************************************************************** 
 * File name:       core.c
 * Description:     shell内核函数，实现对其他shell工具的调用
 * Author:          Mr.Xueyuan
 * Version:         v0.0.03-Frame
 * Date:            2018/7/1
 * History:         git
 *****************************************************************************/ 


/* 链接头文件 */
#include "..\..\inc\Main\stdafx.h"

/* 显示文本 */
xdata char Boot_inf_UART [] = {"
    /r/n 楂樹紭鍏堢骇涓
    /r/n
    /r/n UART init OK
"};     //伪装代码

xdata char Boot_inf_sys [] = {"
    /r/n System Boot Now ...
"};     //启动

xdata char Boot_inf_STime [] = {"
    /r/n System Time Boot Now ...
    /r/n STime init OK
"}      //系统时钟初始化提示信息

/*************************************************
 * Function:        InitShell
 * Description:     初始化Shell
 * Calls:           run
 * Called By:       main
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/ 
void InitShell (void) 
{
    SendString (*Boot_inf_UART);
    SendString (*Boot_inf_sys);
    STimeInit();
    SendString (*Boot_inf_STime);
    run ();
}

/*************************************************
 * Function:        run
 * Description:     shell运行
 * Calls:           none
 * Called By:       main
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/ 
void run (void) 
{

}


/*************************************************
 * Function:        STimeInit
 * Description:     系统时间定时器初始化 (T1)
 * Calls:           none
 * Called By:       STimeInit
 * Input:           none
 * Output:          SystemTime
 * Return:          void
 *************************************************/ 
void STimeInit(void)	    //50毫秒@11.0592MHz
{
	AUXR &= 0xBF;		    //定时器时钟12T模式
	TMOD &= 0x0F;		    //设置定时器模式
	TMOD |= 0x10;		    //设置定时器模式
	TL1 = 0x00;		        //设置定时初值
	TH1 = 0x4C;		        //设置定时初值
	TF1 = 0;		        //清除TF1标志
	TR1 = 1;		        //定时器1开始计时
}

/*************************************************
 * Function:        STime
 * Description:     系统时间定时器
 * Calls:           none
 * Called By:       STimeInit
 * Input:           none
 * Output:          SystemTime
 * Return:          void
 *************************************************/ 
void STime(void) interrupt 3 using 1
{
	TL1 = 0x00;		//复位定时初值
	TH1 = 0x4C;		//复位定时初值
    count_Stime++;  //时间计数递增
    if (count_Stime == 20)  //时间计数置位
    {
        count_Stime = 0;    //复位时间计数
        SystemTime += 1;    //系统时间计时
    }
}


