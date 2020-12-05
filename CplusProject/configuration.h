#include <iostream>
#include <Windows.h>
#include <conio.h>
#include<fstream>
#include<string>

using namespace std;

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

//선택(스페이스바)
#define SUBMIT 4
#ifndef configuration_h
#define configuration_h

enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

class ColorChange {
public:
	void textcolor(int foreground, int background);
};
class Hairida : public ColorChange{
public:
	void textcolor(int foreground, int background);
	void init();
	void titleDraw();
	void gotoxy(int x, int y);
	int keyControl();
	int menuDraw();
	void infoDraw();
	int maplistDraw();
	int maplistDraw2();
	int maplistDraw3();
	void hairStyle(int n);
};
#endif /* configuration_h */