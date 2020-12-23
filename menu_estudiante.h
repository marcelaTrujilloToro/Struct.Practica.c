#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ESTUDIANTES 100
#define OPCION_SALIR 8



void menu_est(struct Estudiante *arr_estudiante, struct Contador *contador)
{

    int opcion = 0;
    do
    {
        printf("\nMENU GESTION ESTUDIANTES.");
        printf("\n-------------------------\n");
        printf("1. Ingresar un estudiante\n");
        printf("2. Imprimir lista de estudiantes\n");
        printf("3. Calcular suma de las edades\n");
        printf("4. Calcular promedio de edades\n");
        printf("5. Mostrar la edad mayor\n");
        printf("6. Mostrar la edad menor\n");
        printf("7. Buscar estudiante por codigo\n");
        printf("8. Regresar al menu principal\n");

        printf("Digite una opcion:\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            validar_codigo(arr_estudiante, contador->cont_estudiante);            
            contador->cont_estudiante++;
            break;

        case 2:
            imprimir_estudiante(arr_estudiante, contador->cont_estudiante);
            break;
        case 3:
            calcular_suma_edad(arr_estudiante, contador->cont_estudiante);
            break;
        case 4:
            mostrar_prome_edad(arr_estudiante, contador->cont_estudiante);
            break;
        case 5:
            mayor_edad(arr_estudiante, contador->cont_estudiante);
            break;
        case 6:
            menor_edad(arr_estudiante, contador->cont_estudiante);
            break;
        case 7:
            buscar_est_por_codigo(arr_estudiante, contador->cont_estudiante);
        }

    } while (opcion != OPCION_SALIR);
}
