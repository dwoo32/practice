#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node*Nextnode;
}Node;

int insertnode(Node*h, int key);
int printnode(Node*h);
void freenode(Node*h);

int main()
{
    int i,n;
    printf("enter :");
    scanf("%d",&n);
    
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->Nextnode=NULL;

    for(i = 1; i <= n; i++){
        insertnode(head, i);
    }

    printnode(head);
    freenode(head);
    
    return 0;

}

int insertnode(Node*h, int key)
{
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=key;
    p->Nextnode=NULL;

    if(h->Nextnode==NULL){
        h->Nextnode=p;
        return 0;
    }
    
    Node*n=h->Nextnode;
    while(n->Nextnode!=NULL){
        n=n->Nextnode;
    }
    n->Nextnode=p;
    return 0;
}

int printnode(Node *h)
{
    Node*p;

    p=h->Nextnode;
    while(p!=NULL){
        printf("%d ", p->data);
    p = p->Nextnode;
    }
    return 0;

}

void freenode(Node*h)
{
    Node*f=h->Nextnode;;
    Node*prev=NULL;
    while(f!=NULL){
        prev=f;
        f=f->Nextnode;
        free(prev);
    }
    free(f);

}