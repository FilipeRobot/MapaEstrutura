// Meu RA: 1729501-5
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Constante
#define tamanho 8
struct filaRa{
    int numRa[tamanho];
    int ini, fim;
};
struct pilhaRaInver{
    int numRaInv[tamanho];
    int ini, topo;
};

filaRa MeuRa;
pilhaRaInver MeuRaInv;
//Portotipação
void inserirRa(int elemento);
void inserirRaInverso(int elemento);
int removerRA();

int main()
{
    setlocale(LC_ALL, "portuguese");
    for (int i = 0; i < tamanho; i++){
        int aux;
        printf("Informe o %d numero do RA: ", i+1);
        scanf("%d", &aux);
        inserirRa(aux);
    }
    //------------Mostrar RA Na ordem-------------------
    system("cls");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", MeuRa.numRa[i]);
        inserirRaInverso(MeuRa.numRa[i]);
    }
    printf("\n");
    //-----------Mostrar RA Inverso---------------------
    for (int i = 0; i < tamanho; i++){
        int aux = removerRA();
        printf("%d ", aux);
    }
    //-------------Fim do Programa----------------------
    printf("\n=====================================\n");
    system("pause");
    return 0;
}

void inserirRaInverso(int elemento){
    if(MeuRaInv.topo == tamanho){
        printf("pilha Cheia.\n");
        system("pause");
    }else{
        MeuRaInv.numRaInv[MeuRaInv.topo] = elemento;
        MeuRaInv.topo++;
    }
}

void inserirRa(int elemento){
    if(MeuRa.fim == tamanho){
        printf("Fila cheia.\n");
        system("pause");
    }else{
        MeuRa.numRa[MeuRa.fim] = elemento;
        MeuRa.fim++;
    }
}

int removerRA(){
    int elemento;
    if(MeuRaInv.topo == MeuRaInv.ini){
        printf("Pilha vazia.\n");
        system("pause");
    }else{
        MeuRaInv.topo--;
        elemento = MeuRaInv.numRaInv[MeuRaInv.topo];
        return elemento;
    }
}
