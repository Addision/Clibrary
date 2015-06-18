#include "lib_time.h"

time_t lib_time_start()
{
	time_t start = time(NULL);
	return start;
}

time_t lib_time_end()
{
	time_t end = time(NULL);
	return end;
}

double lib_time_diff(time_t ti_a, time_t ti_b)
{
	double res = 0;
	if(ti_a <=0L || ti_b <=0L)
		return -1;
	else
		res = (double)difftime(ti_a, ti_b);
	return res;
}

char* lib_time_now(char *outtime, int flag)
{
	time_t now_t;
	struct tm *now_tm;
	if(NULL == outtime)
		return NULL;
	now_t = time(NULL);
	now_tm = localtime(&now_t);

	if(0 == flag)
		strftime(outtime, 20, "%Y-%m-%d %H:%M:%S", now_tm);
	else
		strftime(outtime, 15, "%Y%m%d%H%M%S", now_tm);
	return outtime;
}

char* lib_time_datespan(char* outday, char *inday, int span, char separator/*=-*/)
{
	struct tm day;
	time_t now = time(NULL);
    memset(&day, 0, sizeof(day));
	if(sscanf(inday, "%04d-%02d-%02d", &day.tm_year, &day.tm_mon, &day.tm_mday) == 3)
	{
		day.tm_year -= 1900;
		day.tm_mon -= 1;
		now = mktime(&day);
	}
	else if(sscanf(inday, "%04d/%02d/%02d", &day.tm_year, &day.tm_mon, &day.tm_mday) == 3)
	{
		day.tm_year -= 1900;
		day.tm_mon -= 1;
		now = mktime(&day);
	}
    else if(sscanf(inday, "%04d%02d%02d", &day.tm_year, &day.tm_mon, &day.tm_mday) == 3)
	{
		day.tm_year -= 1900;
		day.tm_mon -= 1;
		now = mktime(&day);
	}
	now += span*3600*24;
	localtime_r(&now, &day);
    sprintf(outday, "%04d%c%02d%c%02d", day.tm_year + 1900, separator, day.tm_mon + 1, separator, day.tm_mday);
    return outday;
}

int lib_time_getCurrentYear()
{
	struct tm tmyear;
	time_t now = time(NULL);
	localtime_r(&now, &tmyear);
	return tmyear.tm_year+1900;
}

int lib_time_getCurrentMon()
{
	struct tm tmmon;
	time_t now = time(NULL);
	localtime_r(&now, &tmmon);
	return tmmon.tm_mon+1;	
}

int lib_time_getCurrentDay()
{
	struct tm tmday;
	time_t now = time(NULL);
	localtime_r(&now, &tmday);
	return tmday.tm_mday;
}
