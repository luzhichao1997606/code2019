#include "variable.h"

/********************************************************************************
*																485传感量轮询函数																*
********************************************************************************/
void X232_Data_Poll(void)
{
  //处理来自终端的指令数据
  if (!rxArray_UART2.finish_Flag)
  {
    rxArray_UART2.finish_Flag = X232_Instr_Deal(&rxArray_UART2);

    X232_CM_Data_Wait_Flag = 0;
  }

  //轮询指令下发
  if (!X232_CM_Data_Wait_Flag)
  { //数据更新且无数据等待
    if (X232_No_Feedback_Flag)
    { //上条指令无反馈
      if (CM_struct_buf[X232_CM_Operating_Road_Num_now].online_status != X232_CM_OFFLINE_CODE)
      { //在线状态发生改变
        CM_struct_buf[X232_CM_Operating_Road_Num_now].online_status =
          CM_struct_buf[X232_CM_Operating_Road_Num_now].online_status << 3;     /*累积无反馈次数*/

        if (CM_struct_buf[X232_CM_Operating_Road_Num_now].online_status == X232_CM_OFFLINE_CODE)
        { //确认掉线
          THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                              (END_CM_ROAD_01_CODE + X232_CM_Operating_Road_Num_now),
                              END_CM_ONLINE_STATUS_CODE, END_CM_OFFLINE_CODE, END_NULL_CODE);
        }
      }

      THEnd_LED_Control(X232_CM_Operating_Road_Num_now + END_LED_ROAD_01_CODE,
                        END_LED_POWER_OFF_CODE);

      X232_No_Feedback_Flag = 0;
      X232_CM_Operating_Road_Num_now = X232_CM_ROAD_NUM;
    }

    if ((!X485_Ctrl_Instr_Wait_Flag) && (!UART2_Data_Get_Flag) && rxArray_UART2.finish_Flag)
    { //串口空闲且无接待指令
      if (X232_CM_Refresh_Flag)
      { //面板更新数据下发
        X232_CM_Refresh_Road_num ++;

        if (X232_CM_Refresh_Road_num <= X232_CM_ROAD_NUM)
        {
          if ((CM_struct_buf[X232_CM_Refresh_Road_num - 1].online_status != X232_CM_OFFLINE_CODE)
              || X232_CM_All_Refresh_Flag)
          { //在线或全部更新
            UART2_event_index = 0;
            UART2_event_start_Flag = 0;
            UART2_data_length_Flag = 0;

            X232_CM_Sensing(X232_CM_Refresh_Road_num);
          }
        }
        else
        {
          X232_CM_Refresh_Flag = 0;
          X232_CM_All_Refresh_Flag = 0;
          X232_CM_Refresh_Road_num = 0;
        }
      }
    }
  }
}

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
