#include "lib_fifo.h"

int lib_fifo_init(const char *fifoname)
{
	int ret = 0;
	if (NULL == fifoname || fifoname == "")
        return -1;
	if(access(fifoname, F_OK) == 0)
		return -2;
	else
        ret = mkfifo(fifoname, 0777);
	return (ret == 0) ? 0: -3;
}

int lib_fifo_read(char *readbuf, const char *fifoname, int bufsize, int mode)
{
	int readfd = -1, readsize = -1;
	int ret;
   	readfd = open(fifoname, mode);
	if(readfd < 0)
		return -1;
	readsize = read(readfd, readbuf, bufsize);
	readbuf[readsize] = '\0';
	close(readfd);
	
	return (readsize > 0) ? 0: -1;
}

int lib_fifo_write(char *writebuf, const char *fifoname, int mode)
{
	int ret = 0;
	int writesize = strlen(writebuf);
	int writefd = -1;
	writefd = open(fifoname, mode);
	if(writefd < 0)
		return -1;
	writesize = write(writefd, writebuf, writesize);
	close(writefd);
	return (writesize > 0) ? 0 : -1;
}

int lib_fifo_delete(const char *fifoname)
{
	int ret;
	if(NULL == fifoname || fifoname == "")
		return -1;
	else
		ret = remove(fifoname);
	return ret;
}
