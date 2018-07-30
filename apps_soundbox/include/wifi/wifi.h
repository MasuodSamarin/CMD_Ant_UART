#ifndef WIFI_TASK_H
#define WIFI_TASK_H

#include "includes.h"

#define WIFI_DEBUG
#ifdef WIFI_DEBUG
    #define wifi_puts     puts
    #define wifi_printf   printf
#else
    #define wifi_puts(...)
    #define wifi_printf(...)
#endif

#define WIFI_TASK_NAME   "WiFiTask"

extern const struct task_info wifi_task_info;

typedef enum __WIFI_MODE
{
	WIFI_MODE_CH_2_EN = 0x0,
	WIFI_MODE_EN_2_CH,
		
}WIFI_MODE;

#endif

