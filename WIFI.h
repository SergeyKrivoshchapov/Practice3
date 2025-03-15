#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#ifndef WIFI_H 
#define WIFI_H

#define MAX_VENDOR_LENGTH 20
#define MAX_INT_LENGTH 8
#define MAX_MARK_LENGTH 10

enum ERROR_CODE
{
	Success, Invalid_Port_Count, Invalid_5G_Mark
};

enum _5G_MARK 
{
	Is5G, Not5G, Undefined
};

typedef struct WIFI
{
	char vendor[MAX_VENDOR_LENGTH]; // название бренда Wifi маршрутизатора
	unsigned short port_count; // количество ethernet портов
	enum _5G_MARK has_5G; // наличие диапазона Wi-Fi 5 ГГц
}WIFI;

int input_int(const char* message);

void input_string(char* buffer, int buffer_size); 

enum _5G_MARK input_5G_mark(const char* message);

enum ERROR_CODE router_DataCheck(const WIFI* router);

//Функция для инициализации структуры.
//В качестве аргументов принимает структуру WIFI по указателю, символьный массив brand_name, целочисленную переменную port_count и переменную перечислимого типа has_5G.
int init_struct(WIFI* router, const char* vendor, unsigned short port_count, enum _5G_MARK has_5G ); 

int struct_init_result(const enum ERROR_CODE result_code);

int init_userdata(WIFI* router);

void copy_struct(const WIFI* router, WIFI* copy);

//Функция для вывода всех полей структуры.
//В качестве аргумента получает структуру по указателю.
void print_struct(const WIFI* router);

int field_changing(WIFI* router);

int update_port_count(WIFI* router, const unsigned short value);

int update_vendor_name(WIFI* router, const char* value);

int update_5G_mark(WIFI* router, const enum _5G_MARK value);

WIFI* dynamic_struct_create(const char* vendor, const unsigned short port_count, const enum _5G_MARK has_5G);

WIFI* dynamic_struct_free(WIFI* dym_struct_ptr);

// Проверяет равенство двух экземпляров структуры посредством сравнения значений по каждому из полей экземпляров. 
// Возвращает 1, если экземпляры идентичны.
int is_equal(const WIFI* router1, const WIFI* router2);

// Функция для сравнения двух экземпляров структур. Возвращает 0, если "больше" первый экземпляр, 1 если второй соответственно.
// Приоритеты для сравнения определены: 1) vendor 2) port_count, has_5G.
// Если vendor у экземпляров совпадает, производится вызов compare_int, которая сравнивает экземпляры по второму приоритету.
int compare(const WIFI* router1, const WIFI* router2);

int compare_int(const WIFI* router1, const WIFI* router2);

#endif /* WIFI_H */
