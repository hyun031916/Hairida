#include "configuration.h"

void ColorChange::textcolor(int foreground, int background) {

}
void Hairida::textcolor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


//콘솔의 가로 세로 제목
void Hairida::init() {
	system("mode con cols=100 lines=50 | title Hairida you");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;	//false 또는 0 : 숨기기
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

//마우스 커서의 위치 이동 함수 구현
void Hairida ::gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//콘솔 핸들 가져오기
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
		case 72: return UP;		//위쪽 화살표 눌렀을 때
		case 80: return DOWN;	//아래쪽 화살표
		case 75: return LEFT;	//왼쪽 화살표
		case 77: return RIGHT;	//오른쪽 화살표
		}
	}
	else if (i == 32)
	{
		return SUBMIT;	//스페이스바 공백
	}
}

//시작 메뉴 구현하기
int Hairida::menuDraw() {
	int x = 24, y = 18;
	gotoxy(x - 2, y);
	printf("> 시 작 하 기");
	gotoxy(x, y + 1);
	printf("설 명 보 기");
	gotoxy(x, y + 2);
	printf("종 료 하 기");

	while (1) {
		int n = keyControl();	//키보드 이벤트를 키 값으로 받아오기
		switch (n) {
		case UP: {	// 입력된 키의 값이 UP인 경우
			if (y > 18) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}break;
		}
		case DOWN: {	//입력된 키의 값이 DOWN인 경우
			if (y < 20) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}break;
		}
		case SUBMIT: {	//입력된 키의 값이 스페이스바인 경우
			return y - 18;

		}
		}
	}
}

