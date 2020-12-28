#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOTA 10000
#define OPC_SALIDA 3

void menu_nota(struct Mov_matricula *arr_matricula, struct Nota *arr_nota, struct Contador *contador)
{

    int opcion = 0;

    do
    {
        printf("\nMENU DE NOTAS.");
        printf("\n-------------------\n");
        printf("1. Digitar una nota.\n");
        printf("2. Imprimir lista de notas.\n");
        printf("3. Regresar al menu principal\n");

        printf("Digite una opcion:\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            validar_ingreso_nota(arr_matricula, contador->cont_matricula, arr_nota, contador->cont_nota);
            contador->cont_nota++;
            break;
        case 2:
            imprimir_nota(arr_nota, contador->cont_nota);
            break;
        }

    } while (opcion != OPC_SALIDA);
}