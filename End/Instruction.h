/*******************************************************************************
*                                    ��������                                  *
*******************************************************************************/
#ifndef __fixed_num
  #define __fixed_num

  //����232 ͨ�ŵ�֡
  //����
  #define X232_CM_HEAD_CODE_POS				0
  #define	X232_CM_ADDRESS_CODE_POS		1
  #define X232_CM_CHECK_SUM_CODE_POS	4

  #define X232_CM_POWER_STATUS_CODE_POS		2
  #define X232_CM_SOURCE_CODE_POS					3

  #define X232_CM_RUN_MODE_FLAG_POS				2
  #define X232_CM_RUN_MODE_CODE_POS				3

  #define X232_CM_CHANNEL_CODE_POS				2

  #define X232_CM_VOLUME_CODE_POS					2
  #define X232_CM_VOLUME_DATA_CODE_POS		3

  #define X232_CM_SOURCE_VALUE_CODE_POS		2
  #define X232_CM_SOURCE_NULL_CODE_POS		3

  #define X232_CM_DATA_01_CODE_POS				2
  #define X232_CM_DATA_02_CODE_POS				3

  //��ѯ
  #define X232_CM_SENSING_DATA_01_POS			2
  #define X232_CM_SENSING_DATA_02_POS			3

  #define X232_CM_CONTROL_FEED_DATA_01_CODE_POS					0
  #define X232_CM_CONTROL_FEED_DATA_03_CODE_POS					2
  #define X232_CM_CONTROL_FEED_DATA_04_CODE_POS					3

  #define X232_CM_SENSING_DATA_CODE_POS					3
  #define X232_CM_SENSING_VOLUME_CODE_POS				4
  #define X232_CM_TREBLE_BASS_CODE_POS					5
  #define X232_CM_SENSING_SOURCE_CODE_POS				12

  #define X232_CM_CONTROL_STYLE_POWER_ON									1
  #define X232_CM_CONTROL_STYLE_POWER_OFF									2
  #define X232_CM_CONTROL_STYLE_PAUSE											3
  #define X232_CM_CONTROL_STYLE_PLAY											4
  #define X232_CM_CONTROL_STYLE_CHANNEL_FORW							5
  #define X232_CM_CONTROL_STYLE_CHANNEL_BACKW							6
  #define X232_CM_CONTROL_STYLE_VOLUME_UP									7
  #define X232_CM_CONTROL_STYLE_VOLUME_DOWN								8
  #define X232_CM_CONTROL_STYLE_SOURCE_SET								9
  #define X232_CM_CONTROL_STYLE_MUTE_ON										10
  #define X232_CM_CONTROL_STYLE_MUTE_OFF									11
  #define X232_CM_CONTROL_STYLE_PLAY_MODE									12
  #define X232_CM_CONTROL_STYLE_AUDIO_SET									13
  #define X232_CM_CONTROL_STYLE_TREBLE_SET								14
  #define X232_CM_CONTROL_STYLE_BASS_SET									15
  #define X232_CM_CONTROL_STYLE_VOLUME_SET								16
  #define X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_UP			17
  #define X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_DOWN		18
  #define X232_CM_CONTROL_STYLE_BASS_ADJUST_UP						19
  #define X232_CM_CONTROL_STYLE_BASS_ADJUST_DOWN					20

#endif

/*******************************************************************************
*                                     ָ���붨��                            	   *
*******************************************************************************/
#ifndef __fixed_code
  #define __fixed_code

  //����232��Nuvo�������ֿ�����
  #define X232_CM_ADDRESS_01_CODE						 0x01

  #define X232_CM_HEAD_CODE								 	 0xA3
  #define X232_CM_SENSING_HEAD_CODE					 0xCC
  #define X232_POWER_STATUS_ON_CODE				 	 0x07				//��Դ��
  #define X232_POWER_STATUS_OFF_CODE				 0x03				//��Դ�ر�
  #define X232_CM_RUN_MODE_FLAG							 0x02			  //��������״̬��־λ
  #define X232_CM_RUN_MODE_PLAY_CODE         0x00       //��������״̬����
  #define X232_CM_RUN_MODE_PAUSE_CODE        0x01       //��������״̬��ͣ
  #define X232_CM_CHANNEL_FORW_CODE          0x05       //����Ƶ��ѡ��/��Ŀ�л���һ��
  #define X232_CM_CHANNEL_BACKW_CODE         0x09       //����Ƶ��ѡ��/��Ŀ�л���һ��
  #define X232_CM_VOLUME_UP_CODE             0x01       //����������
  #define X232_CM_VOLUME_DOWN_CODE           0x08       //����������
  #define X232_CM_SENSING_DATA_01_CODE			 0x00
  #define X232_CM_SENSING_DATA_02_CODE			 0x00
  #define X232_CM_MUTE_ON_CODE							 0x01				//����
  #define X232_CM_MUTE_OFF_CODE							 0x00				//�������

  #define X232_CM_OFFLINE_CODE							 0x00				//����������
  #define X232_CM_ONLINE_CODE								 0x01				//���������

  #define X232_CM_SOURCE_FM_CODE             0x0a       //��ԴFM
  #define X232_CM_SOURCE_MP3_CODE            0x0b       //��ԴUSB/MP3
  #define X232_CM_SOURCE_AUX_CODE            0x0c       //��ԴAUX
  #define X232_CM_SOURCE_DVD_CODE            0x06       //��ԴDVD
  #define X232_CM_SOURCE_FM2_CODE            0x10       //��ԴFM2
  #define X232_CM_SOURCE_IPOD_CODE           0x11       //��ԴIPOD
  #define X232_CM_SOURCE_NET_RADIO_CODE      0x12       //��ԴNET_RADIO
  #define X232_CM_SOURCE_CLOUD_CODE          0x13       //��ԴCLOUD_MUSIC


  #define X232_CM_AUDIO_NORMAL_CODE					 0x00		//��׼
  #define X232_CM_AUDIO_POP_CODE						 0x01		//����
  #define X232_CM_AUDIO_SOFT_CODE					 	 0x02		//���/ƽ��
  #define X232_CM_AUDIO_CLASSIC_CODE				 0x03		//�ŵ�
  #define X232_CM_AUDIO_JAZZ_CODE						 0x04		//��ʿ
  #define X232_CM_AUDIO_ROCK_CODE						 0x05		//ҡ��

  #define X232_CM_TREBLE_SET_CODE            0x13   //��������趨
  #define X232_CM_BASS_SET_CODE              0x03   //��������趨
  #define X232_CM_TREBLE_UP_CODE             0x11   //���������
  #define X232_CM_TREBLE_DOWN_CODE           0x12   //���������
  #define X232_CM_BASS_UP_CODE               0x01   //���������
  #define X232_CM_BASS_DOWN_CODE             0x02   //���������
  #define X232_CM_TREBLE_SET_MAX						 0x0F		//�������ֵ
  #define X232_CM_BASS_SET_MAX							 0x0F		//�������ֵ
  #define X232_CM_VOL_MAX										 0x1F		//�������ֵ
  #define X232_CM_VOL_MIN									 	 0x00		//������Сֵ

#endif

/********************************************************************************
*																NO MORE CODE																		*
********************************************************************************/
