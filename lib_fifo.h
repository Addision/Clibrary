#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

// open(const char *path, O_RDONLY);//1  
// open(const char *path, O_RDONLY | O_NONBLOCK);//2  
// open(const char *path, O_WRONLY);//3  
// open(const char *path, O_WRONLY | O_NONBLOCK);//4  
int lib_fifo_init(const char *fifoname);
int lib_fifo_read(char *readbuf, const char *fifoname, int bufsize,int mode);
int lib_fifo_write(char *writebuf, const char *fifoname, int mode);
int lib_fifo_delete(const char *fifoname);
