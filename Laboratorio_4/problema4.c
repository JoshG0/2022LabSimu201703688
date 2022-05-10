/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc problema4.c -o problema4.out -lm
Fecha:      Sun May 8 16:41:00 CST 2022
Librerias:  stdio (u otras)
Resumen:    EL usuario ingresa dos matrices de 3X3, con estas dos matrices, 
            el programa realiza algunas operaciones como: multiplicacion por 
            una constante, suma de las matrices, resta de las mastrices, 
            multiplicaicon de matrices, el terminante, entre otras.
Entada:    
Salida:    
*/

//Librerias
#include <stdio.h>
#include <math.h>

//1.Declaración de variables
int matA[3][3], matB[3][3], cte; 
//1.1 Varialbes de operaciones
int cteA[3][3], sum[3][3], res[3][3], multi[3][3], trasB[3][3], adjA[3][3], detA;
float invA[3][3], GaussA[3][3], GaussB[3][3], guarda;
//1.2 Variables de control y conteo
int i, j, k; 

//2. Función principal
int main(){
    //Matrices A y B ingresadas por el usuario 
    puts("\n    *** Operaciones con Matrices de 3X3 ***    ");
    puts("\nIngrese los elementos para A (#fila,#columna): ");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("Ingerse %d,%d y preione enter: ",i+1,j+1);
            scanf("%d",&matA[i][j]);
        }
    }
    
    puts("\nIngrese los elementos para B (#fila,#columna): ");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("Ingerse %d,%d y preione enter: ",i+1,j+1);
            scanf("%d",&matB[i][j]);
        }
    }
    //Muestra las matrices ingresadas
    puts("\nLa matriz A es: ");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf(" %d ",matA[i][j]);
            if (j==2)
            {
                printf("\n");
            }  
        }
    }
    puts("\nLa matriz B es: ");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf(" %d ",matB[i][j]);
            if (j==2)
            {
                printf("\n");
            }  
        }
    }
    //Valor de la constante
    puts("\nIngrese el valor de la constante: ");
    scanf("%d",&cte);
    //2.1 Multiplica por una constante
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            cteA[i][j]=cte*matA[i][j];
        }
    }
        //Impresion de resultados
    printf("\nSea c=%d, la matriz A por %d es: \n",cte,cte);
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d ",cteA[i][j]);
            if (j == 2)
            {
                puts("\n"); // aquí y para los demas es un espacio entre filas
            }
        }
    }

    //2.2 Suma de matrices
    puts("\nLa suma de A y B es: ");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            sum[i][j]=matA[i][j]+matB[i][j];
        }
    }
        //Resultado de sumar 
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sum[i][j]);
            if (j == 2)
            {
                puts("\n");
            }
            
        }
    }
    
    //2.3 Resta de matrices
    puts("\nLa resta de A y B es: ");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            res[i][j]=matA[i][j]-matB[i][j];
        }
    }
        //Resultado de restar
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", res[i][j]);
            if (j == 2)
            {
                puts("\n");
            }
        }
    }

    //2.4 Multiplicación de matrices
    multi[0][0]=matA[0][0]*matB[0][0]+matA[0][1]*matB[1][0]+matA[0][2]*matB[2][0];
    multi[1][0]=matA[1][0]*matB[0][0]+matA[1][1]*matB[1][0]+matA[1][2]*matB[2][0];
    multi[2][0]=matA[2][0]*matB[0][0]+matA[2][1]*matB[1][0]+matA[2][2]*matB[2][0];
    multi[0][1]=matA[0][0]*matB[0][1]+matA[0][1]*matB[1][1]+matA[0][2]*matB[2][1];
    multi[1][1]=matA[1][0]*matB[0][1]+matA[1][1]*matB[1][1]+matA[1][2]*matB[2][1];
    multi[2][1]=matA[2][0]*matB[0][1]+matA[2][1]*matB[1][1]+matA[2][2]*matB[2][1];
    multi[0][2]=matA[0][0]*matB[0][2]+matA[0][1]*matB[1][2]+matA[0][2]*matB[2][2];
    multi[1][2]=matA[1][0]*matB[0][2]+matA[1][1]*matB[1][2]+matA[1][2]*matB[2][2];
    multi[2][2]=matA[2][0]*matB[0][2]+matA[2][1]*matB[1][2]+matA[2][2]*matB[2][2];
    // Resultado de multiplicar
    puts("\nLa multiplicaición  de A por B es: ");
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", multi[i][j]);
            if (j == 2)
            {
                puts("\n");
            }
        }
    }

    //2.5 Determinante de A
    detA = (matA[0][0]*matA[1][1]*matA[2][2]+matA[0][1]*matA[1][2]*matA[2][0]+matA[1][0]*matA[2][1]*matA[0][2])-matA[0][2]*matA[1][1]*matA[2][0]-matA[0][1]*matA[1][0]*matA[2][2]-matA[1][2]*matA[2][1]*matA[0][0];
        //Determinante 
    printf("\nEL determinante de A es: \n%d\n",detA);

    //2.6 Traspuesta de B
    puts("\nLa transpuesta de B es: ");
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            trasB[i][j] = matB[j][i];
        }
        
    }
        //impresion en consola
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", trasB[i][j]);
            if (j == 2)
            {
                puts("\n");
            }
        }
    }
    //2.7 Inversa de A
    if (detA == 0)
    {
        puts("\nLa matriz A no es invertible");
    }else
     {
        adjA[0][0]=+matA[1][1]*matA[2][2]-matA[2][1]*matA[1][2];
        adjA[1][0]=-matA[1][0]*matA[2][2]+matA[2][0]*matA[1][2];
        adjA[2][0]=+matA[1][0]*matA[2][1]-matA[2][0]*matA[1][1];
        adjA[0][1]=-matA[0][1]*matA[2][2]+matA[2][1]*matA[0][2];
        adjA[1][1]=+matA[0][0]*matA[2][2]-matA[2][0]*matA[0][2];
        adjA[2][1]=-matA[0][0]*matA[2][1]+matA[2][0]*matA[0][1];
        adjA[0][2]=+matA[0][1]*matA[1][2]-matA[1][1]*matA[0][2];
        adjA[1][2]=-matA[0][0]*matA[1][2]+matA[1][0]*matA[0][2];
        adjA[2][2]=+matA[0][0]*matA[1][1]-matA[1][0]*matA[0][1];
        for ( i=0; i<3; i++ ) {
            for ( j=0; j<3; j++ ) {
                invA[i][j]=adjA[i][j]*pow(detA,-1);
            }
        }
        //Impresion en consola
        puts("\n La inversa de A es: ");
        for ( i = 0; i < 3; j++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%.0f ",invA[i][j]);
                if (j == 2)
                {
                    puts("\n");
                } 
            }
        }
     }

    //2.8 Reducción de Gauss de A
    //2.8.1 Tomando la idea de cómo se haría a "mano" se sigue el mismo procedimietno   
    for ( i=0; i<3; i++ )
    {
        for ( j=0; j<3; j++ )
        {
            //Verdadero: definiremos la variable g=matA[i][j]/matA[j][i] y tambien se entrara a un loop.
            if ( i != j )
            {
                guarda=matA[i][j]/matA[j][i];
                //for: empezando en k=o, verificara si k<4, Verdadero: empezara a definir cada elementod de ga[i][j]=ga[i][k]=mata[i][k]-g*(mata[i][j]) y por ultimo se le aumentara a k por 1.
                for ( k=0; k<4; k++ )
                {
                    GaussA[i][k]=matA[i][k]-guarda*(matA[i][j]);
                }
            }
        }
    }
        //impresion reduccion de Gauus A
    puts("\nLa reducción de Gauss para A será: ");
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%0.f ",GaussA[i][j]);
            if (j == 2)
            {
                puts ("\n");
            }
        }
    }

    //2.9 Reducción Gauss-Jordan B
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            if ( i!=j ) {
                guarda=matB[i][j]/matB[j][i];
                for ( k=0; k<4; k++ ) {
                    GaussB[i][k]=matB[i][k]-guarda*(matB[i][j]);
                }
            }
        }
    }
    //3.9 Gauss Jordan B
    puts("\nLa reducción de Gauss-Jordan para B será: ");
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%0.f ",GaussB[i][j]);
            if (j == 2)
            {
                puts ("\n");
            }
        }
    }
    
    puts("\nFIN :)");   
}    