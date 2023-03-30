#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// cores

/*-----------------Cores do DOS-------------------------------------------------
Descrição: Procedimento para definição de Cores do DOS
------------------------------------------------------------------------------*/
enum DOS_COLORS
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHT_GRAY,
    DARK_GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    YELLOW,
    WHITE
};
/*----------------------------------------------------------------------------*/

/*-----------------Cores das letras---------------------------------------------
Descrição: Procedimento para inserir cores de letras no programa
------------------------------------------------------------------------------*/
void textcolor(iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= iColor);
}
/*----------------------------------------------------------------------------*/

// fim cores

// tela

// This Initiates the fullscreen function
void fullscreen()
{
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}
// fim tela

typedef struct
{
    char nome[26];
    float defesa;
    float ataque;
    float vida;
    float precisao;
    int vitorias;
    int disponivel;
} Lutador;

Lutador personagem[30];

void criadorLutador()
{
    for (int i = 0; i < 30; i++)
    {
        printf("\nDigite o nome do lutador %i: ", i + 1);
        scanf("%s", personagem[i].nome);
        // printf("Lutador: %s", bonecos[i].nome);
        personagem[i].disponivel = 1;
    }

    printf("\nPersonagens Criados!");
    system("pause");
}

void lutadoresProntos()
{
    strcpy(personagem[0].nome, "Patolino");
    strcpy(personagem[1].nome, "Dipper");
    strcpy(personagem[2].nome, "Heman");
    strcpy(personagem[3].nome, "Lion");
    strcpy(personagem[4].nome, "Sans");
    strcpy(personagem[5].nome, "Popeye");
    strcpy(personagem[6].nome, "Finn");
    strcpy(personagem[7].nome, "Jake");
    strcpy(personagem[8].nome, "Batman");
    strcpy(personagem[9].nome, "Flash");
    strcpy(personagem[10].nome, "Star");
    strcpy(personagem[11].nome, "Marco");
    strcpy(personagem[12].nome, "Bill");
    strcpy(personagem[13].nome, "Pernalonga");
    strcpy(personagem[14].nome, "Scrooge");
    strcpy(personagem[15].nome, "SuperPato");
    strcpy(personagem[16].nome, "Baymax");
    strcpy(personagem[17].nome, "Raya");
    strcpy(personagem[18].nome, "Violeta");
    strcpy(personagem[19].nome, "WandaMaximov");
    strcpy(personagem[20].nome, "Edna");
    strcpy(personagem[21].nome, "JamesBond");
    strcpy(personagem[22].nome, "SherlockHolmes");
    strcpy(personagem[23].nome, "DarthVader");
    strcpy(personagem[24].nome, "Gandalf");
    strcpy(personagem[25].nome, "Bilbo");
    strcpy(personagem[26].nome, "PercyJackson");
    strcpy(personagem[27].nome, "Newt");
    strcpy(personagem[28].nome, "Thomas");
    strcpy(personagem[29].nome, "Teresa");
    // for (int i = 0; i < 30; i++){
    //   printf("\n%s\n", fighters[i].nome);
    //}
}

void definirStatus()
{
    for (int i = 0; i < 30; i++)
    {
        personagem[i].defesa = 1 + rand() % 10;
        personagem[i].ataque = 1 + rand() % 10;
        personagem[i].vida = 100;
        personagem[i].disponivel = 1;
        personagem[i].vitorias = 0;
    }
}

void printLutadores()
{
    for (int i = 0; i < 30; i++)
    {
        textcolor("LIGHT_GRAY");
        printf("   %i- Lutador %s       ", i + 1, personagem[i].nome);
        if (i % 2 != 0)
        {
            printf("\n\n\n");
        }
    }
}

void definirJogadores(int jogadores[3])
{
    printf("\nChoose your champions! \n : ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%i", &jogadores[i]);
        jogadores[i] -= 1;
        personagem[jogadores[i]].disponivel = 0;
    }
    system("cls");
}

