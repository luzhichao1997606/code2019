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
*                                    ���Ź�ָ���                              *
********************************************************************************/
#ifndef __feed_dog
#define __feed_dog

#define FEED_DOG            IWDG_ReloadCounter()        //��λWDT������

#define TH_DEBUG_ON                  0         //��������״̬

#endif

/********************************************************************************
*                                 �������Ͷ��塪��32λ��                           *
********************************************************************************/
#ifndef __variable_type
#define __variable_type

typedef signed char INT8;                     //�з��Ŷ�����
typedef signed short INT16;                   //�з�������
typedef signed int INT32;                     //�з��ų�����
typedef unsigned char UINT8;                  //�޷��Ŷ�����
typedef unsigned short UINT16;                //�޷�������
typedef unsigned int UINT32;                  //�޷��ų�����
typedef const char CINT8;                     //�з��Ŷ�����
typedef const short CINT16;                   //�з�������
typedef const int CINT32;                     //�з��ų�����
typedef const unsigned char CUINT8;           //�޷��Ŷ�����
typedef const unsigned short CUINT16;         //�޷�������
typedef const unsigned int CUINT32;           //�޷��ų�����
typedef unsigned char BOOLEAN;                //������
typedef volatile signed char VINT8;           //�з��Ŷ�����
typedef volatile signed short VINT16;         //�з�������
typedef volatile signed int VINT32;           //�з��ų�����
typedef volatile unsigned char VUINT8;        //�޷��Ŷ�����
typedef volatile unsigned short VUINT16;      //�޷�������
typedef volatile unsigned int VUINT32;        //�޷��ų�����

#endif

/********************************************************************************
*                                     �����������                               *
********************************************************************************/
extern UINT8 g_FW_upgrade_exit_flag;            //�˳�����������־
extern volatile UINT8 g_FW_upgrade_mode;        //�̼�����ģʽ;1:ƽ̨����;2:����������3���ӻ�ƽ̨����
extern volatile UINT8 g_FW_upgrade_mode;             //�̼�����ģʽ;1:ƽ̨����;2:����������3���ӻ�ƽ̨����
extern volatile UINT8 g_FW_upgrade_device_type;      //����ģʽ(���ڣ��������ӻ�)

#define FW_UPGRADE_DEVICE_NONE   (0x00)    //�豸����Ϊ��
#define FW_UPGRADE_DEVICE_ZNE    (0x01)    //�豸����Ϊ����
#define FW_UPGRADE_DEVICE_HOST   (0x02)    //�豸����Ϊ�ն�����
#define FW_UPGRADE_DEVICE_SLAVE  (0x32)    //�豸����Ϊ�ӻ�

/********************************************************************************
*                                   ϵͳ���Ͷ���                                 *
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
  UINT8 get_flag:1;	        //ʱ���ѻ�ȡ��־
  UINT8 refresh_flag:1;     //���±�־
  UINT8 ms_beat_num;        //�����ʱ

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
	UINT8 id_pass_flag;	        //�����֤
	UINT8 id[DEVICE_ID_LEN];
}Slave_info;

#endif

/********************************************************************************
*                                     ϵͳ��������                               *
********************************************************************************/
extern CINT8 Device_Software_Version[];            //�豸����汾���ַ�����ʽ��= ��1.0.1����
extern UINT16 Device_Model_Code;                   //��Ʒ�ͺű��룬�ն��ṩ
extern UINT8 Device_Check_Road_Num;                //�豸���˶�·����ϵͳ�ṩ
extern UINT8 Device_Type_Code;                     //�豸���ͱ���
extern UINT8 Device_Link_Flag;                     //�豸������־
extern UINT8 Device_Test_Flag;                     //�豸���Ա�־
extern UINT8 Device_User_Bound_Flag;               //�豸�󶨱�־
extern UINT8 HBS_Device_Flag;                      //Homebus�豸��־
extern UINT8 END_WAN_Model_Type;                   //����ģ������
extern CUINT8 *END_NULL_CODE;                      //ָ��NULLֵ
extern UINT32 Key_Binding_Device_Info;             //����������Ϣ
extern Time_info Sys_Time;                         //ϵͳʱ��
extern Slave_info END_Slave_ID[];                  //485���豸��Ϣ

