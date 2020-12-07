#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

#define BARIS 25
#define KOLOM 25

#define UP 72       //             up
#define DOWN 80     //             down
#define LEFT 75     //             LEFT
#define RIGHT 77    //             right

#define MAIN_BORDER_LEFT 10
#define MAIN_BORDER_RIGHT 70
#define MAIN_BORDER_TOP 5
#define MAIN_BORDER_BOTTOM 25

COORD setCoord={};

void gotoCoord(int x, int y){
    setCoord.X=x;
    setCoord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),setCoord);
}

struct Snake{
	int posX;
	int posY;
	int direction;
} typedef Snake;

struct Food{
	int posX;
	int posY;
} typedef Food;

Snake snakeHead, snakeBody[150], turn[400]; 
Food food;

int lengthSnake = 5, lengthStart = 0, foodCounter = 0, gameLoop = true, parts = 0, a, b;

int main(){
	startFunction();
}

void drawBorder(){
	int i;
	system("cls");
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN) ;
	for(i=MAIN_BORDER_LEFT;i<=MAIN_BORDER_RIGHT;i++){
	   gotoCoord(i, MAIN_BORDER_TOP);
	   printf("%c", 221);
	
	   gotoCoord(i, MAIN_BORDER_BOTTOM);
	   printf("%c", 221);
	
	}	
	for(i=MAIN_BORDER_TOP;i<=MAIN_BORDER_BOTTOM;i++){
	   gotoCoord(MAIN_BORDER_LEFT,i);
		printf("%c", 221);
	   gotoCoord(MAIN_BORDER_RIGHT,i);
	   printf("%c", 221);
	}
	
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN) ;
	gotoCoord(food.posX, food.posY);
	printf("%c", 221);
	
	gotoCoord(MAIN_BORDER_LEFT, MAIN_BORDER_TOP-1);
	printf("Score is : %d", foodCounter-1);
}

void startFunction(){
	setStart(),	moveSnake();
}

void setStart(){
//	snakeHead.direction = RIGHT;
	lengthSnake = 15;
	parts = 0;
	foodCounter = 0;
	snakeHead.posX = 20;
	snakeHead.posY = 20;
	food.posX = 20;
	food.posY = 20;
}

void pauseEachMove(int value1, int value2){
	int k;
    if(snakeHead.direction==UP || snakeHead.direction==DOWN)
        for(k=0;k<=value1;k++);
    else
        for(k=0;k<=value2;k++);
}

void moveSnake(){
	int i, k;
	char keyPress;
	do{
		fflush(stdin);
        lengthStart=0;
        for(i=0;i<=lengthSnake;i++){
	        snakeBody[i].posX=0;
	        snakeBody[i].posY=0;
	
	        if(i==lengthSnake) break;
        }
        //system("cls");
        drawBorder();
        spawnFood();
         
        if(snakeHead.direction == RIGHT) moveSnakeRight();
        if(snakeHead.direction == LEFT) moveSnakeLeft();
        if(snakeHead.direction == UP) moveSnakeUp();
        if(snakeHead.direction == DOWN) moveSnakeDown();
        checkCollision();
        pauseEachMove(3500000, 3000000);
			 
	} while(!kbhit());
	
	keyPress = getch();
	if(keyPress==RIGHT&&snakeHead.direction!=RIGHT&&snakeHead.direction!=LEFT||keyPress==LEFT&&snakeHead.direction!=RIGHT&&snakeHead.direction!=LEFT || keyPress==UP&&snakeHead.direction!=UP&&snakeHead.direction!=DOWN || keyPress==DOWN&&snakeHead.direction!=UP&&snakeHead.direction!=DOWN){
        snakeHead.direction = keyPress;
        parts++;
        turn[parts]=snakeHead;
        for(k=0;k<=1000000;k++);
        if(keyPress==UP){
            snakeHead.posY--;
        }
        else if(keyPress==DOWN){
            snakeHead.posY++;
        }
        else if(keyPress==RIGHT){
            snakeHead.posX++;
        }
        else if(keyPress==LEFT){
            snakeHead.posX--;
        }
    }
    
	moveSnake();
}

void moveSnakeRight(){
	int i, j;
	for(i = 0; i <= snakeHead.posX - turn[parts].posX && lengthStart < lengthSnake; i++){
		if(snakeHead.posX>=MAIN_BORDER_RIGHT){
			system("cls");
			printf("MAIN");
			break;
        }
		snakeBody[lengthStart].posX= a =snakeHead.posX-i;
        snakeBody[lengthStart].posY= b =snakeHead.posY;
        gotoCoord(a,b);

        if(lengthStart==0)
            printf("%c", 254);
        else
            printf("%c", 254);
        lengthStart++;
    }
    
    ableToTurn();
    
    if(!kbhit()){
    	snakeHead.posX++;
	}

}

void moveSnakeLeft(){
	int i, j;
	for(i = 0; i <= turn[parts].posX - snakeHead.posX && lengthStart < lengthSnake; i++){
		if(snakeHead.posX <= MAIN_BORDER_LEFT){
			system("cls");
			printf("bye");
			break;
		}
		snakeBody[lengthStart].posX= a =snakeHead.posX+i;
        snakeBody[lengthStart].posY= b =snakeHead.posY;
        gotoCoord(a,b);

        if(lengthStart==0)
            printf("%c", 254);
        else
            printf("%c", 254);
        lengthStart++;
    }
    
    ableToTurn();
    if(!kbhit()) 
    snakeHead.posX--;
}

