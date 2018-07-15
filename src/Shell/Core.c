/***************************************************************************** 
 * File name:       core.c
 * Description:     shell�ں˺�����ʵ�ֶ�����shell���ߵĵ���
 * Author:          Mr.Xueyuan
 * Version:         v0.0.03-Frame
 * Date:            2018/7/1
 * History:         git
 *****************************************************************************/ 


/* ����ͷ�ļ� */
#include "..\..\inc\Main\stdafx.h"

/* ��ʾ�ı� */
xdata char Boot_inf_UART [] = {"
    /r/n 高优先级�
    /r/n
    /r/n UART init OK
"};     //αװ����

xdata char Boot_inf_sys [] = {"
    /r/n System Boot Now ...
"};     //����

xdata char Boot_inf_STime [] = {"
    /r/n System Time Boot Now ...
    /r/n STime init OK
"}      //ϵͳʱ�ӳ�ʼ����ʾ��Ϣ

/*************************************************
 * Function:        InitShell
 * Description:     ��ʼ��Shell
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
 * Description:     shell����
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
 * Description:     ϵͳʱ�䶨ʱ����ʼ�� (T1)
 * Calls:           none
 * Called By:       STimeInit
 * Input:           none
 * Output:          SystemTime
 * Return:          void
 *************************************************/ 
void STimeInit(void)	    //50����@11.0592MHz
{
	AUXR &= 0xBF;		    //��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;		    //���ö�ʱ��ģʽ
	TMOD |= 0x10;		    //���ö�ʱ��ģʽ
	TL1 = 0x00;		        //���ö�ʱ��ֵ
	TH1 = 0x4C;		        //���ö�ʱ��ֵ
	TF1 = 0;		        //���TF1��־
	TR1 = 1;		        //��ʱ��1��ʼ��ʱ
}

/*************************************************
 * Function:        STime
 * Description:     ϵͳʱ�䶨ʱ��
 * Calls:           none
 * Called By:       STimeInit
 * Input:           none
 * Output:          SystemTime
 * Return:          void
 *************************************************/ 
void STime(void) interrupt 3 using 1
{
	TL1 = 0x00;		//��λ��ʱ��ֵ
	TH1 = 0x4C;		//��λ��ʱ��ֵ
    count_Stime++;  //ʱ���������
    if (count_Stime == 20)  //ʱ�������λ
    {
        count_Stime = 0;    //��λʱ�����
        SystemTime += 1;    //ϵͳʱ���ʱ
    }
}


