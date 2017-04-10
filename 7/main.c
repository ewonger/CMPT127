#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main( int argc, char* argv[] )
{
  list_t* list = list_create();
  if (list==NULL)
  {
    return 1;
  }
  for( int i=0; i<5; i++ )
    list_append( list, i );
  for( int i=-1; i>-5; i-- )
    list_prepend( list, i );
  list_print( list );
  int index = 2;
  element_t* el = list_index( list, index );
  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1; // fail
    }
  printf( "value at index %d is %d\n", index, el->val );
  if( el->val != -2 )
    return 1;

  list_t* list1 = list_create();
  list_append(list1,15);

  if(list1 == NULL)
  {
    return 1;
  }
  if(list1->head == NULL)
  {
    return 1;
  }

  if(list1->tail == NULL)
  {
    return 1;
  }
  if(list1->tail->next !=NULL)
  {
    return 1;
  }

  list_t* listw = list_create();
  list_index(listw,2);



  element_t *el2 = element_create(17);
  if(el2->val != 17)
  {
    printf("not 17");
  }
  if(el2 == NULL)
  {
    return 1;
  }
  element_t* el3 = element_create(26);

  list_t* list2 = list_create();
  for(int x = 0; x < 5; x++)
  {
    list_append( list2, x);

  }
  for(int x = -1; x > -5; x--)
   {

    list_prepend(list2, x);

  }
  if (list->tail->val != 4)
  {
    return 1;
  }

  el3->next = list_index(list2,3);
  free(el3->next);
  el3 = element_create(45);
  if(el3->next != NULL)
  {
    return 1;
  }


  list_t * list3 = list_create();
  list_prepend(list3,13);
  element_t* el4 = list_index(list3,5);
  while(1)
  {
    if(list3->head == NULL)
    {
      return 1;
    }
    if(el4 != NULL)
    {
      return 1;
    }
    break;
  }

  list_t * list4 = list_create();
  list_prepend(list4,64);
  if(list4->tail->val != 64)
  {
    return 1;
  }


  list_t *list5 = list_create();
  list5->head = element_create(923);
  list5->head->next = element_create(332);
  list5->tail = list5->head->next;
  free(list5);
  list5 = list_create();

  if(list5->tail != NULL)
  {
    return 1;
  }

  list_t *list6 = list_create();
  list_print(list6);
  list_destroy(list);
  list_destroy(list2);
  list_destroy(list3);
  list_destroy(list4);
  list_destroy(list5);
  list_destroy(list6);



  return 0; // tests pass
}
