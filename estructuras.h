#include <stdlib.h>

struct Estudiante
{
    char primer_nombre[20];
    char segundo_nombre[20];
    char primer_apellido[20];
    char segundo_apellido[20];
    char codigo[15];
    int edad;
    int estrato;
    char genero;
};

struct Materia
{
    char codigo[15];
    char nombre[35];
    int num_creditos;
    int costo_credito;
};

struct Mov_matricula
{
    char cod_estudiante[15];
    char cod_materia[15];
};

struct Contador
{
    int cont_estudiante;
    int cont_materia;
    int cont_matricula;
    int cont_nota;
    int cont_definitivas;
};

struct Nota
{
    char cod_estudiante[15];
    char cod_materia[15];
    float nota;
    
};

#define MAX_ESTUDIANTES 100
#define MAX_MATERIAS 100
#define MAX_MATRICULA 1000
#define MAX_NOTAS 10000

#define OPCION_SAL 6
