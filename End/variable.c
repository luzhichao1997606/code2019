#include "variable.h"

/*******************************************************************************
*                                    固件信息定义                              *
*******************************************************************************/
CINT8 Device_Software_Version[] = {"2.3.17"};  //设备软件版本：切记每次修改后更新！
UINT16 Device_Model_Code;                     //产品型号编码：切记初始化！

/*******************************************************************************
*                                    系统变量定义                              *
*******************************************************************************/
t_Flag tflag[2];                              //标志
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

SeqQueue rxArray_UART2;                         //串口2指令缓存器

UINT8 X232_CM_buf[X232_CM_ROAD_NUM] = {0, 0, 0, 0, 0, 0, 0, 0};
CM_struct CM_struct_buf[X232_CM_ROAD_NUM];

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
