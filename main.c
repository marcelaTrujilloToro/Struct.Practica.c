#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"
#include "gestion_estudiantes.h"
#include "gestion_materias.h"
#include "mov_matricula.h"
#include "menu_materia.h"
#include "menu_estudiante.h"
#include "menu_inscripcion.h"

#define MAX_ESTUDIANTES 100
#define MAX_MATERIAS 100
#define MAX_MATRICULA 1000

#define OPCION_SAL 4

int main()
{
    
    struct Contador contador;

    contador.cont_estudiante = 0;
    contador.cont_materia = 0;
    contador.cont_matricula =0 ;

    struct Estudiante *arr_estudiante = malloc(MAX_ESTUDIANTES * sizeof(struct Estudiante));

    struct Materia *arr_materia = malloc(MAX_MATERIAS * sizeof(struct Materia)); 

    struct Mov_matricula *arr_matricula = malloc(MAX_MATRICULA * sizeof(struct Mov_matricula));
 

    int opcion = 0;

    do
    {
        printf("\nMENU");
        printf("\n----\n");
        printf("1. Gestionar estudiante\n");
        printf("2. Gestionar materia\n");
        printf("3. Inscripciones\n");
        printf("4. Salir\n");

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
            menu_inscripcion(arr_matricula, arr_estudiante, arr_materia, &contador);
        }

    } while (opcion != OPCION_SAL);
}
