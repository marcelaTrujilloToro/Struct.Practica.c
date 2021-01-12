#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Zona de definición de funciones
//void contar_estudiante_con_mas_perdidas(struct Nota *arr_nota, int cont_nota, struct Estudiante *arr_estudiante, int cont_est, struct Contador contador);
float calcular_nota_definitiva_x_estudiante(struct Nota *arr_nota, int cont_nota, char *codigo_estudiante, char *codigo_materia);
void calcular_nota_definitiva_para_todos_los_estudiantes(struct Nota *arr_nota, int cont_nota, struct Mov_matricula *matricula, int cont_matricula, struct Nota *arr_nota_definitiva, struct Contador *contador);
void num_est_perdieron_al_menos_una_mat(struct Nota *arr_nota_definitiva, struct Nota *arr_nota, int cont_nota, struct Mov_matricula *arr_matricula, int cont_matri, struct Estudiante *arr_estudiante, int cont_est, struct Materia *arr_materia, int cont_mat, struct Contador *contador);
void contar_estudiante_con_mas_perdidas(struct Nota *arr_nota, int cont_nota, struct Mov_matricula *arr_matricula, int cont_matri, struct Estudiante *arr_estudiante, int cont_est, struct Contador *contador, struct Nota *arr_nota_definitiva);
int calcular_perdidas_x_estudiante(struct Nota *arr_nota, int cont_nota, char *codigo_estudiante, char *codigo_materia);
float calcular_promedio_x_estudiante(struct Nota *arr_nota_definitiva, int cont_nota, char *codigo_estudiante, struct Contador contador);
void mostrar_estudiante_con_promedio_mas_alto(struct Estudiante *arr_estudiante, int cont_est, struct Nota *arr_nota, int cont_nota, struct Mov_matricula *arr_matricula, int cont_matricula, struct Nota *arr_nota_definitiva, struct Contador contador);



void mostrar_estudiante_con_promedio_mas_alto(struct Estudiante *arr_estudiante, int cont_est, struct Nota *arr_nota, int cont_nota, struct Mov_matricula *arr_matricula, int cont_matricula, struct Nota *arr_nota_definitiva, struct Contador contador)
{

    struct Nota *arr_promedios = malloc(MAX_NOTAS * sizeof(struct Nota));

    float promedio = 0;
    for (int i = 0; i < contador.cont_definitivas; i++)
    {
        promedio = calcular_promedio_x_estudiante(arr_nota_definitiva, contador.cont_definitivas, arr_nota_definitiva[i].cod_estudiante, contador);
        strcpy(arr_promedios[i].cod_estudiante, arr_nota_definitiva[i].cod_estudiante);
        arr_promedios[i].nota = promedio;
    }

    struct Nota mayor_promedio = arr_promedios[0];

    for (int i = 1; i < contador.cont_definitivas; i++)
    {
        if (arr_promedios[i].nota > mayor_promedio.nota)
        {
            mayor_promedio.nota = arr_promedios[i].nota;
        }
    }
    char nombre_completo[84];
    struct Estudiante estudiante = buscar_est_por_codigo(arr_estudiante, cont_est, mayor_promedio.cod_estudiante);
    obt_nombre_completo_est(estudiante, nombre_completo);
    printf("\nEl estudiante con mayor promedio es: %s con un promedio de %.2f\n", nombre_completo, mayor_promedio.nota);

    free(arr_promedios);
}

float calcular_promedio_x_estudiante(struct Nota *arr_nota_definitiva, int cont_nota, char *codigo_estudiante, struct Contador contador)
{

    float suma_notas = 0;
    int cont_notas_x_est = 0;
    float promedio = 0;

    for (int i = 0; i < contador.cont_definitivas; i++)
    {
        if (strcmp(arr_nota_definitiva[i].cod_estudiante, codigo_estudiante) == 0)
        {
            suma_notas = suma_notas + arr_nota_definitiva[i].nota;
            cont_notas_x_est++;
        }
    }
    promedio = suma_notas / cont_notas_x_est;
    return promedio;
}

