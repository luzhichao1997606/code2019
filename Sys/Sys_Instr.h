/************************************���¼�¼***********************************
   ����			 ����			  ����
2015.06.08  ��ʢƱ  ���䱳��������Դ����(V1.4)
2015.06.18  ��ʢƱ  �����������ڱ�������BUG(1.5)
2015.10.09  ��ʢƱ  ���䴰�����Э������(1.6)
2016.01.12  ��ʢƱ  ���Ӳ�Ʒ����(1.7)
2016.02.01  ��ʢƱ  ������Ʒ����������䱳��������Դ����(1.8)
2016.07.18  ��ʢƱ  �������ֿյ�AC331���ͱ���
2016.08.12  ��ʢƱ  ��������յ����ͱ���
2016.08.26  ��ʢƱ  ���Ӷ�֥�յ����ͱ���
2016.09.21  ��ʢƱ  ���������յ����ͱ���
2016.11.07  ��ʢƱ  �������������ͱ���
2016.11.23  ��ʢƱ  ���������ع��յ����ͱ���
2016.11.24  ��ʢƱ  ������˼���·����ͱ���
2016.11.24  ��ʢƱ  ����ʩ�͵µ�����ͱ���
2016.12.07  ��ʢƱ  ���Ӱ����·硢���Ŀյ����ͱ���
2016.12.23  ��ʢƱ  �����·�ģʽ����
2016.12.30  ��ʢƱ  ���ӿ��͸��յ���ů���ͱ���
2017.03.17  ��ʢƱ  ����������������Э������
2017.06.26  ��ʢƱ  ����������Ч���ӽ�������
*******************************************************************************/

/*******************************************************************************
*                                    ��������                                  *
*******************************************************************************/
#ifndef __system_fixed_num
#define __system_fixed_num

//ϵͳ��========================================================================
#define DEVICE_ID_LEN                       8           //���豸ID����

#define DEVICE_MODEL_CHECK_IN_ROAD_POS      0           //�豸�����ж�λ��

#define END_UPGRADE_FEED_LEN                1           //��������������Ϣ��
  //THNet_System_Report(end_device_addr, END_UPGRADE_CODE, END_UPGRADE_FEED_LEN, long_data);
#define END_UPGRADE_REQUIRE_DATA_LEN        2           //Ҫ������������Ϣ��

//ϵͳʱ��======================================================================
#define END_SYS_CLOCK_DATA_LEN              8           //ϵͳʱ�����ݳ���

#define END_SYS_CLOCK_YEAR_H_POS            0           //ϵͳʱ�����λλ��
#define END_SYS_CLOCK_YEAR_L_POS            1           //ϵͳʱ�����λλ��
#define END_SYS_CLOCK_MONTH_POS             2           //ϵͳʱ����λ��
#define END_SYS_CLOCK_DAY_POS               3           //ϵͳʱ����λ��
#define END_SYS_CLOCK_WEEK_POS              4           //ϵͳʱ������λ��
#define END_SYS_CLOCK_HOUR_POS              5           //ϵͳʱ��Сʱλ��
#define END_SYS_CLOCK_MINUTE_POS            6           //ϵͳʱ�ӷ���λ��
#define END_SYS_CLOCK_SECOND_POS            7           //ϵͳʱ������λ��

//ϵͳ������====================================================================
#define END_SB_SET_DATA_LEN                 2           //����ʱ�����ݳ���
#define END_SB_OVERTIME_REPORT_DATA_LEN     3           //������ʱ�ϱ����ݳ���

#define END_SB_SET_DATA_H_POS               0           //�������ݸ�λ
#define END_SB_SET_DATA_L_POS               1           //�������ݵ�λ

#define END_SB_OVER_REPORT_DATA_H_POS       0           //�����ϱ����ݸ�λ
#define END_SB_OVER_REPORT_DATA_L_POS       1           //�����ϱ����ݵ�λ
#define END_SB_OVER_REPORT_STATUS_POS       2           //�����ϱ�����״̬λ

//������========================================================================
#define END_KEY_BIND_DEVICE_INFO_LEN        3           //�������豸��Ϣ���ݳ���

#define KEY_SET_DEVICE_TYPE_POS             0
#define KEY_SET_DEVICE_ROAD_NUM_POS         1
#define KEY_SET_DEVICE_KEY_NUM_POS          2

#define DEVICE_TOP_KEY_NUM                  16          //����������������

//��������======================================================================
#define IR_CAPACITY_PER_DEV                 25
#define WR_CAPACITY_PER_DEV                 9

//��ֵ������====================================================================
#define END_QS_SET_DATA_LEN                 2           //�����������ݳ���

#define END_QS_SET_DATA_H_POS               0           //�������ݸ�λ
#define END_QS_SET_DATA_L_POS               1           //�������ݵ�λ

//��������====================================================================
#define EWG_LIMIT_SET_DATA_LEN              2           //��ֵ�������ݳ���
#define EWG_OVER_REPORT_DATA_LEN            3           //�����ϱ����ݳ���
#define EWG_TRI_PHASE_REPORT_DATA_LEN       3           //�����ϱ����ݳ���

#define EWG_LIMIT_SET_DATA_H_POS            0           //��ֵ�������ݸ�λ
#define EWG_LIMIT_SET_DATA_L_POS            1           //��ֵ�������ݵ�λ

#define EWG_OVER_REPORT_DATA_H_POS          0           //�����ϱ����ݸ�λ
#define EWG_OVER_REPORT_DATA_L_POS          1           //�����ϱ����ݵ�λ
#define EWG_OVER_REPORT_STATUS_POS          2           //�����ϱ�����״̬λ

#define EWG_TRI_PHASE_REPORT_SEQ_POS        0           //������������λ��
#define EWG_TRI_PHASE_REPORT_H_POS          1           //�������ݸ�λλ��
#define EWG_TRI_PHASE_REPORT_L_POS          2           //�������ݵ�λλ��

#define END_EWG_FEED_LONG_DATA_NUM          4           //�õ����������ݸ���
#define END_EWG_FEED_EXLONG_DATA_NUM        8           //�����õ����������ݸ���

//��������======================================================================
#define END_CM_VOLUME_MAX_NUM               100         //��������
#define END_CM_BASS_TREBLE_MAX_NUM          10          //�ߵ�������
#define END_CM_SONG_NAME_DATA_NUM           31          //�����������ֽ���

//����==========================================================================
#define END_CR_MAX_LEVEL_NUM                100         //���⼶��

//�����ů======================================================================
#define END_CFH_ACTION_DATA_NUM             2           //��ů���������ֽ���

#define END_CFH_ACTION_DATA_H_POS           0           //��ů�������ݸ��ֽ�λ��
#define END_CFH_ACTION_DATA_L_POS           1           //��ů�������ݵ��ֽ�λ��

#endif

/*******************************************************************************
*                                     ָ���붨��                               *
*******************************************************************************/
#ifndef __system_instruction
#define __system_instruction

//�նˣ�ϵͳ����================================================================
#define END_SYS_RELOAD_CODE                 0x10        //ϵͳ������
#define END_SYS_BOUND_STATUS_CODE           0x20        //ϵͳ��״̬��
#define END_SYS_CLOCK_CODE                  0x30        //ϵͳʱ����
#define END_MODE_STATUS_CODE                0x40        //����ģʽѡ��
#define END_ONLINE_STATUS_CODE              0x50        //����״̬
#define END_ID_CHECK_STATUS_CODE            0x60        //ID��֤״̬
#define END_FIRMWARE_CODE                   0x70        //�ն˹̼���Ϣ
#define END_UPGRADE_CODE                    0x80        //�ն˹̼�������Ϣ
#define END_SYS_INITIALIZE_CODE             0x90        //ϵͳ��ʼ��
#define END_UPGRADE_REQUIRE_CODE            0xA0        //�ն�Ҫ��̼�����
#define END_SYS_ID_REPLACE_CODE             0xB0        //ID�滻
#define END_DEVICE_SEARCH_CODE              0xC0        //�豸����

#define END_SYS_RELOAD_SUCCEED_CODE         0xA1        //ϵͳ���óɹ�
#define END_SYS_RELOAD_FAILED_CODE          0xA0        //ϵͳ����ʧ��
#define END_SYS_USER_BOUND_CODE             0xB1        //�û��Ѱ�
#define END_SYS_USER_UNBOUND_CODE           0xB0        //�û�δ��
#define END_MODE_1_AUTHORIZED_CODE          0xCA        //ģʽ1����Ȩ��������
#define END_MODE_2_ONLINE_ONLY_CODE         0xCB        //ģʽ2������ʱ��������
#define END_MODE_3_ALL_OFF_CODE             0xCC        //ģʽ3��ȫ��
#define END_MODE_4_ALL_ON_CODE              0xCD        //ģʽ4��ȫ��
#define END_ONLINE_STATUS_OFF_CODE          0xD0        //����״̬��������
#define END_ONLINE_STATUS_ON_CODE           0xD1        //����״̬������
#define END_SYS_INITIALIZE_SUCCEED_CODE     0xE1        //ϵͳ��ʼ���ɹ�
#define END_SYS_INITIALIZE_FAILED_CODE      0xE0        //ϵͳ��ʼ��ʧ��
#define END_ID_CHECK_PASS_CODE              0xA1        //ID��֤ͨ��
#define END_ID_CHECK_REJECT_CODE            0xA0        //ID��֤��ͨ��
#define END_UPGRADE_REQUIRE_INITIATIVE_CODE 0x01        //�ն�Ҫ��̼���������
#define END_UPGRADE_REQUIRE_ENFORCE_CODE    0x0F        //�ն�Ҫ��̼�ǿ������

//Flash����
#define END_FLASH_SUCCESS_CODE              0x01        //�ɹ�
#define END_FLASH_ERROR_ERASE_CODE          0xE0        //��������
#define END_FLASH_ERROR_WRITE_CODE          0xE1        //д�����
#define END_FLASH_ERROR_READ_CODE           0xE2        //��ȡ����
#define END_FLASH_ERROR_UNALIGNED_CODE      0xE3        //δ�������

//�նˣ��豸����================================================================
#define END_SET_DEVICE_SR_CODE              0x10        //�豸����ָ��̵���������
#define END_SET_DEVICE_EM_CODE              0x20        //�豸����ָ��綯ʽ���������
#define END_SET_DEVICE_SM_CODE              0x30        //�豸����ָ���������
#define END_SET_DEVICE_LI_CODE              0x40        //�豸����ָ��ѧϰ�ͺ���������
#define END_SET_DEVICE_LW_CODE              0x50        //�豸����ָ��ѧϰ������������

//�նˣ��豸����================================================================
#define END_DEVICE_TYPE_SR_CODE             0x61        //����ʽ�̵����� Switch Relay
#define END_DEVICE_TYPE_CR_CODE             0x62        //�ɵ���ʽ�̵����� Changeable Relay
#define END_DEVICE_TYPE_WWH_CODE            0x63        //�߿�ʽ��ˮ���� Wire-type Water Heater
#define END_DEVICE_TYPE_CAC_CODE            0x65        //����յ� Central Air-conditioning
#define END_DEVICE_TYPE_CFH_CODE            0x66        //�����ů Central Floor Heating
#define END_DEVICE_TYPE_CFA_CODE            0x67        //�����·� Central Fresh Air
#define END_DEVICE_TYPE_CM_CODE             0x68        //������������� Auxdi Central Music Control
#define END_DEVICE_TYPE_EM_CODE             0x71        //�綯ʽ����� Electric Motor
#define END_DEVICE_TYPE_LK_CODE             0x72        //������ Lock
#define END_DEVICE_TYPE_TRS_CODE            0x81        //����ʽ�������� Trigger Sensor
#define END_DEVICE_TYPE_QS_CODE             0x82        //������ʽ�������� Quantifiable Sensor
#define END_DEVICE_TYPE_EWG_CODE            0x89        //�������� Electric Water Gas
#define END_DEVICE_TYPE_LI_CODE             0x91        //ѧϰ�ͺ����� Learning Infrared
#define END_DEVICE_TYPE_LW_CODE             0xA1        //ѧϰ�������� Learning Wireless
#define END_DEVICE_TYPE_RK_CODE             0xB1        //�ص�ʽǽ�ڿ����� Rebound Key
#define END_DEVICE_TYPE_RC_CODE             0xB2        //ң������ Remote Controller
#define END_DEVICE_TYPE_SB_CODE             0xE1        //ϵͳ������ System Basis

