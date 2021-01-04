#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SALIDA 5

void menu_informe(struct Nota *arr_nota, struct Estudiante *arr_estudiante, struct Materia *arr_materia, struct Contador *contador)
{

    int opcion = 0;

    do
    {
        printf("\nMENU INFORMES.");
        printf("\n-------------\n");
        printf("1. Mostrar el estudiante y la materia con la nota mas alta.\n");
        printf("2. Cantidad de estudiantes que perdieron materias.\n");
        
        printf("5. Regresar al menu principal\n");

        printf("Digite una opcion:\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            calcular_nota_mas_alta(arr_nota, contador->cont_nota, arr_estudiante, contador->cont_estudiante, arr_materia, contador->cont_materia);
            break;
        case 2:
            calcular_definitiva(arr_nota, contador->cont_nota, arr_estudiante, contador->cont_estudiante, arr_materia, contador->cont_materia);
            break;
        case 3:
            num_est_perdieron_al_menos_una_mat(arr_nota, contador->cont_nota, arr_estudiante, contador->cont_estudiante, arr_materia, contador->cont_materia);
        }

    } while (opcion != SALIDA);
}