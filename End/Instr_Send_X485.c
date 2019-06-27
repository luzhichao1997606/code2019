#include "variable.h"

/*******************************************************************************
*                             UART2 485�������ݷ��ͺ���                        *
*******************************************************************************/
void X485_Send(CUINT8* send_DATA,    //��������������
               CUINT8 Length         //���鳤��
              )
{
  UINT8 i;

  X485_TRANSMIT;                           //drive enable
  delay_10us(10);

  for (i = 0; i < Length; i ++)
  {
    //��XBEE���ʹ�������
    USART_SendData(USART2, send_DATA[i]);
    while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
  }

  delay_10us(10);
  X485_RECEIVE;                           //receive enable
}

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
