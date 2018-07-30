#include "includes.h"
#include "sdk_cfg.h"
#include "wifi/wifi_key.h"
#include "common/msg.h"

/*******************************************************************
                            AD按键表
*******************************************************************/
#define ADKEY_WIFI_SHORT		\
						/*00  220k 耳朵灯开关	 */   	MSG_EAR_LED,\
						/*01  100k 收藏	 */   		MSG_WIFI_COLLECTION,\
						/*02  51k  微聊    */       	NO_MSG,\
						/*03  33k  WIFI模式  */   	MSG_WIFI_MODE,\
						/*04  24K  中译英  ，英译中*/      MSG_WIFI_CH_2_EN,\
						/*05  15k  功能转换*/ 			MSG_CHANGE_WORKMODE,\
						/*06  9.1K 上一曲  */    		MSG_WIFI_VOL_DOWN,\
						/*07  6.2k 下一曲  */   		MSG_WIFI_VOL_UP,\
						/*08  3K   暂停播放*/ 			MSG_WIFI_PP,\
						/*09  0K   语音聊天*/ 		    MSG_WIFI_CHAT,


#define ADKEY_WIFI_LONG		\
                        /*00  童锁*/        MSG_KEY_LOCK,\
                        /*01  播放收藏*/      MSG_WIFI_COLL_PLAY,\
                        /*02*/      	  NO_MSG,\
                        /*03  WiFi配网*/    MSG_WIFI_SET,\
                        /*04*/            NO_MSG,\
                        /*05*/            NO_MSG,\
                        /*06  音量减*/       MSG_WIFI_PREV_FILE,\
                        /*07  音量加*/       MSG_WIFI_NEXT_FILE,\
                        /*08*/            NO_MSG,\
                        /*09*/            NO_MSG,


#define ADKEY_WIFI_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02  微聊开始*/      MSG_WIFI_WECHAT_START,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define ADKEY_WIFI_LONG_UP	\
                        /*00*/            NO_MSG,\
                        /*01*/            NO_MSG,\
                        /*02  微聊结束*/      MSG_WIFI_WECHAT_STOP,\
                        /*03*/    		  NO_MSG,\
                        /*04*/    		  NO_MSG,\
                        /*05*/    		  NO_MSG,\
                        /*06*/    		  NO_MSG,\
                        /*07*/    		  NO_MSG,\
                        /*08*/    		  NO_MSG,\
                        /*09*/    		  NO_MSG,

const u8 wifi_ad_table[4][10] =
{
    /*短按*/	    {ADKEY_WIFI_SHORT},
    /*长按*/		{ADKEY_WIFI_LONG},
    /*连按*/		{ADKEY_WIFI_HOLD},
    /*长按抬起*/	{ADKEY_WIFI_LONG_UP},
};

