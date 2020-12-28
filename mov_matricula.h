#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Mov_matricula incresar_datos(struct Estudiante *arr_estudiante, int con_est, struct Materia *arr_materia, int cont_mat, struct Mov_matricula *arr_matricula, int cont_matri)
{
    struct Mov_matricula matricula;

    return matricula;
}

void crear_arr_matricula(struct Mov_matricula *arr_matricula, int cont_matri, struct Estudiante *arr_estudiante, int con_est, struct Materia *arr_materia, int cont_mat)
{
    arr_matricula[cont_matri] = incresar_datos(arr_estudiante, con_est, arr_materia, cont_mat, arr_matricula, cont_matri);
}

void agregar_matricula(struct Mov_matricula *arr_matricula, int cont_matri, struct Estudiante *arr_estudiante, int con_est, struct Materia *arr_materia, int cont_mat)
{
    crear_arr_matricula(arr_matricula, cont_matri, arr_estudiante, con_est, arr_materia, cont_mat);
}

void imprimir_matricula(struct Mov_matricula *arr_matricula, int cont_matri)
{
    for (int i = 0; i < cont_matri; i++)
    {
        printf("\nEl estudiante con codigo %s, inscribio la materia con codigo %s\n", arr_matricula[i].cod_estudiante, arr_matricula[i].cod_materia);
    }
}

int validar_codigo_de_est_y_mat(struct Mov_matricula *arr_matricula, int cont_matri, char *cod_est_ingresado, char *cod_mat_ingresado)
{
    for (int i = 0; i < cont_matri; i++)
    {
        if ((strcmp(arr_matricula[i].cod_estudiante, cod_est_ingresado) == 0) && (strcmp(arr_matricula[i].cod_materia, cod_mat_ingresado) == 0))
        {
            return 1;
        }
    }
    return 0;

    printf("cod est %s, cod_est_ingre %s, cod mat %s, cod_mat_ingre %s ", cod_est_ingresado, cod_mat_ingresado);
}

void validar_matricula(struct Mov_matricula *arr_matricula, int cont_matri, struct Estudiante *arr_estudiante, int cont_est, struct Materia *arr_materia, int cont_mat)
{

    char codigo_est[15];
    char codigo_mat[15];
    int est_encontrado = 0;
    int mat_encontrado = 0;
    int comparacion_codigos_mat_est = 0;

    printf("\nLISTADO DE ESTUDIANTES:");
    printf("\n----------------------\n");
    imprimir_estudiante(arr_estudiante, cont_est);

    printf("\nLISTADO DE MATERIAS:");
    printf("\n--------------------\n");
    imprimir_materia(arr_materia, cont_mat);

    do
    {
        printf("\nDigite el codigo del estudiante: ");
        scanf("%s", &codigo_est);
        est_encontrado = buscar_est(arr_estudiante, cont_est, codigo_est);

        printf("\nDigite el codigo de la materia: ");
        scanf("%s", &codigo_mat);
        mat_encontrado = buscar_materia(arr_materia, cont_mat, codigo_mat);

        if (est_encontrado == 1 && mat_encontrado == 1)
        {
            comparacion_codigos_mat_est = validar_codigo_de_est_y_mat(arr_matricula, cont_matri, codigo_est, codigo_mat);
        }        

    } while (comparacion_codigos_mat_est == 1);
    
    agregar_matricula(arr_matricula, cont_mat, arr_estudiante, cont_est, arr_materia, cont_mat);
    strcpy(arr_matricula[cont_matri].cod_estudiante, codigo_est);
    strcpy(arr_matricula[cont_matri].cod_materia, codigo_mat);
}
