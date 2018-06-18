/***************************************************************************** 
 * File name:       main.c
 * Description:     主函数文件，包含初始化函数及入口函数。
 * Author:          Mr.Xueyuan
 * Version:         v0.0.01-Frame
 * Date:            2018/6/18
 * History:         none
 *****************************************************************************/ 








/*************************************************
 * Function:        main
 * Description:     主函数
 * Calls:           All
 * Called By:       none
 * Input:           none
 * Output:          void
 * Return:          void
 *************************************************/ 
int main (void) 
{
    /*单片机初始化*/
    init();

    /*运行Shell代码*/
    runShell();

    /*死循环*/
    while (1) 
    {
        
    }
}
