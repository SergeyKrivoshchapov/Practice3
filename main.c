#include "WIFI.h"
#include "list.h"
int main()
{
	struct WIFI_list l;
	WIFI* pdyn1;

	WIFI_list_init(&l);

	WIFI* p1 = dynamic_struct_create("TP_LINK1", 8, 0);
	WIFI* p2 = dynamic_struct_create("TP_LINK2", 8, 0);
	WIFI* p3 = dynamic_struct_create("TP_LINK3", 8, 0);
	
	insert_in_start();
	insert_in_start();
	insert_in_start();

	delete_from_start();

	print_list(&l);

	delete_list();

	insert_to_sorted();

	delete_by_number();


	return 0;
}
