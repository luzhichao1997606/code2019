#include "variable.h"

/********************************************************************************
*												 ϵͳʱ�����7us5���ڴ�������													*
*																��������պ�����																*
********************************************************************************/
void Heartbeat_7us5(void)
{

}

/********************************************************************************
*													ϵͳʱ�����4ms���ڴ�������													*
*															��������պ�����																	*
********************************************************************************/
void Heartbeat_4ms(void)
{
  Timer1_Deal();
}

/********************************************************************************
*																		���������																*
********************************************************************************/
void Timer1_Deal(void)
{
  /*UART2 485�����Լ��*/
  if (!X232_CM_Refresh_Flag)
  {
    X232_CM_Refresh_beat_num ++;
    if (X232_CM_Refresh_beat_num >= CM_REFRESH_CYCLE_NUM)
    {
      X232_CM_Refresh_beat_num = 0;
      X232_CM_Refresh_Flag = 1;

      if (!X232_CM_All_Refresh_Flag)
      {
        X232_CM_All_Refresh_beat_num ++;
        if (X232_CM_All_Refresh_beat_num >= CM_ALL_REFRESH_CYCLE_NUM)
        {
          X232_CM_All_Refresh_beat_num = 0;
          X232_CM_All_Refresh_Flag = 1;
        }
      }
    }
  }

  if (X485_Ctrl_Instr_Wait_Flag)
  {
    X485_Ctrl_Instr_Wait_beat_num ++;
    if (X485_Ctrl_Instr_Wait_beat_num >= X485_CTRL_INSTR_WAIT_NUM)
    {
      X485_Ctrl_Instr_Wait_beat_num = 0;
      X485_Ctrl_Instr_Wait_Flag = 0;
    }
  }

  if (X232_CM_Data_Wait_Flag)
  {
    X232_CM_Data_Wait_beat_num ++;

    if (UART2_Data_Get_Flag)
    { //�ѽ������ݽ���
      UART2_Data_Wait_beat_num ++;

      if (UART2_Data_Wait_beat_num >= UART2_DATA_WAIT_NUM)
      { //ָ����ս���
        rxArray_UART2.finish_Flag = 0;

        UART2_event_index = 0;
        UART2_event_start_Flag = 0;
        UART2_data_length_Flag = 0;
        UART2_Data_Get_Flag = 0;
      }
    }
    else if (X232_CM_Data_Wait_beat_num >= UART2_DATA_END_NUM)
    { //δ���յ���������
      X232_CM_Data_Wait_Flag = 0;
      UART2_Data_Get_Flag = 0;
      X232_CM_Control_Style = 0;
      X232_CM_Sensing_Style = 0;

      if (X232_CM_Operating_Road_Num_now < X232_CM_ROAD_NUM)
      {
        X232_No_Feedback_Flag = 1;
      }
    }
  }
  else if (UART2_Data_Get_Flag)
  { //�ѽ������ݽ���
    UART2_Data_Wait_beat_num ++;

    if (UART2_Data_Wait_beat_num >= UART2_DATA_WAIT_NUM)
    { //ָ����ս���
      rxArray_UART2.finish_Flag = 0;

      UART2_event_index = 0;
      UART2_event_start_Flag = 0;
      UART2_data_length_Flag = 0;
      UART2_Data_Get_Flag = 0;
    }
  }
}

/********************************************************************************
*													ϵͳʱ�����1s���ڴ�������													*
*															��������պ�����																	*
********************************************************************************/
void Heartbeat_1s(void)
{
}

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
