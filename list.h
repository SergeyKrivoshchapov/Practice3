#include "WIFI.h"
#ifndef LIST_H 
#define LIST_H
struct WIFI_item
{
	WIFI data;
	struct WIFI_item* next;
};
struct WIFI_list
{
	struct WIFI_item* head;
};

void WIFI_list_init(struct WIFI_list* list);

void insert_in_start(struct WIFI_list* list, WIFI* p);

void delete_from_start(struct WIFI_list* list);

void print_list(struct WIFI_list* list);

void sort_list(struct WIFI_list* list);

void insert_to_sorted(struct WIFI_list* list, struct WIFI* p);

void delete_list(struct WIFI_list* list);
#endif
