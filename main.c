#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"
#include "gestion_estudiantes.h"
#include "gestion_materias.h"
#include "mov_matricula.h"
#include "menu_materia.h"
#include "menu_estudiante.h"
#include "menu_matricula.h"
#include "gestion_notas.h"
#include "menu_ingreso_nota.h"
#include "informes.h"
#include "menu_informes.h"


int main()
{

    struct Contador contador;

    contador.cont_estudiante = 0;
    contador.cont_materia = 0;
    contador.cont_matricula = 0;
    contador.cont_nota = 0;

    struct Estudiante *arr_estudiante = malloc(MAX_ESTUDIANTES * sizeof(struct Estudiante));

    struct Materia *arr_materia = malloc(MAX_MATERIAS * sizeof(struct Materia));

    struct Mov_matricula *arr_matricula = malloc(MAX_MATRICULA * sizeof(struct Mov_matricula));

    struct Nota *arr_nota = malloc(MAX_NOTAS * sizeof(struct Nota));

    int opcion = 0;

    do
    {
        printf("\nMENU PRINCIPAL");
        printf("\n--------------\n");
        printf("1. Gestionar estudiante\n");
        printf("2. Gestionar materia\n");
        printf("3. Realizar una matricula\n");
        printf("4. Digitar nota\n");
        printf("5. Informes\n");
        printf("6. Salir\n");

        printf("Digite una opcion:\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            menu_est(arr_estudiante, &contador);
            break;
        case 2:
            menu_mat(arr_materia, &contador);
            break;
        case 3:
            menu_matricula(arr_matricula, arr_estudiante, arr_materia, &contador);
            break;
        case 4:
            menu_nota(arr_matricula, arr_nota, &contador);
            break;
        case 5:
            menu_informe(arr_nota, arr_estudiante, arr_materia, &contador);
            break;
        }

    } while (opcion != OPCION_SAL);
}
