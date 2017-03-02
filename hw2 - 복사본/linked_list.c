#include <stdbool.h>
#include <stddef.h>

#include "../include/linked_list.h"

struct list *list_new(void)
{
    struct list* newList
        =(struct list*)malloc(sizeof(struct list));
        newList->_head = NULL;
        newList->_tail = NULL;
        newList->_length = 0;
	return newList; // return pointer to newlist
}

void list_delete(struct list *l)
{
	if(l->_head->_next==NULL){
		printf("Empty list.\n");
	}
	else{
		while(l->_head->_next != NULL){
		_list_node *temp = l->_tail->_prev;
		l->_tail = temp->prev;
		if(NULL==l->_tail) l->_head = l->_tail; // one item
		else l->_tail->_next = NULL;
		free(temp);
		temp = NULL;
		}
		return 1; // non-zero exit sequence.
	}
}

bool list_empty(struct list const * const l)
{
	if(l->head->_next==NULL){
		return true;
	}
	else{	return false;}
}
//?? OS max size? fixed value?
int list_max_size(struct list *l)
{
	return 0;
}	

int list_at(struct list *l, int n)
{
	int counter = 0;
	_list_node *temp = l->_head;
	while(counter<n){
		//move the pointer to desired element.
		temp = temp->_next;
		counter ++;
	}
	return temp->_value;
}

int list_front(struct list *l)
{
	_list_node *temp = l->_head->_next;
	return temp->_value;
}

int list_back(struct list *l)
{
	_list_node *temp = l->_tail->_prev;
	return temp->_value;
}

int list_assign(struct list *l, int n, int data)
{
	int counter = 0;
	_list_node *temp = l->_head;
	while(counter<n){
		temp = temp->_next;
	}
	temp->_value = data;
	return temp->_value;
}

int list_push_front(struct list *l, int data)
{
	struct _list_node* newNode;
        =(struct _list_node*)malloc(sizeof(struct _list_node));
	if(l->_head->_next==NULL){
		l->_head->_next = l->tail->_prev = newNode;
		newNode->_value = data;
	}
	else{
        newNode->_next = l->_head->_next;
		l->_head->_next->_prev = newNode;
		l->_head->_next = newNode;
        newNode->_value = data;
	}
	return newNode->_value;
}

int list_pop_front(struct list *l)
{
	if(l->_head->_next==NULL){
		//ERROR - EMPTY LIST
		return NULL; // int NULL possible??
		printf("ERROR!\n");
	}
	_list_node *dead = l->_head->_next;
	result = dead->_value;
	if(l->_tail->_value==l->_head->_value){
		l->_tail = l->_head = NULL;
		// when there was only one node
	}
	else{
		l->_head->_next = dead->_next;
		dead->_next->_prev = l->_head;
	}
	free(dead);
	return result;
}

int list_push_back(struct list *l, int data)
{
	struct _list_node* newNode;
        =(struct _list_node*)malloc(sizeof(struct _list_node));
	if(l->_head==NULL){
		l->_head = l->tail = newNode;
		l->_head->_next = l->_tail->_next = NULL;
		l->_head->_prev = l->_tail->_prev = NULL;
		newNode->_value = data;
	}
	else{
	
        newNode->_prev = l->_tail;
		l->_tail = newNode;
        newNode->_value = data;
	}
	return data;
}

int list_pop_back(struct list *l)
{
	if(l->_tail==NULL){
		//ERROR - EMPTY LIST
		return NULL; // int NULL possible??
	}
	_list_node *dead = l->_tail;
	result = l->_tail->_value;
	if(l->_tail->_value==l->_head->_value){
		l->_tail = l->_head = NULL;
		// when there was only one node
	}
	else{
		l->_tail = l->_tail->_prev;
		l->_tail->_next = NULL;
	}
	free(dead);
	return result;
}

int list_insert(struct list *l, int n, int data)
{
	int counter = 0;
		struct _list_node* newNode;
        =(struct _list_node*)malloc(sizeof(struct _list_node));
		newNode->_value = data;
		newNode->_prev = NULL;
		newNode->_next = NULL;
		if(n==0){
			newNode->next = l->_head->_next;
			l->_head->_next= newNode;
		}	
		else if(n==l->_length-1){
			l->_tail->_next = newNode;
			l->_tail = newNode;
		}
		else{
			_list_node *current = l->_head;
			while (counter<n){
				current = current->_next;
				counter++;
			}
			newNode->_prev = current;
			newNode->_next = current->_next;
			newNode->_next->_prev = newNode;
			current->_next = newNode;
			//arbitrary
		}
	l->_length++;
	return newValue->_value;
}

struct list *list_insert_list(struct list *dst, struct list *src, int pos)
{
	int counter = 0;
	_list_node *current = src->_head;
	_list_node *newNode = dst->_head->_next;
	while(counter<pos){
		current = current->_next;
		counter++;
	}
			newNode->_prev = current;
			dst->_tail->_prev->_next = current->_next;
			dst->_head->_prev = newNode;
			current->_next = newNode;
			dst->_head->_next = src->_head->next;
			dst->_tail->_prev = src->_tail->prev;
			
	return dst;
}

struct list *list_erase(struct list *l, int start, int finish)
{
	_list_node *current = l->_head;
	_list_node *temp;
	for(int i =0; i<start+1;i++){
		current = current->_next;
	}
	for(int j =0; j<finish+1;j++){
		temp = current->_next;
		free(current);
		current = temp;
		l->_length --;
	}
	return NULL;
}

int list_clear(struct list *l)
{
	_list_node *current = l->_head;
	_list_node *temp;
	while(current->_next!=NULL){
		temp = current->_next;
		current->_value = 0;
		current = temp;
	}
	return 0;
}

int list_remove(struct list *l, int data)
{
	int counter = 0;
	_list_node *current = l->_head;
	_list_node *temp;
	while(current->_value!=data && counter<l->_length-1){
		temp = current->_next;
		counter++;
	}
	if(current->_value ==data){
		temp = current->_next;
		current->_prev->_next = temp;
		free(current);
		//
		return counter;
	}
	else{
		return -1;
	}
}

int list_rremove(struct list *l, int data)
{	int reverse = l->_length;
	_list_node *current = l->_tail;
	_list_node *temp;
	return 0;
}
int main()
{
	list *a = list_new();
	if(list_empty(a)){
		print("List is empty/n");
	}
}