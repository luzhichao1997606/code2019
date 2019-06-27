/************************************更新记录***********************************
   日期			 作者			  内容
2015.06.08  陈盛票  扩充背景音乐音源内容(V1.4)
2015.06.18  陈盛票  修正音量调节变量定义BUG(1.5)
2015.10.09  陈盛票  扩充窗帘电机协议内容(1.6)
2016.01.12  陈盛票  增加产品编码(1.7)
2016.02.01  陈盛票  修正产品编码错误，扩充背景音乐音源内容(1.8)
2016.07.18  陈盛票  增加亿林空调AC331类型编码
2016.08.12  陈盛票  增加特灵空调类型编码
2016.08.26  陈盛票  增加东芝空调类型编码
2016.09.21  陈盛票  增加日立空调类型编码
2016.11.07  陈盛票  增加美格电表类型编码
2016.11.23  陈盛票  增加三菱重工空调类型编码
2016.11.24  陈盛票  增加朗思威新风类型编码
2016.11.24  陈盛票  增加施耐德电表类型编码
2016.12.07  陈盛票  增加百朗新风、美的空调类型编码
2016.12.23  陈盛票  扩充新风模式内容
2016.12.30  陈盛票  增加柯耐弗空调地暖类型编码
2017.03.17  陈盛票  增加三表三相数据协议内容
2017.06.26  陈盛票  背景音乐音效增加金属功能
*******************************************************************************/

/*******************************************************************************
*                                    常量定义                                  *
*******************************************************************************/
#ifndef __system_fixed_num
#define __system_fixed_num

//系统类========================================================================
#define DEVICE_ID_LEN                       8           //从设备ID长度

#define DEVICE_MODEL_CHECK_IN_ROAD_POS      0           //设备类型判断位置

#define END_UPGRADE_FEED_LEN                1           //在线升级反馈信息长
  //THNet_System_Report(end_device_addr, END_UPGRADE_CODE, END_UPGRADE_FEED_LEN, long_data);
#define END_UPGRADE_REQUIRE_DATA_LEN        2           //要求在线升级信息长

//系统时钟======================================================================
#define END_SYS_CLOCK_DATA_LEN              8           //系统时钟数据长度

#define END_SYS_CLOCK_YEAR_H_POS            0           //系统时钟年高位位置
#define END_SYS_CLOCK_YEAR_L_POS            1           //系统时钟年低位位置
#define END_SYS_CLOCK_MONTH_POS             2           //系统时钟月位置
#define END_SYS_CLOCK_DAY_POS               3           //系统时钟日位置
#define END_SYS_CLOCK_WEEK_POS              4           //系统时钟星期位置
#define END_SYS_CLOCK_HOUR_POS              5           //系统时钟小时位置
#define END_SYS_CLOCK_MINUTE_POS            6           //系统时钟分钟位置
#define END_SYS_CLOCK_SECOND_POS            7           //系统时钟秒钟位置

//系统基础类====================================================================
#define END_SB_SET_DATA_LEN                 2           //工作时间数据长度
#define END_SB_OVERTIME_REPORT_DATA_LEN     3           //工作超时上报数据长度

#define END_SB_SET_DATA_H_POS               0           //设置数据高位
#define END_SB_SET_DATA_L_POS               1           //设置数据低位

#define END_SB_OVER_REPORT_DATA_H_POS       0           //超限上报数据高位
#define END_SB_OVER_REPORT_DATA_L_POS       1           //超限上报数据低位
#define END_SB_OVER_REPORT_STATUS_POS       2           //超限上报数据状态位

//按键类========================================================================
#define END_KEY_BIND_DEVICE_INFO_LEN        3           //按键绑定设备信息数据长度

#define KEY_SET_DEVICE_TYPE_POS             0
#define KEY_SET_DEVICE_ROAD_NUM_POS         1
#define KEY_SET_DEVICE_KEY_NUM_POS          2

#define DEVICE_TOP_KEY_NUM                  16          //控制器顶部按键数

//红外无线======================================================================
#define IR_CAPACITY_PER_DEV                 25
#define WR_CAPACITY_PER_DEV                 9

//数值传感类====================================================================
#define END_QS_SET_DATA_LEN                 2           //传感设置数据长度

#define END_QS_SET_DATA_H_POS               0           //设置数据高位
#define END_QS_SET_DATA_L_POS               1           //设置数据低位

//三表传感类====================================================================
#define EWG_LIMIT_SET_DATA_LEN              2           //限值设置数据长度
#define EWG_OVER_REPORT_DATA_LEN            3           //超限上报数据长度
#define EWG_TRI_PHASE_REPORT_DATA_LEN       3           //三相上报数据长度

#define EWG_LIMIT_SET_DATA_H_POS            0           //限值设置数据高位
#define EWG_LIMIT_SET_DATA_L_POS            1           //限值设置数据低位

#define EWG_OVER_REPORT_DATA_H_POS          0           //超限上报数据高位
#define EWG_OVER_REPORT_DATA_L_POS          1           //超限上报数据低位
#define EWG_OVER_REPORT_STATUS_POS          2           //超限上报数据状态位

#define EWG_TRI_PHASE_REPORT_SEQ_POS        0           //三相数据相序位置
#define EWG_TRI_PHASE_REPORT_H_POS          1           //三相数据高位位置
#define EWG_TRI_PHASE_REPORT_L_POS          2           //三相数据低位位置

#define END_EWG_FEED_LONG_DATA_NUM          4           //用电量反馈数据个数
#define END_EWG_FEED_EXLONG_DATA_NUM        8           //超大用电量反馈数据个数

//背景音乐======================================================================
#define END_CM_VOLUME_MAX_NUM               100         //音量级数
#define END_CM_BASS_TREBLE_MAX_NUM          10          //高低音级数
#define END_CM_SONG_NAME_DATA_NUM           31          //歌曲名数据字节数

//调光==========================================================================
#define END_CR_MAX_LEVEL_NUM                100         //调光级数

//中央地暖======================================================================
#define END_CFH_ACTION_DATA_NUM             2           //地暖动作数据字节数

#define END_CFH_ACTION_DATA_H_POS           0           //地暖动作数据高字节位置
#define END_CFH_ACTION_DATA_L_POS           1           //地暖动作数据低字节位置

#endif

/*******************************************************************************
*                                     指令码定义                               *
*******************************************************************************/
#ifndef __system_instruction
#define __system_instruction

//终端：系统设置================================================================
#define END_SYS_RELOAD_CODE                 0x10        //系统重置码
#define END_SYS_BOUND_STATUS_CODE           0x20        //系统绑定状态码
#define END_SYS_CLOCK_CODE                  0x30        //系统时钟码
#define END_MODE_STATUS_CODE                0x40        //工作模式选择
#define END_ONLINE_STATUS_CODE              0x50        //在线状态
#define END_ID_CHECK_STATUS_CODE            0x60        //ID验证状态
#define END_FIRMWARE_CODE                   0x70        //终端固件信息
#define END_UPGRADE_CODE                    0x80        //终端固件升级信息
#define END_SYS_INITIALIZE_CODE             0x90        //系统初始化
#define END_UPGRADE_REQUIRE_CODE            0xA0        //终端要求固件升级
#define END_SYS_ID_REPLACE_CODE             0xB0        //ID替换
#define END_DEVICE_SEARCH_CODE              0xC0        //设备搜索

#define END_SYS_RELOAD_SUCCEED_CODE         0xA1        //系统重置成功
#define END_SYS_RELOAD_FAILED_CODE          0xA0        //系统重置失败
#define END_SYS_USER_BOUND_CODE             0xB1        //用户已绑定
#define END_SYS_USER_UNBOUND_CODE           0xB0        //用户未绑定
#define END_MODE_1_AUTHORIZED_CODE          0xCA        //模式1：授权正常工作
#define END_MODE_2_ONLINE_ONLY_CODE         0xCB        //模式2：联网时正常工作
#define END_MODE_3_ALL_OFF_CODE             0xCC        //模式3：全关
#define END_MODE_4_ALL_ON_CODE              0xCD        //模式4：全开
#define END_ONLINE_STATUS_OFF_CODE          0xD0        //在线状态：不在线
#define END_ONLINE_STATUS_ON_CODE           0xD1        //在线状态：在线
#define END_SYS_INITIALIZE_SUCCEED_CODE     0xE1        //系统初始化成功
#define END_SYS_INITIALIZE_FAILED_CODE      0xE0        //系统初始化失败
#define END_ID_CHECK_PASS_CODE              0xA1        //ID验证通过
#define END_ID_CHECK_REJECT_CODE            0xA0        //ID验证不通过
#define END_UPGRADE_REQUIRE_INITIATIVE_CODE 0x01        //终端要求固件主动升级
#define END_UPGRADE_REQUIRE_ENFORCE_CODE    0x0F        //终端要求固件强制升级

//Flash操作
#define END_FLASH_SUCCESS_CODE              0x01        //成功
#define END_FLASH_ERROR_ERASE_CODE          0xE0        //擦除错误
#define END_FLASH_ERROR_WRITE_CODE          0xE1        //写入错误
#define END_FLASH_ERROR_READ_CODE           0xE2        //读取错误
#define END_FLASH_ERROR_UNALIGNED_CODE      0xE3        //未对齐错误

//终端：设备设置================================================================
#define END_SET_DEVICE_SR_CODE              0x10        //设备设置指令继电器类型码
#define END_SET_DEVICE_EM_CODE              0x20        //设备设置指令电动式电机类型码
#define END_SET_DEVICE_SM_CODE              0x30        //设备设置指令场景类型码
#define END_SET_DEVICE_LI_CODE              0x40        //设备设置指令学习型红外类型码
#define END_SET_DEVICE_LW_CODE              0x50        //设备设置指令学习型无线类型码

//终端：设备类型================================================================
#define END_DEVICE_TYPE_SR_CODE             0x61        //开关式继电器类 Switch Relay
#define END_DEVICE_TYPE_CR_CODE             0x62        //可调节式继电器类 Changeable Relay
#define END_DEVICE_TYPE_WWH_CODE            0x63        //线控式热水器类 Wire-type Water Heater
#define END_DEVICE_TYPE_CAC_CODE            0x65        //中央空调 Central Air-conditioning
#define END_DEVICE_TYPE_CFH_CODE            0x66        //中央地暖 Central Floor Heating
#define END_DEVICE_TYPE_CFA_CODE            0x67        //中央新风 Central Fresh Air
#define END_DEVICE_TYPE_CM_CODE             0x68        //中央音响控制类 Auxdi Central Music Control
#define END_DEVICE_TYPE_EM_CODE             0x71        //电动式电机类 Electric Motor
#define END_DEVICE_TYPE_LK_CODE             0x72        //门锁类 Lock
#define END_DEVICE_TYPE_TRS_CODE            0x81        //触发式传感器类 Trigger Sensor
#define END_DEVICE_TYPE_QS_CODE             0x82        //可量化式传感器类 Quantifiable Sensor
#define END_DEVICE_TYPE_EWG_CODE            0x89        //三表传感器 Electric Water Gas
#define END_DEVICE_TYPE_LI_CODE             0x91        //学习型红外类 Learning Infrared
#define END_DEVICE_TYPE_LW_CODE             0xA1        //学习型无线类 Learning Wireless
#define END_DEVICE_TYPE_RK_CODE             0xB1        //回弹式墙壁开关类 Rebound Key
#define END_DEVICE_TYPE_RC_CODE             0xB2        //遥控器类 Remote Controller
#define END_DEVICE_TYPE_SB_CODE             0xE1        //系统基础类 System Basis

