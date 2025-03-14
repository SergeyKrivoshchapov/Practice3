#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef WIFI_H 
#define WIFI_H

#define vendor_name_lenght 20
typedef struct WIFI
{
	char vendor[vendor_name_lenght];
	unsigned int port_count;
	int has_5G;
}WIFI;

int correct(const struct WIFI* m);

int init_struct(struct WIFI* m, const char* vendor, unsigned int port_count, int has_5G);

void copy_struct(const struct WIFI* m, struct WIFI* copy);

void printstruct(const struct WIFI* );

int change_struct_value(struct WIFI* m, int box_num);

WIFI* dynamic_struct_create();

WIFI* dynamic_struct_free(struct WIFI* dym_struct_ptr);

int is_equal(const struct WIFI* p1,const struct WIFI* p2);

int compare(const struct WIFI* p1, const struct WIFI* p2);

int compare_int(const struct WIFI* p1, const struct WIFI* p2);
#endif /* WIFI_H */
