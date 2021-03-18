#pragma once

#include "defs.h"

struct node {
	T data;

	struct node *prev;
	struct node *next;
};

struct doubly_linked_list {
    struct node *head;
    struct node *tail;
    int counter;
};

struct doubly_linked_list *create_list();

struct doubly_linked_list *insert(struct doubly_linked_list *t, int i, T e);
struct doubly_linked_list *delete_at(struct doubly_linked_list *t, int i);

int size( struct doubly_linked_list *t );
T get( struct struct doubly_linked_list *t, int i );
void replace( struct doubly_linked_list *t, int i, T e );
int index( struct doubly_linked_list *t, T e );
