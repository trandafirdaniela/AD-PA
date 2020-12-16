

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "homework2.h"

void push_element_begining(struct g_node *head,struct pairr new_element_value)
{
    struct g_node *new_element = malloc(sizeof(struct g_node));

    new_element->info = new_element_value;
    new_element->next = head->next;
    head->next = new_element;
}

void push_element_end(struct g_node *head,struct pairr new_element_value)
{
    struct g_node *new_element = malloc(sizeof(struct g_node));
    struct g_node *iterator = head;
    struct g_node *last_element;

    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    last_element = iterator;

    last_element->next = new_element;
    new_element->info = new_element_value;
    new_element->next = NULL;
}

struct pairr pop_element_begining(struct g_node *head)
{
    struct g_node *poped_element;
    struct pairr aux;
    poped_element = head->next;
    head->next = poped_element->next;
    aux = poped_element->info;
    free(poped_element);

    return aux;
}


int list_empty(struct g_node *head)
{
    if(head->next==NULL)
        return 0;
    return 1;
}
int minim(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int absolut(int a,int b)
{
    if(a>b)
        return a-b;
    else
        return b-a;
}
///functia care rezolva cerinta
int solve(int n)
{
    struct g_node *head = malloc(sizeof(struct g_node));
    head->next = NULL;
    int d[n][n],i,j;
    int  inf=2000000000;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            d[i][j]=inf;
    d[0][0]=0;

    struct pairr aux;
    aux.first=aux.second=0;
    push_element_end(head, aux);

/// introduc in coada coltul stanga sus
    /// apoi o sa pornesc un bfs din colt spre coltul opus ca sa iau in ordine toate  punctele din matrice

    while(list_empty(head)==1)
    {
        /// pozitia actuala
        aux=pop_element_begining(head);
        i=aux.first;
        j=aux.second;
        if(i+1<n)
        {
            /// vecinul de jos e in matrice
            if(d[i+1][j]==inf)
            {
                /// daca e diferit inseamna ca acesta este primul vecin care intra in i+1 j
                /// deci putem adauga i+1 j in coada de la bfs
                aux.first=i+1;
                aux.second=j;
                push_element_end(head,aux);

            }
            /// indiferent daca e primul sau ultimul vecin facem minim
            d[i+1][j]=minim(d[i+1][j],d[i][j]+absolut(a[i][j],a[i+1][j]));
        }
        /// facem acelasi lucru si pentru j+1
        if(j+1<n)
        {
            if(d[i][j+1]==inf)
            {
                aux.first=i;
                aux.second=j+1;
                push_element_end(head,aux);
            }
            d[i][j+1]=minim(d[i][j+1],d[i][j]+absolut(a[i][j],a[i][j+1]));
        }
        /// e clar ca se poate ajunge in starea i si j doar din i-1 j sau din i j-1 de aia
        /// pot adauga nodul in coada abia dupa ce d[i][j] este diferit de inf
        /// adica este ultimul vecin acum;

    }
    return d[n-1][n-1];
}
