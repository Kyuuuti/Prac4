#include <stdio.h>
#include <stdbool.h>
#include "CircularArrayQ.h"

CircularArrayQueue create_array_queue(){
	CircularArrayQueue newQueue, queue;
	
	newQueue = initQueue(&queue);
	
	return newQueue;
}

void init_array_queue(CircularArrayQueue *list){
	list->front = MAX;
	list->rear = MAX-1;	
}

bool enqueue(CircularArrayQueue *list, Type p){
	if((list->rear+2)%MAX != list->front){
		list->rear = (list->rear+1)%MAX;
		list->data[list->rear] = p;
		return 1;
	}else{
		return 0;
	}
}

bool dequeue(CircularArrayQueue *list){
	if((list->rear+1)%MAX != list->front){
		list->front = (list->front+1)%MAX;
		return 1;
	}else{
		return 0;
	}
}

bool is_empty(CircularArrayQueue list){
	if((list.rear+1)%MAX == list.front){
		return 1;
	}else{
		return 0;
	}
}

bool is_full(CircularArrayQueue list){
	if((list.rear+2)%MAX == list.front){
		return 1;
	}else{
		return 0;
	}
}

Type front(CircularArrayQueue list){
	return list.data[list.front];
}
