#include "WIFI.h"
#include "list.h"
int main()
{
/*
	// Создание экземпляров структур на стеке 
	WIFI subj1;
	WIFI subj2;
	
	printf("Gets informaions about educational subject.\n");
	printf("Changes it if needs. Outputs result.\n");
	
	// Инициализация экземпляров структуры данными пользователя 
	if (init_userdata(&subj1) == 1) return 1; 
	
	if (init_userdata(&subj2) == 1) return 1;
	
	// Вывод сведений о экземплярах структуры
	printf("\nFirst subject:\n");
	print_struct(&subj1);

	printf("\nSecond subject:\n");
	print_struct(&subj2);

	// Инициализация второго экземпляра структуры как копии первого
	copy_struct(&subj2, &subj1); 

	printf("\nFirst subject:\n");
	print_struct(&subj1);

	printf("\nCopy of first subject:\n");
	print_struct(&subj2);

	// Вывов функции изменения поля первого экземпляра структуры
	if (field_changing(&subj1) == 1) return 1;

	printf("\nResult of changes\n");
	print_struct(&subj1);
*/
	// Инициализация трёх экземпляров структур в динамической пмяти
	printf("Creating first dynamic struct.\n");
	WIFI* router1 = dynamic_struct_create("1", 1, Is5G);

	if (router1 == NULL) return 1;

	printf("First: \n");
	print_struct(router1);

	printf("Creating second dinamic struct.\n");
	WIFI* router2 = dynamic_struct_create("2", 2, Is5G);

	if (router2 == NULL) return 1;
	
	printf("Second: \n");
	print_struct(router2);

	printf("Creating third dynamic struct.\n");
	WIFI* router3 = dynamic_struct_create("3", 3, Not5G);
	
	if (router3 == NULL) return 1;

	printf("Third: \n");
	print_struct(router3);

	//Инициализируем второй экземпляр структуры как копию первого
	printf("Initializing second struct as a copy of first struct\n");
	copy_struct(router2, router1);
	
	printf("First: \n");
	print_struct(router1);

	printf("Copy of first struct\n");
	print_struct(router2);

	// Вызов функции изменения поля в экземпляре структуры инициализированном в динамической памяти
	if (field_changing(router1) == 1) return 1;
	
	printf("\nResult of changes\n");
	print_struct(router1);

	// Удаление экземпляров структуры из динамической памяти
	dynamic_struct_free(router1);
	dynamic_struct_free(router2);
	dynamic_struct_free(router3);


/*	struct WIFI_list router_list;
	WIFI* pdyn1;

	WIFI_list_init(&l);

	WIFI* router1 = dynamic_struct_create("TP_LINK1", 8, 0);
	WIFI* router2 = dynamic_struct_create("TP_LINK2", 8, 0);
	WIFI* router3 = dynamic_struct_create("TP_LINK3", 8, 0);
	
	insert_in_start();
	insert_in_start();
	insert_in_start();

	delete_from_start();

	print_list(&router_list);

	delete_list();

	insert_to_sorted();

	delete_by_number();
*/

	return 0;
}
