#ifndef MSG_H
#define MSG_H

#include "typedef.h"

#define NO_MSG 0xff

enum
{
    MSG_0 = 0,
    MSG_1,
    MSG_2,
    MSG_3,
    MSG_4,
    MSG_5,
    MSG_6,
    MSG_7,
    MSG_8,
    MSG_9,
	MSG_VOL_UP,
	MSG_VOL_DOWN,
    MSG_VOL_STEREO,
	MSG_MUTE,
	MSG_POWER_OFF,
	MSG_POWER_OFF_HOLD,
	MSG_POWER_KEY_UP,
	MSG_POWER_OFF_KEY_MSG,
	MSG_POWER_ON,
    MSG_UPDATA,
	MSG_LOW_POWER,
	MSG_LOW_POWER_VOICE,

	///-------work_mode---------------
	MSG_CHANGE_WORKMODE,
	MSG_NEXT_WORKMODE,
	MSG_PRE_WORKMOD,
    MSG_LAST_WORKMOD,

    // UI MAIN
    MSG_ENTER_MENUMAIN,
	MSG_ENTER_SLEEP_MODE,
    MSG_APP_MAIN_MSGLIST,

	MSG_VOCAL_PP,
    ///-------main_msg，此消息前的消息发送到MAIN线程---------------
    MSG_MAIN_MAX,

	///-------music app---------------
	MSG_MUSIC_NEXT_FILE = 0x20,
    MSG_MUSIC_PREV_FILE,
    MSG_MUSIC_PP,
    MSG_MUSIC_PLAY,
    MSG_MUSIC_PAUSE,
    MSG_MUSIC_STOP,
    MSG_MUSIC_FF,
    MSG_MUSIC_FR,
    MSG_MUSIC_FFR_DONE,
    MSG_MUSIC_RPT,
    MSG_MUSIC_EQ,
    MSG_MUSIC_U_SD,
    MSG_MUSIC_DEL_FILE,
    MSG_MUSIC_SPC_FILE,
    MSG_MUSIC_AB_RPT,
    MSG_MUSIC_PLAY_SN,
	MSG_MUSIC_SET_SPEED,
	MSG_MUSIC_SET_PITCH,
	//0x32
	MSG_MUSIC_DIR_MODE,
	MSG_MUSIC_REVERT_PLAY,
	MSG_AI_TOY_VOL_UP,
	MSG_AI_TOY_VOL_DOWN,
	MSG_AI_TOY_MIC,
	MSG_AI_ACTIVE,
	MSG_AI_BT_DISCONNECT_CTRL,
	MSG_CHANGE_NET_RES_VER_PRIMARY,//小学教材版本切换
	MSG_CHANGE_NET_RES_SUB_PRIMARY,//小学教材学科切换
	MSG_CHANGE_NET_RES_GRADE_PRIMARY,//小学教材年级切换
	MSG_CHANGE_NET_RES_VER_JUNIOR,//初中教材版本切换
	MSG_CHANGE_NET_RES_SUB_JUNIOR,//初中教材学科切换
	MSG_CHANGE_NET_RES_GRADE_JUNIOR,//初中教材年级切换
	MSG_CHANGE_NET_RES_CHILD,//教材幼儿资源切换


    ///-------FM app---------------
    MSG_FM_SCAN_ALL_INIT = 0x40,
    MSG_FM_INIT,
	MSG_FM_SCAN_ALL,
	MSG_FM_PREV_STATION,
	MSG_FM_NEXT_STATION,
	MSG_FM_SCAN_ALL_DOWN,
	MSG_FM_SCAN_ALL_UP,
	MSG_FM_PREV_STEP,
	MSG_FM_NEXT_STEP,
	MSG_SRC,
	MSG_FM_SELECT_CHANNEL,
    MSG_FM_PP,
    MSG_FM_DEL_CHANNEL,
    MSG_FM_SAVE_CHANNEL,
    MSG_FM_SELECT_FREQ,
    ///-------BT app---------------
    MSG_BT_NEXT_FILE = 0x50,
    MSG_BT_PREV_FILE,
    MSG_BT_PP,
    MSG_BT_CALL_LAST_NO,
    MSG_BT_CALL_CONTROL,
    MSG_BT_CALL_REJECT,
    MSG_BT_ANSWER_CALL,
    MSG_BT_SHUTTER,
    MSG_BT_RESET,
    MSG_BT_STACK_STATUS_CHANGE,
	MSG_TEST_HFP,
    MSG_DISCONNECT_ALL_LINK,
    MSG_BT_CONNECT_CTL,
    MSG_BT_CONNECT_STEREO_CTL,
    MSG_BT_HID_CTRL,
    MSG_BT_HID_TAKE_PIC,
    MSG_BT_MUSIC_EQ,
    MSG_BT_STEREO_EQ,
    MSG_BT_SYNC_STEREO_EQ,
    MSG_BT_PAGE_SCAN,
	MSG_BT_SPP_UPDATA,
    MSG_BT_STEREO_SEARCH_DEVICE,
	MSG_DISP_MENU,///自动刷新界面
	MSG_BT_FAST_TEST,
	MSG_BT_TWS_DELETE_ADDR,
	MSG_OSC_INTER_CAP_WRITE,
	