//终端：类型编码============================0x3A==============================
#define END_TYPE_NULL_CODE                  0xFF        //编码错误
//一、中央空调------------------------------
//1.大金
#define END_TYPE_CAC001_R5_CODE             0x01        //1A C401 大金R5
#define END_TYPE_CAC001_A621_CODE           0x02        //1A C402 大金A621
#define END_TYPE_CAC101_DAIKIN_CODE         0x03        //2A C401 大金DAIKIN
//2.亿林AC8800
#define END_TYPE_CAC002_AC8800_CODE         0x04        //1A C701 亿林AC8800
//3.日立
#define END_TYPE_CAC003_HITACHI_CODE        0x05        //1A C403 日立HITACHI
#define END_TYPE_CAC103_HITACHI_CODE        0x06        //2A C403 日立HITACHI
//4.三菱重工
#define END_TYPE_CAC004_MHI_CODE            0x07        //1A C404 三菱重工MHI
#define END_TYPE_CAC104_MHI_CODE            0x08        //2A C404 三菱重工MHI
//5.东芝
#define END_TYPE_CAC005_TOSHIBA_CODE        0x09        //1A C405 东芝TOSHIBA
#define END_TYPE_CAC105_TOSHIBA_CODE        0x0A        //2A C405 东芝TOSHIBA
//6.海洛尔
#define END_TYPE_CAC006_HaiLourKT_CODE      0x0B        //1A C703 海洛尔HaiLourKT
//7.
//8.美的
#define END_TYPE_CAC008_Midea_CODE          0x0C        //1A C408 美的Midea
#define END_TYPE_CAC108_Midea_CODE          0x0D        //2A C408 美的Midea
//9.三菱电机
#define END_TYPE_CAC009_MAC_CODE            0x0E        //1A C409 三菱电机MAC
//10.格力
#define END_TYPE_CAC010_GREE_CODE           0x0F        //1A C40A 格力GREE
//11.海林
#define END_TYPE_CAC011_HaiLinKT_CODE       0x10        //1A C702 海林HaiLinKT
//12.麦克维尔
#define END_TYPE_CAC012_McQuay_CODE         0x11        //1A C40B 麦克维尔McQuay
//13.约克
#define END_TYPE_CAC013_York_CODE           0x12        //1A C40C 约克氟机York
//14.
//15.亿林AC331
#define END_TYPE_CAC015_AC331_CODE          0x13        //1A C706 亿林AC331
//16.特灵
#define END_TYPE_CAC016_TRANE_CODE          0x14        //1A C707 特灵TRANE
//17.柯耐弗
#define END_TYPE_CAC017_okonoff_CODE        0x15        //1A C70C 柯耐弗okonoff
//二、地暖----------------------------------
//1.曼瑞德
#define END_TYPE_FH001_LS6_CODE             0x16        //1A C501 曼瑞德LS6
//2.亿林
#define END_TYPE_FH002_YiLinDN_CODE         0x17        //1A C502 亿林YiLinDN
//3.海林
#define END_TYPE_FH003_HsiLinDN_CODE        0x18        //1A C503 海林HsiLinDN
//三、背景音乐------------------------------
//1.华尔思BM205
#define END_TYPE_CM001_BM205_CODE           0x19        //1A C801 华尔思BM205
//2.澳斯迪DM836
#define END_TYPE_CM002_DM836_CODE           0x1A        //1A C802 澳斯迪DM836
//3.澳斯迪AM8126
#define END_TYPE_CM003_AM8126_CODE          0x1B        //1A C803 澳斯迪AM8126
//4.澳斯迪AM8230
#define END_TYPE_CM004_AM8230_CODE          0x1C        //1A C804 澳斯迪AM8230
//5.天龙功放
#define END_TYPE_CM005_AVR_X4000_CODE       0x1D        //1A C805 天龙功放AVR-X4000
//6.泊声BA56X
#define END_TYPE_CM006_BA56X_CODE           0x1E        //1A C806 泊声功放BA56X
//7.卢福Nuvo
#define END_TYPE_CM007_NV_E4GM_CODE         0x1F        //1A C807 Nuvo功放NV-E4GM
//8.华尔思BM206
#define END_TYPE_CM008_BM206_CODE           0x20        //1A C808 华尔思BM206
//9.右转YZ200
#define END_TYPE_CM009_YZ200_CODE           0x21        //1A C809 右转YZ200
//10.智轩TY101
#define END_TYPE_CM010_TY101_CODE           0x22        //1A C80A 智轩TY101
//11.澳斯迪DM838
#define END_TYPE_CM011_DM838_CODE           0x23        //1A C80B 澳斯迪DM838
//12.澳斯迪AM8318
#define END_TYPE_CM012_AM8318_CODE          0x24        //1A C80C 澳斯迪AM8318
//13.澳斯迪DM836II
#define END_TYPE_CM013_DM836II_CODE         0x39        //1A C80D 澳斯迪DM836II
//14.悠达Yodar
#define END_TYPE_CM014_YODAR_CODE           0x3A        //1A C80E 悠达Yodar
//四、门锁----------------------------------
//1.八佰
#define END_TYPE_LK001_LK800_CODE           0x25        //1A C601 八佰LK800
//2.普罗巴克
#define END_TYPE_LK002_pbk_CODE             0x26        //1A C602 普罗巴克pbk
//3.耶鲁
#define END_TYPE_LK003_yale_CODE            0x27        //1A C603 耶鲁yale
//4.豪力士
#define END_TYPE_LK004_holish_CODE          0x28        //1A C604 豪力士holish
//5.智轩
#define END_TYPE_LK005_ThinkYale_CODE       0x29        //1B E605 智轩耶鲁ThinkYale
//五、窗帘/晾衣架----------------------------------
//1.杜亚
#define END_TYPE_EM001_Dooya_CODE           0x2A        //1A CA01 杜亚Dooya
//2.晾霸
#define END_TYPE_EM002_LBest_CODE           0x2B        //1A CA02 晾霸LBest
//六、调光/调色-----------------------------
//1.调光
#define END_TYPE_CR001_TG01_CODE            0x2C        //1A C901 TG01
//2.调色
#define END_TYPE_CR002_TS01_CODE            0x2D        //1A C902 TS01
//七、环境传感------------------------------
//1.海克智动
#define END_TYPE_EA001_B3_CODE              0x2E        //1A CC01 海克智动B3
//八、三表----------------------------------
//1.埃美柯水表
#define END_TYPE_EWG001_LXSY_25E_CODE       0x2F        //1A CB01 埃美柯LXSY-25E
//2.美格电表
#define END_TYPE_EWG002_MC7200_CODE         0x30        //1A CB02 美格MC7200
//3.施耐德电表
#define END_TYPE_EWG003_PM800_CODE          0x31        //1A CB03 施耐德PM800
//九、按键----------------------------------
//3.智轩
#define END_TYPE_BC003_THB_240_CODE         0x32        //1A C201 THB-240
//十、中央新风------------------------------
//1.霍德森
#define END_TYPE_CFA001_HOODSON_CODE        0x33        //1A C704 HOODSON
//2.罗蕾莱
#define END_TYPE_CFA002_Lorelei_CODE        0x34        //1A C705 Lorelei
//3.兰舍
#define END_TYPE_CFA003_NATHER_CODE         0x35        //1A C708 NATHER
//4.曼瑞德
#define END_TYPE_CFA004_menredXF_CODE       0x36        //1A C709 menredXF
//5.朗思威
#define END_TYPE_CFA005_LOWNSWELL_CODE      0x37        //1A C70A LOWNSWELL
//6.百朗
#define END_TYPE_CFA006_BROAN_CODE          0x38        //1A C70B BROAN

