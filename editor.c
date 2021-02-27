#include <stdio.h>
#include <string.h>
#include <assert.h>

struct dataExec {
    int dia;
    int mes;
    int ano;
};

struct dadosUtilizador {
    char nome[30]; // guarda o nome atribuido pelo utilizador à ação desejada
    char link[100]; // guarda o link do site fornecido pelo utilizador
    struct dataExec clg_data; // guarda a data desejada pelo utilizador para a execução da tarefa
    int diaSemana; // guarda o dia da semana em que o utilizador deseja executar a tarefa
    int horas; // guarda as horas fornecidas pelo utilizador
    int minutos; // guarda os minutos fornecidos pelo utilizador
}stu_data;

struct dadosUtilizador event;

// Para usar, por exemplo a variável diaSemana, tem de se representar por stu_data.diaSemana
// Para usar a variável dia, tem de se representar por stu_data.clg_data.dia

int mostra(void)
{
    int line = 1;
    int i = 0;
    char c = ' ';
    int eve = 1;

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
            if ((line - 2) % 7 == 0 && i > 2)
            {
                line = 1;
                i = 0;
                eve++;
                printf("\nEvento %d\n", eve);
            }

            if (line == 3 && c == '-')
            {
                i = 4;
                printf("Dia da Semana: ");
            }
            else if (line == 3 && i == 1)
            {
                i = 5;
                printf("Data: ");
            }

            if (line == 7 && i > 3)
            {
                i = 1;
            }

            if (line == 1 && i == 0) //Insere o nome do eventos guardado
            {
                printf("Nome: ");
                putchar(c);
                i++;
            }
            else if (line == 1 && i != 0) //Nome
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
            else if (line == 7 && i == 1) // Insere a data do evento guardado no ficheiro
            {
                printf("Hora: ");
                putchar(c);
                i++;
            }
            else if (line == 7 && i != 1 && c != '\n') // Insere a hora do evento guardado no ficheiro
            {
                putchar(c);
            }
            else if (line == 8 && i == 2) // Insere o minuto do evento guardado no ficheiro
            {
                putchar(':');
                putchar(c);
                i++;
            }
            else if (line == 8 && i != 2)
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

//recolha das informações
void recolha(void)
{
    FILE *ficheiro = fopen("data.txt", "a");
    int i, t;
    i = 1;
    

    while (i == 1)
    {
        printf("\nInsira o nome do evento: ");
        scanf("%s", stu_data.nome);
        printf("Insira o link do evento: ");
        scanf("%s", stu_data.link);
        printf("Caso deseje que seja recursivo insira [1], ou [0] caso contrário: ");
        scanf("%d", &t);
        if (t==0)
        {
        printf("Insira a data do evento: ");
        scanf("%d/%d/%d", &stu_data.clg_data.dia, &stu_data.clg_data.mes, &stu_data.clg_data.ano);
        stu_data.diaSemana=8;
        }
        else
        {
        printf("Insira dia da semana em que o evento vai ocorrer: ");
        scanf("%d", &stu_data.diaSemana);
        stu_data.clg_data.dia = (-1);
        stu_data.clg_data.mes = (-1);
        stu_data.clg_data.ano = (-1);
        }
        printf("Insira a que horas o evento vai ocorrer: ");
        scanf("%d:%d", &stu_data.horas, &stu_data.minutos);
        fprintf(ficheiro, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", stu_data.nome, stu_data.link, stu_data.clg_data.dia, stu_data.clg_data.mes, stu_data.clg_data.ano, stu_data.diaSemana, stu_data.horas, stu_data.minutos);
        printf("\nCaso deseje adicionar outro evento insira [1], ou [0] caso contrário: ");
        scanf("%d", &i);
    }

    fclose(ficheiro);
}

void ler(void)
{
    FILE *f = fopen("data.txt", "r+");
    fscanf(f, "%[^\n]\n%[^\n]\n%i\n%i\n%i\n%i\n%i\n%i\n", event.nome, event.link, &event.clg_data.dia,
           &event.clg_data.mes, &event.clg_data.ano, &event.diaSemana, &event.horas, &event.minutos) == 8;
    fclose(f);
}

void ler2(void)
{
    FILE *f = fopen("editar.txt", "r+");
    fscanf(f, "%[^\n]\n%[^\n]\n%i\n%i\n%i\n%i\n%i\n%i\n", event.nome, event.link, &event.clg_data.dia,
           &event.clg_data.mes, &event.clg_data.ano, &event.diaSemana, &event.horas, &event.minutos) == 8;
    fclose(f);
}

void edit(void)
{
    int editarEv = 1; 
    int aEd, t;
    ler2();
    FILE *ficheiro; 
    while (editarEv!=0)
    {
        ficheiro = fopen("copy.txt", "a");
        aEd = 0;
        printf("\nO que pretende editar:\n1.Nome\n2.Link\n3.Data\n4.Horas\n");
        scanf("%d", &aEd);
        switch (aEd)
        {
        case 1:
        {
            printf("Insira o novo nome do evento: \n");
            scanf("%s", event.nome);
            break;
        }
        case 2:
        {
            printf("Insira o novo link do evento: \n");
            scanf("%s", event.link);
            break;
        }
        case 3:
        {
            printf("Caso deseje que seja recursivo insira [1], ou [0] caso contrário.\n");
            scanf("%d", &t);
            if (t == 0)
            {
                printf("Insira a nova data do evento: \n");
                scanf("%d/%d/%d", &event.clg_data.dia, &event.clg_data.mes, &event.clg_data.ano);
                event.diaSemana = 8;
            }
            else
            {
                printf("Insira o novo dia da semana em que o evento vai ocorrer: \n");
                scanf("%d", &event.diaSemana);
                event.clg_data.dia = (-1);
                event.clg_data.mes = (-1);
                event.clg_data.ano = (-1);
            }
            break;
        }
        case 4:
        {
            printf("Insira as novas horas a que o evento vai ocorrer: \n");
            scanf("%d", &event.horas);
            printf("Insira os minutos a que o evento vai ocorrer: \n");
            scanf("%d", &event.minutos);
            break;
        }
        default:
        {
            printf("Valor invalido! Por favor introduza um número válido!\n");
            break;
        }
        }
        
        printf("Caso deseje editar mais algum argumento do evento escreva [1], ou [0] caso contrário.\n");
        scanf("%d", &editarEv);
        fprintf(ficheiro, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", event.nome, event.link, event.clg_data.dia, event.clg_data.mes, event.clg_data.ano, event.diaSemana, event.horas, event.minutos);
        fclose(ficheiro);
    }
}

void removes (int del_line,int mode)
{
    FILE *f1, *f2, *f3;
    int aux=1;
    char c;
    int verf=0;
    f1=fopen("data.txt","r");
    f2=fopen("copy.txt","a");
    f3=fopen("editar.txt","w+");
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
    if (mode==2)
    {
        edit();
    }
    remove("data.txt");
    remove("editar.txt");
    rename("copy.txt","data.txt");
}

void load_menu(void)
{
    int menu = 1;
    int del;
    while (menu != 0)
    {
        //Variavel que permite escolher um numero de 1 a 5
        int choice;
        //Fazer enquato o numero 5 não for imprimido
        printf("\n             /\\\n            <  >\n             \\/\n             ||\n        <>========<>\n            |  |\n\\\\\\\\\\\\\\\\\\\\\\ Menu //////////\n");
        printf("\\\\                       //\n");
        printf("\\\\ 1. Visualizar Eventos //\n");
        printf("\\\\ 2. Criar Evento       //\n");
        printf("\\\\ 3. Editar Evento      //\n");
        printf("\\\\ 4. Apagar Evento      //\n");
        printf("\\\\ 5. Exit               //\n");
        printf("\\\\                       //\n");
        printf("\\\\          oOOo         //\n");
        printf("\\\\         c~~~~ɔ        //\n");
        printf("\\\\         \\\\\\///        //\n");
        printf("\\\\          ----         //\n");
        printf("\\\\                       //\n");
        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////\n            |  |\n            \\  /\n             \\/\n\n             ");

        //Escrever a ação que pretendemos
        assert(scanf("%d", &choice) == 1);
        //switch com todos os casos de possiveis escolhas
        switch (choice)
        {
        //Visualização de Eventos
        case 1:
        {
            mostra();
            break;
        }
        // Criação de Eventos
        case 2:
        {
            recolha();
            break;
        }
        //Edição de Eventos
        case 3:
        {
            mostra();
            printf("\n\nQual evento a editar?\n");
            scanf("%d", &del);
            removes(del, 2);
            break;
        }
        //Apagar Eventos
        case 4:
        {
            mostra();
            printf("\n\nQual evento a apagar?\n");
            scanf("%d", &del);
            removes(del, 1);
            break;
        }
        //Exit
        case 5:
        {
            printf("\n\nBye bye\n");
            menu = 0;
            break;
        }
        // Caso o valor dado seja Invalido
        default:
        {
            printf("\n\nValor invalido! Por favor introduza um número válido\n");
            break;
        }
        }
    }
}

int main()
{
    // Variavel que da 1 ou 0(caso seja necessario voltar ao menu principal)
    load_menu();
    return 0;
}



