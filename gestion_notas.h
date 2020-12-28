#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validar_nota(float nota)
{
    if (nota >= 0 && nota <= 5)
    {
        return 1;
    }
    return 0;
}

struct Nota ingresar_nota(struct Nota *arr_nota, int cont_nota)
{
    struct Nota nota;

    do
    {
        printf("\nDigite la nota: ");
        scanf("%f", &nota.nota);
    } while (validar_nota(nota.nota) == 0);

    return nota;
};

void crear_arr_nota(struct Nota *arr_nota, int cont_nota)
{
    arr_nota[cont_nota] = ingresar_nota(arr_nota, cont_nota);
}

void agregar_nota(struct Nota *arr_nota, int cont_nota)
{
    crear_arr_nota(arr_nota, cont_nota);
}

void imprimir_nota(struct Nota *arr_nota, int cont_nota)
{
    for (int i = 0; i < cont_nota; i++)
    {
        printf("\nEl estudiante: %s en la materia: %s, tiene una nota de %.2f", arr_nota[i].cod_estudiante, arr_nota[i].cod_materia, arr_nota[i].nota);
    }    
}

void validar_ingreso_nota(struct Mov_matricula *arr_matricula, int cont_matricula, struct Nota *arr_nota, int cont_nota)
{
    char codigo_est[15];
    char codigo_mat[15];
    int busqueda_matricula = 0;

    printf("\nLISTADO DE MATRICULAS EXISTENTES:");
    printf("\n----------------------\n");
    imprimir_matricula(arr_matricula, cont_matricula);

    do
    {
        printf("\nDigite el codigo del estudiante: ");
        scanf("%s", &codigo_est);

        printf("\nDigite el codigo de la materia: ");
        scanf("%s", &codigo_mat);

        busqueda_matricula = validar_codigo_de_est_y_mat(arr_matricula, cont_matricula, codigo_est, codigo_mat);

    } while (busqueda_matricula == 0);

    agregar_nota(arr_nota, cont_nota);
    strcpy(arr_nota[cont_nota].cod_estudiante, codigo_est);
    strcpy(arr_nota[cont_nota].cod_materia, codigo_mat);
}