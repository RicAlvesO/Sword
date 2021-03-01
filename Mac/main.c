#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

struct dataExec {
    int dia;
    int mes;
    int ano;
};

struct dadosUtilizador {
    char nome[100]; 
    char link[100]; 
    struct dataExec clg_data; 
    int diaSemana; 
    int horas; 
    int minutos; 
}stu_data;

struct dadosUtilizador nextEvent;
char browser[20] = "open ";

void ler(void)
{
    FILE *f = fopen("data.txt", "r+");
    fscanf(f, "%[^\n]\n%[^\n]\n%i\n%i\n%i\n%i\n%i\n%i\n", nextEvent.nome, nextEvent.link, &nextEvent.clg_data.dia,
           &nextEvent.clg_data.mes, &nextEvent.clg_data.ano, &nextEvent.diaSemana, &nextEvent.horas, &nextEvent.minutos) == 8;
    fclose(f);
}

int contaEventos()
{
    int line = 1;
    char c = ' ';
    FILE *ficheiro = fopen("data.txt", "r");

    while (c != EOF)
    {
        c = getc(ficheiro);
        if (c != EOF)
        {
            if (c == '\n')
            {
                line++;
            }
        }
    }
    line = (line / 8);
    fclose(ficheiro);

    return line;
}

void removes(int del_line)
{
    FILE *f1, *f2, *f3;
    int aux = 1;
    char c;
    int verf = 0;
    f1 = fopen("data.txt", "r");
    f2 = fopen("copy.txt", "a");
    c = ' ';
    while (c != EOF)
    {
        c = getc(f1);
        if (c != EOF)
        {
            if ((8 * del_line - 7) > aux || aux > (8 * del_line))
            {
                putc(c, f2);
            }
            if (c == '\n')
            {
                aux++;
            }
        }
    }
    fclose(f1);
    fclose(f2);
    remove("data.txt");
    rename("copy.txt", "data.txt");
}

int main(void)
{
    
    int i, eve, loop = 1;
    ler();
    while (loop == 1) //Loop principal
    {
        //Vai Buscar o tempo atual
        FILE *ficheiro;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        eve=contaEventos();
        for (i=0; i<eve; i++)
        {
            if ((tm.tm_wday == nextEvent.diaSemana || (tm.tm_mday == nextEvent.clg_data.dia && (tm.tm_mon + 1) == nextEvent.clg_data.mes && (tm.tm_year + 1900) == nextEvent.clg_data.ano)) && tm.tm_hour > nextEvent.horas || tm.tm_hour == nextEvent.horas && tm.tm_min > nextEvent.minutos)
            {
                removes(1);
                if (nextEvent.diaSemana == tm.tm_wday)
                {
                    ficheiro = fopen("data.txt", "a");
                    fprintf(ficheiro, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", nextEvent.nome, nextEvent.link, nextEvent.clg_data.dia, nextEvent.clg_data.mes, nextEvent.clg_data.ano, nextEvent.diaSemana, nextEvent.horas, nextEvent.minutos);
                    fclose(ficheiro);
                }
                ler();
            }
        }
        if (tm.tm_hour == nextEvent.horas && tm.tm_min == nextEvent.minutos && (tm.tm_wday == nextEvent.diaSemana || (tm.tm_mday == nextEvent.clg_data.dia && (tm.tm_mon + 1) == nextEvent.clg_data.mes && (tm.tm_year + 1900) == nextEvent.clg_data.ano)))
        {
            strcat(browser, nextEvent.link);
            system(browser);
            strcpy(browser, "open ");
            removes(1);
            if (nextEvent.diaSemana == tm.tm_wday)
            {
                ficheiro = fopen("data.txt", "a");
                fprintf(ficheiro, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", nextEvent.nome, nextEvent.link, nextEvent.clg_data.dia, nextEvent.clg_data.mes, nextEvent.clg_data.ano, nextEvent.diaSemana, nextEvent.horas, nextEvent.minutos);
                fclose(ficheiro);
            }
            ler();
        }

        sleep(60);
        ler();
        i=0;
    }
    return 0;
}

