#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} node ;

void addNode(node **tree, int key)
{
    node *tmpNode;
    node *tmpTree = *tree;

    node *elem = malloc(sizeof(node));
    elem->key = key;
    elem->left = NULL;
    elem->right = NULL;

    if(tmpTree)
    do
    {
        tmpNode = tmpTree;
        if(key > tmpTree->key )
        {
            tmpTree = tmpTree->right;
            if(!tmpTree) tmpNode->right = elem;
        }
        else
        {
            tmpTree = tmpTree->left;
            if(!tmpTree) tmpNode->left = elem;
        }
    }
    while(tmpTree);
    else  *tree = elem;
}

int searchNode(node *tree, int key)
{
    while(tree)
    {
        if(key == tree->key) return 1;

        if(key > tree->key ) tree = tree->right;
        else tree = tree->left;
    }
    return 0;
}
int hash (int val,int n)
{
    return (val % n);
}

int main()
{
    FILE *fp;
	fp=fopen("hashtab.csv","w");
    float temps;
    int n,i,val,a;
    do
    {
        printf("Donnez nbr des elments,");
        scanf("%d",&n);
        node **TTree ;
        TTree=malloc(n*sizeof(node));
        fprintf(fp, "%d", n);
        for(i=0;i<n;i++)
        {
            TTree[i]=NULL;
        }
        srand(time(NULL));
        for (i=0 ; i<n ; i++)
        {
            val=rand();
            addNode(&TTree[hash(val,n)],val);
        }
        printf("Donnez une valeur ,");
        scanf("%d",&val);
        clock_t start=clock();
        i=searchNode(TTree[hash(val,n)],val);
        printf("\n\n%d\n\n",i);
        clock_t end=clock();
        temps=(float)(end-start);
        printf ("\nTS=%f", (float)temps / CLOCKS_PER_SEC);
        fprintf(fp, "\n%f\r\t", temps);
        printf("\nVoulez vous essayer avec %d elements? \n1: Yes\n2: No.\n", i);
	    scanf("%d", &a);
    }while(a == 1);


        return 0;
}