void definirTimeInimigo(int inimigos[3])
{
    for (int i = 0; i < 3;)
    {
        inimigos[i] = rand() % 30;
        if (personagem[inimigos[i]].disponivel == 1)
        {
            personagem[inimigos[i]].disponivel = 0;
            i++;
        }
    }
}

void definirJogadorAtual(int *jogador_atual, int jogadores[3])
{
    for (int i = 0; i < 1;)
    {
        *jogador_atual = rand() % 3;
        if (personagem[jogadores[*jogador_atual]].vida == 100)
        {
            i++;
        }
    }
}

void definirInimigoAtual(int *inimigo_atual, int inimigos[3])
{
    for (int i = 0; i < 1;)
    {
        *inimigo_atual = rand() % 3;
        if (personagem[inimigos[*inimigo_atual]].vida == 100)
        {
            i++;
        }
    }
}

int jogadorBate(int jogadores[3], int inimigos[3], int jogador_atual, int inimigo_atual)
{
    float num = 1 - (rand() / 1000);
    personagem[jogadores[jogador_atual]].precisao = 1 - (personagem[jogadores[jogador_atual]].vida * personagem[jogadores[jogador_atual]].ataque) / 1000;
    if (personagem[jogadores[jogador_atual]].precisao > num)
    {
        personagem[inimigos[inimigo_atual]].vida = personagem[inimigos[inimigo_atual]].vida - (personagem[jogadores[jogador_atual]].ataque) / ((personagem[inimigos[inimigo_atual]].defesa) / 10);
        return 1;
    }
    else
    {
        return 0;
    }
}

int inimigoBate(int jogadores[3], int inimigos[3], int jogador_atual, int inimigo_atual)
{
    int num = 1 - (rand() / 1000);
    personagem[inimigos[inimigo_atual]].precisao = 1 - (personagem[inimigos[inimigo_atual]].vida * personagem[inimigos[inimigo_atual]].ataque) / 1000;
    if (personagem[inimigos[inimigo_atual]].precisao > num)
    {
        personagem[jogadores[jogador_atual]].vida = personagem[jogadores[jogador_atual]].vida - (personagem[inimigos[inimigo_atual]].ataque) / ((personagem[jogadores[jogador_atual]].defesa) / 10);
        return 1;
    }
    else
    {
        return 0;
    }
}

