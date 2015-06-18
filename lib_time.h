#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/timeb.h>
#include <string.h>

time_t lib_time_start();

time_t lib_time_end();

double lib_time_diff(time_t ti_a, time_t ti_b);

char* lib_time_now(char *outtime, int flag);

char* lib_time_datespan(char* outday, char *inday, int span, char separator/*=-*/);

int lib_time_getCurrentYear();

int lib_time_getCurrentMon();

int lib_time_getCurrentDay();









