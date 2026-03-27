#include <stdio.h> 
#define N 2
//hecho en primer semestra 2025. 
//chequea que los vectores que ingresas son linealmente independientes o no.
//hoy, 26/03/2026 lo agrego a github y al releerlo, aspire a mucho. nisiquiera se 
//usa el teorema.O



/*SEGURAMENTE HAY UNA MANERA MUCHO MAS FACIL DE ESCRIBIR TODO ESTO*/
//inspiracion:
/* Teorema: Sea V un espacio Vectorial sobre un cuerpo K. Sea S={v1, .. ,vn} conjunto de generadores de V.
Entonces existe B en S tal que B es base de V.

Lo mas esencial del teorema es que de un conjunto de generadores puedo sacar una base. 
para que sea mas facil voy a considerar V=R²(para probar) y K=R  (esto en un futuro probablemente se pueda cambiar
y preguntar al usuario)*/

/* tenemos que resolver varios problemas: 
(-1)- que le pido al usuario?
0- definir los vectores.
1- definir que S sea un conjunto de generadores. EN PARTICULAR de R²
2- definir que es una base. -> definir que es li y definir que es que genere a R²(vuelvo a 1)
3- escribir el mecanismo de la demostracion del teorema. 
*/

/*posibles soluciones: 
(-1)- para la version uno, solo le voy a pedir un S cjto de generadores y devolver una base B 
(-0,5)- debo definir un arreglo como "sinonimo" de conjunto
0- definir un struct
1- 
2- 
3- seguro es un ciclo
*/


/* esto se resuelve facil si vamos de a partes:
en particular las funciones auxiliares estan declaradas estan en orden de resolucion =)
ayuda 1 del chat: como declarar arreglo de otro tipo.
*/


/*definicion generador(del teorico): un conjunto S en un V esp. vect. se dice generador si el subespacio generado por S es el 
conjunto de todas las combinaciones lineales de elementos de S. { a1.v1+...+anvn : ai en K y vi en S}*/

struct vectoresR2 {
    int x;
    int y;
};

struct div_t {
    int cociente;
    int resto;
};

void pide_vectores (int tam, struct vectoresR2 v[]) {
    int i;
    i=0;
    while (i<tam){
       printf("ingrese vector (¡sin parentesis! solo con coma) en la posicion %d\n", i);
       scanf("%d,%d", &v[i].x, &v[i].y); //ojo! a la notacion//
       i=i+1;
    }
}

void imprime_vectores (int tam, struct vectoresR2 v[]){
    int i;
    i=0;
    while (i<tam){
        printf("el vector en la posicion %d es (%d,%d)\n", i, v[i].x, v[i].y);
        i=i+1;
    }
}
/*no hacen falta dos distintos para cada coordenada porque estan hechos para nros arbitrarios*/
struct div_t division_primera_coordenada (int x, int y){
    int q, r;
    q=0;
    r= x;
    struct div_t cocyres_p;  //x=q*y+r;//
    while (r>=y){
        q=q+1;                 
        r=r-y;
    }
    cocyres_p.cociente = q; 
    cocyres_p.resto = r;


    return cocyres_p;
}

struct div_t division_segunda_coordenada (int x, int y){ 
    int q, r;
    q=0;
    r=x;
    struct div_t cocyres_s;  //x=q*y+r; x>y //
    while (r>=y){
        q=q+1;
        r=r-y;
    }
    cocyres_s.cociente = q; 
    cocyres_s.resto = r;
    return cocyres_s;
}

int son_multiplos (struct div_t g, struct div_t p ){
                                                     
   if (g.cociente==p.cociente && g.resto==0){
      return 1; //son multiplos//
   }
   else {
        return 2;
   }
}

void devolver_cociente (void)  {
    
}
  
