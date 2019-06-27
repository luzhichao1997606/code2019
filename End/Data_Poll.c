#include "variable.h"

/********************************************************************************
*																485��������ѯ����																*
********************************************************************************/
void X232_Data_Poll(void)
{
  //���������ն˵�ָ������
  if (!rxArray_UART2.finish_Flag)
  {
    rxArray_UART2.finish_Flag = X232_Instr_Deal(&rxArray_UART2);

    X232_CM_Data_Wait_Flag = 0;
  }

  //��ѯָ���·�
  if (!X232_CM_Data_Wait_Flag)
  { //���ݸ����������ݵȴ�
    if (X232_No_Feedback_Flag)
    { //����ָ���޷���
      if (CM_struct_buf[X232_CM_Operating_Road_Num_now].online_status != X232_CM_OFFLINE_CODE)
      { //����״̬�����ı�
        CM_struct_buf[X232_CM_Operating_Road_Num_now].online_status =
          CM_struct_buf[X232_CM_Operating_Road_Num_now].online_status << 3;     /*�ۻ��޷�������*/

        if (CM_struct_buf[X232_CM_Operating_Road_Num_now].online_status == X232_CM_OFFLINE_CODE)
        { //ȷ�ϵ���
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
    { //���ڿ������޽Ӵ�ָ��
      if (X232_CM_Refresh_Flag)
      { //�����������·�
        X232_CM_Refresh_Road_num ++;

        if (X232_CM_Refresh_Road_num <= X232_CM_ROAD_NUM)
        {
          if ((CM_struct_buf[X232_CM_Refresh_Road_num - 1].online_status != X232_CM_OFFLINE_CODE)
              || X232_CM_All_Refresh_Flag)
          { //���߻�ȫ������
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
