#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Zona de definición de funciones
int contar_materias_perdidas_x_est(struct Nota *arr_nota, int cont_nota, struct Estudiante estudiante, struct Contador *contador);
struct Nota crear_nueva_struct_no_repetidos(struct Nota *arr_nota, struct Nota *arr_asig_est_no_repetidos, int cont_nota, struct Estudiante estudiante, struct Contador *contador);
void contar_estudiante_con_mas_perdidas(struct Nota *arr_nota, int cont_nota, struct Estudiante *arr_estudiante, int cont_est, struct Contador contador);

void contar_estudiante_con_mas_perdidas(struct Nota *arr_nota, int cont_nota, struct Estudiante *arr_estudiante, int cont_est, struct Contador contador)
{
    int *notas_perdidas = malloc(cont_nota *sizeof(int));

    char nombre_completo[84];

    for (int i = 0; i < cont_nota; i++)
    {
        notas_perdidas[i] = contar_materias_perdidas_x_est(arr_nota, cont_nota, arr_estudiante[i], &contador);
    }

    int mayor_cant_notas_perdidas = notas_perdidas[0];
    for (int i = 1; i < cont_est; i++)
    {
        if (notas_perdidas[i] > mayor_cant_notas_perdidas)
        {
            mayor_cant_notas_perdidas = notas_perdidas[i];
            struct Estudiante estudiante = buscar_est_por_codigo(arr_estudiante, cont_est, arr_estudiante[i].codigo);
            obt_nombre_completo_est(estudiante, nombre_completo);
        }
    }
    printf("El estudiante que mas materias perdio fue: %s con %d materias perdidas", nombre_completo, mayor_cant_notas_perdidas);
}

//cuantos estudiantes perdieron al menos una materia
void num_est_perdieron_al_menos_una_mat(struct Nota *arr_nota, int cont_nota, struct Estudiante *arr_estudiante, int cont_est, struct Materia *arr_materia, int cont_mat, struct Contador contador)
{
    int contador_est_perdieron_mat = 0;

    for (int i = 0; i < cont_est; i++)
    {
        int cont_materias_perdidas = contar_materias_perdidas_x_est(arr_nota, cont_nota, arr_estudiante[i], &contador);
        if (cont_materias_perdidas > 0)
        {
            struct Estudiante estudiante = buscar_est_por_codigo(arr_estudiante, cont_est, arr_estudiante[i].codigo);
            char nombre_completo[84];
            obt_nombre_completo_est(estudiante, nombre_completo);
            printf("\nEl estudiante %s perdio %d materias", nombre_completo, cont_materias_perdidas);

            contador_est_perdieron_mat++;
        }
    }

    printf("\n%d estudiante(s) perdieron materias\n", contador_est_perdieron_mat);
}

struct Nota crear_nueva_struct_no_repetidos(struct Nota *arr_nota, struct Nota *arr_asig_est_no_repetidos, int cont_nota, struct Estudiante estudiante, struct Contador *contador)
{
    //llenar nueva estructura de no repetidos con la combinación de estudiante-materia sin repetir.

    for (int i = 0; i < cont_nota; i++)
    {
        int existe_en_no_repetidos = 0;
        for (int j = 0; j < contador->cont_asig_est_no_repetidos; j++)
        {

            if (
                strcmp(arr_nota[i].cod_estudiante, arr_asig_est_no_repetidos[j].cod_estudiante) == 0 && strcmp(arr_nota[i].cod_materia, arr_asig_est_no_repetidos[j].cod_materia) == 0 && strcmp(arr_nota[i].cod_estudiante, estudiante.codigo) == 0)

            {
                existe_en_no_repetidos = 1;
            }
        }

        if (existe_en_no_repetidos == 0 && strcmp(arr_nota[i].cod_estudiante, estudiante.codigo) == 0)
        {

            struct Nota nota;
            strcpy(nota.cod_estudiante, arr_nota[i].cod_estudiante);
            strcpy(nota.cod_materia, arr_nota[i].cod_materia);

            arr_asig_est_no_repetidos[contador->cont_asig_est_no_repetidos] = nota;
            contador->cont_asig_est_no_repetidos++;
        }
    }
}

int contar_materias_perdidas_x_est(struct Nota *arr_nota, int cont_nota, struct Estudiante estudiante, struct Contador *contador)
{
    int cont_materias_perdidas = 0;
    //calcular la definitiva
    struct Nota *arr_asig_est_no_repetidos = malloc(MAX_NOTAS * sizeof(struct Nota));

    crear_nueva_struct_no_repetidos(arr_nota, arr_asig_est_no_repetidos, cont_nota, estudiante, contador);

    for (int i = 0; i < contador->cont_asig_est_no_repetidos; i++)
    {

        float nota_definitiva_i = 0;
        int cont_notas_materia = 0;
        for (int j = 0; j < cont_nota; j++)
        {
            if (strcmp(arr_nota[j].cod_materia, arr_asig_est_no_repetidos[i].cod_materia) == 0 && strcmp(arr_nota[j].cod_estudiante, arr_asig_est_no_repetidos[i].cod_estudiante) == 0)
            {
                nota_definitiva_i = nota_definitiva_i + arr_nota[j].nota;
                cont_notas_materia++;
            }
        }

        nota_definitiva_i = nota_definitiva_i / cont_notas_materia;

        if (nota_definitiva_i < 3)
        {
            cont_materias_perdidas++;
        }
    }

    return cont_materias_perdidas;

    free(arr_asig_est_no_repetidos);
}

void calcular_nota_mas_alta(struct Nota *arr_nota, int cont_nota, struct Estudiante *arr_estudiante, int cont_est, struct Materia *arr_materia, int cont_mat)
{
    struct Nota nota_mayor = arr_nota[0];
    for (int i = 1; i < cont_nota; i++)
    {
        if (arr_nota[i].nota > nota_mayor.nota)
        {
            nota_mayor = arr_nota[i];
        }
    }

    struct Estudiante estudiante = buscar_est_por_codigo(arr_estudiante, cont_est, nota_mayor.cod_estudiante);
    struct Materia materia = buscar_mat_por_codigo(arr_materia, cont_mat, nota_mayor.cod_materia);

    printf("\nEl estudiante y la materia con mayor nota es:\n");
    char nombre_completo[84];
    obt_nombre_completo_est(estudiante, nombre_completo);
    printf("\n%s  en la materia %s con nota %.2f\n", nombre_completo, materia.nombre, nota_mayor.nota);
}
