#include <stdio.h> 
#include <stdlib.h> //para el random//
#include <time.h>  //para que el random no sea siempre el mismo, incluye el tiempo de la maquina//

//pretty proud of this one, not gonna lie. 
//hecho en el primer semestre de 2025/

//version dos donde hay vidas y niveles//

int aleatoriofacil (void) {
    int x;

    srand(time(NULL));  //"semilla" que agarra el rand()//
    x = rand() % 21; //me da numero aleatorio entre los restos de 21 que son justamente nros entre 0 y 20//  
    
    return x;
}

int aleatoriomedio (void) {
    int x;

    srand(time(NULL));  
    x = rand() % 101; //me da numero aleatorio entre los restos de 101 que son justamente nros entre 0 y 100//  
    
    return x;
}

int aleatoriodificil (void) {
    int x;

    srand(time(NULL));  //"semilla" que agarra el rand()//
    x = rand() % 1001; //me da numero aleatorio entre los restos de 1001 que son justamente nros entre 0 y 1000//  
    
    return x;
}

int bajo_alto (int i, int m, int numero, int num) {
    while (i>0) {
      if (m == numero){ //tiene que ir primero porque si llega a ser true pero esta ultimo -> no me lo toma. (por como funciona el while)//
            return 1; //no sabia que se podia hacer esto, el numero se adivino, se termina el programa.//
        }
        else if (m > numero) {
        printf("Muy bajo\n");
        printf("te quedan %d vidas\n", i);
        printf("Ingresa nuevo número entre 0 y %d\n", num);
        scanf("%d", &numero);
    } 
    else if (m < numero) {
        printf("Muy alto\n");
        printf("te quedan %d vidas\n", i);
        printf("Ingresa nuevo número entre 0 y %d\n", num);
        scanf("%d", &numero); 
    } 
    i=i-1;
    }
    return 0;
}

int respuesta (int a, int b) {
    if (a==0){
        printf("Perdiste =( =(, el número era %d\n", b);
    } else if (a==1){
        printf("¡¡¡Adivinaste!!! =) =), el número era %d\n", b);
    }
 return 0;
}

void niveles (void) {
    char c;
    int n, i, l, f;
    printf("Elija su nivel de dificultad ingresando la letra correspondiente\n");
    printf("F - Nivel Facil, tendrá 5 vidas\n");
    printf("M - Nivel Medio, tendrá 10 vidas\n");
    printf("D - Nivel Dificil, tendrá 15 vidas\n");
    scanf(" %c", &c); //espacio para que tome el salto//

    if (c == 'F') { //igualdad dde char//
        printf("ingrese un número entre 0 y 20\n");
        scanf("%d", &n);
        i=5; 
        f = aleatoriofacil();
        l = bajo_alto (i, f, n, 20);
        respuesta(l,f);
    } else if (c== 'M') {
        printf("ingrese un número entre 0 y 100\n");
        scanf("%d", &n);
        i=10;
        f = aleatoriomedio();
        l = bajo_alto (i, f, n, 100);
        respuesta(l,f);
    } else if (c=='D') {
        printf("ingrese un número entre 0 y 1000\n");
        scanf("%d", &n);
        i=15;
        f = aleatoriodificil();
        l = bajo_alto (i, f, n, 1000);
        respuesta(l,f);
    }
 


}


int  main (void) {
    char c;
    printf("La maquina pensó en un número, usted debe adivinarlo,\n");
    printf("en cada turno se le pedira ingresar un número.\n");
    printf("Si el número que ingreso es mayor al de la maquina, se le dira 'muy alto'.\n");
    printf("Si el número que ingreso es menor al de la maquina, se le dira 'muy bajo'.\n"); 
    printf("Con esta nueva información, ajuste su número adecudamente.\n");
    printf("Empecemos!! =)\n"); 
    niveles();
    
    printf("¿Queres jugar otro juego?\n"); //nuevo 12-05-2025
    printf("si continuar jugando, ingrese 'Y'\n");
    printf("si no quiere jugar mas, ingrese'N'\n");
    scanf(" %c", &c); 

     if (c =='Y') {
             niveles ();
     } else {
        printf("gracias por jugar!! =)\n");
     }  


  return 0;
}

//version 3: algoritmo de busqueda binaria//
