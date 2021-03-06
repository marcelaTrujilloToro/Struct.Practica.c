#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void obt_nombre_completo_est(struct Estudiante estudiante, char *nombre_completo);

int validar_edad(int num)
{

    if (num >= 0 && num < 110)
    {
        return 1;
    }
    return 0;
}

int validar_estrato(int num)
{

    if (num >= 0 && num <= 6)
    {
        return 1;
    }
    return 0;
}

int validar_genero(char genero)
{
    char femenino = 'f';
    char masculino = 'm';

    if (genero == femenino || genero == masculino)
    {
        return 1;
    }
    return 0;
}

int buscar_est(struct Estudiante *arr_estudiante, int cont_est, char *busqueda)
{
    int encontrado = 0;

    for (int i = 0; i < cont_est; i++)
    {
        if (strcmp(busqueda, arr_estudiante[i].codigo) == 0)
        {
            encontrado = 1;
            break;
        }else
        {
            encontrado = 0;
        }
    }
    return encontrado;
}

struct Estudiante solicitar_datos()
{
    struct Estudiante e;

    printf("\nIngrese el primer nombre: ");
    scanf("%s", &e.primer_nombre);
    printf("\nIngrese el segundo nombre: ");
    scanf("%s", &e.segundo_nombre);
    printf("\nIngrese el primer apellido: ");
    scanf("%s", &e.primer_apellido);
    printf("\nIngrese el segundo apellido: ");
    scanf("%s", &e.segundo_apellido);

    do
    {
        printf("\nDigite la edad:");
        scanf("%d", &e.edad);
    } while (validar_edad(e.edad) == 0);

    do
    {
        printf("\nDigite el estrato:");
        scanf("%d", &e.estrato);
    } while (validar_estrato(e.estrato) == 0);

    char femenino[1] = "f";
    char masculino[1] = "m";

    do
    {
        printf("\nIngrese el genero (f o m): ");
        scanf("%s", &e.genero);
    } while (validar_genero(e.genero) == 0);

    return e;
}

void crear_arr_estudiantes(struct Estudiante *arr_estudiante, int cont_est)
{
    arr_estudiante[cont_est] = solicitar_datos();
}

void agregar_estudiante(struct Estudiante *arr_estudiante, int cont_est)
{
    crear_arr_estudiantes(arr_estudiante, cont_est);
}

void imprimir_estudiante(struct Estudiante *arr_estudiante, int cont_est)
{

    for (int i = 0; i < cont_est; i++)

    {
        printf("Estudiante: %s %s %s %s tiene codigo %s, edad %d,  estrato %d y genero %c\n", arr_estudiante[i].primer_nombre, arr_estudiante[i].segundo_nombre, arr_estudiante[i].primer_apellido, arr_estudiante[i].segundo_apellido, arr_estudiante[i].codigo, arr_estudiante[i].edad, arr_estudiante[i].estrato, arr_estudiante[i].genero);
    }
}

int calcular_suma_edad(struct Estudiante *arr_estudiante, int cont_est)
{
    int suma = 0;
    for (int i = 0; i < cont_est; i++)
    {
        suma = suma + arr_estudiante[i].edad;
    }
    printf("\nLa suma de las edades de los estudiantes es: %d", suma);
    return suma;
}

float calcular_promedio(int suma, float cant)
{
    float promedio = 0;
    promedio = suma / cant;
    return promedio;
}

void mostrar_prome_edad(struct Estudiante *arr_estudiante, int cont_est)
{
    int suma = calcular_suma_edad(arr_estudiante, cont_est);
    float promedio = calcular_promedio(suma, cont_est);
    printf("\nEl promedio de edad de los estudiantes es: %.2f", promedio);
}

void mayor_edad(struct Estudiante *arr_estudiante, int cont_est)
{
    struct Estudiante estudiante_mayor = arr_estudiante[0];

    for (int i = 1; i < cont_est; i++)
    {
        if (arr_estudiante[i].edad > estudiante_mayor.edad)
        {
            estudiante_mayor = arr_estudiante[i];
        }
    }
    char nombre_completo[84];
    obt_nombre_completo_est(estudiante_mayor, nombre_completo);
    printf("\nLa mayor edad es: %d, del estudiante: %s", estudiante_mayor.edad, nombre_completo);
}

void menor_edad(struct Estudiante *arr_estudiante, int cont_est)
{
    struct Estudiante estudiante_menor = arr_estudiante[0];

    for (int i = 1; i < cont_est; i++)
    {
        if (arr_estudiante[i].edad < estudiante_menor.edad)
        {
            estudiante_menor = arr_estudiante[i];
        }
    }
    char nombre_completo[84];
    obt_nombre_completo_est(estudiante_menor, nombre_completo);
    printf("\nLa mayor edad es: %d, del estudiante: %s", estudiante_menor.edad, nombre_completo);
}

struct Estudiante buscar_est_por_codigo(struct Estudiante *arr_estudiante, int cont_est, char *busqueda)
{
    for (int i = 0; i < cont_est; i++)
    {
        if (strcmp(busqueda, arr_estudiante[i].codigo) == 0)
        {
            return arr_estudiante[i];
        }
    }

    struct Estudiante estudiante = {
        .codigo = "-1",
    };

    return estudiante;
}

void validar_codigo(struct Estudiante *arr_estudiante, int cont_est)
{
    char codigo[15];
    int encontrado = 0;
    do
    {
        printf("\nDigite el codigo el estudiante: ");
        scanf("%s", &codigo);
        encontrado = buscar_est(arr_estudiante, cont_est, codigo);

    } while (encontrado == 1);

    if (encontrado == 0)
    {
        agregar_estudiante(arr_estudiante, cont_est);
        strcpy(arr_estudiante[cont_est].codigo, codigo);
    }
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
