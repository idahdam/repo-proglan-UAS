#include "Header.h"

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

COORD setCoordSnake={};

void gotoCoord(int x, int y){
    setCoordSnake.X=x;
    setCoordSnake.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),setCoordSnake);
}

void drawBorder(int state){
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
	
	if(state == 1){
		gotoCoord(MAIN_BORDER_LEFT, MAIN_BORDER_TOP-1);
		printf("Score is : %d", foodCounter-1);
	}
	else if(state == 0){
		gotoCoord(MAIN_BORDER_LEFT+10, MAIN_BORDER_TOP+10);
		printf("Press any key to move your snake");
	}
}

void startFunction(){
	setStart(),	moveSnake();
}

void setStart(){
	char keyPress;
    gotoCoord(0, 0);
    background();
    drawBorder(0);
    keyPress = getch();
    system("cls");
    gotoCoord(0, 0);
    drawBorder(1);
    background();
	snakeHead.direction = keyPress;
	lengthSnake = 15;
	parts = 0;
	foodCounter = 0;
	snakeHead.posX = MAIN_BORDER_LEFT + 10;
	snakeHead.posY = MAIN_BORDER_TOP + 10;
	food.posX = MAIN_BORDER_LEFT + 10;
	food.posY = MAIN_BORDER_BOTTOM - MAIN_BORDER_TOP;
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
	background();
	do{
		fflush(stdin);
        lengthStart=0;
        for(i=0;i<=lengthSnake;i++){
	        snakeBody[i].posX=0;
	        snakeBody[i].posY=0;
	
	        if(i==lengthSnake) break;
        }
        //system("cls");
        drawBorder(1);
        background();
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
			menu();
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
//			printf("bye");
			menu();
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
			menu();
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
			menu();
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
//			exit(0);
			printLose();
			enterScore(foodCounter);
			menu();
			
		}
	}
	
	for(i = 0; i<=lengthSnake; i++){
		if(snakeHead.posX == MAIN_BORDER_RIGHT || snakeHead.posX == MAIN_BORDER_LEFT || snakeHead.posY == MAIN_BORDER_TOP || snakeHead.posY == MAIN_BORDER_BOTTOM){
			pauseEachMove(100000000, 100000000);
			//break;
			//system("cls");
			// insert lose here and enter the thing
			printLose();
			enterScore(foodCounter-1);
        	menu();
        	
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
		for(i = 0; i<lengthSnake; i++){
			if(food.posX == snakeBody[i].posX && food.posY == snakeBody[i].posY){
				spawnFood();
			}
		}
		
		foodCounter++;
		lengthSnake+=2;
	}	
}
