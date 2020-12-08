#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define YELLOW_BG "\x1B[48;2;176;184;63m"
#define GRAY_TEXT "\x1B[38;2;80;80;80m"

void background(){
    system("color 68");
}
COORD setCoord={};
void gotoxy(int x , int y){
    setCoord.X=x;
    setCoord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),setCoord);
}

void loading(){
    int r;
    int q;
    printf("===================================================");
    gotoxy(10,5);
    printf("loading game please wait\n");
    gotoxy(10,7);
    for(r=1;r<=23;r++){
        for(q=0;q<=50000000;q++);//to display the character slowly
            printf("%c",221);
            }
}

void menu(){
    system("cls");
    printf("===================================================");
    gotoxy(20,2);
    printf("snake game\n");
    printf("===================================================");
    gotoxy(20,5);
    printf("play\n");
    gotoxy(20,7);
    printf("how to play\n");
    gotoxy(20,9);
    printf("high score\n");
    printf("===================================================");
}

int main() {
system("cls");
background();
HANDLE wHnd;    // Handle to write to the console.
wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTitle("snake game project");
SMALL_RECT windowSize = {0, 0, 70, 20};
SetConsoleWindowInfo(wHnd, 1, &windowSize);
    loading();
    menu();
    getch();
    return 0;
}


