#include <stdio.h>
#include "Exercise1.h"

int get_queue_length(CircularArrayQueue list){
	int count=0, i;
	
	for(i=list.front; i<=list.rear; i++){
		count++;
	}
	return count;
}
