#include <stdio.h>
#include <stdlib.h>
#include "homework1.h"
///functie care returneaza minimul dintre doua numere
int minim(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}
///functie care returneaza valoarea absoluta a diferentei a doua numere
int absolut(int x,int y)
{
    if(x>y)
        return x-y;
    else
        return y-x;
}
///algoritmul folosit pentru rezolvarea cerintei
int solve(int n)
{
    int i,j;

    int sum[n+1][n+1]; ///matricea in care formez costul
    int inf=2000000000;
    for(i=0; i<=n; i++)
        sum[0][i]=inf,sum[i][0]=inf;

    sum[0][1]=sum[1][0]=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            ///aleg pentru fiecare varianta care are suma absoluta minima
            sum[i][j]=minim(absolut(cost[i][j-1],cost[i][j])+sum[i][j-1],absolut(cost[i-1][j],cost[i][j])+sum[i-1][j]);



        }

    }
    ///rezultatul este valoarea ultimului element din matrice - costul primului element

    int result=sum[n][n]-cost[1][1];
    return result;

}
