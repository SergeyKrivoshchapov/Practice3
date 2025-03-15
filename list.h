#include "WIFI.h"
#ifndef LIST_H 
#define LIST_H

typedef struct WIFI_item
{
	WIFI* data; // Данные о роутере
	struct WIFI_item* next; // Указатель на следующий элемент списка
}WIFI_item;

typedef struct WIFI_list
{
	struct WIFI_item* head; // Указатель на первый элемент списка 
}WIFI_list;

// Функция добавления элемента в начало списка
// Принимает в качестве аргументов список роутеров по указателю, экземпляр структуры роутера по значению. 
// Выделяет память динамически для нового элемента. 
// Устанавливаются новые значения указателей next, head 
// Возвращает 0 при успешном исходе, иначе 1
int push_front(WIFI_list* list, WIFI* data);

// Функция удаления первого элемента списка
// Принимает в качестве аргумента список роутеров по указателю.
// обновляет head, освобождает память для удаленного элемента.
void delete_front(WIFI_list* list);

// Функция вывода сведений для каждого элемента списка
// Принимает в качестве аргумента список роутеров по указателю.
// Внутри вызывает print_struct
void print_list(const WIFI_list* list);

// Функция очищения списка.
// Принимает в качестве аргумента список роутеров по указателю.
// вызывает delete_front, пока в списке есть элементы
void delete_list(WIFI_list* list);

// Добавляет новый элемент в список с сохранением условий упорядочивания. Список упорядочен по 1)vendor 2)port_count, has_5G 
// Принимает в качестве аргументов список роутеров по указателю, экземпляр структуры роутера по значению. 
// При успешной инициализации нового элемента возвращает возвращает 0, иначе 1
int add_to_ordered(WIFI_list* list, WIFI* data);

// Функция удаления заданного элемента из списка
// Принимает в качестве аргументов список роутеров по указателю, экземпляр структуры роутера по значению.
// Находит элемент через is_equal
// Если удаляемый элемент в начале списка обновляем head
// Если нет, обновляем next. Если соответствующий элемент отсутствует в списке, выводится ошибка и список остаётся прежним.
void delete_selected_element(WIFI_list* list, WIFI* data);

#endif
