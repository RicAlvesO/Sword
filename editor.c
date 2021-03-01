#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

struct dataExec
{
    int dia;
    int mes;
    int ano;
};

struct dadosUtilizador
{
    char nome[100];           // guarda o nome atribuido pelo utilizador à ação desejada
    char link[300];           // guarda o link do site fornecido pelo utilizador
    struct dataExec clg_data; // guarda a data desejada pelo utilizador para a execução da tarefa
    int diaSemana;            // guarda o dia da semana em que o utilizador deseja executar a tarefa
    int horas;                // guarda as horas fornecidas pelo utilizador
    int minutos;              // guarda os minutos fornecidos pelo utilizador
} stu_data;

struct dadosUtilizador event;

void import(void)
{
    FILE *f1, *f2;
    int aux = 1;
    char c;
    char fich[50];
    printf("Para consultar a estrutura que o ficheiro deve ter, visite o menu AJUDA.\n");
    printf("Por favor copie o ficheiro para a pasta do programa e, de seguida, introduza o nome do arquivo (nome.txt):\n");
    scanf("%s", fich);
    f1 = fopen(fich, "r+");
    f2 = fopen("data.txt", "a");
    c = ' ';
    while (c != EOF)
    {
        c = getc(f1);
        if (c != EOF)
        {
            putc(c, f2);
            if (c == '\n')
            {
                aux++;
            }
        }
    }
    fclose(f1);
    fclose(f2);
    remove(fich);
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

void recolha(void)
{
    FILE *ficheiro;
    int i, t, j, h, m, z;
    i = 1;

    while (i == 1)
    {
        j = 1;
        t = 3;
        z = 1;
        ficheiro = fopen("data.txt", "a");
        printf("\nInsira o nome do evento (não use espaços neste campo): ");
        scanf("%s", stu_data.nome);
        printf("Insira o link do evento: ");
        scanf("%s", stu_data.link);
        while (t < 0 || t > 1)
        {
            printf("Caso deseje que seja recursivo insira [1], ou [0] caso contrário: ");
            scanf("%d", &t);
        }
        if (t == 0)
        {
            while (z == 1)
            {
                printf("Insira a data do evento (\"dd/mm/aaaa\"): ");
                scanf("%d/%d/%d", &stu_data.clg_data.dia, &stu_data.clg_data.mes, &stu_data.clg_data.ano);
                if (stu_data.clg_data.mes < 1 || stu_data.clg_data.mes > 12 || stu_data.clg_data.dia < 1 || stu_data.clg_data.dia > 31)
                {
                    printf("\nPor favor introduza uma data válida.\n");
                }
                else
                {
                    z = 0;
                }
            }
            stu_data.diaSemana = 8;
        }
        else
        {
            printf("Insira dia da semana em que o evento vai ocorrer (0-6, sendo 0 domingo e 6 sábado): ");
            scanf("%d", &stu_data.diaSemana);
            while (stu_data.diaSemana < 0 || stu_data.diaSemana > 6)
            {
                printf("Dia de semana inválido\n");
                printf("Insira dia da semana em que o evento vai ocorrer(0 a 6, sendo 0 domingo e 6 sábado): ");
                scanf("%d", &stu_data.diaSemana);
            }
            stu_data.clg_data.dia = (-1);
            stu_data.clg_data.mes = (-1);
            stu_data.clg_data.ano = (-1);
        }
        while (j == 1)
        {
            printf("Insira a que horas o evento vai ocorrer (\"hh:mm\"): ");
            scanf("%d:%d", &h, &m);
            if (h >= 0 && h <= 23 && m >= 0 && m <= 59)
            {
                stu_data.horas = h;
                stu_data.minutos = m;
                j = 0;
            }
            else
            {
                printf("\nPor favor introduza uma hora válida.\n");
            }
        }

        fprintf(ficheiro, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", stu_data.nome, stu_data.link, stu_data.clg_data.dia, stu_data.clg_data.mes, stu_data.clg_data.ano, stu_data.diaSemana, stu_data.horas, stu_data.minutos);
        fclose(ficheiro);
        printf("\nCaso deseje adicionar outro evento insira [1], ou [0] caso contrário: ");
        scanf("%d", &i);
    }
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
    int aEd, t, h, m, j, z;
    j = 1;
    z = 1;
    ler2();
    FILE *ficheiro;
    ficheiro = fopen("copy.txt", "a");
    while (editarEv != 0)
    {
        aEd = 0;
        printf("\nO que pretende editar:\n1.Nome\n2.Link\n3.Data\n4.Horas\n");
        scanf("%d", &aEd);
        switch (aEd)
        {
        case 1:
        {
            printf("Insira o novo nome do evento (não use espaços neste campo): \n");
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
                while (z == 1)
                {
                    printf("Insira a nova data do evento (\"dd/mm/aaaa\"): ");
                    scanf("%d/%d/%d", &event.clg_data.dia, &event.clg_data.mes, &event.clg_data.ano);
                    if (event.clg_data.mes < 1 || event.clg_data.mes > 12 || event.clg_data.dia < 1 || event.clg_data.dia > 31)
                    {
                        printf("\nPor favor introduza uma data válida.\n");
                    }
                    else
                    {
                        z = 0;
                    }
                }
                event.diaSemana = 8;
            }
            else
            {
                printf("Insira o novo dia da semana em que o evento vai ocorrer: \n");
                scanf("%d", &event.diaSemana);
                if (event.diaSemana < 0 || event.diaSemana > 6)
                {
                    printf("Dia de semana inválido\n");
                    break;
                }
                event.clg_data.dia = (-1);
                event.clg_data.mes = (-1);
                event.clg_data.ano = (-1);
            }
            break;
        }
        case 4:
        {
            while (j == 1)
            {
                printf("Insira a que horas o evento vai ocorrer (\"hh:mm\"): ");
                scanf("%d:%d", &h, &m);
                if (h >= 0 && h <= 23 && m >= 0 && m <= 59)
                {
                    event.horas = h;
                    event.minutos = m;
                    j = 0;
                }
            }
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
    }
    fprintf(ficheiro, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", event.nome, event.link, event.clg_data.dia, event.clg_data.mes, event.clg_data.ano, event.diaSemana, event.horas, event.minutos);
    fclose(ficheiro);
}

void move(void)
{
    ler2();
    FILE *ficheiro;
    ficheiro = fopen("copy.txt", "a");
    fprintf(ficheiro, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", event.nome, event.link, event.clg_data.dia, event.clg_data.mes, event.clg_data.ano, event.diaSemana, event.horas, event.minutos);
    fclose(ficheiro);
}

void removes(int del_line, int mode)
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
    if (mode == 2)
    {
        edit();
    }
    else if (mode == 3)
    {
        move();
    }
    remove("data.txt");
    remove("editar.txt");
    rename("copy.txt", "data.txt");
}

void ordenar(void)
{
    char trash0[50], trash1[50], trash2[50], trash3[50];
    int horas[3], diaSemana[3], minutos[3], dia[3], mes[3], ano[3];
    double diasUntil[3], difHoras[3], difMin[3];
    int eliminado = 0;
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

    if (dia[1] == (-1))
    {
        diasUntil[1] = diaSemana[1] - diaSemana[0];
        if (diasUntil[1] < 0)
        {
            diasUntil[1] = diasUntil[1] + 7;
        }
        diasUntil[1] = diasUntil[1] * 1440;
    }
    else
    {
        if (ano[1] < ano[0] || (ano[1] == ano[0] && mes[1] < mes[0]) || (ano[1] == ano[0] && mes[1] == mes[0] && dia[1] < dia[0]))
        {
            removes(1, 1);
            eliminado = 1;
        }
        else if (ano[1] == ano[0] && mes[1] == mes[0])
        {
            diasUntil[1] = dia[1] - dia[0];
        }
        else if (ano[1] == ano[0] && dia[1] == dia[0])
        {
            diasUntil[1] = (mes[1] - mes[0]) * (30.5) * 1440;
        }
        else if (mes[1] == mes[0] && dia[1] == dia[0])
        {
            diasUntil[1] = (ano[1] - ano[0]) * (365.25) * 1440;
        }
        else if (ano[1] == ano[0])
        {
            diasUntil[1] = ((mes[1] - mes[0]) * (30.5) * 1440) + ((30.5 - dia[1]) * 1440);
        }
        else if (mes[1] == mes[0])
        {
            diasUntil[1] = ((ano[1] - ano[0]) * 365.25 * 1440) + ((dia[1] - dia[0]) * 1440);
        }
        else if (dia[1] == dia[0])
        {
            diasUntil[1] = ((12 - mes[1]) * (30.5) * 1440) + ((ano[1] - ano[0]) * 365.25 * 1440);
        }
        else
        {
            diasUntil[1] = ((12 - mes[1]) * (30.5) * 1440) + ((ano[1] - ano[0]) * 365.25 * 1440) + ((30.5 - dia[1]) * 1440);
        }
    }

    if (eliminado != 1)
    {
        difHoras[1] = horas[1] - horas[0];
        difMin[1] = minutos[1] - minutos[0];
        if (difHoras[1] < 0)
        {
            difHoras[1] = difHoras[1];
        }
        if (difMin[1] < 0)
        {
            difMin[1] = difMin[1];
        }
        diasUntil[1] = diasUntil[1] + (difHoras[1] * 60) + difMin[1];
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
            removes(2, 1);
            if (eliminado == 1)
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

    if (eliminado < 2)
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

    if (eliminado == 0)
    {
        diasUntil[0] = diasUntil[1] - diasUntil[2];
        if (diasUntil[0] <= 0)
        {
            removes(2, 3);
        }
        else
        {
            removes(1, 3);
        }
    }

    fclose(fd);
}

void ajuda(void)
{
    int t = 3;
    printf("______________________________________________________________________________________________________________________________________\n\n\n");
    printf("\n           //\\\\\\\\\\\\\\\\\\\\\\\\  \\\\\\\\\\\\\\\\                 ///////  |||||||||||||||  |||||||||||||\\\\    |||||||||\\\\\\\\  \n");
    printf("          ||           ||   \\\\    \\\\   ////\\\\\\\\    //   //   ||           ||  ||           ||    ||          \\\\                   \n");
    printf("           \\\\    ||||||//    \\\\    \\\\  //     \\\\  //   //    ||  |||||||  ||  ||  ||||||   ||    ||           \\\\                  \n");
    printf("            \\\\     \\\\         \\\\    \\\\//       \\\\//   //     ||  ||   ||  ||  ||  ||  ||   ||    ||  ||||||    ||                  \n");
    printf("             \\\\      \\\\        \\\\        //\\\\        //      ||  ||   ||  ||  ||  ||||||  //     ||  ||  ||    ||                    \n");
    printf("               \\\\     \\\\        \\\\      //  \\\\      //       ||  ||   ||  ||  ||          \\\\     ||  ||||||    ||                  \n");
    printf("          //|||||||    ||        \\\\    //    \\\\    //        ||  |||||||  ||  ||  |||||\\\\  \\\\    ||           //                    \n");
    printf("          ||           ||         \\\\  //      \\\\  //         ||           ||  ||  ||    \\\\  \\\\   ||          //                     \n");
    printf("           \\\\\\\\\\\\\\\\\\\\////          \\\\//        \\\\//          |||||||||||||||  ||||||     \\\\\\\\\\\\  ||///////////         \n\n");

    printf("\n\n");

    //VISUALIZAR UM EVENTO
    printf("______________________________________________________________________________________________________________________________________\n\n");
    printf("<1> Visualizar um Evento \n");
    printf("______________________________________________________________________________________________________________________________________\n\n");

    printf("» Sempre que pretenda visualizar os seus eventos atuais terá que selecionar o número '1' no menu principal e pressionar 'ENTER'.\n");
    printf("Assim ser-lhe-á disponibilizado a lista de todos os eventos, ordenados desde a data mais próxima a ocorrer para a data mais distante.\n");

    //CRIAR UM EVENTO
    printf("_______________________________________________________________________________________________________________________________________\n\n");
    printf("<2> Criar um Evento \n");
    printf("_______________________________________________________________________________________________________________________________________\n\n");

    printf("» Sempre que pretenda criar eventos terá que selecionar o número '2' no menu principal e pressionar 'ENTER'. \n");
    printf("  Será necessario escrever o nome do evento que quer guardar(o qual deve ter '_' caso queira escrever mais do que um nome),\n");
    printf("o link através do qual pretende aceder ao evento, se o evento será recursivo ou não, ou seja, se pretende que o evento ocorra\n");
    printf("sempre num dado dia da semana,ou se pretende que o evento ocorra numa determinada data: \n\n");

    // caso em que o evento seja recursivo.
    printf("\t> se o evento que pretende usar for recursivo deve introduzir o valor '1'e de seguida será pedido o dia da semana\n");
    printf("\t (entre 0(Domingo) e 6(Sabado)) em que o evento irá ocorrer e a hora a que este vai começar.Assim o evento\n");
    printf("\t irá acontecer todas as semanas na hora determinada.\n\n");
    //caso em que o evento não seja recursivo.
    printf("\t> se o evento que pretende usar não for recursivo deve introduuzir o valor '0' e de seguida será pedido para introduzir\n");
    printf("\t a data em que o evento irá ocorrer e a respetiva hora. Assim o evento irá ocorrer na data dada, na hora determinada\n");
    printf("\t pelo utilizador.\n\n");
    //final do processo
    printf("» No final do processo ser-lhe-á disponibilizada a opção de criar outro evento ou simplesmente para de criar eventos\n");
    printf("e voltar ao menu principal, neste caso, tal como nos outros acima referidos, devera introduzir o numero '1' se a sua\n");
    printf("resposta corresponder a'sim' ou '0' caso a sua resposta corresponder a 'não'.\n");

    //EDITAR UM EVENTO
    printf("_________________________________________________________________________________________________________________________________________\n\n");
    printf("<3> Editar um Evento \n");
    printf("_________________________________________________________________________________________________________________________________________\n\n");
    printf("» Sempre que pretenda editar eventos terá que selecionar o número '3' no menu principal e pressionar 'ENTER'. \n");
    printf("  Ser-lhe-á fornecido uma lista com todos os eventos criados até à data (cada um tem um número associado), de seguida terá\n");
    printf("que selecionar o número do evento que pretende editar. Em segudia será questionado sobre qual a parte do evento que\n");
    printf("pertende alterar (nome, link, a recursividade de um evento, a data, o dia da seman, a hora).\n");

    //APAGAR UM EVENTO
    printf("_________________________________________________________________________________________________________________________________________\n\n");
    printf("<4> Apagar um Evento \n");
    printf("_________________________________________________________________________________________________________________________________________\n\n");
    printf("» Sempre que pretenda apagar um evento terá que selecionar o número '4' no menu principal e pressionar 'ENTER'.\n");
    printf("  Ser-lhe-á fornecido uma lista com todos os eventos criados até à data (cada um tem um número associado), de seguida\n");
    printf("será pedido para o utilizador introduzir o número correspondente ao evento que pretende eliminar, e assim que o evento\n");
    printf("for eliminado o utilizador volta para o menu principal.\n\n");
    printf("_________________________________________________________________________________________________________________________________________\n\n");

    //IMPORTAR FICHEIROS
    printf("_________________________________________________________________________________________________________________________________________\n\n");
    printf("<5> Importar Ficheiros\n");
    printf("_________________________________________________________________________________________________________________________________________\n\n");
    printf("» Pode também importar ficheiros de colegas,amigos ou até mesmo colaboradores. Ao introduzir o número '5' ser-lhe-á pedido\n");
    printf("para importar um ficheiro para a pasta da aplicação e digitar o seu nome.\n");
    printf("A estrutura de cada ficheiro deve ser igual à apresentada abaixo: \n\n");
    //Exemplo de um ficheiro
    printf("             Evento x\n");
    printf("             Nome: nome_do_ficheiro\n");
    printf("             Dia da Semana: (número de 0 a 6, sendo 0 domingo e 6 sábado)     OU     Data: dd/mm/aaaa\n");
    printf("             Hora: hh:mm\n");
    printf("\nImportante: \n");
    printf("\t No ultimo evento não dê ENTER após escrever a hora.\n\n");
    printf("\t Deve notar que ao importar um ficheiro este será copiado para o ficheiro principal data.txt e o ficheirom original será eliminado,\n");
    printf("\tvisto que, os seus contéudos já se irão encontrar disponiveis no ficheiro de data original.\n");
    printf("_________________________________________________________________________________________________________________________________________\n\n");
    while (t < 0 || t > 1)
    {
        printf("Continuar para Menu [1]: ");
        scanf("%d", &t);
    }
}

void supordenar(void)
{
    FILE *f1, *f2;
    int m, n, i, j;
    int aux = 1;
    char c;
    f2 = fopen("copya.txt", "w");
    fclose(f2);
    n = contaEventos();
    for (i = 0; i < n; i++)
    {
        m = contaEventos();
        for (j = 1; j < m; j++)
        {
            ordenar();
        }
        f1 = fopen("data.txt", "r");
        f2 = fopen("copya.txt", "a");
        ler();
        fprintf(f2, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", event.nome, event.link, event.clg_data.dia, event.clg_data.mes, event.clg_data.ano, event.diaSemana, event.horas, event.minutos);
        fclose(f1);
        fclose(f2);
        removes(1, 1);
    }
    remove("data.txt");
    rename("copya.txt", "data.txt");
}

void load_menu(void)
{
    char try;
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
        printf("\\\\ 5. Importar ficheiros //\n");
        printf("\\\\ 6. Exit               //\n");
        printf("\\\\ 7. Ajuda              //\n");
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
            int t = 3;
            supordenar();
            mostra();
            while (t < 0 || t > 1)
            {
                printf("Continuar para Menu [1]: ");
                scanf("%d", &t);
            }
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
            int line;
            line = contaEventos();
            mostra();
            printf("\n\nQual evento a editar?\n");
            scanf("%d", &del);
            if (del < 0 || del > line)
            {
                printf("O evento inserido não é válido!\n");
                break;
            }
            removes(del, 2);
            break;
        }
        //Apagar Eventos
        case 4:
        {
            int line, apagar = 1;
            while (apagar == 1)
            {
                line = contaEventos();
                mostra();
                printf("\n\nQual evento a apagar?\n");
                scanf("%d", &del);
                if (del < 0 || del > line)
                {
                    printf("O evento inserido não é válido!\n");
                    break;
                }
                removes(del, 1);
                printf("\nDesja apagar mais algum evento?\n[1]Sim\n[0]Nao\n");
                scanf("%d", &apagar);
            }
            break;
        }
        //Importar
        case 5:
        {
            import();
            break;
        }
        //Exit
        case 6:
        {
            supordenar();
            printf("\n\nBye bye\n");
            menu = 0;
            break;
        }
        //Ajuda
        case 7:
        {
            ajuda();
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
