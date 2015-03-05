#include "lib_mysql.h"

int lib_mysql_conn(const char *addr, const char *username, const char *passwd, const char *database)
{
	mysql_init(conn);
	if(! mysql_real_connect(conn, addr, username, passwd, database, 0,NULL,0))
	{
		return -1;
	}
}

void lib_mysql_close()
{
	if(res != NULL)
		mysql_free_result(res);
	mysql_close(conn);
}

int lib_mysql_excute(const char *sqlstr)
{
	if(mysql_real_query(conn, sqlstr))
	{
		return -1;
	}
}

int lib_mysql_res(MYSQL_RES *res)
{
	if(!(res = mysql_store_result(conn)))
	{
		return -1;
	}
}

int lib_mysql_set_character(const char *character)
{
	if(msyql_set_character_set(conn, character) < 0)
	{
		return -1;
	}
}

//mysql_autocommit(&mysql, 0);//关闭自动提交
//mysql_commit(&mysql); //提交，用于事务处理

