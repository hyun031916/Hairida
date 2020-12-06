#include "configuration.h"

void ColorChange::textcolor(int foreground, int background) {

}
void Hairida::textcolor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


//�ܼ��� ���� ���� ����
void Hairida::init() {
	system("mode con cols=100 lines=50 | title Hairida you");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;	//false �Ǵ� 0 : �����
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}


void Hairida::titleDraw() {
	textcolor(DARKGRAY, BLACK);
	cout << "\n\n\n" << endl;
	cout << "   #   #      #      #####    ####     #####    ####        #" << endl;
	cout << "   #   #     #  #      #      #   #      #      #   #      # #" << endl;
	cout << "   #####    #####      #      ####       #      #    #    #####" << endl;
	cout << "   #   #    #   #      #      #  #       #      #   #     #   #" << endl;
	cout << "   #   #    #   #    #####    #   #    #####    ####      #   #" << endl;
	cout << "\n\n" << endl;
	cout << "              #     #      #####     #     #      " << endl;
	cout << "               #   #      #     #    #     #         " << endl;
	cout << "                 #        #     #    #     #      " << endl;
	cout << "                 #        #     #    #     #          " << endl;
	cout << "                 #         #####      #####        " << endl;

	textcolor(RED, BLACK);
}

//���콺 Ŀ���� ��ġ �̵� �Լ� ����
void Hairida ::gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//�ܼ� �ڵ� ��������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int Hairida::keyControl() {
	int i = _getch();
	if (i == 224) {
		i = _getch();
		switch (i) {
		case 72: return UP;		//���� ȭ��ǥ ������ ��
		case 80: return DOWN;	//�Ʒ��� ȭ��ǥ
		case 75: return LEFT;	//���� ȭ��ǥ
		case 77: return RIGHT;	//������ ȭ��ǥ
		}
	}
	else if (i == 32)
	{
		return SUBMIT;	//�����̽��� ����
	}
}

//���� �޴� �����ϱ�
int Hairida::menuDraw() {
	int x = 24, y = 18;
	gotoxy(x - 2, y);
	printf("> �� �� �� ��");
	gotoxy(x, y + 1);
	printf("�� �� �� ��");
	gotoxy(x, y + 2);
	printf("�� �� �� ��");

	while (1) {
		int n = keyControl();	//Ű���� �̺�Ʈ�� Ű ������ �޾ƿ���
		switch (n) {
		case UP: {	// �Էµ� Ű�� ���� UP�� ���
			if (y > 18) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}break;
		}
		case DOWN: {	//�Էµ� Ű�� ���� DOWN�� ���
			if (y < 20) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}break;
		}
		case SUBMIT: {	//�Էµ� Ű�� ���� �����̽����� ���
			return y - 18;

		}
		}
	}
}

