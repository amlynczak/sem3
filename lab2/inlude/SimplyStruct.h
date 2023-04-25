#include<cstdio>
#include<cstdlib>
#pragma once

struct TItem{
    int value;
    struct TItem *next;
};

/**
 * @brief wyswietla wszystkie elementy listy
 * 
 * @param head pierwszy element listy
 */
void show(TItem *head){
    TItem *current = head;
    printf("Aktualny stan listy: \n<");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf(">\n");
}

/**
 * @brief inicjalizuje nowy element
 * 
 * @return struct TItem* zwraca ten nowy element
 */
struct TItem *InitItem(){
    TItem *tmp = new TItem();
    tmp->value = 0;
    tmp->next = NULL;
    return tmp;
}

/**
 * @brief dodaje na poczatek
 * 
 * @param head pierwszy element
 * @param val dodawana wartosc
 */
void push(TItem **head, int val){
    TItem *new_node = new TItem();
    new_node->value = val;
    new_node->next = *head;
    *head = new_node;
}

/**
 * @brief czyszczenie listy
 * 
 * @param head pierwszy element
 * do momentu jak nastepy element dla head nie bedzie nullem 
 * 
 */
void clear(TItem **head){
    TItem *current = *head;
    while (current != NULL) {
        TItem *tmp = current;
        current = current->next;
        delete tmp;
    }
    *head = NULL;
}

/**
 * @brief usuwa i zwraca pierwszy element listy
 * 
 * @param head pierwszy element
 * @return int wartosc pierwszego elementu
 */
int pop(TItem **head){
    if (*head == NULL) {
        return 0;
    }
    int value = (*head)->value;
    TItem *tmp = *head;
    *head = (*head)->next;
    delete tmp;
    return value;
}