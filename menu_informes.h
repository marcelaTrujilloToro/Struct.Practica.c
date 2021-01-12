#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SALIDA 6

void menu_informe(struct Nota *arr_nota_definitiva, struct Nota *arr_nota, struct Estudiante *arr_estudiante, struct Materia *arr_materia, struct Mov_matricula *arr_matricula, struct Contador *contador)
{

    int opcion = 0;

    do
    {
        printf("\nMENU INFORMES.");
        printf("\n-------------\n");
        printf("1. Mostrar el estudiante y la materia con la nota mas alta.\n");
        printf("2. Cantidad de estudiantes que perdieron materias.\n");
        printf("3. Mostrar el estudiante con mas materias perdidas.\n");
        printf("4. Mostrar el estudiante con promedio de notas mas alto.\n");

        printf("6. Regresar al menu principal\n");

        printf("Digite una opcion:\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            calcular_nota_mas_alta(arr_nota, contador->cont_nota, arr_estudiante, contador->cont_estudiante, arr_materia, contador->cont_materia);
            break;
        case 2:
            num_est_perdieron_al_menos_una_mat(arr_nota_definitiva, arr_nota, contador->cont_nota, arr_matricula, contador->cont_matricula, arr_estudiante, contador->cont_estudiante, arr_materia, contador->cont_materia, contador);
            break;
        case 3:
            contar_estudiante_con_mas_perdidas(arr_nota, contador->cont_nota, arr_matricula, contador->cont_matricula, arr_estudiante, contador->cont_estudiante, contador, arr_nota_definitiva);
            break;
        case 4:
            mostrar_estudiante_con_promedio_mas_alto(arr_estudiante, contador->cont_estudiante, arr_nota, contador->cont_nota, arr_matricula, contador->cont_matricula, arr_nota_definitiva, *contador);
        }

    } while (opcion != SALIDA);
}