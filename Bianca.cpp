#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    char mat[30][30], tasto1;
    int x1=12, y1=14;

    while (true) {
        tasto1=getch();

        if(tasto1==75) x1--;
        if(tasto1==77) x1++;
        if(tasto1==79) y1--;
        if(tasto1==80) y1++;

        gotoxy(x1, y1);printf("+");
        gotoxy(x1+1, y1);printf(" ");
        gotoxy(x1-1, y1);printf(" ");
        gotoxy(x1, y1+1);printf(" ");
        gotoxy(x1, y1-1);printf(" ");

    }

    return 0;
}