/********************************************************************************
*                                   ϵͳ��������                                 *
********************************************************************************/
//ϵͳ���ܳ�ʼ������
void SYS_Init(void);
//�ն�Ӧ�ù�����ǰ��ʼ�������������г���ʱ���ݣ����ɹر����ؿڹ��ܣ�
void END_Early_Init(void);
//ϵͳ���к���
void SYS_Running(void);
//����1�жϴ�������ϵͳ�ã�
void UART1_Deal(void);
//����2�жϴ�������485/232��
void UART2_Deal(void);
//����3�жϴ�������485/232��
void UART3_Deal(void);
//����4�жϴ�������485/232��
void UART4_Deal(void);
//����5�жϴ�������485/232��
void UART5_Deal(void);
//Tim3����
void Heartbeat_7us5_Open(void);
//Tim3�ر�
void Heartbeat_7us5_Close(void);
//ϵͳʱ�����7.5us���ڴ���������������պ�����
void Heartbeat_7us5(void);
//ϵͳʱ�����4ms���ڴ���������������պ�����
void Heartbeat_4ms(void);
//ϵͳʱ�����1s���ڴ���������������պ�����
void Heartbeat_1s(void);
//��ʱ��2�жϴ�������ϵͳ�ã�
void Timer2_Deal(void);
//��ʱ��3�жϴ�����
void Timer3_Deal(void);
//t ms��ʱ����
void delay_ms(CUINT16 t);
//t 10us��ʱ����
void delay_10us(CUINT8 t);
//�豸״̬��Ϣ�������
void Device_Status_Clear(void);
//485����2���ݽ��պ���
void UART2_DATA_GET(
                    CUINT8 Data                    //����2���ص�����
                      );
//485����3���ݽ��պ���
void UART3_DATA_GET(
                    CUINT8 Data                    //����3���ص�����
                      );
//485����4���ݽ��պ���
void UART4_DATA_GET(
                    CUINT8 Data                    //����4���ص�����
                      );
//485����5���ݽ��պ���
void UART5_DATA_GET(
                    CUINT8 Data                    //����5���ص�����
                      );
//ƽ̨����ָ�����
UINT8 THCloud_Control_Deal(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8 Device_Type,            //�豸����
                    CUINT8 Device_Road_num,        //�����豸·��
                    CUINT8 Action_Type_Code,       //����������
                    CUINT8 Action_Num_Code,        //������ֵ��
                    CUINT8 *Long_Data              //�����ݣ���ʱAction_Num_CodeΪ�����ݳ���
                                                   //����ʱ��END_NULL_CODE���
                      );
//ƽ̨��ѯָ�����
UINT8 THCloud_Inquiry_Deal(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8 Device_Type,            //�豸����
                    CUINT8 Device_Road_num,        //�����豸·��
                    CUINT8 Action_Type_Code,       //����������
                    CUINT8 Action_Num_Code,        //������ֵ��
                    CUINT8 *Long_Data              //�����ݣ���ʱAction_Num_CodeΪ�����ݳ���
                                                   //����ʱ��END_NULL_CODE���
                      );
//ƽ̨����ָ�����
UINT8 THCloud_Set_Deal(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8 Device_Type,            //�豸����
                    CUINT8 Device_Road_num,        //�����豸·��/�豸������
                    CUINT8 Action_Type_Code,       //����������
                    CUINT8 Action_Num_Code,        //������ֵ��
                    CUINT8 *Long_Data              //�����ݣ���ʱAction_Num_CodeΪ�����ݳ���
                                                   //����ʱ��END_NULL_CODE���
                      );
//ƽ̨ϵͳָ�����
UINT8 THCloud_System_Deal(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8 Action_Type_Code,       //����������
                    CUINT8 Action_Num_Code,        //������ֵ��
                    CUINT8 *Long_Data              //�����ݣ���ʱAction_Num_CodeΪ�����ݳ���
                                                   //����ʱ��END_NULL_CODE���
                      );

//�ն˿��Ʒ����ϱ�����
void THNet_Control_Report(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8 Device_Type_Code,       //�豸������
                    CUINT8 Device_Road_num,        //�豸�ϱ�·��
                    CUINT8 Report_Status_Code,     //�ϱ�״̬��
                    CINT16 Report_Data,            //�ϱ�����
                    CUINT8 *Long_Data              //�����ݣ���ʱReport_DataΪ�����ݳ���
                                                   //����ʱ��END_NULL_CODE���
                      );
