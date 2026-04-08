#include <stdio.h>
#include <stdbool.h>
//juego de ajedrez en C
#define N 9
#define M 5
#define CELL_MAX (N * N - 1)

//si queres mover un peon, pone la P antes
char* validas[13]={"R*", "Q*", "K*", "B*", "N*", "P*", "N ", "Q ", "K ", "B ", "R ", "P ", "0 "};

/*
x: captura
0-0: enroque corto
0-0-0: enroque largo
+: jaque
#: jaque mate
*/


void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("...............");
    printf("\n");

}

void print_board(char* board[N][N])
{
    int cell = 1; // mi lado computadora me dice que empiece desde 0, pero mi lado ajedrz me dice que empiece desde 1.

    print_sep(N-4);
    for (int row = 0; row < N; ++row) {
        for (int column = 0; column < N; ++column) {
            printf("\t |  %s ", board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(N-4);
    }
}





bool mov_legal(char* board[N][N], char movimiento[M]){
    int j;
    j=0;
    bool legal=false;
    while(j<13){
        printf("validas[j]= %c\n", validas[j][0]);
        legal= movimiento[0]==validas[j][0] || legal;
        printf("legal=%d\n", legal);
        j=j+1;
    }
    return legal;
}




int main (){
    printf("AJEDRZ\t\n");
	printf("juego de ajedrez en terminal\n");
	printf("sos las blancas\n");
    printf("los que tienen * son las negras; y en la notacion debe ir con el * (!!)\n");
    printf("para mover, usar notacion algebraica del ajedrez, ej: hc3\n");
    printf("que se lee como: horse to c3 o caballo a c3\n");

  char* board[N][N] = {
        { "-","a", "b", "c", "d", "e", "f", "g", "h"},
        { "8","R*", "N*", "B*", "Q*", "K*", "N*", "H*", "R*"}, 
        { "7","P*", "P*", "P*", "P*", "P*", "P*", "P*", "P*"},
        { "6","", "", "", "", "", "", "", ""}, 
        { "5","", "", "", "", "", "", "", ""},
        { "4","", "", "", "", "", "", "", ""}, 
        { "3","", "", "", "", "", "", "", ""},
        { "2","P", "P", "P", "P", "P", "P", "P", "P"}, 
        { "1","R", "N", "B", "Q", "K", "B", "N", "R"},
    };

    char* turno= "Blancas";
    char movimiento[M];
    int i=0;
    print_board(board);
   
    printf("turno: %s\n", turno);
    printf("ingrese movimiento:\n");
    while(i<3){
        scanf(" %c", &movimiento[i]);
        printf("movimiento[0]= %c\n", movimiento[0]);
        i=i+1; 
    }

    printf("es legal? %d\n",mov_legal(board,movimiento));
    
    
   

	return 0;
}