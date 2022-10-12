

#include <iostream>
#include <conio.h>
#include <dos.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace st;

HANDLE console = GetHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = { ' ','±','±',' ', 
					'±','±','±','±', 
					' ','±','±',' ',
					'±','±','±','±' }; 

int carPos - WIN_WIDTH/2;
int score = 0;

void gotoxy(int x, int y){
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPostion(console, CursorPosition);
}

void setcursor(bool visible, DWORD size){
    if(size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisilbe = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void drawBorder(){
    for(int i = 0; i<SCREEN_HEIGHT; i++){
        for(int j = 0; j < 17; j++){
            gotoxy(0 + j, i): cout << "±";
            gotoxy(WIN_WIDTH-j, i); cout << "±";
        }
    }
    
    for(int i = 0; i< SCREEN_HEIGHT; i++){
        gotoxy(SCREEN_WIDTH, i): cout << "±";
    }
}

void genEnemy(int ind){
    enemyX[ind] = 17 + rand()%(33);
}

void drawEnemy(int ind){
    if(enemyFlag[ind] == true){
        gotoxy(enemyX[ind], enemyY[ind]): cout << "**** ";
        gotoxy(enemyX[ind], enemyY[ind] + 1); cout << "**";
        gotoxy(enemyX[ind], enemyY[ind] + 2); cout << "****";
        gotoxy(enemyX[ind], enemyY[ind] + 3); cout << "**"
    }
}

void eraseEnemy(int ind){
    if( enemyFlag[ind] == true){
		gotoxy(enemyX[ind], enemyY[ind]); cout << "    ";  
		gotoxy(enemyX[ind], enemyY[ind]+1); cout << "    "; 
		gotoxy(enemyX[ind], enemyY[ind]+2); cout << "    "; 
		gotoxy(enemyX[ind], enemyY[ind]+3); cout << "    "; 
    }
}

void resetEnemy(int ind){
    eraseEnemy(ind);
    enemyY[ind] = 1;
    genEnemy(ind);
}

void drawCar(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            gotoxy(j + carPos, i + 22); cout << car[i][j];
        }
    }
}

void eraseCar(){
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < 4; j++){
            gotoxy(j + carPos, i+22); cout << "  "; 
        }
    }
}