//���� ����
void Hairida::infoDraw() {
	system("cls");
	printf("\n\n\n");
	printf("                         [���۹�]\n\n\n");
	printf("                         �̵� : ȭ��ǥ(�����¿�)\n\n\n\n\n\n\n");
	printf("                         ���� : �����̽��� \n\n\n\n\n\n\n");
	printf("                         [����] \n\n\n");
	printf("                         ������ : �����");
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

//�� ����
int Hairida::maplistDraw()
{
	string hairlength;
	int x = 32;
	int y = 10;
	system("cls");
	cout << endl << endl;
	cout << "                             [����� ����]" << endl << endl;
	cout << "                   ���α׷��� �̿��ϱ� ���ؼ��� ������� \n                   ������ �ʿ��մϴ� �������ּ���!" << endl << endl << endl;
	cout << "                               <�Ӹ�����>" << endl;

	gotoxy(x - 2, y);
	cout << "> ª�� �Ӹ�" << endl;
	gotoxy(x, y + 1);
	cout << "�ܹ� �Ӹ�" << endl;
	gotoxy(x, y + 2);
	cout << "�� �Ӹ�" << endl;
	gotoxy(x, y + 3);
	cout << "�ڷ�" << endl;

	while (1) {
		int n = keyControl();	//Ű���� �̺�Ʈ Ű������ �ޱ�
		switch (n) {
		case UP: {	//�Էµ� Ű�� ���� UP�� ���
			if (y > 10) {	//y�� 10-14���� �̵�
				gotoxy(x - 2, y);	//x-2�� ">"�� ��ĭ ������ ����ϱ� ����
				cout << " ";	//���� ��ġ �����
				gotoxy(x - 2, --y);	//���� �̵��� ��ġ�� �̵�
				cout << ">";	//�ٽ� �׸���
			}
			break;
		}case DOWN: {
			if (y < 13) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			if (y == 10) {
				hairlength = "ª�� �Ӹ�";
			}
			else if (y == 11) {
				hairlength = "�ܹ� �Ӹ�";
			}
			else if (y == 12) {
				hairlength = "�� �Ӹ�";
			}
			ofstream writeFile;
			writeFile.open("hairlength.txt");
			if (writeFile.is_open()) {
				writeFile << hairlength;
			}
			return y - 10;	//�����̽���(����)�Ǿ��� ��� y-6
		}
		}
	}
}

int Hairida::maplistDraw2()
{
	string hairstyle;
	int x = 32;
	int y = 10;
	system("cls");
	cout << endl << endl;
	cout << "                             [����� ����]" << endl << endl;
	cout << "                   ���α׷��� �̿��ϱ� ���ؼ��� ������� \n                   ������ �ʿ��մϴ� �������ּ���!" << endl << endl << endl;
	cout << "                               <�Ӹ� ����>" << endl;

	gotoxy(x - 2, y);
	cout << "> ���Ӹ�" << endl;
	gotoxy(x, y + 1);
	cout << "�����Ӹ�" << endl;
	gotoxy(x, y + 2);
	cout << "�ڷ�" << endl;
	while (1) {
		int n = keyControl();	//Ű���� �̺�Ʈ Ű������ �ޱ�
		switch (n) {
		case UP: {	//�Էµ� Ű�� ���� UP�� ���
			if (y > 10) {	//y�� 10-14���� �̵�
				gotoxy(x - 2, y);	//x-2�� ">"�� ��ĭ ������ ����ϱ� ����
				cout << " ";	//���� ��ġ �����
				gotoxy(x - 2, --y);	//���� �̵��� ��ġ�� �̵�
				cout << ">";	//�ٽ� �׸���
			}
			break;
		}case DOWN: {
			if (y < 12){
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			if (y == 10) {
				hairstyle = "|";
			}
			else if (y == 11) {
				hairstyle = "$";
			}
			ofstream writeFile;
			writeFile.open("hairstyle.txt");
			if (writeFile.is_open()) {
				writeFile << hairstyle;
			}
			return y - 10;	//�����̽���(����)�Ǿ��� ��� y-6
		}
		}
	}
}

int Hairida::maplistDraw3()
{
	int x = 32;
	int y = 10;
	system("cls");
	cout << endl << endl;
	cout << "                             [����� ����]" << endl << endl;
	cout << "                   ����� ������ �ԷµǾ����. \n                   �غ� �Ǿ�����? ���� �Ӹ��� �ٲپ�����ؿ�.\n                  ���ϴ� �Ӹ� ������ �����ϼ���." << endl << endl << endl;
	cout << "                               <�Ӹ� ����>" << endl;

	string color = "";
	textcolor(WHITE, BLACK);
	gotoxy(x - 2, y);
	cout << "> �Ͼ��" << endl;

	textcolor(YELLOW, BLACK);
	gotoxy(x, y + 1);
	cout << "�����" << endl;

	textcolor(RED, BLACK);
	gotoxy(x, y + 2);
	cout << "������" << endl;


	textcolor(BLUE, BLACK);
	gotoxy(x, y + 3);
	cout << "�Ķ���" << endl;


	textcolor(MAGENTA, BLACK);
	gotoxy(x, y + 4);
	cout << "�����" << endl;

	textcolor(WHITE, BLACK);
	gotoxy(x, y + 5);
	cout << "�ڷ�" << endl;

	

	while (1) {
		int n = keyControl();	//Ű���� �̺�Ʈ Ű������ �ޱ�
		switch (n) {
		case UP: {	//�Էµ� Ű�� ���� UP�� ���
			if (y > 10) {	//y�� 10-14���� �̵�
				gotoxy(x - 2, y);	//x-2�� ">"�� ��ĭ ������ ����ϱ� ����
				cout << " ";	//���� ��ġ �����
				gotoxy(x - 2, --y);	//���� �̵��� ��ġ�� �̵�
				cout << ">";	//�ٽ� �׸���
			}
			break;
		}case DOWN: {
			if (y < 15) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			if (y == 10) {
				color = "WHITE";
			}
			else if (y == 11) {
				color = "YELLOW";
			}
			else if (y == 12) {
				color = "RED";
			}
			else if (y == 13) {
				color = "BLUE";
			}
			else if (y == 14) {
				color = "MAGENTA";
			}
			ofstream writeFile;
			writeFile.open("haircolor.txt");
			if (writeFile.is_open()) {
				writeFile << color;
			}
			
			return y - 10;	//�����̽���(����)�Ǿ��� ��� y-6
		}
		}
	}
}

void Hairida::hairStyle(int n) {
	switch (n) {
	case 0:
		cout << "ª�� �Ӹ� ����" << endl<<endl<<endl;
		cout << "          &&&&&&&&&&&&&" << endl;
		cout << "      &&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;

	case 1:
		cout << "�ܹ� �Ӹ� ����" << endl << endl << endl;
		cout << "          &&&&&&&&&&&&&" << endl;
		cout << "      &&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;
	case 2:
		cout << "�� �Ӹ� ����" << endl << endl << endl;
		cout << "          &&&&&&&&&&&&&" << endl;
		cout << "      &&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;
	}
}





int main()
{
	Hairida h1;
	h1.textcolor(RED, BLACK);
	h1.init();
	while (1) {
		h1.titleDraw();
		int menuCode = h1.menuDraw();
		if (menuCode == 0) {
			//���ӽ���
			int n1 = h1.maplistDraw();

			int n2 = h1.maplistDraw2();

			int n3 = h1.maplistDraw3();
			if (n3 == 0) {
			}
			string in_line;
			ifstream in("hairstyle.txt");
			while (getline(in, in_line)) {
				string n = in_line;
				printf("%s %s %s", n, n, n);
			}
			in.close();
			Sleep(10000);
			/*else if (n1 == 1) {
				cout << "�ܹ� �Ӹ� ������";
				Sleep(1000);
			}
			else if (n1 == 2) {
				cout << "�� �Ӹ� ������";
				Sleep(1000);
			}*/
		}
		else if (menuCode == 1) {
			//���� ����
			h1.infoDraw();
		}
		else if (menuCode == 2) {
			//����
			return 0;
		}
		system("cls");
	}
	
	return 0;
}