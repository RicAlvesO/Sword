#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void removes(int del_line)
{
    FILE *f1, *f2, *f3;
    int aux = 1;
    char c;
    int verf = 0;
    f1 = fopen("data.txt", "r");
    f2 = fopen("copy.txt", "a");
    f3 = fopen("editar.txt", "w+");
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
            else
            {
                putc(c, f3);
            }
            if (c == '\n')
            {
                aux++;
            }
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    remove("data.txt");
    remove("editar.txt");
    rename("copy.txt", "data.txt");
}

int main()
{
    char trash0[20], trash1[20], trash2[20], trash3[20];
    int horas[3], diaSemana[3], minutos[3], dia[3], mes[3], ano[3]; 
    double diasUntil[3], difHoras[3], difMin[3];
    int eliminado=0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    horas[0] = tm.tm_hour;
    diaSemana[0] = tm.tm_wday;
    minutos[0] = tm.tm_min;
    dia[0] = tm.tm_mday; 
    mes[0] = tm.tm_mon + 1;
    ano[0] = tm.tm_year + 1900;

    FILE *fd = fopen("data.txt", "r+");

    fscanf(fd, "%s %s %d %d %d %d %d %d %s %s %d %d %d %d %d %d", trash0, trash1, &dia[1], &mes[1], &ano[1], &diaSemana[1], &horas[1], &minutos[1], trash2, trash3, &dia[2], &mes[2], &ano[2], &diaSemana[2], &horas[2], &minutos[2]);

    if (dia[1]==(-1))
    {
        diasUntil[1]=diaSemana[1]-diaSemana[0];
        if (diasUntil[1]<0)
        {
            diasUntil[1]=diasUntil[1]+7;
        }
        diasUntil[1]=diasUntil[1]*1440;
    }
    else
    {
        if (ano[1] < ano[0] || (ano[1] == ano[0] && mes[1] < mes[0]) || (ano[1] == ano[0] && mes[1] == mes[0] && dia[1] < dia[0]))
        {
            removes(1);
            eliminado=1;
        }
        else if (ano[1]==ano[0] && mes[1]==mes[0])
        {
            diasUntil[1]=dia[1]-dia[0];
        }
        else if (ano[1]==ano[0] && dia[1]==dia[0])
        {
            diasUntil[1] = (mes[1]-mes[0])*(30.5)*1440;
        }
        else if (mes[1] == mes[0] && dia[1] == dia[0])
        {
            diasUntil[1] = (ano[1] - ano[0]) * (365.25) * 1440;
        }
        else if (ano[1] == ano[0])
        {
            diasUntil[1] = ((mes[1] - mes[0]) * (30.5) * 1440)+((30.5-dia[1])*1440);
        }
        else if (mes[1] == mes[0])
        {
            diasUntil[1] = ((ano[1] - ano[0]) * 365.25 * 1440) + ((dia[1] - dia[0]) * 1440);
        }
        else if (dia[1] == dia[0])
        {
            diasUntil[1] = ((12-mes[1]) * (30.5) * 1440) + ((ano[1] - ano[0]) * 365.25 * 1440);
        }
        else
        {
            diasUntil[1] = ((12-mes[1]) * (30.5) * 1440) + ((ano[1] - ano[0]) * 365.25 * 1440)+((30.5-dia[1])*1440);
        }
    }

    if(eliminado!=1)
    {
        difHoras[1]=horas[1]-horas[0];
        difMin[1]=minutos[1]-minutos[0];
        if (difHoras[1]<0)
        {
            difHoras[1]=difHoras[1];
        }
        if (difMin[1] < 0)
        {
            difMin[1] = difMin[1];
        }
        diasUntil[1]=diasUntil[1]+(difHoras[1]*60)+difMin[1];
    }

    if (dia[2] == (-1))
    {
        diasUntil[2] = diaSemana[2] - diaSemana[0];
        if (diasUntil[2] < 0)
        {
            diasUntil[2] = diasUntil[2] + 7;
        }
        diasUntil[2] = diasUntil[2] * 1440;
    }
    else
    {
        if (ano[2] < ano[0] || (ano[2] == ano[0] && mes[2] < mes[0]) || (ano[2] == ano[0] && mes[2] == mes[0] && dia[2] < dia[0]))
        {
            removes(2);
            if (eliminado==1)
            {
                eliminado = 3;
            }
            else
            {
                eliminado = 2;
            }
        }
        else if (ano[2] == ano[0] && mes[2] == mes[0])
        {
            diasUntil[2] = dia[2] - dia[0];
        }
        else if (ano[2] == ano[0] && dia[2] == dia[0])
        {
            diasUntil[2] = (mes[2] - mes[0]) * (30.5) * 1440;
        }
        else if (mes[2] == mes[0] && dia[2] == dia[0])
        {
            diasUntil[2] = (ano[2] - ano[0]) * (365.25) * 1440;
        }
        else if (ano[2] == ano[0])
        {
            diasUntil[2] = ((mes[2] - mes[0]) * (30.5) * 1440) + ((30.5 - dia[2]) * 1440);
        }
        else if (mes[2] == mes[0])
        {
            diasUntil[2] = ((ano[2] - ano[0]) * 365.25 * 1440) + ((dia[2] - dia[0]) * 1440);
        }
        else if (dia[2] == dia[0])
        {
            diasUntil[2] = ((12 - mes[2]) * (30.5) * 1440) + ((ano[2] - ano[0]) * 365.25 * 1440);
        }
        else
        {
            diasUntil[2] = ((12 - mes[2]) * (30.5) * 1440) + ((ano[2] - ano[0]) * 365.25 * 1440) + ((30.5 - dia[2]) * 1440);
        }
    }

    if(eliminado<2)
    {
        difHoras[2] = horas[2] - horas[0];
        difMin[2] = minutos[2] - minutos[0];
        if (difHoras[2] < 0)
        {
            difHoras[2] = difHoras[2];
        }
        if (difMin[2] < 0)
        {
            difMin[2] = difMin[2];
        }
        diasUntil[2] = diasUntil[2] + (difHoras[2] * 60) + difMin[2];
    }

    switch (eliminado)
    {
    case 1:
        {
        printf("%f", diasUntil[2]);
        break;
        }
    case 2:
        {
            printf("%f", diasUntil[1]);
            break;
        }
    case 3:
        {
            printf("Nenhum");
            break;
        }
    default:
        {
        diasUntil[0] = diasUntil[1] - diasUntil[2];
        if (diasUntil[0] <= 0)
        {
            diasUntil[0] = diasUntil[1];
        }
        else
        {
            diasUntil[0] = diasUntil[2];
        }
        printf("%f ou %f\nMenor:%f\n", diasUntil[1], diasUntil[2], diasUntil[0]);
        break;
        }
    }

    fclose(fd);
}
