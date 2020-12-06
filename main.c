/* ***************************************************************
                    SNAKE VERSION 1.98089                        *
---------------------------SB DON*-------------------------------*
                 ===========================O                    *
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include <conio.h>
/* ***************************************************************
                    CONSTANTS                                    *
*****************************************************************/
#define UP 72       //             up
#define DOWN 80     //             down
#define LEFT 75     //             LEFT
#define RIGHT 77    //             right
/* ***************************************************************
                    MAKING COORDINATES                           *
*****************************************************************/
COORD setCoord={};
void gotoCoord(int x , int y){
    setCoord.X=x;
    setCoord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),setCoord);
}
/* ***************************************************************
                    STRUCTURE DEFINING                           *
*****************************************************************/
struct snakePart{
    int x;
    int y;
    int direction;
};

typedef struct snakePart Snake;
Snake headSnake,turn[400],food,bodySnake[150],bigFood,Bug,Bug2,Bug3;
/* ***************************************************************
                    INITIALIZERS                                 *
*****************************************************************/
int lengthSnake=5,lengthStart=0,turn_no=0,a,b,big=0,counter=0,fatter=0,bugCount=0,bugCount2=0,Foodcall=0,scoreOn=0,scoreTotal=0;
long double longNum=1000000;
/* ***************************************************************
                    STRUCTURE DEFINING                           *
*****************************************************************/
void delay(){
    int k;
    if(headSnake.direction==UP || headSnake.direction==DOWN)
        for(k=0;k<=35000000;k++);
    else
        for(k=0;k<=30000000;k++);
}

void drawBackground(){

	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN) ;
   system("cls");
   int i;
   if(Foodcall==1){
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN) ;
   gotoCoord(food.x,food.y);
   printf("%c",162);
   }
   if(big==1)
   {


	SetConsoleTextAttribute(h, FOREGROUND_RED) ;
       gotoCoord(bigFood.x,bigFood.y);
       printf("%c",153);

   }
   if(bugCount)
   {
       SetConsoleTextAttribute(h, FOREGROUND_BLUE |FOREGROUND_INTENSITY) ;
       gotoCoord(Bug.x,Bug.y);
       printf("%c",177);
   }
   if(bugCount2)
   {
       SetConsoleTextAttribute(h, FOREGROUND_GREEN) ;
       gotoCoord(Bug2.x,Bug2.y);
       printf("%c",175);
   }
    if(bugCount2>=2)
   {
       SetConsoleTextAttribute(h, FOREGROUND_GREEN) ;
       gotoCoord(Bug3.x,Bug3.y);
       printf("%c",219);
   }
   if(scoreOn){
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY) ;
        gotoCoord(16,9);
    printf("Score: %d",scoreTotal);
   }
   SetConsoleTextAttribute(h, FOREGROUND_GREEN) ;
   for(i=10;i<71;i++)
   {
       gotoCoord(i,10);
       printf("%c",66);

       gotoCoord(i,30);
       printf("%c",66);

   }
   for(i=11;i<30;i++)
   {
       gotoCoord(10,i);
    	printf("%c",65);
       gotoCoord(70,i);
       printf("%c",65);
   }
}
/* ***************************************************************
                    MOVE SNAKE RIGHT                             *
*****************************************************************/
void moveRight(){
    int i,k;

    for(i=0;i<=(headSnake.x-turn[turn_no].x)&&lengthStart<lengthSnake;i++){
//         if(headSnake.x>=69){
//            turn_no++;
//            turn[turn_no]=headSnake;
//            turn[turn_no].x=headSnake.x;
//            turn[turn_no].x=69;
//            headSnake.x=11;
//            turn_no++;
//            turn[turn_no]=headSnake;
//        }
        
        bodySnake[lengthStart].x=a=headSnake.x-i;
        bodySnake[lengthStart].y=b=headSnake.y;
        gotoCoord(a,b);

        if(lengthStart==0)
            printf("%c",153);
        else
            printf("%c",205);
        lengthStart++;
    }
    turnSnake();
    if(!kbhit())
    headSnake.x++;
}

/* ***************************************************************
                    MOVE SNAKE LEFT                              *
*****************************************************************/

void moveLeft(){
    int i;

    for(i=0;i<=(turn[turn_no].x-headSnake.x)&&lengthStart<lengthSnake;i++){
        if(headSnake.x<=11){
            turn_no++;
            turn[turn_no]=headSnake;
            turn[turn_no].x=11;
            headSnake.x=69;
            turn_no++;
            turn[turn_no]=headSnake;
         }
       bodySnake[lengthStart].x=a=headSnake.x+i;
        bodySnake[lengthStart].y=b=headSnake.y;
        gotoCoord(a,b);
        if(lengthStart==0)
            printf("%c",153);
        else
           printf("%c",205);
        lengthStart++;
    }
    turnSnake();
    //if(!kbhit())
    headSnake.x--;
}
/* ***************************************************************
                    MOVE SNAKE UPWARD                            *
*****************************************************************/

