#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <stdio.h>

#include "list.h"

list_t* list_create( void )
{
	list_t* L = malloc( sizeof(list_t) );
	L->head = NULL;
	L->tail = NULL;
	return L;
}

void list_destroy( list_t* list )
{
	element_t* el = list->head;
  	while(el)
    {
    		element_t* next = el->next;
    		free(el);
    		el = next;
    	}
    	free(list);
}

element_t* element_create( int i )
{
	element_t* el = malloc(sizeof(element_t));
  	if(el)
    {
    		el->val = i;
    		el->next = NULL;
    	}
   	 return el;
}

int list_append(list_t* list, int i)
{
	element_t* el = element_create(i);
    	if(el == NULL)
      {
    		return 1;
	}
 	if(list->head == NULL)
  {
    list->head = el;
	}
	if( list->tail )
  {
		list->tail->next = el;
	}
  	list->tail = el;
  	return 0;
}

int list_prepend( list_t* list, int i )
{
	element_t* el = element_create( i );
  	if( el == NULL )
    {
    	return 1;
	}
 	if( list->tail == NULL )
  {
    	list->tail = el;
	}
  	if( list->head )
    {
    	el->next = list->head;
	}
  	list->head = el;
 	 return 0;
}

element_t* list_index( list_t* list, unsigned int i )
{
	if( list->head == NULL )
  {
    return NULL;
  }
  	element_t* el = list->head;
  	unsigned int k = 0;
  	while( k < i )
    {
    	if( el->next == NULL )
      {
			return NULL;
		}
      	k++;
      	el = el->next;
	}
  return el;
}

void list_print( list_t* list )
{
  element_t* el;
	printf( "{" );
  	for( el = list->head; el; el = el->next ){
    	printf( " %d", el->val );
	}
    printf( " }\n" );
}
