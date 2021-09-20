#include <stdio.h>
#include <string.h>
#include "Person.h"

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
}

void init_SAL(PersonStaticArrayList *list){
	list->count=0;
}

void insert_first_SAL(PersonStaticArrayList *list, Person p){
	if(MAX_LIST>list->count) {
        list->data[list->count++] = p;
    }
}

void display_SAL(PersonStaticArrayList list){
	int i;
    printf("{");
    for(i=0; i<list.count; ++i) {
        printf("%s | %c | %s", list.data[i].name, list.data[i].sex, list.data[i].city);
        if(i < list.count-1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void init_DAL(PersonDynamicArrayList *list){
	list = (PersonDynamicArrayList *) malloc(sizeof(PersonDynamicArrayList));

    list->count = 0;
    list->max = MAX_LIST;
    list->data = (Person *) malloc(sizeof(Person)*list->max);
}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
	int i;
    if(list->count >= list->max) {
        list->max *= 2;
        list->data = realloc(list->data, list->max);
    }

    for(i = list->count; i > 0; --i) {
        list->data[i] = list->data[i-1];
    }
    list->data[i] = p;
    list->count++;
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){
	if(list->count >= list->max) {
        list->max *= 2;
        list->data = realloc(list->data, list->max);
    }

    list->data[list->count++] = p;
}

void delete_first_DAL(PersonDynamicArrayList *list){
	int i;
    if(list->count <= 0) {
    } else {
        for(i=0; i<list->count-1; ++i) {
            list->data[i] = list->data[i+1];
        }
        list->count--;
    }
}

void delete_last_DAL(PersonDynamicArrayList *list){
	if(list->count <= 0) {
    } else {
        list->count--;
    }
}

void delete_by_city_DAL(PersonDynamicArrayList *list, String city){
	int i, pos;

    for(i=0; i<list->count; ++i) {
        if(strcmp(list.data[i].city, city)==0) {
            pos=i;
            break;
        }
    }

    if(i<list->count) {
        for(i=pos; i<list->count-1; ++i) {
            strcmp(list.data[i].city, city)!=0;
        }
        list->count--;
    }
}

void display_DAL(PersonDynamicArrayList list){
	int i;
    printf("{");
    for(i=0; i<list.count; ++i) {
        printf("%s | %c | %s", list.data[i].name, list.data[i].sex, list.data[i].city);
        if(list.count-1 > i) {
            printf(", ");
        }
    }
    printf("} Count: %d; Max: %d\n", list.count, list.max);
}

void insert_first_LL(PersonLinkedList *list, Person p){
	PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));

    if(temp != NULL) {
        temp->next = *list;
        *list = temp;
        temp->elem = p;
    }
}

void insert_last_LL(PersonLinkedList *list, Person p){
	PersonLinkedList *current;
    PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));

    if(temp != NULL) {
        for(current = list; *current != NULL; current = &(*current)->next) {}
        temp->next = NULL;
        *current = temp;
        temp->elem = p;
    }
}

void delete_by_city_LL(PersonLinkedList *list, String city){
	PersonLinkedList *current, temp;

    if(*list != NULL) {
        for(current = list; *current != NULL && strcmp(list->elem.city, city)!=0; current = &(*current)->next) {}
        if(*current != NULL) {
            temp = *current;
            *current = temp->next; // *current = (*current)->next
            free(temp);
        }
    }
}

void display_LL(PersonLinkedList list){
	printf("[");

    for(list != NULL; list = list->next) {
        printf("%s | %c | %s", list->elem.name, list->elem.sex, list->elem.city);
        if(list->next != NULL) {
            printf(" -> ");
        }
    }

    printf("]\n");
}

void init_vspace(VSpace *vs){
	int i;
    for(i=MAX-1; i>=0; --i) {
        vs->data[i].elem = 0;
        vs->data[i].next = i-1;
    }
    vs->avail = MAXVSPACE-1;
}

Position alloc_space(VSpace *vs){
	Position avail = vs->avail;

    if(avail != -1) {
        vs->avail = vs->data[avail].next;
    }

    return avail;
}

void free_space(VSpace *vs, Position index){
	if(index != -1 && index < MAX) {
        vs->data[index].elem = 0;
        vs->data[index].next = vs->avail;
        vs->avail = index;
    }
}

void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	Position temp = allocSpace(vs);

    if(temp != -1) {
        vs->data[temp].elem = p;
        vs->data[temp].next = *list;
        *list = temp;
    }
}

void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){
	Position temp = *list;

    if(*list != -1) {
        *list = vs->data[*list].next;
        freeSpace(vs, temp);
    }
}

void display_CBL(VSpace vs, PersonCusorBasedList list){
	int i;
    printf("{");
    for(i=list; i != -1; i = vs.data[i].next) {
        printf("%s | %c | %s", vs.data[i].elem.name, vs.data[i].elem.sex, vs.data[i].elem.city);
    }
    printf("}\n");
}
