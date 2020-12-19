#include "Header.h"

struct node{
	char* data;
	struct node *next;
}typedef node;

node *head = NULL, *tmp = NULL, *itr = NULL, *prev = NULL;
int number, i, line = 0, toggle = 1;

void quotebox(){
    int x = 15 ;
    int y = 17;
    // print border
    gotoxy(x,y);
    int i,j;
		for ( i= 0 ; i <50 ; i++){
    printf("=");
	}
	printf("\n");y++;
	for ( j =0 ; j < 7 ; j++ ){
	gotoxy(x,y);
		for ( i= 0 ; i <50 ; i++){
			if (i==0){
				printf("%c",186);
			}
		}
		y++;
	}
		x = 64;
		y = 18 ;
	for ( j =0 ; j < 7 ; j++ ){
	gotoxy(x,y);
		for ( i= 0 ; i <50 ; i++){
			if (i == 49){
					printf("%c\n",186);
			}
		}
		y++;
	}
	x = 15;
	gotoxy(x,y);
	for ( i= 0 ; i <50 ; i++){
    printf("=");
	}
}

void printLose(){
	system("cls");
	int x,y;
	int randcount;
	x = 18;
	y = 1 ;
 	gotoxy(x,y);printf("  ____    ____  ______    __    __  ");y++;    
 	gotoxy(x,y);printf("  \\   \\  /   / /  __  \\  |  |  |  | ");y++;     
 	gotoxy(x,y);printf("   \\   \\/   / |  |  |  | |  |  |  | ");y++;      
 	gotoxy(x,y);printf("    \\_    _/  |  |  |  | |  |  |  | ");y++;      
 	gotoxy(x,y);printf("      |  |    |  `--'  | |  `--'  | ");y++;      
 	gotoxy(x,y);printf("      |__|     \\______/   \\______/  ");y+=2;      
                                          
	gotoxy(x,y);printf(" __        ______        _______. _______ ");y++; 
	gotoxy(x,y);printf("|  |      /  __  \\      /       ||   ____|");y++; 
	gotoxy(x,y);printf("|  |     |  |  |  |    |   (----`|  |__   ");y++; 
	gotoxy(x,y);printf("|  |     |  |  |  |     \\   \\    |   __|  ");y++; 
	gotoxy(x,y);printf("|  `----.|  `--'  | .----)   |   |  |____ ");y++; 
	gotoxy(x,y);printf("|_______| \\______/  |_______/    |_______|");y++; 
	x = 24;
	y = 19;
	gotoxy(x,y);printf("    message from developer :");y+=2;
	
    srand( time( NULL ) ); //seed random-number generator //
    randcount = rand()%5;
    x = 23;
	if (randcount == 1){
	gotoxy(x,y);printf("- thats okay you can try again -");y+=2;
	}
	else if (randcount == 2){
	gotoxy(x,y);printf("- keep trying and you will succeed -");y+=2;
	}
	else if (randcount == 3){
	gotoxy(x,y);printf("- smile :) you already try your best -");y+=2;
	}
	else if (randcount == 4){
	gotoxy(x,y);printf("  - thats all you've got? -");y+=2;
	}
	else if (randcount == 0){
	gotoxy(x,y);printf(" -not that good but not bad -");y+=2;
	}
	
	x = 26;
	gotoxy(x,y);printf("press any key to continue");
	
	x = 20;
    y = 28;
	gotoxy(x,y);printf("   _________         _________");y++;
	gotoxy(x,y);printf("  /         \\       /         \\");y++;
	gotoxy(x,y);printf(" /  /~~~~~\\  \\     /  /~~~~~\\  \\");y++;
	gotoxy(x,y);printf(" |  |     |  |     |  |     |  |         /");y++;
	gotoxy(x,y);printf(" |  |     |  |     |  |     |  |       //");y++;
	gotoxy(x,y);printf("(x  x)    \\  \\_____/  /     \\  \\_____/ /");y++;
	gotoxy(x,y);printf(" \\__/      \\         /       \\        /");y++;
	gotoxy(x,y);printf("   |         ~~~~~~~~~         ~~~~~~~~");y++;
	gotoxy(x,y);printf("   ^");y++;
    quotebox();
    background();
    getch();
}

