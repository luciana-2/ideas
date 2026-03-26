#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 

//version dos donde hay vidas y niveles//

int aleatorio (void) {
    int x;

    srand(time(NULL));  //"semilla" que agarra el rand()//
    x = rand() % 21; //me da numero aleatorio entre los restos de 21 que son justamente nros entre 0 y 20//  
    
    return x;
}


int  main (void) {
    int numero, m,i;
    printf("La maquina pensó en un número, usted debe adivinarlo,\n");
    printf("en cada turno se le pedira ingresar un número.\n");
    printf("Si el número que ingreso es mayor al de la maquina, se le dira 'muy alto'.\n");
    printf("Si el número que ingreso es menor al de la maquina, se le dira 'muy bajo'.\n"); 
    printf("Con esta nueva información, ajuste su número adecudamente.\n");
    printf("Empecemos!! =)\n"); 
    printf("ingrese un número entre 0 y 20\n");
    scanf("%d", &numero); 
    
    i=5; //5 vidas//
    m = aleatorio(); 

while ((i>=0) && (m > numero || m < numero)) {
        if (m > numero) {
        printf("Muy bajo\n");
        printf("te quedan %d vidas\n", i);
        printf("Ingrese nuevo número entre 0 y 20\n");
        scanf("%d", &numero);
    } 
    else if (m < numero) {
        printf("Muy alto\n");
        printf("te quedan %d vidas\n", i);
        printf("Ingrese nuevo número entre 0 y 20\n");
        scanf("%d", &numero); 
    } 
    i=i-1;
    
}
    printf("¡¡¡Adivinaste!!!, el número era %d\n", m); //una vez que se rompe el ciclo es porque m == numero//
 return 0;
}