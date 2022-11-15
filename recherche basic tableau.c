#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE *fp;
	fp=fopen("algo_project.csv","w");
	int *t;
	int n, val, a, i = 10, j, exist;
	double timeSpent;

	printf("Essayer de trouver une valeur dans un tableau de %d elements\n", i);
	do {
	
	exist =0;
	t=(int*) malloc (sizeof(int)*i);
	fprintf(fp, "%d\t,", i);
	for (j=0; j<i; j++){
		t[j] = rand();
	}
	printf("\nDonnez la valeur que vous voulez trouver\n");
	scanf("%d", &val);
	
	clock_t begin = clock();
	for(j=0; j<i; j++){
	
		if (val == t[j]){
			exist = 1;
		}
	}
	clock_t end = clock();
	if ( exist == 1){
		printf("\nLa valeur exist");
	}
	else{
		printf("\nLa valeur n\'existe pas");
	}

	i= i * 10;
	timeSpent = (double)(end - begin);
	printf ("\nTS=%f", (float)timeSpent / CLOCKS_PER_SEC);
	fprintf(fp, "%f\t", timeSpent);
	printf("\nVoulez vous essayer avec %d elements? \n1: Yes\n2: No.\n", i);
	scanf("%d", &a);
	

	}while(a == 1);

	return 0;
}
