#include <mysql.h>
#include <my_global.h>
int main(int argc, char const *argv[]) {
  MYSQL *conn = mysql_init(NULL);

  if(!conn){
    fprintf(stderr, "%s\n", mysql_error(conn) );
    exit(1);
  }

  if( mysql_real_connect(conn, "localhost", "root", "password", NULL, 0, NULL, 0) == NULL) {
    fprintf(stderr, "Connection Error : %s\n", mysql_error(conn) );
    mysql_close(conn);
    exit(1);
  }

  if( mysql_query(conn, "create database cprogram")){
    fprintf(stderr, "Database creation failed : %s\n", mysql_error(conn) );
    mysql_close(conn);
    exit(1);
  }
  else{
    fprintf(stderr, "Query Success : Database Created \n" );
  }

  mysql_close(conn);
  exit(0);

}
