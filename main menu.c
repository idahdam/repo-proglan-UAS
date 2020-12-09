#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

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
    printf("===================================================\n");
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("===================================================");
    gotoxy(10,5);
    printf("loading game please wait\n");
    gotoxy(10,7);
    for(r=1;r<=24;r++){
        for(q=0;q<=50000000;q++);//to display the character slowly
            printf("%c",221);
            }
}

void arrow(int ap, int rp){
    if (rp == ap){
        printf("===>  ");
    }
    else {
        printf("      ");
    }

}

void menu(){
    int pos = 1;
    int kpress = 0;
    #define max 4
    #define min 1

    while(kpress !=13){
    system("cls");
    printf("===================================================");
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    gotoxy(18,1);
    printf("Snake Game");
    gotoxy(18,2);
    printf("by hadi & jo\n");
    printf("===================================================");
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("%c                                                 %c\n",186,186);
    printf("===================================================");
    gotoxy(15,5);
    arrow(1,pos);printf("PLAY\n");
    gotoxy(15,7);
    arrow(2,pos);printf("how to play\n");
    gotoxy(15,9);
    arrow(3,pos);printf("high score\n");
    gotoxy(15,11);
    arrow(4,pos);printf("EXIT\n");
        
    kpress = getch();

    if (kpress== 80 && pos != max){
        pos++;
    }
    else if (kpress== 72 && pos != min){
        pos--;
    }
    else{
        pos = pos;
    }

    }
    switch (pos){
    case 1:
        system("cls");
        printf("play selecet");
        getch();
        menu();
        break;
    case 2:
        system("cls");
        printf("how to play selected");
        getch();
        menu();
        break;
    case 3:
        system("cls");
        printf("highscore selected");
        getch();
        menu();
        break;
    case 4:
        return 0;
        break;
    }

}

int main() {
system("cls");
background();
HANDLE wHnd;    // Handle to write to the console.
wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTitle("snake game project");
SMALL_RECT windowSize = {0, 0, 50, 20};
SetConsoleWindowInfo(wHnd, 1, &windowSize);
    loading();
    menu();
    getch();
    return 0;
}


