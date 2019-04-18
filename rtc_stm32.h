/*
 * rtc.h
 *
 *  Created on: 27 Feb 2019
 *      Author: Stefan Jaritz
 */

#ifndef DRV_RTC_STM32_H_
#define DRV_RTC_STM32_H_

#include <zephyr/types.h>

#define RTC_NAME "STM32_RTC"

typedef struct rtc_time {
	u8_t hours;
	u8_t minutes;
	u8_t seconds;
} rtc_time_t;

typedef struct rtc_date {
	u8_t day;
	u8_t weekday;
	u8_t month;
	u8_t year;
} rtc_date_t;

typedef struct rtc_raw_ts {
	u32_t d;
	u32_t t;
	u16_t ss;
} rtc_raw_ts_t;

typedef struct rtc_ts {
	rtc_date_t d;
	rtc_time_t t;
	unsigned int ms;
} rtc_ts_t;

rtc_ts_t rtc_ts_fromRaw(rtc_raw_ts_t * ts);
void rtc_setTime (rtc_ts_t st);
void rtc_getTimestamp (rtc_raw_ts_t * ts);

typedef struct rtc_api_s {
	void (* getTimestamp) (rtc_raw_ts_t * ts);
	void (* setTime) (rtc_ts_t st);
} rtc_api_t;



#endif /* DRV_RTC_STM32_H_ */
