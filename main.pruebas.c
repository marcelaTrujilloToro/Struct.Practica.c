#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"
#include "gestion_estudiantes.h"
#include "gestion_materias.h"
#include "gestion_matricula.h"
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
    struct Nota *arr_nota_definitva = malloc(MAX_NOTAS * sizeof(struct Nota));

    //estudiantes
    struct Estudiante estudiante = {
        .codigo = "1234",
        .primer_nombre = "Marcela",
        .segundo_nombre = "",
        .primer_apellido = "Trujillo",
        .segundo_apellido = "Toro",
        .edad = 29,
        .estrato = 2,
        .genero = 'f'};
    arr_estudiante[0] = estudiante;

    struct Estudiante estudiante1 = {
        .codigo = "12345",
        .primer_nombre = "Zharick",
        .segundo_nombre = "",
        .primer_apellido = "Trujillo",
        .segundo_apellido = "Toro",
        .edad = 29,
        .estrato = 2,
        .genero = 'f'};
    arr_estudiante[1] = estudiante1;

    struct Estudiante estudiante2 = {
        .codigo = "123456",
        .primer_nombre = "Idalys",
        .segundo_nombre = "Del Carmen",
        .primer_apellido = "Farias",
        .segundo_apellido = "Mendoza",
        .edad = 32,
        .estrato = 3,
        .genero = 'f'};
    arr_estudiante[2] = estudiante2;

    struct Estudiante estudiante3 = {
        .codigo = "1234567",
        .primer_nombre = "Pepito",
        .segundo_nombre = "",
        .primer_apellido = "Perez",
        .segundo_apellido = "",
        .edad = 37,
        .estrato = 5,
        .genero = 'm'};
    arr_estudiante[3] = estudiante3;

    //matriculas
    struct Materia materia = {
        .codigo = "9876",
        .nombre = "programacion",
        .num_creditos = 3,
        .costo_credito = 300000};
    arr_materia[0] = materia;

    struct Materia materia1 = {
        .codigo = "98765",
        .nombre = "bases",
        .num_creditos = 3,
        .costo_credito = 300000};
    arr_materia[1] = materia1;

    //matriculas
    struct Mov_matricula matricula1 =
        {
            .cod_estudiante = "1234",
            .cod_materia = "9876",
        };
    arr_matricula[0] = matricula1;

    struct Mov_matricula matricula2 =
        {
            .cod_estudiante = "12345",
            .cod_materia = "9876"};
    arr_matricula[1] = matricula2;

    struct Mov_matricula matricula3 =
        {
            .cod_estudiante = "123456",
            .cod_materia = "9876"};
    arr_matricula[2] = matricula3;

    struct Mov_matricula matricula4 =
        {
            .cod_estudiante = "123456",
            .cod_materia = "98765",
        };
    arr_matricula[3] = matricula4;

    struct Mov_matricula matricula5 =
        {
            .cod_estudiante = "1234567",
            .cod_materia = "98765",
        };
    arr_matricula[4] = matricula5;

    // notas
    struct Nota nota = {
        .cod_estudiante = "1234",
        .cod_materia = "9876",
        .nota = 4};
    arr_nota[0] = nota;

    struct Nota nota1 = {
        .cod_estudiante = "1234",
        .cod_materia = "9876",
        .nota = 5};
    arr_nota[1] = nota1;

    struct Nota nota2 = {
        .cod_estudiante = "12345",
        .cod_materia = "9876",
        .nota = 1};
    arr_nota[2] = nota2;

    struct Nota nota3 = {
        .cod_estudiante = "123456",
        .cod_materia = "9876",
        .nota = 2};
    arr_nota[3] = nota3;

    struct Nota nota4 = {
        .cod_estudiante = "123456",
        .cod_materia = "98765",
        .nota = 2};
    arr_nota[4] = nota4;

    struct Nota nota5 = {
        .cod_estudiante = "1234567",
        .cod_materia = "98765",
        .nota = 5};
    arr_nota[5] = nota5;

    //contador
    struct Contador contador =
        {
            .cont_estudiante = 4,
            .cont_materia = 2,
            .cont_nota = 6,
            .cont_matricula = 5};

    num_est_perdieron_al_menos_una_mat(arr_nota_definitva, arr_nota, contador.cont_nota, arr_matricula, contador.cont_matricula, arr_estudiante, contador.cont_estudiante, arr_materia, contador.cont_materia, &contador);

    contar_estudiante_con_mas_perdidas(arr_nota, contador.cont_nota, arr_matricula, contador.cont_matricula, arr_estudiante, contador.cont_estudiante, &contador, arr_nota_definitva);

    mostrar_estudiante_con_promedio_mas_alto(arr_estudiante, contador.cont_estudiante, arr_nota, contador.cont_nota, arr_matricula, contador.cont_matricula, arr_nota_definitva, contador);

    calcular_prom_mas_alto_entre_hombres_y_mujeres(arr_estudiante, contador.cont_estudiante, arr_nota_definitva, contador);

    free(arr_estudiante);
    free(arr_materia);
    free(arr_matricula);
    free(arr_nota);
    free(arr_nota_definitva);

    return 0;
}
