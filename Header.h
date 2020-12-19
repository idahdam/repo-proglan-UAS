#ifndef HEADER_H
	
	#define HEADER_H
		
	#include <stdio.h>
	#include <stdlib.h>
	#include <windows.h>
	#include <time.h>
	#include <conio.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdbool.h>
	
	#define MAX_POS 4
    #define MIN_POS 1
    #define MAX_POS_EXIT 2
    #define MIN_POS_EXIT 1
    
    #define BARIS 25
	#define KOLOM 25
	
	#define UP 72       //             up
	#define DOWN 80     //             down
	#define LEFT 75     //             LEFT
	#define RIGHT 77    //             right
	
	#define MAIN_BORDER_LEFT 10
	#define MAIN_BORDER_RIGHT 70
	#define MAIN_BORDER_TOP 10
	#define MAIN_BORDER_BOTTOM 30
	
	#define MAX_LEN 100
	
	// functions in Welcome.c
	
	void mainFunction();
	void background();
	void loading();
	void arrow(int ap, int rp);
	void menu();
	void gotoxy(int x , int y);
	void about();
	
	// functions in Start.c
	
	void gotoCoord(int x, int y);
	void drawBorder(int state);
	void startFunction();
	void setStart();
	void pauseEachMove(int value1, int value2);
	void moveSnake();
	void moveSnakeRight();
	void moveSnakeLeft();
	void moveSnakeUp();
	void moveSnakeDown();
	void ableToTurn();
	void checkCollision();
	void spawnFood();
	
	// functions in Leaderboard.c
	
	void printLose();
	void enterScore(int score);
	void showScore();
	void reArrange();
	void deleteLinkedList();
	int checkLine();
	
	// functions in Exit.c
	void areYouSure();
	

#endif

