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
    struct Nota *arr_asig_est_no_repetidos = malloc(MAX_NOTAS * sizeof(struct Nota));

    struct Estudiante estudiante = {
        .codigo = "1234",
        .primer_nombre = "marcela",
        .segundo_nombre = "",
        .primer_apellido = "Trujillo",
        .segundo_apellido = "Toro",
        .edad = 29,
        .estrato = 2,
        .genero = 'f'};
    arr_estudiante[0] = estudiante;

    struct Estudiante estudiante1 = {
        .codigo = "12345",
        .primer_nombre = "zharick",
        .segundo_nombre = "",
        .primer_apellido = "Trujillo",
        .segundo_apellido = "Toro",
        .edad = 29,
        .estrato = 2,
        .genero = 'f'};
    arr_estudiante[1] = estudiante1;

    struct Estudiante estudiante2 = {
        .codigo = "123456",
        .primer_nombre = "idalys",
        .segundo_nombre = "Del carmen",
        .primer_apellido = "Farias",
        .segundo_apellido = "Mendoza",
        .edad = 32,
        .estrato = 3,
        .genero = 'f'};
    arr_estudiante[2] = estudiante2;

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

    struct Nota perdida1 = {
        .cod_estudiante = "12345",
        .cod_materia = "9876"};
    arr_asig_est_no_repetidos[0] = perdida1;

    struct Nota perdida2 = {
        .cod_estudiante = "123456",
        .cod_materia = "9876"};
    arr_asig_est_no_repetidos[1] = perdida2;

    struct Nota perdida3 = {
        .cod_estudiante = "123456",
        .cod_materia = "98765"};
    arr_asig_est_no_repetidos[2] = perdida3;

    struct Contador contador = {
        .cont_estudiante = 3,
        .cont_materia = 2,
        .cont_nota = 5,
        .cont_asig_est_no_repetidos = 3};

    num_est_perdieron_al_menos_una_mat(arr_nota, contador.cont_nota, arr_estudiante, contador.cont_estudiante, arr_materia, contador.cont_materia, contador);
    contar_estudiante_con_mas_perdidas(arr_nota, contador.cont_nota, arr_estudiante, contador.cont_estudiante, contador);
    return 0;
}