void sort(){
    char *strFileName = "leaderboard.txt";
    char *strFileSummary = "leaderboard_out.txt";
    char strTempData[MAX_LEN];
    char **strData = NULL; // String List
    int i, j;
    int noOfLines = 0;

    FILE * ptrFileLog = NULL;
    FILE * ptrSummary = NULL;

    if ( (ptrFileLog = fopen(strFileName, "r")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n", strFileName);
        
    }
    if ( (ptrSummary = fopen(strFileSummary, "w")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n", strFileSummary);
    }

    // Read and store in a string list.
    while(fgets(strTempData, MAX_LEN, ptrFileLog) != NULL) {
        // Remove the trailing newline character
        if(strchr(strTempData,'\n'))
            strTempData[strlen(strTempData)-1] = '\0';
        strData = (char**)realloc(strData, sizeof(char**)*(noOfLines+1));
        strData[noOfLines] = (char*)calloc(MAX_LEN,sizeof(char));
        strcpy(strData[noOfLines], strTempData);
        noOfLines++;
    }
    // Sort the array.
    for(i= 0; i < (noOfLines - 1); ++i) {
        for(j = 0; j < ( noOfLines - i - 1); ++j) {
            if(atoi(strData[j])< atoi(strData[j+1])){
                strcpy(strTempData, strData[j]);
                strcpy(strData[j], strData[j+1]);
                strcpy(strData[j+1], strTempData);
            }
        }
    }
    // Write it to outfile. file.
    for(i = 0; i < noOfLines; i++)
        fprintf(ptrSummary,"%s\n",strData[i]);
    // free each string
    for(i = 0; i < noOfLines; i++)
        free(strData[i]);
    // free string list.
    free(strData);
    fclose(ptrFileLog);
    fclose(ptrSummary);
}

void enterScore(int score){
	int x,y;
	toggle = 0;
    FILE *fp, *fp2;
    char nama[3];
    system("cls");
    fp = fopen("leaderboard.txt", "a");
    fp2 = fopen("leaderboard_out.txt", "a");
	background();
	x = 18;
	y = 3;
    gotoxy(x,y);printf("\n\t\t\tMasukkan 3 huruf inisialmu: ");y+=3;
    x = 35;
    gotoxy(x,y);scanf("%3s", &nama);
 	fprintf(fp, "%d \t %s\n", score, nama);
	fclose(fp);
	fclose(fp2);
	toggle = 1;
}

void showScore(){
	sort();
    FILE *fp;
    char str[MAXCHAR];
    char filename[] = "leaderboard_out.txt";
    system("cls");
	number = 1;
    fp = fopen(filename, "r");
    if (fp == NULL){
        // printf("Could not open file %s", filename);
        // return 1;
	int p=1;
	int q = 12;
	int i ;
	gotoxy(q,p);printf("      __    __   __    _______  __    __  ");p++;         
    gotoxy(q,p);printf("     |  |  |  | |  |  /  _____||  |  |  | ");p++;        
    gotoxy(q,p);printf("     |  |__|  | |  | |  |  __  |  |__|  |  ");p++;        
    gotoxy(q,p);printf("     |   __   | |  | |  | |_ | |   __   | ");p++;         
    gotoxy(q,p);printf("     |  |  |  | |  | |  |__| | |  |  |  | ");p++;         
    gotoxy(q,p);printf("     |__|  |__| |__|  \\______| |__|  |__|  ");p++;        
                                                       
	gotoxy(q,p);printf("     _______.  ______   ______   .______       _______ ");p++;
	gotoxy(q,p);printf("    /       | /      | /  __  \\  |   _  \\     |   ____|");p++;
	gotoxy(q,p);printf("   |   (----`|  ,----'|  |  |  | |  |_)  |    |  |__   ");p++;
	gotoxy(q,p);printf("    \\   \\    |  |     |  |  |  | |      /     |   __|  ");p++;
	gotoxy(q,p);printf(".----)   |   |  `----.|  `--'  | |  |\\  \\----.|  |____ ");p++;
	gotoxy(q,p);printf("|_______/     \\______| \\______/  | _| `._____||_______|\n\n");
    for ( i= 0 ; i <80 ; i++){
    printf("=");
	}
	printf("\n\n");
        printf("\t\t\tScoreboard is empty.\n");
    }
    
    else{
    int p=1;
	int q = 12;
	int i ;
	gotoxy(q,p);printf("      __    __   __    _______  __    __  ");p++;         
    gotoxy(q,p);printf("     |  |  |  | |  |  /  _____||  |  |  | ");p++;        
    gotoxy(q,p);printf("     |  |__|  | |  | |  |  __  |  |__|  |  ");p++;        
    gotoxy(q,p);printf("     |   __   | |  | |  | |_ | |   __   | ");p++;         
    gotoxy(q,p);printf("     |  |  |  | |  | |  |__| | |  |  |  | ");p++;         
    gotoxy(q,p);printf("     |__|  |__| |__|  \\______| |__|  |__|  ");p++;        
                                                       
	gotoxy(q,p);printf("     _______.  ______   ______   .______       _______ ");p++;
	gotoxy(q,p);printf("    /       | /      | /  __  \\  |   _  \\     |   ____|");p++;
	gotoxy(q,p);printf("   |   (----`|  ,----'|  |  |  | |  |_)  |    |  |__   ");p++;
	gotoxy(q,p);printf("    \\   \\    |  |     |  |  |  | |      /     |   __|  ");p++;
	gotoxy(q,p);printf(".----)   |   |  `----.|  `--'  | |  |\\  \\----.|  |____ ");p++;
	gotoxy(q,p);printf("|_______/     \\______| \\______/  | _| `._____||_______|\n\n");
    for ( i= 0 ; i <80 ; i++){
    printf("=");
	}
	printf("\n\n");
    	printf("    \t\t\t--Best\t Name \t Score--\n\n");
	for ( i= 0 ; i <80 ; i++){
    printf("=");
	}
	printf("\n");
		
		line = checkLine();
		
		for(number = 1; number<=line; number++){
			
			fgets(str, MAXCHAR, fp);
				
			tmp = malloc(sizeof(struct node)); //kapling baru lagi
			(*tmp).data = str;
			(*tmp).next = NULL;
			
			if(number == 1){
				
				head = tmp;	
				printf("\n    \t\t\t--%d \t %s\m\n", number, head->data);
							
			}
			
			else if(number <= 10){
				
				itr = head;
				
					while(1){
						if((*itr).next == NULL){
							(*itr).next = tmp;
							break;
						}
						else{
							itr = (*itr).next;
						}
					}		
							
				printf("\t\t\t--%d \t %s\n", number, itr->data);
				
			}			
		}
	}


    fclose(fp);
	printf("\n\n\t\t\tpress Enter to go to main.");
	background();
	line == 0;
    getch();
    menu();
}

int checkLine(){
 		int trueLine = 0;
		FILE* fp = fopen("leaderboard_out.txt", "r");
		char str[MAXCHAR];
		while (fgets(str, MAXCHAR, fp) != NULL){
	        trueLine++;
	        if(line == 11){
	        	break;
			}
		}
		
		return trueLine;
}