void moveUp(){
    int i,j,k;

    for(i=0;i<=(turn[turn_no].y-headSnake.y)&&lengthStart<lengthSnake;i++){
        if(headSnake.y<=11){
            turn_no++;
            turn[turn_no]=headSnake;
            headSnake.y=29;
            turn[turn_no].y=11;
            turn_no++;
            turn[turn_no]=headSnake;
        }
        bodySnake[lengthStart].x=a=headSnake.x;
        bodySnake[lengthStart].y=b=headSnake.y+i;
        gotoCoord(a,b);

        if(lengthStart==0)
            printf("%c",153);
        else
            printf("%c",186);
        lengthStart++;
    }
    turnSnake();
    //if(!kbhit())
    headSnake.y--;

}
/* ***************************************************************
                    MOVE SNAKE DONWARD                           *
*****************************************************************/
void moveDown(){
    int i,k;
    int count = 0;
    for(i=0; i <= (headSnake.y-turn[turn_no].y)&&lengthStart<lengthSnake;i++){
         if(headSnake.y>=29){
            turn_no++;
            turn[turn_no]=headSnake;
            turn[turn_no].y=29;
            headSnake.y=11;
            turn_no++;
            turn[turn_no]=headSnake;
    }
   /* if(headSnake.y == turn[turn_no].y)
        {
            printf("Subesh");
            getch();
        }*/
      bodySnake[lengthStart].x=a=headSnake.x;
        bodySnake[lengthStart].y=b=headSnake.y-i;
        gotoCoord(a,b);

        if(lengthStart==0)
            printf("%c",153);
        else
            printf("%c",186);
        lengthStart++;
        count++;
    }

    if(count==1){
        gotoCoord(headSnake.x,headSnake.y+1);
        printf("%c",153);

    }
    turnSnake();
   // if(!kbhit())
    headSnake.y++;
}
/* ***************************************************************
                   MOVE THE SNAKE                                *
*****************************************************************/
void moveSnake(){
    char ab,key;
    int i,k;

    do{

             fflush(stdin);
             lengthStart=0;
             for(i=0;i<=lengthSnake;i++)
             {
                 bodySnake[i].x=0;
                 bodySnake[i].y=0;

                 if(i==lengthSnake)
                    break;
             }

             makeFood();
             makeBug();
             drawBackground();



        	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN| FOREGROUND_INTENSITY) ;
        if(headSnake.direction==RIGHT)
            moveRight();
        if(headSnake.direction==LEFT)
            moveLeft();
        if(headSnake.direction==UP)
            moveUp();
        else if(headSnake.direction==DOWN)
            moveDown();
    	keepScore();
       checkGame();
       delay();
    }while(!kbhit());