//�նˣ����ͱ���============================0x3A==============================
#define END_TYPE_NULL_CODE                  0xFF        //�������
//һ������յ�------------------------------
//1.���
#define END_TYPE_CAC001_R5_CODE             0x01        //1A C401 ���R5
#define END_TYPE_CAC001_A621_CODE           0x02        //1A C402 ���A621
#define END_TYPE_CAC101_DAIKIN_CODE         0x03        //2A C401 ���DAIKIN
//2.����AC8800
#define END_TYPE_CAC002_AC8800_CODE         0x04        //1A C701 ����AC8800
//3.����
#define END_TYPE_CAC003_HITACHI_CODE        0x05        //1A C403 ����HITACHI
#define END_TYPE_CAC103_HITACHI_CODE        0x06        //2A C403 ����HITACHI
//4.�����ع�
#define END_TYPE_CAC004_MHI_CODE            0x07        //1A C404 �����ع�MHI
#define END_TYPE_CAC104_MHI_CODE            0x08        //2A C404 �����ع�MHI
//5.��֥
#define END_TYPE_CAC005_TOSHIBA_CODE        0x09        //1A C405 ��֥TOSHIBA
#define END_TYPE_CAC105_TOSHIBA_CODE        0x0A        //2A C405 ��֥TOSHIBA
//6.�����
#define END_TYPE_CAC006_HaiLourKT_CODE      0x0B        //1A C703 �����HaiLourKT
//7.
//8.����
#define END_TYPE_CAC008_Midea_CODE          0x0C        //1A C408 ����Midea
#define END_TYPE_CAC108_Midea_CODE          0x0D        //2A C408 ����Midea
//9.������
#define END_TYPE_CAC009_MAC_CODE            0x0E        //1A C409 ������MAC
//10.����
#define END_TYPE_CAC010_GREE_CODE           0x0F        //1A C40A ����GREE
//11.����
#define END_TYPE_CAC011_HaiLinKT_CODE       0x10        //1A C702 ����HaiLinKT
//12.���ά��
#define END_TYPE_CAC012_McQuay_CODE         0x11        //1A C40B ���ά��McQuay
//13.Լ��
#define END_TYPE_CAC013_York_CODE           0x12        //1A C40C Լ�˷���York
//14.
//15.����AC331
#define END_TYPE_CAC015_AC331_CODE          0x13        //1A C706 ����AC331
//16.����
#define END_TYPE_CAC016_TRANE_CODE          0x14        //1A C707 ����TRANE
//17.���͸�
#define END_TYPE_CAC017_okonoff_CODE        0x15        //1A C70C ���͸�okonoff
//������ů----------------------------------
//1.�����
#define END_TYPE_FH001_LS6_CODE             0x16        //1A C501 �����LS6
//2.����
#define END_TYPE_FH002_YiLinDN_CODE         0x17        //1A C502 ����YiLinDN
//3.����
#define END_TYPE_FH003_HsiLinDN_CODE        0x18        //1A C503 ����HsiLinDN
//������������------------------------------
//1.����˼BM205
#define END_TYPE_CM001_BM205_CODE           0x19        //1A C801 ����˼BM205
//2.��˹��DM836
#define END_TYPE_CM002_DM836_CODE           0x1A        //1A C802 ��˹��DM836
//3.��˹��AM8126
#define END_TYPE_CM003_AM8126_CODE          0x1B        //1A C803 ��˹��AM8126
//4.��˹��AM8230
#define END_TYPE_CM004_AM8230_CODE          0x1C        //1A C804 ��˹��AM8230
//5.��������
#define END_TYPE_CM005_AVR_X4000_CODE       0x1D        //1A C805 ��������AVR-X4000
//6.����BA56X
#define END_TYPE_CM006_BA56X_CODE           0x1E        //1A C806 ��������BA56X
//7.¬��Nuvo
#define END_TYPE_CM007_NV_E4GM_CODE         0x1F        //1A C807 Nuvo����NV-E4GM
//8.����˼BM206
#define END_TYPE_CM008_BM206_CODE           0x20        //1A C808 ����˼BM206
//9.��תYZ200
#define END_TYPE_CM009_YZ200_CODE           0x21        //1A C809 ��תYZ200
//10.����TY101
#define END_TYPE_CM010_TY101_CODE           0x22        //1A C80A ����TY101
//11.��˹��DM838
#define END_TYPE_CM011_DM838_CODE           0x23        //1A C80B ��˹��DM838
//12.��˹��AM8318
#define END_TYPE_CM012_AM8318_CODE          0x24        //1A C80C ��˹��AM8318
//13.��˹��DM836II
#define END_TYPE_CM013_DM836II_CODE         0x39        //1A C80D ��˹��DM836II
//14.�ƴ�Yodar
#define END_TYPE_CM014_YODAR_CODE           0x3A        //1A C80E �ƴ�Yodar
//�ġ�����----------------------------------
//1.�˰�
#define END_TYPE_LK001_LK800_CODE           0x25        //1A C601 �˰�LK800
//2.���ްͿ�
#define END_TYPE_LK002_pbk_CODE             0x26        //1A C602 ���ްͿ�pbk
//3.Ү³
#define END_TYPE_LK003_yale_CODE            0x27        //1A C603 Ү³yale
//4.����ʿ
#define END_TYPE_LK004_holish_CODE          0x28        //1A C604 ����ʿholish
//5.����
#define END_TYPE_LK005_ThinkYale_CODE       0x29        //1B E605 ����Ү³ThinkYale
//�塢����/���¼�----------------------------------
//1.����
#define END_TYPE_EM001_Dooya_CODE           0x2A        //1A CA01 ����Dooya
//2.����
#define END_TYPE_EM002_LBest_CODE           0x2B        //1A CA02 ����LBest
//��������/��ɫ-----------------------------
//1.����
#define END_TYPE_CR001_TG01_CODE            0x2C        //1A C901 TG01
//2.��ɫ
#define END_TYPE_CR002_TS01_CODE            0x2D        //1A C902 TS01
//�ߡ���������------------------------------
//1.�����Ƕ�
#define END_TYPE_EA001_B3_CODE              0x2E        //1A CC01 �����Ƕ�B3
//�ˡ�����----------------------------------
//1.������ˮ��
#define END_TYPE_EWG001_LXSY_25E_CODE       0x2F        //1A CB01 ������LXSY-25E
//2.������
#define END_TYPE_EWG002_MC7200_CODE         0x30        //1A CB02 ����MC7200
//3.ʩ�͵µ��
#define END_TYPE_EWG003_PM800_CODE          0x31        //1A CB03 ʩ�͵�PM800
//�š�����----------------------------------
//3.����
#define END_TYPE_BC003_THB_240_CODE         0x32        //1A C201 THB-240
//ʮ�������·�------------------------------
//1.����ɭ
#define END_TYPE_CFA001_HOODSON_CODE        0x33        //1A C704 HOODSON
//2.������
#define END_TYPE_CFA002_Lorelei_CODE        0x34        //1A C705 Lorelei
//3.����
#define END_TYPE_CFA003_NATHER_CODE         0x35        //1A C708 NATHER
//4.�����
#define END_TYPE_CFA004_menredXF_CODE       0x36        //1A C709 menredXF
//5.��˼��
#define END_TYPE_CFA005_LOWNSWELL_CODE      0x37        //1A C70A LOWNSWELL
//6.����
#define END_TYPE_CFA006_BROAN_CODE          0x38        //1A C70B BROAN

