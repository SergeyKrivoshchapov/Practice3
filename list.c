#include "list.h"

void WIFI_list_init(struct WIFI_list* list)
{
    list->head = NULL;
}
void insert_in_start(struct WIFI_list* list, const char brand_name[], const unsigned int port_count, const int has_5G)
{
    struct WIFI m;
    struct WIFI_item tmp;
    init_struct(&m, brand_name, port_count, has_5G);
    tmp.data = list->head->data;
    tmp.next = list->head;
    list->head->data = m;
    list->head = list->head->next;
    list->head->data = tmp.data;
    free(&tmp);
}

void print_list(struct WIFI_list* list)
{
    while (list->head->next != NULL) printstruct(list->head->data);
}

