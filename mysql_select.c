#include <mysql.h>
#include <my_global.h>

int error(MYSQL *conn){
  fprintf(stderr, "Error : %s\n", mysql_error(conn) );
  mysql_close(conn);
  exit(1);
}

int main(int argc, char const *argv[]) {
  MYSQL *conn = mysql_init(NULL);

  if(!conn){
    fprintf(stderr, "%s\n", mysql_error(conn) );
    exit(1);
  }

  // We are going to use database cprogram and create the table,
  if( mysql_real_connect(conn, "localhost", "root", "password", "cprogram", 0, NULL, 0) == NULL) {
    error(conn);
  }

  // first of all, we are going to query mysql with select query.
  if(mysql_query(conn, "select * from test")){
    error(conn);
  }

  // we are storing the result in the res structure.
  MYSQL_RES *res  = mysql_store_result(conn);

  // mysql_num_fields will calculate the number of rows.
  int columns = mysql_num_fields(res);

  // now we are declaring the MYSQL_ROW structure.
  MYSQL_ROW row;
  int i;

  while(row = (mysql_fetch_row(res))){
    for(i=0; i<columns; i++){
      printf("%s ", row[i] );
    }
    printf("\n" );
  }

  mysql_free_result(res);
  mysql_close(conn);
  exit(0);

}
