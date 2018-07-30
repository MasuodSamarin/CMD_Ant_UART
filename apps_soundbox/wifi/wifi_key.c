#include "includes.h"
#include "sdk_cfg.h"
#include "wifi/wifi_key.h"
#include "common/msg.h"

/*******************************************************************
                            AD������
*******************************************************************/
#define ADKEY_WIFI_SHORT		\
						/*00  220k ����ƿ���	 */   	MSG_EAR_LED,\
						/*01  100k �ղ�	 */   		MSG_WIFI_COLLECTION,\
						/*02  51k  ΢��    */       	NO_MSG,\
						/*03  33k  WIFIģʽ  */   	MSG_WIFI_MODE,\
						/*04  24K  ����Ӣ  ��Ӣ����*/      MSG_WIFI_CH_2_EN,\
						/*05  15k  ����ת��*/ 			MSG_CHANGE_WORKMODE,\
						/*06  9.1K ��һ��  */    		MSG_WIFI_VOL_DOWN,\
						/*07  6.2k ��һ��  */   		MSG_WIFI_VOL_UP,\
						/*08  3K   ��ͣ����*/ 			MSG_WIFI_PP,\
						/*09  0K   ��������*/ 		    MSG_WIFI_CHAT,


#define ADKEY_WIFI_LONG		\
                        /*00  ͯ��*/        MSG_KEY_LOCK,\
                        /*01  �����ղ�*/      MSG_WIFI_COLL_PLAY,\
                        /*02*/      	  NO_MSG,\
                        /*03  WiFi����*/    MSG_WIFI_SET,\
                        /*04*/            NO_MSG,\
                        /*05*/            NO_MSG,\
                        /*06  ������*/       MSG_WIFI_PREV_FILE,\
                        /*07  ������*/       MSG_WIFI_NEXT_FILE,\
                        /*08*/            NO_MSG,\
                        /*09*/            NO_MSG,


#define ADKEY_WIFI_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02  ΢�Ŀ�ʼ*/      MSG_WIFI_WECHAT_START,\
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
                        /*02  ΢�Ľ���*/      MSG_WIFI_WECHAT_STOP,\
                        /*03*/    		  NO_MSG,\
                        /*04*/    		  NO_MSG,\
                        /*05*/    		  NO_MSG,\
                        /*06*/    		  NO_MSG,\
                        /*07*/    		  NO_MSG,\
                        /*08*/    		  NO_MSG,\
                        /*09*/    		  NO_MSG,

const u8 wifi_ad_table[4][10] =
{
    /*�̰�*/	    {ADKEY_WIFI_SHORT},
    /*����*/		{ADKEY_WIFI_LONG},
    /*����*/		{ADKEY_WIFI_HOLD},
    /*����̧��*/	{ADKEY_WIFI_LONG_UP},
};

