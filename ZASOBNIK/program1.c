#include <stdio.h>

typedef struct{
    char znacka [25];
    char typ [15];
    int vek;
    int cena;
}AUTO;

typedef struct atom{
    AUTO a;
    struct atom *nasl;
}ATOM;

int main() {

    ATOM *p_a;
    p_a=(ATOM*)malloc(sizeof(ATOM));
    strcpy(p_a->a.znacka,"Ford");
    strcpy(p_a->a.typ,"Focus");
    p_a->a.vek = 16;
    p_a->a.cena = 2000;
    p_a->nasl = NULL;

    printf("%s, %s, %d, %d", p_a->a.znacka,p_a->a.typ, p_a->a.vek, p_a->a.cena);

    return 0;
}