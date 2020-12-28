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

int buscar_materia(struct Materia *arr_materia, int cont_mat, char *codigo){
    int encontrado = 0;
    for (int i = 0; i < cont_mat; i++)
    {
        if (strcmp(codigo, arr_materia[i].codigo) == 0)
        {
            encontrado = 1;
            break;
        }
        encontrado = 0;               
    }    
    return encontrado;
    printf("encontrado en buscar materia: ", encontrado);
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

void agregar_materia(struct Materia *arr_materia, int cont_mat){
    crear_arreglo_materias(arr_materia, cont_mat);
}

void imprimir_materia(struct Materia *arr_materia, int cont_mat){
    for (int i = 0; i < cont_mat ; i++)
    {
        printf("Materia: %s, codigo: %s, numero creditos: %d, costo por creditos: %d\n", arr_materia[i].nombre, arr_materia[i].codigo, arr_materia[i].num_creditos, arr_materia[i].costo_credito);
    }   
}

void buscar_mat_por_codigo(struct Materia *arr_materia, int cont_mat){
    printf("\n Digite el codigo de la materia a buscar:");
    char busqueda[15];
    scanf("%s", &busqueda);
    if (buscar_materia(arr_materia, cont_mat, busqueda) == 1)
    {
        printf("\nEste codigo %s ya existe.\n", busqueda);
    }else
    {
        printf("\nEste codigo: %s no existe.\n", busqueda);
    }
    
    
}

void validar_codigo_mat(struct Materia *arr_materia, int cont_mat){
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

