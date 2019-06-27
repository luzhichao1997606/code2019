#include "variable.h"

/*******************************************************************************
*                             UART2 485串口数据发送函数                        *
*******************************************************************************/
void X485_Send(CUINT8* send_DATA,    //待发送数据数组
               CUINT8 Length         //数组长度
              )
{
  UINT8 i;

  X485_TRANSMIT;                           //drive enable
  delay_10us(10);

  for (i = 0; i < Length; i ++)
  {
    //往XBEE发送串口数据
    USART_SendData(USART2, send_DATA[i]);
    while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
  }

  delay_10us(10);
  X485_RECEIVE;                           //receive enable
}

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
