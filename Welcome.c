#include "Header.h"

COORD setCoord={};
void gotoxy(int x , int y){
    setCoord.X=x;
    setCoord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), setCoord);
}

void background(){
	
    system("color 68");
    int x = 0;
    int y= 0 ;
    // print border
    gotoxy(x,y);
    int i,j;
		for ( i= 0 ; i <80 ; i++){
    printf("=");
	}
	printf("\n");y++;
	for ( j =0 ; j < 39 ; j++ ){
	gotoxy(x,y);
		for ( i= 0 ; i <80 ; i++){
			if (i==0){
				printf("%c",186);
			}
		}
		y++;
	}	
		x = 79;
		y = 1 ;
	for ( j =0 ; j < 39 ; j++ ){
	gotoxy(x,y);
		for ( i= 0 ; i <80 ; i++){
			if (i == 79){
					printf("%c\n",186);
			}
		}
		y++;
	}
	x = 0;
	gotoxy(x,y);
	for ( i= 0 ; i <80 ; i++){
    printf("=");
	}
	gotoxy(30,38);
    printf("copyright hadi & jo\n");
}

void loading(){
	
    int r;
    int q;
    
    gotoxy(28,18);
    printf("loading game please wait\n");
    gotoxy(28,19);
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
	int i;
	int j;
    while(kpress !=13){
    system("cls");
    background();
    
    // display title
	int p=1;
	int q = 12;
	gotoxy(q,p);printf("     _______..__   __.      ___       __  ___  _______ ");
	gotoxy(q,p+1);printf("    /       ||  \\ |  |     /   \\     |  |/  / |   ____|");
	gotoxy(q,p+2);printf("   |   (----`|   \\|  |    /  ^  \\    |  '  /  |  |__   ");
	gotoxy(q,p+3);printf("    \\   \\    |  . `  |   /  /_\\  \\   |    <   |   __|  ");
	gotoxy(q,p+4);printf(".----)   |   |  |\\   |  /  _____  \\  |  .  \\  |  |____ ");
	gotoxy(q,p+5);printf("|_______/    |__| \\__| /__/     \\__\\ |__|\\__\\ |_______|");
                                                       
	gotoxy(q,p+7);printf("        _______      ___      .___  ___.  _______      ");   
	gotoxy(q,p+8);printf("       /  _____|    /   \\     |   \\/   | |   ____|     ");   
	gotoxy(q,p+9);printf("      |  |  __     /  ^  \\    |  \\  /  | |  |__        ");  
	gotoxy(q,p+10);printf("      |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|       ");  
	gotoxy(q,p+11);printf("      |  |__| |  /  _____  \\  |  |  |  | |  |____     ");   
	gotoxy(q,p+12);printf("       \\______| /__/     \\__\\ |__|  |__| |_______|    ");  
	
	
	// display smaller table
	q = 8 ;
	gotoxy(q,p+15);for ( i= 0 ; i <64 ; i++){
    printf("=");
	}
	printf("\n");
	for ( j =0 ; j < 10 ; j++ ){
	gotoxy(q,p+16);
		for ( i= 0 ; i <64 ; i++){
			if (i==0){
				printf("%c",186);
			}
			else if (i == 63){
					printf("%c",186);
			}
			else{
				printf(" ");
			}
		}
		p++;
	}
	
	// display menu option
	p= 26;
	gotoxy(q,p);for ( i= 0 ; i <64 ; i++){
    printf("=");
	}
	q = 30;
	p = 18;   
	gotoxy(q,p);
    arrow(1,pos);printf("PLAY\n");
    gotoxy(q,p+2);
    arrow(2,pos);printf("how to play\n");
    gotoxy(q,p+4);
    arrow(3,pos);printf("high score\n");
    gotoxy(q,p+6);
    arrow(4,pos);printf("EXIT\n");
    
    //display snake
    p = 28;
    q = 20;
	gotoxy(q,p);printf("   _________         _________");p++;
	gotoxy(q,p);printf("  /         \\       /         \\");p++;
	gotoxy(q,p);printf(" /  /~~~~~\\  \\     /  /~~~~~\\  \\");p++;
	gotoxy(q,p);printf(" |  |     |  |     |  |     |  |         /");p++;
	gotoxy(q,p);printf(" |  |     |  |     |  |     |  |       //");p++;
	gotoxy(q,p);printf("(o  o)    \\  \\_____/  /     \\  \\_____/ /");p++;
	gotoxy(q,p);printf(" \\__/      \\         /       \\        /");p++;
	gotoxy(q,p);printf("  |         ~~~~~~~~~         ~~~~~~~~");p++;
	gotoxy(q,p);printf("  ^");p++;
    
                                                       
    kpress = getch();

    if (kpress== 80 && pos != MAX_POS){
        pos++;
    }
    else if (kpress== 72 && pos != MIN_POS){
        pos--;
    }
    else if(kpress == 80 && pos == MAX_POS){
    	pos = MIN_POS;
	}
    else if(kpress == 72 && pos == MIN_POS){
    	pos = MAX_POS;
	}
    else{
        pos = pos;
    }

    }
    switch (pos){
    case 1:
        system("cls");
//        printf("play selecet");
		startFunction();
		printLose();
        //break;
    case 2:
        system("cls");
        about();
        break;
    case 3:
        system("cls");
//        printf("highscore selected");
		showScore();
        break;
    case 4:
    	system("cls");
//    	printf("exit selected");
		areYouSure();
        return;
        break;
    }

}

void mainFunction() {
system("cls");
background();
HANDLE wHnd;    // Handle to write to the console.
wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTitle("Snake Game Project 1.0.0");
SMALL_RECT windowSize = {0, 0, MAIN_BORDER_RIGHT+10, MAIN_BORDER_BOTTOM+10};
SetConsoleWindowInfo(wHnd, 1, &windowSize);
	loading();
	menu();
    getch();
    return;
}


