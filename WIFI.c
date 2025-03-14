#include "WIFI.h"
#ifndef WIFI_C
#define WIFI_C
int correct(const struct WIFI * m)

{
    int flag = 0; 
    if(m->has_5G != 0 && m->has_5G != 1)flag = 1;
    else if(m->port_count > 32) flag = 2;
    else if(strlen(m->vendor)<=0) flag = 3;
    switch(flag)
    { 
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
    }
}

int init_struct(WIFI* m, const char* vendor, unsigned int port_count, int has_5G ) 
{ 
    int flag;
    strcpy(m->vendor, vendor);
    m->port_count = port_count;
    m->has_5G = has_5G;   
    flag = correct(m);
    return flag;
}

void copy_struct(const WIFI* m, struct WIFI * copy )
{
    strcpy(copy->vendor, m->vendor);
    copy->port_count = m->port_count;
    copy->has_5G = m->has_5G;
}
void printstruct(const WIFI* m)
{
    printf(" Brand name: %s \n port_count: %d\n has 5g: %s\n\n ",
    m->vendor,
    m->port_count,
    m->has_5G ? "yes":"no");
}

int change_struct_value(struct WIFI* m, int box_num)
{
    int flag, new_data_i;
    char new_data_ch[vendor_name_lenght];
    switch (box_num)
    {
        case 1:
        printf("\nPlease, enter new brand name:");
        fgets(new_data_ch, vendor_name_lenght, stdin);
        strcpy(m->vendor, new_data_ch);
        flag = correct(m); 
        return flag; 
    case 2:
        printf("Please, enter new port_count:");
        fgets(new_data_ch, vendor_name_lenght, stdin);
        new_data_i = atoi(new_data_ch);
        m->port_count = new_data_i;
        flag = correct(m); 
        return flag;
    case 3:
        printf("Please, enter if wifi-router has 5G(1 - has, 0 - hasn't):");
        fgets(new_data_ch, vendor_name_lenght, stdin);
        new_data_i = atoi(new_data_ch);
        m->has_5G = new_data_i;
        flag = correct(m);
        return flag;

    }
}

WIFI* dynamic_struct_create(const char* vendor,const unsigned int port_count,const int has_5G)
{
    if((WIFI*)malloc(sizeof(WIFI))!=NULL)
    {
        struct WIFI* dym_struct_ptr = (struct WIFI*)malloc(sizeof(struct WIFI));
        init_struct(dym_struct_ptr, vendor, port_count, has_5G);
        return dym_struct_ptr;
    } 

}

WIFI* dynamic_struct_free(struct WIFI* dym_struct_ptr)
{ 
    free(dym_struct_ptr);
    dym_struct_ptr = NULL;
}

int is_equal(const struct WIFI* p1, const struct WIFI* p2)
{
    return ((strcmp(p1->vendor, p2->vendor) == 0) && p1->port_count == p2->port_count && p1->has_5G == p2->has_5G);
}

int compare(const struct WIFI* p1, const struct WIFI* p2)
{
    int vend_cmp_result = strcmp(p2->vendor, p1->vendor);
    if (vend_cmp_result != 0) return (vend_cmp_result < 0);
    return compare_int(p1, p2); 
}

int compare_int(const struct WIFI* p1, const struct WIFI* p2)
{
    return ((p2->port_count > p1->has_5G) || (p2->has_5G > p1->has_5G));
}
#endif 
 
