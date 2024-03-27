#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List* list = (List*)malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
  return list;
}

void * firstList(List * list) 
{
  if (list->head == NULL)
  {
    Node* newNode = createNode(NULL);
    list->head = newNode;
    list->tail = newNode;
    list->current = newNode;
  }
  return list->head->data;
}

void * nextList(List * list) 
{
  Node* newNode = createNode(NULL);
  if(list->current == NULL || list->current->next == NULL)
  {
    list->current = newNode;
  }
  else
    list->current = list->current->next;
  
  return list->current->data;
}

void * lastList(List * list) 
{
  Node* newNode = createNode(NULL);
  if(list->tail == NULL || list->tail->prev == NULL)
  {
    list->tail = newNode;
    while(list->tail->next != NULL)
    {
      list->tail = list->tail->next;
    }
  }
  list->current = list->tail;
  return list->tail->data;
}

void * prevList(List * list) 
{
  if(list->current == NULL)
    return NULL;
  
  if(list->current->prev == NULL)
    return NULL;
  
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) 
{
  Node* newNode = createNode(data);
  if(list->tail == NULL)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
  }
}

void pushBack(List * list, void * data) 
{
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
  Node* newNode = createNode(data);
  if(list->current == NULL)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  if(list->current == list->tail)
  {
    list->tail->next = newNode;
    newNode->prev = list->tail;
    list->tail = newNode;
  }
  if(list->current != NULL || list->current == list->head)
  {
    newNode->next = list->current->next;
    newNode->prev = list->current;
    list->current->next = newNode;
    list->current = newNode;
    
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}