//�նˣ���Ʒ����============================0x016A==============================
#define END_MODEL_X_ROAD_NULL_CODE          0xFFFF      //�������
//һ������յ�------------------------------
//1.���
#define END_MODEL_CAC001_ROAD_09_CODE       0x0101      //THK 091A C401 ���R5 9·
#define END_MODEL_CAC001_ROAD_04_CODE       0x0143      //THK 041A C402 ���A621 4· 
#define END_MODEL_CAC001_ROAD_08_CODE       0x0102      //THK 081A C402 ���A621 8· 
#define END_MODEL_CAC001_ROAD_16_CODE       0x0103      //THK 161A C402 ���A621 16·
#define END_MODEL_CAC001_ROAD_32_CODE       0x013D      //THK 321A C402 ���A621 32·
#define END_MODEL_CAC001_ROAD_64_CODE       0x0140      //THK 641A C402 ���A621 64·
#define END_MODEL_CAC101_ROAD_04_CODE       0x0147      //THK 042A C401 ���DAIKIN 4· 
#define END_MODEL_CAC101_ROAD_08_CODE       0x0148      //THK 082A C401 ���DAIKIN 8· 
#define END_MODEL_CAC101_ROAD_16_CODE       0x0149      //THK 162A C401 ���DAIKIN 16·
#define END_MODEL_CAC101_ROAD_32_CODE       0x014A      //THK 322A C401 ���DAIKIN 32·
#define END_MODEL_CAC101_ROAD_64_CODE       0x014B      //THK 642A C401 ���DAIKIN 64·
//1-2.���mini
#define END_MODEL_CAC102_ROAD_16_CODE       0x0166      //THK 162A C402 ���DAIKIN mini 16·
//2.����AC8800
#define END_MODEL_CAC002_ROAD_04_CODE       0x011C      //THK 041A C701 ����AC8800 4·
#define END_MODEL_CAC002_ROAD_08_CODE       0x011D      //THK 081A C701 ����AC8800 8·
#define END_MODEL_CAC002_ROAD_16_CODE       0x011E      //THK 161A C701 ����AC8800 16·
//3.����
#define END_MODEL_CAC003_ROAD_04_CODE       0x0142      //THK 041A C403 ����HITACHI 4·
#define END_MODEL_CAC003_ROAD_08_CODE       0x0104      //THK 081A C403 ����HITACHI 8·
#define END_MODEL_CAC003_ROAD_16_CODE       0x0105      //THK 161A C403 ����HITACHI 16·
#define END_MODEL_CAC103_ROAD_08_CODE       0x0158      //THK 082A C403 ����HITACHI 8·
#define END_MODEL_CAC103_ROAD_16_CODE       0x0159      //THK 162A C403 ����HITACHI 16·
//4.�����ع�
#define END_MODEL_CAC004_ROAD_04_CODE       0x0106      //THK 041A C404 �����ع�MHI 4·
#define END_MODEL_CAC004_ROAD_08_CODE       0x0107      //THK 081A C404 �����ع�MHI 8·
#define END_MODEL_CAC004_ROAD_16_CODE       0x0108      //THK 161A C404 �����ع�MHI 16·
#define END_MODEL_CAC004_ROAD_32_CODE       0x013F      //THK 321A C404 �����ع�MHI 32·
#define END_MODEL_CAC104_ROAD_04_CODE       0x015B      //THK 042A C404 �����ع�MHI 4·
#define END_MODEL_CAC104_ROAD_08_CODE       0x015C      //THK 082A C404 �����ع�MHI 8·
#define END_MODEL_CAC104_ROAD_16_CODE       0x015D      //THK 162A C404 �����ع�MHI 16·
#define END_MODEL_CAC104_ROAD_32_CODE       0x015E      //THK 322A C404 �����ع�MHI 32·
//5.��֥
#define END_MODEL_CAC005_ROAD_08_CODE       0x0109      //THK 081A C405 ��֥TOSHIBA 8·
#define END_MODEL_CAC005_ROAD_16_CODE       0x010A      //THK 161A C405 ��֥TOSHIBA 16·
#define END_MODEL_CAC105_ROAD_08_CODE       0x0156      //THK 082A C405 ��֥TOSHIBA 8·
#define END_MODEL_CAC105_ROAD_16_CODE       0x0157      //THK 162A C405 ��֥TOSHIBA 16·
//6.�����
#define END_MODEL_CAC006_ROAD_08_CODE       0x013E      //THK 081A C703 �����HaiLourKT 8·
//7.
//8.����
#define END_MODEL_CAC008_ROAD_08_CODE       0x010B      //THK 081A C408 ����Midea 8·
#define END_MODEL_CAC008_ROAD_16_CODE       0x010C      //THK 161A C408 ����Midea 16·
#define END_MODEL_CAC008_ROAD_64_CODE       0x010D      //THK 641A C408 ����Midea 64·
#define END_MODEL_CAC108_ROAD_08_CODE       0x0162      //THK 082A C408 ����Midea 8·
#define END_MODEL_CAC108_ROAD_16_CODE       0x0163      //THK 162A C408 ����Midea 16·
//9.������
#define END_MODEL_CAC009_ROAD_04_CODE       0x014C      //THK 041A C409 ������MAC 4·
#define END_MODEL_CAC009_ROAD_08_CODE       0x010E      //THK 081A C409 ������MAC 8·
#define END_MODEL_CAC009_ROAD_16_CODE       0x010F      //THK 161A C409 ������MAC 16·
#define END_MODEL_CAC109_ROAD_08_CODE       0x0169      //THK 082A C409 ������MAC 8·
#define END_MODEL_CAC109_ROAD_16_CODE       0x016A      //THK 162A C409 ������MAC 16·
//10.����
#define END_MODEL_CAC010_ROAD_08_CODE       0x0110      //THK 081A C40A ����GREE 8·
#define END_MODEL_CAC010_ROAD_16_CODE       0x0111      //THK 161A C40A ����GREE 16·
//11.����
#define END_MODEL_CAC011_ROAD_08_CODE       0x013B      //THK 081A C702 ����HaiLinKT 8·
//12.���ά��
#define END_MODEL_CAC012_ROAD_08_CODE       0x0112      //THK 081A C40B ���ά��McQuay 8·
#define END_MODEL_CAC012_ROAD_16_CODE       0x0113      //THK 161A C40B ���ά��McQuay 16·
//13.Լ��
#define END_MODEL_CAC013_ROAD_16_CODE       0x0139      //THK 161A C40C Լ�˷���York 16·
//14.
//15.����AC331
#define END_MODEL_CAC015_ROAD_04_CODE       0x014E      //THK 041A C706 ����AC331 4·
#define END_MODEL_CAC015_ROAD_08_CODE       0x014F      //THK 081A C706 ����AC331 8·
#define END_MODEL_CAC015_ROAD_16_CODE       0x0150      //THK 161A C706 ����AC331 16·
//16.����
#define END_MODEL_CAC016_ROAD_08_CODE       0x0152      //THK 081A C707 ����TRANE 8·
//17.���͸�
#define END_MODEL_CAC017_ROAD_08_CODE       0x0164      //THZ 081A C70C ���͸�okonoff 8·
//������ů----------------------------------
//1.�����
#define END_MODEL_FH001_ROAD_07_CODE        0x0114      //THK 071A C501 �����LS6 7·
//2.����
#define END_MODEL_FH002_ROAD_04_CODE        0x0155      //THK 041A C502 ����YiLinDN 4·
#define END_MODEL_FH002_ROAD_08_CODE        0x0115      //THK 081A C502 ����YiLinDN 8·
#define END_MODEL_FH002_ROAD_16_CODE        0x0116      //THK 161A C502 ����YiLinDN 16·
//3.����
#define END_MODEL_FH003_ROAD_04_CODE        0x014D      //THK 041A C503 ����HsiLinDN 4·
#define END_MODEL_FH003_ROAD_08_CODE        0x013C      //THK 081A C503 ����HsiLinDN 8·
//������������------------------------------
//1.����˼BM205
#define END_MODEL_CM001_ROAD_04_CODE        0x011F      //THY 041A C801 ����˼BM205 4·
//2.��˹��DM836
#define END_MODEL_CM002_ROAD_04_CODE        0x0121      //THY 041A C802 ��˹��DM836 4·
//3.��˹��AM8126
#define END_MODEL_CM003_ROAD_04_CODE        0x0123      //THY 041A C803 ��˹��AM8126 4·
#define END_MODEL_CM003_ROAD_08_CODE        0x0124      //THY 081A C803 ��˹��AM8126 8·
//4.��˹��AM8230
#define END_MODEL_CM004_ROAD_04_CODE        0x0125      //THY 041A C804 ��˹��AM8230 4·
#define END_MODEL_CM004_ROAD_08_CODE        0x0126      //THY 081A C804 ��˹��AM8230 8·
//5.��������
#define END_MODEL_CM005_ROAD_01_CODE        0x0127      //THY 011A C805 ��������AVR-X4000 1·
//6.����BA56X
#define END_MODEL_CM006_ROAD_04_CODE        0x0128      //THY 041A C806 ��������BA56X 4·
//7.¬��Nuvo
#define END_MODEL_CM007_ROAD_04_CODE        0x0129      //THY 041A C807 Nuvo����NV-E4GM 4·
//8.����˼BM206
#define END_MODEL_CM008_ROAD_04_CODE        0x012A      //THY 041A C808 ����˼BM206 4·
#define END_MODEL_CM008_ROAD_08_CODE        0x012B      //THY 081A C808 ����˼BM206 8·
//9.��תYZ200
#define END_MODEL_CM009_ROAD_04_CODE        0x012C      //THY 041A C809 ��תYZ200 4·
#define END_MODEL_CM009_ROAD_08_CODE        0x012D      //THY 081A C809 ��תYZ200 8·
//10.����TY101
#define END_MODEL_CM010_ROAD_04_CODE        0x012E      //THY 041A C80A ����TY101 4·
#define END_MODEL_CM010_ROAD_08_CODE        0x012F      //THY 081A C80A ����TY101 8·
//11.��˹��DM838
#define END_MODEL_CM011_ROAD_04_CODE        0x013A      //THY 041A C80B ��˹��DM838 4·
//12.��˹��AM8318
#define END_MODEL_CM012_ROAD_08_CODE        0x0145      //THY 081A C80C ��˹��AM8318 8·
//13.��˹��DM836II
#define END_MODEL_CM013_ROAD_04_CODE        0x0122      //THY 041A C80D ��˹��DM836II 4·
//14.�ƴ�Yodar
#define END_MODEL_CM014_ROAD_04_CODE        0x0120      //THY 041A C80E �ƴ�Yodar 4·
//�ġ�����----------------------------------
//1.�˰�
#define END_MODEL_LK001_ROAD_04_CODE        0x0117      //THS 041A C601 �˰�LK800 4·
//2.���ްͿ�
#define END_MODEL_LK002_ROAD_04_CODE        0x0118      //THS 041A C602 ���ްͿ�pbk 4·
//3.Ү³
#define END_MODEL_LK003_ROAD_01_CODE        0x0119      //THS 011A C603 Ү³yale 1·
//4.����ʿ
#define END_MODEL_LK004_ROAD_04_CODE        0x011A      //THS 041A C604 ����ʿholish 4·
//5.����
#define END_MODEL_LK005_ROAD_01_CODE        0x011B      //THS 011B E605 ����Ү³ThinkYale 1·
//�塢����/���¼�----------------------------------
//1.����
#define END_MODEL_EM001_ROAD_04_CODE        0x0133      //THC 041A CA01 ����Dooya 4·
#define END_MODEL_EM001_ROAD_08_CODE        0x0134      //THC 081A CA01 ����Dooya 8·
#define END_MODEL_EM001_ROAD_16_CODE        0x0135      //THC 161A CA01 ����Dooya 16·
//2.����
#define END_MODEL_EM002_ROAD_04_CODE        0x0151      //THC 041A CA02 ����LBest 4·
//��������/��ɫ-----------------------------
//1.����
#define END_MODEL_CR001_ROAD_04_CODE        0x0130      //THL 041A C901 TG01 4·
#define END_MODEL_CR001_ROAD_12_CODE        0x0131      //THL 121A C901 TG01 12·
//2.��ɫ
#define END_MODEL_CR002_ROAD_04_CODE        0x0132      //THL 041A C902 TS01 4·
//�ߡ���������------------------------------
//1.�����Ƕ�
#define END_MODEL_EA001_ROAD_04_CODE        0x0141      //THE 041A CC01 �����Ƕ�B3 4·
#define END_MODEL_EA001_ROAD_08_CODE        0x0137      //THE 081A CC01 �����Ƕ�B3 8·
//�ˡ�����----------------------------------
//1.������ˮ��
#define END_MODEL_EWG001_ROAD_16_CODE       0x0136      //THW 161A CB01 ������LXSY-25E 16·
//2.������
#define END_MODEL_EWG002_ROAD_32_CODE       0x015A      //THW 321A CB02 ����MC7200 32·
//3.ʩ�͵µ��
#define END_MODEL_EWG003_ROAD_32_CODE       0x0160      //THW 321A CB03 ʩ�͵�PM800 32·
//4.������
#define END_MODEL_EWG004_ROAD_04_CODE       0x0165      //THW 041A CB04 ����D866 4·
//�š�����----------------------------------
//3.����
#define END_MODEL_BC003_ROAD_240_CODE       0x0138      //THB 241A C201 THB-240 240·
//ʮ�������·�------------------------------
//1.����ɭ
#define END_MODEL_CFA001_ROAD_08_CODE       0x0144      //THF 081A C704 HOODSON 8·
//2.������
#define END_MODEL_CFA002_ROAD_08_CODE       0x0146      //THF 081A C705 Lorelei 8·
//3.����
#define END_MODEL_CFA003_ROAD_08_CODE       0x0153      //THF 081A C708 NATHER 8·
//4.�����
#define END_MODEL_CFA004_ROAD_08_CODE       0x0154      //THF 081A C709 menredXF 8·
//5.��˼��
#define END_MODEL_CFA005_ROAD_04_CODE       0x015F      //THF 041A C70A LOWNSWELL 4·
//6.����
#define END_MODEL_CFA006_ROAD_01_CODE       0x0161      //THF 011A C70B BROAN 1·

//�ն�·��======================================================================
#define END_ROAD_NUM_00_CODE                0x00        //��0·
#define END_ROAD_NUM_01_CODE                0x01        //��1·
#define END_ROAD_NUM_04_CODE                0x04        //��4·
#define END_ROAD_NUM_05_CODE                0x05        //��5·
#define END_ROAD_NUM_07_CODE                0x07        //��7·
#define END_ROAD_NUM_08_CODE                0x08        //��8·
#define END_ROAD_NUM_09_CODE                0x09        //��9·
#define END_ROAD_NUM_12_CODE                0x12        //��12·
#define END_ROAD_NUM_16_CODE                0x16        //��16·
#define END_ROAD_NUM_24_CODE                0x24        //��24·
#define END_ROAD_NUM_32_CODE                0x32        //��32·
#define END_ROAD_NUM_50_CODE                0x50        //��50·
#define END_ROAD_NUM_64_CODE                0x64        //��64·

#define END_START_ROAD_01_CODE              0x01        //��·����ʼ01·

//==============================================================================
//����ָ��
#define END_OK_CODE                         0xEF        //��ȷ��
#define END_CHECK_CODE                      0xED        //�����
#define END_ERROR_CODE                      0xEE        //������

//˫����ָ��
#define END_CLOSE_CODE                      0x00        //�ն��豸�ر�
#define END_OPEN_CODE                       0xFF        //�ն��豸��

//������ָ��
#define END_STOP_CODE                       0x00        //�ն��豸ֹͣ
#define END_FORWARD_CODE                    0x01        //�ն��豸ǰ��
#define END_BACKWARD_CODE                   0x02        //�ն��豸����

//���ݲ���ָ��
#define END_POSITIVE_CODE                   0x00        //����
#define END_NEGATIVE_CODE                   0x01        //����
#define END_ZERO_CODE                       0x00        //����λΪ0
#define END_ONE_CODE                        0x01        //����λΪ1
#define END_TWO_CODE                        0x02        //����λΪ2
#define END_THREE_CODE                      0x03        //����λΪ3
#define END_FOUR_CODE                       0x04        //����λΪ4
#define END_FIVE_CODE                       0x05        //����λΪ5
#define END_TEN_CODE                        0x0A        //����λΪ10
#define END_FULL_CODE                       0xFFFF      //����λΪ��ֵ