ab=getch();

    key=getch();


    if(key==RIGHT&&headSnake.direction!=RIGHT&&headSnake.direction!=LEFT||key==LEFT&&headSnake.direction!=RIGHT&&headSnake.direction!=LEFT || key==UP&&headSnake.direction!=UP&&headSnake.direction!=DOWN || key==DOWN&&headSnake.direction!=UP&&headSnake.direction!=DOWN)
    {
        headSnake.direction=key;
        turn_no++;
        turn[turn_no]=headSnake;
        for(k=0;k<=1000000;k++);
        if(key==UP){
            headSnake.y--;
        }
        else if(key==DOWN){
            headSnake.y++;
        }
        else if(key==RIGHT){
            headSnake.x++;
        }
        else if(key==LEFT){
            headSnake.x--;
        }
    }
    moveSnake();
}
/* ***************************************************************
                    MAKE THE SNAKE TURN                          *
*****************************************************************/
void turnSnake(){
    int i,c=1,j,f=0,k,check,doubleCheck;
    for(k=0;k<=1000000;k++);
    for(i=turn_no;i>=0;i--)
    {
        if(f==1){
            f=0;
            continue;
        }
        c=1;
        if (turn[i].x==turn[i-1].x)
        {
                check=turn[i].y-turn[i-1].y;
             if(turn[i].y==29&&turn[i].direction==UP||turn[i].y==11&&turn[i].direction==DOWN)
              {
                  continue;
              }

             if(check>0)
              {
                  for(j=0;j<=check&&lengthStart<lengthSnake;j++)
                  {

                    lengthStart++;
                    if(lengthSnake==lengthStart)
                        break;
                      bodySnake[lengthStart].y=b=turn[i].y-j;
                       bodySnake[lengthStart].x=a=turn[i].x;
                      gotoCoord(a,b);

                      if(turn[i].direction==RIGHT&&c==1){

                      printf("%c",200);
                      c++;
                      }
                      else if(turn[i].direction==LEFT&&c==1){

                        printf("%c",188);
                        c++;
                      }
                      else

                        printf("%c",186);


                  }

              }
              else
                for(j=0;j<=-check&&lengthStart<lengthSnake;j++)
                  {
                      bodySnake[lengthStart].y=b=turn[i].y+j;
                       bodySnake[lengthStart].x=a=turn[i].x;
                      gotoCoord(a,b);

                      if(turn[i].direction==RIGHT&&c==1){

                      printf("%c",201);
                      c++;
                      }
                      else if(turn[i].direction==LEFT&&c==1){

                        printf("%c",187);
                        c++;
                      }
                      else

                        printf("%c",186);
                      lengthStart++;
                  }

        }
        else if (turn[i].y==turn[i-1].y)
        {
              check=turn[i].x-turn[i-1].x;
                if(turn[i].x==11&&turn[i].direction==RIGHT||turn[i].x==69&&turn[i].direction==LEFT)
              {

                  continue;
              }
               if(check>0)
              {
                  for(j=0;j<=check&&lengthStart<lengthSnake;j++)
                  {
                        bodySnake[lengthStart].y=b=turn[i].y;
                       bodySnake[lengthStart].x=a=turn[i].x-j;
                      gotoCoord(a,b);
                      if(turn[i].direction==UP&&c==1){

                      printf("%c",188);
                      c++;
                      }
                      else if(turn[i].direction==DOWN&&c==1){

                        printf("%c",187);
                        c++;
                      }
                      else

                        printf("%c",205);

                      lengthStart++;
                  }

              }
              else
                for(j=0;j<=-check&&lengthStart<lengthSnake;j++)
                  {

                      bodySnake[lengthStart].y=b=turn[i].y;
                      bodySnake[lengthStart].x=a=turn[i].x+j;
                      gotoCoord(a,b);
                      if(turn[i].direction==UP&&c==1){

                      printf("%c",200);
                      c++;
                      }
                      else if(turn[i].direction==DOWN&&c==1){

                        printf("%c",201);
                        c++;
                      }
                      else

                        printf("%c",205);


                      lengthStart++;
                  }
        }


    }
}
/* ***************************************************************
                    MAKING SNACKS FOR SNAKE                      *
*****************************************************************/
void checkGame(){
    int i,k;

        if(headSnake.x==Bug.x && headSnake.y==Bug.y){
        for(k=0;k<=100000000;k++);
         mainMenu();
        }
        if(headSnake.x==Bug2.x && headSnake.y==Bug2.y)
        longNum*=5;
        if(headSnake.x==Bug3.x && headSnake.y==Bug3.y)
        lengthSnake-=3;
        if(lengthSnake<=0)
            lengthSnake=1;
        for(i=3;i<lengthSnake;i++)
        {
            if(bodySnake[0].x==bodySnake[i].x&& bodySnake[0].y==bodySnake[i].y){
                 for(k=0;k<=100000000;k++);
                 mainMenu();
            }
        }
}
/* ***************************************************************
                    MAKING SNACKS FOR SNAKE                      *
*****************************************************************/
void makeFood(){
    srand(time(0));
    int i,j;
    if(headSnake.x==food.x && headSnake.y==food.y)
    {
     for(i=1;i<=1+rand()%10;i++)
     food.x=12+rand()%(68-12);
     for(i=1;i<=1+rand()%10;i++)
      food.y=12+rand()%(28-12);
      counter++;
      fatter++;
      longNum=1000000;
      lengthSnake+=3;
    }

      if(fatter==3){
      big=1;
      for(i=1;i<=1+rand()%10;i++)
       bigFood.x=12+rand()%(68-12);
      for(i=1;i<=1+rand()%10;i++)
       bigFood.y=12+rand()%(28-12);
       fatter=0;
       bugCount++;
      }
      if(headSnake.x==bigFood.x && headSnake.y==bigFood.y)
    {
        lengthSnake+=5;
        big=0;
    }
}
/* ***************************************************************
                    MAKING SNACKS FOR SNAKE                      *
*****************************************************************/
void makeBug(){
    int i,j;
    srand(time(0));

    if(bugCount){
        j=rand()%30;
        if(j==20)
        {
           for(i=1;i<=1+rand()%10;i++)
           Bug.x=12+rand()%(68-12);
           for(i=1;i<=1+rand()%10;i++)
           Bug.y=12+rand()%(28-12);
        }
    }
    if(bugCount>3)
        bugCount2=1;
    if(bugCount2)
    {
        j=rand()%10;
        if(j==1){
        for(i=1;i<=1+rand()%10;i++)
           Bug2.x=12+rand()%(68-12);
           for(i=1;i<=1+rand()%10;i++)
           Bug2.y=12+rand()%(28-12);
        }
        bugCount2++;
    }
    if(bugCount2>=2)
    {
        j=rand()%5;
        if(j==4){
        for(i=1;i<=1+rand()%10;i++)
           Bug3.x=12+rand()%(68-12);
           for(i=1;i<=1+rand()%10;i++)
           Bug3.y=12+rand()%(28-12);
        }
    }
}
/* ***************************************************************
                    MOVE CURSOR                                  *
*****************************************************************/
int moveCursor(){
    int i=1;
    char ch='0';
    while(1)
    {
        gotoCoord(50,16+i);
        switch (ch)
        {
        case 80:
            i++;
            if(i==4)
                i=1;
            break;
        case 72:
            i--;
            if(i==0)
                i=3;
            break;
        }
        gotoCoord(30,16+i);
            printf("->");
        gotoCoord(40,16+i);
           ch=getch();
        gotoCoord(30,16+i);
            printf("  ");
        if(ch=='\r')
        {
            if(i==1)
                return 1;
            else if(i==2)
                return 2;
            else
                return 3;
        }

    }

}
/* ***************************************************************
                    WELCOME TO SUBU SNAKE XD                     *
*****************************************************************/
void welcomeTo(){
    drawBackground();
    char welcome[]="Welcome To SUBU-SNAKE";
    int i,k,j;
    gotoCoord(30,16);
    for(i=0;i<strlen(welcome);i++)
    {
        for(k=0;k<=10000000;k++);
        printf("%c",welcome[i]);
    }

    for(j=0;j<=35;j++)
    {
        for(k=0;k<=1000000;k++);
        drawBackground();
        lengthStart=0;
        gotoCoord(30,16);

        for(i=0;i<strlen(welcome);i++)
        {

            printf("%c",welcome[i]);
        }
        gotoCoord(38,19);
        printf("loading...");

        for(k=0;k<=10000000;k++);
        moveRight();
        gotoCoord(30+26,20);
    printf("X");
    }
for(k=0;k<=100000000;k++);
}

