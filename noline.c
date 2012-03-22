#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"noline.h"

char board[board_x][board_y];
int turn = 1; /*Keeps track of which turn it is;*/


/*Board Related Functions*/

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
		/*Do Nothing*/
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

/*Returns 1 if input is valid, else returns 0*/
int input_is_valid(int x, int y) {
	/*Checks that values are within scope for the board size*/	
	if ((x < board_x) && (x >= 0) &&	(y < board_y) && (y >= 0)) {
		return 1;
	}else {
		return 0;
	}
}

void print_err(int exit_status) {
	switch(exit_status) {
		case 1:
			printf("Usage: noline dim [playerXtype [playerOtype [Oin Oout Xin Xout]]]\n");
			break;
		case 2:
			printf("Invalid board dimension.\n");
			break;
		case 3:
			printf("Invalid player type.\n");
			break;
		case 4:
			printf("Invalid files\n");
			break;
	}
}

/*Main*/

int main(int argc, const char* argv[] ) {
	int nbytes = 100;
	
	/*Command-line Arguments*/
	
	int dim; /*Denotes Side-length of Grid*/
	
	/*----------------------*/
	
	char *input;
	int x, y;
	int args_assigned;
	
	
	/*If no Args specified*/
	if (argc < 2) {
		print_err(1);
		return 0;
	}
	
	else {
		
		setup_board();
		print_board();
	
		/*Main Game Loop*/
		while (1) {
		
			while (args_assigned != 2){
				input = (char *) malloc (nbytes + 1);
				getline(&input, &nbytes, stdin);
				args_assigned = sscanf (input, "%d %d", &x, &y);
			}
				
			if (board[x][y] != '0' && board[x][y] != 'X') {
				/*Validate Input*/
				if (input_is_valid(x,y) == 1){
					insert_number(get_char(), x, y);
					print_board();
					turn++;
				}
			}
		}
	}
}