	//0x6A

	MSG_SPEECH_INPUT,
	MSG_MICROPHONE,
	MSG_WECHAT,
	MSG_CH_2_EN,
	MSG_EN_2_CH,

    ///-------AUX app---------------
    MSG_AUX_INIT = 0x70,
    MSG_AUX_MUTE,
	
	MSG_ECHO_SET_PARM,
	MSG_PITCH_SET_PARM,

	///htk
    MSG_HTK_LOOP_CMD,
	//speex
	MSG_SPEEX_START,
	MSG_SPEEX_STOP,
	MSG_SPEEX_SEND_START,
	MSG_SPEEX_SEND_STOP,
	MSG_SPEEX_SEND_CONTINUE_END,
	MSG_SPEEX_ENCODE_ERR,
	MSG_SMART_CHECK_DISCONNECT,
	MSG_SMART_NOTICE_PLAN,
	MSG_IDLE_TIMEOUT_POWER_OFF,
	MSG_SMART_CONNECT,
	MSG_SMART_DISCONNECT,


    ///-------PC app---------------
    MSG_PC_MODE_INIT = 0x80,
    MSG_PC_CARD_READER,
    MSG_PC_SPK_MUTE,
    MSG_PC_SPK_UNMUTE,
    MSG_PC_SPK_VOL,
    MSG_PC_MUTE,
    MSG_PC_VOL_UP,
    MSG_PC_VOL_DOWN,
    MSG_PC_PP,
    MSG_PC_PLAY_NEXT,
    MSG_PC_PLAY_PREV,
    MSG_PC_UPDATA,
    MSG_PC_SPK_PP,
    MSG_PC_MIC_MUTE,
    MSG_PC_MIC_UNMUTE,
    MSG_PC_MIC_VOL,

    ///-------RTC app---------------
    MSG_RTC_INIT = 0x90,
    MSG_RTC_SETTING,
    MSG_ALM_SETTING,
    MSG_ALM_SW,
    MSG_ALM_ON,
    MSG_ALARM_OFF,
    MSG_RTC_PLUS,
    MSG_RTC_MINUS,
    MSG_RTC_POWER_DOWN,

    ///-------ENCODE app---------------
    MSG_REC_INIT,
    MSG_REC_START,
    MSG_REC_STOP,
    MSG_REC_PP,
    MSG_REC_PLAY,
    MSG_ENCODE_ERR,

    MSG_ECHO_START,
    MSG_ECHO_STOP,

    ///-------IDLE app--------------
    MSG_IDLE_MODE,
    MSG_IDLE_CTL,
    MSG_ENTER_IDLE_TASK,
    MSG_EXIT_IDLE_TASK,
    // MSG_IDLE_CNT,
    // MSG_IDLE_CNT_LONG,
    // MSG_IDLE_CNT_HOLD,
    // MSG_IDLE_CNT_UP,

	MSG_PROMPT_PLAY,

    MSG_INPUT_TIMEOUT,
    MSG_HALF_SECOND,
    MSG_ENTER_MENULIST,
    MSG_APP_MSGLIST,
	MSG_DAC_ON,
	MSG_DAC_OFF,

	//解码器消息
	SYS_EVENT_BEGIN_DEC = 0xB0,
    SYS_EVENT_DEC_FR_END,
    SYS_EVENT_DEC_FF_END,
    SYS_EVENT_DEC_END,
    SYS_EVENT_DEC_DEVICE_ERR,

