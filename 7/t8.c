#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void concat( list_t* l1, list_t* l2)
{
	if (l2->head == NULL)
  {
		assert(l2->tail == NULL);
	}
	else if (l1->head == NULL)
  {
		assert(l1->head == NULL);
		*l1 = *l2;
	}
	else
  {
		l1->tail->next = l2->head;
		l1->tail = l2->tail;
	}
	free(l2);
	}

void list_sort( list_t* list )
{
	if (list->head == list->tail)
  {
		return;
	}
	else
  {
		element_t* pivot = list->head;
		element_t* swp = list->head->next;
		list_t* l1 = list_create();
		list_t* l2 = list_create();
		while (swp != NULL)
    {
			if (swp->val < pivot->val)
      {
				list_append(l1,swp->val);
			}
			else
      {
				list_append(l2,swp->val);
			}
			swp = swp->next;
		}
		list->head = NULL;
		list->tail = NULL;
		list_sort(l1);
		list_sort(l2);
		concat(list,l1);
		list_append(list,pivot->val);
		concat(list,l2);
	}
}
