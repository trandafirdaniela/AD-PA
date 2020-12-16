#include <stdio.h>
#include <stdlib.h>
#include "homework2.h"
#include <time.h>
int n;


FILE *files_in[10];
FILE *files_out[10];
int main()
{

    int result=0;
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
        //printf("%s",name);
        in=fopen(namein,"r");
        out=fopen(nameout,"w");
        fscanf(in,"%d",&n);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                fscanf(in,"%d",&a[i][j]);
            }
        int result=solve(n);
        fprintf(out,"%d",result);
        fclose(in);
        fclose(out);
        clock_t end = clock();
        printf("Test %d duration: %.3lf ms \n",test,(double)(end - begin)*1000 / CLOCKS_PER_SEC);
    }
}
