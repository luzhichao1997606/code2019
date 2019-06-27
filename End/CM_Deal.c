#include "variable.h"
void delay50ms(void)   //��� 0us
{
  unsigned char a, b, c;
  for (c = 151; c > 0; c--)
    for (b = 107; b > 0; b--)
      for (a = 48; a > 0; a--);

}


/*******************************************************************************
*                         		  			���ƺ��� 			     	           	         *
*******************************************************************************/
void X232_CM_Control(CUINT8 Device_Road_num,     	   //�����豸·��
                     CUINT8 Action_Type_Code,         //����������
                     CUINT8 Action_Num_Code           //������ֵ��
                    )
{
  if ((Device_Road_num >= END_CM_ROAD_01_CODE)
      && (Device_Road_num < (END_CM_ROAD_01_CODE + X232_CM_ROAD_NUM)))
  { //���ж�·����ȷ
    UINT8 pos, instru_status;

    instru_status = 1;
    pos = Device_Road_num - END_CM_ROAD_01_CODE;

    X232_CM_buf[X232_CM_HEAD_CODE_POS] = X232_CM_HEAD_CODE;		//ͷ��
    X232_CM_buf[X232_CM_ADDRESS_CODE_POS] = pos;							//·��

    switch (Action_Type_Code)
    {
      case END_CM_POWER_STATUS_CODE:		//���ػ�ģʽ

        switch (Action_Num_Code)
        {
          case END_CM_POWER_ON_CODE:		//����

            X232_CM_buf[X232_CM_POWER_STATUS_CODE_POS] = X232_POWER_STATUS_ON_CODE;
            X232_CM_buf[X232_CM_SOURCE_CODE_POS]	= 0;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_POWER_ON;

            break;
          case END_CM_POWER_OFF_CODE:		//�ػ�

            X232_CM_buf[X232_CM_POWER_STATUS_CODE_POS] = X232_POWER_STATUS_OFF_CODE;
            X232_CM_buf[X232_CM_SOURCE_CODE_POS]	= 0;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_POWER_OFF;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_RUN_MODE_CODE:    //��ͣ��ʼ

        switch (Action_Num_Code)
        {
          case END_CM_RUN_MODE_PAUSE_CODE:		//��ͣ

            X232_CM_buf[X232_CM_RUN_MODE_FLAG_POS] = X232_CM_RUN_MODE_FLAG;
            X232_CM_buf[X232_CM_RUN_MODE_CODE_POS] = X232_CM_RUN_MODE_PAUSE_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_PAUSE;

            break;
          case END_CM_RUN_MODE_PLAY_CODE:			//����

            X232_CM_buf[X232_CM_RUN_MODE_FLAG_POS] = X232_CM_RUN_MODE_FLAG;
            X232_CM_buf[X232_CM_RUN_MODE_CODE_POS] = X232_CM_RUN_MODE_PLAY_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_PLAY;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_CHANNEL_SET_CODE: 		//Ƶ��ѡ��

        switch (Action_Num_Code)
        {
          case END_CM_CHANNEL_FORW_CODE:		//��һ��

            X232_CM_buf[X232_CM_CHANNEL_CODE_POS] = X232_CM_CHANNEL_FORW_CODE;
            X232_CM_buf[X232_CM_SOURCE_CODE_POS] = 2;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_CHANNEL_FORW;

            break;
          case END_CM_CHANNEL_BACKW_CODE:		//��һ��

            X232_CM_buf[X232_CM_CHANNEL_CODE_POS] = X232_CM_CHANNEL_BACKW_CODE;
            X232_CM_buf[X232_CM_SOURCE_CODE_POS] = 2;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_CHANNEL_BACKW;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_VOLUME_ADJUST_CODE:  		//��������

        switch (Action_Num_Code)
        {
          case END_CM_VOLUME_UP_CODE:			//������

            X232_CM_buf[X232_CM_VOLUME_CODE_POS] = X232_CM_VOLUME_UP_CODE;
            X232_CM_buf[X232_CM_VOLUME_DATA_CODE_POS] = 1;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_VOLUME_UP;

            break;
          case END_CM_VOLUME_DOWN_CODE:		//������

            X232_CM_buf[X232_CM_VOLUME_CODE_POS] = X232_CM_VOLUME_DOWN_CODE;
            X232_CM_buf[X232_CM_VOLUME_DATA_CODE_POS] = 1;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_VOLUME_DOWN;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_SOURCE_SET_CODE:			//��Դ�趨

        X232_CM_buf[X232_CM_SOURCE_NULL_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_SOURCE_FM_CODE:			//��ԴFM

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_FM_CODE;

            break;
          case END_CM_SOURCE_USB_CODE:		//��ԴUSB/MP3

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_MP3_CODE;

            break;
          case END_CM_SOURCE_AUX_CODE:		//��ԴAUX

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_AUX_CODE;

            break;
          case END_CM_SOURCE_DVD_CODE:		//��ԴDVD

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_DVD_CODE;

            break;
          case END_CM_SOURCE_IPOD_CODE:		//��ԴIPOD

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_IPOD_CODE;

          case END_CM_SOURCE_NET_CODE:		//��ԴNET_RIDIO

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_NET_RADIO_CODE;

          case END_CM_SOURCE_NET2_CODE:		//��ԴCLOUD

            X232_CM_buf[X232_CM_SOURCE_VALUE_CODE_POS] = X232_CM_SOURCE_CLOUD_CODE;

            break;
          default:

            instru_status = 0;

            break;
        }

        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_SOURCE_SET;

        break;
      case END_CM_MUTE_STATUS_CODE:			//��������

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xab;
        X232_CM_buf[X232_CM_DATA_02_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_MUTE_ON_CODE:		//����

            X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_MUTE_ON_CODE;
            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_MUTE_ON;

            break;
          case END_CM_MUTE_OFF_CODE:		//����ȡ��

            X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_MUTE_OFF_CODE;
            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_MUTE_OFF;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_PLAY_MODE_CODE:			//����ģʽ

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xEA;		//ͷ��
        X232_CM_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS] = 0x01;

        switch (Action_Num_Code)
        {
          case END_CM_MODE_SINGLE_REPEAT_CODE:		//����ѭ��

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = 0x01;

            break;
          case END_CM_MODE_ORDER_PLAY_CODE:		//˳�򲥷�

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = 0x00;

            break;
          default:

            instru_status = 0;

            break;
        }

        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_PLAY_MODE;

        break;
      case END_CM_AUDIO_SET_CODE:    	//������Ч�趨

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xA4;		//ͷ��
        X232_CM_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_AUDIO_NORMAL_CODE:		//��׼

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_NORMAL_CODE;

            break;
          case END_CM_AUDIO_POP_CODE:		//����

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_POP_CODE;

            break;
          case END_CM_AUDIO_SOFT_CODE:		//���/ƽ��

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_SOFT_CODE;

            break;
          case END_CM_AUDIO_CLASSIC_CODE:		//�ŵ�

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_CLASSIC_CODE;

            break;
          case END_CM_AUDIO_JAZZ_CODE:		//��ʿ

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_JAZZ_CODE;

            break;
          case END_CM_AUDIO_ROCK_CODE:		//ҡ��

            X232_CM_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] = X232_CM_AUDIO_ROCK_CODE;

            break;
          default:

            instru_status = 0;

            break;
        }

        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_AUDIO_SET;

        break;
      case END_CM_TREBLE_SET_CODE:    //��������趨

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xAF;		//ͷ��
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
      case END_CM_BASS_SET_CODE:   		//��������趨

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xAF;		//ͷ��
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
      case END_CM_VOLUME_SET_CODE:      //�����趨

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xC0;		//ͷ��
        X232_CM_buf[X232_CM_DATA_01_CODE_POS] = 0x00;

        X232_CM_buf[X232_CM_DATA_02_CODE_POS] = (Action_Num_Code * X232_CM_VOL_MAX) / 100;

        X232_CM_Control_Style = X232_CM_CONTROL_STYLE_VOLUME_SET;

        break;
      case END_CM_TREBLE_ADJUST_CODE:   	//��������

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xAF;		//ͷ��
        X232_CM_buf[X232_CM_DATA_02_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_VOLUME_UP_CODE:			//������

            X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_TREBLE_UP_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_UP;

            break;
          case END_CM_VOLUME_DOWN_CODE:		//������

            X232_CM_buf[X232_CM_DATA_01_CODE_POS] = X232_CM_TREBLE_DOWN_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_DOWN;

            break;
          default:

            instru_status = 0;

            break;
        }

        break;
      case END_CM_BASS_ADJUST_CODE: 		//��������

        X232_CM_buf[X232_CM_HEAD_CODE_POS] = 0xAF;		//ͷ��
        X232_CM_buf[X232_CM_DATA_02_CODE_POS] = 0x00;

        switch (Action_Num_Code)
        {
          case END_CM_VOLUME_UP_CODE:			//������

            X232_CM_buf[X232_CM_VOLUME_CODE_POS] = X232_CM_BASS_UP_CODE;

            X232_CM_Control_Style = X232_CM_CONTROL_STYLE_BASS_ADJUST_UP;

            break;
          case END_CM_VOLUME_DOWN_CODE:		//������

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
    { //ָ����Ч
      X232_CM_buf[X232_CM_CHECK_SUM_CODE_POS] = Check_Sum(X232_CM_buf, X232_CHECK_SUM_LEN);		//У��λ

      X485_Send(X232_CM_buf, X232_CM001_BUF_LEN);

      X232_CM_Data_Wait_beat_num = 0;
      X232_CM_Data_Wait_Flag = 1;
    }
  }
}

/*******************************************************************************
*																			��ѯ����																  *
*******************************************************************************/
void X232_CM_Sensing(CUINT8 Device_Addr_num)
{
  UINT8 pos;

  if ((Device_Addr_num >= X232_CM_ADDRESS_01_CODE)
      && (Device_Addr_num < (X232_CM_ADDRESS_01_CODE + X232_CM_ROAD_NUM)))
  { //�ж�·����ȷ
    pos = Device_Addr_num - X232_CM_ADDRESS_01_CODE;

    X232_CM_buf[X232_CM_HEAD_CODE_POS] = X232_CM_SENSING_HEAD_CODE;     					//��ʼ��
    X232_CM_buf[X232_CM_ADDRESS_CODE_POS] =  pos;																	//·��
    X232_CM_buf[X232_CM_SENSING_DATA_01_POS] = X232_CM_SENSING_DATA_01_CODE;
    X232_CM_buf[X232_CM_SENSING_DATA_01_POS] = X232_CM_SENSING_DATA_02_CODE;
    X232_CM_buf[X232_CM_CHECK_SUM_CODE_POS] = Check_Sum(X232_CM_buf, X232_CHECK_SUM_LEN);		//У��λ

    X485_Send(X232_CM_buf, X232_CM001_BUF_LEN);

    X232_CM_Operating_Road_Num_now = pos;
    X232_CM_Data_Wait_beat_num = 0;
    X232_CM_Data_Wait_Flag = 1;
    X232_CM_Sensing_Style = 1;
  }
}

/*******************************************************************************
*                            	 		ָ�������   			        		             *
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

  //�Ƚ��������ж�,�ٽ������ݴ���
  while (QueueNotEmpty(rxArray_UART2))		//����ǿ�
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
          { //�����ѿ�
            //break;
            goto end;
          }
        }

        if (rxArray_buf[4] == Check_Sum(rxArray_buf, 3))
        { //У������ȷ
          cycle_flag = 1;
        }
        else
        { //У��������жϷ��������Ƿ����5���ֽ�
          for (i = 5; i < rxArray_buf[2]; i ++)
          {
            if (QueueDelete(&rxArray_UART2, &rxArray_buf[i]) == 0)
            { //�����ѿ�
              //break;
              goto end;
            }
          }

          rxArray_buf[2] --;

          if (rxArray_buf[(rxArray_buf[2])] == Check_Sum(rxArray_buf, (rxArray_buf[2] - 1)))
          { //У������ȷ
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
          case 0x00:      //����״̬�����ı�
          case 0x02:
          case 0x10:
          case 0x80:

            CM_struct_buf[pos].online_status = X232_CM_ONLINE_CODE;     //����

            THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                (END_CM_ROAD_01_CODE + pos), END_CM_ONLINE_STATUS_CODE,
                                END_CM_ONLINE_CODE, END_NULL_CODE);

            break;
          case 0x08:
          case 0x40:

            CM_struct_buf[pos].online_status = X232_CM_ONLINE_CODE;     //����

            break;
        }

        //���Ʒ���
        if (X232_CM_Control_Style)
        {
          switch (X232_CM_Control_Style)
          {
            case X232_CM_CONTROL_STYLE_POWER_ON:		//����

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
            case X232_CM_CONTROL_STYLE_POWER_OFF:		//�ػ�

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
            case X232_CM_CONTROL_STYLE_PAUSE:		//��ͣ

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
            case X232_CM_CONTROL_STYLE_PLAY:		//����

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
            case X232_CM_CONTROL_STYLE_CHANNEL_FORW:		//��һ��

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xF1)
              {
                song_len = rxArray_buf[2] - 5;
                Feedback_Action_Flag = 1;

                if (song_len >= SONG_NAME_NUM)
                { //��Ŀ���Ƴ��ȳ����޶���Χ
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
            case X232_CM_CONTROL_STYLE_CHANNEL_BACKW:		//��һ��

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xF1)
              {
                song_len = rxArray_buf[2] - 5;
                Feedback_Action_Flag = 1;

                if (song_len >= SONG_NAME_NUM)
                { //��Ŀ���Ƴ��ȳ����޶���Χ
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
            case X232_CM_CONTROL_STYLE_VOLUME_UP:		//����+

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
            case X232_CM_CONTROL_STYLE_VOLUME_DOWN:		//����-

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
            case X232_CM_CONTROL_STYLE_SOURCE_SET:		//��Դ

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
            case X232_CM_CONTROL_STYLE_MUTE_ON:	//����

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAB)
              {
                CM_struct_buf[pos].mute_status = 0x01;
                Feedback_Action_Flag = 1;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_MUTE_STATUS_CODE,
                                     END_CM_MUTE_ON_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_MUTE_OFF:	//�������

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAB)
              {
                CM_struct_buf[pos].mute_status = 0x00;
                Feedback_Action_Flag = 1;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_MUTE_STATUS_CODE,
                                     END_CM_MUTE_OFF_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_PLAY_MODE:	//��������

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xE9)
              {
                if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] == 0x05)
                { //��������
                  CM_struct_buf[pos].play_mode = 0x01;
                  Feedback_Action_Flag = 1;

                  THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                       (END_CM_ROAD_01_CODE + pos), END_CM_PLAY_MODE_CODE,
                                       END_CM_MODE_SINGLE_PLAY_CODE, END_NULL_CODE);
                }
                else if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS] == 0x07)
                { //˳�򲥷�
                  CM_struct_buf[pos].play_mode = 0x00;
                  Feedback_Action_Flag = 1;

                  THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                       (END_CM_ROAD_01_CODE + pos), END_CM_PLAY_MODE_CODE,
                                       END_CM_MODE_ORDER_PLAY_CODE, END_NULL_CODE);
                }
              }

              break;
            case 	X232_CM_CONTROL_STYLE_AUDIO_SET:	//������Ч

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xA3)
              {
                CM_struct_buf[pos].audio_value = rxArray_buf[3] >> 4;

                switch (CM_struct_buf[pos].audio_value)
                {
                  case X232_CM_AUDIO_NORMAL_CODE:		//��׼

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_NORMAL_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_POP_CODE:		//����

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_POP_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_SOFT_CODE:		//���/ƽ��

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_SOFT_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_CLASSIC_CODE:		//�ŵ�

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_CLASSIC_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_JAZZ_CODE:		//��ʿ

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_JAZZ_CODE, END_NULL_CODE);

                    break;
                  case X232_CM_AUDIO_ROCK_CODE:		//ҡ��

                    Feedback_Action_Flag = 1;

                    THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                         (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                         END_CM_AUDIO_ROCK_CODE, END_NULL_CODE);

                    break;
                }
              }

              break;
            case X232_CM_CONTROL_STYLE_TREBLE_SET:	//�����趨

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].treble_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_TREBLE_SET_CODE,
                                     CM_struct_buf[pos].treble_value, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_BASS_SET:	//�����趨

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].bass_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_BASS_SET_CODE,
                                     CM_struct_buf[pos].bass_value, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_VOLUME_SET:	//�����趨

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xA3)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].volume_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_03_CODE_POS];
                temp = CM_struct_buf[pos].volume_value * 100 / X232_CM_VOL_MAX;

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_VOLUME_SET_CODE, temp, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_UP: 	//����+

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].treble_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_TREBLE_ADJUST_CODE,
                                     END_CM_VOLUME_UP_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_TREBLE_ADJUST_VOL_DOWN:	//����-

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].treble_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_TREBLE_ADJUST_CODE,
                                     END_CM_VOLUME_DOWN_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_BASS_ADJUST_UP:	//����+

              if (rxArray_buf[X232_CM_CONTROL_FEED_DATA_01_CODE_POS] == 0xAF)
              {
                Feedback_Action_Flag = 1;
                CM_struct_buf[pos].bass_value = rxArray_buf[X232_CM_CONTROL_FEED_DATA_04_CODE_POS];

                THNet_Control_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                     (END_CM_ROAD_01_CODE + pos), END_CM_BASS_ADJUST_CODE,
                                     END_CM_VOLUME_UP_CODE, END_NULL_CODE);
              }

              break;
            case X232_CM_CONTROL_STYLE_BASS_ADJUST_DOWN:	//����-

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
          //��ѯ����
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
            { //����״̬�����ı�
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

            //���������
            if (CM_struct_buf[pos].power_status == 0x01)
            {
              THEnd_LED_Control(pos + END_LED_ROAD_01_CODE, END_LED_POWER_ON_CODE);
            }
            else
            {
              THEnd_LED_Control(pos + END_LED_ROAD_01_CODE, END_LED_POWER_OFF_CODE);
            }

            if (CM_struct_buf[pos].run_mode != run_mode)
            { //����״̬�����ı�
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
            { //���������ı�
              CM_struct_buf[pos].volume_value = volume;
              temp = volume * 100 / X232_CM_VOL_MAX;

              THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                  (END_CM_ROAD_01_CODE + pos), END_CM_VOLUME_SET_CODE, temp, END_NULL_CODE);
            }

            if (CM_struct_buf[pos].mute_status != mute)
            { //����״̬�����ı�
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
            { //��Դ�����ı�
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
            { //��Ч�����ı�
              CM_struct_buf[pos].audio_value = audio;

              switch (audio)
              {
                case X232_CM_AUDIO_NORMAL_CODE:		//��׼

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_NORMAL_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_POP_CODE:		//����

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_POP_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_SOFT_CODE:		//���/ƽ��

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_SOFT_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_CLASSIC_CODE:		//�ŵ�

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_CLASSIC_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_JAZZ_CODE:		//��ʿ

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_JAZZ_CODE, END_NULL_CODE);

                  break;
                case X232_CM_AUDIO_ROCK_CODE:		//ҡ��

                  THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                      (END_CM_ROAD_01_CODE + pos), END_CM_AUDIO_SET_CODE,
                                      END_CM_AUDIO_ROCK_CODE, END_NULL_CODE);

                  break;
              }
            }

            if (CM_struct_buf[pos].play_mode != play_mode)
            { //����ģʽ�����ı�
              CM_struct_buf[pos].play_mode = play_mode;

              if (play_mode == 0x01)
              { //��������
                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_PLAY_MODE_CODE,
                                    END_CM_MODE_SINGLE_PLAY_CODE, END_NULL_CODE);
              }
              else if (play_mode == 0x02)
              { //˳�򲥷�
                THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                    (END_CM_ROAD_01_CODE + pos), END_CM_PLAY_MODE_CODE,
                                    END_CM_MODE_ORDER_PLAY_CODE, END_NULL_CODE);
              }
            }

            if (CM_struct_buf[pos].treble_value != treble)
            { //����״̬�����ı�
              CM_struct_buf[pos].treble_value = treble;

              THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                  (END_CM_ROAD_01_CODE + pos), END_CM_TREBLE_SET_CODE, treble, END_NULL_CODE);
            }

            if (CM_struct_buf[pos].bass_value != bass)
            { //����״̬�����ı�
              CM_struct_buf[pos].bass_value = bass;

              THNet_Status_Report(END_DEVICE_HOST_ADDR_CODE, END_DEVICE_TYPE_CM_CODE,
                                  (END_CM_ROAD_01_CODE + pos), END_CM_BASS_SET_CODE, bass, END_NULL_CODE);
            }
          }

          if (rxArray_buf[0] == 0xF1)
          {
            song_len = rxArray_buf[2] - 5;

            if (song_len >= SONG_NAME_NUM)
            { //��Ŀ���Ƴ��ȳ����޶���Χ
              song_len = SONG_NAME_NUM - 1;
            }

            for (i = 0; i < song_len; i ++)
            {
              if (CM_struct_buf[pos].song_name[i + 1] != rxArray_buf[4 + i])
              { //�����������ı�
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
        { //�����ϱ�
          if (rxArray_buf[0] == 0xF1)
          {
            song_len = rxArray_buf[2] - 5;

            if (song_len >= SONG_NAME_NUM)
            { //��Ŀ���Ƴ��ȳ����޶���Χ
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
      { //�����Ѵ����˳�����
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
