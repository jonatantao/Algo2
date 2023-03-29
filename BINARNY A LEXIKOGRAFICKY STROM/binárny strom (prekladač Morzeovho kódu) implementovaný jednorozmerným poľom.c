#include <stdio.h>
#include <stdlib.h>
#define MAX 32

typedef struct{
    char pole[MAX];
}STROM;

void ini(STROM *st){
    int i;
    for(i = 0; i < MAX; i++)
        st->pole[i] = ' ';
}
// ,E,T,I,A,,,
void vloz(STROM *st, char mk[], char z){
    int i = 0, j;
    for(j = 0; j < strlen(mk); j++)
        if(mk[j] == '.')
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    st->pole[i] = z;
}

void hladaj(STROM st, char mk[], char *z){
    int i = 0, j;
    for(j = 0; j < strlen(mk); j++)
        if(mk[j] == '.')
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    *z = st.pole[i];
}

int main()
{
    STROM stp;
    ini(&stp);
    FILE *f;
    char mk[5];
    char c;
    f = fopen("vstup.txt","r");
    while(!feof(f)){
        fscanf(f,"%c%s\n",&c,mk);
        //printf("%s -> %c\n",mk,c);
        vloz(&stp,mk,c);
    }
    fclose(f);
    int i;
    for(i = 0; i < MAX; i++)
        printf("%c,",stp.pole[i]);
    printf("\n");

    hladaj(stp,"--.",&c);
    printf("%c\n",c);
}