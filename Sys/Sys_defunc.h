#include "stm32f10x.h"
#include "Sys_Instr.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H

/* Uncomment the line corresponding to the STMicroelectronics evaluation board
   used to run the example */
#if !defined (USE_STM3210B_EVAL) &&  !defined (USE_STM3210E_EVAL) &&  !defined (USE_STM3210C_EVAL) &&  !defined (USE_STM32100B_EVAL)
 #define USE_STM3210E_EVAL
#endif

#endif /* __PLATFORM_CONFIG_H */

/********************************************************************************
*                                    看门狗指令定义                              *
********************************************************************************/
#ifndef __feed_dog
#define __feed_dog

#define FEED_DOG            IWDG_ReloadCounter()        //复位WDT计数器

#define TH_DEBUG_ON                  0         //开启调试状态

#endif

/********************************************************************************
*                                 数据类型定义——32位机                           *
********************************************************************************/
#ifndef __variable_type
#define __variable_type

typedef signed char INT8;                     //有符号短整型
typedef signed short INT16;                   //有符号整型
typedef signed int INT32;                     //有符号长整型
typedef unsigned char UINT8;                  //无符号短整型
typedef unsigned short UINT16;                //无符号整型
typedef unsigned int UINT32;                  //无符号长整型
typedef const char CINT8;                     //有符号短整型
typedef const short CINT16;                   //有符号整型
typedef const int CINT32;                     //有符号长整型
typedef const unsigned char CUINT8;           //无符号短整型
typedef const unsigned short CUINT16;         //无符号整型
typedef const unsigned int CUINT32;           //无符号长整型
typedef unsigned char BOOLEAN;                //布尔型
typedef volatile signed char VINT8;           //有符号短整型
typedef volatile signed short VINT16;         //有符号整型
typedef volatile signed int VINT32;           //有符号长整型
typedef volatile unsigned char VUINT8;        //无符号短整型
typedef volatile unsigned short VUINT16;      //无符号整型
typedef volatile unsigned int VUINT32;        //无符号长整型

#endif

/********************************************************************************
*                                     在线升级相关                               *
********************************************************************************/
extern UINT8 g_FW_upgrade_exit_flag;            //退出在线升级标志
extern volatile UINT8 g_FW_upgrade_mode;        //固件升级模式;1:平台升级;2:串口升级；3：从机平台升级
extern volatile UINT8 g_FW_upgrade_mode;             //固件升级模式;1:平台升级;2:串口升级；3：从机平台升级
extern volatile UINT8 g_FW_upgrade_device_type;      //升级模式(串口，主机，从机)

#define FW_UPGRADE_DEVICE_NONE   (0x00)    //设备类型为空
#define FW_UPGRADE_DEVICE_ZNE    (0x01)    //设备类型为网关
#define FW_UPGRADE_DEVICE_HOST   (0x02)    //设备类型为终端主机
#define FW_UPGRADE_DEVICE_SLAVE  (0x32)    //设备类型为从机

/********************************************************************************
*                                   系统类型定义                                 *
********************************************************************************/
#ifndef __defunc_fixed_type
#define __defunc_fixed_type

typedef enum
{
  FW_UPGRADE_MODE_NONE,
	FW_UPGRADE_MODE_NET_HOST,
	FW_UPGRADE_MODE_SERIAL_HOST,
	FW_UPGRADE_MODE_CHANNEL_SLAVE
}FW_E_Upgrade_Mode;

typedef struct
{
  UINT8 get_flag:1;	        //时钟已获取标志
  UINT8 refresh_flag:1;     //更新标志
  UINT8 ms_beat_num;        //毫秒计时

  union
  {
    struct
    {
      UINT16 year;
      UINT8 month;
      UINT8 day;
      UINT8 week;
      UINT8 hour;
      UINT8 minute;
      UINT8 second;
    }one;
    UINT8 all[END_SYS_CLOCK_DATA_LEN];
  }time;
}Time_info;

typedef struct
{
	UINT8 id_pass_flag;	        //身份验证
	UINT8 id[DEVICE_ID_LEN];
}Slave_info;

#endif

