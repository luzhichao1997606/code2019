#include "variable.h"

/*******************************************************************************
*                                    �̼���Ϣ����                              *
*******************************************************************************/
CINT8 Device_Software_Version[] = {"2.3.17"};  //�豸����汾���м�ÿ���޸ĺ���£�
UINT16 Device_Model_Code;                     //��Ʒ�ͺű��룺�мǳ�ʼ����

/*******************************************************************************
*                                    ϵͳ��������                              *
*******************************************************************************/
t_Flag tflag[2];                              //��־
UINT8 UART2_event_index,
      UART2_event_num,
      UART2_deal_event_num,
      X232_CM_Operating_Road_Num_now,
      X232_CM_Control_Style,
      X232_CM_Sensing_Style;
UINT8 UART2_Data_Wait_beat_num,
      X232_CM_All_Refresh_beat_num,
      X232_CM_Refresh_Road_num;
UINT16 X232_CM_Refresh_beat_num,
       X232_CM_Data_Wait_beat_num;
UINT16 X485_Ctrl_Instr_Wait_beat_num;

SeqQueue rxArray_UART2;                         //����2ָ�����

UINT8 X232_CM_buf[X232_CM_ROAD_NUM] = {0, 0, 0, 0, 0, 0, 0, 0};
CM_struct CM_struct_buf[X232_CM_ROAD_NUM];

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
