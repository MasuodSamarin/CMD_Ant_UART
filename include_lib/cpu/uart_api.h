#ifndef __UART_API_H__
#define __UART_API_H__

#include "typedef.h"
#include "uart_param.h"

typedef struct uart_handle
{
    char name[5];
    void (*putbyte)(void *param,char a);
    char (*getbyte)(void *param);
}__uart_handle;


void uart_module_on();
void uart_module_off();
s32 uart_module_open(__uart_handle *handle,char *name);
s32 uart_module_close(__uart_handle *handle);
s32 uart_module_init(__uart_handle *handle,__uart_param *param);
s32 uart_module_start(__uart_handle *handle);
s32 uart_module_stop(__uart_handle *handle);
s32 uart_reg_isr_callback_fun(__uart_handle *handle,u32 priority,void (*callback_fun)(u8 value,void *p,u8 isr_flag));
s32 uart_unreg_isr_callback_fun(__uart_handle *handle,u32 priority,void (*callback_fun)(u8 value,void *p,u8 isr_flag));
s32 uart_module_ctrl(__uart_handle *handle,u32 cmd,u32 para,void *p);

#if WIFI_BT_UART_EN
#define KEY_VALUE_PREV		0xA1
#define KEY_VALUE_PLAY  	0xA2
#define KEY_VALUE_NEXT  	0xA3
#define KEY_VALUE_VOL_DOWN  0xA4
#define KEY_VALUE_VOL_UP  	0xA5
#define KEY_VALUE_WECHAT_START  0x06
#define KEY_VALUE_WECHAT_STOP  	0x86
//#define KEY_VALUE_CHAT_START  0x07
//#define KEY_VALUE_CHAT_STOP  	0x87
#define KEY_VALUE_CHAT 			0x07
#define KEY_VALUE_WIFI_SET  	0xA9
#define KEY_VALUE_CH_2_EN  		0xAA
#define KEY_VALUE_EN_2_CH  		0xAB
#define KEY_VALUE_COLLECTION    0xAD
#define KEY_VALUE_COLL_PLAY     0xCD
#define WIFI_MODE_START		    0x0C
#define WIFI_MODE_STOP   	    0x8C
#define WIFI_LOW_POWER_WARN		0x15
#define WIFI_LOW_POWER_OFF		0x16
#define WIFI_ECHO_START			0x17
#define WIFI_ECHO_STOP			0x18
#define WIFI_DAILY_NEWS			0xCE
#endif

#endif