//终端：产品编码============================0x016A==============================
#define END_MODEL_X_ROAD_NULL_CODE          0xFFFF      //编码错误
//一、中央空调------------------------------
//1.大金
#define END_MODEL_CAC001_ROAD_09_CODE       0x0101      //THK 091A C401 大金R5 9路
#define END_MODEL_CAC001_ROAD_04_CODE       0x0143      //THK 041A C402 大金A621 4路 
#define END_MODEL_CAC001_ROAD_08_CODE       0x0102      //THK 081A C402 大金A621 8路 
#define END_MODEL_CAC001_ROAD_16_CODE       0x0103      //THK 161A C402 大金A621 16路
#define END_MODEL_CAC001_ROAD_32_CODE       0x013D      //THK 321A C402 大金A621 32路
#define END_MODEL_CAC001_ROAD_64_CODE       0x0140      //THK 641A C402 大金A621 64路
#define END_MODEL_CAC101_ROAD_04_CODE       0x0147      //THK 042A C401 大金DAIKIN 4路 
#define END_MODEL_CAC101_ROAD_08_CODE       0x0148      //THK 082A C401 大金DAIKIN 8路 
#define END_MODEL_CAC101_ROAD_16_CODE       0x0149      //THK 162A C401 大金DAIKIN 16路
#define END_MODEL_CAC101_ROAD_32_CODE       0x014A      //THK 322A C401 大金DAIKIN 32路
#define END_MODEL_CAC101_ROAD_64_CODE       0x014B      //THK 642A C401 大金DAIKIN 64路
//1-2.大金mini
#define END_MODEL_CAC102_ROAD_16_CODE       0x0166      //THK 162A C402 大金DAIKIN mini 16路
//2.亿林AC8800
#define END_MODEL_CAC002_ROAD_04_CODE       0x011C      //THK 041A C701 亿林AC8800 4路
#define END_MODEL_CAC002_ROAD_08_CODE       0x011D      //THK 081A C701 亿林AC8800 8路
#define END_MODEL_CAC002_ROAD_16_CODE       0x011E      //THK 161A C701 亿林AC8800 16路
//3.日立
#define END_MODEL_CAC003_ROAD_04_CODE       0x0142      //THK 041A C403 日立HITACHI 4路
#define END_MODEL_CAC003_ROAD_08_CODE       0x0104      //THK 081A C403 日立HITACHI 8路
#define END_MODEL_CAC003_ROAD_16_CODE       0x0105      //THK 161A C403 日立HITACHI 16路
#define END_MODEL_CAC103_ROAD_08_CODE       0x0158      //THK 082A C403 日立HITACHI 8路
#define END_MODEL_CAC103_ROAD_16_CODE       0x0159      //THK 162A C403 日立HITACHI 16路
//4.三菱重工
#define END_MODEL_CAC004_ROAD_04_CODE       0x0106      //THK 041A C404 三菱重工MHI 4路
#define END_MODEL_CAC004_ROAD_08_CODE       0x0107      //THK 081A C404 三菱重工MHI 8路
#define END_MODEL_CAC004_ROAD_16_CODE       0x0108      //THK 161A C404 三菱重工MHI 16路
#define END_MODEL_CAC004_ROAD_32_CODE       0x013F      //THK 321A C404 三菱重工MHI 32路
#define END_MODEL_CAC104_ROAD_04_CODE       0x015B      //THK 042A C404 三菱重工MHI 4路
#define END_MODEL_CAC104_ROAD_08_CODE       0x015C      //THK 082A C404 三菱重工MHI 8路
#define END_MODEL_CAC104_ROAD_16_CODE       0x015D      //THK 162A C404 三菱重工MHI 16路
#define END_MODEL_CAC104_ROAD_32_CODE       0x015E      //THK 322A C404 三菱重工MHI 32路
//5.东芝
#define END_MODEL_CAC005_ROAD_08_CODE       0x0109      //THK 081A C405 东芝TOSHIBA 8路
#define END_MODEL_CAC005_ROAD_16_CODE       0x010A      //THK 161A C405 东芝TOSHIBA 16路
#define END_MODEL_CAC105_ROAD_08_CODE       0x0156      //THK 082A C405 东芝TOSHIBA 8路
#define END_MODEL_CAC105_ROAD_16_CODE       0x0157      //THK 162A C405 东芝TOSHIBA 16路
//6.海洛尔
#define END_MODEL_CAC006_ROAD_08_CODE       0x013E      //THK 081A C703 海洛尔HaiLourKT 8路
//7.
//8.美的
#define END_MODEL_CAC008_ROAD_08_CODE       0x010B      //THK 081A C408 美的Midea 8路
#define END_MODEL_CAC008_ROAD_16_CODE       0x010C      //THK 161A C408 美的Midea 16路
#define END_MODEL_CAC008_ROAD_64_CODE       0x010D      //THK 641A C408 美的Midea 64路
#define END_MODEL_CAC108_ROAD_08_CODE       0x0162      //THK 082A C408 美的Midea 8路
#define END_MODEL_CAC108_ROAD_16_CODE       0x0163      //THK 162A C408 美的Midea 16路
//9.三菱电机
#define END_MODEL_CAC009_ROAD_04_CODE       0x014C      //THK 041A C409 三菱电机MAC 4路
#define END_MODEL_CAC009_ROAD_08_CODE       0x010E      //THK 081A C409 三菱电机MAC 8路
#define END_MODEL_CAC009_ROAD_16_CODE       0x010F      //THK 161A C409 三菱电机MAC 16路
#define END_MODEL_CAC109_ROAD_08_CODE       0x0169      //THK 082A C409 三菱电机MAC 8路
#define END_MODEL_CAC109_ROAD_16_CODE       0x016A      //THK 162A C409 三菱电机MAC 16路
//10.格力
#define END_MODEL_CAC010_ROAD_08_CODE       0x0110      //THK 081A C40A 格力GREE 8路
#define END_MODEL_CAC010_ROAD_16_CODE       0x0111      //THK 161A C40A 格力GREE 16路
//11.海林
#define END_MODEL_CAC011_ROAD_08_CODE       0x013B      //THK 081A C702 海林HaiLinKT 8路
//12.麦克维尔
#define END_MODEL_CAC012_ROAD_08_CODE       0x0112      //THK 081A C40B 麦克维尔McQuay 8路
#define END_MODEL_CAC012_ROAD_16_CODE       0x0113      //THK 161A C40B 麦克维尔McQuay 16路
//13.约克
#define END_MODEL_CAC013_ROAD_16_CODE       0x0139      //THK 161A C40C 约克氟机York 16路
//14.
//15.亿林AC331
#define END_MODEL_CAC015_ROAD_04_CODE       0x014E      //THK 041A C706 亿林AC331 4路
#define END_MODEL_CAC015_ROAD_08_CODE       0x014F      //THK 081A C706 亿林AC331 8路
#define END_MODEL_CAC015_ROAD_16_CODE       0x0150      //THK 161A C706 亿林AC331 16路
//16.特灵
#define END_MODEL_CAC016_ROAD_08_CODE       0x0152      //THK 081A C707 特灵TRANE 8路
//17.柯耐弗
#define END_MODEL_CAC017_ROAD_08_CODE       0x0164      //THZ 081A C70C 柯耐弗okonoff 8路
//二、地暖----------------------------------
//1.曼瑞德
#define END_MODEL_FH001_ROAD_07_CODE        0x0114      //THK 071A C501 曼瑞德LS6 7路
//2.亿林
#define END_MODEL_FH002_ROAD_04_CODE        0x0155      //THK 041A C502 亿林YiLinDN 4路
#define END_MODEL_FH002_ROAD_08_CODE        0x0115      //THK 081A C502 亿林YiLinDN 8路
#define END_MODEL_FH002_ROAD_16_CODE        0x0116      //THK 161A C502 亿林YiLinDN 16路
//3.海林
#define END_MODEL_FH003_ROAD_04_CODE        0x014D      //THK 041A C503 海林HsiLinDN 4路
#define END_MODEL_FH003_ROAD_08_CODE        0x013C      //THK 081A C503 海林HsiLinDN 8路
//三、背景音乐------------------------------
//1.华尔思BM205
#define END_MODEL_CM001_ROAD_04_CODE        0x011F      //THY 041A C801 华尔思BM205 4路
//2.澳斯迪DM836
#define END_MODEL_CM002_ROAD_04_CODE        0x0121      //THY 041A C802 澳斯迪DM836 4路
//3.澳斯迪AM8126
#define END_MODEL_CM003_ROAD_04_CODE        0x0123      //THY 041A C803 澳斯迪AM8126 4路
#define END_MODEL_CM003_ROAD_08_CODE        0x0124      //THY 081A C803 澳斯迪AM8126 8路
//4.澳斯迪AM8230
#define END_MODEL_CM004_ROAD_04_CODE        0x0125      //THY 041A C804 澳斯迪AM8230 4路
#define END_MODEL_CM004_ROAD_08_CODE        0x0126      //THY 081A C804 澳斯迪AM8230 8路
//5.天龙功放
#define END_MODEL_CM005_ROAD_01_CODE        0x0127      //THY 011A C805 天龙功放AVR-X4000 1路
//6.泊声BA56X
#define END_MODEL_CM006_ROAD_04_CODE        0x0128      //THY 041A C806 泊声功放BA56X 4路
//7.卢福Nuvo
#define END_MODEL_CM007_ROAD_04_CODE        0x0129      //THY 041A C807 Nuvo功放NV-E4GM 4路
//8.华尔思BM206
#define END_MODEL_CM008_ROAD_04_CODE        0x012A      //THY 041A C808 华尔思BM206 4路
#define END_MODEL_CM008_ROAD_08_CODE        0x012B      //THY 081A C808 华尔思BM206 8路
//9.右转YZ200
#define END_MODEL_CM009_ROAD_04_CODE        0x012C      //THY 041A C809 右转YZ200 4路
#define END_MODEL_CM009_ROAD_08_CODE        0x012D      //THY 081A C809 右转YZ200 8路
//10.智轩TY101
#define END_MODEL_CM010_ROAD_04_CODE        0x012E      //THY 041A C80A 智轩TY101 4路
#define END_MODEL_CM010_ROAD_08_CODE        0x012F      //THY 081A C80A 智轩TY101 8路
//11.澳斯迪DM838
#define END_MODEL_CM011_ROAD_04_CODE        0x013A      //THY 041A C80B 澳斯迪DM838 4路
//12.澳斯迪AM8318
#define END_MODEL_CM012_ROAD_08_CODE        0x0145      //THY 081A C80C 澳斯迪AM8318 8路
//13.澳斯迪DM836II
#define END_MODEL_CM013_ROAD_04_CODE        0x0122      //THY 041A C80D 澳斯迪DM836II 4路
//14.悠达Yodar
#define END_MODEL_CM014_ROAD_04_CODE        0x0120      //THY 041A C80E 悠达Yodar 4路
//四、门锁----------------------------------
//1.八佰
#define END_MODEL_LK001_ROAD_04_CODE        0x0117      //THS 041A C601 八佰LK800 4路
//2.普罗巴克
#define END_MODEL_LK002_ROAD_04_CODE        0x0118      //THS 041A C602 普罗巴克pbk 4路
//3.耶鲁
#define END_MODEL_LK003_ROAD_01_CODE        0x0119      //THS 011A C603 耶鲁yale 1路
//4.豪力士
#define END_MODEL_LK004_ROAD_04_CODE        0x011A      //THS 041A C604 豪力士holish 4路
//5.智轩
#define END_MODEL_LK005_ROAD_01_CODE        0x011B      //THS 011B E605 智轩耶鲁ThinkYale 1路
//五、窗帘/晾衣架----------------------------------
//1.杜亚
#define END_MODEL_EM001_ROAD_04_CODE        0x0133      //THC 041A CA01 杜亚Dooya 4路
#define END_MODEL_EM001_ROAD_08_CODE        0x0134      //THC 081A CA01 杜亚Dooya 8路
#define END_MODEL_EM001_ROAD_16_CODE        0x0135      //THC 161A CA01 杜亚Dooya 16路
//2.晾霸
#define END_MODEL_EM002_ROAD_04_CODE        0x0151      //THC 041A CA02 晾霸LBest 4路
//六、调光/调色-----------------------------
//1.调光
#define END_MODEL_CR001_ROAD_04_CODE        0x0130      //THL 041A C901 TG01 4路
#define END_MODEL_CR001_ROAD_12_CODE        0x0131      //THL 121A C901 TG01 12路
//2.调色
#define END_MODEL_CR002_ROAD_04_CODE        0x0132      //THL 041A C902 TS01 4路
//七、环境传感------------------------------
//1.海克智动
#define END_MODEL_EA001_ROAD_04_CODE        0x0141      //THE 041A CC01 海克智动B3 4路
#define END_MODEL_EA001_ROAD_08_CODE        0x0137      //THE 081A CC01 海克智动B3 8路
//八、三表----------------------------------
//1.埃美柯水表
#define END_MODEL_EWG001_ROAD_16_CODE       0x0136      //THW 161A CB01 埃美柯LXSY-25E 16路
//2.美格电表
#define END_MODEL_EWG002_ROAD_32_CODE       0x015A      //THW 321A CB02 美格MC7200 32路
//3.施耐德电表
#define END_MODEL_EWG003_ROAD_32_CODE       0x0160      //THW 321A CB03 施耐德PM800 32路
//4.华邦电表
#define END_MODEL_EWG004_ROAD_04_CODE       0x0165      //THW 041A CB04 华邦D866 4路
//九、按键----------------------------------
//3.智轩
#define END_MODEL_BC003_ROAD_240_CODE       0x0138      //THB 241A C201 THB-240 240路
//十、中央新风------------------------------
//1.霍德森
#define END_MODEL_CFA001_ROAD_08_CODE       0x0144      //THF 081A C704 HOODSON 8路
//2.罗蕾莱
#define END_MODEL_CFA002_ROAD_08_CODE       0x0146      //THF 081A C705 Lorelei 8路
//3.兰舍
#define END_MODEL_CFA003_ROAD_08_CODE       0x0153      //THF 081A C708 NATHER 8路
//4.曼瑞德
#define END_MODEL_CFA004_ROAD_08_CODE       0x0154      //THF 081A C709 menredXF 8路
//5.朗思威
#define END_MODEL_CFA005_ROAD_04_CODE       0x015F      //THF 041A C70A LOWNSWELL 4路
//6.百朗
#define END_MODEL_CFA006_ROAD_01_CODE       0x0161      //THF 011A C70B BROAN 1路

//终端路数======================================================================
#define END_ROAD_NUM_00_CODE                0x00        //共0路
#define END_ROAD_NUM_01_CODE                0x01        //共1路
#define END_ROAD_NUM_04_CODE                0x04        //共4路
#define END_ROAD_NUM_05_CODE                0x05        //共5路
#define END_ROAD_NUM_07_CODE                0x07        //共7路
#define END_ROAD_NUM_08_CODE                0x08        //共8路
#define END_ROAD_NUM_09_CODE                0x09        //共9路
#define END_ROAD_NUM_12_CODE                0x12        //共12路
#define END_ROAD_NUM_16_CODE                0x16        //共16路
#define END_ROAD_NUM_24_CODE                0x24        //共24路
#define END_ROAD_NUM_32_CODE                0x32        //共32路
#define END_ROAD_NUM_50_CODE                0x50        //共50路
#define END_ROAD_NUM_64_CODE                0x64        //共64路

#define END_START_ROAD_01_CODE              0x01        //总路数起始01路

//==============================================================================
//错误指令
#define END_OK_CODE                         0xEF        //正确码
#define END_CHECK_CODE                      0xED        //审核码
#define END_ERROR_CODE                      0xEE        //错误码

//双操作指令
#define END_CLOSE_CODE                      0x00        //终端设备关闭
#define END_OPEN_CODE                       0xFF        //终端设备打开

//三操作指令
#define END_STOP_CODE                       0x00        //终端设备停止
#define END_FORWARD_CODE                    0x01        //终端设备前进
#define END_BACKWARD_CODE                   0x02        //终端设备后退

