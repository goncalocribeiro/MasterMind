#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

struct elementosRanking{

    char nome[20];
    int score;

}a;

struct elementosRanking ranking[10]; //ARRAY PARA GUARDAR NOME E SCORE DOS JOGADORES
int posicaoRanking = 0; //VARIAVEL GLOBAL QUE DETERMINA A POSICAO ONDE VAI SER REGISTADO UM NOVO SCORE

void clear (){

    while(getchar() != '\n');

}

void helper(){

    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    char s;

    system("CLS");

    printf("\n\tPrimeiro de tudo, precisa de saber quais as cores existentes nesta versao do Master Mind. Como tal, as cores possiveis de usar sao amarelo, azul, laranja e verde.\n");
    printf("\tE necessario ter tambem em conta que tem 10 tentativas para adivinhar a combinacao e submeter o seu resultado a ranking, de outra forma perde o jogo.\n");

    SetConsoleTextAttribute (hConsole, 14);
    printf("\nCOMECAR A JOGAR:\n");
    SetConsoleTextAttribute (hConsole, 15);
    printf("\n\tEscolha a opcao 1 'Novo jogo'.\n");
    printf("\tDe seguida vai-lhe ser pedido para inserir a primeira cor, depois de a escrever pressione ENTER para lhe ser pedida a segunda cor e assim sucessivamente. Depois de ter inserido as quatro cores, vai-lhe ser mostrado quantos pretos (cores que existem na chave e que estao na posicao correta) e quantos brancos (cores que existem na chave mas que estao na posicao errada) a sua tentativa possui.\n");
    printf("\tSe a sua tentativa estiver com as cores certas e na sequencia certa, o resultado da sua tentativa sera 'Preto: 4 Branco: 0'\n");
    printf("\tApos isto, sera mostrada uma mensagem de congratulacao e devera inserir o seu nome para que seja registado no ranking.\n");
    printf("\tOs jogadores que conseguem ganhar com o menor numero de tentativas, ficam melhor classificados.\n");

    SetConsoleTextAttribute (hConsole, 14);
    printf("\nRESUMINDO:\n");
    SetConsoleTextAttribute (hConsole, 15);
    SetConsoleTextAttribute (hConsole, 6);
    printf("\n\tTentativas:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("10\n");
    SetConsoleTextAttribute (hConsole, 6);
    printf("\tSequencia de 4 cores:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("amarelo, azul, laranja ou verde\n");
    SetConsoleTextAttribute (hConsole, 6);
    printf("\tPasso 1: ");
    SetConsoleTextAttribute (hConsole, 15);
    printf("Escolher a opcao 'Novo jogo' no menu;\n");
    SetConsoleTextAttribute (hConsole, 6);
    printf("\tPasso 2:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("Introduzir sequencias;\n");
    SetConsoleTextAttribute (hConsole, 6);
    printf("\tPasso 3:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("Apos conseguir descobrir a sequencia, introduzir nome para ranking;\n");

    SetConsoleTextAttribute (hConsole, 12);
    printf("\nPrima enter para voltar ao menu de jogo...");
    SetConsoleTextAttribute (hConsole, 15);
    clear();
    s = getchar();

    system("CLS");

    main();

}

void faq(){

    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    system("CLS");

    char s;

    printf("O Mastermind e um jogo de tabuleiro inventado por Mordechai Meirowitz. Publicado em 1971, o jogo vendeu mais de 50 milhoes de tabuleiros em 80 paises, tornando-se o jogo mais bem sucedido da decada de 1970, sendo que os pinos do jogo oficial sao azul, amarelo, verde, rosa, roxo e laranja\n");
    SetConsoleTextAttribute (hConsole, 14);
    printf("\nResumidamente:\n");

    SetConsoleTextAttribute (hConsole, 6);
    printf("\n\tDesigner/Criador:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("\tMordechai Meirowitz\n");

    SetConsoleTextAttribute (hConsole, 6);
    printf("\tTempo existente:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("\tDesde 1970\n");

    SetConsoleTextAttribute (hConsole, 6);
    printf("\tFormas de jogar:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("\tPapel, tabuleiro e computador\n");

    SetConsoleTextAttribute (hConsole, 6);
    printf("\tJogadores:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("\t\t2 Jogadores\n");

    SetConsoleTextAttribute (hConsole, 6);
    printf("\tIdade Minima:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("\t\t8 anos\n");

    SetConsoleTextAttribute (hConsole, 6);
    printf("\tTempo de jogo:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("\t\tEntre 10 a 30 Minutos\n");

    SetConsoleTextAttribute (hConsole, 6);
    printf("\tNumero de pinos:");
    SetConsoleTextAttribute (hConsole, 15);
    printf("\tDesde 3 ate 8\n");

    SetConsoleTextAttribute (hConsole, 14);
    printf("\nEsta versao foi realizada por Goncalo Ribeiro e Andre Mendonca do curso de TPSI da EST no IPS, para a disciplina de Algoritmos no ano letivo 2013-2014\n");

    SetConsoleTextAttribute (hConsole, 12);
    printf("\nPrima enter para voltar ao menu de jogo...");
    clear();
    s = getchar();

    system("CLS");

    main();

}

//FUNCAO VERRANKING
int verRanking(){

    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    system("CLS");

    int x=0, y=0, trocar=0;
    char trocaNome[20], s;

    for (x=0; x < 10 - 1; x++){

        for (y=0; y < 10 - x - 1; y++){

            if (ranking[y].score > ranking[y+1].score && ranking[y+1].score != 0){

                trocar = ranking[y].score; //GUARDA O MAIOR
                ranking[y].score = ranking[y+1].score; //GUARDA O MAIS PEQUENO NA POSICAO DO MAIOR
                ranking[y+1].score = trocar; //GUARDA O MAIOR NA POSICAO DO MAIS PEQUENO

                strncpy(trocaNome, ranking[y].nome, 20);
                strncpy(ranking[y].nome, ranking[y+1].nome, 20);
                strncpy(ranking[y+1].nome, trocaNome, 20);
            }
        }
    }
        SetConsoleTextAttribute (hConsole, 6);
        printf("\t\t\tRANKING\n\n");

    for (x=0; x < 10; x++){


        SetConsoleTextAttribute (hConsole, 14);
        printf("\n%d LUGAR",x+1);
        SetConsoleTextAttribute (hConsole, 15);
        printf("\n\tNome: %s\n\tScore: %d\n",ranking[x].nome, ranking[x].score);

    }

    SetConsoleTextAttribute (hConsole, 12);
    printf("\nPrima enter para voltar ao menu de jogo...");
    SetConsoleTextAttribute (hConsole, 15);
    clear();
    s = getchar();

    system("CLS");

    main();

}
//FUNCAO VERRANKING

//FUNCAO INTRODUZIR_RANKING
int introduzirRanking(int score){

    printf("\nRegista-te no ranking!\n");
    printf("\nNome: ");
    clear();
    gets(a.nome);
    a.score = score;

    ranking[posicaoRanking] = a;
    posicaoRanking++;

    verRanking();
}
//FUNCAO INTRODUZIR_RANKING

//FUNCAO NOVOJOGO
void novoJogo(){ // 1 = Amarelo; 2 = Azul; 3 = Laranja; 4 = Verde

    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    system("CLS");

    int escolhaComputador[4], escolhaJogadorInt[4], verificacao[4];
    char escolhaJogador[10][200], cores[10][200], s;
    int myRand, i=0, x=0, branco=0, preto=0, tentativas=1;

    srand(time(NULL));

    for(i=0; i < 4; i++){ // O computador faz a escolha aleatoria da combinacao de cores

        myRand = rand() % 4 + 1;
        escolhaComputador[i] = myRand; //Guarda a escolha do computador no array escolhaComputador
    }

    for (tentativas=1; tentativas <= 10; tentativas++){ //10 tentativas

        if(preto == 4){ // VERIFICA SE A COMBINACAO ESTA CERTA

            SetConsoleTextAttribute (hConsole, 2);
            printf("\nParabens !! Conseguiu descobrir a combinacao de cores a %d tentativa\n", tentativas - 1);
            SetConsoleTextAttribute (hConsole, 15);
            printf("\n\n\n");

            introduzirRanking(tentativas - 1);
            break;

        } else {

            SetConsoleTextAttribute (hConsole, 14);
            printf("\nTentativa %d/10\n", tentativas);
            SetConsoleTextAttribute (hConsole, 15);

            for(i=0; i < 4; i++){ // 4 cores para cada tentativa

                printf("\t%d cor: ", i+1);
                scanf("%s", escolhaJogador[i]);

                /*TRANSFORMA CORES EM NUMERO INTEIRO CORRESPONDENTE*/
                if((strcmp(escolhaJogador[i], "Amarelo")) == 0 || (strcmp(escolhaJogador[i], "AMARELO")) == 0|| (strcmp(escolhaJogador[i], "amarelo")) == 0){

                    escolhaJogadorInt[i] = 1;

                } else if((strcmp(escolhaJogador[i], "Azul")) == 0 || (strcmp(escolhaJogador[i], "AZUL")) == 0|| (strcmp(escolhaJogador[i], "azul")) == 0){

                    escolhaJogadorInt[i] = 2;

                } else if((strcmp(escolhaJogador[i], "Laranja")) == 0 || (strcmp(escolhaJogador[i], "LARANJA")) == 0|| (strcmp(escolhaJogador[i], "laranja")) == 0){

                    escolhaJogadorInt[i] = 3;

                } else if((strcmp(escolhaJogador[i], "Verde")) == 0 || (strcmp(escolhaJogador[i], "VERDE")) == 0|| (strcmp(escolhaJogador[i], "verde")) == 0){

                    escolhaJogadorInt[i] = 4;

                }
                /*TRANSFORMA CORES EM NUMERO INTEIRO CORRESPONDENTE*/

            }

            //REPOE A ZERO OS VALOR DO ARRAY "VERIFICACAO" E DAS VARIAVEIS QUE CONTAM OS BRANCOS E OS PRETOS
            verificacao[0] = 0;
            verificacao[1] = 0;
            verificacao[2] = 0;
            verificacao[3] = 0;
            branco = 0;
            preto = 0;

            for(i=0; i < 4; i++){ //VERIFICA SE A POSICAO ATUAL E IGUAL A DA CHAVE -> "escolhaComputador"

                if(escolhaJogadorInt[i] == escolhaComputador[i]){

                    verificacao[i] = 2; //PRETO

                } else {

                    for(x=0; x < 4; x++){ //PERCORRE CADA POSICAO DO ARRAY DA TENTATIVA -> "escolhaJogadorInt"

                        if((escolhaJogadorInt[i] == escolhaComputador[x]) && verificacao[x] == 0){

                            verificacao[x] = 1; //BRANCO
                            break;
                        }

                    }

                }

            }


            for(i=0; i < 4; i++){ //VERIFICA QUANTOS PRETOS E QUANTOS BRANCOS EXISTEM DENTRO DO ARRAY "VERIFICACAO"

                if (verificacao[i] == 2){

                    preto++;

                } else if (verificacao[i] == 1){

                    branco++;

                }

            }

            SetConsoleTextAttribute (hConsole, 2);
            printf("\nPretos: %d\n", preto);

            SetConsoleTextAttribute (hConsole, 12);
            printf("Brancos: %d\n", branco);

            SetConsoleTextAttribute (hConsole, 15);

        } //FECHA SE PRETO != 4

        if (tentativas == 10 && preto != 4) {

            for(i=0; i<4; i++){

                if(escolhaComputador[i] == 1){

                    strncpy(cores[i], "amarelo", 8);

                }

                if(escolhaComputador[i] == 2){

                    strncpy(cores[i], "azul", 5);

                }

                if(escolhaComputador[i] == 3){

                    strncpy(cores[i], "laranja", 8);

                }

                if(escolhaComputador[i] == 4){

                    strncpy(cores[i], "verde", 6);

                }

            }

            SetConsoleTextAttribute (hConsole, 12);
            printf("\nGAME OVER!!! Nao conseguiu descobrir a combinacao! :(\nA combinacao de cores era: %s - %s - %s - %s\n", cores[0], cores[1], cores[2], cores[3]);
            SetConsoleTextAttribute (hConsole, 15);

            printf("\nPrima enter para voltar ao menu de jogo...");
            clear();
            s = getchar();

            system("CLS");

            main();

        }

    } //FECHA TENTATIVAS

}
//FUNCAO NOVOJOGO

main()
{
    int opcao;

    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute (hConsole, 2);
    printf("********************************************************************\n");
    printf("*                                                                  *\n");
    printf("*                                                                  *\n");
    printf("*                                                                  *\n");
    printf("*  *** ***  ******  *****  *******  *****  *****                   *\n");
    SetConsoleTextAttribute (hConsole, 14);
    printf("*  *  *  *  *    *  *         *     *      *   *                   *\n");
    printf("*  *     *  ******  *****     *     *****  *****                   *\n");
    printf("*  *     *  *    *      *     *     *      * *                     *\n");
    SetConsoleTextAttribute (hConsole, 6);
    printf("*  *     *  *    *  *****     *     *****  *   *                   *\n");
    printf("*  _____________________________________________                   *\n");
    printf("*                                                                  *\n");
    SetConsoleTextAttribute (hConsole, 12);
    printf("*                             *** ***  *******  **    *  ****      *\n");
    printf("*                             *  *  *     *     * *   *  *   *     *\n");
    printf("*                             *     *     *     *  *  *  *    *    *\n");
    SetConsoleTextAttribute (hConsole, 5);
    printf("*                             *     *     *     *   * *  *   *     *\n");
    printf("*                             *     *  *******  *    **  ****      *\n");
    printf("*                             _________________________________    *\n");
    SetConsoleTextAttribute (hConsole, 9);
    printf("*                                                                  *\n");
    printf("*                                                                  *\n");
    printf("********************************************************************\n");
    SetConsoleTextAttribute (hConsole, 15);
    printf("\n\t\t    BEM VINDO AO MASTER MIND");
    printf("\n\n\t\t\t 1- Novo jogo\n");
    printf("\t\t\t 2- Ranking\n");
    printf("\t\t\t 3- Como jogar ?\n");
    printf("\t\t\t 4- Curiosidades\n");
    printf("\t\t\t 0- Sair\n");

    do{

        printf("\nEscolha a opcao: ");
        scanf("%d", &opcao);

    } while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 0);

    switch (opcao) {

        case 1: novoJogo();break;
        case 2: verRanking();break;
        case 3: helper();break;
        case 4: faq ();break;
        case 0: system("CLS"); exit(0);break;

    }

}
