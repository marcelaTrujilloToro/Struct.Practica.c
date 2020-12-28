#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MATRICULA 1000
#define OPCION_SALIDA 3

void menu_matricula( struct Mov_matricula *arr_matricula,  struct Estudiante *arr_estudiante, struct Materia *arr_materia, struct Contador *contador)
{      
    int opcion = 0;

    do
    {
        printf("\nMENU MATRICULA.");
        printf("\n----------------\n");
        printf("1. Realizar una matricula.\n");
        printf("2. Imprimir lista de matriculas.\n");
        printf("3. Regresar al menu principal\n");

        printf("Digite una opcion:\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            validar_matricula(arr_matricula, contador->cont_matricula, arr_estudiante, contador->cont_estudiante, arr_materia, contador->cont_materia);
            contador->cont_matricula++;
            break;
        case 2:
            imprimir_matricula(arr_matricula, contador->cont_matricula);
            break;
        }

    } while (opcion != OPCION_SALIDA);
}