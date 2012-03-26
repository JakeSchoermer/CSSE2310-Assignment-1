#define board_x 5
#define board_y 5

void setup_board(int);

void print_board(void);

void insert_number(char, int, int);

char get_char(void);

int board_input_is_valid(int, int);

void print_err(int);

void game_over_status(int);

void cmd_in(int, const char* []);

void print_args(void);

int horizontal_line(char, int, int);

int vertical_line(char, int, int);

int diagonal_line(char, int, int);
