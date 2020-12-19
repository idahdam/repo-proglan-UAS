#include "Header.h"

/*Ask user to exit or go back*/
void areYouSure(){
    int pos = 1;
    int kpress = 0;
	int i;
	int j;
    while(kpress !=13){
    system("cls");
    background();
    
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
	gotoxy(q,p);
	
	for ( i= 0 ; i <64 ; i++){
    	printf("=");
	}
	q = 30;
	p = 18;   
	gotoxy(q,p);
	printf("Are you sure?\n");
    gotoxy(q,p+2);
	printf("\n");
    gotoxy(q,p+4);
    arrow(1,pos);
	printf("No\n");
    gotoxy(q,p+6);
    arrow(2,pos);
	printf("Yes\n");
        
                                                       
    kpress = getch();

    if (kpress== 80 && pos != MAX_POS_EXIT){
        pos++;
    }
    else if (kpress== 72 && pos != MIN_POS_EXIT){
        pos--;
    }
    else if(kpress == 80 && pos == MAX_POS_EXIT){
    	pos = MIN_POS_EXIT;
	}
    else if(kpress == 72 && pos == MIN_POS_EXIT){
    	pos = MAX_POS_EXIT;
	}
    else{
        pos = pos;
    }

    }
    switch (pos){
    case 1:
        system("cls");
		menu();
        break;
    case 2:
        gotoxy(20, 30); printf("nice to see you here. press enter to exit");
        getch(), system("cls"), exit(0);
        break;
	}
    gotoxy(32,38);
    printf("copyright hadi & jo\n");
}
