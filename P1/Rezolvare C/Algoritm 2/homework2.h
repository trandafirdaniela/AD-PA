#ifndef CODE_LIST_H
#define CODE_LIST_H

struct pairr
{
    int first,second;
};
struct g_node
{
    struct pairr info;
    struct g_node *next;
};
int a[1005][1005];



void push_element_begining(struct g_node *head,struct pairr new_element_value);
void push_element_end(struct g_node *head,struct pairr new_element_value);
struct pairr pop_element_begining(struct g_node *head);
int pop_element_end(struct g_node *head);
int  list_empty(struct g_node *head);
int list_empty(struct g_node *head);
int minim(int a,int b);
int absolut(int a,int b);
int solve(int n);


#endif //CODE_LIST_H
