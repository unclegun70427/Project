#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>

void gotoXY(int,int);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int x, int y){

	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);

}
