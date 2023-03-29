#include <stdio.h>
#include <stdlib.h>
#define ML (UZOL*)malloc(sizeof(UZOL))

//     |
//    ' '
//   /   \
//  'E'  'T'
// /  \  / \
//'I' 'A''N' 'M'
// --- 'O'
// ... 'S'

typedef struct uzol{
    char c;
    struct uzol *L, *P;
}UZOL;

//inicializacia
//vlozenie uzla
//vyhladavnie
//odstranenie (rekurzivne)

void ini(UZOL **t){
    *t = ML;
    (*t)->c = ' ';
    (*t)->L = (*t)->P = NULL;
}

void vloz(UZOL *t, char mk[5], char lz){
    int i;
    UZOL *pom = t;
    for(i = 0; i < strlen(mk); i++){
        if(mk[i] == '.'){
            if(pom->L == NULL){
                pom->L = ML;
                pom = pom->L;
                pom->L = pom->P = NULL;
                //pom->c = '@';
            }else{
                pom = pom->L;
            }
        }else{
            //mk[i] == '-'; nie je prikaz
            if(pom->P == NULL){
                pom->P = ML;
                pom = pom->P;
                pom->L = pom->P = NULL;
            }else{
                pom = pom->P;
            }
        }
    }
    pom->c = lz;
}

void hladaj(UZOL *t, char mk[], char *lz){
    UZOL *pom = t;
    int chyba = 0;
    int i = 0;
    while(!chyba && i < strlen(mk)){
        if(mk[i] == '.')
            if(pom->L != NULL)
                pom = pom->L;
            else
                chyba = 1;
        else
            if(pom->P != NULL)
                pom = pom->P;
            else
                chyba = 1;
        i++;
    }
    if(!chyba) *lz = pom->c;
     else{
            *lz = '@';
            fprintf(stderr,"tento kod neexistuje\n");
     }
}

int main()
{
    UZOL *st;
    ini(&st);
    char ret[5];
    char l;
    FILE *f;
    f = fopen("vstup.txt","r");
    while(!feof(f)){
        fscanf(f,"%c%s\n",&l,ret);
        //printf("%s -> %c\n", ret,l);
        vloz(st,ret,l);
    }
    fclose(f);

    strcpy(ret, "----");
    hladaj(st,ret, &l);
    printf("%s -> %c\n", ret, l);
    return 0;
}