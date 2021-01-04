#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"
#include "gestion_estudiantes.h"
#include "gestion_materias.h"
#include "mov_matricula.h"
#include "menu_materia.h"
#include "menu_estudiante.h"
#include "menu_matricula.h"
#include "gestion_notas.h"
#include "menu_ingreso_nota.h"
#include "informes.h"
#include "menu_informes.h"


int main()
{
    struct Estudiante *arr_estudiante = malloc(MAX_ESTUDIANTES * sizeof(struct Estudiante));
    struct Materia *arr_materia = malloc(MAX_MATERIAS * sizeof(struct Materia));
    struct Mov_matricula *arr_matricula = malloc(MAX_MATRICULA * sizeof(struct Mov_matricula));
    struct Nota *arr_nota = malloc(MAX_NOTAS * sizeof(struct Nota));

     struct Estudiante estudiante = {
        .codigo = "1234",
        .primer_nombre = "marcela",
        .segundo_nombre = "",
        .primer_apellido = "Trujillo",
        .segundo_apellido = "Toro",
        .edad = 29,
        .estrato = 2,
        .genero = 'f'
    };
    arr_estudiante[0] = estudiante;

     struct Estudiante estudiante1 = {
        .codigo = "12345",
        .primer_nombre = "zharick",
        .segundo_nombre = "",
        .primer_apellido = "Trujillo",
        .segundo_apellido = "Toro",
        .edad = 29,
        .estrato = 2,
        .genero = 'f'
    };
    arr_estudiante[1] = estudiante1;

    struct Materia materia ={
        .codigo = "9876",
        .nombre = "programacion",
        .num_creditos = 3,
        .costo_credito = 300000
    };
    arr_materia[0] = materia;

    struct Nota nota = {
        .cod_estudiante = "1234",
        .cod_materia = "9876",
        .nota = 4
    };
    arr_nota[0] = nota;

    struct Nota nota1 = {
        .cod_estudiante = "1234",
        .cod_materia = "9876",
        .nota = 5
    };
    arr_nota[1] = nota1;

    struct Nota nota2 = {
        .cod_estudiante = "12345",
        .cod_materia = "9876",
        .nota = 1
    };
    arr_nota[2] = nota2;


    struct Contador contador = {
        .cont_estudiante = 2,
        .cont_materia = 1,
        .cont_nota = 3
    };

    num_est_perdieron_al_menos_una_mat(arr_nota, contador.cont_nota, arr_estudiante, contador.cont_estudiante, arr_materia, contador.cont_materia);

    return 0;
}