    SYS_EVENT_DEC_SET_END,

    SYS_EVENT_PLAY_SEL_END,

	///-------WiFi app--------------
	MSG_WIFI_MODE = 0xB7,  	
	MSG_WIFI_CTL,
	MSG_ENTER_WIFI_TASK,
	MSG_EXIT_WIFI_TASK,
	MSG_KEY_LOCK,		///儿童锁
	MSG_EAR_LED,
	MSG_WIFI_CONNECT,
	MSG_WIFI_DISCONNECT,
	MSG_WIFI_CONNECTING, ///0xBF
	
	MSG_WIFI_PLAY = 0xD6,
	MSG_WIFI_PAUSE,
	MSG_WIFI_CHATING,
	MSG_WIFI_CHAT_FAILED,
	MSG_WIFI_CHAT_SUCCESS,	
	MSG_WIFI_PP,	
	MSG_WIFI_NEXT_FILE,
	MSG_WIFI_PREV_FILE,
	MSG_WIFI_VOL_UP,
	MSG_WIFI_VOL_DOWN,
	MSG_WIFI_WECHAT_START,	///微信聊天
	MSG_WIFI_WECHAT_STOP,
	MSG_WIFI_CHAT,		///语音点歌
	MSG_WIFI_COLLECTION,///收藏
	MSG_WIFI_COLL_PLAY, ///播放收藏的内容
	MSG_WIFI_CH_2_EN,
	MSG_WIFI_EN_2_CH,
	MSG_WIFI_SET,		///0xE7    WiFi配网
	MSG_WIFI_DAILY_NEWS,
	MSG_WIFI_POWER_OFF,
	MSG_WIFI_POWER_WARNING,
	MSG_NULL = 0xff,
};

enum{
//	SYS_MSG_0 = 0x40,

	SYS_EVENT_DEV_ONLINE = 0xc0,
	SYS_EVENT_DEV_OFFLINE,
    SYS_EVENT_LGDEV_ONLINE,
    SYS_EVENT_LGDEV_OFFLINE,
    SYS_EVENT_SYSCLK_NOTFIT_DEVMOUNT,   ///<当前系统时钟不满足设备枚举需求，收到此消息，切换进music
	SYS_EVENT_AUX_IN,           ///<AUX插入
	SYS_EVENT_AUX_OUT,          ///<AUX拔出
	SYS_EVENT_PC_IN,            ///<PC 插入
	SYS_EVENT_PC_OUT,           ///<PC 拔出
	SYS_EVENT_DECODE_END,
	SYS_EVENT_STORE_BP,
	SYS_EVENT_RESTORE_BP,
	SYS_EVENT_DEL_TASK,
	SYS_EVENT_TONE_END,
	SYS_EVENT_RES_MANAGE_RUN,
	SYS_EVENT_TASK_EXIT_REQ,
	SYS_EVENT_TASK_RUN_REQ,
    SYS_EVENT_BT_BACKCON,       ///<蓝牙在后台才连接成功，由用户选择处理
	SYS_EVENT_BT_BACKDISCON,    ///<蓝牙在后台断开成功，由用户选择处理
	SYS_EVENT_DEV_BEGIN_MOUNT,
	SYS_EVENT_DEV_MOUNT_ERR,
 	SYS_EVENT_SYS_TIMER_DELAY,  ///0xD5
};

enum
{
    MSG_RSCP_RECIEVE_DATA = 0x3001,    //
    MSG_RSCP_RECIEVE_WAIT,    //
    
	//pack send
    MSG_RSCP_CHANGE_WORDMODE_ACTION,
    MSG_RSCP_REPORT_FRAME,
    MSG_RSCP_REPORT_CTL_STATE,
    MSG_RSCP_REPORT_LIGHT_STATE,
    MSG_RSCP_REPORT_LONGFRAME,
    MSG_RSCP_REPORT_ID3_INFO,
    MSG_RSCP_SEND_OPT_DATA,
    MSG_RSCP_SEND_OPT_DATA_NO_ACK,
    // MSG_RSCP_REPORT_MODE_INFO,

};



struct event_head {
	const char *str;
	int len;
	char data[0];
};

#endif



