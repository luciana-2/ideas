#include <stdio.h>

//juego de ajedrez en C
#define N 8

#define CELL_MAX (N * N - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[N][N])
{
    int cell = 1; // mi lado computadora me dice que empiece desde 0, pero mi lado ajedrz me dice que empiece desde 1.

    print_sep(N);
    for (int row = 0; row < N; ++row) {
        for (int column = 0; column < N; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(N);
    }
}


int main (){
	printf("juego de ajedrez en terminal\n");
	printf("sos blancas\n");
  char board[N][N] = {
        { 'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'}, 
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        { '-', '-', '-', '-', '-', '-', '-', '-'}, 
        { '-', '-', '-', '-', '-', '-', '-', '-'},
        { '-', '-', '-', '-', '-', '-', '-', '-'}, 
        { '-', '-', '-', '-', '-', '-', '-', '-'},
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, 
        { 'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'}
    };

    print_board(board);


	return 0;
}