//数据操作指令
#define END_POSITIVE_CODE                   0x00        //正数
#define END_NEGATIVE_CODE                   0x01        //负数
#define END_ZERO_CODE                       0x00        //数据位为0
#define END_ONE_CODE                        0x01        //数据位为1
#define END_TWO_CODE                        0x02        //数据位为2
#define END_THREE_CODE                      0x03        //数据位为3
#define END_FOUR_CODE                       0x04        //数据位为4
#define END_FIVE_CODE                       0x05        //数据位为5
#define END_TEN_CODE                        0x0A        //数据位为10
#define END_FULL_CODE                       0xFFFF      //数据位为满值

#define END_START_ROAD_01_CODE              0x01        //总路数起始01路

//终端：按键触发类指令
#define END_TRIGGER_CODE                    0x01        //终端触发1次
#define END_TRIGGER_DOUBLE_CODE             0x02        //终端连续触发2次
#define END_TRIGGER_TRI_CODE                0x03        //终端连续触发3次
#define END_TRIGGER_FORTH_CODE              0x04        //终端连续触发4次
#define END_TRIGGER_FIFTH_CODE              0x05        //终端连续触发5次
#define END_TRIGGER_SIXTH_CODE              0x06        //终端连续触发6次
#define END_TRIGGER_TENTH_CODE              0x0A        //终端连续触发10次
#define END_TRIGGER_ST_LONG_CODE            0xF0        //终端连续长时间触发
#define END_TRIGGER_NR_LONG_CODE            0xFD        //终端连续长时间触发
#define END_TRIGGER_EX_LONG_CODE            0xFF        //终端连续超长时间触发
#define END_UNTRIGGER_CODE                  0x00        //终端状态良好

//按键
#define KEY_STYLE_TOP_KEYBOARD_CODE         0x01        //顶板按键类型
#define KEY_STYLE_NORMAL_CODE               0x02        //普通按键类型

//响铃
#define BELL_RING_MODE_01_CODE              0x01        //正常响铃
#define BELL_RING_MODE_05_CODE              0x05        //正常响铃

//终端==========================================================================
#define NO_DEAL_RESULT_CODE                 0xFF
#define END_DEVICE_HOST_ADDR_CODE           0x00        //主机地址
#define END_DEVICE_B_ADDR_CODE              0x01        //从机B地址：继电器2
#define END_DEVICE_C_ADDR_CODE              0x02        //从机C地址：继电器3
#define END_DEVICE_D_ADDR_CODE              0x03        //从机D地址：继电器4
#define END_DEVICE_E_ADDR_CODE              0x04        //从机E地址：继电器5
#define END_DEVICE_F_ADDR_CODE              0x05        //从机F地址：无线触发1
#define END_DEVICE_G_ADDR_CODE              0x06        //从机G地址：无线触发2
#define END_DEVICE_H_ADDR_CODE              0x07        //从机H地址：无线触发3
#define END_DEVICE_ALL_ADDR_CODE            0x40        //所有从机地址
#define END_DEVICE_ALL_ROAD_CODE            0xFF        //所有路次

//指示灯
#define END_LED_POWER_OFF_CODE              0x00        //指示灯关闭
#define END_LED_POWER_ON_CODE               0xFF        //指示灯打开

#define END_LED_ROAD_01_CODE                0x01        //指示灯第1路
#define END_LED_ROAD_02_CODE                0x02        //指示灯第2路
#define END_LED_ROAD_03_CODE                0x03        //指示灯第3路
#define END_LED_ROAD_04_CODE                0x04        //指示灯第4路
#define END_LED_ROAD_05_CODE                0x05        //指示灯第5路
#define END_LED_ROAD_06_CODE                0x06        //指示灯第6路
#define END_LED_ROAD_07_CODE                0x07        //指示灯第7路
#define END_LED_ROAD_08_CODE                0x08        //指示灯第8路
#define END_LED_ROAD_09_CODE                0x09        //指示灯第9路
#define END_LED_ROAD_10_CODE                0x0A        //指示灯第10路
#define END_LED_ROAD_11_CODE                0x0B        //指示灯第11路
#define END_LED_ROAD_12_CODE                0x0C        //指示灯第12路
#define END_LED_ROAD_13_CODE                0x0D        //指示灯第13路
#define END_LED_ROAD_14_CODE                0x0E        //指示灯第14路
#define END_LED_ROAD_15_CODE                0x0F        //指示灯第15路
#define END_LED_ROAD_16_CODE                0x10        //指示灯第16路
#define END_LED_ROAD_ALL_CODE               0x00        //指示灯

//终端：系统基础类===============================================================
#define END_SB_ONLINE_STATUS_CODE           0x21        //在线状态码
#define END_SB_OVERTIME_STATUS_CODE         0x22        //超时状态码
#define END_SB_LOCK_SET_CODE                0xF1        //锁定设置
#define END_SB_OVERTIME_SET_CODE            0xF2        //超时设置：分钟
#define END_SB_LED_MODE_SET_CODE            0xF3        //指示灯工作模式设置

//1.在线状态
#define END_SB_ONLINE_ON_CODE               0x01        //在线
#define END_SB_ONLINE_OFF_CODE              0x00        //掉线
//2.超时状态
#define END_SB_OVERTIME_RESTORE_CODE        0x00        //超时恢复/无超时
#define END_SB_OVERTIME_ALARM_CODE          0x01        //超时
//3.锁定设置
#define END_SB_LOCK_ON_CODE                 0x01        //锁定/全锁
#define END_SB_LOCK_OFF_CODE                0x00        //解锁/无锁
//4.指示灯工作模式设置
#define END_SB_LED_MODE_OFF_CODE            0x00        //指示灯关闭
#define END_SB_LED_MODE_ON_CODE             0xFF        //指示灯打开
#define END_SB_LED_MODE_01_CODE             0x01        //指示灯模式1
#define END_SB_LED_MODE_02_CODE             0x02        //指示灯模式2
#define END_SB_LED_MODE_03_CODE             0x03        //指示灯模式3
#define END_SB_LED_MODE_04_CODE             0x04        //指示灯模式4
#define END_SB_LED_MODE_05_CODE             0x05        //指示灯模式5
#define END_SB_LED_MODE_06_CODE             0x06        //指示灯模式6

//终端：系统基础
#define END_SB_ROAD_01_CODE                 0x01        //系统基础第01路

//终端：开关式继电器类==========================================================
#define END_SR_POWER_STATUS_CODE            0x10        //电源状态

#define END_SR_POWER_OFF_CODE               0x00        //电源关闭
#define END_SR_POWER_ON_CODE                0xFF        //电源打开

        //(1-16):THP-H16, THP-S16
#define END_SR_ROAD_ALL_CODE                0x00        //继电器所有路
#define END_SR_ROAD_01_CODE                 0x01        //继电器第1路
#define END_SR_ROAD_02_CODE                 0x02        //继电器第2路
#define END_SR_ROAD_03_CODE                 0x03        //继电器第3路
#define END_SR_ROAD_04_CODE                 0x04        //继电器第4路
#define END_SR_ROAD_05_CODE                 0x05        //继电器第5路
#define END_SR_ROAD_06_CODE                 0x06        //继电器第6路
#define END_SR_ROAD_07_CODE                 0x07        //继电器第7路
#define END_SR_ROAD_08_CODE                 0x08        //继电器第8路
#define END_SR_ROAD_09_CODE                 0x09        //继电器第9路
#define END_SR_ROAD_10_CODE                 0x0A        //继电器第10路
#define END_SR_ROAD_11_CODE                 0x0B        //继电器第11路
#define END_SR_ROAD_12_CODE                 0x0C        //继电器第12路
#define END_SR_ROAD_13_CODE                 0x0D        //继电器第13路
#define END_SR_ROAD_14_CODE                 0x0E        //继电器第14路
#define END_SR_ROAD_15_CODE                 0x0F        //继电器第15路
#define END_SR_ROAD_16_CODE                 0x10        //继电器第16路
#define END_SR_ROAD_17_CODE                 0x11        //继电器第17路
#define END_SR_ROAD_18_CODE                 0x12        //继电器第18路
#define END_SR_ROAD_19_CODE                 0x13        //继电器第19路
				//(65-6D):THZ-S15
#define END_SR_ROAD_Z01_CODE                0x65        //继电器第1路

//终端：可调节式继电器类========================================================
#define END_CR_POWER_LEVEL_CODE             0x10        //电源等级：0x00~0x64
#define END_CR_ONLINE_STATUS_CODE           0x11        //可调灯在线状态码
#define END_CR_MODE_STYLE_CODE              0x20        //模式控制
#define END_CR_OVERLOAD_STATUS_CODE         0x30        //过载保护

//1.电源控制(0~100)
#define END_CR_POWER_OFF_CODE               0xFF        //电源关闭
//2.在线状态
#define END_CR_OFFLINE_CODE                 0x00        //可调灯掉线码
#define END_CR_ONLINE_CODE                  0x01        //可调灯在线码
//3.模式控制
//4.过载保护
#define END_CR_OVERLOAD_RESTORE_CODE        0x00        //保护解除
#define END_CR_OVERLOAD_PROTECT_CODE        0x01        //过载保护

#define END_CR_ROAD_01_CODE                 0x01        //可调灯第1路
#define END_CR_ROAD_09_CODE                 0x09        //可调灯第9路
#define END_CR_ROAD_12_CODE                 0x0C        //可调灯第12路

//终端：三表传感器类============================================================
#define END_EWG_ONLINE_STATUS_CODE          0x20        //在线状态
#define END_EWG_ACTIVE_POWER_CODE           0x11        //当前功率W（全波有功功率平均值）
#define END_EWG_POWER_CONSUM_CODE           0x12        //用电量kWh（×100）（可查询）
#define END_EWG_VOLTAGE_CODE                0x13        //电压V（×100）（全波电压有效平均值）
#define END_EWG_CURRENT_CODE                0x14        //电流A（×100）（全波电流有效平均值）
#define END_EWG_FREQUENCY_CODE              0x15        //频率Hz（×100）（频率秒平均值）
#define END_EWG_REACTIVE_POWER_CODE         0x16        //无功功率W（全波无功功率平均值）
#define END_EWG_APPARENT_POWER_CODE         0x17        //视在功率VA
#define END_EWG_POWER_FACTOR_CODE           0x18        //功率因数PF（×100）
#define END_EWG_TRI_VOLTAGE_CODE            0x19        //三相电压V（×100）（全波电压有效平均值）
#define END_EWG_TRI_CURRENT_CODE            0x1A        //三相电流A（×100）（全波电流有效平均值）
#define END_EWG_WATER_CONSUM_CODE           0x30        //用水量m3（×100）（可查询）
#define END_EWG_VALVE_STATUS_CODE           0x31        //阀门状态
#define END_EWG_LEAK_STATUS_CODE            0x32        //泄漏状态
#define END_EWG_ERROR_ALARM_CODE            0xF0        //故障报警
#define END_EWG_OVERLOAD_STATUS_CODE        0xF1        //过载保护状态
#define END_EWG_LIMIT_STATUS_CODE           0xF2        //超限保护状态
#define END_EWG_OVERLOAD_VALUE_SET_CODE     0xB0        //负载设置
#define END_EWG_LIMIT_LOWER_SET_CODE        0xB1        //下限值设置
#define END_EWG_LIMIT_UPPER_SET_CODE        0xB2        //上限值设置
#define END_EWG_LIMIT_ACT_SET_CODE          0xB3        //超限动作设置
#define END_EWG_POWER_RATIO_SET_CODE        0xB4        //电表变比值设置

