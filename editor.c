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

//recolha das informações
void recolha(void)
{
    FILE *ficheiro = fopen("data.txt", "a");
    int i, t;
    i = 1;
    

    while (i == 1)
    {
        printf("Insira o nome do evento: \n");
        scanf("%s", stu_data.nome);
        printf("Insira o link do evento: \n");
        scanf("%s", stu_data.link);
        printf("Caso deseje que seja recursivo insira [1], ou [0] caso contrário.\n");
        scanf("%d", &t);
        if (t==0)
        {
        printf("Insira a data do evento: \n");
        scanf("%d/%d/%d", &stu_data.clg_data.dia, &stu_data.clg_data.mes, &stu_data.clg_data.ano);
        stu_data.diaSemana=8;
        }
        else
        {
        printf("Insira dia da semana em que o evento vai ocorrer: \n");
        scanf("%d", &stu_data.diaSemana);
        stu_data.clg_data.dia = (-1);
        stu_data.clg_data.mes = (-1);
        stu_data.clg_data.ano = (-1);
        }
        printf("Insira a que horas o evento vai ocorrer: \n");
        scanf("%d", &stu_data.horas);
        printf("Insira os minutos a que o evento vai ocorrer: \n");
        scanf("%d", &stu_data.minutos);
        fprintf(ficheiro, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n\n", stu_data.nome, stu_data.link, stu_data.clg_data.dia, stu_data.clg_data.mes, stu_data.clg_data.ano, stu_data.diaSemana, stu_data.horas, stu_data.minutos);
        printf("Caso deseje adicionar outro evento insira [1], ou [0] caso contrário.\n");
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


void removes (int del_line, int mode)
{
    FILE *f1, *f2;
    int aux=1;
    char c;
    f1=fopen("data.txt","r");
    f2=fopen("copy.txt","w");
    c = ' ';
    while (c != EOF) {
      c = getc(f1);
      if (c == '\n')
      aux++;
      //except the line to be deleted
      if ((9*del_line-8)>aux || aux > (9*del_line))
      {
        putc(c, f2);
      }
      else if (mode == 2)
      {
          edit();
      }
    }
    fclose(f1);
    fclose(f2);
    remove("data.txt");
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
        printf("\n\n--------Menu---------\n\n");
        printf("1.Visualizar Eventos\n");
        printf("2.Criar Evento\n");
        printf("3.Editar Evento\n");
        printf("4.Apagar Evento\n");
        printf("5.Exit\n\n");
        printf("---------------------\n\n");

        //Escrever a ação que pretendemos
        assert(scanf("%d", &choice) == 1);
        //switch com todos os casos de possiveis escolhas
        switch (choice)
        {
        //Visualização de Eventos
        case 1:
        {
            /* code */
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
            /* code */
            break;
        }
        //Apagar Eventos
        case 4:
        {
            printf("Qual evento a apagar?");
            scanf("%d", &del);
            removes(del, 1);
            break;
        }
        //Exit
        case 5:
        {
            printf("Bye bye\n");
            menu = 0;
            break;
        }
        // Caso o valor dado seja Invalido
        default:
        {
            printf("Valor invalido! Por favor introduza um número válido\n");
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