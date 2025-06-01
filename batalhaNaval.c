#include <stdio.h>


float tabuleiro[10][10] = {0}; //DEFINIÇÃO DA MATRIZ TABULEIRO COMO GLOBAL

int barcoL(int posicX, int posicY, int posicVH);
int tabuleiroF(void);

int main(void) { //FUNÇÃO MAIN / APRESENTAÇÃO DO TABULEIRO E NAVIOS

    printf("=========BATALHA NAVAL========\n");
    barcoL(3,3,1); //EXEMPLO BARCO 1
    barcoL(10,8,0); //EXEMPLO BARCO 2
    barcoL(6,7,1); //EXEMPLO BARCO 3
    tabuleiroF();
    printf("=========BATALHA NAVAL========\n");

    return 0;
}

// FUNÇÃO PARA A CONSTRUÇÃO DO TABULEIRO
int tabuleiroF(void) {

    for (int contX = 1; contX <= 10; contX++) {
        for (int contY = 1; contY <= 10; contY++) {
            printf(" %0.f ", tabuleiro[contX][contY]);
        }
        printf("\n");
    }
    return 0;
}

//FUNÇÃO PARA A CONSTRUÇÃO DO BARCO
int barcoL(int posicX, int posicY, int posicVH) { //0 orientacao vertical, 1 orientacao horizontal

    switch (posicVH) {
        int cont;
        case 0:
            cont = 1;
            while (cont <= 3) {
                cont++;
                tabuleiro[posicX][posicY];
                tabuleiro[posicX][posicY++] = 3;
            }
            break;
        case 1:
            cont = 1;
            while (cont <= 3) {
                cont++;
                tabuleiro[posicX][posicY];
                tabuleiro[posicX++][posicY] = 3;
            }
            break;
        default:
            printf("orientacao invalida");
    }
    return 0;
}

