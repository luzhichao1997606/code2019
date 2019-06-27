/*******************************************************************************
*                                    常量定义                                  *
*******************************************************************************/
#ifndef __fixed_num
  #define __fixed_num

  //基于232 通信的帧
  //控制
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

  //查询
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
*                                     指令码定义                            	   *
*******************************************************************************/
#ifndef __fixed_code
  #define __fixed_code

  //基于232的Nuvo背景音乐控制器
  #define X232_CM_ADDRESS_01_CODE						 0x01

  #define X232_CM_HEAD_CODE								 	 0xA3
  #define X232_CM_SENSING_HEAD_CODE					 0xCC
  #define X232_POWER_STATUS_ON_CODE				 	 0x07				//电源打开
  #define X232_POWER_STATUS_OFF_CODE				 0x03				//电源关闭
  #define X232_CM_RUN_MODE_FLAG							 0x02			  //音响运行状态标志位
  #define X232_CM_RUN_MODE_PLAY_CODE         0x00       //音响运行状态播放
  #define X232_CM_RUN_MODE_PAUSE_CODE        0x01       //音响运行状态暂停
  #define X232_CM_CHANNEL_FORW_CODE          0x05       //音响频道选择/曲目切换上一曲
  #define X232_CM_CHANNEL_BACKW_CODE         0x09       //音响频道选择/曲目切换下一曲
  #define X232_CM_VOLUME_UP_CODE             0x01       //音响音量加
  #define X232_CM_VOLUME_DOWN_CODE           0x08       //音响音量减
  #define X232_CM_SENSING_DATA_01_CODE			 0x00
  #define X232_CM_SENSING_DATA_02_CODE			 0x00
  #define X232_CM_MUTE_ON_CODE							 0x01				//静音
  #define X232_CM_MUTE_OFF_CODE							 0x00				//解除静音

  #define X232_CM_OFFLINE_CODE							 0x00				//音响在线码
  #define X232_CM_ONLINE_CODE								 0x01				//音响掉线码

  #define X232_CM_SOURCE_FM_CODE             0x0a       //音源FM
  #define X232_CM_SOURCE_MP3_CODE            0x0b       //音源USB/MP3
  #define X232_CM_SOURCE_AUX_CODE            0x0c       //音源AUX
  #define X232_CM_SOURCE_DVD_CODE            0x06       //音源DVD
  #define X232_CM_SOURCE_FM2_CODE            0x10       //音源FM2
  #define X232_CM_SOURCE_IPOD_CODE           0x11       //音源IPOD
  #define X232_CM_SOURCE_NET_RADIO_CODE      0x12       //音源NET_RADIO
  #define X232_CM_SOURCE_CLOUD_CODE          0x13       //音源CLOUD_MUSIC


  #define X232_CM_AUDIO_NORMAL_CODE					 0x00		//标准
  #define X232_CM_AUDIO_POP_CODE						 0x01		//流行
  #define X232_CM_AUDIO_SOFT_CODE					 	 0x02		//柔和/平滑
  #define X232_CM_AUDIO_CLASSIC_CODE				 0x03		//古典
  #define X232_CM_AUDIO_JAZZ_CODE						 0x04		//爵士
  #define X232_CM_AUDIO_ROCK_CODE						 0x05		//摇滚

  #define X232_CM_TREBLE_SET_CODE            0x13   //音响高音设定
  #define X232_CM_BASS_SET_CODE              0x03   //音响低音设定
  #define X232_CM_TREBLE_UP_CODE             0x11   //音响高音加
  #define X232_CM_TREBLE_DOWN_CODE           0x12   //音响高音减
  #define X232_CM_BASS_UP_CODE               0x01   //音响低音加
  #define X232_CM_BASS_DOWN_CODE             0x02   //音响低音减
  #define X232_CM_TREBLE_SET_MAX						 0x0F		//高音最大值
  #define X232_CM_BASS_SET_MAX							 0x0F		//低音最大值
  #define X232_CM_VOL_MAX										 0x1F		//音量最大值
  #define X232_CM_VOL_MIN									 	 0x00		//音量最小值

#endif

/********************************************************************************
*																NO MORE CODE																		*
********************************************************************************/