//�ն˲�ѯ�����ϱ�����
void THNet_Inquiry_Report(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8 Device_Type_Code,       //�豸������
                    CUINT8 Device_Road_num,        //�豸�ϱ�·��
                    CUINT8 Report_Status_Code,     //�ϱ�״̬��
                    CINT16 Report_Data,            //�ϱ�����
                    CUINT8 *Long_Data              //�����ݣ���ʱReport_DataΪ�����ݳ���
                                                   //����ʱ��END_NULL_CODE���
                      );
//�ն����÷����ϱ�����
void THNet_Set_Report(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8 Device_Type_Code,       //�豸������
                    CUINT8 Device_Road_num,        //�豸�ϱ�·��/�豸������
                    CUINT8 Report_Status_Code,     //�ϱ�״̬��
                    CINT16 Report_Data,            //�ϱ�����
                    CUINT8 *Long_Data              //�����ݣ���ʱReport_DataΪ�����ݳ���
                                                   //����ʱ��END_NULL_CODE���
                      );
//�ն�״̬�����ϱ�����
void THNet_Status_Report(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8 Device_Type_Code,       //�豸������
                    CUINT8 Device_Road_num,        //�豸�ϱ�·��
                    CUINT8 Report_Status_Code,     //�ϱ�״̬��
                    CINT16 Report_Data,            //�ϱ�����
                    CUINT8 *Long_Data              //�����ݣ���ʱReport_DataΪ�����ݳ���
                                                   //����ʱ��END_NULL_CODE���
                      );
//�ն�ϵͳָ���ϱ�����
void THNet_System_Report(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8 Action_Type_Code,       //����������
                    CUINT8 Action_Num_Code,        //������ֵ��
                    CUINT8 *Long_Data              //�����ݣ���ʱAction_Num_CodeΪ�����ݳ���
                                                   //����ʱ��END_NULL_CODE���
                      );

//�ն��豸ID�Ϸ��Լ��
UINT8 END_Device_ID_Check(
                    CUINT8 END_Addr_Code,          //�ն˵�ַ��
                    CUINT8* Device_id              //�豸ID
                      );

//���߰�������������
UINT8 X485_Key_Action_Deal(
                    CUINT8 Keypad_Pos,             //ǽ�ڿ���λ��������0��ʼ
                    CUINT8 Key_Pos,                //����λ��������0��ʼ
                    CUINT8 Key_Beat_Num            //��������
                      );
//��������������
UINT8 THEnd_Key_Action_Deal(
                    CUINT8 Key_Style,              //��������
                    CUINT8 Key_Pos,                //����λ��������0��ʼ
                    CUINT8 Key_Beat_Num,           //��������
                    CUINT32 Key_Bind_Device_Info   //�����豸��Ϣ
                      );
//�����󶨴�����
UINT32 THEnd_Key_Bind_Deal(
                    CUINT8 Key_Pos,                //����λ��������0��ʼ
                    CUINT8 Key_Beat_Num,           //��������
                    CUINT8 Data_Length,            //���ݳ���
                    CUINT8 *Device_Data            //��������
                      );
//����ָʾ�ƿ��ƺ���
void THEnd_LED_Control(
                    CUINT8 Device_Road_num,        //�����豸·��
                    CUINT8 Action_num_Code         //������ֵ��
                      );
//��������������
void THEnd_Bell_Control(
                    CUINT8 Ring_Mode
                      );

/*��ʹ��Flash��ַ��Χ��0x08025000 ~ 0x080277FF����10k�����𳬷�Χʹ�ã�����*/
//Flashд�뺯��
UINT8 Flash_Write(
                    CUINT8 *Write_DATA,            //��д����������
                    CUINT8 Length,                 //д�����ݳ���
                    CUINT32 Start_Addr             //д����ʼ��ַ
                      );
//Flash��ȡ����
UINT8 Flash_Read(
                    UINT8 *Read_DATA,              //�����ö�ȡ��������
                    UINT8 Start_Pos,               //��ȡ���ݷ�����ʼλ�ã���0��ʼ
                    CUINT8 Length,                 //��ȡ���ݳ���
                    CUINT32 Start_Addr             //��ȡ��ʼ��ַ
                      );
//����Flash��ʼ������
UINT8 Flash_Using_Reload(void);

/********************************************************************************
*                                    NO MORE CODE                               *
********************************************************************************/
