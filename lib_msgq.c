#include "lib_msgq.h"

/********************************* 
* Function Name:
* Function description:
* Author: jensonhjt 
* Input parameter: 
*   filename : file path
    id : 1
    flag : IPC_CREAT|0660
* Return value: 
*
**********************************/
int lib_msgq_init(char *filename, int id, int msgflag)
{
	int ret = 0;
	ret = msgget(ftok(filename, id), msgflag);
	
	return ret;	
}
/********************************* 
* Function Name:
* Function description:
* Author: jensonhjt 
* Input parameter: 
*   msgqid : 
* Return value: 
*
**********************************/
int lib_msgq_send(int msgid, const void *msgp, size_t msgsz, int msgflg)
{
	int ret = 0;
	ret = msgsnd(msgid, msgp, msgsz,  msgflg);
	return ret;
}

int lib_msgq_rcv(int msqid, void *msgp, size_t msgsz, long msgtyp,int msgflg)
{
	int ret = 0;
	ret = msgrcv(msqid, msgp, msgsz, msgtyp, msgflg);
	return ret;
}

int lib_msgq_free(int msqid)
{
	int ret = 0;
	struct msqid_ds buf;
	ret = msgctl(msqid, IPC_RMID, &buf);

	return ret;
}

int lib_msgq_stat(int msqid,  struct msqid_ds *info)
{
	int ret = 0;
	ret = msgctl(msqid, IPC_STAT, info);
	return ret;
}

int lib_msgq_exist(int msqid)
{
	int ret = msgget(msqid, IPC_EXCL);
	return ret;
}
