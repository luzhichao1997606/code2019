#include "variable.h"

/*******************************************************************************
*                                按键动作处理函数                              *
*******************************************************************************/
UINT8 THEnd_Key_Action_Deal(
  CUINT8 Key_Style,							//按键类型
  CUINT8 Key_Pos,           		//按键位置数，从0开始
  CUINT8 Key_Beat_Num,      		//按键动作
  CUINT32 Key_Bind_Device_Info	//所绑设备信息
)
{
  UINT8 key_deal_status;

  key_deal_status = 1;

  switch (Key_Style)
  {
    case KEY_STYLE_TOP_KEYBOARD_CODE:				//为顶部按键面板

      if ((Key_Beat_Num == END_TRIGGER_CODE) && (Key_Pos < DEVICE_TOP_KEY_NUM))
      { //顶板单击直接处理
        if (Key_Pos < X232_CM_ROAD_NUM)
        { //路数合法
          if ((!X232_CM_Data_Wait_Flag) && rxArray_UART2.finish_Flag)
          { //无待接收及处理数据，下发控制指令
            THEnd_Bell_Control(BELL_RING_MODE_01_CODE);			//开关动作蜂鸣器

            if (CM_struct_buf[Key_Pos].power_status == 0x01)
            { //开关状态发生改变
              //执行关
              X232_CM_Control(Key_Pos + END_CM_ROAD_01_CODE, END_CM_POWER_STATUS_CODE,
                              END_CM_POWER_OFF_CODE);
            }
            else
            {
              //执行开
              X232_CM_Control(Key_Pos + END_CM_ROAD_01_CODE, END_CM_POWER_STATUS_CODE,
                              END_CM_POWER_ON_CODE);
            }

            X485_Ctrl_Instr_Wait_Flag = 0;
          }
          else
          { //先不处理
            X485_Ctrl_Instr_Wait_beat_num = 0;
            X485_Ctrl_Instr_Wait_Flag = 1;

            key_deal_status = 0;
          }
        }
      }

      break;
    case KEY_STYLE_NORMAL_CODE:					//为普通按键类型

      if (((Key_Beat_Num >= END_TRIGGER_CODE)
           && (Key_Beat_Num <= END_TRIGGER_FORTH_CODE))
          || (Key_Beat_Num == END_TRIGGER_ST_LONG_CODE))
      { //执行动作有效
        UINT32 device_info;
        UINT8 road_pos;

        device_info = Key_Bind_Device_Info;

        //对所存储格式按键绑定数据进行分析执行
        switch (((UINT8)(device_info >> 24) & 0xF0))
        { //取高8位，进行设备类型判断
          case END_SET_DEVICE_SR_CODE:      //继电器等动作交替类

            road_pos = (UINT8)(device_info >> 16) - 1;

            if (road_pos < X232_CM_ROAD_NUM)
            { //路数合法
              if ((!X232_CM_Data_Wait_Flag) && rxArray_UART2.finish_Flag)
              { //无待接收及处理数据，下发控制指令
                THEnd_Bell_Control(BELL_RING_MODE_01_CODE);			//开关动作蜂鸣器

                if (CM_struct_buf[road_pos].power_status == 0x01)
                { //开关状态发生改变
                  //执行关
                  X232_CM_Control(road_pos + END_CM_ROAD_01_CODE, END_CM_POWER_STATUS_CODE,
                                  END_CM_POWER_OFF_CODE);
                }
                else
                { //执行开
                  X232_CM_Control(road_pos + END_CM_ROAD_01_CODE, END_CM_POWER_STATUS_CODE,
                                  END_CM_POWER_ON_CODE);
                }

                X485_Ctrl_Instr_Wait_Flag = 0;
              }
              else
              { //先不处理
                X485_Ctrl_Instr_Wait_beat_num = 0;
                X485_Ctrl_Instr_Wait_Flag = 1;

                key_deal_status = 0;
              }
            }

            break;
          case END_SET_DEVICE_SM_CODE:      //场景

            THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_RK_CODE,
                                (Key_Pos + END_KEY_01_CODE), END_ZERO_CODE, Key_Beat_Num, END_NULL_CODE);

            key_deal_status = 2;

            break;
          case 0x00:			//未绑定
          case 0xF0:

            key_deal_status = 3;

            break;
          default:

            break;
        }
      }

      break;
  }

  return key_deal_status;
}

/*******************************************************************************
*                          按键设置设备信息封装处理函数                        *
*******************************************************************************/
UINT32 THEnd_Key_Bind_Deal(
  CUINT8 Key_Pos,           //按键位置数，从0开始
  CUINT8 Key_Beat_Num,      //按键动作
  CUINT8 Data_Length,				//数据长度
  CUINT8 *Device_Data				//数据内容
)
{
  UINT32 device_info;
  UINT8 key_set_device_type,
        key_set_device_road_num;
  //  UINT8 key_set_device_key_num;

  device_info = END_ZERO_CODE;

  key_set_device_type = Device_Data[KEY_SET_DEVICE_TYPE_POS];
  key_set_device_road_num = Device_Data[KEY_SET_DEVICE_ROAD_NUM_POS];
  //  key_set_device_key_num = Device_Data[KEY_SET_DEVICE_KEY_NUM_POS];

  switch (key_set_device_type)
  { //设备类型
    case END_SET_DEVICE_SR_CODE:      //继电器等动作交替类

      device_info = (((UINT32)key_set_device_type) << 24)
                    + (((UINT32)(key_set_device_road_num - END_SR_ROAD_01_CODE + 1)) << 16);

      break;
    default:      //其它

      device_info = ((UINT32)key_set_device_type) << 24;

      break;
  }

  if (Key_Beat_Num == END_ZERO_CODE)
  { //为待绑定状态，存储按键绑定所关联的设备信息
    Key_Binding_Device_Info = device_info;
  }

  return device_info;			//返回绑定信息
}

/*******************************************************************************
*				 											   NO MORE CODE	     						        	       *
*******************************************************************************/
