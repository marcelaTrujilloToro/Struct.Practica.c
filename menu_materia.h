#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MATERIAS 100
#define OPCION 4

void menu_mat(struct Materia *arr_materia, struct Contador *contador)
{

    int opcion = 0;

    do
    {
        printf("\nMENU GESTION MATERIAS.");
        printf("\n----------------------\n");
        printf("1. Agregar materia\n");
        printf("2. Imprimir lista de materias\n");
        printf("3. Buscar materia por codigo\n");
        printf("4. Regresar al menu principal\n");

        printf("\nDigite una opcion.\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            validar_codigo_mat(arr_materia, contador->cont_materia);
            contador->cont_materia++;
            break;
        case 2:
            imprimir_materia(arr_materia, contador->cont_materia);
            break;
        case 3:
            buscar_mat_por_codigo(arr_materia, contador->cont_materia);
        }
    } while (opcion != OPCION);
}