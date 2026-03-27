#include <stdio.h>

#define N 10

//hoy es 26/03/2026.Cuando la idea de escribir esto en C se me ocurrio.

/*quiero intentar hacer el metodo de newton para encontrar raices de una funcion en C*/
/* sin chat-gpt, simplemente con lo que me dieron en analisis numerico*/
/*yo estimo que lo mas dificil va a ser lo de pedir una funcion ?*/
/*porque el algoritmo ya existe*/
//funcion: x^2 − 40x + 0.25 sacada de practico2

//Creo que funciona, probarlo ingresando x=2 o mas y con x=41 o mas. (aproximaciones de las funciones)
//yo quiero agregarle que el usuario ingrese la funcion :|  

int main (void){
    double func_r, prima, x, temp;
  	
  	int i=1;

    printf("la funcion es: x^2 − 40x + 0.25\n");
    printf("ingrese aproximacion de la raiz(con punto en vez de coma)\n");
    scanf("%lf", &x);

    func_r = x*x - 40*x + 0.25; //tiene valor de aproximacion f(x0). 
    printf("el valor de la funcion en la aproximacion es de: %lf\n", func_r);

    prima = 2*x - 40;
    printf("el valor de la primera derivada de la funcion es: %lf\n", prima);

    temp = x - func_r/prima; //primer elemento de la sucesion
    while(i<N && prima!=0){
    	func_r = temp*temp - 40*temp + 0.25;
    	prima =2*temp -40; 

    	temp = temp - func_r/prima ;
    	i=i+1;
    }
    //aproximacion?
    printf("ultimo valor de la sucesion: %lf\n", temp);

    return 0;
}
