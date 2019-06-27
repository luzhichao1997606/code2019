#include "variable.h"

/********************************************************************************
*																ϵͳ��ʼ������																	*
********************************************************************************/
void Init(void)
{
  //	init_Device_Info();
  init_UART2();
}

/********************************************************************************
*			�ն�Ӧ�ù�����ǰ��ʼ�������������г���ʱ���ݣ����ɹر����ؿڹ��ܣ�				*
********************************************************************************/
void END_Early_Init(void)
{
  init_Device_Info();
}

/********************************************************************************
*															�豸��Ϣ��ʼ������																*
********************************************************************************/
void init_Device_Info(void)
{
  //ÿ����Ʒ����Ψһ��ţ���·����ͬ���Ҳ��ͬ��
  switch (Device_Check_Road_Num)
  {
    case END_ROAD_NUM_04_CODE:    //4·

      Device_Model_Code = END_MODEL_CM004_ROAD_04_CODE;    //THY 041A C804 ��˹��AM8230 4·

      break;
    case END_ROAD_NUM_08_CODE:    //8·

      Device_Model_Code = END_MODEL_CM004_ROAD_08_CODE;    //THY 081A C804 ��˹��AM8230 8·

      break;
    default:

      Device_Model_Code = END_MODEL_X_ROAD_NULL_CODE;

      break;
  }
}

/********************************************************************************
*																485ͨ�ų�ʼ��																		*
********************************************************************************/
void init_UART2(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  USART_InitTypeDef USART_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  	//ʹ�ܴ���2ʹ�õ�GPIOʱ��
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);   //ʹ�ܴ���2ʱ��

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  USART_InitStructure.USART_BaudRate = 4800;              	 /*���ò�����Ϊ4800*/
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;/*��������λΪ8*/
  USART_InitStructure.USART_StopBits = USART_StopBits_1;     /*����ֹͣλΪ1λ*/
  USART_InitStructure.USART_Parity = USART_Parity_No;        /*��У��*/
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;/*��Ӳ������*/
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  /*���ͺͽ���*/
  USART_Init(USART2, &USART_InitStructure);

  USART_Cmd(USART2, ENABLE);
  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  X485_RECEIVE;				//receive enable

  UART2_Data_Wait_beat_num = 0;
  UART2_Data_Get_Flag = 0;
  UART2_data_length_Flag = 0;
  UART2_event_start_Flag = 0;
  UART2_event_index = 0;

  X485_Ctrl_Instr_Wait_beat_num = 0;
  X485_Ctrl_Instr_Wait_Flag = 0;
  X232_No_Feedback_Flag = 0;
  X232_CM_Operating_Road_Num_now = X232_CM_ROAD_NUM;
  X232_CM_Data_Wait_beat_num = 0;
  X232_CM_Data_Wait_Flag = 0;
  X232_CM_Refresh_Flag = 0;
  X232_CM_All_Refresh_Flag = 0;
  X232_CM_Refresh_Road_num = 0;
  X232_CM_Control_Style = 0;
  UART2_event_num = 0;
  UART2_deal_event_num = 0;
  X232_CM_Sensing_Style = 0;
  Feedback_Action_Flag = 0;

  Device_Status_Clear();
  QueueInit(&rxArray_UART2);
}

/********************************************************************************
*																�豸״̬��Ϣ�������														*
********************************************************************************/
void Device_Status_Clear(void)
{
  UINT8 i, j;

  for (i = 0; i < X232_CM_ROAD_NUM; i ++)
  {
    CM_struct_buf[i].volume_value = 0x20;
    CM_struct_buf[i].run_mode = 0x02;
    CM_struct_buf[i].power_status = 0x02;
    CM_struct_buf[i].online_status = 0x02;
    CM_struct_buf[i].source_value = 0x08;
    CM_struct_buf[i].mute_status = 0x02;
    CM_struct_buf[i].audio_value = 0x06;
    CM_struct_buf[i].play_mode = 0x02;
    CM_struct_buf[i].treble_value = 0x10;
    CM_struct_buf[i].bass_value = 0x10;

    for (j = 0; j < SONG_NAME_NUM; j ++)
    {
      CM_struct_buf[i].song_name[j] = 0x00;
    }
  }
}

/*******************************************************************************
*																	NO MORE CODE															   *
*******************************************************************************/