//1.在线状态
#define END_EWG_OFFLINE_CODE                0x00        //不在线
#define END_EWG_ONLINE_CODE                 0x01        //在线
//10.三相电压
//11.三相电流
#define END_EWG_TRI_PHASE_A_CODE            0x01        //A相
#define END_EWG_TRI_PHASE_B_CODE            0x02        //B相
#define END_EWG_TRI_PHASE_C_CODE            0x03        //C相
//13.阀门状态
#define END_EWG_VALVE_CLOSE_CODE            0x00        //阀门关闭
#define END_EWG_VALVE_OPEN_CODE             0x01        //阀门打开
//14.泄漏状态
#define END_EWG_LEAK_OFF_CODE               0x00        //正常
#define END_EWG_LEAK_ON_CODE                0x01        //泄漏
//15.故障报警
#define END_EWG_ERROR_COMM_CODE             0x01        //通信故障
//16.过载保护
#define END_EWG_OVERLOAD_RESTORE_CODE       0x00        //保护解除
#define END_EWG_OVERLOAD_PROTECT_CODE       0x01        //过载保护
//17.超限保护
#define END_EWG_LIMIT_RESTORE_CODE          0x00        //保护解除
#define END_EWG_LIMIT_LOWER_CODE            0x01        //下限保护
#define END_EWG_LIMIT_UPPER_CODE            0x02        //上限保护
//21.超限动作
#define END_EWG_LIMIT_ACT_NONE_CODE         0x00        //不处理
#define END_EWG_LIMIT_ACT_REPORT_CODE       0x01        //仅上报
#define END_EWG_LIMIT_ACT_ACTION_CODE       0x02        //动作且上报

#define END_EWG_ROAD_01_CODE                0x01        //三表第1路

//终端：红外无线学习类指令======================================================
#define END_OPERATING_CODE                  0x31        //操作指令
#define END_LEARNING_CODE                   0x32        //学习指令
        //(1-10):THR-S10
        //(1-5):THR-S5
        //(1-F):THZ-S15
#define END_IR_ROAD_01_CODE                 0x01        //学习型红外第1路
#define END_IR_ROAD_05_CODE                 0x05        //学习型红外第5路
#define END_IR_ROAD_10_CODE                 0x0A        //学习型红外第10路
#define END_IR_ROAD_15_CODE                 0x0F        //学习型红外第15路
        //(11-20):THR-S10, THR-S5
#define END_WR_ROAD_01_CODE                 0x0B        //学习型无线第1路
#define END_WR_ROAD_05_CODE                 0x0F        //学习型无线第5路
#define END_WR_ROAD_10_CODE                 0x14        //学习型无线第10路
        //(29-37):THZ-S15
#define END_WR_ROAD_Z01_CODE                0x29        //学习型无线第1路

//终端：触发式传感器类==========================================================
#define END_TR_TRIGGER_STATUS_CODE          0x10        //触发状态
#define END_TR_ONLINE_STATUS_CODE           0x11        //在线状态
#define END_TR_POWER_STATUS_CODE            0x12        //开关机状态
#define END_TR_DEFENSE_STATUS_CODE          0x13        //布撤防状态
#define END_TR_SENDER_POWER_CODE            0x20        //发送端电量状态
#define END_TR_SENCEIVER_POWER_CODE         0x21        //收送端电量状态
#define END_TR_SENDER_BATTERY_CODE          0x30        //发送端电池状态
#define END_TR_SENCEIVER_BATTERY_CODE       0x31        //收送端电池状态
#define END_TR_LIGHT_INTERF_CODE            0x40        //强光干扰
#define END_TR_IR_ALIGN_STATUS_CODE         0x50        //红外线对射状态
#define END_TR_OTHER_ALARM_CODE             0x60        //其它报警
#define END_TR_BINDING_CODE                 0xB0        //对码/清码设置

//1.触发状态
#define END_TRIGGER_CODE                    0x01        //触发
#define END_UNTRIGGER_CODE                  0x00        //触发消失
//2.在线状态
#define END_TR_ONLINE_CODE                  0x01        //在线
#define END_TR_OFFLINE_CODE                 0x00        //不在线
//3.开关机状态
#define END_TR_POWER_ON_CODE                0x01        //开机
#define END_TR_POWER_OFF_CODE               0x00        //关机
//4.布撤防状态
#define END_TR_DEFENSE_ON_CODE              0x01        //布防
#define END_TR_DEFENSE_OFF_CODE             0x00        //撤防
//5.发送端电量状态(0~100)
#define END_TR_SPOWER_OK_CODE               0xFF        //发送端电量正常
#define END_TR_SPOWER_LOW_CODE              0xFE        //发送端电量低电
//6.收送端电量状态(0~100)
#define END_TR_SCPOWER_OK_CODE              0xFF        //收送端电量正常
#define END_TR_SCPOWER_LOW_CODE             0xFE        //收送端电量低电
//7.发送端电池状态
#define END_TR_SBATTERY_OK_CODE             0x00        //发送端电池正常
#define END_TR_SBATTERY_BREAK_CODE          0x01        //发送端电池损坏
//8.收送端电池状态
#define END_TR_SCBATTERY_OK_CODE            0x00        //收送端电池正常
#define END_TR_SCBATTERY_BREAK_CODE         0x01        //收送端电池损坏
//9.强光干扰
#define END_TR_LIINTERF_RECOVER_CODE        0x00        //强光干扰恢复
#define END_TR_LIINTERF_APPEAR_CODE         0x01        //强光干扰产生
//10.红外线对射状态
#define END_TR_IR_ALIGN_ON_CODE             0x00        //红外线已对上
#define END_TR_IR_ALIGN_OFF_CODE            0x01        //红外线未对上
//11.其它报警
#define END_TR_ALARM_TAMPER_CODE            0x01        //防拆报警
#define END_TR_ALARM_SENDER_REBOOT_CODE     0x02        //发送端重启报警
//12.对码/清码设置
#define END_TR_BINDING_BIND_CODE            0x01        //对码
#define END_TR_BINDING_REMOVE_CODE          0x00        //清码
#define END_TRIGGER_00_CODE                 0x42        //触发开关第01路
#define END_TRIGGER_01_CODE                 0x41        //触发传感器第01路

//终端：数值型传感器类==========================================================
#define END_QS_ONLINE_STATUS_CODE           0x11        //在线状态码
#define END_QS_LED_SET_CODE                 0x31        //传感指示设置
#define END_QS_THRESHOLD_01_CODE            0x32        //传感区间阈值一设置
#define END_QS_THRESHOLD_02_CODE            0x33        //传感区间阈值二设置
#define END_QS_ADJUST_SET_CODE              0x34        //传感偏值设置

#define END_QS_TEMP_DATA_CODE               0xA0        //温度数据(×10)
#define END_QS_HUMI_DATA_CODE               0xA1        //湿度数据(×10)
#define END_QS_LUMI_DATA_CODE               0xA2        //光照度数据(×1)
#define END_QS_PM25_DATA_CODE               0xA3        //PM2.5数据(×1)
#define END_QS_CO2_DATA_CODE                0xA4        //CO2数据(×1)
#define END_QS_TVOC_DATA_CODE               0xA5        //TVOC数据(×100)
#define END_QS_NOISE_DATA_CODE              0xA6        //噪声数据(×1)

#define END_QS_TEMP_AVERAGE_CODE            0xB1        //温度平均数据（原值）
#define END_QS_HUMI_AVERAGE_CODE            0xB2        //湿度平均数据（原值）
#define END_QS_LUMI_AVERAGE_CODE            0xB3        //光照度平均数据（1/100）
#define END_QS_PM25_AVERAGE_CODE            0xB4        //PM2.5平均数据（1/100）
#define END_QS_CO2_AVERAGE_CODE             0xB5        //CO2平均数据（1/100）
#define END_QS_TVOC_AVERAGE_CODE            0xB6        //TVOC平均数据（原值）
#define END_QS_NOISE_AVERAGE_CODE           0xB7        //噪声平均数据（原值）

#define END_QS_TEMP_MEDIAN_CODE             0xC1        //温度中位数据（原值）
#define END_QS_HUMI_MEDIAN_CODE             0xC2        //湿度中位数据（原值）
#define END_QS_LUMI_MEDIAN_CODE             0xC3        //光照度中位数据（1/100）
#define END_QS_PM25_MEDIAN_CODE             0xC4        //PM2.5中位数据（1/100）
#define END_QS_CO2_MEDIAN_CODE              0xC5        //CO2中位数据（1/100）
#define END_QS_TVOC_MEDIAN_CODE             0xC6        //TVOC中位数据（原值）
#define END_QS_NOISE_MEDIAN_CODE            0xC7        //噪声中位数据（原值）

//1.在线状态
#define END_QS_ONLINE_CODE                  0x01        //在线
#define END_QS_OFFLINE_CODE                 0x00        //不在线
//2.传感指示设置
#define END_QS_LED_OFF_CODE                 0x00        //传感指示关闭
#define END_QS_LED_ON_CODE                  0xFF        //传感指示打开
#define END_QS_LED_RESTORE_CODE             0xFE        //传感指示恢复出厂设置

//温度(01)
#define END_QS_ROAD_01_CODE                 0x01        //温度传感器第01路
#define END_QS_ROAD_07_CODE                 0x07        //温度传感器第02路
#define END_QS_ROAD_13_CODE                 0x0D        //温度传感器第03路
#define END_QS_ROAD_19_CODE                 0x13        //温度传感器第04路
#define END_QS_ROAD_25_CODE                 0x19        //温度传感器第05路
#define END_QS_ROAD_31_CODE                 0x1F        //温度传感器第06路
#define END_QS_ROAD_37_CODE                 0x25        //温度传感器第07路
#define END_QS_ROAD_43_CODE                 0x2B        //温度传感器第08路
//湿度(02)
#define END_QS_ROAD_02_CODE                 0x02        //湿度传感器第01路
#define END_QS_ROAD_08_CODE                 0x08        //湿度传感器第02路
#define END_QS_ROAD_14_CODE                 0x0E        //湿度传感器第03路
#define END_QS_ROAD_20_CODE                 0x14        //湿度传感器第04路
#define END_QS_ROAD_26_CODE                 0x1A        //湿度传感器第05路
#define END_QS_ROAD_32_CODE                 0x20        //湿度传感器第06路
#define END_QS_ROAD_38_CODE                 0x26        //湿度传感器第07路
#define END_QS_ROAD_44_CODE                 0x2C        //湿度传感器第08路
//光照度(03)
#define END_QS_ROAD_03_CODE                 0x03        //光照传感器第01路
#define END_QS_ROAD_09_CODE                 0x09        //光照传感器第02路
#define END_QS_ROAD_15_CODE                 0x0F        //光照传感器第03路
#define END_QS_ROAD_21_CODE                 0x15        //光照传感器第04路
#define END_QS_ROAD_27_CODE                 0x1B        //光照传感器第05路
#define END_QS_ROAD_33_CODE                 0x21        //光照传感器第06路
#define END_QS_ROAD_39_CODE                 0x27        //光照传感器第07路
#define END_QS_ROAD_45_CODE                 0x2D        //光照传感器第08路
//PM2.5(04)
#define END_QS_ROAD_04_CODE                 0x04        //PM2.5传感器第01路
#define END_QS_ROAD_10_CODE                 0x0A        //PM2.5传感器第02路
#define END_QS_ROAD_16_CODE                 0x10        //PM2.5传感器第03路
#define END_QS_ROAD_22_CODE                 0x16        //PM2.5传感器第04路
#define END_QS_ROAD_28_CODE                 0x1C        //PM2.5传感器第05路
#define END_QS_ROAD_34_CODE                 0x22        //PM2.5传感器第06路
#define END_QS_ROAD_40_CODE                 0x28        //PM2.5传感器第07路
#define END_QS_ROAD_46_CODE                 0x2E        //PM2.5传感器第08路
//CO2(05)
#define END_QS_ROAD_05_CODE                 0x05        //CO2传感器第01路
#define END_QS_ROAD_11_CODE                 0x0B        //CO2传感器第02路
#define END_QS_ROAD_17_CODE                 0x11        //CO2传感器第03路
#define END_QS_ROAD_23_CODE                 0x17        //CO2传感器第04路
#define END_QS_ROAD_29_CODE                 0x1D        //CO2传感器第05路
#define END_QS_ROAD_35_CODE                 0x23        //CO2传感器第06路
#define END_QS_ROAD_41_CODE                 0x29        //CO2传感器第07路
#define END_QS_ROAD_47_CODE                 0x2F        //CO2传感器第08路
//TVOC(06)
#define END_QS_ROAD_06_CODE                 0x06        //TVOC传感器第01路
#define END_QS_ROAD_12_CODE                 0x0C        //TVOC传感器第01路
#define END_QS_ROAD_18_CODE                 0x12        //TVOC传感器第01路
#define END_QS_ROAD_24_CODE                 0x18        //TVOC传感器第01路
#define END_QS_ROAD_30_CODE                 0x1E        //TVOC传感器第01路
#define END_QS_ROAD_36_CODE                 0x24        //TVOC传感器第01路
#define END_QS_ROAD_42_CODE                 0x2A        //TVOC传感器第01路
#define END_QS_ROAD_48_CODE                 0x30        //TVOC传感器第01路

