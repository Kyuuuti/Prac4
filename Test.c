#include <stdio.h>
#include <string.h>
#include "Exercise1.h"

int main(void) 
{
	PersonStaticArrayList *list;
	PersonDynamicArrayList *newList;
    // To do code logic here.
    Person p1 = createPerson("Max", 'M', "Cebu");
    
    displayPersonInfo(p1);
    
    init_SAL(&list);
    insert_first_SAL(&list, p1);
	display_SAL(list);
	
	Person p2 = createPerson("Max", 'M', "Cebu");
    
    displayPersonInfo(p2);
    
   	init_DAL(&newList);
   	insert_first_DAL(&newList, p2);
   	insert_last_DAL(&newList, p2);
   	delete_first_DAL(&newList);
   	delete_last_DAL(&newList);
   	delete_by_city_DAL(&newList, "Cebu");
   	display_DAL(newList);

    return 0;
}
