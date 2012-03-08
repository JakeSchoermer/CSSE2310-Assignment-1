#include<stdio.h>
#include"noline.h"

char board[board_x][board_y];

//Board Related Functions

void setup_board(void) {
	int x,y;
	for (x=0; x<5; x++) {
		for (y=0; y<5; y++) {
			board[x][y] = '.';
		}
	}
}

void print_board(void) {
	int x,y;
	for (x=0; x<5; x++) {
		for(y=0; y<5; y++) {
			printf("%c", board[x][y]);
		}
		printf("\n");
	}
}


//Main

int main(int argc, const char* argv[] ) {
	setup_board();
	print_board();
}
