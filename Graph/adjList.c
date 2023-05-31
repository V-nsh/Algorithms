#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct Node *next;
};

struct graph{
    int numvert;
    struct node** adjLists;
    int* visited;
};

struct node* createNode(int key){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = key;
    newNode->next = NULL;
    return newNode;
}

struct graph* createGraph(int vertices){
    struct graph* graph= malloc(sizeof(struct node*));
    graph->numvert = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL; 
    }
    return graph;
}