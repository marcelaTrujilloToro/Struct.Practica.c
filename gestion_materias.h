#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validar_creditos(int num)
{
    if (num >= 0 && num <= 20)
    {
        return 1;
    }
    return 0;
}

int validar_costo_cred(int num)
{
    if (num > 0)
    {
        return 1;
    }
    return 0;
}

int buscar_materia(struct Materia *arr_materia, int cont_mat, char *codigo)
{
    int encontrado = 0;
    for (int i = 0; i < cont_mat; i++)
    {
        if (strcmp(codigo, arr_materia[i].codigo) == 0)
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

struct Materia crear_materia()
{
    struct Materia m;

    printf("\nIngrese el nombre de la materia:");
    scanf("%s", &m.nombre);

    do
    {
        printf("\nIngrese el numero de creditos de la materia:");
        scanf("%d", &m.num_creditos);
    } while (validar_creditos(m.num_creditos) == 0);

    do
    {
        printf("\nIngrese el costo por credito de la materia:");
        scanf("%d", &m.costo_credito);
    } while (validar_costo_cred(m.costo_credito) == 0);

    return m;
}

void crear_arreglo_materias(struct Materia *arr_materia, int cont_mat)
{
    arr_materia[cont_mat] = crear_materia();
}

void agregar_materia(struct Materia *arr_materia, int cont_mat)
{
    crear_arreglo_materias(arr_materia, cont_mat);
}

void imprimir_materia(struct Materia *arr_materia, int cont_mat)
{
    for (int i = 0; i < cont_mat; i++)
    {
        printf("Materia: %s, codigo: %s, numero creditos: %d, costo por creditos: %d\n", arr_materia[i].nombre, arr_materia[i].codigo, arr_materia[i].num_creditos, arr_materia[i].costo_credito);
    }
}

struct Materia buscar_mat_por_codigo(struct Materia *arr_materia, int cont_mat, char *busqueda)
{

    for (int i = 0; i < cont_mat; i++)
    {
        if (strcmp(busqueda, arr_materia[i].codigo) == 0)
        {
            return arr_materia[i];
        }
    }
    struct Materia materia = {
        .codigo = "-1",
    };

    return materia;
}

void validar_codigo_mat(struct Materia *arr_materia, int cont_mat)
{
    char codigo[15];
    int encontrado = 0;
    do
    {
        printf("\nDigite el codigo de la materia: ");
        scanf("%s", &codigo);
        encontrado = buscar_materia(arr_materia, cont_mat, codigo);
    } while (encontrado == 1);

    if (encontrado == 0)
    {
        agregar_materia(arr_materia, cont_mat);
        strcpy(arr_materia[cont_mat].codigo, codigo);
    }
}