void luta(int jogadores[3], int inimigos[3], int *vitorias, int *derrotas)
{
    int jogador_atual = 0, inimigo_atual = 0;
    int chalenger = 1 + rand() % 2; // decide o time que comeca 1 -jogador e 2 - inimigo
    definirJogadorAtual(&jogador_atual, jogadores);
    definirInimigoAtual(&inimigo_atual, inimigos);
    textcolor(BLUE);
    printf("\n\n                                                  %s      VS      %s\n", personagem[jogadores[jogador_atual]].nome, personagem[inimigos[inimigo_atual]].nome);
    system("pause");

    if (chalenger < 2)
    {
        int status = 0; // se o jogador morrer, status=1, se o inimigo morrer, status=2

        while (status != 1 && status != 2)
        {
            system("cls");
            textcolor(DARK_GRAY);
            printf("\n                                                               Lutador %s comeca:", personagem[jogadores[jogador_atual]].nome); // lutador iniciante
            textcolor(LIGHT_RED);
            // menu com informacoes dos lutadores
            printf("\n\n\n                                                          Seu lutador %s:                      Lutador inimigo %s\n                                                          -Vida:%.2f                                          -Vida:%.2f\n                                                          -Ataque: %.2f                                          -Ataque: %.2f\n\n", personagem[jogadores[jogador_atual]].nome, personagem[inimigos[inimigo_atual]].nome, personagem[jogadores[jogador_atual]].vida, personagem[inimigos[inimigo_atual]].vida, personagem[jogadores[jogador_atual]].ataque, personagem[inimigos[inimigo_atual]].ataque);

            int acertoJogador, acertoInimigo;

            acertoJogador = jogadorBate(jogadores, inimigos, jogador_atual, inimigo_atual); // verifica se o jogador acertou o inimigo
            if (acertoJogador == 1)
            {
                textcolor(DARK_GRAY);
                printf("\n                                                          %s acertou %s\n", personagem[jogadores[jogador_atual]].nome, personagem[inimigos[inimigo_atual]].nome);
            }
            else
            {
                textcolor(DARK_GRAY);
                printf("\n                                                          %s esquivou do ataque de %s\n", personagem[inimigos[inimigo_atual]].nome, personagem[jogadores[jogador_atual]].nome);
            }

            system("pause");

            if (personagem[inimigos[inimigo_atual]].vida <= 0)
            {
                textcolor(LIGHT_GREEN);
                printf("\n                                                          Lutador %s morreu! \n                                                  Prepare-se para a batalha seguinte!\n", personagem[inimigos[inimigo_atual]].nome);
                status = 2;
                *vitorias += 1;
                personagem[jogadores[jogador_atual]].vitorias += 1;
                personagem[jogadores[jogador_atual]].vida = 100;
                system("pause");
                break;
            }

            acertoInimigo = inimigoBate(jogadores, inimigos, jogador_atual, inimigo_atual); // verifica se o inimigo acertou o jogador
            if (acertoInimigo == 1)
            {
                textcolor(DARK_GRAY);
                printf("\n                                                          %s acertou %s\n", personagem[inimigos[inimigo_atual]].nome, personagem[jogadores[jogador_atual]].nome);
            }
            else
            {
                textcolor(DARK_GRAY);
                printf("\n                                                          %s esquivou do ataque de %s\n", personagem[jogadores[jogador_atual]].nome, personagem[inimigos[inimigo_atual]].nome);
            }

            system("pause");

            if (personagem[jogadores[jogador_atual]].vida <= 0)
            {
                textcolor(RED);
                printf("\n                                      Lutador %s morreu! Escolheremos o seu proximo lutador para a batalha\n", personagem[jogadores[jogador_atual]].nome);
                status = 1;
                *derrotas += 1;
                personagem[inimigos[inimigo_atual]].vitorias += 1;
                personagem[inimigos[inimigo_atual]].vida = 100;
                system("pause");

                break;
            }
        }
    }
    if (chalenger >= 2)
    {

        int status = 0; // se o jogador morrer, status=1, se o inimigo morrer, status=2

        while (status != 1 && status != 2)
        {
            system("cls");
            textcolor(DARK_GRAY);
            printf("\n                                                               Lutador %s comeca:", personagem[inimigos[inimigo_atual]].nome); // lutador iniciante
            textcolor(LIGHT_RED);
            // menu com informacoes dos lutadores
            printf("\n\n\n                                                          Seu lutador %s:                      Lutador inimigo %s\n                                                          -Vida:%.2f                                          -Vida:%.2f\n                                                          -Ataque: %.2f                                          -Ataque: %.2f\n\n", personagem[jogadores[jogador_atual]].nome, personagem[inimigos[inimigo_atual]].nome, personagem[jogadores[jogador_atual]].vida, personagem[inimigos[inimigo_atual]].vida, personagem[jogadores[jogador_atual]].ataque, personagem[inimigos[inimigo_atual]].ataque);

            int acertoJogador, acertoInimigo;

            acertoInimigo = inimigoBate(jogadores, inimigos, jogador_atual, inimigo_atual); // verifica se o inimigo acertou o jogador
            if (acertoInimigo == 1)
            {
                textcolor(DARK_GRAY);
                printf("\n                                                          %s acertou %s\n", personagem[inimigos[inimigo_atual]].nome, personagem[jogadores[jogador_atual]].nome);
            }
            else
            {
                textcolor(DARK_GRAY);
                printf("\n                                                          %s esquivou do ataque de %s\n", personagem[jogadores[jogador_atual]].nome, personagem[inimigos[inimigo_atual]].nome);
            }

            system("pause");

            if (personagem[jogadores[jogador_atual]].vida <= 0)
            {
                textcolor(RED);
                printf("\n                                      Lutador %s morreu! Escolheremos o seu proximo lutador para a batalha\n", personagem[jogadores[jogador_atual]].nome);
                status = 1;
                *derrotas += 1;
                personagem[inimigos[inimigo_atual]].vitorias += 1;
                personagem[inimigos[inimigo_atual]].vida = 100;
                system("pause");

                break;
            }

            acertoJogador = jogadorBate(jogadores, inimigos, jogador_atual, inimigo_atual); // verifica se o jogador acertou o inimigo
            if (acertoJogador == 1)
            {
                textcolor(DARK_GRAY);
                printf("\n                                                          %s acertou %s\n", personagem[jogadores[jogador_atual]].nome, personagem[inimigos[inimigo_atual]].nome);
            }
            else
            {
                textcolor(DARK_GRAY);
                printf("\n                                                          %s esquivou do ataque de %s\n", personagem[inimigos[inimigo_atual]].nome, personagem[jogadores[jogador_atual]].nome);
            }

            system("pause");

            if (personagem[inimigos[inimigo_atual]].vida <= 0)
            {
                textcolor(LIGHT_GREEN);
                printf("\n                                                          Lutador %s morreu! \n                                                  Prepare-se para a batalha seguinte!\n", personagem[inimigos[inimigo_atual]].nome);
                status = 2;
                *vitorias += 1;
                personagem[jogadores[jogador_atual]].vitorias += 1;
                personagem[jogadores[jogador_atual]].vida = 100;
                system("pause");
                break;
            }
        }
    }
}

