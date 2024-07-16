#include<stdio.h>

struct No {

    int valor;
    No *prox;

    No() {
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No *inicio, *fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }


  void inserirFinal(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void imprimir() {

        No *aux = inicio;

        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }

        printf("\n");

    }

    void removerInicio() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }



    void atividade1(int x) {

        for (int i = 0; i < x; i++) {
            removerFinal();
        }

    }


    void atividade2() {
        if (n <= 1) return;
        if (n == 2) {
            removerFinal();
            return;
        }
        No* segundo = inicio->prox;
        inicio->prox = segundo->prox;
        delete(segundo);
        n--;
    }



    void atividade3() {
        inserirFinal(n);
    }

    void atividade4(int x) {

        for (int i = 1; i <= x; i++) {
            inserirFinal(i);
        }

    }

    void atividade5(int v) {
        if (n <= 1) return;
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        No* novo = new No(v);
        aux->prox = novo;
        novo->prox = fim;
        n++;
    }

};

int main() {

    Lista l;



    l.atividade1(5);
    l.atividade2();
    l.atividade3();
    l.atividade4(8);
    l.atividade5(7);


    l.imprimir();

//    printf("%d\n", l.());

    return 0;
}
