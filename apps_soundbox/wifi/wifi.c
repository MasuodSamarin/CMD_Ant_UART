#include "bt_key_deal.h"
#include "rtos/os_api.h"
#include "common/msg.h"
#include "common/app_cfg.h"
#include "bluetooth/avctp_user.h"
#include "rtos/task_manage.h"
#include "play_sel/play_sel.h"
#include "dec/decoder_phy.h"
#include "ui/led/led.h"
#include "dac/dac_api.h"
#include "dac/dac.h"
#include "ui/ui_api.h"
#include "bt_key_msg.h"
#include "key_drv/key.h"
#include "bt_ui.h"
#include "dac/eq_api.h"
#include "sys_detect.h"
#include "dac/eq.h"
#include "encode/encode.h"
#include "echo/echo_api.h"
#include "echo/echo_deal.h"
#include "vm/vm.h"
#include "vm/vm_api.h"
#include "rcsp/rcsp_interface.h"
#include "bluetooth/nfc_api.h"
#include "key_drv/key_voice.h"
#include "ai_toy.h"
#include "ui/led/led_eye.h"
#include "bt_smart.h"

#include "uart.h"
#include "cpu/uart_api.h"
#include "wifi/wifi.h"
#include "wifi/wifi_key.h"


extern void wifi_uart_send(u8 data, u8 len);
extern void ble_server_close(void);
extern void bt_edr_close(void);
extern void bt_prompt_play_by_name(void * file_name, void * let);
static tbool wifi_notice_play_callback(void *priv, int msg[])
{
	return false;
}

static u8 g_wifi_mode = WIFI_MODE_CH_2_EN; //中英互译状态
bool wifi_mode_flag = 0;	//WiFi模式下为1，按键转模式到其他模式为0
extern u8 microphone_enable;
extern bool wifi_dc_check;	//充电检测
REVERB_API_STRUCT * wifi_reverb = NULL;
static void wifi_task(void *p)
{
	NOTICE_PLAYER_ERR n_err;
    int msg[6];
	int tmp_msg;
	dac_channel_on(MUSIC_CHANNEL, FADE_ON);
	set_sys_vol(dac_ctl.sys_vol_l,dac_ctl.sys_vol_r,FADE_ON);

	//ble_server_close();
	bt_edr_close();

    wifi_puts("\n************************WIFI TASK********************\n");

	/*n_err = notice_player_play_by_path(WIFI_TASK_NAME, 
			(char *)AI_TOY_NOTICE_SLEEP, 
			wifi_notice_play_callback,
			NULL);
	*/
	
	wifi_reverb = NULL;
	if(microphone_enable)
	{
		tmp_msg = MSG_ECHO_START;
		echo_msg_deal_api((void**)&wifi_reverb, &tmp_msg);
	}

	while(1)
	{
		memset(msg,0x00,sizeof(msg));
		os_taskq_pend(0, ARRAY_SIZE(msg), msg);
		clear_wdt();
       
		switch(msg[0])
		{
			case MSG_HALF_SECOND:
			//case SYS_EVENT_PLAY_SEL_END: //提示音结束
				break;
				
			case SYS_EVENT_DEL_TASK:
				if (os_task_del_req_name(OS_TASK_SELF) == OS_TASK_DEL_REQ)
				{
					echo_exit_api((void**)&wifi_reverb);
					os_task_del_res_name(OS_TASK_SELF);
				}
				break;

	        case MSG_WIFI_CTL:
	            os_taskq_post_msg(MAIN_TASK_NAME, 1, MSG_EXIT_WIFI_TASK);
	            break;

			case MSG_MICROPHONE:
				if(msg[1] == 0)
				{
					//wifi_puts("microphone_disable_wifi!\n");
					microphone_enable = 0;
					wifi_uart_send(WIFI_ECHO_STOP, 1);
					tmp_msg = MSG_ECHO_STOP;
					//bt_prompt_play_by_name(AI_TOY_NOTICE_EXIT_MIC,NULL);
					echo_msg_deal_api((void**)&wifi_reverb, &tmp_msg);
				}
				else
				{
					//wifi_puts("microphone_enable_wifi!\n");
					microphone_enable = 1;
					wifi_uart_send(WIFI_ECHO_START, 1);
					tmp_msg = MSG_ECHO_START;
					//bt_prompt_play_by_name(AI_TOY_NOTICE_ENTER_MIC,NULL);
					echo_msg_deal_api((void**)&wifi_reverb, &tmp_msg);
				}
				break;

			case MSG_LOW_POWER_VOICE:
				if(!wifi_dc_check)
				{
					wifi_puts("wifi_low_power_warning!\n");
					wifi_uart_send(WIFI_LOW_POWER_WARN, 1);
				}
				break;
			
			/*case MSG_LOW_POWER:
				eye_led_api(EFFECT_POWER_OFF, 15 ,0);
				wifi_uart_send(WIFI_LOW_POWER_OFF, 1);
				break;
			*/	
			case MSG_WIFI_DISCONNECT:
				eye_led_api(EFFECT_NO_CONNECT, 0 ,0);
				break;
			case MSG_WIFI_CONNECT:
				eye_led_api(EFFECT_CONNECT_OK, 0 ,0);
				break;
			case MSG_WIFI_CONNECTING:
				eye_led_api(EFFECT_CONNECT, 0 ,0);
				break;
			case MSG_WIFI_PLAY:
				eye_led_api(EFFECT_PLAY, 0 ,0);
				break;
			case MSG_WIFI_PAUSE:
				eye_led_api(EFFECT_PAUSE, 0 ,0);
				break;
			
			case MSG_WIFI_CHATING:
				eye_led_api(EFFECT_SPEECH_INPUT, 0 ,0);
				break;
			case MSG_WIFI_CHAT_FAILED:
				eye_led_api(EFFECT_SPEECH_RESULT_FAIL, 0 ,0);
				break;
			case MSG_WIFI_CHAT_SUCCESS:
				eye_led_api(EFFECT_SPEECH_RESULT_OK, 0 ,0);
				break;
				
			case MSG_WIFI_PP:		
				wifi_uart_send(KEY_VALUE_PLAY, 1);
				break;
			case MSG_WIFI_NEXT_FILE:
				wifi_uart_send(KEY_VALUE_NEXT, 1);
				eye_led_api(EFFECT_NEXT, 15 ,0);
				break;
			case MSG_WIFI_PREV_FILE:
				wifi_uart_send(KEY_VALUE_PREV, 1);
				eye_led_api(EFFECT_PREV, 15 ,0);
				break;
			case MSG_WIFI_VOL_UP:
				wifi_uart_send(KEY_VALUE_VOL_UP, 1);
				break;
			case MSG_WIFI_VOL_DOWN:
				wifi_uart_send(KEY_VALUE_VOL_DOWN, 1);
				break;
			case MSG_WIFI_WECHAT_START:
				wifi_uart_send(KEY_VALUE_WECHAT_START, 1);
				break;
			case MSG_WIFI_WECHAT_STOP:
				wifi_uart_send(KEY_VALUE_WECHAT_STOP, 1);
				break;
			case MSG_WIFI_CHAT:			//语音对话点播
				wifi_uart_send(KEY_VALUE_CHAT, 1);
				break;
			case MSG_WIFI_COLLECTION:	//收藏
				wifi_uart_send(KEY_VALUE_COLLECTION, 1);
				break;
			case MSG_WIFI_COLL_PLAY:	//播放收藏内容
				wifi_uart_send(KEY_VALUE_COLL_PLAY, 1);
				break;

			case MSG_WIFI_CH_2_EN:		//中英互译
				eye_led_api(EFFECT_SPEECH_INPUT, 0 ,0);
				if(g_wifi_mode == WIFI_MODE_EN_2_CH){
					g_wifi_mode = WIFI_MODE_CH_2_EN;
					wifi_uart_send(KEY_VALUE_CH_2_EN, 1);
				}
				else if(g_wifi_mode == WIFI_MODE_CH_2_EN){
					g_wifi_mode = WIFI_MODE_EN_2_CH;
					wifi_uart_send(KEY_VALUE_EN_2_CH, 1);
				}
				break;
				
			case MSG_WIFI_SET:			//WiFi配网
				wifi_uart_send(KEY_VALUE_WIFI_SET, 1);
				break;

			case MSG_WIFI_DAILY_NEWS:
				wifi_uart_send(WIFI_DAILY_NEWS, 1);
			default:
				break;
		}
	}
}