void contar_estudiante_con_mas_perdidas(struct Nota *arr_nota, int cont_nota, struct Mov_matricula *arr_matricula, int cont_matri, struct Estudiante *arr_estudiante, int cont_est, struct Contador *contador, struct Nota *arr_nota_definitiva)
{
    calcular_nota_definitiva_para_todos_los_estudiantes(arr_nota, cont_nota, arr_matricula, cont_matri, arr_nota_definitiva, contador);

    int *notas_perdidas = malloc(contador->cont_definitivas * sizeof(int));

    for (int i = 0; i < contador->cont_definitivas; i++)
    {
        notas_perdidas[i] = calcular_perdidas_x_estudiante(arr_nota, cont_nota, arr_nota[i].cod_estudiante, arr_nota[i].cod_materia);
    }

    int mayor_cant_notas_perdidas = notas_perdidas[0];
    char nombre_completo[84];

    for (int i = 1; i < contador->cont_definitivas; i++)
    {
        if (notas_perdidas[i] > mayor_cant_notas_perdidas)
        {
            mayor_cant_notas_perdidas = notas_perdidas[i];
            struct Estudiante estudiante = buscar_est_por_codigo(arr_estudiante, cont_est, arr_nota[i].cod_estudiante);
            obt_nombre_completo_est(estudiante, nombre_completo);
        }
    }
    printf("\nEl estudiante que mas materias perdio fue: %s con %d materias perdidas\n", nombre_completo, mayor_cant_notas_perdidas);

    free(notas_perdidas);
}

//cuantos estudiantes perdieron al menos una materia
void num_est_perdieron_al_menos_una_mat(struct Nota *arr_nota_definitiva, struct Nota *arr_nota, int cont_nota, struct Mov_matricula *arr_matricula, int cont_matri, struct Estudiante *arr_estudiante, int cont_est, struct Materia *arr_materia, int cont_mat, struct Contador *contador)
{
    calcular_nota_definitiva_para_todos_los_estudiantes(arr_nota, cont_nota, arr_matricula, cont_matri, arr_nota_definitiva, contador);

    int contador_est_perdieron_mat = 0;

    printf("\nEstudiantes que perdieron materias:");

    for (int i = 0; i < cont_matri; i++)
    {

        if (arr_nota_definitiva[i].nota < 3 && strcmp(arr_estudiante[i].codigo, arr_nota_definitiva[i].cod_estudiante) == 0)
        {
            struct Estudiante estudiante = buscar_est_por_codigo(arr_estudiante, cont_est, arr_estudiante[i].codigo);
            char nombre_completo[84];
            obt_nombre_completo_est(estudiante, nombre_completo);
            printf("\n%s ", nombre_completo);

            contador_est_perdieron_mat++;
        }
    }

    printf("\nEn total %d estudiante(s) perdieron materias\n", contador_est_perdieron_mat);
}

void calcular_nota_definitiva_para_todos_los_estudiantes(struct Nota *arr_nota, int cont_nota, struct Mov_matricula *matricula, int cont_matricula, struct Nota *arr_nota_definitiva, struct Contador *contador)
{

    float nota_definitiva_est = 0;
    for (int i = 0; i < cont_matricula; i++)
    {
        nota_definitiva_est = calcular_nota_definitiva_x_estudiante(arr_nota, cont_nota, matricula[i].cod_estudiante, matricula[i].cod_materia);
        strcpy(arr_nota_definitiva[i].cod_estudiante, matricula[i].cod_estudiante);
        strcpy(arr_nota_definitiva[i].cod_materia, matricula[i].cod_materia);
        arr_nota_definitiva[i].nota = nota_definitiva_est;
        contador->cont_definitivas++;
    }
}

float calcular_nota_definitiva_x_estudiante(struct Nota *arr_nota, int cont_nota, char *codigo_estudiante, char *codigo_materia)
{

    float nota_definitiva = 0;
    int cont_notas = 0;
    for (int i = 0; i < cont_nota; i++)
    {
        if (strcmp(arr_nota[i].cod_estudiante, codigo_estudiante) == 0 && strcmp(arr_nota[i].cod_materia, codigo_materia) == 0)
        {
            nota_definitiva = nota_definitiva + arr_nota[i].nota;
            cont_notas++;
        }
    }
    nota_definitiva = nota_definitiva / cont_notas;
    return nota_definitiva;
}

int calcular_perdidas_x_estudiante(struct Nota *arr_nota, int cont_nota, char *codigo_estudiante, char *codigo_materia)
{

    int contador_perdidas = 0;
    for (int i = 0; i < cont_nota; i++)
    {
        if (calcular_nota_definitiva_x_estudiante(arr_nota, cont_nota, arr_nota[i].cod_estudiante, arr_nota[i].cod_materia) < 3 && strcmp(arr_nota[i].cod_estudiante, codigo_estudiante) == 0)
        {
            contador_perdidas++;
        }
    }

    return contador_perdidas;
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