#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"


struct doubly_linked_list *init_list( struct doubly_linked_list *t )
{
	t->head = NULL;
	t->tail = NULL;
	t->counter = 0;

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
	p->prev = NULL;
	p->next = NULL;

	return p;
}

struct doubly_linked_list *insert(struct doubly_linked_list *t, int i, T e)
{
	assert(0<=i && i<=t->counter);

	struct node *p = create_node(e);
	struct node *prev_node, *next_node;

	if(i == 0)
	{
		if(t->counter == 0)
		{
			t->head = t->tail = p;
			t->counter ++;
		}else
		{
			p->next = t->head;
			t->head->prev = p;
			t->head = p;
			t->counter ++;
		}
	}else if(i == t->counter)
	{
		if(t->counter == 0)
		{
			t->head = t->tail = p;
			t->counter ++;
		}else
		{
			t->tail->next = p;
			p->prev = t->tail;
			t->tail = p;
			t->counter ++;
		}
	}else
	{
		prev_node = t->head;
		for (int j = 0; j < t->counter; j++)
		{
			if(j == i-1) break;
			prev_node = prev_node->next;
		}
		
		assert(prev_node != NULL);

		next_node = prev_node->next;
		prev_node->next = p;
		p->next = next_node;
		next_node->prev = p;
		p->prev = prev_node;

		t->counter ++;
	}

	return t;
}

struct doubly_linked_list *delete_at(struct doubly_linked_list *t, int i)
{
	assert(t->counter > 0);
	assert(0 <= i && i < t->counter);

	struct node *p, *prev_node, *cur_node, *next_node;

	if(i == 0)
	{
		if(t->counter == 1)
		{
			free(t->head);
			t->head = t->tail = NULL;
			t->counter --;
		}else
		{
			p = t->head->next;
			free(t->head);
			t->head = p;
			t->counter --;
		}
	}else if(i > 0)
	{
		cur_node = t->head;
		for (int j = 0; j < t->counter; j++)
		{
			if(j == i) break;
			cur_node = cur_node->next;
		}

		assert(cur_node != NULL);
		
		if(cur_node == t->tail) 
		{
			prev_node = cur_node->prev;
			t->tail = prev_node;
		}else
		{
			prev_node = cur_node->prev;
			next_node = cur_node->next;
			prev_node->next = next_node;
			next_node->prev = prev_node;
		}
		
		t->counter --;

		free(cur_node);
	}

	return t;
}

int size( struct doubly_linked_list *t )
{
	return t->counter;
}

T get( struct doubly_linked_list *t, int i )
{
	assert(t->counter > 0);
	assert(0 <= i && i < t->counter);

	struct node *p;

	p = t->head;
	for (int j = 0; j < t->counter; j++)
	{
		if(j == i) break;
		p = p->next;
	}

	assert(p != NULL);

	return(p->data);
}

void replace( struct doubly_linked_list *t, int i, T e )
{
	assert(t->counter > 0);
	assert(0 <= i && i < t->counter);

	struct node *p;

	p = t->head;
	for (int j = 0; j < t->counter; j++)
	{
		if(j == i) break;
		p = p->next;
	}

	assert(p != NULL);

	p->data = e;

	return;
}

int index( struct doubly_linked_list *t, T e )
{
	struct node *p;

	p = t->head;
	for (int j = 0; j < t->counter; j++)
	{
		if(p->data == e) return j;
		p = p->next;
	}

	return -1;
}
