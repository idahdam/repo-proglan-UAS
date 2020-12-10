#include "Header.h"

struct Score{
	char inisial[3];
	int data;
	int key;
	struct Score *next;
};

struct Score *head = NULL;
struct Score *current = NULL;

int number;


//
//void sort(){
//
//   int i, j, k, tempKey, tempData;
//   struct Score *current;
//   struct Score *next;
//	
//   int size = length();
//   k = size ;
//	
//   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
//      current = head;
//      next = head->next;
//		
//      for ( j = 1 ; j < k ; j++ ) {   
//
//         if ( current->data > next->data ) {
//            tempData = current->data;
//            current->data = next->data;
//            next->data = tempData;
//
//            tempKey = current->key;
//            current->key = next->key;
//            next->key = tempKey;
//         }
//			
//         current = current->next;
//         next = next->next;
//      }
//   }   
//}

void enterScore(int score){
    FILE *fp;
    char nama[3];
    system("cls");
    system("COLOR 8f");
    fp = fopen("savefile.txt", "a");
    printf("\t\t\t");
    printf("=====================================================\n");
    printf("\n\t\t\tMasukkan 3 huruf inisialmu: ");
    scanf("%s", &nama);
//    fprintf(fp, "%s \t %d \t %d:%d\n", nama, score, minutes, seconds);
	fclose(fp);
}

void showScore(){
    FILE *fp;
    char str[MAXCHAR];
    char filename[] = "savefile.txt";
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
    	printf("\t\t\t--Last\t Name \t Move \t Minutes:Seconds--\n\n");
	}
	printf("\t\t\t========================================\n");
    while (fgets(str, MAXCHAR, fp) != NULL){
		printf("\t\t\t-- \t %s",  str);
        number++;
        if(number == 11){
        	break;
		}
	}

    fclose(fp);
    printf("\n\n\t\t\tEnter to go to main.");
    getch();
    menu();
}
