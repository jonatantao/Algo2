#include <stdio.h>
#include <stdlib.h>
#define ML (UZOL*)malloc(sizeof(UZOL))
#define MAX ('Z' - 'A')

typedef struct uzol{
    char ss[15];
    struct uzol *pole[MAX];
}UZOL;

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
        if(pom->pole[as[i] - 'A'] == NULL){
            pom->pole[as[i] - 'A'] = ML;
            pom = pom->pole[as[i] - 'A'];
            strcpy(pom->ss,"none");
            for(j = 0; j < MAX; j++)
                pom->pole[j] = NULL;
        }else{
            pom = pom->pole[as[i] - 'A'];
        }
    }
    strcpy(pom->ss,ss);
}

void hladaj(UZOL *lt, char as[], char ss[]){
    int i = 0;
    int chyba = 0;
    UZOL *pom = lt;
    while(!chyba && i < strlen(as)){
        if(pom->pole[as[i] - 'A'] != NULL)
            pom = pom->pole[as[i] - 'A'];
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
    vloz(lst,"DOG","PES");
    vloz(lst,"DO","ROBIT");
    vloz(lst,"DOOR","DVERE");
    vloz(lst,"GOLD","ZLATO");
    char ret[20];
    strcpy(ret,"DOOR");
    char rets[20];
    hladaj(lst,ret,rets);
    printf("%s -> %s\n",ret,rets);
    return 0;
}