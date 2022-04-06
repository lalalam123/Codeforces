#include <stdio.h>
#include <stdlib.h>

// Educational Codeforces Round 107 (Rated for Div. 2) C Yet Another Card Deck
// Codeforces link:
// https://codeforces.com/contest/1511/problem/C

// Doubly linked list block, actually it don't need the previous
typedef struct Node{
    int value;
    struct Node *previous;
    struct Node *next;
}Node;

// Number of card, Number of query, Temporary position value
int n,q,position;
Node *universalfirstpointer;

void initalize(int n, int q, Node *card, int *query);
int find(int value, Node *firstpointer);
int find_(int value, Node *firstpointer, Node *pointer, int counter);
void swap(Node *firstpointer, Node *pointer, int counter);

// Wrapper function -> find at what position the query value is equal to the card value
int find(int value, Node *firstpointer){
    int counter = 1;
    if(firstpointer->value == value){
        return 1;
    }else{
        return find_(value, firstpointer, firstpointer->next, counter);
    }
}

// Recurssive Function -> Find at what position the query value is equal to the card value
int find_(int value, Node *firstpointer, Node *pointer, int counter){

    if(pointer->value == value){
        counter++;
        swap(firstpointer, pointer, counter);
        return counter;
    }else{
        counter++;
        return find_(value, firstpointer, pointer->next, counter);
    }   

}

// Reorder the sequence of the linked list
void swap(Node *firstpointer, Node *pointer, int counter){

    if(counter==n){
        pointer->previous->next = NULL;
        pointer->next=firstpointer;
        pointer->previous=NULL;
        firstpointer->previous=pointer;
        universalfirstpointer=pointer;
        return;
    }
    pointer->previous->next = pointer->next;
    pointer->next->previous=pointer->previous;
    pointer->next=firstpointer;
    pointer->previous=NULL;
    firstpointer->previous=pointer;
    universalfirstpointer=pointer;
    return;
}

int main(){

    scanf("%d %d",&n,&q);
    //printf("%d %d\n",n,q);

    Node *card = (Node *)malloc(n*sizeof(Node));
    int *query = (int *)malloc(q*sizeof(int));

    initalize(n, q, card, query);
    /*
    for(int i=0; i<n;i++){
        printf("%d ",card[i].value);
    }
    printf("\n");
    for(int i=0; i<q;i++){
        printf("%d ",query[i]);
    }
    printf("\n");
    */
    universalfirstpointer = card;

    for(int i=0; i<q ;i++){
        position = find(query[i], universalfirstpointer);
        printf("%d ",position);
    }
    printf("\n");

    free(card);
    free(query);

    return 0;
}

// To initalize the value and pointer of each linked nodes
void initalize(int n, int q, Node *card, int *query){

    scanf("%d",&card[0].value);
    card[0].previous = NULL;
    card[0].next = &card[1];

    for(int i=1; i<n-1; i++){
        scanf("%d",&card[i].value);
        card[i].previous = &card[i-1];
        card[i].next = &card[i+1];
    }

    scanf("%d",&card[n-1].value);
    card[n-1].previous = &card[n-2];
    card[n-1].next = NULL;

    for(int i=0; i < q ; i++){
        scanf("%d", &query[i]);
    }

    return;
}