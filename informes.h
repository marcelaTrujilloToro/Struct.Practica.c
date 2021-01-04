#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Zona de definición de funciones
void obt_nombre_completo_est(struct Estudiante estudiante, char *nombre_completo);
int contar_materias_perdidas_x_est(struct Nota *arr_nota, int cont_nota, struct Estudiante estudiante);

//cuantos estudiantes perdieron al menos una materia
void num_est_perdieron_al_menos_una_mat(struct Nota *arr_nota, int cont_nota, struct Estudiante *arr_estudiante, int cont_est, struct Materia *arr_materia, int cont_mat)
{
    int contador_est_perdieron_mat = 0;

    for (int i = 0; i < cont_est; i++)
    {
        int cont_materias_perdidas = contar_materias_perdidas_x_est(arr_nota, cont_nota, arr_estudiante[i]);
        if (cont_materias_perdidas > 0)
        {
            struct Estudiante estudiante = buscar_est_por_codigo(arr_estudiante, cont_est, arr_estudiante[i].codigo);
            char nombre_completo[84];
            obt_nombre_completo_est(estudiante, nombre_completo);
            printf("\nEl estudiante %s perdio %d materias", estudiante.primer_nombre, cont_materias_perdidas);

            contador_est_perdieron_mat++;
        }
    }

    printf("\n%d estudiante(s) perdieron materias", contador_est_perdieron_mat);
}

int contar_materias_perdidas_x_est(struct Nota *arr_nota, int cont_nota, struct Estudiante estudiante)
{
    //aqui se almacenan los estudiantes y las asignaturas sin repetir la combinación estudiante/asignatura
    struct Nota *arr_asig_est_no_repetidos = malloc(MAX_NOTAS * sizeof(struct Nota));
    int cont_asig_est_no_repetidos = 0;

    //llenar nueva estructura de no repetidos con la combinación de estudiante-materia sin repetir.
    for (int i = 0; i < cont_nota; i++)
    {
        int existe_en_no_repetidos = 0;
        for (int j = 0; j < cont_asig_est_no_repetidos; j++)
        {
            if (
                strcmp(arr_nota[i].cod_estudiante, arr_asig_est_no_repetidos[j].cod_estudiante) == 0 
                && strcmp(arr_nota[i].cod_materia, arr_asig_est_no_repetidos[j].cod_materia) == 0 
                && strcmp(arr_nota[i].cod_estudiante, estudiante.codigo) == 0)
            {
                existe_en_no_repetidos = 1;
            }
        }

        if (existe_en_no_repetidos == 0 && strcmp(arr_nota[i].cod_estudiante, estudiante.codigo) == 0)
        {
            struct Nota nota;
            strcpy(nota.cod_estudiante, arr_nota[i].cod_estudiante);
            strcpy(nota.cod_materia, arr_nota[i].cod_materia);

            arr_asig_est_no_repetidos[cont_asig_est_no_repetidos] = nota;
            cont_asig_est_no_repetidos++;
        }
    }



    int cont_materias_perdidas = 0;
    //calcular la definitiva
    

    for (int i = 0; i < cont_asig_est_no_repetidos; i++)
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

    free(arr_asig_est_no_repetidos);

    return cont_materias_perdidas;
}

void obt_nombre_completo_est(struct Estudiante estudiante, char *nombre_completo)
{
    strcpy(nombre_completo, estudiante.primer_nombre);
    strcat(nombre_completo, " ");
    strcat(nombre_completo, estudiante.segundo_nombre);
    strcat(nombre_completo, " ");
    strcat(nombre_completo, estudiante.primer_apellido);
    strcat(nombre_completo, " ");
    strcat(nombre_completo, estudiante.segundo_apellido);
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

    struct Estudiante estudiante = buscar_est_por_codigo(arr_estudiante, cont_est, nota_mayor.cod_estudiante); // pendiente sacar pedir codigo de esta funcion
    struct Materia materia = buscar_mat_por_codigo(arr_materia, cont_mat);

    printf("\nEl estudiante y la materia con mayor nota es:\n");
    printf("%s %s %s %s en la materia %s con nota %.2f\n", estudiante.primer_nombre, estudiante.segundo_nombre, estudiante.primer_apellido, estudiante.segundo_apellido, materia.nombre, nota_mayor.nota);
}

float calcular_definitiva(struct Nota *arr_nota, int cont_nota, struct Estudiante *arr_estudiante, int cont_est, struct Materia *arr_materia, int cont_mat)
{

    struct Estudiante estudiante;
    struct Materia materia;

    float suma = 0;
    int contador = 0;

    estudiante = buscar_est_por_codigo(arr_estudiante, cont_est, "");
    materia = buscar_mat_por_codigo(arr_materia, cont_mat);

    for (int i = 0; i < cont_nota; i++)
    {

        if ((arr_nota[i].cod_estudiante == estudiante.codigo) && arr_nota[i].cod_materia == materia.codigo)
        {
            suma = suma + arr_nota[i].nota;
            contador++;
        }
    }

    float promedio = suma / contador;
    printf("suma : %.2f, promedio %.2f", suma, promedio);

    return 0;
}

void calcular_cuantos_est_perdieron_mat(struct Nota *arr_nota, int cont_nota)
{

    // pendiente contar estudiantes individualmente

    int contador = 0;

    for (int i = 0; i < cont_nota; i++)
    {
        if (arr_nota[i].nota < 3)
        {
            contador++;
        }
    }
    printf("\nEl total de estudiantes que perdieron materias fue: %d\n", contador);
    /*calcular_definitiva(arr_nota, cont_nota);*/
}