//终端：按键类==================================================================
        //(1-218):THP-H16
        //(1-18):THP-S18
        //(1-6):THZ-S15
#define END_KEY_01_CODE                     0x01        //回弹按键第01路
#define END_KEY_06_CODE                     0x06        //回弹按键第06路
#define END_KEY_18_CODE                     0x12        //回弹按键第18路
#define END_KEY_218_CODE                    0xDA        //回弹按键第218路

//终端：遥控器==================================================================
#define END_RCM_BINDING_CODE                0x61        //遥控器绑定
#define END_RCM_VERIFY_CODE                 0x62        //遥控器确认
#define END_RCM_INVALID_CODE                0x63        //遥控器无效
#define END_RCM_CLEAN_CODE                  0x64        //遥控器清码

//终端：电动式电机类============================================================
#define END_EM_ONLINE_STATUS_CODE           0x06        //窗帘在线状态
#define END_EM_SWITCH_CTRL_CODE             0x15        //窗帘开关控制
#define END_EM_ANGLE_CTRL_CODE              0x25        //窗帘角度控制
#define END_EM_LIGHT_CTRL_CODE              0x08        //晾衣架照明控制
#define END_EM_DRTING_CTRL_CODE             0x09        //晾衣架烘干控制
#define END_EM_AIR_DRY_CTRL_CODE            0x0A        //晾衣架风干控制
#define END_EM_DISINFECT_CTRL_CODE          0x0B        //晾衣架消毒控制
#define END_EM_ANION_CTRL_CODE              0x0C        //晾衣架负离子开关
#define END_EM_CURTAIN_STYLE_CODE           0x95        //窗帘类型设置
#define END_EM_ADDR_SET_CODE                0xA5        //窗帘地址设置
#define END_EM_REVERSE_SET_CODE             0xB5        //窗帘反向设置
#define END_EM_HAND_SET_CODE                0xC5        //窗帘手拉设置
#define END_EM_RANGE_SET_CODE               0xD5        //窗帘行程设置
#define END_EM_ANGLE_COEF_SET_CODE          0xE5        //窗帘角度系数设置

//1.在线状态
#define END_EM_ONLINE_CODE                  0x01        //窗帘在线
#define END_EM_OFFLINE_CODE                 0x00        //窗帘不在线
//2.开关控制(百分比：0~100)
#define END_EM_SCTRL_CLOSE_CODE             0xF0        //窗帘关闭/晾衣架下降
#define END_EM_SCTRL_STOP_CODE              0xF1        //窗帘停止
#define END_EM_SCTRL_OPEN_CODE              0xF2        //窗帘打开/晾衣架上升
//3.角度控制(角度：0~180)
#define END_EM_ACTRL_UP_CODE                0xF0        //窗帘角度增大
#define END_EM_ACTRL_DOWN_CODE              0xF1        //窗帘角度减小
//4.照明控制
#define END_EM_LIGHT_OFF_CODE               0x00        //关闭
#define END_EM_LIGHT_ON_CODE                0x01        //打开
//5.烘干控制
#define END_EM_DRYING_OFF_CODE              0x00        //关闭
#define END_EM_DRYING_ON_CODE               0x01        //打开
//6.风干控制
#define END_EM_AIR_DRY_OFF_CODE             0x00        //关闭
#define END_EM_AIR_DRY_ON_CODE              0x01        //打开
//7.消毒控制
#define END_EM_DISINFECT_OFF_CODE           0x00        //关闭
#define END_EM_DISINFECT_ON_CODE            0x01        //打开
//8.负离子开关
#define END_EM_ANION_OFF_CODE               0x00        //关闭
#define END_EM_ANION_ON_CODE                0x01        //打开
//9.窗帘类型
#define END_EM_STYLE_CURTAIN_CODE           0x01        //开合帘
#define END_EM_STYLE_SHUTTER_CODE           0x02        //卷帘
#define END_EM_STYLE_BLIND_CODE             0x03        //百叶帘
//10.地址设置
#define END_EM_ADDR_SET_OK_CODE             0x01        //窗帘地址设置成功
#define END_EM_ADDR_SET_FAIL_CODE           0x00        //窗帘地址设置失败
//11.反向设置
#define END_EM_REVERSE_MOTOR_CODE           0x01        //窗帘电机反向
#define END_EM_REVERSE_ANGLE_CODE           0x02        //窗帘角度反向
//12.手拉设置
#define END_EM_HAND_ON_CODE                 0x00        //窗帘手拉开启
#define END_EM_HAND_OFF_CODE                0x01        //窗帘手拉关闭
//13.行程设置
#define END_EM_RANGE_UP_CODE                0x01        //窗帘上行程
#define END_EM_RANGE_DOWN_CODE              0x02        //窗帘下行程
#define END_EM_RANGE_DELETE_CODE            0xF0        //窗帘删除行程
//14.角度系数设置(百分比：0~100)
#define END_EM_ACOEF_UP_CODE                0xF0        //窗帘角度系数增大
#define END_EM_ACOEF_DOWN_CODE              0xF1        //窗帘角度系数减小

//终端：电动窗帘================================================================
#define END_EM_ROAD_01_CODE                 0x01        //窗帘第01路
#define END_EM_ROAD_08_CODE                 0x08        //窗帘第08路
#define END_EM_ROAD_16_CODE                 0x10        //窗帘第16路

//终端：门锁====================================================================
#define END_LK_ONLINE_STATUS_CODE           0x41        //门锁在线状态
#define END_LK_CTRL_CODE                    0x50        //门锁操作
#define END_LK_STATUS_CHECK_CODE            0x50        //门锁状态查询
#define END_LK_KEY_CTRL_CODE                0x60        //钥匙操作
#define END_LK_UNLOCK_ALARM_CODE            0x70        //开锁报警
#define END_LK_ELIMI_ALARM_CODE             0x80        //门锁消警
#define END_LK_DEFENSE_CODE                 0x90        //门锁撤布防
#define END_LK_POWER_CODE                   0xD0        //门锁电量
#define END_LK_BINDING_CODE                 0xE0        //门锁绑定

//1.在线状态
#define END_LK_OFFLINE_CODE                 0x00        //门锁掉线码
#define END_LK_ONLINE_CODE                  0x01        //门锁在线码
//2.开关控制
#define END_LK_LOCK_CODE                    0x00        //门锁关锁动作
#define END_LK_UNLOCK_CODE                  0x01        //门锁开锁动作
#define END_LK_UNLOCK_EMER_CODE             0x02        //门锁应急开锁动作
//5.开锁警报
#define END_LK_UNLOCK_ILLEGAL_CODE          0x01        //非法钥匙开锁报警
#define END_LK_UNLOCK_HOSTAGE_CODE          0x02        //挟持开锁报警
#define END_LK_UNLOCK_BREAKING_CODE         0x03        //撬门报警
#define END_LK_UNLOCK_VIBRATION_CODE        0x04        //振动报警
#define END_LK_UNLOCK_OVERTIME_CODE         0x06        //未关门超时报警
#define END_LK_UNLOCK_NORMAL_CODE           0x10        //正常开锁报警
#define END_LK_UNLOCK_KEY_01_CODE           0x11        //1号钥匙开锁报警
//6.门锁消警
#define END_LK_ALARM_ELIMI_CODE             0x01        //门锁消警动作
//7.门锁不撤防
#define END_LK_DEFENSE_ON_CODE              0x01        //门锁布防
#define END_LK_DEFENSE_OFF_CODE             0x00        //门锁撤防
//8.门锁电量
#define END_LK_POWER_OK_CODE                0x00        //电量正常
#define END_LK_POWER_LOW_CODE               0x01        //电量不足
//9.门锁绑定
#define END_LK_BINDING_BIND_CODE            0x01        //门锁绑定动作
#define END_LK_BINDING_REMOVE_CODE          0x00        //门锁解绑动作

//终端：门锁
#define END_LK_ROAD_01_CODE                 0x01        //门锁第01路
#define END_LK_ROAD_02_CODE                 0x02        //门锁第02路
#define END_LK_ROAD_04_CODE                 0x04        //门锁第04路

//终端：背景音乐================================================================
#define END_CM_ONLINE_STATUS_CODE           0x11        //音响在线状态码
#define END_CM_POWER_STATUS_CODE            0x20        //音响开关控制
#define END_CM_SOURCE_SET_CODE              0x30        //音响音源选择
#define END_CM_VOLUME_SET_CODE              0x40        //音响音量设定
#define END_CM_VOLUME_ADJUST_CODE           0x41        //音响音量调整
#define END_CM_TREBLE_SET_CODE              0x42        //音响高音设定
#define END_CM_TREBLE_ADJUST_CODE           0x43        //音响高音调整
#define END_CM_BASS_SET_CODE                0x44        //音响低音设定
#define END_CM_BASS_ADJUST_CODE             0x45        //音响低音调整
#define END_CM_AUDIO_SET_CODE               0x46        //音响音效设定
#define END_CM_MUTE_STATUS_CODE             0x48        //音响静音控制
#define END_CM_RUN_MODE_CODE                0x60        //音响播放控制
#define END_CM_CHANNEL_SET_CODE             0x61        //音响曲目切换
#define END_CM_DIRECTORY_SET_CODE           0x62        //音响目录切换
#define END_CM_PLAY_MODE_CODE               0x63        //音响播放模式
#define END_CM_RADIO_STATUS_CODE            0x64        //音响收音状态
#define END_CM_RADIO_BAND_CODE              0x65        //音响收音频段
#define END_CM_SONG_NAME_CODE               0x66        //音响歌曲名

