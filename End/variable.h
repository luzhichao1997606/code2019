#include "IO_Define.h"
#include "Sys_defunc.h"
#include "Sys_Instr.h"
#include "Instruction.h"

/********************************************************************************
*																	心跳常量定义																	*
********************************************************************************/
#ifndef __timer_num
  #define __timer_num

  #define CM_REFRESH_CYCLE_NUM	1250		//轮询周期:5秒
  //(5000 / TIMER0_CYCLE) = 1250
  #define CM_ALL_REFRESH_CYCLE_NUM	20		//全部轮询周期：1分钟
  //(60000 / (CM_REFRESH_CYCLE_NUM * TIMER0_CYCLE)) = 20
  #define UART2_DATA_WAIT_NUM		20		//指令接收结束判断时间
  //(80 / TIMER0_CYCLE) = 20
  #define UART2_DATA_END_NUM     325     //控制反馈指令结束等待时间
  //(1300 / TIMER0_CYCLE) = 325
  #define X485_CTRL_INSTR_WAIT_NUM		 500      //控制指令待执行等待时间：2s
  //(2000 / TIMERA_CYCLE) = 500

#endif

/********************************************************************************
*																		常量定义																		*
********************************************************************************/
#ifndef __constant_num
  #define __constant_num

  #define UART2_BUFFER_NUM        80        //缓存器大小
  #define MAX_EVENT_NUM						10

  #define	X232_CM_ROAD_NUM				8					//控制路数
  #define X232_CM001_BUF_LEN			5
  #define X232_CHECK_SUM_LEN			3
  #define SONG_NAME_NUM			    	21	      //歌曲名长度，首字节为名字编码类型：GB2312

  #define MAXQUEUESIZE						255

#endif

/********************************************************************************
*																数据类型定义											 						  *
********************************************************************************/
typedef struct rx2
{
  UINT8 finish_Flag: 1;
  UINT8 len: 7;
  UINT8 buf[UART2_BUFFER_NUM];
} UART2_struct;

typedef struct         //数据结构体
{
  UINT8 run_mode: 2;
  UINT8 volume_value: 6;
  UINT8 power_status: 2;
  UINT8 source_value: 4;
  UINT8 play_mode: 2;
  UINT8 mute_status: 2;
  UINT8 audio_value: 5;
  UINT8 online_status;
  UINT8 treble_value;
  UINT8 bass_value;
  UINT8 song_name[SONG_NAME_NUM];

} CM_struct;

typedef union
{
  struct
  {
    UINT8  F0: 1;
    UINT8  F1: 1;
    UINT8  F2: 1;
    UINT8  F3: 1;
    UINT8  F4: 1;
    UINT8  F5: 1;
    UINT8  F6: 1;
    UINT8  F7: 1;
  } oneBit;
  UINT8 allBits;
} t_Flag;

typedef struct rx
{
  UINT8 buf[MAXQUEUESIZE];
  UINT8 head;
  UINT8 end;
  UINT8 count;
  UINT8 finish_Flag;
} SeqQueue;

/********************************************************************************
*																	变量声明																			*
********************************************************************************/
extern t_Flag tflag[2];

#define  UART2_Data_Get_Flag          tflag[0].oneBit.F0
#define  UART2_data_length_Flag       tflag[0].oneBit.F1
#define  X232_CM_Data_Wait_Flag	  	  tflag[0].oneBit.F2
#define  UART2_event_start_Flag       tflag[0].oneBit.F3
#define  X232_No_Feedback_Flag				tflag[0].oneBit.F4
#define  X232_CM_Refresh_Flag					tflag[0].oneBit.F5
#define  X232_CM_All_Refresh_Flag			tflag[0].oneBit.F6
#define  Feedback_Action_Flag					tflag[0].oneBit.F7

#define  X485_Ctrl_Instr_Wait_Flag  	tflag[1].oneBit.F0

extern UINT8 UART2_event_index,
       UART2_event_num,
       UART2_deal_event_num,
       X232_CM_Operating_Road_Num_now,
       X232_CM_Control_Style,
       X232_CM_Sensing_Style;
extern UINT8 UART2_Data_Wait_beat_num,
       X232_CM_All_Refresh_beat_num,
       X232_CM_Refresh_Road_num;
extern UINT16 X232_CM_Refresh_beat_num,
       X232_CM_Data_Wait_beat_num;
extern UINT16 X485_Ctrl_Instr_Wait_beat_num;

extern UINT8 X232_CM_buf[];                     //232通信指令

extern SeqQueue rxArray_UART2;
extern CM_struct CM_struct_buf[];

/********************************************************************************
*																			函数声明																	  *
********************************************************************************/
void Init(void);
void init_Device_Info(void);                          //设备信息初始化函数
void init_UART2(void);                          //声明双串口初始化函数

void X485_DATA_GET(UINT8);
void Timer1_Deal(void);
void X485_Send(CUINT8*, CUINT8);					//UART2 485串口数据发送函数
void X232_Data_Poll(void);								//485传感器轮询函数
UINT8 X232_Instr_Deal(struct rx *);						//指令处理函数
void X232_CM_Control(CUINT8, CUINT8, CUINT8);		//控制函数
void X232_CM_Sensing(CUINT8);							//查询函数
void X232_CM_Data_Feedback(void);					//反馈函数
UINT16 Check_Sum(UINT8*, UINT8);					//校验码函数
void QueueInit(SeqQueue *);								//队列初始化函数
UINT8 QueueNotEmpty(SeqQueue);						//队列查询函数
UINT8 QueueAdd(SeqQueue *, UINT8);				//进队列函数
UINT8 QueueDelete(SeqQueue *, UINT8 *);		//出队列函数
UINT8 QueueHeadGet(SeqQueue, UINT8 *);		//获取队列头函数

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