#define END_START_ROAD_01_CODE              0x01        //��·����ʼ01·

//�նˣ�����������ָ��
#define END_TRIGGER_CODE                    0x01        //�ն˴���1��
#define END_TRIGGER_DOUBLE_CODE             0x02        //�ն���������2��
#define END_TRIGGER_TRI_CODE                0x03        //�ն���������3��
#define END_TRIGGER_FORTH_CODE              0x04        //�ն���������4��
#define END_TRIGGER_FIFTH_CODE              0x05        //�ն���������5��
#define END_TRIGGER_SIXTH_CODE              0x06        //�ն���������6��
#define END_TRIGGER_TENTH_CODE              0x0A        //�ն���������10��
#define END_TRIGGER_ST_LONG_CODE            0xF0        //�ն�������ʱ�䴥��
#define END_TRIGGER_NR_LONG_CODE            0xFD        //�ն�������ʱ�䴥��
#define END_TRIGGER_EX_LONG_CODE            0xFF        //�ն���������ʱ�䴥��
#define END_UNTRIGGER_CODE                  0x00        //�ն�״̬����

//����
#define KEY_STYLE_TOP_KEYBOARD_CODE         0x01        //���尴������
#define KEY_STYLE_NORMAL_CODE               0x02        //��ͨ��������

//����
#define BELL_RING_MODE_01_CODE              0x01        //��������
#define BELL_RING_MODE_05_CODE              0x05        //��������

//�ն�==========================================================================
#define NO_DEAL_RESULT_CODE                 0xFF
#define END_DEVICE_HOST_ADDR_CODE           0x00        //������ַ
#define END_DEVICE_B_ADDR_CODE              0x01        //�ӻ�B��ַ���̵���2
#define END_DEVICE_C_ADDR_CODE              0x02        //�ӻ�C��ַ���̵���3
#define END_DEVICE_D_ADDR_CODE              0x03        //�ӻ�D��ַ���̵���4
#define END_DEVICE_E_ADDR_CODE              0x04        //�ӻ�E��ַ���̵���5
#define END_DEVICE_F_ADDR_CODE              0x05        //�ӻ�F��ַ�����ߴ���1
#define END_DEVICE_G_ADDR_CODE              0x06        //�ӻ�G��ַ�����ߴ���2
#define END_DEVICE_H_ADDR_CODE              0x07        //�ӻ�H��ַ�����ߴ���3
#define END_DEVICE_ALL_ADDR_CODE            0x40        //���дӻ���ַ
#define END_DEVICE_ALL_ROAD_CODE            0xFF        //����·��

//ָʾ��
#define END_LED_POWER_OFF_CODE              0x00        //ָʾ�ƹر�
#define END_LED_POWER_ON_CODE               0xFF        //ָʾ�ƴ�

#define END_LED_ROAD_01_CODE                0x01        //ָʾ�Ƶ�1·
#define END_LED_ROAD_02_CODE                0x02        //ָʾ�Ƶ�2·
#define END_LED_ROAD_03_CODE                0x03        //ָʾ�Ƶ�3·
#define END_LED_ROAD_04_CODE                0x04        //ָʾ�Ƶ�4·
#define END_LED_ROAD_05_CODE                0x05        //ָʾ�Ƶ�5·
#define END_LED_ROAD_06_CODE                0x06        //ָʾ�Ƶ�6·
#define END_LED_ROAD_07_CODE                0x07        //ָʾ�Ƶ�7·
#define END_LED_ROAD_08_CODE                0x08        //ָʾ�Ƶ�8·
#define END_LED_ROAD_09_CODE                0x09        //ָʾ�Ƶ�9·
#define END_LED_ROAD_10_CODE                0x0A        //ָʾ�Ƶ�10·
#define END_LED_ROAD_11_CODE                0x0B        //ָʾ�Ƶ�11·
#define END_LED_ROAD_12_CODE                0x0C        //ָʾ�Ƶ�12·
#define END_LED_ROAD_13_CODE                0x0D        //ָʾ�Ƶ�13·
#define END_LED_ROAD_14_CODE                0x0E        //ָʾ�Ƶ�14·
#define END_LED_ROAD_15_CODE                0x0F        //ָʾ�Ƶ�15·
#define END_LED_ROAD_16_CODE                0x10        //ָʾ�Ƶ�16·
#define END_LED_ROAD_ALL_CODE               0x00        //ָʾ��

//�նˣ�ϵͳ������===============================================================
#define END_SB_ONLINE_STATUS_CODE           0x21        //����״̬��
#define END_SB_OVERTIME_STATUS_CODE         0x22        //��ʱ״̬��
#define END_SB_LOCK_SET_CODE                0xF1        //��������
#define END_SB_OVERTIME_SET_CODE            0xF2        //��ʱ���ã�����
#define END_SB_LED_MODE_SET_CODE            0xF3        //ָʾ�ƹ���ģʽ����

//1.����״̬
#define END_SB_ONLINE_ON_CODE               0x01        //����
#define END_SB_ONLINE_OFF_CODE              0x00        //����
//2.��ʱ״̬
#define END_SB_OVERTIME_RESTORE_CODE        0x00        //��ʱ�ָ�/�޳�ʱ
#define END_SB_OVERTIME_ALARM_CODE          0x01        //��ʱ
//3.��������
#define END_SB_LOCK_ON_CODE                 0x01        //����/ȫ��
#define END_SB_LOCK_OFF_CODE                0x00        //����/����
//4.ָʾ�ƹ���ģʽ����
#define END_SB_LED_MODE_OFF_CODE            0x00        //ָʾ�ƹر�
#define END_SB_LED_MODE_ON_CODE             0xFF        //ָʾ�ƴ�
#define END_SB_LED_MODE_01_CODE             0x01        //ָʾ��ģʽ1
#define END_SB_LED_MODE_02_CODE             0x02        //ָʾ��ģʽ2
#define END_SB_LED_MODE_03_CODE             0x03        //ָʾ��ģʽ3
#define END_SB_LED_MODE_04_CODE             0x04        //ָʾ��ģʽ4
#define END_SB_LED_MODE_05_CODE             0x05        //ָʾ��ģʽ5
#define END_SB_LED_MODE_06_CODE             0x06        //ָʾ��ģʽ6

//�նˣ�ϵͳ����
#define END_SB_ROAD_01_CODE                 0x01        //ϵͳ������01·

//�նˣ�����ʽ�̵�����==========================================================
#define END_SR_POWER_STATUS_CODE            0x10        //��Դ״̬

#define END_SR_POWER_OFF_CODE               0x00        //��Դ�ر�
#define END_SR_POWER_ON_CODE                0xFF        //��Դ��

        //(1-16):THP-H16, THP-S16
#define END_SR_ROAD_ALL_CODE                0x00        //�̵�������·
#define END_SR_ROAD_01_CODE                 0x01        //�̵�����1·
#define END_SR_ROAD_02_CODE                 0x02        //�̵�����2·
#define END_SR_ROAD_03_CODE                 0x03        //�̵�����3·
#define END_SR_ROAD_04_CODE                 0x04        //�̵�����4·
#define END_SR_ROAD_05_CODE                 0x05        //�̵�����5·
#define END_SR_ROAD_06_CODE                 0x06        //�̵�����6·
#define END_SR_ROAD_07_CODE                 0x07        //�̵�����7·
#define END_SR_ROAD_08_CODE                 0x08        //�̵�����8·
#define END_SR_ROAD_09_CODE                 0x09        //�̵�����9·
#define END_SR_ROAD_10_CODE                 0x0A        //�̵�����10·
#define END_SR_ROAD_11_CODE                 0x0B        //�̵�����11·
#define END_SR_ROAD_12_CODE                 0x0C        //�̵�����12·
#define END_SR_ROAD_13_CODE                 0x0D        //�̵�����13·
#define END_SR_ROAD_14_CODE                 0x0E        //�̵�����14·
#define END_SR_ROAD_15_CODE                 0x0F        //�̵�����15·
#define END_SR_ROAD_16_CODE                 0x10        //�̵�����16·
#define END_SR_ROAD_17_CODE                 0x11        //�̵�����17·
#define END_SR_ROAD_18_CODE                 0x12        //�̵�����18·
#define END_SR_ROAD_19_CODE                 0x13        //�̵�����19·
				//(65-6D):THZ-S15
#define END_SR_ROAD_Z01_CODE                0x65        //�̵�����1·

//�նˣ��ɵ���ʽ�̵�����========================================================
#define END_CR_POWER_LEVEL_CODE             0x10        //��Դ�ȼ���0x00~0x64
#define END_CR_ONLINE_STATUS_CODE           0x11        //�ɵ�������״̬��
#define END_CR_MODE_STYLE_CODE              0x20        //ģʽ����
#define END_CR_OVERLOAD_STATUS_CODE         0x30        //���ر���

//1.��Դ����(0~100)
#define END_CR_POWER_OFF_CODE               0xFF        //��Դ�ر�
//2.����״̬
#define END_CR_OFFLINE_CODE                 0x00        //�ɵ��Ƶ�����
#define END_CR_ONLINE_CODE                  0x01        //�ɵ���������
//3.ģʽ����
//4.���ر���
#define END_CR_OVERLOAD_RESTORE_CODE        0x00        //�������
#define END_CR_OVERLOAD_PROTECT_CODE        0x01        //���ر���

#define END_CR_ROAD_01_CODE                 0x01        //�ɵ��Ƶ�1·
#define END_CR_ROAD_09_CODE                 0x09        //�ɵ��Ƶ�9·
#define END_CR_ROAD_12_CODE                 0x0C        //�ɵ��Ƶ�12·

//�նˣ�����������============================================================
#define END_EWG_ONLINE_STATUS_CODE          0x20        //����״̬
#define END_EWG_ACTIVE_POWER_CODE           0x11        //��ǰ����W��ȫ���й�����ƽ��ֵ��
#define END_EWG_POWER_CONSUM_CODE           0x12        //�õ���kWh����100�����ɲ�ѯ��
#define END_EWG_VOLTAGE_CODE                0x13        //��ѹV����100����ȫ����ѹ��Чƽ��ֵ��
#define END_EWG_CURRENT_CODE                0x14        //����A����100����ȫ��������Чƽ��ֵ��
#define END_EWG_FREQUENCY_CODE              0x15        //Ƶ��Hz����100����Ƶ����ƽ��ֵ��
#define END_EWG_REACTIVE_POWER_CODE         0x16        //�޹�����W��ȫ���޹�����ƽ��ֵ��
#define END_EWG_APPARENT_POWER_CODE         0x17        //���ڹ���VA
#define END_EWG_POWER_FACTOR_CODE           0x18        //��������PF����100��
#define END_EWG_TRI_VOLTAGE_CODE            0x19        //�����ѹV����100����ȫ����ѹ��Чƽ��ֵ��
#define END_EWG_TRI_CURRENT_CODE            0x1A        //�������A����100����ȫ��������Чƽ��ֵ��
#define END_EWG_WATER_CONSUM_CODE           0x30        //��ˮ��m3����100�����ɲ�ѯ��
#define END_EWG_VALVE_STATUS_CODE           0x31        //����״̬
#define END_EWG_LEAK_STATUS_CODE            0x32        //й©״̬
#define END_EWG_ERROR_ALARM_CODE            0xF0        //���ϱ���
#define END_EWG_OVERLOAD_STATUS_CODE        0xF1        //���ر���״̬
#define END_EWG_LIMIT_STATUS_CODE           0xF2        //���ޱ���״̬
#define END_EWG_OVERLOAD_VALUE_SET_CODE     0xB0        //��������
#define END_EWG_LIMIT_LOWER_SET_CODE        0xB1        //����ֵ����
#define END_EWG_LIMIT_UPPER_SET_CODE        0xB2        //����ֵ����
#define END_EWG_LIMIT_ACT_SET_CODE          0xB3        //���޶�������
#define END_EWG_POWER_RATIO_SET_CODE        0xB4        //�����ֵ����

//1.����״̬
#define END_EWG_OFFLINE_CODE                0x00        //������
#define END_EWG_ONLINE_CODE                 0x01        //����
//10.�����ѹ
//11.�������
#define END_EWG_TRI_PHASE_A_CODE            0x01        //A��
#define END_EWG_TRI_PHASE_B_CODE            0x02        //B��
#define END_EWG_TRI_PHASE_C_CODE            0x03        //C��
//13.����״̬
#define END_EWG_VALVE_CLOSE_CODE            0x00        //���Źر�
#define END_EWG_VALVE_OPEN_CODE             0x01        //���Ŵ�
//14.й©״̬
#define END_EWG_LEAK_OFF_CODE               0x00        //����
#define END_EWG_LEAK_ON_CODE                0x01        //й©
//15.���ϱ���
#define END_EWG_ERROR_COMM_CODE             0x01        //ͨ�Ź���
//16.���ر���
#define END_EWG_OVERLOAD_RESTORE_CODE       0x00        //�������
#define END_EWG_OVERLOAD_PROTECT_CODE       0x01        //���ر���
//17.���ޱ���
#define END_EWG_LIMIT_RESTORE_CODE          0x00        //�������
#define END_EWG_LIMIT_LOWER_CODE            0x01        //���ޱ���
#define END_EWG_LIMIT_UPPER_CODE            0x02        //���ޱ���
//21.���޶���
#define END_EWG_LIMIT_ACT_NONE_CODE         0x00        //������
#define END_EWG_LIMIT_ACT_REPORT_CODE       0x01        //���ϱ�
#define END_EWG_LIMIT_ACT_ACTION_CODE       0x02        //�������ϱ�

#define END_EWG_ROAD_01_CODE                0x01        //�����1·

//�նˣ���������ѧϰ��ָ��======================================================
#define END_OPERATING_CODE                  0x31        //����ָ��
#define END_LEARNING_CODE                   0x32        //ѧϰָ��
        //(1-10):THR-S10
        //(1-5):THR-S5
        //(1-F):THZ-S15
#define END_IR_ROAD_01_CODE                 0x01        //ѧϰ�ͺ����1·
#define END_IR_ROAD_05_CODE                 0x05        //ѧϰ�ͺ����5·
#define END_IR_ROAD_10_CODE                 0x0A        //ѧϰ�ͺ����10·
#define END_IR_ROAD_15_CODE                 0x0F        //ѧϰ�ͺ����15·
        //(11-20):THR-S10, THR-S5
#define END_WR_ROAD_01_CODE                 0x0B        //ѧϰ�����ߵ�1·
#define END_WR_ROAD_05_CODE                 0x0F        //ѧϰ�����ߵ�5·
#define END_WR_ROAD_10_CODE                 0x14        //ѧϰ�����ߵ�10·
        //(29-37):THZ-S15
#define END_WR_ROAD_Z01_CODE                0x29        //ѧϰ�����ߵ�1·

//�նˣ�����ʽ��������==========================================================
#define END_TR_TRIGGER_STATUS_CODE          0x10        //����״̬
#define END_TR_ONLINE_STATUS_CODE           0x11        //����״̬
#define END_TR_POWER_STATUS_CODE            0x12        //���ػ�״̬
#define END_TR_DEFENSE_STATUS_CODE          0x13        //������״̬
#define END_TR_SENDER_POWER_CODE            0x20        //���Ͷ˵���״̬
#define END_TR_SENCEIVER_POWER_CODE         0x21        //���Ͷ˵���״̬
#define END_TR_SENDER_BATTERY_CODE          0x30        //���Ͷ˵��״̬
#define END_TR_SENCEIVER_BATTERY_CODE       0x31        //���Ͷ˵��״̬
#define END_TR_LIGHT_INTERF_CODE            0x40        //ǿ�����
#define END_TR_IR_ALIGN_STATUS_CODE         0x50        //�����߶���״̬
#define END_TR_OTHER_ALARM_CODE             0x60        //��������
#define END_TR_BINDING_CODE                 0xB0        //����/��������

//1.����״̬
#define END_TRIGGER_CODE                    0x01        //����
#define END_UNTRIGGER_CODE                  0x00        //������ʧ
//2.����״̬
#define END_TR_ONLINE_CODE                  0x01        //����
#define END_TR_OFFLINE_CODE                 0x00        //������
//3.���ػ�״̬
#define END_TR_POWER_ON_CODE                0x01        //����
#define END_TR_POWER_OFF_CODE               0x00        //�ػ�
//4.������״̬
#define END_TR_DEFENSE_ON_CODE              0x01        //����
#define END_TR_DEFENSE_OFF_CODE             0x00        //����
//5.���Ͷ˵���״̬(0~100)
#define END_TR_SPOWER_OK_CODE               0xFF        //���Ͷ˵�������
#define END_TR_SPOWER_LOW_CODE              0xFE        //���Ͷ˵����͵�
//6.���Ͷ˵���״̬(0~100)
#define END_TR_SCPOWER_OK_CODE              0xFF        //���Ͷ˵�������
#define END_TR_SCPOWER_LOW_CODE             0xFE        //���Ͷ˵����͵�
//7.���Ͷ˵��״̬
#define END_TR_SBATTERY_OK_CODE             0x00        //���Ͷ˵������
#define END_TR_SBATTERY_BREAK_CODE          0x01        //���Ͷ˵����
//8.���Ͷ˵��״̬
#define END_TR_SCBATTERY_OK_CODE            0x00        //���Ͷ˵������
#define END_TR_SCBATTERY_BREAK_CODE         0x01        //���Ͷ˵����
//9.ǿ�����
#define END_TR_LIINTERF_RECOVER_CODE        0x00        //ǿ����Żָ�
#define END_TR_LIINTERF_APPEAR_CODE         0x01        //ǿ����Ų���
//10.�����߶���״̬
#define END_TR_IR_ALIGN_ON_CODE             0x00        //�������Ѷ���
#define END_TR_IR_ALIGN_OFF_CODE            0x01        //������δ����
//11.��������
#define END_TR_ALARM_TAMPER_CODE            0x01        //���𱨾�
#define END_TR_ALARM_SENDER_REBOOT_CODE     0x02        //���Ͷ���������
//12.����/��������
#define END_TR_BINDING_BIND_CODE            0x01        //����
#define END_TR_BINDING_REMOVE_CODE          0x00        //����
#define END_TRIGGER_00_CODE                 0x42        //�������ص�01·
#define END_TRIGGER_01_CODE                 0x41        //������������01·

//�նˣ���ֵ�ʹ�������==========================================================
#define END_QS_ONLINE_STATUS_CODE           0x11        //����״̬��
#define END_QS_LED_SET_CODE                 0x31        //����ָʾ����
#define END_QS_THRESHOLD_01_CODE            0x32        //����������ֵһ����
#define END_QS_THRESHOLD_02_CODE            0x33        //����������ֵ������
#define END_QS_ADJUST_SET_CODE              0x34        //����ƫֵ����

#define END_QS_TEMP_DATA_CODE               0xA0        //�¶�����(��10)
#define END_QS_HUMI_DATA_CODE               0xA1        //ʪ������(��10)
#define END_QS_LUMI_DATA_CODE               0xA2        //���ն�����(��1)
#define END_QS_PM25_DATA_CODE               0xA3        //PM2.5����(��1)
#define END_QS_CO2_DATA_CODE                0xA4        //CO2����(��1)
#define END_QS_TVOC_DATA_CODE               0xA5        //TVOC����(��100)
#define END_QS_NOISE_DATA_CODE              0xA6        //��������(��1)

#define END_QS_TEMP_AVERAGE_CODE            0xB1        //�¶�ƽ�����ݣ�ԭֵ��
#define END_QS_HUMI_AVERAGE_CODE            0xB2        //ʪ��ƽ�����ݣ�ԭֵ��
#define END_QS_LUMI_AVERAGE_CODE            0xB3        //���ն�ƽ�����ݣ�1/100��
#define END_QS_PM25_AVERAGE_CODE            0xB4        //PM2.5ƽ�����ݣ�1/100��
#define END_QS_CO2_AVERAGE_CODE             0xB5        //CO2ƽ�����ݣ�1/100��
#define END_QS_TVOC_AVERAGE_CODE            0xB6        //TVOCƽ�����ݣ�ԭֵ��
#define END_QS_NOISE_AVERAGE_CODE           0xB7        //����ƽ�����ݣ�ԭֵ��

#define END_QS_TEMP_MEDIAN_CODE             0xC1        //�¶���λ���ݣ�ԭֵ��
#define END_QS_HUMI_MEDIAN_CODE             0xC2        //ʪ����λ���ݣ�ԭֵ��
#define END_QS_LUMI_MEDIAN_CODE             0xC3        //���ն���λ���ݣ�1/100��
#define END_QS_PM25_MEDIAN_CODE             0xC4        //PM2.5��λ���ݣ�1/100��
#define END_QS_CO2_MEDIAN_CODE              0xC5        //CO2��λ���ݣ�1/100��
#define END_QS_TVOC_MEDIAN_CODE             0xC6        //TVOC��λ���ݣ�ԭֵ��
#define END_QS_NOISE_MEDIAN_CODE            0xC7        //������λ���ݣ�ԭֵ��

//1.����״̬
#define END_QS_ONLINE_CODE                  0x01        //����
#define END_QS_OFFLINE_CODE                 0x00        //������
//2.����ָʾ����
#define END_QS_LED_OFF_CODE                 0x00        //����ָʾ�ر�
#define END_QS_LED_ON_CODE                  0xFF        //����ָʾ��
#define END_QS_LED_RESTORE_CODE             0xFE        //����ָʾ�ָ���������

//�¶�(01)
#define END_QS_ROAD_01_CODE                 0x01        //�¶ȴ�������01·
#define END_QS_ROAD_07_CODE                 0x07        //�¶ȴ�������02·
#define END_QS_ROAD_13_CODE                 0x0D        //�¶ȴ�������03·
#define END_QS_ROAD_19_CODE                 0x13        //�¶ȴ�������04·
#define END_QS_ROAD_25_CODE                 0x19        //�¶ȴ�������05·
#define END_QS_ROAD_31_CODE                 0x1F        //�¶ȴ�������06·
#define END_QS_ROAD_37_CODE                 0x25        //�¶ȴ�������07·
#define END_QS_ROAD_43_CODE                 0x2B        //�¶ȴ�������08·
//ʪ��(02)
#define END_QS_ROAD_02_CODE                 0x02        //ʪ�ȴ�������01·
#define END_QS_ROAD_08_CODE                 0x08        //ʪ�ȴ�������02·
#define END_QS_ROAD_14_CODE                 0x0E        //ʪ�ȴ�������03·
#define END_QS_ROAD_20_CODE                 0x14        //ʪ�ȴ�������04·
#define END_QS_ROAD_26_CODE                 0x1A        //ʪ�ȴ�������05·
#define END_QS_ROAD_32_CODE                 0x20        //ʪ�ȴ�������06·
#define END_QS_ROAD_38_CODE                 0x26        //ʪ�ȴ�������07·
#define END_QS_ROAD_44_CODE                 0x2C        //ʪ�ȴ�������08·
//���ն�(03)
#define END_QS_ROAD_03_CODE                 0x03        //���մ�������01·
#define END_QS_ROAD_09_CODE                 0x09        //���մ�������02·
#define END_QS_ROAD_15_CODE                 0x0F        //���մ�������03·
#define END_QS_ROAD_21_CODE                 0x15        //���մ�������04·
#define END_QS_ROAD_27_CODE                 0x1B        //���մ�������05·
#define END_QS_ROAD_33_CODE                 0x21        //���մ�������06·
#define END_QS_ROAD_39_CODE                 0x27        //���մ�������07·
#define END_QS_ROAD_45_CODE                 0x2D        //���մ�������08·
//PM2.5(04)
#define END_QS_ROAD_04_CODE                 0x04        //PM2.5��������01·
#define END_QS_ROAD_10_CODE                 0x0A        //PM2.5��������02·
#define END_QS_ROAD_16_CODE                 0x10        //PM2.5��������03·
#define END_QS_ROAD_22_CODE                 0x16        //PM2.5��������04·
#define END_QS_ROAD_28_CODE                 0x1C        //PM2.5��������05·
#define END_QS_ROAD_34_CODE                 0x22        //PM2.5��������06·
#define END_QS_ROAD_40_CODE                 0x28        //PM2.5��������07·
#define END_QS_ROAD_46_CODE                 0x2E        //PM2.5��������08·
//CO2(05)
#define END_QS_ROAD_05_CODE                 0x05        //CO2��������01·
#define END_QS_ROAD_11_CODE                 0x0B        //CO2��������02·
#define END_QS_ROAD_17_CODE                 0x11        //CO2��������03·
#define END_QS_ROAD_23_CODE                 0x17        //CO2��������04·
#define END_QS_ROAD_29_CODE                 0x1D        //CO2��������05·
#define END_QS_ROAD_35_CODE                 0x23        //CO2��������06·
#define END_QS_ROAD_41_CODE                 0x29        //CO2��������07·
#define END_QS_ROAD_47_CODE                 0x2F        //CO2��������08·
//TVOC(06)
#define END_QS_ROAD_06_CODE                 0x06        //TVOC��������01·
#define END_QS_ROAD_12_CODE                 0x0C        //TVOC��������01·
#define END_QS_ROAD_18_CODE                 0x12        //TVOC��������01·
#define END_QS_ROAD_24_CODE                 0x18        //TVOC��������01·
#define END_QS_ROAD_30_CODE                 0x1E        //TVOC��������01·
#define END_QS_ROAD_36_CODE                 0x24        //TVOC��������01·
#define END_QS_ROAD_42_CODE                 0x2A        //TVOC��������01·
#define END_QS_ROAD_48_CODE                 0x30        //TVOC��������01·