//1.在线状态
#define END_CM_OFFLINE_CODE                 0x00        //音响掉线码
#define END_CM_ONLINE_CODE                  0x01        //音响在线码
//2.开关控制
#define END_CM_POWER_OFF_CODE               0x00        //音响开关关闭
#define END_CM_POWER_ON_CODE                0x01        //音响开关打开
//3.音源选择
#define END_CM_SOURCE_NULL_CODE             0x00        //音源无介质
#define END_CM_SOURCE_USB_CODE              0x01        //音源USB/MP3
#define END_CM_SOURCE_TUNER_CODE            0x02        //音源TUNER
#define END_CM_SOURCE_DVD_CODE              0x03        //音源DVD
#define END_CM_SOURCE_PC_CODE               0x04        //音源PC
#define END_CM_SOURCE_TV_CODE               0x05        //音源TV
#define END_CM_SOURCE_AUX_CODE              0x06        //音源AUX
#define END_CM_SOURCE_AUX2_CODE             0x17        //音源AUX2
#define END_CM_SOURCE_IPOD_CODE             0x07        //音源IPOD
#define END_CM_SOURCE_SD_CODE               0x08        //音源SD
#define END_CM_SOURCE_FM_CODE               0x09        //音源FM
#define END_CM_SOURCE_BT_CODE               0x0A        //音源蓝牙
#define END_CM_SOURCE_IRADIO_CODE           0x0B        //音源IRADIO
#define END_CM_SOURCE_OP_CODE               0x0C        //音源Optical
#define END_CM_SOURCE_51_CODE               0x0D        //音源5.1LINE
#define END_CM_SOURCE_CD_CODE               0x0E        //音源CD
#define END_CM_SOURCE_OTHER_CODE            0x0F        //音源其它
#define END_CM_SOURCE_CBL_CODE              0x10        //音源CBL/SAT
#define END_CM_SOURCE_BR_CODE               0x11        //音源Blu-ray
#define END_CM_SOURCE_MPLAY_CODE            0x12        //音源MPLAY
#define END_CM_SOURCE_NET_CODE              0x13        //音源NET
#define END_CM_SOURCE_NET2_CODE             0x18        //音源NET2
#define END_CM_SOURCE_NET3_CODE             0x19        //音源NET3
#define END_CM_SOURCE_GAME_CODE             0x14        //音源GAME
#define END_CM_SOURCE_FLASH_CODE            0x15        //音源内存
#define END_CM_SOURCE_ALL_CODE              0x16        //音源全部

#define END_CM_SOURCE_SOFT_CODE             0x30        //音源轻音乐Soft Music
#define END_CM_SOURCE_POP_CODE              0x31        //音源流行乐Pop Music
#define END_CM_SOURCE_CLASSIC_CODE          0x32        //音源古典乐Classical Music
#define END_CM_SOURCE_ROCK_CODE             0x33        //音源摇滚乐Rock Music

#define END_CM_SOURCE_PARLOR_CODE           0x34        //音源会客Parlor
#define END_CM_SOURCE_DINING_CODE           0x35        //音源就餐Dining
#define END_CM_SOURCE_ENTTAIN_CODE          0x36        //音源娱乐Entertainment
#define END_CM_SOURCE_LEISURE_CODE          0x37        //音源休闲Leisure
#define END_CM_SOURCE_JOY_CODE              0x38        //音源欢乐Joy
#define END_CM_SOURCE_QUIET_CODE            0x39        //音源幽静Quiet
#define END_CM_SOURCE_ROMANTIC_CODE         0x3A        //音源浪漫Romantic
#define END_CM_SOURCE_WARM_CODE             0x3B        //音源温馨Warm
#define END_CM_SOURCE_ORIGINAL_CODE         0x3C        //音源原声Original
//5.音量调节
#define END_CM_VOLUME_UP_CODE               0xF0        //音响音量加
#define END_CM_VOLUME_DOWN_CODE             0xF1        //音响音量减
//8.音效控制
#define END_CM_AUDIO_NORMAL_CODE            0x00        //标准
#define END_CM_AUDIO_POP_CODE               0x01        //流行
#define END_CM_AUDIO_SOFT_CODE              0x02        //柔和/平滑
#define END_CM_AUDIO_CLASSIC_CODE           0x03        //古典
#define END_CM_AUDIO_JAZZ_CODE              0x04        //爵士
#define END_CM_AUDIO_ROCK_CODE              0x05        //摇滚
#define END_CM_AUDIO_BASS_CODE              0x06        //重音
#define END_CM_AUDIO_DANCE_CODE             0x07        //舞曲
#define END_CM_AUDIO_HIPHOP_CODE            0x08        //嘻哈
#define END_CM_AUDIO_VOCAL_CODE             0x09        //人声
#define END_CM_AUDIO_METAL_CODE		  				0x0A				//金属
//9.静音控制
#define END_CM_MUTE_ON_CODE                 0x01        //音响音量静音
#define END_CM_MUTE_OFF_CODE                0x00        //音响音量取消静音
//10.播放控制
#define END_CM_RUN_MODE_PLAY_CODE           0x01        //音响运行状态播放
#define END_CM_RUN_MODE_PAUSE_CODE          0x02        //音响运行状态暂停
#define END_CM_RUN_MODE_STOP_CODE           0x00        //音响运行状态停止
//11.曲目切换/12.目录切换
#define END_CM_CHANNEL_FORW_CODE            0x00        //音响频道选择/曲目切换上一曲
#define END_CM_CHANNEL_BACKW_CODE           0x01        //音响频道选择/曲目切换下一曲
//13.播放模式
#define END_CM_MODE_SINGLE_PLAY_CODE        0x01        //单曲播放
#define END_CM_MODE_SINGLE_REPEAT_CODE      0x02        //单曲循环
#define END_CM_MODE_ORDER_PLAY_CODE         0x03        //顺序播放
#define END_CM_MODE_DIRECT_PLAY_CODE        0x04        //目录播放
#define END_CM_MODE_SHUFFLE_PLAY_CODE       0x05        //随机播放
#define END_CM_MODE_ORDER_REPEAT_CODE       0x06        //顺序循环
//14.收音频段
#define END_CM_RADIO_FM_CODE                0x00        //收音FM
#define END_CM_RADIO_AM_CODE                0x01        //收音AM
//收音静音
#define END_CM_RADIO_MUTE_CODE              0x00        //收音静音
#define END_CM_RADIO_UNMUTE_CODE            0x01        //收音不静音
//15.歌曲名
#define END_CM_SONG_NAME_UTF8_CODE          0x01        //歌曲名为UTF-8编码
#define END_CM_SONG_NAME_GB2312_CODE        0x02        //歌曲名为GB2312编码

//终端：中央音响
#define END_CM_ROAD_01_CODE                 0x01        //中央音响第01路
#define END_CM_ROAD_08_CODE                 0x08        //中央音响第08路
#define END_CM_ROAD_09_CODE                 0x09        //中央音响第09路

//终端：中央空调================================================================
#define END_CAC_ONLINE_STATUS_CODE          0x11        //空调在线状态码
#define END_CAC_POWER_STATUS_CODE           0x20        //空调开关状态码
#define END_CAC_RUN_MODE_CODE               0x30        //空调运行模式码
#define END_CAC_FAN_FLOW_CODE               0x40        //空调风扇风量码
#define END_CAC_TEMPERATURE_SET_CODE        0x50        //空调设定温度码（0x0A~0x1E）
#define END_CAC_FAN_DIRECT_CODE             0x60        //空调设定风向码
#define END_CAC_TEMPERATURE_REAL_CODE       0x70        //空调吸入温度码（0x0A~0x1E）
#define END_CAC_TEMP_AVERAGE_CODE           0x71        //空调吸入温度平均值（0x0A~0x1E）
#define END_CAC_TEMP_MEDIAN_CODE            0x72        //空调吸入温度中位值（0x0A~0x1E）
#define END_CAC_FILTER_STATUS_CODE          0x80        //空调过滤网状态码
#define END_CAC_COMPRESSOR_STATUS_CODE      0x90        //空调压缩机状态码
#define END_CAC_LOCK_STATUS_CODE            0xA0        //空调锁定操作面板
#define END_CAC_FAULT_STATUS_CODE           0xB0        //空调故障状态码
#define END_CAC_FAULT_CODE_CODE             0xF0        //空调故障数值码

//1.在线状态
#define END_CAC_ONLINE_ON_CODE              0x01        //空调在线
#define END_CAC_ONLINE_OFF_CODE             0x00        //空调掉线
//2.开关控制
#define END_CAC_POWER_ON_CODE               0x01        //空调电源开启
#define END_CAC_POWER_OFF_CODE              0x00        //空调电源关闭
//3.模式控制
#define END_CAC_MODE_HEAT_CODE              0x01        //空调模式制热
#define END_CAC_MODE_COLD_CODE              0x02        //空调模式制冷
#define END_CAC_MODE_AIR_CODE               0x03        //空调模式送风
#define END_CAC_MODE_AUTO_CODE              0x04        //空调模式自动
#define END_CAC_MODE_VENTILATE_CODE         0x05        //空调模式换气
#define END_CAC_MODE_DEHUMID_CODE           0x06        //空调模式除湿
//4.风速控制
#define END_CAC_FAN_FLOW_AUTO_CODE          0x00        //空调风扇风量自动
#define END_CAC_FAN_FLOW_HIGHER_CODE        0x04        //空调风扇风量超高风
#define END_CAC_FAN_FLOW_HIGH_CODE          0x01        //空调风扇风量高风
#define END_CAC_FAN_FLOW_MID_CODE           0x02        //空调风扇风量中风
#define END_CAC_FAN_FLOW_LOW_CODE           0x03        //空调风扇风量低风
#define END_CAC_FAN_FLOW_LOWER_CODE         0x05        //空调风扇风量超低风
#define END_CAC_FAN_FLOW_1_CODE             0x01        //空调风扇风量风速1
#define END_CAC_FAN_FLOW_2_CODE             0x02        //空调风扇风量风速2
#define END_CAC_FAN_FLOW_3_CODE             0x03        //空调风扇风量风速3
#define END_CAC_FAN_FLOW_4_CODE             0x04        //空调风扇风量风速4
#define END_CAC_FAN_FLOW_5_CODE             0x05        //空调风扇风量风速5
//5.温度控制
//6.风向控制
#define END_CAC_FAN_DIR_P0_CODE             0x00        //空调风向P0
#define END_CAC_FAN_DIR_P1_CODE             0x01        //空调风向P1
#define END_CAC_FAN_DIR_P2_CODE             0x02        //空调风向P2
#define END_CAC_FAN_DIR_P3_CODE             0x03        //空调风向P3
#define END_CAC_FAN_DIR_P4_CODE             0x04        //空调风向P4
#define END_CAC_FAN_DIR_P5_CODE             0x05        //空调风向P5
#define END_CAC_FAN_DIR_STOP_CODE           0x06        //空调风向停止
#define END_CAC_FAN_DIR_SWING_CODE          0x07        //空调风向摇摆
#define END_CAC_FAN_DIR_AUTO_CODE           0x08        //空调风向自动
#define END_CAC_FAN_DIR_SWING_UD_CODE       0x09        //空调风向上下摇摆
#define END_CAC_FAN_DIR_SWING_LR_CODE       0x0A        //空调风向左右摇摆
//7.实温采集
//8.实温平均值
//9.实温中位值
//10.过滤网状态
#define END_CAC_FILTER_OK_CODE              0x00        //空调过滤网正常
#define END_CAC_FILTER_WASH_CODE            0x01        //空调过滤网清洗
//11.压缩机状态
#define END_CAC_COMPRESSOR_OFF_CODE         0x00        //空调压缩机关闭
#define END_CAC_COMPRESSOR_ON_CODE          0x01        //空调压缩机打开
//12.面板锁定控制
#define END_CAC_LOCK_OFF_CODE               0x00        //空调锁定操作面板解锁
#define END_CAC_LOCK_ON_CODE                0x02        //空调锁定操作面板锁定
#define END_CAC_LOCK_HALF_CODE              0x01        //空调锁定操作面板半锁
#define END_CAC_LOCK_ALL_CODE               0x02        //空调锁定操作面板全锁
//13.故障状态
#define END_CAC_FAULT_NONE_CODE             0x00        //空调无故障
#define END_CAC_FAULT_HAD_CODE              0x01        //空调有故障
//14.故障代码

