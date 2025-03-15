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

int add_to_ordered(WIFI_list* list, WIFI data) 
{
    WIFI_item* new_item = (WIFI_item*)malloc(sizeof(WIFI_item));
    if (!new_item) 
    {
        printf("Can't create new item.");
        return 1;
    }
    new_item->data = data;
    new_item->next = NULL;

    if (list->head == NULL || compare(&data, &list->head->data) < 0) 
    {
        new_item->next = list->head;
        list->head = new_item;
    } 
    else 
    {
        WIFI_item* current = list->head;
        while (current->next != NULL && compare(&data, &current->next->data) >= 0) current = current->next;
        new_item->next = current->next;
        current->next = new_item;
    }
    return 0;
}

void delete_selected_element(WIFI_list* list, WIFI data) 
{
    WIFI_item* current = list->head;
    WIFI_item* previous = NULL;

    while (current != NULL) 
    {
        if (is_equal(&current->data, &data)) 
	{
            if (previous == NULL) list->head = current->next; 
	    else previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Selected element not in list.\n");
}
