#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"noline.h"

char board[100][100];
int turn = 1; /*Keeps track of which turn it is;*/


/*Command-line Arguments*/
	
int dim; /*Denotes Side-length of Grid*/
int playerXtype;
int playerOtype;
char* Oin = "-";
char* Oout = "-";
char* Xin = "-";
char* Xout = "-";


void setup_board(int dim) {
	

	int x,y;
	for (x=0; x<dim; x++) {
		for (y=0; y<dim; y++) {
			board[x][y] = '.';
		}
	}
}


void print_board(void) {
	int i,x,y;
	
	
	for (i=0;i<dim;i++)
		printf("-");
	printf("\n");
	
	for (x=0; x<dim; x++) {
		for(y=0; y<dim; y++) {
			printf("%c", board[x][y]);
		}
		printf("\n");
	}
	for (i=0;i<dim;i++)
		printf("=");
	printf("\n");
}

void insert_number(char ch, int x, int y) {
	if (x > dim || y > dim) {
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
int board_input_is_valid(int x, int y) {
	/*Checks that values are within scope for the board size*/	
	if ((x < dim) && (x >= 0) &&(y < dim) && (y >= 0)) {
		return 1;
	}else {
		return 0;
	}
}

void print_err(int exit_status) {
	switch(exit_status) {
		case 1:
			fprintf(stderr,"Usage: noline dim [playerXtype [playerOtype [Oin Oout Xin Xout]]]\n");
			break;
		case 2:
			fprintf(stderr,"Invalid board dimension.\n");
			break;
		case 3:
			fprintf(stderr,"Invalid player type.\n");
			break;
		case 4:
			fprintf(stderr,"Invalid files\n");
			break;
	}
}

void end_game(int game_over_status, char player) {
	switch(game_over_status) {
		case 0:
			printf("The game is a draw.\n");
		case 1:
			printf("Player %c loses", player);
		case 2:
			printf("Player %c loses due to EOF", player);
	}
}

void cmd_in(int argc, const char* argv[]) {
	int i;

	for (i=0; i<argc; i++) {
		/*dim*/
		if ((i==1)) {
			if ((atoi(argv[i])%2!=0)) {
				dim = atoi(argv[i]);
			}
			else {
				/*Invalid Board Dimension*/
				print_err(2);
				exit(0);
			}
		}
		
		/*PlayerXtype & Player O type*/
		if ((i==2) || (i==3)) {
			printf("%s\n" argv[i]);
		}
		
		/**/
	}
}

/*Main*/

int main(int argc, const char* argv[] ) {
	int nbytes = 100;
	/*----------------------*/
	
	char *input;
	int x, y;
	int args_assigned;
	
	/*If no Args specified*/
	if ((argc !=2) && (argc !=3) && (argc != 4) && (argc != 8)) {
		print_err(1);
		exit(0);
	}
	
	else {
		
		cmd_in(argc, argv);			
		setup_board(dim);
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
				if (board_input_is_valid(x,y) == 1){
					insert_number(get_char(), x, y);
					print_board();
					turn++;
				}
			}
			args_assigned = 0; /*reset for next sscanf*/
		}
	}
}