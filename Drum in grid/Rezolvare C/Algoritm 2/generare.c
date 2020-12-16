#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "homework2.h"
FILE *files_in[10];
FILE *files_out[10];

int generare()
{
    ///FILE *files[10];
    for (int test = 0; test < 10; test++)
    {
        char filename[20];
        sprintf(filename, "test%d_in.txt", test);
        files_in[test] = fopen(filename, "w+");

        sprintf(filename, "test%d_out.txt", test);
        files_out[test] = fopen(filename, "w+");

        int n=(test+1)*50;
        //fprintf(files_in[i],"%d",n);
        fprintf(files_in[test],"%d\n",n);
        for(int linie=1; linie<=n; linie++)
        {
            for(int coloana=1; coloana<=n; coloana++)
                fprintf(files_in[test],"%d ",rand());
            fprintf(files_in[test],"\n");
        }
        fclose(files_in[test]);
        fclose(files_out[test]);
    }
}
