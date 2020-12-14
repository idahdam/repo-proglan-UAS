#include "Header.h"

struct node{
	char* data;
	struct node *next;
}typedef node;

node *head = NULL, *tmp = NULL, *itr = NULL, *prev = NULL;
int number, i, line = 0, toggle = 1;


void printLose(){
    int n=0;
    int a=0;
    for(n=1 ; n <= 7 ; n++){
    a= n ;
    if (a == 1) {
	    system("cls");
	    system("COLOR 8C");
	    printf("\n\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000         00000         0000           00000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000  00000000000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000  00000000000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000         0000           00000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  000000000000  0000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  000000000000  0000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000          00000         000000        0000           00000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");
	    Sleep(100);
	}
    if (a == 2) {
		system("cls");
		system("COLOR 8C");
		printf("\n\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
		printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");
		Sleep(100);
	}
    if (a == 3) {
	    system("cls");
	    system("COLOR 8C");
	    printf("\n\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000         00000         0000           00000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000  00000000000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000  00000000000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000         0000           00000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  000000000000  0000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  000000000000  0000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000          00000         000000        0000           00000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");
	    Sleep(100);
	}
    if (a == 4) {
	    system("cls");
	    system("COLOR 8C");
	    printf("\n\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");
	    Sleep(100);
	}
    if (a == 5) {
	    system("cls");
	    system("COLOR 8C");
	    printf("\n\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000         00000         0000           00000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000  00000000000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000  00000000000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000         0000           00000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  000000000000  0000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  000000000000  0000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000          00000         000000        0000           00000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");
	    Sleep(100);
		}
    if (a == 6) {
	    system("cls");
	    system("COLOR 84");
	    printf("\n\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");
	    Sleep(100);
	}
    if (a == 7) {
	    system("cls");
	    system("COLOR 8C");
	    printf("\n\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000         00000         0000           00000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000  00000000000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000  00000000000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  00000         0000           00000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  000000000000  0000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000   000000000000  00000  000000000000  0000  00000000000000000000\n");printf("\t\t\t");
	    printf("00000000000          00000         000000        0000           00000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");printf("\t\t\t");
	    printf("000000000000000000000000000000000000000000000000000000000000000000000000000\n");
	    Sleep(2000);
	    system("cls");
	    }
    }
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
            if(strcmp(strData[j], strData[j+1]) < 0) {
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
	toggle = 0;
    FILE *fp, *fp2;
    char nama[3];
    system("cls");
    system("COLOR 8f");
    fp = fopen("leaderboard.txt", "a");
    fp2 = fopen("leaderboard_out.txt", "a");
    printf("\t\t\t");
    printf("=====================================================\n");
    printf("\n\t\t\tMasukkan 3 huruf inisialmu: ");
    scanf("%3s", &nama);
 	fprintf(fp, "%d \t %s\n", score, nama);
 	showScore();
	fclose(fp);
	fclose(fp2);
	toggle = 1;
}

void showScore(){
    FILE *fp;
    char str[MAXCHAR];
    sort();
    char filename[] = "leaderboard_out.txt";
    system("cls");
	number = 1;
    fp = fopen(filename, "r");
    if (fp == NULL){
        // printf("Could not open file %s", filename);
        // return 1;
    	printf("\t\t\t========================================\n");
    	printf("\t\t\t\t\tScoreBoard\t\t\n\n");
    	printf("\t\t\t========================================\n");
        printf("\t\t\tScoreboard is empty.\n");
    }
    else{
    	printf("\t\t\t========================================\n");
    	printf("\t\t\t\t\tScoreBoard\t\t\n\n");
    	printf("\t\t\t========================================\n");
    	printf("\t\t\t--Best\t Name \t Score--\n\n");
		printf("\t\t\t========================================\n");
		
		line = checkLine();

		
		for(number = 1; number<=line; number++){
			
			fgets(str, MAXCHAR, fp);
				
			tmp = malloc(sizeof(struct node)); //kapling baru lagi
			(*tmp).data = str;
			(*tmp).next = NULL;
			
			if(number == 1){
				
				head = tmp;	
				printf("\t\t\t--%d \t %s\n", number, head->data);
							
			}
			
			else{
				
				itr = head;
				
				if(toggle == 0){
					while(1){
						if((*itr).next == NULL){
							(*itr).next = tmp;
							break;
						}
						else{
							itr = (*itr).next;
						}
					}
				}

				
				printf("\t\t\t--%d \t %s\n", number, tmp->data);
			}			
		}
	
		number = 1;
	}


    fclose(fp);
	printf("\n\n\t\t\tEnter to go to main.");
    getch();
    menu();
}

int checkLine(){
		FILE* fp = fopen("leaderboard_out.txt", "r");
		char str[MAXCHAR];
		while (fgets(str, MAXCHAR, fp) != NULL){
//			printf("\t\t\t--%d \t %s\n", number,  str);
	        line++;
	        if(line == 11){
	        	break;
			}
		}
		
		return line;
}

void deleteLinkedList(){
	itr = head;
	for(number = 1; number<=line; number++){
		while(1){

			if((*itr).next == NULL){ //iteratorPtr merujuk ke node paling akhir
				free(itr);
				(*prev).next = NULL;
				break;
			}else{
				prev = itr; //alamat yg barusan dicek
				itr = (*itr).next; //alamat yg dicek berikutnya
			}
		}
	}
}
