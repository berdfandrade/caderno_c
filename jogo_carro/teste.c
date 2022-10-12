#include "conio.h"

main()
{
	int x,y;
	int tecla;
	initconio();
	textbackground(BLUE);
	clrscr();
	nocursor();
	textcolor(WHITE);
	gotoxy(10,10);
	cprintf("Teste da CONIO");
	for(y=1;y<=30;y++)
	{
	  textcolor(GREEN);
	  textbackground(BLACK);
	  gotoxy(1,y);
	  cprintf("%d",y);
	  textcolor(WHITE);
	  textbackground(BLUE);
	  for(x=1;x<=80;x++)
	  {
		  gotoxy(x+5,y);
		  cprintf(".");
	  }
	}
	do
	{
	  tecla = key();
	  gotoxy(20,20);
	  cprintf("%d  ",tecla);
	} while(tecla!='z');

	doneconio();
}

