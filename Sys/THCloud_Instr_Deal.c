#include "variable.h"

/********************************************************************************
*																平台控制指令处理函数														*
********************************************************************************/ 
UINT8 THCloud_Control_Deal(
					CUINT8 END_Addr_Code,				//终端地址码
					CUINT8 Device_Type,					//设备类型
					CUINT8 Device_Road_num,			//动作设备路数
					CUINT8 Action_Type_Code,		//动作类型码
					CUINT8 Action_Num_Code,			//动作数值码
					CUINT8 *Long_Data						//长数据，此时Action_Num_Code为长数据长度
																			//不用时用END_NULL_CODE填充
						)
{
	switch(Device_Type)
	{
	case END_DEVICE_TYPE_CM_CODE:    //背景音乐 

		if((!X232_CM_Data_Wait_Flag) && rxArray_UART2.finish_Flag)
		{
			X232_CM_Control(Device_Road_num, Action_Type_Code, Action_Num_Code);

  		X485_Ctrl_Instr_Wait_Flag = 0;
			X232_CM_Refresh_beat_num = 0;
			X232_CM_Refresh_Flag = 0;			//暂停轮询
		}
		else
		{		//有待接收数据，暂缓指令执行
			X485_Ctrl_Instr_Wait_beat_num = 0;
			X485_Ctrl_Instr_Wait_Flag = 1;

			return 0;
		}
		
		break;
	default:

		return 1;

	}

	return 1;
}

/********************************************************************************
*															平台查询指令处理函数															*
********************************************************************************/
UINT8 THCloud_Inquiry_Deal(
					CUINT8 END_Addr_Code,				//终端地址码
					CUINT8 Device_Type,					//设备类型
					CUINT8 Device_Road_num,			//动作设备路数
					CUINT8 Action_Type_Code,		//动作类型码
					CUINT8 Action_Num_Code,			//动作数值码
					CUINT8 *Long_Data						//长数据，此时Action_Num_Code为长数据长度
																			//不用时用END_NULL_CODE填充
						)
{
	switch(Device_Type)
	{
	case END_DEVICE_TYPE_LK_CODE:    //门锁类 Lock

		break;
	case END_DEVICE_TYPE_CAC_CODE:    //中央空调 Central Air-conditioning

		break;
	case END_DEVICE_TYPE_CM_CODE:    //中央音响

		break;
	case END_DEVICE_TYPE_RK_CODE:	//回弹式开关类 Rebound Key

		break;
	default:

		return 1;
	}

	return 1;
}

/********************************************************************************
*															平台设置指令处理函数															*
********************************************************************************/
UINT8 THCloud_Set_Deal(
					CUINT8 END_Addr_Code,				//终端地址码
					CUINT8 Device_Type,					//设备类型
					CUINT8 Device_Road_num,			//动作设备路数
					CUINT8 Action_Type_Code,		//动作类型码
					CUINT8 Action_Num_Code,			//动作数值码
					CUINT8 *Long_Data						//长数据，此时Action_Num_Code为长数据长度
																			//不用时用END_NULL_CODE填充
						)
{
	switch(Device_Type)
	{
	case END_DEVICE_TYPE_RC_CODE:		//遥控器类 Remote Controller

		break;
	case END_DEVICE_TYPE_RK_CODE:		//回弹式开关类 Rebound Key

		break;
	case END_DEVICE_TYPE_LK_CODE:     //门锁类 Lock

		break;
	default:

		return 1;
	}

	return 1;
}

/********************************************************************************
*															平台设置指令处理函数																*
********************************************************************************/
UINT8 THCloud_System_Deal(
					CUINT8 END_Addr_Code,						//终端地址码
					CUINT8 Action_Type_Code,				//动作类型码
					CUINT8 Action_Num_Code,					//动作数值码
					CUINT8 *Long_Data								//长数据，此时Action_Num_Code为长数据长度
																					//不用时用END_NULL_CODE填充
						)
{
	switch(Action_Type_Code)
	{
	case END_SYS_RELOAD_CODE:			//系统重置码


		break;
	}

	return 1;
}

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
