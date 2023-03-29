#include <stdio.h>
#include <stdlib.h>
#define ML (UZOL*)malloc(sizeof(UZOL))
#define MAX 4

//A,b,*,3

typedef struct uzol{
    char ss[15];
    struct uzol *pole[MAX];
}UZOL;

int posun(char z){
    switch(z){
        case 'A': return 0;
        case 'b': return 1;
        case '*': return 2;
        case '3': return 3;
        default: return -1;
    }
}

void ini(UZOL **lt){
    *lt = ML;
    strcpy((*lt)->ss,"");
    int i;
    for(i = 0; i < MAX; i++)
        (*lt)->pole[i] = NULL;
}

void vloz(UZOL *lt, char as[], char ss[]){
    int i,j;
    UZOL *pom = lt;
    for(i = 0; i < strlen(as); i++){
        if(pom->pole[posun(as[i])] == NULL){
            pom->pole[posun(as[i])] = ML;
            pom = pom->pole[posun(as[i])];
            strcpy(pom->ss,"none");
            for(j = 0; j < MAX; j++)
                pom->pole[j] = NULL;
        }else{
            pom = pom->pole[posun(as[i])];
        }
    }
    strcpy(pom->ss,ss);
}

void hladaj(UZOL *lt, char as[], char ss[]){
    int i = 0;
    int chyba = 0;
    UZOL *pom = lt;
    while(!chyba && i < strlen(as)){
        if(pom->pole[posun(as[i])] != NULL)
            pom = pom->pole[posun(as[i])];
        else
            chyba = 1;
        i++;
    }
    if(!chyba && strcmp(pom->ss,"none") != 0)
        strcpy(ss,pom->ss);
    else{
        fprintf(stderr,"slovo %s nie je v slovniku\n",as);
        strcpy(ss,"???");
    }
}

int main()
{
    UZOL *lst;
    ini(&lst);
    vloz(lst,"Ab*","PES");
    vloz(lst,"**","ROBIT");
    vloz(lst,"*3A","DVERE");
    vloz(lst,"AbA","ZLATO");
    char ret[20];
    strcpy(ret,"Abb");
    char rets[20];
    hladaj(lst,ret,rets);
    printf("%s -> %s\n",ret,rets);
    return 0;
}