//�նˣ�������==================================================================
        //(1-218):THP-H16
        //(1-18):THP-S18
        //(1-6):THZ-S15
#define END_KEY_01_CODE                     0x01        //�ص�������01·
#define END_KEY_06_CODE                     0x06        //�ص�������06·
#define END_KEY_18_CODE                     0x12        //�ص�������18·
#define END_KEY_218_CODE                    0xDA        //�ص�������218·

//�նˣ�ң����==================================================================
#define END_RCM_BINDING_CODE                0x61        //ң������
#define END_RCM_VERIFY_CODE                 0x62        //ң����ȷ��
#define END_RCM_INVALID_CODE                0x63        //ң������Ч
#define END_RCM_CLEAN_CODE                  0x64        //ң��������

//�նˣ��綯ʽ�����============================================================
#define END_EM_ONLINE_STATUS_CODE           0x06        //��������״̬
#define END_EM_SWITCH_CTRL_CODE             0x15        //�������ؿ���
#define END_EM_ANGLE_CTRL_CODE              0x25        //�����Ƕȿ���
#define END_EM_LIGHT_CTRL_CODE              0x08        //���¼���������
#define END_EM_DRTING_CTRL_CODE             0x09        //���¼ܺ�ɿ���
#define END_EM_AIR_DRY_CTRL_CODE            0x0A        //���¼ܷ�ɿ���
#define END_EM_DISINFECT_CTRL_CODE          0x0B        //���¼���������
#define END_EM_ANION_CTRL_CODE              0x0C        //���¼ܸ����ӿ���
#define END_EM_CURTAIN_STYLE_CODE           0x95        //������������
#define END_EM_ADDR_SET_CODE                0xA5        //������ַ����
#define END_EM_REVERSE_SET_CODE             0xB5        //������������
#define END_EM_HAND_SET_CODE                0xC5        //������������
#define END_EM_RANGE_SET_CODE               0xD5        //�����г�����
#define END_EM_ANGLE_COEF_SET_CODE          0xE5        //�����Ƕ�ϵ������

//1.����״̬
#define END_EM_ONLINE_CODE                  0x01        //��������
#define END_EM_OFFLINE_CODE                 0x00        //����������
//2.���ؿ���(�ٷֱȣ�0~100)
#define END_EM_SCTRL_CLOSE_CODE             0xF0        //�����ر�/���¼��½�
#define END_EM_SCTRL_STOP_CODE              0xF1        //����ֹͣ
#define END_EM_SCTRL_OPEN_CODE              0xF2        //������/���¼�����
//3.�Ƕȿ���(�Ƕȣ�0~180)
#define END_EM_ACTRL_UP_CODE                0xF0        //�����Ƕ�����
#define END_EM_ACTRL_DOWN_CODE              0xF1        //�����Ƕȼ�С
//4.��������
#define END_EM_LIGHT_OFF_CODE               0x00        //�ر�
#define END_EM_LIGHT_ON_CODE                0x01        //��
//5.��ɿ���
#define END_EM_DRYING_OFF_CODE              0x00        //�ر�
#define END_EM_DRYING_ON_CODE               0x01        //��
//6.��ɿ���
#define END_EM_AIR_DRY_OFF_CODE             0x00        //�ر�
#define END_EM_AIR_DRY_ON_CODE              0x01        //��
//7.��������
#define END_EM_DISINFECT_OFF_CODE           0x00        //�ر�
#define END_EM_DISINFECT_ON_CODE            0x01        //��
//8.�����ӿ���
#define END_EM_ANION_OFF_CODE               0x00        //�ر�
#define END_EM_ANION_ON_CODE                0x01        //��
//9.��������
#define END_EM_STYLE_CURTAIN_CODE           0x01        //������
#define END_EM_STYLE_SHUTTER_CODE           0x02        //����
#define END_EM_STYLE_BLIND_CODE             0x03        //��Ҷ��
//10.��ַ����
#define END_EM_ADDR_SET_OK_CODE             0x01        //������ַ���óɹ�
#define END_EM_ADDR_SET_FAIL_CODE           0x00        //������ַ����ʧ��
//11.��������
#define END_EM_REVERSE_MOTOR_CODE           0x01        //�����������
#define END_EM_REVERSE_ANGLE_CODE           0x02        //�����Ƕȷ���
//12.��������
#define END_EM_HAND_ON_CODE                 0x00        //������������
#define END_EM_HAND_OFF_CODE                0x01        //���������ر�
//13.�г�����
#define END_EM_RANGE_UP_CODE                0x01        //�������г�
#define END_EM_RANGE_DOWN_CODE              0x02        //�������г�
#define END_EM_RANGE_DELETE_CODE            0xF0        //����ɾ���г�
//14.�Ƕ�ϵ������(�ٷֱȣ�0~100)
#define END_EM_ACOEF_UP_CODE                0xF0        //�����Ƕ�ϵ������
#define END_EM_ACOEF_DOWN_CODE              0xF1        //�����Ƕ�ϵ����С

//�նˣ��綯����================================================================
#define END_EM_ROAD_01_CODE                 0x01        //������01·
#define END_EM_ROAD_08_CODE                 0x08        //������08·
#define END_EM_ROAD_16_CODE                 0x10        //������16·

//�նˣ�����====================================================================
#define END_LK_ONLINE_STATUS_CODE           0x41        //��������״̬
#define END_LK_CTRL_CODE                    0x50        //��������
#define END_LK_STATUS_CHECK_CODE            0x50        //����״̬��ѯ
#define END_LK_KEY_CTRL_CODE                0x60        //Կ�ײ���
#define END_LK_UNLOCK_ALARM_CODE            0x70        //��������
#define END_LK_ELIMI_ALARM_CODE             0x80        //��������
#define END_LK_DEFENSE_CODE                 0x90        //����������
#define END_LK_POWER_CODE                   0xD0        //��������
#define END_LK_BINDING_CODE                 0xE0        //������

//1.����״̬
#define END_LK_OFFLINE_CODE                 0x00        //����������
#define END_LK_ONLINE_CODE                  0x01        //����������
//2.���ؿ���
#define END_LK_LOCK_CODE                    0x00        //������������
#define END_LK_UNLOCK_CODE                  0x01        //������������
#define END_LK_UNLOCK_EMER_CODE             0x02        //����Ӧ����������
//5.��������
#define END_LK_UNLOCK_ILLEGAL_CODE          0x01        //�Ƿ�Կ�׿�������
#define END_LK_UNLOCK_HOSTAGE_CODE          0x02        //Ю�ֿ�������
#define END_LK_UNLOCK_BREAKING_CODE         0x03        //���ű���
#define END_LK_UNLOCK_VIBRATION_CODE        0x04        //�񶯱���
#define END_LK_UNLOCK_OVERTIME_CODE         0x06        //δ���ų�ʱ����
#define END_LK_UNLOCK_NORMAL_CODE           0x10        //������������
#define END_LK_UNLOCK_KEY_01_CODE           0x11        //1��Կ�׿�������
//6.��������
#define END_LK_ALARM_ELIMI_CODE             0x01        //������������
//7.����������
#define END_LK_DEFENSE_ON_CODE              0x01        //��������
#define END_LK_DEFENSE_OFF_CODE             0x00        //��������
//8.��������
#define END_LK_POWER_OK_CODE                0x00        //��������
#define END_LK_POWER_LOW_CODE               0x01        //��������
//9.������
#define END_LK_BINDING_BIND_CODE            0x01        //�����󶨶���
#define END_LK_BINDING_REMOVE_CODE          0x00        //���������

//�նˣ�����
#define END_LK_ROAD_01_CODE                 0x01        //������01·
#define END_LK_ROAD_02_CODE                 0x02        //������02·
#define END_LK_ROAD_04_CODE                 0x04        //������04·

//�նˣ���������================================================================
#define END_CM_ONLINE_STATUS_CODE           0x11        //��������״̬��
#define END_CM_POWER_STATUS_CODE            0x20        //���쿪�ؿ���
#define END_CM_SOURCE_SET_CODE              0x30        //������Դѡ��
#define END_CM_VOLUME_SET_CODE              0x40        //���������趨
#define END_CM_VOLUME_ADJUST_CODE           0x41        //������������
#define END_CM_TREBLE_SET_CODE              0x42        //��������趨
#define END_CM_TREBLE_ADJUST_CODE           0x43        //�����������
#define END_CM_BASS_SET_CODE                0x44        //��������趨
#define END_CM_BASS_ADJUST_CODE             0x45        //�����������
#define END_CM_AUDIO_SET_CODE               0x46        //������Ч�趨
#define END_CM_MUTE_STATUS_CODE             0x48        //���쾲������
#define END_CM_RUN_MODE_CODE                0x60        //���첥�ſ���
#define END_CM_CHANNEL_SET_CODE             0x61        //������Ŀ�л�
#define END_CM_DIRECTORY_SET_CODE           0x62        //����Ŀ¼�л�
#define END_CM_PLAY_MODE_CODE               0x63        //���첥��ģʽ
#define END_CM_RADIO_STATUS_CODE            0x64        //��������״̬
#define END_CM_RADIO_BAND_CODE              0x65        //��������Ƶ��
#define END_CM_SONG_NAME_CODE               0x66        //���������

//1.����״̬
#define END_CM_OFFLINE_CODE                 0x00        //���������
#define END_CM_ONLINE_CODE                  0x01        //����������
//2.���ؿ���
#define END_CM_POWER_OFF_CODE               0x00        //���쿪�عر�
#define END_CM_POWER_ON_CODE                0x01        //���쿪�ش�
//3.��Դѡ��
#define END_CM_SOURCE_NULL_CODE             0x00        //��Դ�޽���
#define END_CM_SOURCE_USB_CODE              0x01        //��ԴUSB/MP3
#define END_CM_SOURCE_TUNER_CODE            0x02        //��ԴTUNER
#define END_CM_SOURCE_DVD_CODE              0x03        //��ԴDVD
#define END_CM_SOURCE_PC_CODE               0x04        //��ԴPC
#define END_CM_SOURCE_TV_CODE               0x05        //��ԴTV
#define END_CM_SOURCE_AUX_CODE              0x06        //��ԴAUX
#define END_CM_SOURCE_AUX2_CODE             0x17        //��ԴAUX2
#define END_CM_SOURCE_IPOD_CODE             0x07        //��ԴIPOD
#define END_CM_SOURCE_SD_CODE               0x08        //��ԴSD
#define END_CM_SOURCE_FM_CODE               0x09        //��ԴFM
#define END_CM_SOURCE_BT_CODE               0x0A        //��Դ����
#define END_CM_SOURCE_IRADIO_CODE           0x0B        //��ԴIRADIO
#define END_CM_SOURCE_OP_CODE               0x0C        //��ԴOptical
#define END_CM_SOURCE_51_CODE               0x0D        //��Դ5.1LINE
#define END_CM_SOURCE_CD_CODE               0x0E        //��ԴCD
#define END_CM_SOURCE_OTHER_CODE            0x0F        //��Դ����
#define END_CM_SOURCE_CBL_CODE              0x10        //��ԴCBL/SAT
#define END_CM_SOURCE_BR_CODE               0x11        //��ԴBlu-ray
#define END_CM_SOURCE_MPLAY_CODE            0x12        //��ԴMPLAY
#define END_CM_SOURCE_NET_CODE              0x13        //��ԴNET
#define END_CM_SOURCE_NET2_CODE             0x18        //��ԴNET2
#define END_CM_SOURCE_NET3_CODE             0x19        //��ԴNET3
#define END_CM_SOURCE_GAME_CODE             0x14        //��ԴGAME
#define END_CM_SOURCE_FLASH_CODE            0x15        //��Դ�ڴ�
#define END_CM_SOURCE_ALL_CODE              0x16        //��Դȫ��

#define END_CM_SOURCE_SOFT_CODE             0x30        //��Դ������Soft Music
#define END_CM_SOURCE_POP_CODE              0x31        //��Դ������Pop Music
#define END_CM_SOURCE_CLASSIC_CODE          0x32        //��Դ�ŵ���Classical Music
#define END_CM_SOURCE_ROCK_CODE             0x33        //��Դҡ����Rock Music

#define END_CM_SOURCE_PARLOR_CODE           0x34        //��Դ���Parlor
#define END_CM_SOURCE_DINING_CODE           0x35        //��Դ�Ͳ�Dining
#define END_CM_SOURCE_ENTTAIN_CODE          0x36        //��Դ����Entertainment
#define END_CM_SOURCE_LEISURE_CODE          0x37        //��Դ����Leisure
#define END_CM_SOURCE_JOY_CODE              0x38        //��Դ����Joy
#define END_CM_SOURCE_QUIET_CODE            0x39        //��Դ�ľ�Quiet
#define END_CM_SOURCE_ROMANTIC_CODE         0x3A        //��Դ����Romantic
#define END_CM_SOURCE_WARM_CODE             0x3B        //��Դ��ܰWarm
#define END_CM_SOURCE_ORIGINAL_CODE         0x3C        //��Դԭ��Original
//5.��������
#define END_CM_VOLUME_UP_CODE               0xF0        //����������
#define END_CM_VOLUME_DOWN_CODE             0xF1        //����������
//8.��Ч����
#define END_CM_AUDIO_NORMAL_CODE            0x00        //��׼
#define END_CM_AUDIO_POP_CODE               0x01        //����
#define END_CM_AUDIO_SOFT_CODE              0x02        //���/ƽ��
#define END_CM_AUDIO_CLASSIC_CODE           0x03        //�ŵ�
#define END_CM_AUDIO_JAZZ_CODE              0x04        //��ʿ
#define END_CM_AUDIO_ROCK_CODE              0x05        //ҡ��
#define END_CM_AUDIO_BASS_CODE              0x06        //����
#define END_CM_AUDIO_DANCE_CODE             0x07        //����
#define END_CM_AUDIO_HIPHOP_CODE            0x08        //����
#define END_CM_AUDIO_VOCAL_CODE             0x09        //����
#define END_CM_AUDIO_METAL_CODE		  				0x0A				//����
//9.��������
#define END_CM_MUTE_ON_CODE                 0x01        //������������
#define END_CM_MUTE_OFF_CODE                0x00        //��������ȡ������
//10.���ſ���
#define END_CM_RUN_MODE_PLAY_CODE           0x01        //��������״̬����
#define END_CM_RUN_MODE_PAUSE_CODE          0x02        //��������״̬��ͣ
#define END_CM_RUN_MODE_STOP_CODE           0x00        //��������״ֹ̬ͣ
//11.��Ŀ�л�/12.Ŀ¼�л�
#define END_CM_CHANNEL_FORW_CODE            0x00        //����Ƶ��ѡ��/��Ŀ�л���һ��
#define END_CM_CHANNEL_BACKW_CODE           0x01        //����Ƶ��ѡ��/��Ŀ�л���һ��
//13.����ģʽ
#define END_CM_MODE_SINGLE_PLAY_CODE        0x01        //��������
#define END_CM_MODE_SINGLE_REPEAT_CODE      0x02        //����ѭ��
#define END_CM_MODE_ORDER_PLAY_CODE         0x03        //˳�򲥷�
#define END_CM_MODE_DIRECT_PLAY_CODE        0x04        //Ŀ¼����
#define END_CM_MODE_SHUFFLE_PLAY_CODE       0x05        //�������
#define END_CM_MODE_ORDER_REPEAT_CODE       0x06        //˳��ѭ��
//14.����Ƶ��
#define END_CM_RADIO_FM_CODE                0x00        //����FM
#define END_CM_RADIO_AM_CODE                0x01        //����AM
//��������
#define END_CM_RADIO_MUTE_CODE              0x00        //��������
#define END_CM_RADIO_UNMUTE_CODE            0x01        //����������
//15.������
#define END_CM_SONG_NAME_UTF8_CODE          0x01        //������ΪUTF-8����
#define END_CM_SONG_NAME_GB2312_CODE        0x02        //������ΪGB2312����

//�նˣ���������
#define END_CM_ROAD_01_CODE                 0x01        //���������01·
#define END_CM_ROAD_08_CODE                 0x08        //���������08·
#define END_CM_ROAD_09_CODE                 0x09        //���������09·

//�նˣ�����յ�================================================================
#define END_CAC_ONLINE_STATUS_CODE          0x11        //�յ�����״̬��
#define END_CAC_POWER_STATUS_CODE           0x20        //�յ�����״̬��
#define END_CAC_RUN_MODE_CODE               0x30        //�յ�����ģʽ��
#define END_CAC_FAN_FLOW_CODE               0x40        //�յ����ȷ�����
#define END_CAC_TEMPERATURE_SET_CODE        0x50        //�յ��趨�¶��루0x0A~0x1E��
#define END_CAC_FAN_DIRECT_CODE             0x60        //�յ��趨������
#define END_CAC_TEMPERATURE_REAL_CODE       0x70        //�յ������¶��루0x0A~0x1E��
#define END_CAC_TEMP_AVERAGE_CODE           0x71        //�յ������¶�ƽ��ֵ��0x0A~0x1E��
#define END_CAC_TEMP_MEDIAN_CODE            0x72        //�յ������¶���λֵ��0x0A~0x1E��
#define END_CAC_FILTER_STATUS_CODE          0x80        //�յ�������״̬��
#define END_CAC_COMPRESSOR_STATUS_CODE      0x90        //�յ�ѹ����״̬��
#define END_CAC_LOCK_STATUS_CODE            0xA0        //�յ������������
#define END_CAC_FAULT_STATUS_CODE           0xB0        //�յ�����״̬��
#define END_CAC_FAULT_CODE_CODE             0xF0        //�յ�������ֵ��

//1.����״̬
#define END_CAC_ONLINE_ON_CODE              0x01        //�յ�����
#define END_CAC_ONLINE_OFF_CODE             0x00        //�յ�����
//2.���ؿ���
#define END_CAC_POWER_ON_CODE               0x01        //�յ���Դ����
#define END_CAC_POWER_OFF_CODE              0x00        //�յ���Դ�ر�
//3.ģʽ����
#define END_CAC_MODE_HEAT_CODE              0x01        //�յ�ģʽ����
#define END_CAC_MODE_COLD_CODE              0x02        //�յ�ģʽ����
#define END_CAC_MODE_AIR_CODE               0x03        //�յ�ģʽ�ͷ�
#define END_CAC_MODE_AUTO_CODE              0x04        //�յ�ģʽ�Զ�
#define END_CAC_MODE_VENTILATE_CODE         0x05        //�յ�ģʽ����
#define END_CAC_MODE_DEHUMID_CODE           0x06        //�յ�ģʽ��ʪ
//4.���ٿ���
#define END_CAC_FAN_FLOW_AUTO_CODE          0x00        //�յ����ȷ����Զ�
#define END_CAC_FAN_FLOW_HIGHER_CODE        0x04        //�յ����ȷ������߷�
#define END_CAC_FAN_FLOW_HIGH_CODE          0x01        //�յ����ȷ����߷�
#define END_CAC_FAN_FLOW_MID_CODE           0x02        //�յ����ȷ����з�
#define END_CAC_FAN_FLOW_LOW_CODE           0x03        //�յ����ȷ����ͷ�
#define END_CAC_FAN_FLOW_LOWER_CODE         0x05        //�յ����ȷ������ͷ�
#define END_CAC_FAN_FLOW_1_CODE             0x01        //�յ����ȷ�������1
#define END_CAC_FAN_FLOW_2_CODE             0x02        //�յ����ȷ�������2
#define END_CAC_FAN_FLOW_3_CODE             0x03        //�յ����ȷ�������3
#define END_CAC_FAN_FLOW_4_CODE             0x04        //�յ����ȷ�������4
#define END_CAC_FAN_FLOW_5_CODE             0x05        //�յ����ȷ�������5
//5.�¶ȿ���
//6.�������
#define END_CAC_FAN_DIR_P0_CODE             0x00        //�յ�����P0
#define END_CAC_FAN_DIR_P1_CODE             0x01        //�յ�����P1
#define END_CAC_FAN_DIR_P2_CODE             0x02        //�յ�����P2
#define END_CAC_FAN_DIR_P3_CODE             0x03        //�յ�����P3
#define END_CAC_FAN_DIR_P4_CODE             0x04        //�յ�����P4
#define END_CAC_FAN_DIR_P5_CODE             0x05        //�յ�����P5
#define END_CAC_FAN_DIR_STOP_CODE           0x06        //�յ�����ֹͣ
#define END_CAC_FAN_DIR_SWING_CODE          0x07        //�յ�����ҡ��
#define END_CAC_FAN_DIR_AUTO_CODE           0x08        //�յ������Զ�
#define END_CAC_FAN_DIR_SWING_UD_CODE       0x09        //�յ���������ҡ��
#define END_CAC_FAN_DIR_SWING_LR_CODE       0x0A        //�յ���������ҡ��
//7.ʵ�²ɼ�
//8.ʵ��ƽ��ֵ
//9.ʵ����λֵ
//10.������״̬
#define END_CAC_FILTER_OK_CODE              0x00        //�յ�����������
#define END_CAC_FILTER_WASH_CODE            0x01        //�յ���������ϴ
//11.ѹ����״̬
#define END_CAC_COMPRESSOR_OFF_CODE         0x00        //�յ�ѹ�����ر�
#define END_CAC_COMPRESSOR_ON_CODE          0x01        //�յ�ѹ������
//12.�����������
#define END_CAC_LOCK_OFF_CODE               0x00        //�յ���������������
#define END_CAC_LOCK_ON_CODE                0x02        //�յ����������������
#define END_CAC_LOCK_HALF_CODE              0x01        //�յ���������������
#define END_CAC_LOCK_ALL_CODE               0x02        //�յ������������ȫ��
//13.����״̬
#define END_CAC_FAULT_NONE_CODE             0x00        //�յ��޹���
#define END_CAC_FAULT_HAD_CODE              0x01        //�յ��й���
//14.���ϴ���

//�նˣ�����յ�
#define END_CAC_ROAD_01_CODE                0x01        //����յ���01·
#define END_CAC_ROAD_08_CODE                0x08        //����յ���08·
#define END_CAC_ROAD_09_CODE                0x09        //����յ���08·
#define END_CAC_ROAD_16_CODE                0x10        //����յ���16·

