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
	//MYSQL Conn;	//Mysql ���� ���� ����ü
	//MYSQL* ConnPtr = NULL;	//�ڵ�
	//MYSQL_RES* Result;	//���� ������ ��� ��� ����ü ������
	//MYSQL_ROW Row;	//���� ������ ��� ����ü
	//int Stat;

	//mysql_init(&Conn);	//Mysql ���� �ʱ�ȭ
	//
	////�����ͺ��̽��� ����
	//ConnPtr = mysql_real_connect(&Conn, "127.0.0.1", "root", "1111", "cplus", 3307, (char*)NULL, 0);

	////���� ��� Ȯ��, NULL�� ��� ���� ������ ��
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

