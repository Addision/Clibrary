#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LEVEL_DEBUG 0
#define LEVEL_INFO  1
#define LEVEL_WARN  2
#define LEVEL_ERROR 3

static const char * log_str[] = {"DEBUG", "INFO", "WARN", "ERROR"};
const char *logpath = "/home/ubuntu/test/logfile";
#define LOG(level, format, ...) do{	\
	char msg[256];                     \
	char ti[32];					   \
	FILE *fp = fopen(logpath, "a+");   \
	time_t now = time(NULL);            \
   	sprintf(msg, format, ##__VA_ARGS__);					  \
    strftime(ti, sizeof(ti), "%Y-%m-%d %H:%M:%S", localtime(&now)); \
	fprintf(fp, "[%s] [%s] %s\n", ti, log_str[level], msg); \
    fflush(fp);   \
    fclose(fp); \
}while(0)