//�նˣ������·�================================================================
#define END_CFA_ONLINE_STATUS_CODE          0x11        //�·�����״̬��
#define END_CFA_POWER_STATUS_CODE           0x20        //�·翪��״̬��
#define END_CFA_RUN_MODE_CODE               0x30        //�·�����ģʽ��
#define END_CFA_FAN_FLOW_CODE               0x40        //�·���ȷ�����
#define END_CFA_EXHAUST_FAN_FLOW_CODE       0x41        //�·��ŷ���ȷ�����
#define END_CFA_BYPASS_STATUS_CODE          0x42        //�·���ͨ״̬��
#define END_CFA_HUMIDITY_REAL_CODE          0x50        //�·�ʪ�Ȳɼ���(��10)(����)
#define END_CFA_HUMI_AVERAGE_CODE           0x51        //�·�ɼ�ʪ��ƽ��ֵ(��10)(����)
#define END_CFA_HUMI_REAL_OUTDOOR_CODE      0x54        //�·�����ʪ�Ȳɼ���(��10)
#define END_CFA_HUMI_AVE_OUTDOOR_CODE       0x55        //�·�����ɼ�ʪ��ƽ��ֵ(��10)
#define END_CFA_PM25_REAL_CODE              0x60        //�·�PM2.5�ɼ���(��1)
#define END_CFA_PM25_AVERAGE_CODE           0x61        //�·�ɼ�PM2.5ƽ��ֵ(��1)
#define END_CFA_VOC_REAL_CODE               0x68        //�·�VOC�ɼ���(��100)
#define END_CFA_VOC_AVERAGE_CODE            0x69        //�·�ɼ�VOCƽ��ֵ(��100)
#define END_CFA_TEMPERATURE_REAL_CODE       0x70        //�·������¶���(��10)(����)
#define END_CFA_TEMP_AVERAGE_CODE           0x71        //�·������¶�ƽ��ֵ(��10)(����)
#define END_CFA_TEMP_REAL_OUTDOOR_CODE      0x74        //�·������¶���(��10)
#define END_CFA_TEMP_AVE_OUTDOOR_CODE       0x75        //�·������¶�ƽ��ֵ(��10)
#define END_CFA_FILTER_STATUS_CODE          0x80        //�·������״̬��
#define END_CFA_LOCK_STATUS_CODE            0xA0        //�·������������
#define END_CFA_FAULT_STATUS_CODE           0xB0        //�·����״̬��
#define END_CFA_FAULT_CODE_CODE             0xF0        //�·������ֵ��

//1.����״̬
#define END_CFA_ONLINE_ON_CODE              0x01        //�·�����
#define END_CFA_ONLINE_OFF_CODE             0x00        //�·����
//2.���ؿ���
#define END_CFA_POWER_ON_CODE               0x01        //�·��Դ����
#define END_CFA_POWER_OFF_CODE              0x00        //�·��Դ�ر�
//3.ģʽ����
#define END_CFA_MODE_STANDBY_CODE           0x01        //�·�ģʽ����
#define END_CFA_MODE_AUTO_CODE              0x02        //�·�ģʽ�Զ�/����
#define END_CFA_MODE_OUTER_LOOP_CODE        0x03        //�·�ģʽ��ѭ��
#define END_CFA_MODE_INNER_LOOP_CODE        0x04        //�·�ģʽ��ѭ��
#define END_CFA_MODE_DISINFECT_CODE         0x05        //�·�ģʽ������ɱ��
#define END_CFA_MODE_HAND_CODE              0x06        //�·�ģʽ�ֶ�
#define END_CFA_MODE_STRONG_CODE            0x07        //�·�ģʽǿ��
#define END_CFA_MODE_SAVING_CODE            0x08        //�·�ģʽ����/ʡ��
#define END_CFA_MODE_VENTILATE_CODE         0x09        //�·�ģʽ����
#define END_CFA_MODE_EXHAUST_CODE           0x0A        //�·�ģʽ�ŷ�
#define END_CFA_MODE_SPRAUT_CODE            0x0B        //�·�ģʽ����
#define END_CFA_MODE_ANTIFREEZE_CODE        0x0C        //�·�ģʽ����
//4.���ٿ���(�·�)
#define END_CFA_FAN_FLOW_HIGH_CODE          0x01        //�·���ȷ����߷�
#define END_CFA_FAN_FLOW_MID_CODE           0x02        //�·���ȷ����з�
#define END_CFA_FAN_FLOW_LOW_CODE           0x03        //�·���ȷ����ͷ�
#define END_CFA_FAN_FLOW_STOP_CODE          0x04        //�·���ȷ���ֹͣ
#define END_CFA_FAN_FLOW_AUTO_CODE          0x05        //�·���ȷ����Զ�
//5.�ŷ���ٿ���
#define END_CFA_EXHAUST_FAN_FLOW_HIGH_CODE  0x01        //�·��ŷ���ȷ����߷�
#define END_CFA_EXHAUST_FAN_FLOW_MID_CODE   0x02        //�·��ŷ���ȷ����з�
#define END_CFA_EXHAUST_FAN_FLOW_LOW_CODE   0x03        //�·��ŷ���ȷ����ͷ�
#define END_CFA_EXHAUST_FAN_FLOW_STOP_CODE  0x04        //�·��ŷ���ȷ���ֹͣ
//6.��ͨ����
#define END_CFA_BYPASS_ON_CODE              0x01        //�·���ͨ����
#define END_CFA_BYPASS_OFF_CODE             0x00        //�·���ͨ�ر�
//7.ʪ�Ȳɼ�(��10)(����)
//8.ʪ��ƽ��ֵ(��10)(����)
//9.����ʪ�Ȳɼ�(��10)
//10.����ʪ��ƽ��ֵ(��10)
//11.PM2.5�ɼ�(��1)
//12.PM2.5ƽ��ֵ(��1)
//13.VOC�ɼ�(��100)
//14.VOCƽ��ֵ(��100)
//15.ʵ�²ɼ�(��10)(����)
//16.ʵ��ƽ��ֵ(��10)(����)
//17.����ʵ�²ɼ�(��10)
//18.����ʵ��ƽ��ֵ(��10)
//19.������״̬
#define END_CFA_FILTER_OK_CODE              0x00        //�·����������
#define END_CFA_FILTER_WASH_CODE            0x01        //�·��������ϴ
//20.�����������
#define END_CFA_LOCK_OFF_CODE               0x00        //�·���������������
#define END_CFA_LOCK_ON_CODE                0x02        //�·����������������
#define END_CFA_LOCK_HALF_CODE              0x01        //�·���������������
#define END_CFA_LOCK_ALL_CODE               0x02        //�·������������ȫ��
//21.����״̬
#define END_CFA_FAULT_NONE_CODE             0x00        //�·��޹���
#define END_CFA_FAULT_HAD_CODE              0x01        //�·��й���
//22.���ϴ���

//�նˣ������·�
#define END_CFA_ROAD_01_CODE                0x01        //�����·��01·
#define END_CFA_ROAD_08_CODE                0x08        //�����·��08·
#define END_CFA_ROAD_09_CODE                0x09        //�����·��08·
#define END_CFA_ROAD_16_CODE                0x10        //�����·��16·

//�նˣ������ů================================================================
#define END_CFH_POWER_STATUS_CODE           0x94        //��ů��Դ״̬��
#define END_CFH_MODE_STATUS_CODE            0x95        //��ůģʽ״̬��
#define END_CFH_TEMPERATURE_SET_CODE        0x96        //��ů�趨�¶���(��10)
#define END_CFH_HEATING_STATUS_CODE         0x97        //��ů����״̬��
#define END_CFH_TEMPERATURE_REAL_CODE       0x98        //��ů�����¶���(��10)
#define END_CFH_TEMP_AVERAGE_CODE           0xA1        //��ů�����¶�ƽ��ֵ(��10)
#define END_CFH_TEMP_MEDIAN_CODE            0xA2        //��ů�����¶���λֵ(��10)
#define END_CFH_ONLINE_STATUS_CODE          0x99        //��ů����״̬��
#define END_CFH_LOCK_MODE_CODE              0xA0        //��ů����ģʽ��

//1.���ؿ���
#define END_CFH_POWER_ON_CODE               0x00        //��ů��Դ����
#define END_CFH_POWER_OFF_CODE              0x01        //��ů��Դ�ر�
//2.ģʽ����
#define END_CFH_MODE_AUTO_CODE              0x00        //��ůģʽ�Զ�
#define END_CFH_MODE_HAND_CODE              0x01        //��ůģʽ�ֶ�
#define END_CFH_MODE_TEMP_CODE              0x02        //��ůģʽ��ʱ
#define END_CFH_MODE_LOCK_CODE              0x03        //��ůģʽ����
//3.�趨�¶�(��10)
//4.����״̬
#define END_CFH_HEATING_ON_CODE             0x01        //��ů����
#define END_CFH_HEATING_OFF_CODE            0x00        //��ů������
//5.ʵ�²ɼ�(��10)
//6.ʵ��ƽ��ֵ(��10)
//7.ʵ����λֵ(��10)
//8.����״̬
#define END_CFH_ONLINE_ON_CODE              0x01        //��ů����
#define END_CFH_ONLINE_OFF_CODE             0x00        //��ů����
//9.�����������
#define END_CFH_LOCK_MODE_UNLOCK_CODE       0x00        //��ůδ����
#define END_CFH_LOCK_MODE_SEMI_LOCK_CODE    0x01        //��ů������
#define END_CFH_LOCK_MODE_FULL_LOCK_CODE    0x02        //��ůȫ����

//�նˣ������ů
#define END_CFH_ROAD_01_CODE                0x01        //��ů��01·
#define END_CFH_ROAD_06_CODE                0x06        //��ů��06·
#define END_CFH_ROAD_07_CODE                0x07        //��ů��07·
#define END_CFH_ROAD_08_CODE                0x08        //��ů��08·
#define END_CFH_ROAD_16_CODE                0x10        //��ů��16·

//�նˣ���ˮ��==================================================================
#define END_WWH_POWER_STATUS_CODE           0x03      //��ˮ������״̬��
#define END_WWH_TEMPERATURE_SET_CODE        0x04      //��ˮ���趨�¶���
#define END_WWH_TEMPERATURE_REAL_CODE       0x05      //��ˮ��ʵʱ�¶���
#define END_WWH_TEMP_AVERAGE_CODE           0x06      //��ˮ��ʵʱ�¶�ƽ��ֵ
#define END_WWH_ONLINE_STATUS_CODE          0x12      //��ˮ������״̬��
#define END_WWH_HEATING_STATUS_CODE         0x22      //��ˮ������״̬��
#define END_WWH_LOCK_STATUS_CODE            0x92      //��ˮ���������״̬��
#define END_WWH_FAULT_STATUS_CODE           0xA2      //��ˮ������״̬��
#define END_WWH_FAULT_CODE_CODE             0xE2      //��ˮ��������ֵ��

//1.���ؿ���
#define END_WWH_POWER_ON_CODE               0xFF        //��ˮ����Դ����
#define END_WWH_POWER_OFF_CODE              0x00        //��ˮ����Դ�ر�
//2.�趨�¶�
//3.ʵ�²ɼ�
//4.ʵ��ƽ��ֵ
//5.����״̬
#define END_WWH_ONLINE_ON_CODE              0x01        //��ˮ������
#define END_WWH_ONLINE_OFF_CODE             0x00        //��ˮ������
//6.����״̬
#define END_WWH_HEATING_ON_CODE             0x01        //��ˮ������
#define END_WWH_HEATING_OFF_CODE            0x00        //��ˮ��������
//7.�����������
#define END_WWH_LOCK_OFF_CODE               0x00        //��ˮ����������������
#define END_WWH_LOCK_ON_CODE                0x02        //��ˮ�����������������
#define END_WWH_LOCK_HALF_CODE              0x01        //��ˮ����������������
#define END_WWH_LOCK_ALL_CODE               0x02        //��ˮ�������������ȫ��
//8.����״̬
#define END_WWH_FAULT_NONE_CODE             0x00        //��ˮ���޹���
#define END_WWH_FAULT_HAD_CODE              0x01        //��ˮ���й���
//9.���ϴ���

//�նˣ���ˮ��
#define END_WWH_ROAD_01_CODE                0x01        //��ˮ����01·

#endif

/********************************************************************************
*                                   NO MORE CODE                                *
********************************************************************************/
