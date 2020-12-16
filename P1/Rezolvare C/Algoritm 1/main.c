#include <limits.h>
#include <stdio.h>
#include "homework1.h"
#include <time.h>

int n;
FILE *files_in[10];
FILE *files_out[10];
int main()
{
    int result=0;
///generez filele pentru in si out
    generare(files_in,files_out);

    int i,j,test;
    FILE *in,*out;

    for(test=0; test<10; test++)
    {
        clock_t begin = clock();
        char namein[]= "testx_in.txt";
        char nameout[]= "testx_out.txt";
        namein[4]=test+48;
        nameout[4]=test+48;
        in=fopen(namein,"r");
        out=fopen(nameout,"w");
        ///din fiecare fila citesc dimensiunea si valorile
        fscanf(in,"%d",&n);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                fscanf(in,"%d",&cost[i][j]);
            }
        }
        int result=solve(n);
        ///afisez rezultatul
        fprintf(out,"%d",result);
        fclose(in);
        fclose(out);
        clock_t end = clock();
        printf("Test %d duration: %.3lf ms \n",test,(double)(end - begin)*1000 / CLOCKS_PER_SEC);


    }


}
/*
5
3 7 9 2 7
9 8 3 5 5
1 7 9 8 5
3 8 6 4 10
6 3 9 7 8
*/
