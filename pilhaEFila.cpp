#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *prox;
};

struct Fila {
    struct No *cabeca, *cauda;
    int n;
};

void inverterFila(struct Fila *fila) {
    struct No *anterior = NULL;
    struct No *atual = fila->cabeca;
    struct No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    fila->cabeca = anterior;
}

int main() {
    int n, m, i, x, v[100001];
    struct Fila f;
    f.cabeca = f.cauda = NULL;
    f.n = 0;

    for (i = 0; i <= 100000; i++) v[i] = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        struct No *novo = (struct No*)malloc(sizeof(struct No));
        novo->valor = x;
        novo->prox = NULL;
        if (f.cabeca == NULL) {
            f.cabeca = novo;
            f.cauda = novo;
        } else {
            f.cauda->prox = novo;
            f.cauda = novo;
        }
        f.n++;
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        v[x]++;
    }

    inverterFila(&f);

    while (f.cabeca != NULL) {
        x = f.cabeca->valor;
        if (v[x] == 0) {
            printf("%d ", x);
        }
        struct No *temp = f.cabeca;
        f.cabeca = f.cabeca->prox;
        free(temp);
        f.n--;
    }

    printf("\n");

    return 0;
}
