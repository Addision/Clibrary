#include <stdio.h>
#include <string.h>
#include "lib_log.h"

static FILE *fp;

void my_log(int severity, const char *msg)
{
	const char *s;
	
	if(fp == NULL)
		return;
	switch (severity) {
	case LOG_DEBUG: s = "debug"; break;
	case LOG_MSG:   s = "msg";   break;
	case LOG_WARN:  s = "warn";  break;
	case LOG_ERR:   s = "error"; break;
	default:               s = "?";     break; /* never reached */
    }
	fprintf(fp, "[%s] %s\n", s, msg);
   
}
void set_callback_log(const char *path)
{
	fp = fopen(path,"a+");
	log_set_cb(my_log);
}

int main()
{
	
	char *path = "/home/ubuntu/test/haha.log";
	set_callback_log(path);
	log_errx(LOG_ERR,"[%s]haha","xixi");
	return 0;
}


