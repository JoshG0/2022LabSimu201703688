#include <stdio.h>
#include <math.h>
//numerar los pasos del pseudocodigo

/*Declaracion de variables:
mata[3][3], matb[3][3]: arrays [3][3] de elementos enteros, formaran las matrices ingresadas por el usuario.
c: entero, constante que ingresara el usuario.
mataxc[3][3]: array [3][3] de elementos enteros, guardara el valor de la multiplicacion entre mata y la constante c.
s[3][3]: array [3][3] de elementos enteros, guardara el valor de la suma entre mata y matb.
r[3][3]: array [3][3] de elementos enteros, guardara el valor de la resta entre mata y matb.
m[3][3]: array [3][3] de elementos enteros, guardara el valor de la multiplicacion entre mata y matb.
trb[3][3]: array [3][3] de elementos enteros, guardara el valor de la transpuesta de matb.
adja[3][3]: array [3][3] de elementos enteros, guardara el valor de la matriz adjunta de mata.
deta: entero, guardara el valor de la determinante de a.
ina[3][3]: array [3][3] de elementos double, guardara el valor de la matriz inversa de mata.
i, j: apoyaran para la creacion y manejo de las matrices.
*/
int c, mata[3][3], matb[3][3];
int mataxc[3][3], s[3][3], r[3][3], m[3][3], deta, trb[3][3], adja[3][3];
double ina[3][3], x[10], ga[3][3], gb[3][3], g;
int i, j, k;
void main() {
    //Creacion de la matA.
    printf("Please enter the values for matA. \n");
    //Por medio de dos for-loops se estara trabajanda con cada elemento de los arrays, el primer for-loop sera para las filas y el segundo for-loop sera para las columnas. 
    //for: loop que empieza en i=0, verifica si i<3, Verdadero: entra a otro for, luego aumenta i por 1.
    for ( i=0; i<3; i++ ) {
        //for: loop que empieza en j=0, verifica si j<3, luego aumenta i por 1.
        for ( j=0; j<3; j++ ) {
            //Despliega pide al usuario que ingrese un valor para cada componente de la matriz matA y luego lo guarada al elemento mata[i][j].
            printf("Please enter %d%d: ", i+1,j+1);
            scanf("%d", &mata[i][j]);
        }
    }
    //Despliega: matriz matA.
    //Usando un metodo similar a lo anterior creando for-loops.
    printf("The matb is: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", mata[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    //Creacion de la matB.
    printf("Please enter the values for matB. \n");
    //Usando el mismo metodo para matA.
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf("Please enter %d%d: ", i+1,j+1);
            scanf("%d", &matb[i][j]);
        }
    }
    printf("The matB is: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", matb[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    //Pide al usuario y luego guarda la constanta a c.
    printf("Please enter a constant c: \n");
    scanf("%d", &c);
    printf("The constant c is: %d \n", c);
    //NOTA: para algunas operaciones entre matrices se tiene un patron sencillo el cual se podia hacer por medio de un for-loop pero para otras operaciones el patron era demasiado complicado y era mas sencillo ingresar los elementos de forma directa.
    //Multiplicacion matA*c:
    //Usando el metodo ya establecido, se tomara cada elemento de la matA y multiplicarlo por la constante c. Es muy similar a como se crearon las matrices pero solo cambia el segundo for-loop, luego, volviedo a utilizar el mismo metodo se desplegara el resultado de la multiplicacion guardada al array mataxc.
    printf("Matrix matAxc: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            mataxc[i][j]=c*mata[i][j];
        }
    }
    //Impresión del resultado multiplicar por una constante
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", mataxc[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    //Suma entre matA y matB.
    //Usando el metodo ya establecido, se tomara el elemento matA[i][j] y se le sumara al elemento matB[i][j]. Es muy similar a la multiplicacion, luego, volviedo a utilizar el mismo metodo se desplegara el resultado de la suma guaradada al array s[i][j].
    printf("Adition of both matrix: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            s[i][j]=mata[i][j]+matb[i][j];
        }
    }
    //Impresion de la suma 
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", s[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    //Resta entre matA y matB.
    //Usando el metodo ya establecido, se tomara el elemento matA[i][j] y se le restara al elemento matB[i][j]. Es muy similar a la suma, luego, volviedo a utilizar el mismo metodo se desplegara el resultado de la resta guaradada al array r[i][j].
    printf("Substraction of both matrix: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            r[i][j]=mata[i][j]-matb[i][j];
        }
    }
    //Impresion de resta
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", r[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    //Multiplicacion entre matA y matB.
    //Para este caso el algoritmo para obtener cada elemento de la multiplicacion es demasiado complicada y era mucho mas sencillo ingresara de forma directa cada componente, luego usando el metodo ya establecido se desplegara la multiplicacion guardada en matAxmatB.
    printf("Multiplication matAxmatB: \n");
    m[0][0]=mata[0][0]*matb[0][0]+mata[0][1]*matb[1][0]+mata[0][2]*matb[2][0];
    m[1][0]=mata[0+1][0]*matb[0][0]+mata[0+1][1]*matb[1][0]+mata[0+1][2]*matb[2][0];
    m[2][0]=mata[0+2][0]*matb[0][0]+mata[0+2][1]*matb[1][0]+mata[0+2][2]*matb[2][0];
    m[0][1]=mata[0][0]*matb[0][0+1]+mata[0][1]*matb[1][0+1]+mata[0][2]*matb[2][0+1];
    m[1][1]=mata[0+1][0]*matb[0][0+1]+mata[0+1][1]*matb[1][0+1]+mata[0+1][2]*matb[2][0+1];
    m[2][1]=mata[0+2][0]*matb[0][0+1]+mata[0+2][1]*matb[1][0+1]+mata[0+2][2]*matb[2][0+1];
    m[0][2]=mata[0][0]*matb[0][0+2]+mata[0][1]*matb[1][0+2]+mata[0][2]*matb[2][0+2];
    m[1][2]=mata[0+1][0]*matb[0][0+2]+mata[0+1][1]*matb[1][0+2]+mata[0+1][2]*matb[2][0+2];
    m[2][2]=mata[0+2][0]*matb[0][0+2]+mata[0+2][1]*matb[1][0+2]+mata[0+2][2]*matb[2][0+2];
    //impresion de la multiplicacion
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", m[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    //Determinante de matA.
    //Para este caso el algoritmo para obtener  determinante es demasiado complicada y era mucho mas sencillo ingresara de forma directa la formula, luego usando el metodo ya establecido se desplegara la determinante guardada en deta.
    printf("Determinante de matA: \n");
    deta=mata[0][0]*mata[1][1]*mata[2][2]+mata[0][1]*mata[1][2]*mata[2][0]+mata[1][0]*mata[2][1]*mata[0][2]-mata[0][2]*mata[1][1]*mata[2][0]-mata[0][1]*mata[1][0]*mata[2][2]-mata[1][2]*mata[2][1]*mata[0][0];
    //impresion de deteminante

    printf("%d \n", deta);
    //Transpuesta de matB.
    //Usando el metodo ya establecido, se tomara el elemento matB[i][j] y se cambiara por matB[j][i]. Luego, volviedo a utilizar el mismo metodo se desplegara el resultado guaradada al array trb[i][j].
    printf("Transpuesta de matB: \n");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            trb[i][j]=matb[j][i];
            }
    }
    //Impresion de traspuesta
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %d", trb[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    //Inversa de matA.
    //Para este caso el algoritmo para obtener la inversa de matA es demasiado complicada y era mucho mas sencillo ingresara de forma directa cada elemento, luego usando el metodo ya establecido se desplegara la matriz inversa guardada en ina.
    printf("Inverse de matA: \n");
    if ( deta==0 ) {
        printf("The matrix matA does not have an inverse \n");
    }
    else {
        adja[0][0]=+mata[1][1]*mata[2][2]-mata[2][1]*mata[1][2];
        adja[1][0]=-mata[1][0]*mata[2][2]+mata[2][0]*mata[1][2];
        adja[2][0]=+mata[1][0]*mata[2][1]-mata[2][0]*mata[1][1];
        adja[0][1]=-mata[0][1]*mata[2][2]+mata[2][1]*mata[0][2];
        adja[1][1]=+mata[0][0]*mata[2][2]-mata[2][0]*mata[0][2];
        adja[2][1]=-mata[0][0]*mata[2][1]+mata[2][0]*mata[0][1];
        adja[0][2]=+mata[0][1]*mata[1][2]-mata[1][1]*mata[0][2];
        adja[1][2]=-mata[0][0]*mata[1][2]+mata[1][0]*mata[0][2];
        adja[2][2]=+mata[0][0]*mata[1][1]-mata[1][0]*mata[0][1];
        for ( i=0; i<3; i++ ) {
            for ( j=0; j<3; j++ ) {
                ina[i][j]=adja[i][j]*pow(deta,-1);
            }
        }
        //
        //impresion de datos 
        for ( i=0; i<3; i++ ) {
            for ( j=0; j<3; j++ ) {
                printf(" %f", ina[i][j]);
                if ( j==2 ) {
                    printf("\n");
                }
            }
        }
    }
    //Reduccion Gauss-Jordan para matriz A.
    printf("The Gauss-Jordan reduction of matA is: \n");
    //Usando el metodo ya establecido estara comprobando por medio de un if cada elementod de la matA.
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            //if: verifica si i!=j, Verdadero: definiremos la variable g=mata[i][j]/mata[j][i] y tambien se entrara a un for loop.
            if ( i!=j ) {
                g=mata[i][j]/mata[j][i];
                //for: empezando en k=o, verificara si k<4, Verdadero: empezara a definir cada elementod de ga[i][j]=ga[i][k]=mata[i][k]-g*(mata[i][j]) y por ultimo se le aumentara a k por 1.
                for ( k=0; k<4; k++ ) {
                    ga[i][k]=mata[i][k]-g*(mata[i][j]);
                }
            }
        }
    }
    //Usando el metodo ya establecido se desplegara el resultado de la reduccion Gauss-Jordan para matriz A.
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %f", ga[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    //Reduccion Gauss-Jordan para matriz B.
    printf("The Gauss-Jordan reduction of matB is: \n");
    //Similar al anterior.
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            if ( i!=j ) {
                g=matb[i][j]/matb[j][i];
                for ( k=0; k<4; k++ ) {
                    gb[i][k]=matb[i][k]-g*(matb[i][j]);
                }
            }
        }
    }
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            printf(" %f", gb[i][j]);
            if ( j==2 ) {
                printf("\n");
            }
        }
    }
    printf("END \n");
}