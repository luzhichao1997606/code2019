#include "IO_Define.h"
#include "Sys_defunc.h"
#include "Sys_Instr.h"
#include "Instruction.h"

/********************************************************************************
*																	������������																	*
********************************************************************************/
#ifndef __timer_num
  #define __timer_num

  #define CM_REFRESH_CYCLE_NUM	1250		//��ѯ����:5��
  //(5000 / TIMER0_CYCLE) = 1250
  #define CM_ALL_REFRESH_CYCLE_NUM	20		//ȫ����ѯ���ڣ�1����
  //(60000 / (CM_REFRESH_CYCLE_NUM * TIMER0_CYCLE)) = 20
  #define UART2_DATA_WAIT_NUM		20		//ָ����ս����ж�ʱ��
  //(80 / TIMER0_CYCLE) = 20
  #define UART2_DATA_END_NUM     325     //���Ʒ���ָ������ȴ�ʱ��
  //(1300 / TIMER0_CYCLE) = 325
  #define X485_CTRL_INSTR_WAIT_NUM		 500      //����ָ���ִ�еȴ�ʱ�䣺2s
  //(2000 / TIMERA_CYCLE) = 500

#endif

/********************************************************************************
*																		��������																		*
********************************************************************************/
#ifndef __constant_num
  #define __constant_num

  #define UART2_BUFFER_NUM        80        //��������С
  #define MAX_EVENT_NUM						10

  #define	X232_CM_ROAD_NUM				8					//����·��
  #define X232_CM001_BUF_LEN			5
  #define X232_CHECK_SUM_LEN			3
  #define SONG_NAME_NUM			    	21	      //���������ȣ����ֽ�Ϊ���ֱ������ͣ�GB2312

  #define MAXQUEUESIZE						255

#endif

/********************************************************************************
*																�������Ͷ���											 						  *
********************************************************************************/
typedef struct rx2
{
  UINT8 finish_Flag: 1;
  UINT8 len: 7;
  UINT8 buf[UART2_BUFFER_NUM];
} UART2_struct;

typedef struct         //���ݽṹ��
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
*																	��������																			*
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

extern UINT8 X232_CM_buf[];                     //232ͨ��ָ��

extern SeqQueue rxArray_UART2;
extern CM_struct CM_struct_buf[];

/********************************************************************************
*																			��������																	  *
********************************************************************************/
void Init(void);
void init_Device_Info(void);                          //�豸��Ϣ��ʼ������
void init_UART2(void);                          //����˫���ڳ�ʼ������

void X485_DATA_GET(UINT8);
void Timer1_Deal(void);
void X485_Send(CUINT8*, CUINT8);					//UART2 485�������ݷ��ͺ���
void X232_Data_Poll(void);								//485��������ѯ����
UINT8 X232_Instr_Deal(struct rx *);						//ָ�����
void X232_CM_Control(CUINT8, CUINT8, CUINT8);		//���ƺ���
void X232_CM_Sensing(CUINT8);							//��ѯ����
void X232_CM_Data_Feedback(void);					//��������
UINT16 Check_Sum(UINT8*, UINT8);					//У���뺯��
void QueueInit(SeqQueue *);								//���г�ʼ������
UINT8 QueueNotEmpty(SeqQueue);						//���в�ѯ����
UINT8 QueueAdd(SeqQueue *, UINT8);				//�����к���
UINT8 QueueDelete(SeqQueue *, UINT8 *);		//�����к���
UINT8 QueueHeadGet(SeqQueue, UINT8 *);		//��ȡ����ͷ����

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
