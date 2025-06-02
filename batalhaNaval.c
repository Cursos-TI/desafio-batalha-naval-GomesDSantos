#include <stdio.h>


float tabuleiro[10][10] = {0}; //DEFINIÇÃO DA MATRIZ TABULEIRO COMO GLOBAL

int barcoL(int posicX, int posicY, int posicVH);
int tabuleiroF(void);

int main(void) { //FUNÇÃO MAIN / APRESENTAÇÃO DO TABULEIRO E NAVIOS

    printf("=========BATALHA NAVAL========\n");
    barcoL(2,2,0); //EXEMPLO BARCO 1
    barcoL(10,8,1); //EXEMPLO BARCO 2
    barcoL(3,7,2); //EXEMPLO BARCO 3
    barcoL(8,5,3); //EXEMPLO BARCO 4
    tabuleiroF();
    printf("=========BATALHA NAVAL========\n");

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
int barcoL(int posicX, int posicY, int posicVH) { //0=vertical, 1=horizontal, 2=diagonal direita, 3=diagonal esquerda

    switch (posicVH) {
        int cont;
        case 0:
            cont = 1;
        while (cont <= 3) {
            cont++;
            tabuleiro[posicX][posicY] += 3;
            tabuleiro[posicX++][posicY];
        }
        break;
        case 1:
            cont = 1;
        while (cont <= 3) {
            cont++;
            tabuleiro[posicX][posicY] += 3;
            tabuleiro[posicX][posicY++];
        }
        break;
        case 2:
            cont = 1;
        while (cont <= 3) {
            cont++;
            tabuleiro[posicX][posicY] += 3;
            tabuleiro[posicX++][posicY++];
        }
        break;
        case 3:
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