int  chequeo_ceros (struct vectoresR2 v[]){  
    struct div_t n; 
    struct div_t m;
    while (v[0].x != 0 && v[0].y !=0 && v[1].x != 0 && v[1].y !=0 ){ //caso ninguno cero
       if (v[0].x >= v[1].x && v[0].y >= v[1].y) {
          n=division_primera_coordenada(v[0].x, v[1].x);
          m=division_primera_coordenada (v[0].y,v[1].y); 
          return (son_multiplos(n,m));
       } else if (v[0].x <= v[1].x && v[0].y <= v[1].y) {
          n=division_primera_coordenada(v[1].x, v[0].x);
          m=division_primera_coordenada (v[1].y,v[0].y);
          return (son_multiplos(n,m));
       } else if (v[0].x <= v[1].x && v[0].y >= v[1].y){
          n=division_primera_coordenada(v[1].x, v[0].x);
          m=division_primera_coordenada (v[0].y,v[1].y);
          return (son_multiplos(n,m));
       } else if (v[0].x >= v[1].x && v[0].y <= v[1].y) {
          n=division_primera_coordenada(v[0].x, v[1].x);
          m=division_primera_coordenada (v[1].y,v[0].y);
          return (son_multiplos(n,m));
       }
}    //seguro hay otra forma de hacerlo mas general, pero no se me ocurre//
/*SE TIENE QUE PODER MEJORAR!!*/
 if ((v[0].x != 0 && v[0].y ==0 && v[1].x == 0 && v[1].y !=0) ||(v[0].x == 0 && v[0].y !=0 && v[1].x != 0 && v[1].y ==0)) 
   { 
    //"diagonal"//
    return 2;
   } else if (v[0].x == 0 && v[0].y ==0 && v[1].x == 0 && v[1].y ==0)  { //caso todos cero//
    return 1;
   } else if (v[0].x != 0 && v[0].y ==0 && v[1].x == 0 && v[1].y ==0) { /*son las matrices elementales vistas como vectores*/
    return 1;
   } else if (v[0].x == 0 && v[0].y !=0 && v[1].x == 0 && v[1].y ==0) {
    return 1;
   } else if (v[0].x == 0 && v[0].y ==0 && v[1].x != 0 && v[1].y ==0) {
    return 1;
   } else if (v[0].x == 0 && v[0].y ==0 && v[1].x == 0 && v[1].y !=0) {
    return 1;
   } else if (v[0].x != 0 && v[0].y ==0 && v[1].x != 0 && v[1].y ==0) {
    return 1;
   } else if (v[0].x == 0 && v[0].y !=0 && v[1].x != 0 && v[1].y ==0) {
    return 1;
   } else if (v[0].x == 0 && v[0].y !=0 && v[1].x != 0 && v[1].y !=0) { //caso (a,b),(0,d) y sus variantes//
    return 2;
   } else if (v[0].x != 0 && v[0].y ==0 && v[1].x != 0 && v[1].y !=0) {
    return 2;
   } else if (v[0].x != 0 && v[0].y !=0 && v[1].x == 0 && v[1].y !=0) {
    return 2;
   } else if (v[0].x != 0 && v[0].y !=0 && v[1].x != 0 && v[1].y ==0) {
    return 2;
   } else if (v[0].x != 0 && v[0].y !=0 && v[1].x == 0 && v[1].y ==0) { //caso un vector cero y el otro no//
    return 1;
   } else if (v[0].x == 0 && v[0].y ==0 && v[1].x != 0 && v[1].y !=0){
     return 1;
   }
 return 7;
}
   

void  son_li (int tam, struct vectoresR2 v[]){
    if (tam == 2 && chequeo_ceros(v)== 1){
        printf("No son linealmente independientes\n");  //ver que uno no es multiplo del otro-> creo que es teorema//
    } else if (tam == 2 && chequeo_ceros(v)== 2) {
        printf("son linealmente independientes\n");
    }
     else if (tam == 1){
        if (v[0].x !=0 || v[0].y!=0){
              printf("es linealmente independiente\n");
        } else {
            printf("No es linealmente independiente\n");
        }
    } else if (tam >=3) {
        printf("No son l.i.\n");
    }
}


int main (void) {
    int n;
    printf("¿cual es el largo de su conjunto de vectores en R²?\n");
    scanf("%d", &n);
    struct vectoresR2 v[n];  //declaracion del arreglo de n vectores del tipo vectoresR2. Rarazo *-*//
    pide_vectores(n, v);
    son_li(n,v);

    return 0;
}