void rank()
{
    Lutador rank[30];
    for (int i = 0; i < 30; i++)
    {
        for (int j = i + 1; j < 30; j++)
        {
            if (personagem[i].vitorias < personagem[j].vitorias)
            {
                rank[i].vitorias = personagem[j].vitorias;
                strcpy(rank[i].nome, personagem[j].nome);
            }
        }
    }

    for (int k = 0; k < 30; k++)
    {
        textcolor(LIGHT_GREEN);
        printf("\n%i - %s - %i vitorias\n", k + 1, rank[k].nome, rank[k].vitorias);
    }
}

void jogo()
{
    int jogadores[3], inimigos[3], round = 1, vitorias = 0, derrotas = 0;
    system("cls");
    definirStatus();
    printLutadores();
    definirJogadores(jogadores);
    // começa o round
    while (round <= 9)
    {
        definirTimeInimigo(inimigos);

        // menu do round
        system("cls");
        textcolor(LIGHT_RED);
        printf("\n\n\n         @@@       @@@   @@@@@@@@   @@@@@@      @@@@@@@    @@@@@@      @@@@@@@@@@    @@@@@@   @@@@@@@   @@@@@@@  @@@@@@@@  \n         @@@       @@@  @@@@@@@@@  @@@@@@@@     @@@@@@@@  @@@@@@@@     @@@@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@  @@@@@@@@  \n         @@!       @@!  !@@        @@!  @@@     @@!  @@@  @@!  @@@     @@! @@! @@!  @@!  @@@  @@!  @@@    @@!    @@!       \n         !@!       !@!  !@!        !@!  @!@     !@!  @!@  !@!  @!@     !@! !@! !@!  !@!  @!@  !@!  @!@    !@!    !@!       \n         @!!       !!@  !@! @!@!@  @!@!@!@!     @!@  !@!  @!@!@!@!     @!! !!@ @!@  @!@  !@!  @!@!!@!     @!!    @!!!:!    \n         !!!       !!!  !!! !!@!!  !!!@!!!!     !@!  !!!  !!!@!!!!     !@!   ! !@!  !@!  !!!  !!@!@!      !!!    !!!!!:    \n         !!:       !!:  :!!   !!:  !!:  !!!     !!:  !!!  !!:  !!!     !!:     !!:  !!:  !!!  !!: :!!     !!:    !!:       \n          :!:      :!:  :!:   !::  :!:  !:!     :!:  !:!  :!:  !:!     :!:     :!:  :!:  !:!  :!:  !:!    :!:    :!:       \n          :: ::::   ::   ::: ::::  ::   :::      :::: ::  ::   :::     :::     ::   ::::: ::  ::   :::     ::     :: ::::  \n         : :: : :  :     :: :: :    :   : :     :: :  :    :   : :      :      :     : :  :    :   : :     :     : :: ::   \n         ");

        printf("\n\n                                                          Round %i :", round);
        printf("\n\n\n                         Time 1 [%s][%s][%s]           Time 2 [%s][%s][%s]\n", personagem[jogadores[0]].nome, personagem[jogadores[1]].nome, personagem[jogadores[2]].nome, personagem[inimigos[0]].nome, personagem[inimigos[1]].nome, personagem[inimigos[2]].nome);

        while (vitorias < 3 && derrotas < 3)
        {
            luta(jogadores, inimigos, &vitorias, &derrotas);
            if (derrotas == 3)
            {
                textcolor("RED");
                printf("\n                                                          Game Over, voce perdeu!\n");
                //rank();
                system("pause");
                round = 9;
            }
            if (vitorias == 3)
            {
                textcolor("LIGHT_GREEN");
                printf("\n                                                          Parabens, proximo Round!\n");
                personagem[jogadores[0]].vida = 100;
                personagem[jogadores[1]].vida = 100;
                personagem[jogadores[2]].vida = 100;
                system("pause");
            }
        }
        round++;
        vitorias = 0;
        derrotas = 0;
    }
    if (round >= 9 && (personagem[jogadores[0]].vida == 100) || (personagem[jogadores[1]].vida == 100) || (personagem[jogadores[2]].vida == 100))
    {
        system("cls");
        textcolor("LIGHT_MAGENTA");
        printf("                                                          Parabens, voce derrotou a Liga da Morte!");
        // rank();
        system("pause");
    }
}

