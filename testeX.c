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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int abrirArquivo(char *palavra, int linha); //define apenas o cabeçalho da função. Sem o cabeçalho, a função deve ficar acima do main

int main()
{
    char palavraforca[50];
    int linha, i;
       scanf ("%d", &i);
       linha=(1+i); //para nome do evento
       abrirArquivo(palavraforca, linha);
       printf("%s ", palavraforca);

       linha=(7+i); //para hora do evento
       abrirArquivo(palavraforca, linha);
       printf("%s:", palavraforca);

       linha=(8+i); //para minuto do evento
       abrirArquivo(palavraforca, linha);
       printf("%s ", palavraforca);

       linha=(6+i); //para dia da semana do evento
       abrirArquivo(palavraforca, linha);
       printf("%s ", palavraforca);

       linha=(3+i); //para nome do evento
       abrirArquivo(palavraforca, linha);
       printf("%s/", palavraforca);

       linha=(4+i); //para pegar a palavra na segunda linha
       abrirArquivo(palavraforca, linha);
       printf("%s/", palavraforca);

       linha=(5+i); //para pegar a palavra na terceira linha
       abrirArquivo(palavraforca, linha);
       printf("%s\n", palavraforca);

    return 0;
}

int abrirArquivo(char *palavra, int linha)
{
    FILE *file;
    file=fopen("ArqTeste.txt", "r");
    int cont=0;
    while(cont!=linha){
        fscanf(file, "%s", palavra); //lê uma linha
        cont++;
    }

    fclose(file);
    return 0;
}