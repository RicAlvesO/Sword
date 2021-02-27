#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int mostra(void){
    int line=1;
    int i=0;
    char c=' ';
    int eve=1;

    FILE *fd = fopen("data.txt", "r");
    
    if (fd == NULL) 
    {
        printf("Failed to open file\n");
        return -1;
    }

    printf("\nEvento %d\n", eve);
    while (c != EOF)
    {
        c = getc(fd);
        if (c != EOF)
        {
            if ((line-2)%7==0 && i>2)
            {
                line=1;
                i=0;
                eve++;
                printf("\nEvento %d\n",eve);
            }


            if (line == 3 && c == '-')
            {
                i = 4;
                printf("Dia da Semana: ");
            }
            else if (line == 3 && i==1)
            {
                i = 5;
                printf("Data: ");
            }

            if (line == 7 && i > 3)
            {
                i = 1;
            }

            if (line==1 && i==0) //Insere o nome do eventos guardado
            {
                printf("Nome: ");
                putchar(c);
                i++;
            }
            else if (line==1 && i!=0) //Nome 
            {
                putchar(c);
            }
            else if (line == 3 && i != 4 && c != '\n') //Insere o nome do eventos guardado
            {
                putchar(c);
            }
            else if (line == 4 && i == 5) //Nome
            {
                putchar('/');
                putchar(c);
                i++;
            }
            else if (line == 4 && i > 5 && c != '\n') //Insere o nome do eventos guardado
            {
                putchar(c);
            }
            else if (line == 5 && i == 6) //Nome
            {
                putchar('/');
                putchar(c);
                i++;
            }
            else if (line == 5 && i > 6) //Insere o nome do eventos guardado
            {
                putchar(c);
            }
            else if (line == 6 && i == 4) //Insere o nome do eventos guardado
            {
                switch (c)
                {
                    case '0':
                        {
                        printf("Domingo\n");
                        break;
                        }
                    case '1':
                        {
                        printf("Segunda\n");
                        break;
                        }
                    case '2':
                        {
                        printf("Terça\n");
                        break;
                        }
                    case '3':
                        {
                        printf("Quarta\n");
                        break;
                        }
                    case '4':
                        {
                        printf("Quinta\n");
                        break;
                        }
                    case '5':
                        {
                        printf("Sexta\n");
                        break;
                        }
                    case '6':
                        {
                        printf("Sábado\n");
                        break;
                        }
                    default:
                        break;
                }
            }
            else if (line==7 && i==1) // Insere a data do evento guardado no ficheiro
            {
                printf("Hora: ");
                putchar(c);
                i++;
            }
            else if (line==7 && i!=1 && c!='\n') // Insere a hora do evento guardado no ficheiro
            {
                putchar(c);
            }
            else if (line==8 && i==2) // Insere o minuto do evento guardado no ficheiro
            {
                putchar(':');
                putchar(c);
                i++;
            }
            else if (line==8 && i!=2) 
            {
                putchar(c);
            }

            if (c == '\n')
            {
                line++;
            }
        }
    }
    return 0;
}



int main ()
{
    mostra();

    return 0;
}