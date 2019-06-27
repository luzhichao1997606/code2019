#include "variable.h"
void delay50ms(void)   //误差 0us
{
  unsigned char a, b, c;
  for (c = 151; c > 0; c--)
    for (b = 107; b > 0; b--)
      for (a = 48; a > 0; a--);

}


/*******************************************************************************
*                         		  			控制函数 			     	           	         *
*******************************************************************************/
void X232_CM_Control(CUINT8 Device_Road_num,     	   //动作设备路数
                     CUINT8 Action_Type_Code,         //动作类型码
                     CUINT8 Action_Num_Code           //动作数值码
                    )
{
  if ((Device_Road_num >= END_CM_ROAD_01_CODE)
      && (Device_Road_num < (END_CM_ROAD_01_CODE + X232_CM_ROAD_NUM)))
  { //先判断路数正确
    UINT8 pos, instru_status;

    instru_status = 1;
    pos = Device_Road_num - END_CM_ROAD_01_CODE;

    X232_CM_buf[X232_CM_HEAD_CODE_POS] = X232_CM_HEAD_CODE;		//头码
    X232_CM_buf[X232_CM_ADDRESS_CODE_POS] = pos;							//路数

    switch (Action_Type_Code)
    {
      case END_CM_POWER_STATUS_CODE:		//开关机模式

        switch (Action_Num_Code)
        {
          case END_CM_POWER_ON_CODE:		//开机

            X232_CM_buf[X232_CM_POWER_STATUS_CODE_POS] = X232_POWER_STATUS_ON_CODE;
            X232_CM_buf[X232_CM_SOURCE_CODE_POS]	= 0;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_POWER_ON;

            break;
          case END_CM_POWER_OFF_CODE:		//关机

            X232_CM_buf[X232_CM_POWER_STATUS_CODE_POS] = X232_POWER_STATUS_OFF_CODE;
            X232_CM_buf[X232_CM_SOURCE_CODE_POS]	= 0;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_POWER_OFF;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_RUN_MODE_CODE:    //暂停或开始

        switch (Action_Num_Code)
        {
          case END_CM_RUN_MODE_PAUSE_CODE:		//暂停

            X232_CM_buf[X232_CM_RUN_MODE_FLAG_POS] = X232_CM_RUN_MODE_FLAG;
            X232_CM_buf[X232_CM_RUN_MODE_CODE_POS] = X232_CM_RUN_MODE_PAUSE_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_PAUSE;

            break;
          case END_CM_RUN_MODE_PLAY_CODE:			//播放

            X232_CM_buf[X232_CM_RUN_MODE_FLAG_POS] = X232_CM_RUN_MODE_FLAG;
            X232_CM_buf[X232_CM_RUN_MODE_CODE_POS] = X232_CM_RUN_MODE_PLAY_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_PLAY;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_CHANNEL_SET_CODE: 		//频道选择

        switch (Action_Num_Code)
        {
          case END_CM_CHANNEL_FORW_CODE:		//上一曲

            X232_CM_buf[X232_CM_CHANNEL_CODE_POS] = X232_CM_CHANNEL_FORW_CODE;
            X232_CM_buf[X232_CM_SOURCE_CODE_POS] = 2;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_CHANNEL_FORW;

            break;
          case END_CM_CHANNEL_BACKW_CODE:		//下一曲

            X232_CM_buf[X232_CM_CHANNEL_CODE_POS] = X232_CM_CHANNEL_BACKW_CODE;
            X232_CM_buf[X232_CM_SOURCE_CODE_POS] = 2;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_CHANNEL_BACKW;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_VOLUME_ADJUST_CODE:  		//音量调整

        switch (Action_Num_Code)
        {
          case END_CM_VOLUME_UP_CODE:			//音量加

            X232_CM_buf[X232_CM_VOLUME_CODE_POS] = X232_CM_VOLUME_UP_CODE;
            X232_CM_buf[X232_CM_VOLUME_DATA_CODE_POS] = 1;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_VOLUME_UP;

            break;
          case END_CM_VOLUME_DOWN_CODE:		//音量减

            X232_CM_buf[X232_CM_VOLUME_CODE_POS] = X232_CM_VOLUME_DOWN_CODE;
            X232_CM_buf[X232_CM_VOLUME_DATA_CODE_POS] = 1;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_VOLUME_DOWN;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_SOURCE_SET_CODE:			//音源设定

        X232_CM_buf[X232_CM_SOURCE_NULL_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_SOURCE_FM_CODE:			//音源FM

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_FM_CODE;

            break;
          case END_CM_SOURCE_USB_CODE:		//音源USB/MP3

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_MP3_CODE;

            break;
          case END_CM_SOURCE_AUX_CODE:		//音源AUX

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_AUX_CODE;

            break;
          case END_CM_SOURCE_DVD_CODE:		//音源DVD

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_DVD_CODE;

            break;
          case END_CM_SOURCE_IPOD_CODE:		//音源IPOD

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_IPOD_CODE;

          case END_CM_SOURCE_NET_CODE:		//音源NET_RIDIO

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_NET_RADIO_CODE;

          case END_CM_SOURCE_NET2_CODE:		//音源CLOUD

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_CLOUD_CODE;

            break;
          default:

            instru_status = 0;

            break;
        }

        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_SOURCE_SET;

        break;
      case END_CM_MUTE_STATUS_CODE:			//静音控制

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xab;
        X232_CM_buf[X232_CM_DATA_02_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_MUTE_ON_CODE:		//静音

            X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_MUTE_ON_CODE;
            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_MUTE_ON;

            break;
          case END_CM_MUTE_OFF_CODE:		//静音取消

            X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_MUTE_OFF_CODE;
            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_MUTE_OFF;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_PLAY_MODE_CODE:			//播放模式

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xEA;		//头码
        X232_CM_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS] = 0x01;

        switch (Action_Num_Code)
        {
          case END_CM_MODE_SINGLE_REPEAT_CODE:		//单曲循环

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = 0x01;

            break;
          case END_CM_MODE_ORDER_PLAY_CODE:		//顺序播放

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = 0x00;

            break;
          default:

            instru_status = 0;

            break;
        }

        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_PLAY_MODE;

        break;
      case END_CM_AUDIO_SET_CODE:    	//音响音效设定

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xA4;		//头码
        X232_CM_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_AUDIO_NORMAL_CODE:		//标准

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_NORMAL_CODE;

            break;
          case END_CM_AUDIO_POP_CODE:		//流行

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_POP_CODE;

            break;
          case END_CM_AUDIO_SOFT_CODE:		//柔和/平滑

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_SOFT_CODE;

            break;
          case END_CM_AUDIO_CLASSIC_CODE:		//古典

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_CLASSIC_CODE;

            break;
          case END_CM_AUDIO_JAZZ_CODE:		//爵士

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_JAZZ_CODE;

            break;
          case END_CM_AUDIO_ROCK_CODE:		//摇滚

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_ROCK_CODE;

            break;
          default:

            instru_status = 0;

            break;
        }

        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_AUDIO_SET;

        break;
      case END_CM_TREBLE_SET_CODE:    //音响高音设定

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xAF;		//头码
        X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_TREBLE_SET_CODE;

        if (Action_Num_Code > X232_CM_TREBLE_SET_MAX)
        { //0-0x15
          X232_CM_buf[X232_CM_DATA_02_CODE_POS] = X232_CM_TREBLE_SET_MAX;
        }
        else
        {
          X232_CM_buf[X232_CM_DATA_02_CODE_POS] = Action_Num_Code;
        }

        CM_struct_buf[pos].treble_value = Action_Num_Code;
        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_TREBLE_SET;

        break;
      case END_CM_BASS_SET_CODE:   		//音响低音设定

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xAF;		//头码
        X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_BASS_SET_CODE;

        if (Action_Num_Code > X232_CM_BASS_SET_MAX)
        { //0x00-0x15
          X232_CM_buf[X232_CM_DATA_02_CODE_POS] = X232_CM_BASS_SET_MAX;
        }
        else
        {
          X232_CM_buf[X232_CM_DATA_02_CODE_POS] = Action_Num_Code;
        }

        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_BASS_SET;

        break;
      case END_CM_VOLUME_SET_CODE:      //音量设定

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xC0;		//头码
        X232_CM_buf[X232_CM_DATA_01_CODE_POS] = 0x00;

        X232_CM_buf[X232_CM_DATA_02_CODE_POS] = (Action_Num_Code * X232_CM_VOL_MAX) / 100;

        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_VOLUME_SET;

        break;
      case END_CM_TREBLE_ADJUST_CODE:   	//高音调整

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xAF;		//头码
        X232_CM_buf[X232_CM_DATA_02_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_VOLUME_UP_CODE:			//音量加

            X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_TREBLE_UP_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_UP;

            break;
          case END_CM_VOLUME_DOWN_CODE:		//音量减

            X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_TREBLE_DOWN_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_DOWN;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_BASS_ADJUST_CODE: 		//低音调整

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xAF;		//头码
        X232_CM_buf[X232_CM_DATA_02_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_VOLUME_UP_CODE:			//音量加

            X232_CM_buf[X232_CM_VOLUME_CODE_POS] = X232_CM_BASS_UP_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_BASS_ADJUST_UP;

            break;
          case END_CM_VOLUME_DOWN_CODE:		//音量减

            X232_CM_buf[X232_CM_VOLUME_CODE_POS] = X232_CM_BASS_DOWN_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_BASS_ADJUST_DOWN;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      default:

        instru_status = 0;

        break;
    }

    if (instru_status)
    { //指令有效
      X232_CM_buf[X232_CM_CHECK_SUM_CODE_POS] = Check_Sum(X232_CM_buf, X232_CHECK_SUM_LEN);		//校验位

      X485_Send(X232_CM_buf, X232_CM001_BUF_LEN);

      X232_CM_Data_Wait_beat_num = 0;
      X232_CM_Data_Wait_Flag = 1;
    }
  }
}

/*******************************************************************************
*																			查询函数																  *
*******************************************************************************/
void X232_CM_Sensing(CUINT8 Device_Addr_num)
{
  UINT8 pos;

  if ((Device_Addr_num >= X232_CM_ADDRESS_01_CODE)
      && (Device_Addr_num < (X232_CM_ADDRESS_01_CODE + X232_CM_ROAD_NUM)))
  { //判断路数正确
    pos = Device_Addr_num - X232_CM_ADDRESS_01_CODE;

    X232_CM_buf[X232_CM_HEAD_CODE_POS] = X232_CM_SENSING_HEAD_CODE;     					//起始码
    X232_CM_buf[X232_CM_ADDRESS_CODE_POS] =  pos;																	//路数
    X232_CM_buf[X232_CM_SENSING_DATA_01_POS] = X232_CM_SENSING_DATA_01_CODE;
    X232_CM_buf[X232_CM_SENSING_DATA_01_POS] = X232_CM_SENSING_DATA_02_CODE;
    X232_CM_buf[X232_CM_CHECK_SUM_CODE_POS] = Check_Sum(X232_CM_buf, X232_CHECK_SUM_LEN);		//校验位

    X485_Send(X232_CM_buf, X232_CM001_BUF_LEN);

    X232_CM_Operating_Road_Num_now = pos;
    X232_CM_Data_Wait_beat_num = 0;
    X232_CM_Data_Wait_Flag = 1;
    X232_CM_Sensing_Style = 1;
  }
}

/*******************************************************************************
*                            	 		指令反馈函数   			        		             *
*******************************************************************************/
UINT8   rxArray_buf[96] ;
void X232_CM_Data_Feedback()
{
  UINT8 i, pos, cycle_flag, temp;
  UINT8 power_status, run_mode, volume, source, mute,
        song_len, audio, play_mode, treble, bass;
  UINT8 SONG_NAME_OLD[SONG_NAME_NUM];

  cycle_flag = 0;

  for (i = 0; i < 96; i ++)
  {
    rxArray_buf[i] = 0;
  }

  //先进行数据判断,再进行数据处理
  while (QueueNotEmpty(rxArray_UART2))		//缓存非空
  {
    QueueDelete(&rxArray_UART2, &rxArray_buf[0]);

    switch (rxArray_buf[0])
    {
      case 0xE9:
      case 0xF1:
      case 0xF8:
      case 0xF2:
      case 0xF5:
      case 0xA3:
      case 0xCD:
      case 0xFC:

        for (i = 1; i < 5; i ++)
        {
          if (QueueDelete(&rxArray_UART2, &rxArray_buf[i]) == 0)
          { //队列已空
            //break;
            goto end;
          }
        }

        if (rxArray_buf[4] == Check_Sum(rxArray_buf, 3))
        { //校验码正确
          cycle_flag = 1;
        }
        else
        { //校验码错误，判断反馈数据是否多于5个字节
          for (i = 5; i < rxArray_buf[2]; i ++)
          {
            if (QueueDelete(&rxArray_UART2, &rxArray_buf[i]) == 0)
            { //队列已空
              //break;
              goto end;
            }
          }

          rxArray_buf[2] --;

          if (rxArray_buf[(rxArray_buf[2])] == Check_Sum(rxArray_buf, (rxArray_buf[2] - 1)))
          { //校验码正确
            cycle_flag = 1;

            rxArray_buf[2] ++;
          }
          else
          {
            cycle_flag = 0;
          }
        }

        break;
      default:

        cycle_flag = 0;

        break;
    }

    if (cycle_flag == 1)
    {
      if (rxArray_buf[X232_CM_ADDRESS_CODE_POS] <= 7)
      {
        pos = rxArray_buf[X232_CM_ADDRESS_CODE_POS];

        switch (CM_struct_buf[pos].online_status)
        {
          case 0x00:      //在线状态发生改变
          case 0x02:
          case 0x10:
          case 0x80:

            CM_struct_buf[pos].online_status = X232_CM_ONLINE_CODE;     //在线

            THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                (END_CM_ROAD_01_CODE + pos), END_CM_ONLINE_STATUS_CODE,
                                END_CM_ONLINE_CODE, END_NULL_CODE);

            break;
          case 0x08:
          case 0x40:

            CM_struct_buf[pos].online_status = X232_CM_ONLINE_CODE;     //在线

            break;
        }

        //控制反馈
        if (X232_CM_Control_Style)
        {
          switch (X232_CM_Control_Style)
          {
            case X232_CM_CONTROL_STYLE_POWER_ON:		//开机

              if ((rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xCD)
                  && (rxArray_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS] == 0x01))
              {
                CM_struct_buf[pos].power_status = 0x01;
                Feedback_Action_Flag = 1;

                THEnd_LED_Control(pos + END_LED_ROAD_01_CODE, END_LED_POWER_ON_CODE);

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_POWER_STATUS_CODE,
                                     END_CM_POWER_ON_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_POWER_OFF:		//关机

              if ((rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xCD)
                  && (rxArray_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS] == 0x00))
              {
                CM_struct_buf[pos].power_status = 0x00;
                Feedback_Action_Flag = 1;

                THEnd_LED_Control(pos + END_LED_ROAD_01_CODE, END_LED_POWER_OFF_CODE);

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_POWER_STATUS_CODE,
                                     END_CM_POWER_OFF_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_PAUSE:		//暂停

              if ((rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xE9)
                  && (rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] == 0x02))
              {
                CM_struct_buf[pos].run_mode = 0x00;
                Feedback_Action_Flag = 1;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_RUN_MODE_CODE,
                                     END_CM_RUN_MODE_PAUSE_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_PLAY:		//播放

              if ((rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xCD)
                  && (rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] == 0x03))
              {
                CM_struct_buf[pos].run_mode = 0x01;
                Feedback_Action_Flag = 1;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_RUN_MODE_CODE,
                                     END_CM_RUN_MODE_PLAY_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_CHANNEL_FORW:		//上一曲

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xF1)
              {
                song_len = rxArray_buf[2] - 5;
                Feedback_Action_Flag = 1;

                if (song_len >= SONG_NAME_NUM)
                { //节目名称长度超过限定范围
                  song_len = SONG_NAME_NUM - 1;
                }

                CM_struct_buf[pos].song_name[0] = END_CM_SONG_NAME_GB2312_CODE;

                for (i = 0; i < song_len; i ++)
                {
                  if (CM_struct_buf[pos].song_name[i + 1] != rxArray_buf[4 + i])
                  {
                    CM_struct_buf[pos].song_name[i + 1] = rxArray_buf[4 + i];
                  }
                }

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_CHANNEL_SET_CODE,
                                     END_CM_CHANNEL_FORW_CODE, END_NULL_CODE);

                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_SONG_NAME_CODE,
                                    (song_len + 1), CM_struct_buf[pos].song_name);
              }

              break;
            case X232_CM_CONTROL_STYLE_CHANNEL_BACKW:		//下一曲

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xF1)
              {
                song_len = rxArray_buf[2] - 5;
                Feedback_Action_Flag = 1;

                if (song_len >= SONG_NAME_NUM)
                { //节目名称长度超过限定范围
                  song_len = SONG_NAME_NUM - 1;
                }

                for (i = 0; i < song_len; i ++)
                {
                  CM_struct_buf[pos].song_name[i]  = 0;
                }

                CM_struct_buf[pos].song_name[0] = END_CM_SONG_NAME_GB2312_CODE;

                for (i = 0; i < song_len; i ++)
                {
                  if (CM_struct_buf[pos].song_name[i + 1] != rxArray_buf[4 + i])
                  {
                    CM_struct_buf[pos].song_name[i + 1]  = rxArray_buf[4 + i];


                  }
                }

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_CHANNEL_SET_CODE,
                                     END_CM_CHANNEL_BACKW_CODE, END_NULL_CODE);

                delay50ms();

                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_SONG_NAME_CODE,
                                    (song_len + 1), CM_struct_buf[pos].song_name);


                for (i = 0; i < song_len; i ++)
                {
                  CM_struct_buf[pos].song_name[i + 1]  = 0;
                  SONG_NAME_OLD[i] = rxArray_buf[4 + i];
                }

              }


              break;
            case X232_CM_CONTROL_STYLE_VOLUME_UP:		//音量+

              if ((rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xA3)
                  && (rxArray_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS]
                      == (CM_struct_buf[pos].volume_value + 1)))
              {
                CM_struct_buf[pos].volume_value ++;
                Feedback_Action_Flag = 1;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_VOLUME_ADJUST_CODE,
                                     END_CM_VOLUME_UP_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_VOLUME_DOWN:		//音量-

              if ((rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xA3)
                  && (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS]
                      == (CM_struct_buf[pos].volume_value - 1)))
              {
                CM_struct_buf[pos].volume_value --;
                Feedback_Action_Flag = 1;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_VOLUME_ADJUST_CODE,
                                     END_CM_VOLUME_DOWN_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_SOURCE_SET:		//音源

              if ((rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xA3)
                  && (rxArray_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS]
                      == CM_struct_buf[pos].volume_value))
              {
                switch ((rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] & 0x0f))
                {
                  case 0x06:	//DVD

                    CM_struct_buf[pos].source_value = 0;
                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                         END_CM_SOURCE_DVD_CODE, END_NULL_CODE);

                    break;
                  case 0x05:	//FM

                    CM_struct_buf[pos].source_value = 1;
                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                         END_CM_SOURCE_FM_CODE, END_NULL_CODE);

                    break;
                  case 0x03:	//MP3

                    CM_struct_buf[pos].source_value = 2;
                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                         END_CM_SOURCE_USB_CODE, END_NULL_CODE);

                    break;
                  case 0x07:	//AUX

                    CM_struct_buf[pos].source_value = 3;
                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                         END_CM_SOURCE_AUX_CODE, END_NULL_CODE);

                    break;
                  case 0x09:	//IPOD

                    CM_struct_buf[pos].source_value = 5;
                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                         END_CM_SOURCE_IPOD_CODE, END_NULL_CODE);

                    break;
                }
              }

              break;
            case X232_CM_CONTROL_STYLE_MUTE_ON:	//静音

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAB)
              {
                CM_struct_buf[pos].mute_status = 0x01;
                Feedback_Action_Flag = 1;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_MUTE_STATUS_CODE,
                                     END_CM_MUTE_ON_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_MUTE_OFF:	//解除静音

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAB)
              {
                CM_struct_buf[pos].mute_status = 0x00;
                Feedback_Action_Flag = 1;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_MUTE_STATUS_CODE,
                                     END_CM_MUTE_OFF_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_PLAY_MODE:	//单曲操作

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xE9)
              {
                if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] == 0x05)
                { //单曲播放
                  CM_struct_buf[pos].play_mode = 0x01;
                  Feedback_Action_Flag = 1;

                  THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                       (END_CM_ROAD_01_CODE + pos), END_CM_PLAY_MODE_CODE,
                                       END_CM_MODE_SINGLE_PLAY_CODE, END_NULL_CODE);
                }
                else if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] == 0x07)
                { //顺序播放
                  CM_struct_buf[pos].play_mode = 0x00;
                  Feedback_Action_Flag = 1;

                  THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                       (END_CM_ROAD_01_CODE + pos), END_CM_PLAY_MODE_CODE,
                                       END_CM_MODE_ORDER_PLAY_CODE, END_NULL_CODE);
                }
              }

              break;
            case 	X232_CM_CONTROL_STYLE_AUDIO_SET:	//播放音效

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xA3)
              {
                CM_struct_buf[pos].audio_value = rxArray_buf[3] >> 4;

                switch (CM_struct_buf[pos].audio_value)
                {
                  case X232_CM_AUDIO_NORMAL_CODE:		//标准

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_NORMAL_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_POP_CODE:		//流行

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_POP_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_SOFT_CODE:		//柔和/平滑

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_SOFT_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_CLASSIC_CODE:		//古典

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_CLASSIC_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_JAZZ_CODE:		//爵士

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_JAZZ_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_ROCK_CODE:		//摇滚

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_ROCK_CODE, END_NULL_CODE);

                    break;
                }
              }

              break;
            case X232_CM_CONTROL_STYLE_TREBLE_SET:	//高音设定

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].treble_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_TREBLE_SET_CODE,
                                     CM_struct_buf[pos].treble_value, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_BASS_SET:	//低音设定

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].bass_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_BASS_SET_CODE,
                                     CM_struct_buf[pos].bass_value, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_VOLUME_SET:	//音量设定

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xA3)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].volume_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS];
                temp = CM_struct_buf[pos].volume_value * 100 / X232_CM_VOL_MAX;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_VOLUME_SET_CODE, temp, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_UP: 	//高音+

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].treble_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_TREBLE_ADJUST_CODE,
                                     END_CM_VOLUME_UP_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_DOWN:	//高音-

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].treble_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_TREBLE_ADJUST_CODE,
                                     END_CM_VOLUME_DOWN_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_BASS_ADJUST_UP:	//低音+

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].bass_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_BASS_ADJUST_CODE,
                                     END_CM_VOLUME_UP_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_BASS_ADJUST_DOWN:	//低音-

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].bass_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_BASS_ADJUST_CODE,
                                     END_CM_VOLUME_DOWN_CODE, END_NULL_CODE);
              }

              break;
          }

          X232_CM_Control_Style = 0;
        }
        else if (X232_CM_Sensing_Style)
        {
          //查询反馈
          if (rxArray_buf[0] == 0xFC)
          {
            power_status = rxArray_buf[X232_CM_SENSING_DATA_CODE_POS] & 0x01;
            run_mode = (rxArray_buf[X232_CM_SENSING_DATA_CODE_POS] >> 1) & 0x01;
            mute = (rxArray_buf[X232_CM_SENSING_DATA_CODE_POS] >> 2) & 0x01;
            play_mode = (rxArray_buf[X232_CM_SENSING_DATA_CODE_POS] >> 3) & 0x01;
            volume = rxArray_buf[X232_CM_SENSING_VOLUME_CODE_POS];
            source = rxArray_buf[X232_CM_SENSING_SOURCE_CODE_POS] & 0x0f;
            audio = rxArray_buf[12] >> 4;
            treble = rxArray_buf[X232_CM_TREBLE_BASS_CODE_POS] >> 4;
            bass = rxArray_buf[X232_CM_TREBLE_BASS_CODE_POS] & 0x0f;

            if (CM_struct_buf[pos].power_status != power_status)
            { //开关状态发生改变
              CM_struct_buf[pos].power_status = power_status;

              if (power_status == 0x01)
              {
                THEnd_LED_Control(pos + END_LED_ROAD_01_CODE, END_LED_POWER_ON_CODE);

                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_POWER_STATUS_CODE,
                                    END_CM_POWER_ON_CODE, END_NULL_CODE);
              }
              else
              {
                THEnd_LED_Control(pos + END_LED_ROAD_01_CODE, END_LED_POWER_OFF_CODE);

                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_POWER_STATUS_CODE,
                                    END_CM_POWER_OFF_CODE, END_NULL_CODE);
              }
            }

            //按键背光灯
            if (CM_struct_buf[pos].power_status == 0x01)
            {
              THEnd_LED_Control(pos + END_LED_ROAD_01_CODE, END_LED_POWER_ON_CODE);
            }
            else
            {
              THEnd_LED_Control(pos + END_LED_ROAD_01_CODE, END_LED_POWER_OFF_CODE);
            }

            if (CM_struct_buf[pos].run_mode != run_mode)
            { //运行状态发生改变
              CM_struct_buf[pos].run_mode = run_mode;

              if (run_mode == 0x00)
              {
                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_RUN_MODE_CODE,
                                    END_CM_RUN_MODE_PAUSE_CODE, END_NULL_CODE);
              }
              else
              {
                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_RUN_MODE_CODE,
                                    END_CM_RUN_MODE_PLAY_CODE, END_NULL_CODE);
              }
            }

            if (CM_struct_buf[pos].volume_value != volume)
            { //音量发生改变
              CM_struct_buf[pos].volume_value = volume;
              temp = volume * 100 / X232_CM_VOL_MAX;

              THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                  (END_CM_ROAD_01_CODE + pos), END_CM_VOLUME_SET_CODE, temp, END_NULL_CODE);
            }

            if (CM_struct_buf[pos].mute_status != mute)
            { //静音状态发生改变
              CM_struct_buf[pos].mute_status = mute;

              if (mute == 0x00)
              {
                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_MUTE_STATUS_CODE,
                                    END_CM_MUTE_OFF_CODE, END_NULL_CODE);
              }
              else
              {
                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_MUTE_STATUS_CODE,
                                    END_CM_MUTE_ON_CODE, END_NULL_CODE);
              }
            }

            if (CM_struct_buf[pos].source_value != source)
            { //音源发生改变
              CM_struct_buf[pos].source_value = source;

              switch (source)
              {
                case 0:	//DVD

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                      END_CM_SOURCE_DVD_CODE, END_NULL_CODE);

                  break;
                case 1:	//FM

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                      END_CM_SOURCE_FM_CODE, END_NULL_CODE);

                  break;
                case 2:	//MP3

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                      END_CM_SOURCE_USB_CODE, END_NULL_CODE);

                  break;
                case 3:	//AUX

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                      END_CM_SOURCE_AUX_CODE, END_NULL_CODE);

                  break;
                case 5:	//IPOD

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_SOURCE_SET_CODE,
                                      END_CM_SOURCE_IPOD_CODE, END_NULL_CODE);

                  break;
              }
            }

            if (CM_struct_buf[pos].audio_value != audio)
            { //音效发生改变
              CM_struct_buf[pos].audio_value = audio;

              switch (audio)
              {
                case X232_CM_AUDIO_NORMAL_CODE:		//标准

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_NORMAL_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_POP_CODE:		//流行

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_POP_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_SOFT_CODE:		//柔和/平滑

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_SOFT_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_CLASSIC_CODE:		//古典

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_CLASSIC_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_JAZZ_CODE:		//爵士

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_JAZZ_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_ROCK_CODE:		//摇滚

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_ROCK_CODE, END_NULL_CODE);

                  break;
              }
            }

            if (CM_struct_buf[pos].play_mode != play_mode)
            { //播放模式发生改变
              CM_struct_buf[pos].play_mode = play_mode;

              if (play_mode == 0x01)
              { //单曲播放
                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_PLAY_MODE_CODE,
                                    END_CM_MODE_SINGLE_PLAY_CODE, END_NULL_CODE);
              }
              else if (play_mode == 0x02)
              { //顺序播放
                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_PLAY_MODE_CODE,
                                    END_CM_MODE_ORDER_PLAY_CODE, END_NULL_CODE);
              }
            }

            if (CM_struct_buf[pos].treble_value != treble)
            { //高音状态发生改变
              CM_struct_buf[pos].treble_value = treble;

              THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                  (END_CM_ROAD_01_CODE + pos), END_CM_TREBLE_SET_CODE, treble, END_NULL_CODE);
            }

            if (CM_struct_buf[pos].bass_value != bass)
            { //低音状态发生改变
              CM_struct_buf[pos].bass_value = bass;

              THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                  (END_CM_ROAD_01_CODE + pos), END_CM_BASS_SET_CODE, bass, END_NULL_CODE);
            }
          }

          if (rxArray_buf[0] == 0xF1)
          {
            song_len = rxArray_buf[2] - 5;

            if (song_len >= SONG_NAME_NUM)
            { //节目名称长度超过限定范围
              song_len = SONG_NAME_NUM - 1;
            }

            for (i = 0; i < song_len; i ++)
            {
              if (CM_struct_buf[pos].song_name[i + 1] != rxArray_buf[4 + i])
              { //歌曲名发生改变
                CM_struct_buf[pos].song_name[0] = END_CM_SONG_NAME_GB2312_CODE;
                Feedback_Action_Flag = 1;

                for (i = 0; i < song_len; i ++)
                {
                  if (CM_struct_buf[pos].song_name[i + 1] != rxArray_buf[4 + i])
                  {
                    CM_struct_buf[pos].song_name[i + 1] = rxArray_buf[4 + i];
                  }
                }

                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_SONG_NAME_CODE,
                                    (song_len + 1), CM_struct_buf[pos].song_name);

                break;
              }
            }
          }

          X232_CM_Sensing_Style = 0;
        }
        else
        { //主动上报
          if (rxArray_buf[0] == 0xF1)
          {
            song_len = rxArray_buf[2] - 5;

            if (song_len >= SONG_NAME_NUM)
            { //节目名称长度超过限定范围
              song_len = SONG_NAME_NUM - 1;
            }

            for (i = 0; i < song_len; i ++)
            {
              if (CM_struct_buf[pos].song_name[i + 1] != rxArray_buf[4 + i])
              {
                UINT8 j;

                CM_struct_buf[pos].song_name[0] = END_CM_SONG_NAME_GB2312_CODE;

                for (j = 0; j < song_len; j ++)
                {
                  if (CM_struct_buf[pos].song_name[j + 1] != rxArray_buf[4 + j])
                  {
                    CM_struct_buf[pos].song_name[j + 1] = rxArray_buf[4 + j];
                  }
                }

                Feedback_Action_Flag = 1;

                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_SONG_NAME_CODE,
                                    (song_len + 1), CM_struct_buf[pos].song_name);

                break;
              }
            }
          }
        }
      }

      if (Feedback_Action_Flag == 1)
      { //数据已处理，退出函数
        Feedback_Action_Flag = 0;

        X232_CM_Operating_Road_Num_now = X232_CM_ROAD_NUM;
        cycle_flag = 0;

        break;
      }
      else
      {
        continue;
      }
    }
    else
    {
      continue;
    }
  }

end:

  X232_CM_Operating_Road_Num_now = X232_CM_ROAD_NUM;
  cycle_flag = 0;
}

/********************************************************************************
*																	NO MORE CODE																	*
********************************************************************************/
