#include "variable.h"

/********************************************************************************
*												 系统时钟里的7us5周期处理函数，													*
*																不用请清空函数体																*
********************************************************************************/
void Heartbeat_7us5(void)
{

}

/********************************************************************************
*													系统时钟里的4ms周期处理函数，													*
*															不用请清空函数体																	*
********************************************************************************/
void Heartbeat_4ms(void)
{
  Timer1_Deal();
}

/********************************************************************************
*																		溢出处理函数																*
********************************************************************************/
void Timer1_Deal(void)
{
  /*UART2 485周期性检测*/
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
    { //已进行数据接收
      UART2_Data_Wait_beat_num ++;

      if (UART2_Data_Wait_beat_num >= UART2_DATA_WAIT_NUM)
      { //指令接收结束
        rxArray_UART2.finish_Flag = 0;

        UART2_event_index = 0;
        UART2_event_start_Flag = 0;
        UART2_data_length_Flag = 0;
        UART2_Data_Get_Flag = 0;
      }
    }
    else if (X232_CM_Data_Wait_beat_num >= UART2_DATA_END_NUM)
    { //未接收到反馈数据
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
  { //已进行数据接收
    UART2_Data_Wait_beat_num ++;

    if (UART2_Data_Wait_beat_num >= UART2_DATA_WAIT_NUM)
    { //指令接收结束
      rxArray_UART2.finish_Flag = 0;

      UART2_event_index = 0;
      UART2_event_start_Flag = 0;
      UART2_data_length_Flag = 0;
      UART2_Data_Get_Flag = 0;
    }
  }
}

/********************************************************************************
*													系统时钟里的1s周期处理函数，													*
*															不用请清空函数体																	*
********************************************************************************/
void Heartbeat_1s(void)
{
}

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