/* ***************************************************************
                    MAIN MENU                                    *
*****************************************************************/
void mainMenu(){
    resetGame();
    drawBackground();
    gotoCoord(35,15);
    printf("Main Menu");
    gotoCoord(33,17);
    printf("Play Game");
    gotoCoord(33,18);
    printf("About Game");
    gotoCoord(33,19);
    printf("Exit");
    switch(moveCursor()){
    case 1:
        load();
        playGame();/* ***************************************************************
                    START GAME                                   *
*****************************************************************/
        return;
    case 2:
        //
    case 3:
        exit(0);
    }
}
/* ***************************************************************
                    Score                                        *
*****************************************************************/
void keepScore(){

int c=0;
      if(headSnake.x==bigFood.x && headSnake.y==bigFood.y)
    {
        scoreTotal+=2;
    }

      if(headSnake.x==food.x && food.y==food.y)
    {
        scoreTotal+=1;

    }
    if(headSnake.x==Bug3.x && headSnake.y==Bug3.y)
    {
        scoreTotal-=3;

    }

}
/* ***************************************************************
                    Loading The Game                             *
*****************************************************************/
void load(){

    drawBackground();
    int r,q;
    gotoCoord(35,18);
    printf("loading...");
    gotoCoord(29,19);
    for(r=1;r<=20;r++){
        for(q=0;q<=10000000;q++);//to display the character slowly
            printf("%c",221);
}
for(q=0;q<=100000000;q++);
}
/* ***************************************************************
                    RESET GAME                                   *
*****************************************************************/
void resetGame(){
    turn_no=0;
    headSnake.x=20;
    headSnake.y=20;
    food.x=25;
    food.y=25;
    headSnake.direction=RIGHT;
    turn[turn_no]=headSnake;
    lengthSnake=50;
    lengthStart=0;
    big=0;
    counter=0;
    fatter=0;
    bugCount=0;
    bugCount2=0;
    Foodcall=0;
    scoreOn=0;
    scoreTotal=0;
long double longNum=1000000;
}
/* ***************************************************************
                    START GAME                                   *
*****************************************************************/
void playGame(){
    Foodcall=1;
    scoreOn=1;
    headSnake.x=20;
    headSnake.y=20;
    moveSnake();

}
int main()
{

    resetGame();
    welcomeTo();
    mainMenu();

}