/********************************************************************************
*                                     系统变量声明                               *
********************************************************************************/
extern CINT8 Device_Software_Version[];            //设备软件版本（字符串格式：= “1.0.1”）
extern UINT16 Device_Model_Code;                   //产品型号编码，终端提供
extern UINT8 Device_Check_Road_Num;                //设备供核对路数，系统提供
extern UINT8 Device_Type_Code;                     //设备类型编码
extern UINT8 Device_Link_Flag;                     //设备联网标志
extern UINT8 Device_Test_Flag;                     //设备测试标志
extern UINT8 Device_User_Bound_Flag;               //设备绑定标志
extern UINT8 HBS_Device_Flag;                      //Homebus设备标志
extern UINT8 END_WAN_Model_Type;                   //网络模块类型
extern CUINT8 *END_NULL_CODE;                      //指针NULL值
extern UINT32 Key_Binding_Device_Info;             //按键待绑定信息
extern Time_info Sys_Time;                         //系统时钟
extern Slave_info END_Slave_ID[];                  //485从设备信息

/********************************************************************************
*                                   系统函数声明                                 *
********************************************************************************/
//系统功能初始化函数
void SYS_Init(void);
//终端应用功能提前初始化函数：不可有长耗时内容，不可关闭下载口功能！
void END_Early_Init(void);
//系统运行函数
void SYS_Running(void);
//串口1中断处理函数：系统用！
void UART1_Deal(void);
//串口2中断处理函数：485/232用
void UART2_Deal(void);
//串口3中断处理函数：485/232用
void UART3_Deal(void);
//串口4中断处理函数：485/232用
void UART4_Deal(void);
//串口5中断处理函数：485/232用
void UART5_Deal(void);
//Tim3开启
void Heartbeat_7us5_Open(void);
//Tim3关闭
void Heartbeat_7us5_Close(void);
//系统时钟里的7.5us周期处理函数，不用请清空函数体
void Heartbeat_7us5(void);
//系统时钟里的4ms周期处理函数，不用请清空函数体
void Heartbeat_4ms(void);
//系统时钟里的1s周期处理函数，不用请清空函数体
void Heartbeat_1s(void);
//定时器2中断处理函数：系统用！
void Timer2_Deal(void);
//定时器3中断处理函数
void Timer3_Deal(void);
//t ms延时函数
void delay_ms(CUINT16 t);
//t 10us延时函数
void delay_10us(CUINT8 t);
//设备状态信息清除函数
void Device_Status_Clear(void);
//485串口2数据接收函数
void UART2_DATA_GET(
                    CUINT8 Data                    //串口2发回的数据
                      );
//485串口3数据接收函数
void UART3_DATA_GET(
                    CUINT8 Data                    //串口3发回的数据
                      );
//485串口4数据接收函数
void UART4_DATA_GET(
                    CUINT8 Data                    //串口4发回的数据
                      );
//485串口5数据接收函数
void UART5_DATA_GET(
                    CUINT8 Data                    //串口5发回的数据
                      );
//平台控制指令处理函数
UINT8 THCloud_Control_Deal(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8 Device_Type,            //设备类型
                    CUINT8 Device_Road_num,        //动作设备路数
                    CUINT8 Action_Type_Code,       //动作类型码
                    CUINT8 Action_Num_Code,        //动作数值码
                    CUINT8 *Long_Data              //长数据，此时Action_Num_Code为长数据长度
                                                   //不用时用END_NULL_CODE填充
                      );
//平台查询指令处理函数
UINT8 THCloud_Inquiry_Deal(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8 Device_Type,            //设备类型
                    CUINT8 Device_Road_num,        //动作设备路数
                    CUINT8 Action_Type_Code,       //动作类型码
                    CUINT8 Action_Num_Code,        //动作数值码
                    CUINT8 *Long_Data              //长数据，此时Action_Num_Code为长数据长度
                                                   //不用时用END_NULL_CODE填充
                      );
//平台设置指令处理函数
UINT8 THCloud_Set_Deal(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8 Device_Type,            //设备类型
                    CUINT8 Device_Road_num,        //动作设备路数/设备子类型
                    CUINT8 Action_Type_Code,       //动作类型码
                    CUINT8 Action_Num_Code,        //动作数值码
                    CUINT8 *Long_Data              //长数据，此时Action_Num_Code为长数据长度
                                                   //不用时用END_NULL_CODE填充
                      );
//平台系统指令处理函数
UINT8 THCloud_System_Deal(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8 Action_Type_Code,       //动作类型码
                    CUINT8 Action_Num_Code,        //动作数值码
                    CUINT8 *Long_Data              //长数据，此时Action_Num_Code为长数据长度
                                                   //不用时用END_NULL_CODE填充
                      );

