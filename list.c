#include "list.h"

int push_front(WIFI_list* list, WIFI data) 
{
    WIFI_item* new_item = (WIFI_item*)malloc(sizeof(WIFI_item));
    if (!new_item)
    {
	printf("Can't create new item");
	return 1;
    }
    new_item->data = data;
    new_item->next = list->head;
    list->head = new_item;
    return 0;
}

void delete_front(WIFI_list* list) 
{
    if (list->head == NULL) 
    {
        printf("Empty.\n");
        return;
    }
    struct WIFI_item* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void print_list(const WIFI_list* list) 
{
    WIFI_item* current = list->head;
    while (current != NULL) 
    {
        print_struct(&current->data);
        current = current->next;
    }
}

void delete_list(WIFI_list* list) 
{
    while (list->head != NULL) delete_front(list);
}

