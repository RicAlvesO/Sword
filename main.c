#include <stdio.h>
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
char browser[] = "firefox ";

void ler(void)
{
    FILE *f = fopen("data.txt", "r+");
    fscanf(f, "%[^\n]\n%[^\n]\n%i\n%i\n%i\n%i\n%i\n%i\n", nextEvent.nome, nextEvent.link, &nextEvent.clg_data.dia,
           &nextEvent.clg_data.mes, &nextEvent.clg_data.ano, &nextEvent.diaSemana, &nextEvent.horas, &nextEvent.minutos) == 8;
    fclose(f);
}

int main(void)
{
    
    int loop = 1;
    ler();
    while (loop == 1) //Loop principal
    {
        //Vai Buscar o tempo atual
        time_t t = time(NULL);
        strcat(browser, nextEvent.link);
        struct tm tm = *localtime(&t);
        if (tm.tm_hour == nextEvent.horas && tm.tm_min == nextEvent.minutos && (tm.tm_wday == nextEvent.diaSemana || (tm.tm_mday == nextEvent.clg_data.dia && (tm.tm_mon+1) == nextEvent.clg_data.mes && (tm.tm_year + 1900) == nextEvent.clg_data.ano)))
        {
            system(browser);
            nextEvent.horas = (-1);
        }
        sleep(60);
    }
    return 0;
}

