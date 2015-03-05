#include <stdlib.h>
#include <mysql/mysql.h>

MYSQL *conn;
MYSQL_ROW row;
MYSQL_RES *res;

// 正确编译方式：gcc $(mysql_config --cflags) test_mysql.c -o test_mysql $(mysql_config --libs)
// 或者：gcc test.c -o test $(mysql_config --cflags --libs)
