#include "WIFI.h"
#ifndef LIST_H 
#define LIST_H

typedef struct WIFI_item
{
	WIFI data;
	struct WIFI_item* next;
}WIFI_item;

typedef struct WIFI_list
{
	struct WIFI_item* head;
}WIFI_list;

int push_front(WIFI_list* list, WIFI data);

void delete_front(WIFI_list* data);

void print_list(const WIFI_list* data);

void delete_list(WIFI_list* list);

int add_to_ordered(WIFI_list* list, WIFI data);

void delete_selected_element(WIFI_list* list, WIFI data);

#endif
