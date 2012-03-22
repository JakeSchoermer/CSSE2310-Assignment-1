#include<stdio.h>
#include"noline.h"

char board[board_x][board_y];
int turn = 1; //Keeps track of which turn it is;

//Board Related Functions

void setup_board(void) {
	int x,y;
	for (x=0; x<board_x; x++) {
		for (y=0; y<board_y; y++) {
			board[x][y] = '.';
		}
	}
}

void print_board(void) {
	int x,y;
	printf("-----\n");
	for (x=0; x<board_y; x++) {
		for(y=0; y<board_y; y++) {
			printf("%c", board[x][y]);
		}
		printf("\n");
	}
	printf("=====\n");
}

void insert_number(char ch, int x, int y) {
	if (x > board_x || y > board_y) {
		//Do Nothing
	}
	else {
		board[x][y] = ch;	
	}
}

char get_char(void) {
	if (turn%2==1) {
		return '0';
	}
	else {
		return 'X';
	}
}

//Returns 1 if unput is valid, else returns 0
int input_is_valid(int x, int y)
	if (x < board_x && x > 0 &&
		y <board_y && y > 0) {
		return 1
	}else {
		return 0
	}
}

//Main

int main(int argc, const char* argv[] ) {
	int x, y;

	setup_board();
	print_board();
	
	//Main Game Loop
	while (1) {
		scanf("%d %d", &x, &y); //Get User Input
		
		if (board[x][y] != '0' && board[x][y] != 'X') {
			insert_number(get_char(), x, y);
			
			turn++;
		}
		else {
			printf("\n");
		}

		
		print_board();
	}
}
