#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"


struct doubly_linked_list *init_list( struct doubly_linked_list *t )
{
	t->head = NULL;
	t->tail = NULL;
	t->count = 0;

	return t;
}

struct doubly_linked_list *create_list()
{
    struct doubly_linked_list *t = (struct doubly_linked_list *)malloc( sizeof(struct doubly_linked_list) );

	return init_list( t );
}

struct node *create_node( T e )
{
	struct node *p = (struct node *)malloc( sizeof(struct node) );

	p->data = e;
	p->next = NULL;

	return p;
}