int main()
{
    srand(time(NULL));
    fullscreen();
    char game = '1';
    int criar = 0;
    while (game == '1' || game == '2' || game == '3')
    {
        // menu
        system("cls");
        textcolor(RED);
        printf("\n\n\n           888b     d888                  888             888     888    d8P                         888               888    \n           8888b   d8888                  888             888     888   d8P                          888               888    \n           88888b.d88888                  888             888     888  d8P                           888               888    \n           888Y88888P888  .d88b.  888d888 888888  8888b.  888     888d88K      .d88b.  88888b.d88b.  88888b.   8888b.  888888 \n           888 Y888P 888 d88  88b 888P    888         88b 888     8888888b    d88  88b 888  888  88b 888  88b      88b 888    \n           888  Y8P  888 888  888 888     888    .d888888 888     888  Y88b   888  888 888  888  888 888  888 .d888888 888    \n           888       888 Y88..88P 888     Y88b.  888  888 888     888   Y88b  Y88..88P 888  888  888 888 d88P 888  888 Y88b.  \n           888       888   Y88P   888       Y888  Y888888 888     888    Y88b   Y88P   888  888  888 88888P    Y888888   Y888");
        printf("\n\n");
        textcolor(DARK_GRAY);
        printf("\n                                                       1-Start\n                                                       2-Criar Personagem\n                                                       3-Fullscreen\n                                                       4-Exit");
        game = getch();
        switch (game)
        {
        case '1':
            if (criar == 1)
            {
                jogo();
            }
            else
            {
                lutadoresProntos();
                jogo();
            }
            break;
        case '2':
            // chama o criador de personagem
            criadorLutador();
            criar = 1;
            break;
        case '3':
            fullscreen();
            break;
        case '4':
            textcolor(MAGENTA);
            printf("\n                                 Obrigado por jogar!//Thanks for playing! ~ NiCS\n");
            exit(0);
            break;
        }
    }
}
