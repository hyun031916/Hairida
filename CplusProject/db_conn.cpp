#include <stdlib.h>
#include <iostream>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

using namespace std;
int main(void)
{

	sql::Driver* driver;
	
	sql::Connection* con;

	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3307", "root", "1111");
	con->setSchema("python");

	//delete con;

	cout << endl;

	return EXIT_SUCCESS;
	//MYSQL Conn;	//Mysql 정보 담을 구조체
	//MYSQL* ConnPtr = NULL;	//핸들
	//MYSQL_RES* Result;	//쿼리 성공시 결과 담는 구조체 포인터
	//MYSQL_ROW Row;	//행의 정보를 담는 구조체
	//int Stat;

	//mysql_init(&Conn);	//Mysql 정보 초기화
	//
	////데이터베이스와 연결
	//ConnPtr = mysql_real_connect(&Conn, "127.0.0.1", "root", "1111", "cplus", 3307, (char*)NULL, 0);

	////연결 결과 확인, NULL일 경우 연결 실패한 것
	//if (ConnPtr == NULL) {
	//	fprintf(stderr, "Mysql connection error : %s", mysql_error(&Conn));
	//	return 1;
	//}

	//mysql_close(ConnPtr);

	//char *Query = "SELECT * FROM hairida_info";
	//Stat = mysql_query(ConnPtr, Query);
	//if (Stat != 0)
	//{
	//	fprintf(stderr, "Mysql query error : %s", mysql_error(&Conn));
	//	return 1;
	//}

	//Result = mysql_store_result(ConnPtr);
	//while ((Row = mysql_fetch_row(Result)) != NULL)
	//{
	//	printf("%s %s %s ", Row[0], Row[1], Row[2]);
	//}
	//mysql_free_result(Result);

}

