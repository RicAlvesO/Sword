#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct dataExec
{
    int dia;
    int mes;
    int ano;
};

struct dadosUtilizador
{
    char nome[30];            // guarda o nome atribuido pelo utilizador à ação desejada
    char link[100];           // guarda o link do site fornecido pelo utilizador
    struct dataExec clg_data; // guarda a data desejada pelo utilizador para a execução da tarefa
    int diaSemana;            // guarda o dia da semana em que o utilizador deseja executar a tarefa
    int horas;                // guarda as horas fornecidas pelo utilizador
    int minutos;              // guarda os minutos fornecidos pelo utilizador
} stu_data;

void ler1()
{
    FILE *f = fopen("data.txt", "r+");
    struct dadosUtilizador testtop;
    fscanf(f, "%[^\n]\n%[^\n]\n%i\n%i\n%i\n%i\n%i\n%i\n", stu_data.nome, stu_data.link, &stu_data.clg_data.dia,
                  &stu_data.clg_data.mes, &stu_data.clg_data.ano, &stu_data.diaSemana, &stu_data.horas, &stu_data.minutos) == 8;

}

int main()
{
    ler1();
    printf("%i\n", stu_data.minutos);

    return 0;
}


" %s", str





int main()
{
    int t;
    printf ("Insira o nº a operação que pretende alterar: \n");
    scanf ("%d", &t);
    FILE * f= fopen("data.txt", "a");
    fseek (f,t*sizeof (struct dadosUtilizador),SEEK_SET);
    fread (&stu_data,sizeof(struct dadosUtilizador),1,f);
    printf ("%s,%s,%d,%d,%d,%d,%d,%d;\n",stu_data.nome, stu_data.link, stu_data.clg_data.dia, stu_data.clg_data.mes, stu_data.clg_data.ano, stu_data.diaSemana, stu_data.horas, stu_data.minutos);
    fclose (f);
    return (0);
}