//终端：中央空调
#define END_CAC_ROAD_01_CODE                0x01        //中央空调第01路
#define END_CAC_ROAD_08_CODE                0x08        //中央空调第08路
#define END_CAC_ROAD_09_CODE                0x09        //中央空调第08路
#define END_CAC_ROAD_16_CODE                0x10        //中央空调第16路

//终端：中央新风================================================================
#define END_CFA_ONLINE_STATUS_CODE          0x11        //新风在线状态码
#define END_CFA_POWER_STATUS_CODE           0x20        //新风开关状态码
#define END_CFA_RUN_MODE_CODE               0x30        //新风运行模式码
#define END_CFA_FAN_FLOW_CODE               0x40        //新风风扇风量码
#define END_CFA_EXHAUST_FAN_FLOW_CODE       0x41        //新风排风风扇风量码
#define END_CFA_BYPASS_STATUS_CODE          0x42        //新风旁通状态码
#define END_CFA_HUMIDITY_REAL_CODE          0x50        //新风湿度采集码(×10)(室内)
#define END_CFA_HUMI_AVERAGE_CODE           0x51        //新风采集湿度平均值(×10)(室内)
#define END_CFA_HUMI_REAL_OUTDOOR_CODE      0x54        //新风室外湿度采集码(×10)
#define END_CFA_HUMI_AVE_OUTDOOR_CODE       0x55        //新风室外采集湿度平均值(×10)
#define END_CFA_PM25_REAL_CODE              0x60        //新风PM2.5采集码(×1)
#define END_CFA_PM25_AVERAGE_CODE           0x61        //新风采集PM2.5平均值(×1)
#define END_CFA_VOC_REAL_CODE               0x68        //新风VOC采集码(×100)
#define END_CFA_VOC_AVERAGE_CODE            0x69        //新风采集VOC平均值(×100)
#define END_CFA_TEMPERATURE_REAL_CODE       0x70        //新风吸入温度码(×10)(室内)
#define END_CFA_TEMP_AVERAGE_CODE           0x71        //新风吸入温度平均值(×10)(室内)
#define END_CFA_TEMP_REAL_OUTDOOR_CODE      0x74        //新风室外温度码(×10)
#define END_CFA_TEMP_AVE_OUTDOOR_CODE       0x75        //新风室外温度平均值(×10)
#define END_CFA_FILTER_STATUS_CODE          0x80        //新风过滤网状态码
#define END_CFA_LOCK_STATUS_CODE            0xA0        //新风锁定操作面板
#define END_CFA_FAULT_STATUS_CODE           0xB0        //新风故障状态码
#define END_CFA_FAULT_CODE_CODE             0xF0        //新风故障数值码

//1.在线状态
#define END_CFA_ONLINE_ON_CODE              0x01        //新风在线
#define END_CFA_ONLINE_OFF_CODE             0x00        //新风掉线
//2.开关控制
#define END_CFA_POWER_ON_CODE               0x01        //新风电源开启
#define END_CFA_POWER_OFF_CODE              0x00        //新风电源关闭
//3.模式控制
#define END_CFA_MODE_STANDBY_CODE           0x01        //新风模式待机
#define END_CFA_MODE_AUTO_CODE              0x02        //新风模式自动/智能
#define END_CFA_MODE_OUTER_LOOP_CODE        0x03        //新风模式外循环
#define END_CFA_MODE_INNER_LOOP_CODE        0x04        //新风模式内循环
#define END_CFA_MODE_DISINFECT_CODE         0x05        //新风模式内消毒杀菌
#define END_CFA_MODE_HAND_CODE              0x06        //新风模式手动
#define END_CFA_MODE_STRONG_CODE            0x07        //新风模式强劲
#define END_CFA_MODE_SAVING_CODE            0x08        //新风模式经济/省电
#define END_CFA_MODE_VENTILATE_CODE         0x09        //新风模式换气
#define END_CFA_MODE_EXHAUST_CODE           0x0A        //新风模式排风
#define END_CFA_MODE_SPRAUT_CODE            0x0B        //新风模式春秋
#define END_CFA_MODE_ANTIFREEZE_CODE        0x0C        //新风模式防冻
//4.风速控制(新风)
#define END_CFA_FAN_FLOW_HIGH_CODE          0x01        //新风风扇风量高风
#define END_CFA_FAN_FLOW_MID_CODE           0x02        //新风风扇风量中风
#define END_CFA_FAN_FLOW_LOW_CODE           0x03        //新风风扇风量低风
#define END_CFA_FAN_FLOW_STOP_CODE          0x04        //新风风扇风量停止
#define END_CFA_FAN_FLOW_AUTO_CODE          0x05        //新风风扇风量自动
//5.排风风速控制
#define END_CFA_EXHAUST_FAN_FLOW_HIGH_CODE  0x01        //新风排风风扇风量高风
#define END_CFA_EXHAUST_FAN_FLOW_MID_CODE   0x02        //新风排风风扇风量中风
#define END_CFA_EXHAUST_FAN_FLOW_LOW_CODE   0x03        //新风排风风扇风量低风
#define END_CFA_EXHAUST_FAN_FLOW_STOP_CODE  0x04        //新风排风风扇风量停止
//6.旁通控制
#define END_CFA_BYPASS_ON_CODE              0x01        //新风旁通开启
#define END_CFA_BYPASS_OFF_CODE             0x00        //新风旁通关闭
//7.湿度采集(×10)(室内)
//8.湿度平均值(×10)(室内)
//9.室外湿度采集(×10)
//10.室外湿度平均值(×10)
//11.PM2.5采集(×1)
//12.PM2.5平均值(×1)
//13.VOC采集(×100)
//14.VOC平均值(×100)
//15.实温采集(×10)(室内)
//16.实温平均值(×10)(室内)
//17.室外实温采集(×10)
//18.室外实温平均值(×10)
//19.过滤网状态
#define END_CFA_FILTER_OK_CODE              0x00        //新风过滤网正常
#define END_CFA_FILTER_WASH_CODE            0x01        //新风过滤网清洗
//20.面板锁定控制
#define END_CFA_LOCK_OFF_CODE               0x00        //新风锁定操作面板解锁
#define END_CFA_LOCK_ON_CODE                0x02        //新风锁定操作面板锁定
#define END_CFA_LOCK_HALF_CODE              0x01        //新风锁定操作面板半锁
#define END_CFA_LOCK_ALL_CODE               0x02        //新风锁定操作面板全锁
//21.故障状态
#define END_CFA_FAULT_NONE_CODE             0x00        //新风无故障
#define END_CFA_FAULT_HAD_CODE              0x01        //新风有故障
//22.故障代码

//终端：中央新风
#define END_CFA_ROAD_01_CODE                0x01        //中央新风第01路
#define END_CFA_ROAD_08_CODE                0x08        //中央新风第08路
#define END_CFA_ROAD_09_CODE                0x09        //中央新风第08路
#define END_CFA_ROAD_16_CODE                0x10        //中央新风第16路

//终端：中央地暖================================================================
#define END_CFH_POWER_STATUS_CODE           0x94        //地暖电源状态码
#define END_CFH_MODE_STATUS_CODE            0x95        //地暖模式状态码
#define END_CFH_TEMPERATURE_SET_CODE        0x96        //地暖设定温度码(×10)
#define END_CFH_HEATING_STATUS_CODE         0x97        //地暖加热状态码
#define END_CFH_TEMPERATURE_REAL_CODE       0x98        //地暖吸入温度码(×10)
#define END_CFH_TEMP_AVERAGE_CODE           0xA1        //地暖吸入温度平均值(×10)
#define END_CFH_TEMP_MEDIAN_CODE            0xA2        //地暖吸入温度中位值(×10)
#define END_CFH_ONLINE_STATUS_CODE          0x99        //地暖在线状态码
#define END_CFH_LOCK_MODE_CODE              0xA0        //地暖锁定模式码

//1.开关控制
#define END_CFH_POWER_ON_CODE               0x00        //地暖电源开启
#define END_CFH_POWER_OFF_CODE              0x01        //地暖电源关闭
//2.模式控制
#define END_CFH_MODE_AUTO_CODE              0x00        //地暖模式自动
#define END_CFH_MODE_HAND_CODE              0x01        //地暖模式手动
#define END_CFH_MODE_TEMP_CODE              0x02        //地暖模式临时
#define END_CFH_MODE_LOCK_CODE              0x03        //地暖模式锁定
//3.设定温度(×10)
//4.加热状态
#define END_CFH_HEATING_ON_CODE             0x01        //地暖加热
#define END_CFH_HEATING_OFF_CODE            0x00        //地暖不加热
//5.实温采集(×10)
//6.实温平均值(×10)
//7.实温中位值(×10)
//8.在线状态
#define END_CFH_ONLINE_ON_CODE              0x01        //地暖在线
#define END_CFH_ONLINE_OFF_CODE             0x00        //地暖掉线
//9.面板锁定控制
#define END_CFH_LOCK_MODE_UNLOCK_CODE       0x00        //地暖未锁定
#define END_CFH_LOCK_MODE_SEMI_LOCK_CODE    0x01        //地暖半锁定
#define END_CFH_LOCK_MODE_FULL_LOCK_CODE    0x02        //地暖全锁定

//终端：中央地暖
#define END_CFH_ROAD_01_CODE                0x01        //地暖第01路
#define END_CFH_ROAD_06_CODE                0x06        //地暖第06路
#define END_CFH_ROAD_07_CODE                0x07        //地暖第07路
#define END_CFH_ROAD_08_CODE                0x08        //地暖第08路
#define END_CFH_ROAD_16_CODE                0x10        //地暖第16路

//终端：热水器==================================================================
#define END_WWH_POWER_STATUS_CODE           0x03      //热水器开关状态码
#define END_WWH_TEMPERATURE_SET_CODE        0x04      //热水器设定温度码
#define END_WWH_TEMPERATURE_REAL_CODE       0x05      //热水器实时温度码
#define END_WWH_TEMP_AVERAGE_CODE           0x06      //热水器实时温度平均值
#define END_WWH_ONLINE_STATUS_CODE          0x12      //热水器在线状态码
#define END_WWH_HEATING_STATUS_CODE         0x22      //热水器加热状态码
#define END_WWH_LOCK_STATUS_CODE            0x92      //热水器面板锁定状态码
#define END_WWH_FAULT_STATUS_CODE           0xA2      //热水器故障状态码
#define END_WWH_FAULT_CODE_CODE             0xE2      //热水器故障数值码

//1.开关控制
#define END_WWH_POWER_ON_CODE               0xFF        //热水器电源开启
#define END_WWH_POWER_OFF_CODE              0x00        //热水器电源关闭
//2.设定温度
//3.实温采集
//4.实温平均值
//5.在线状态
#define END_WWH_ONLINE_ON_CODE              0x01        //热水器在线
#define END_WWH_ONLINE_OFF_CODE             0x00        //热水器掉线
//6.加热状态
#define END_WWH_HEATING_ON_CODE             0x01        //热水器加热
#define END_WWH_HEATING_OFF_CODE            0x00        //热水器不加热
//7.面板锁定控制
#define END_WWH_LOCK_OFF_CODE               0x00        //热水器锁定操作面板解锁
#define END_WWH_LOCK_ON_CODE                0x02        //热水器锁定操作面板锁定
#define END_WWH_LOCK_HALF_CODE              0x01        //热水器锁定操作面板半锁
#define END_WWH_LOCK_ALL_CODE               0x02        //热水器锁定操作面板全锁
//8.故障状态
#define END_WWH_FAULT_NONE_CODE             0x00        //热水器无故障
#define END_WWH_FAULT_HAD_CODE              0x01        //热水器有故障
//9.故障代码

//终端：热水器
#define END_WWH_ROAD_01_CODE                0x01        //热水器第01路

#endif

/********************************************************************************
*                                   NO MORE CODE                                *
********************************************************************************/
