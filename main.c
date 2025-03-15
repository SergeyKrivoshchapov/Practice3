#include "WIFI.h"
#include "list.h"
int main()
{
	// Инициализация в динамической памяти трёх экземпляров структуры
	printf("Creating first struct.\n");
	WIFI* router1 = dynamic_struct_create("1", 1, Is5G);

	if (router1 == NULL) return 1; // Проверка корректности инициализации экземпляра

	printf("First: \n");
	print_struct(router1); // Вывод сведений о структуре

	printf("Creating second struct.\n");
	WIFI* router2 = dynamic_struct_create("2", 2, Is5G);

	if (router2 == NULL) return 1;
	
	printf("Second: \n");
	print_struct(router2);

	printf("Creating third struct.\n");
	WIFI* router3 = dynamic_struct_create("3", 3, Not5G);
	
	if (router3 == NULL) return 1;

	printf("Third: \n");
	print_struct(router3);

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
	
	//Освобождение динамической памяти, выделенной под экземпляры структуры
	dynamic_struct_free(router1);
	dynamic_struct_free(router2);
	dynamic_struct_free(router3);
	
	printf("Creating first dynamic struct.\n");
	router1 = dynamic_struct_create("1", 1, Is5G);

	if (router1 == NULL) return 1;

	printf("First: \n");
	print_struct(router1);

	printf("Creating second dynamic struct.\n");
	router2 = dynamic_struct_create("2", 2, Is5G);

	if (router2 == NULL) return 1;
	
	printf("Second: \n");
	print_struct(router2);

	printf("Creating third dynamic struct.\n");
	router3 = dynamic_struct_create("3", 3, Not5G);
	
	if (router3 == NULL) return 1;

	printf("Third: \n");
	print_struct(router3);

	printf("Creating fourth dynamic struct.\n");
	WIFI* router4 = dynamic_struct_create("4", 3, Is5G);

	if (router4 == NULL) return 1;
	
	printf("Initializing ordered list\n");

	if(add_to_ordered(router_list, router1) == 1) return 1;
	if(add_to_ordered(router_list, router2) == 1) return 1;
	if(add_to_ordered(router_list, router3) == 1) return 1;
	if(add_to_ordered(router_list, router4) == 1) return 1;

	print_list(router_list);

	delete_selected_element(router_list, router4);

	printf("Ordered list after deleting element:\n");
	print_list(router_list);

	delete_list(router_list);

	dynamic_struct_free(router1);
	dynamic_struct_free(router2);
	dynamic_struct_free(router3);
	dynamic_struct_free(router4);

	return 0;
}