/*----------------------------------------------------------------------------*/
/**@brief  WIFI 任务创建
   @param  priv：任务间参数传递指针
   @return 无
   @note   static void wifi_task_init(void *priv)
*/
/*----------------------------------------------------------------------------*/
static void wifi_task_init(void *priv)
{
    u32 err;
	err = os_task_create(wifi_task,
			(void*)0,
			TaskWiFiPrio,
			10,
			WIFI_TASK_NAME);

	wifi_uart_send(WIFI_MODE_START, 1);//通知WIFI模块，进入工作
	wifi_mode_flag = 1;
    if(OS_NO_ERR == err)
    {
        key_msg_register(WIFI_TASK_NAME, wifi_ad_table, NULL, NULL, NULL);
    }
}


/*----------------------------------------------------------------------------*/
/**@brief  WIFI 任务删除退出
   @param  无
   @return 无
   @note   static void wifi_task_exit(void)
*/
/*----------------------------------------------------------------------------*/
static void wifi_task_exit(void)
{
	if (os_task_del_req(WIFI_TASK_NAME) != OS_TASK_NOT_EXIST)
	{
		os_taskq_post_event(WIFI_TASK_NAME, 1, SYS_EVENT_DEL_TASK);
		do{
			OSTimeDly(1);
		} while(os_task_del_req(WIFI_TASK_NAME) != OS_TASK_NOT_EXIST);
		wifi_uart_send(WIFI_MODE_STOP, 1);	//通知WIFI模块，结束工作
		wifi_puts("del_wifi_task: succ\n");
	}
}


/*----------------------------------------------------------------------------*/
/**@brief  WIFI 任务信息
   @note   const struct task_info wifi_task_info
*/
/*----------------------------------------------------------------------------*/
TASK_REGISTER(wifi_task_info) = {
	.name = WIFI_TASK_NAME,
	.init = wifi_task_init,
	.exit = wifi_task_exit,
};
