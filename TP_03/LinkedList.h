/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{

    void* pElement; // PUNTERO A CUALQUIER DATO
    struct Node* pNextNode; // Apunta al siguiente NODO // EL ULTIMO NODO APUNTA A NULL

}typedef Node;

struct LinkedList
{
    Node* pFirstNode; //PUNTERO AL PRIMER NODO
    int size; //CANTIDAD DE NODOS

}typedef LinkedList;

#endif

//Publicas
LinkedList* ll_newLinkedList(void); //Pide memoria dinamica para guardar un linked list

int ll_len(LinkedList* this); //Recibe un puntero a Linkedlist retorna un entero (Cantidad de elementos)

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

int ll_add(LinkedList* this, void* pElement); //Agrega un nodo con un elemento

void* ll_get(LinkedList* this, int index); //Trae el elemento del index agregado
int ll_indexOf(LinkedList* this, void* pElement); // Devuelve el index pasando el elemento

int ll_set(LinkedList* this, int index,void* pElement); // SET EL VALOR DE UN ELEMENTO EB UN INDEX
int ll_remove(LinkedList* this,int index); // REMUEVE EL NODO PERO NO PIERDE EL APUNTADOR AL NODO SIGUIENTE
int ll_clear(LinkedList* this); //Libera la lista hace un free a todos los elementos

int ll_deleteLinkedList(LinkedList* this); // Elimina la linkedlist

int ll_isEmpty(LinkedList* this); //Devuelve si la lista vacia

int ll_push(LinkedList* this, int index, void* pElement); //Inserta un nodo en el index

void* ll_pop(LinkedList* this,int index); //Devuelve el elemento del nodo a borrar

int ll_contains(LinkedList* this, void* pElement); //RETORNA SI CONTIENE EL ELEMENTO

int ll_containsAll(LinkedList* this,LinkedList* this2); // RETORNA SI CONTIENE EL ELEMENTO DE LA LISTA EN LA LISTA 2 RETTORNA UNA SUBLISTA
//RETORNA UNA NUEVA SUBLISTA
LinkedList* ll_subList(LinkedList* this,int from,int to);
//RETORNA LA MISMA LISTA CLONADA
LinkedList* ll_clone(LinkedList* this);
//ORDENA LA LISTA
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
