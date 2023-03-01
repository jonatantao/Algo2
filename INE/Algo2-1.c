#define ML (ATOM*)MALLOC(sizeof(ATOM))


typedef struct{

	char meno[10];
	int c_b;
	int vek;
}PES;

typedef struct atom{
		
	PES*h;
	struct atom*nasl;
}ATOM;

int main()
{
	ATOM*p_a;
	p_a =ML;
	p_a->nasl=NULL;	
	p_a->h=(PES*)malloc(sizeof(PES));
	strcpy(p_a)->h->meno("pes");
	p_a->h->c_b=10;
	p_a->h->vek=5;
	
	ATOM*atom;
	pom=p_a;
	while(pom->nasl!=NULL){
		pom=pom->nasl;
	}
	pom->nasl=ML;
		
	
	
	
	
	
	return 0;
}