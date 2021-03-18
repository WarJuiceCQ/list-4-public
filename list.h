#pragma once

#include "defs.h"

struct node {
	T data;
	struct node *next;
};

struct singly_linked_list {
	struct node *head;
	//struct node *tail;
	int count;
};

struct singly_linked_list *create_list();

struct singly_linked_list *insert(struct singly_linked_list *t, int i, T e);
struct singly_linked_list *delete_at(struct singly_linked_list *t, int i);

int size( struct singly_linked_list *t );
T get( struct struct singly_linked_list *t, int i );
void replace( struct singly_linked_list *t, int i, T e );
int index( struct singly_linked_list *t, T e );