void moveSnakeUp(){
	int i, j;
	for(i = 0; i <= turn[parts].posY - snakeHead.posY  && lengthStart < lengthSnake; i++){
		if(snakeHead.posY <= MAIN_BORDER_TOP){
			system("cls");
			printf("bye");
			break;
		}
		snakeBody[lengthStart].posX= a =snakeHead.posX;
        snakeBody[lengthStart].posY= b =snakeHead.posY+i;
        gotoCoord(a,b);

        if(lengthStart==0)
            printf("%c", 254);
        else
            printf("%c", 254);
        lengthStart++;
    }
    
    ableToTurn();
    if(!kbhit())
    snakeHead.posY--;	
}

void moveSnakeDown(){
	int i, j;
	for(i = 0; i <= snakeHead.posY - turn[parts].posY && lengthStart < lengthSnake; i++){
		if(snakeHead.posY >= MAIN_BORDER_BOTTOM){
			system("cls");
			printf("bye");
			break;
		}
		snakeBody[lengthStart].posX= a =snakeHead.posX;
        snakeBody[lengthStart].posY= b =snakeHead.posY-i;
        gotoCoord(a,b);

        if(lengthStart==0)
            printf("%c", 254);
        else
            printf("%c", 254);
        lengthStart++;
    }
    
    ableToTurn();
    if(!kbhit())
    snakeHead.posY++;
}

void ableToTurn(){
	
    int i, j, c, k, check;
    pauseEachMove(1000000, 1000000);
    for(i=parts;i>=0;i--){
        if (turn[i].posX==turn[i-1].posX){
            check = turn[i].posY-turn[i-1].posY;
            c = 1;
			//moving up            
            if(check>0){
                for(j=0;j<=check&&lengthStart<lengthSnake;j++){

                    lengthStart++;
                    if(lengthSnake==lengthStart){
                    	break;
					}

                    snakeBody[lengthStart].posY=b=turn[i].posY-j;
                    snakeBody[lengthStart].posX=a=turn[i].posX;
                    gotoCoord(a,b);

                    if(turn[i].direction==RIGHT && c == 1){
	                    printf("%c",254);
	                    c++;
                    }
                    
                    else if(turn[i].direction==LEFT && c == 1){
                    	printf("%c",254);
                        c++;
                    }
                    
                    else{
						printf("%c",254);
					}                     
                }
            }
            // moving down
            else
                for(j=0;j<=-check&&lengthStart<lengthSnake;j++){
                    snakeBody[lengthStart].posY=b=turn[i].posY+j;
                    snakeBody[lengthStart].posX=a=turn[i].posX;
                    gotoCoord(a,b);

                    if(turn[i].direction==RIGHT && c == 1){

	                   printf("%c",254);
	                   c++;
                    }
                    else if(turn[i].direction==LEFT && c == 1){

                    	printf("%c",254);
                        c++;
                    }
                    else{
                    	printf("%c",254);
                    	lengthStart++;
					}

                }

        }
        else if (turn[i].posY==turn[i-1].posY)
        {
			check=turn[i].posX-turn[i-1].posX;
			// moving right
			if(check>0){
			for(j=0;j<=check&&lengthStart<lengthSnake;j++){
			  	snakeBody[lengthStart].posY=b=turn[i].posY;
	            snakeBody[lengthStart].posX=a=turn[i].posX-j;
	        	gotoCoord(a,b);
	            if(turn[i].direction==UP&&c==1){
	
	              printf("%c",254);
	              c++;
	             }
	              
	            else if(turn[i].direction==DOWN&&c==1){
	
	                printf("%c",254);
	                c++;
	            }
	            else{
	            	printf("%c",254);
				}                       
	              lengthStart++;
	          }
	
	      }
	      //moving left
	      else
	        for(j=0;j<=-check&&lengthStart<lengthSnake;j++){
	
				snakeBody[lengthStart].posY=b=turn[i].posY;
				snakeBody[lengthStart].posX=a=turn[i].posX+j;
				gotoCoord(a,b);
				if(turn[i].direction==UP&&c==1){
				
				printf("%c",254);
				c++;
				}
				else if(turn[i].direction==DOWN&& c == 1){
				
				printf("%c",254);
				c++;
				}
				else {
				printf("%c",254);
				}
				
				lengthStart++;
	        }
        }

    }
}

void checkCollision(){
	int i;
	for(i = 3; i<=lengthSnake; i++){
		if(snakeHead.posX == snakeBody[i].posX && snakeHead.posY == snakeBody[i].posY){
			pauseEachMove(100000000, 100000000);
			exit(0);
		}
	}
}

void spawnFood(){
	srand(time(NULL));
	int a, b, i, j;
	if(snakeHead.posX == food.posX && snakeHead.posY == food.posY){
		for(i = 0; i<1+rand()%10; i++){
			food.posX = MAIN_BORDER_LEFT+1+rand()%(MAIN_BORDER_RIGHT-MAIN_BORDER_LEFT-1);
		}
		for(i = 0; i<1+rand()%10; i++){
			food.posY = MAIN_BORDER_TOP+1+rand()%(MAIN_BORDER_BOTTOM-MAIN_BORDER_TOP-1);
		}
		foodCounter++;
		lengthSnake+=2;
	}	
}
