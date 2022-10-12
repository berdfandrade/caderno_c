

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

int collision(){
    if(enemyY[0] + 4 >= 23){
        if(enemyx[0] + 4 - carPos >= 0 && enemyX[0] - 4 - carPos < 9){
            return 1; 
        }
    }
    return 0;
}

// Função de gameover 
void gameover(){
	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- FIM DE JOGO -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\tAperte qualquer tecla para voltar para o menu.";
	getch();
}

void updateScore(){
    gotoxy(WIN_WIDTH + 7, 5); cout << "Pontuação:  " << score << endl; 
}

void instructions(){
    system("cls"); 
    cout << "Instruções";
    cout << "\n"
}

void instructions(){
	
	system("cls");
	cout<<"Instruções";
	cout<<"\n----------------";
	cout<<"\n Evite carros se movendo para a esquerda ou direita!";
	cout<<"\n\n Aperte 'a' para se mover apra a esquerda";
	cout<<"\n Aperte 'd' para se mover apra a direita";
	cout<<"\n Aperte 'ESC' para sair";
	cout<<"\n\nAperte qualquer tecla para voltar ao menu";
	getch();
}

void play(){
    carPos = -1 + WIN_WIDTH/2;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

	gotoxy(WIN_WIDTH + 7, 2);cout<<"Car Game";
	gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
	gotoxy(WIN_WIDTH + 6, 6);cout<<"----------";
	gotoxy(WIN_WIDTH + 7, 12);cout<<"Control ";
	gotoxy(WIN_WIDTH + 7, 13);cout<<"-------- ";
	gotoxy(WIN_WIDTH + 2, 14);cout<<" Tecla A - Esquerda";
	gotoxy(WIN_WIDTH + 2, 15);cout<<" Tecla D - Direita"; 

    gotoxy(18, 5);cout<<"Aperte qualquer tecla para começar";
	getch();
	gotoxy(18, 5);cout<<"                      ";
}