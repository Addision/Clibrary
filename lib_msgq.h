/*
 * Filename: lib_msgq.h
 *                
 * Version:       0.1
 * Author:        LaiJia <laijia2008@126.com>
 * Created at:    Sun Nov  9 22:55:44 2014
 *                
 * Description:   
 *
 */


#ifndef _LIB_MSGQ_H
#define _LIB_MSGQ_H

#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>

#define LEN 256
struct msg_s
{
	long int mytype;
	char msgtext[LEN];
};
//function spacefied
//flag 默认为 IPC_CREAT | 0666
int lib_msgq_init(char *filename, int id, int msgflag);
int lib_msgq_send(int msgid, const void *msgp, size_t msgsz, int msgflg);
int lib_msgq_rcv(int msqid, void *msgp, size_t msgsz, long msgtyp,int msgflg);
int lib_msgq_free(int msqid);
int lib_msgq_stat(int msqid,  struct msqid_ds *info);
#endif
