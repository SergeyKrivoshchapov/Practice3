#include "WIFI.h"
#include "list.h"
int main()
{
	// Инициализация трёх экземпляров структуры на стеке
	printf("Creating first struct.\n");
	WIFI router1;

	if (struct_init_result(init_struct(&router1, "TPLINK", 2, Is5G)) != 0) return 1;

	printf("First: \n");
	print_struct(&router1); // Вывод сведений о структуре

	printf("Creating second struct.\n");
	WIFI router2;
	if (struct_init_result(init_struct(&router2, "TPLINK", 6, Is5G)) != 0) return 1;

	printf("Second: \n");
	print_struct(&router2);

	printf("Creating third struct.\n");
	WIFI router3;
	if (struct_init_result(init_struct(&router3, "ROSTELECOM", 2, Not5G)) != 0) return 1;

	printf("Third: \n");
	print_struct(&router3);

	// Инициализация неупорядоченного списка 
	printf("Initializing not ordered list with three structs.\n");
	WIFI_list* router_list = (WIFI_list*)malloc(sizeof(WIFI_list));
	if (router_list == NULL) 
	{
		printf("Can't create list.\n");
		return 1;
	}
	router_list->head = NULL;
	
	// Добавляем элементы в начало списка
	if (push_front(router_list, router1) == 1) return 1;
	if (push_front(router_list, router2) == 1) return 1;
	if (push_front(router_list, router3) == 1) return 1;

	print_list(router_list); // Вывод сведений о  каждом элементе списка

	printf("Removing front element:\n");
	delete_front(router_list); // Удаления первого элемента списка
	
	print_list(router_list);

	delete_list(router_list); // Удаление списка полностью.

	return 0;
}
