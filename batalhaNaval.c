#include <stdio.h>


float tabuleiro[10][10] = {0}; //DEFINIÇÃO DA MATRIZ TABULEIRO COMO GLOBAL

int barcoL(int posicX, int posicY, int posicVH);
int poder(int atk, int atkX, int atkY);
int tabuleiroF(void);

int main(void) { //FUNÇÃO MAIN / APRESENTAÇÃO DO TABULEIRO E NAVIOS

    printf("=========BATALHA NAVAL========\n");
    barcoL(1,1,0); //EXEMPLO BARCO 1
    barcoL(10,1,1); //EXEMPLO BARCO 2
    barcoL(6,2,2); //EXEMPLO BARCO 3
    barcoL(8,5,3); //EXEMPLO BARCO 4
    tabuleiroF();
    printf("=========BATALHA NAVAL========\n");
    printf("\n");

    printf("========PODERES NAVAIS=======\n");
    poder(1,5,2); //EXEMPLO PODER 1
    poder(2,3,6); //EXEMPLO PODER 2
    poder(3,8,6); //EXEMPLO PODER 2

    tabuleiroF();
    printf("========PODERES NAVAIS=======\n");

    return 0;
}

// FUNÇÃO PARA A CONSTRUÇÃO DO TABULEIRO
int tabuleiroF(void) {

    for (int contY = 1; contY <= 10; contY++) {
        for (int contX = 1; contX <= 10; contX++) {
            printf(" %0.f ", tabuleiro[contX][contY]);
        }
        printf("\n");
    }
    return 0;
}

//FUNÇÃO PARA A CONSTRUÇÃO DO BARCO
int barcoL(int posicX, int posicY, int posicVH) { //0=VERTICAL, 1=HORIZONTAL, 2=DIAG. DIREITA, 3=DIAG. ESQUERDA

    switch (posicVH) {
        int cont;
        case 0: // 0=VERTICAL
            cont = 1;
        while (cont <= 3) {
            cont++;
            tabuleiro[posicX][posicY] += 3;
            tabuleiro[posicX++][posicY];
        }
        break;
        case 1: // 1=HORIZONTAL
            cont = 1;
        while (cont <= 3) {
            cont++;
            tabuleiro[posicX][posicY] += 3;
            tabuleiro[posicX][posicY++];
        }
        break;
        case 2: // 2=DIAG. DIREITA
            cont = 1;
        while (cont <= 3) {
            cont++;
            tabuleiro[posicX][posicY] += 3;
            tabuleiro[posicX++][posicY++];
        }
        break;
        case 3: // 3=DIAG. ESQUERDA
            cont = 1;
        while (cont <=3) {
            cont++;
            tabuleiro[posicX][posicY] += 3;
            tabuleiro[posicX--][posicY++];
        }
        break;
        default:
            printf("\nOrientacao invalida\n");
    }
    return 0;
}

//DEFINIÇÃO DA FUNÇÃO PARA AS HABILIDADES
int poder(int atk, int atkX, int atkY) { // 1 = CONE, 2 = CRUZ, 3 = OCTOGONO
    switch (atk) {
        int cont, contX, contY;
        case 1: // ATAQUE EM CONE
            cont = 1;
            while (cont <= 3) {
                cont = 1;
                contX = atkX;
                contY = atkY;
                if (cont == 1) {
                    for (int i = 1; i <= 2; i++) {
                        tabuleiro[contX][contY] = 5;
                        tabuleiro[contX++][contY++];
                    }
                }
                cont++;
                if (cont == 2) {
                    for (int i = 1; i <= 5; i++) {
                        tabuleiro[contX][contY] = 5;
                        tabuleiro[contX--][contY];
                    }
                }
                cont++;
                if (cont == 3) {
                    tabuleiro[contX++][contY--];
                    for (int i = 1; i <= 3; i++) {
                        tabuleiro[contX++][contY];
                        tabuleiro[contX][contY] = 5;
                    }
                }
                cont++;
            }
            break;
        case 2: //ATAQUE EM CRUZ
            cont = 1;
            while (cont <= 2) {
                cont = 1;
                contX = atkX;
                contY = atkY;
                if (cont == 1) {
                    for (int i = 1; i <= 5; i++) {
                        tabuleiro[contX][contY] = 5;
                        tabuleiro[contX][contY++];
                    }
                }
                cont++;
                if (cont == 2) {
                    tabuleiro[contX-=2][contY-=3];
                    for (int i = 1; i <= 5; i++) {
                        tabuleiro[contX][contY] = 5;
                        tabuleiro[contX++][contY];
                    }
                }
                cont++;
            }
            break;
        case 3: //ATAQUE EM "OCTOGONO"
            cont = 1;
            contX = atkX;
            contY = atkY;
            while (cont <= 6) {
                if (cont == 1) {
                    for (int i = 1; i <= 1; i++) {
                        tabuleiro[contX][contY] = 5;
                        tabuleiro[contX++][contY++];
                    }
                }
                cont++;
                if (cont == 2) {
                    for (int i = 1; i <= 3; i++) {
                        tabuleiro[contX][contY] = 5;
                        tabuleiro[contX--][contY];
                    }
                }
                cont++;
                if (cont == 3) {
                    tabuleiro[contX--][contY++];
                    for (int i = 1; i <= 6; i++) {
                        tabuleiro[contX][contY] = 5;
                        tabuleiro[contX++][contY];
                    }
                }
                cont++;
                if (cont == 4) {
                    tabuleiro[contX--][contY++];
                    for (int i = 1; i <= 3; i++) {
                        tabuleiro[contX--][contY];
                        tabuleiro[contX][contY] = 5;
                    }
                }
                cont++;
                if (cont == 5) {
                    tabuleiro[contX++][contY++];
                    for (int i = 1; i <= 1; i++) {
                        tabuleiro[contX][contY] = 5;
                    }
                }
                cont++;
            }
            break;
        default: // CASO O PODER SEJA INVALIDO
            printf("poder invalido");
    }
    return 0;
}