//终端控制反馈上报函数
void THNet_Control_Report(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8 Device_Type_Code,       //设备类型码
                    CUINT8 Device_Road_num,        //设备上报路数
                    CUINT8 Report_Status_Code,     //上报状态码
                    CINT16 Report_Data,            //上报数据
                    CUINT8 *Long_Data              //长数据，此时Report_Data为长数据长度
                                                   //不用时用END_NULL_CODE填充
                      );
//终端查询反馈上报函数
void THNet_Inquiry_Report(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8 Device_Type_Code,       //设备类型码
                    CUINT8 Device_Road_num,        //设备上报路数
                    CUINT8 Report_Status_Code,     //上报状态码
                    CINT16 Report_Data,            //上报数据
                    CUINT8 *Long_Data              //长数据，此时Report_Data为长数据长度
                                                   //不用时用END_NULL_CODE填充
                      );
//终端设置反馈上报函数
void THNet_Set_Report(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8 Device_Type_Code,       //设备类型码
                    CUINT8 Device_Road_num,        //设备上报路数/设备子类型
                    CUINT8 Report_Status_Code,     //上报状态码
                    CINT16 Report_Data,            //上报数据
                    CUINT8 *Long_Data              //长数据，此时Report_Data为长数据长度
                                                   //不用时用END_NULL_CODE填充
                      );
//终端状态反馈上报函数
void THNet_Status_Report(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8 Device_Type_Code,       //设备类型码
                    CUINT8 Device_Road_num,        //设备上报路数
                    CUINT8 Report_Status_Code,     //上报状态码
                    CINT16 Report_Data,            //上报数据
                    CUINT8 *Long_Data              //长数据，此时Report_Data为长数据长度
                                                   //不用时用END_NULL_CODE填充
                      );
//终端系统指令上报函数
void THNet_System_Report(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8 Action_Type_Code,       //动作类型码
                    CUINT8 Action_Num_Code,        //动作数值码
                    CUINT8 *Long_Data              //长数据，此时Action_Num_Code为长数据长度
                                                   //不用时用END_NULL_CODE填充
                      );

//终端设备ID合法性检查
UINT8 END_Device_ID_Check(
                    CUINT8 END_Addr_Code,          //终端地址码
                    CUINT8* Device_id              //设备ID
                      );

//总线按键动作处理函数
UINT8 X485_Key_Action_Deal(
                    CUINT8 Keypad_Pos,             //墙壁开关位置数，从0开始
                    CUINT8 Key_Pos,                //按键位置数，从0开始
                    CUINT8 Key_Beat_Num            //按键动作
                      );
//按键动作处理函数
UINT8 THEnd_Key_Action_Deal(
                    CUINT8 Key_Style,              //按键类型
                    CUINT8 Key_Pos,                //按键位置数，从0开始
                    CUINT8 Key_Beat_Num,           //按键动作
                    CUINT32 Key_Bind_Device_Info   //所绑设备信息
                      );
//按键绑定处理函数
UINT32 THEnd_Key_Bind_Deal(
                    CUINT8 Key_Pos,                //按键位置数，从0开始
                    CUINT8 Key_Beat_Num,           //按键动作
                    CUINT8 Data_Length,            //数据长度
                    CUINT8 *Device_Data            //数据内容
                      );
//顶板指示灯控制函数
void THEnd_LED_Control(
                    CUINT8 Device_Road_num,        //动作设备路数
                    CUINT8 Action_num_Code         //动作数值码
                      );
//顶板铃声处理函数
void THEnd_Bell_Control(
                    CUINT8 Ring_Mode
                      );

/*可使用Flash地址范围：0x08025000 ~ 0x080277FF，共10k。切勿超范围使用！！！*/
//Flash写入函数
UINT8 Flash_Write(
                    CUINT8 *Write_DATA,            //待写入数据数组
                    CUINT8 Length,                 //写入数据长度
                    CUINT32 Start_Addr             //写入起始地址
                      );
//Flash读取函数
UINT8 Flash_Read(
                    UINT8 *Read_DATA,              //待放置读取数据数组
                    UINT8 Start_Pos,               //读取数据放置起始位置：从0开始
                    CUINT8 Length,                 //读取数据长度
                    CUINT32 Start_Addr             //读取起始地址
                      );
//所用Flash初始化函数
UINT8 Flash_Using_Reload(void);

/********************************************************************************
*                                    NO MORE CODE                               *
********************************************************************************/