//게임 설명
void Hairida::infoDraw() {
	system("cls");
	printf("\n\n\n");
	printf("                         [조작법]\n\n\n");
	printf("                         이동 : 화살표(상하좌우)\n\n\n\n\n\n\n");
	printf("                         선택 : 스페이스바 \n\n\n\n\n\n\n");
	printf("                         [정보] \n\n\n");
	printf("                         개발자 : 김수현");
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

//맵 구현
int Hairida::maplistDraw()
{
	int x = 32;
	int y = 10;
	system("cls");
	cout << endl << endl;
	cout << "                             [사용자 정보]" << endl << endl;
	cout << "                   프로그램을 이용하기 위해서는 사용자의 \n                   정보가 필요합니다 협조해주세요!" << endl << endl << endl;
	cout << "                               <머리길이>" << endl;

	gotoxy(x - 2, y);
	cout << "> 짧은 머리" << endl;
	gotoxy(x, y + 1);
	cout << "단발 머리" << endl;
	gotoxy(x, y + 2);
	cout << "긴 머리" << endl;
	gotoxy(x, y + 3);
	cout << "뒤로" << endl;

	while (1) {
		int n = keyControl();	//키보드 이벤트 키값으로 받기
		switch (n) {
		case UP: {	//입력된 키의 값이 UP인 경우
			if (y > 10) {	//y는 10-14까지 이동
				gotoxy(x - 2, y);	//x-2는 ">"를 두칸 이전에 출력하기 위함
				cout << " ";	//원래 위치 지우기
				gotoxy(x - 2, --y);	//새로 이동한 위치로 이동
				cout << ">";	//다시 그리기
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
			return y - 10;	//스페이스바(선택)되었을 경우 y-6
		}
		}
	}
}

int Hairida::maplistDraw2()
{
	int x = 32;
	int y = 10;
	system("cls");
	cout << endl << endl;
	cout << "                             [사용자 정보]" << endl << endl;
	cout << "                   프로그램을 이용하기 위해서는 사용자의 \n                   정보가 필요합니다 협조해주세요!" << endl << endl << endl;
	cout << "                               <머리 상태>" << endl;

	gotoxy(x - 2, y);
	cout << "> 생머리" << endl;
	gotoxy(x, y + 1);
	cout << "곱슬머리" << endl;
	gotoxy(x, y + 2);
	cout << "뒤로" << endl;

	while (1) {
		int n = keyControl();	//키보드 이벤트 키값으로 받기
		switch (n) {
		case UP: {	//입력된 키의 값이 UP인 경우
			if (y > 10) {	//y는 10-14까지 이동
				gotoxy(x - 2, y);	//x-2는 ">"를 두칸 이전에 출력하기 위함
				cout << " ";	//원래 위치 지우기
				gotoxy(x - 2, --y);	//새로 이동한 위치로 이동
				cout << ">";	//다시 그리기
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
			return y - 10;	//스페이스바(선택)되었을 경우 y-6
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
	cout << "                             [사용자 정보]" << endl << endl;
	cout << "                   사용자 정보가 입력되었어요. \n                   준비가 되었나요? 이제 머리를 바꾸어보도록해요.\n                  원하는 머리 색상을 선택하세요." << endl << endl << endl;
	cout << "                               <머리 색상>" << endl;

	string color = "";
	textcolor(WHITE, BLACK);
	gotoxy(x - 2, y);
	cout << "> 하얀색" << endl;

	textcolor(YELLOW, BLACK);
	gotoxy(x, y + 1);
	cout << "노란색" << endl;

	textcolor(RED, BLACK);
	gotoxy(x, y + 2);
	cout << "빨간색" << endl;


	textcolor(BLUE, BLACK);
	gotoxy(x, y + 3);
	cout << "파란색" << endl;


	textcolor(MAGENTA, BLACK);
	gotoxy(x, y + 4);
	cout << "보라색" << endl;

	textcolor(WHITE, BLACK);
	gotoxy(x, y + 5);
	cout << "뒤로" << endl;

	if (y == 0) {
		color = "WHITE";
	}
	else if (y == 1) {
		color = "YELLOW";
	}
	else if (y == 2) {
		color = "RED";
	}
	else if (y == 3) {
		color = "BLUE";
	}
	else if (y == 4) {
		color = "MAGENTA";
	}

	while (1) {
		int n = keyControl();	//키보드 이벤트 키값으로 받기
		switch (n) {
		case UP: {	//입력된 키의 값이 UP인 경우
			if (y > 10) {	//y는 10-14까지 이동
				gotoxy(x - 2, y);	//x-2는 ">"를 두칸 이전에 출력하기 위함
				cout << " ";	//원래 위치 지우기
				gotoxy(x - 2, --y);	//새로 이동한 위치로 이동
				cout << ">";	//다시 그리기
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
			ofstream writeFile;
			writeFile.open("hairColor.txt");
			const char* c = color.c_str();
			if (writeFile.is_open()) {
				writeFile.write(c, 10);
			}
			
			return y - 10;	//스페이스바(선택)되었을 경우 y-6
		}
		}
	}
}

void Hairida::hairStyle(int n) {
	switch (n) {
	case 0:
		cout << "짧은 머리 선택" << endl<<endl<<endl;
		cout << "          &&&&&&&&&&&&&" << endl;
		cout << "      &&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;

	case 1:
		cout << "단발 머리 선택" << endl << endl << endl;
		cout << "          &&&&&&&&&&&&&" << endl;
		cout << "      &&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&&&&&&&&&&&&&&&&&&" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;
		cout << "    &&&&&            &&&&&" << endl;
		cout << "    $$$$$            $$$$$" << endl;
	case 2:
		cout << "긴 머리 선택" << endl << endl << endl;
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
			//게임시작
			int n1 = h1.maplistDraw();

			int n2 = h1.maplistDraw2();

			int n3 = h1.maplistDraw3();
			if (n3 == 0) {
				ofstream writeFile;	//쓸 파일 선언
				writeFile.open("colorChange.txt");

				if (writeFile.is_open())
				{
					writeFile.write("0", 10);
				}
				writeFile.close();
			}
			if (n1 == 0) {
				string in_line;
				ifstream in("hairstyle.txt");
				while (getline(in, in_line)) {
					if (in_line == "곱슬머리") {
						cout << in_line;
					}
				}
				in.close();
				Sleep(1000);
			}
			else if (n1 == 1) {
				cout << "단발 머리 선택함";
				Sleep(1000);
			}
			else if (n1 == 2) {
				cout << "긴 머리 선택함";
				Sleep(1000);
			}
		}
		else if (menuCode == 1) {
			//게임 설명
			h1.infoDraw();
		}
		else if (menuCode == 2) {
			//종료
			return 0;
		}
		system("cls");
	}
	
	return 0;
}