#include "variable.h"

/*******************************************************************************
*                                ��������������                              *
*******************************************************************************/
UINT8 THEnd_Key_Action_Deal(
  CUINT8 Key_Style,							//��������
  CUINT8 Key_Pos,           		//����λ��������0��ʼ
  CUINT8 Key_Beat_Num,      		//��������
  CUINT32 Key_Bind_Device_Info	//�����豸��Ϣ
)
{
  UINT8 key_deal_status;

  key_deal_status = 1;

  switch (Key_Style)
  {
    case KEY_STYLE_TOP_KEYBOARD_CODE:				//Ϊ�����������

      if ((Key_Beat_Num == END_TRIGGER_CODE) && (Key_Pos < DEVICE_TOP_KEY_NUM))
      { //���嵥��ֱ�Ӵ���
        if (Key_Pos < X232_CM_ROAD_NUM)
        { //·���Ϸ�
          if ((!X232_CM_Data_Wait_Flag) && rxArray_UART2.finish_Flag)
          { //�޴����ռ��������ݣ��·�����ָ��
            THEnd_Bell_Control(BELL_RING_MODE_01_CODE);			//���ض���������

            if (CM_struct_buf[Key_Pos].power_status == 0x01)
            { //����״̬�����ı�
              //ִ�й�
              X232_CM_Control(Key_Pos + END_CM_ROAD_01_CODE, END_CM_POWER_STATUS_CODE,
                              END_CM_POWER_OFF_CODE);
            }
            else
            {
              //ִ�п�
              X232_CM_Control(Key_Pos + END_CM_ROAD_01_CODE, END_CM_POWER_STATUS_CODE,
                              END_CM_POWER_ON_CODE);
            }

            X485_Ctrl_Instr_Wait_Flag = 0;
          }
          else
          { //�Ȳ�����
            X485_Ctrl_Instr_Wait_beat_num = 0;
            X485_Ctrl_Instr_Wait_Flag = 1;

            key_deal_status = 0;
          }
        }
      }

      break;
    case KEY_STYLE_NORMAL_CODE:					//Ϊ��ͨ��������

      if (((Key_Beat_Num >= END_TRIGGER_CODE)
           && (Key_Beat_Num <= END_TRIGGER_FORTH_CODE))
          || (Key_Beat_Num == END_TRIGGER_ST_LONG_CODE))
      { //ִ�ж�����Ч
        UINT32 device_info;
        UINT8 road_pos;

        device_info = Key_Bind_Device_Info;

        //�����洢��ʽ���������ݽ��з���ִ��
        switch (((UINT8)(device_info >> 24) & 0xF0))
        { //ȡ��8λ�������豸�����ж�
          case END_SET_DEVICE_SR_CODE:      //�̵����ȶ���������

            road_pos = (UINT8)(device_info >> 16) - 1;

            if (road_pos < X232_CM_ROAD_NUM)
            { //·���Ϸ�
              if ((!X232_CM_Data_Wait_Flag) && rxArray_UART2.finish_Flag)
              { //�޴����ռ��������ݣ��·�����ָ��
                THEnd_Bell_Control(BELL_RING_MODE_01_CODE);			//���ض���������

                if (CM_struct_buf[road_pos].power_status == 0x01)
                { //����״̬�����ı�
                  //ִ�й�
                  X232_CM_Control(road_pos + END_CM_ROAD_01_CODE, END_CM_POWER_STATUS_CODE,
                                  END_CM_POWER_OFF_CODE);
                }
                else
                { //ִ�п�
                  X232_CM_Control(road_pos + END_CM_ROAD_01_CODE, END_CM_POWER_STATUS_CODE,
                                  END_CM_POWER_ON_CODE);
                }

                X485_Ctrl_Instr_Wait_Flag = 0;
              }
              else
              { //�Ȳ�����
                X485_Ctrl_Instr_Wait_beat_num = 0;
                X485_Ctrl_Instr_Wait_Flag = 1;

                key_deal_status = 0;
              }
            }

            break;
          case END_SET_DEVICE_SM_CODE:      //����

            THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_RK_CODE,
                                (Key_Pos + END_KEY_01_CODE), END_ZERO_CODE, Key_Beat_Num, END_NULL_CODE);

            key_deal_status = 2;

            break;
          case 0x00:			//δ��
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
*                          ���������豸��Ϣ��װ������                        *
*******************************************************************************/
UINT32 THEnd_Key_Bind_Deal(
  CUINT8 Key_Pos,           //����λ��������0��ʼ
  CUINT8 Key_Beat_Num,      //��������
  CUINT8 Data_Length,				//���ݳ���
  CUINT8 *Device_Data				//��������
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
  { //�豸����
    case END_SET_DEVICE_SR_CODE:      //�̵����ȶ���������

      device_info = (((UINT32)key_set_device_type) << 24)
                    + (((UINT32)(key_set_device_road_num - END_SR_ROAD_01_CODE + 1)) << 16);

      break;
    default:      //����

      device_info = ((UINT32)key_set_device_type) << 24;

      break;
  }

  if (Key_Beat_Num == END_ZERO_CODE)
  { //Ϊ����״̬���洢���������������豸��Ϣ
    Key_Binding_Device_Info = device_info;
  }

  return device_info;			//���ذ���Ϣ
}

/*******************************************************************************
*				 											   NO MORE CODE	     						        	       *
*******************************************************************************/
