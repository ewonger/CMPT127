#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <string.h> // for memset()
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "intarr.h"

intarr_t* intarr_create( unsigned int len )
{
  intarr_t* ia=malloc(sizeof(intarr_t));
  if (ia!=NULL)
  {
    ia->len=len;
    ia->data=malloc(len*sizeof(intarr_t));
    return ia;
  }
  else
  {
    return NULL;
  }
}

void intarr_destroy( intarr_t* ia )
{
  if (ia!=NULL)
  {
    if (ia->data!=NULL)
    {
      free(ia->data);
    }
  }
}

intarr_result_t intarr_set( intarr_t* ia,
                  			    unsigned int index,
                  			    int val )
{
  if (index>=0&&index<ia->len&&ia!=NULL)
  {
    ia->data[index]=val;
    return INTARR_OK;
  }
  else if (ia==NULL)
  {
    return INTARR_BADARRAY;
  }
  else
  {
    return INTARR_BADINDEX;
  }
}

intarr_result_t intarr_get( const intarr_t* ia,
                  			    unsigned int index,
                  			    int* i )
{
  if (index>=0&&index<ia->len&&i!=NULL)
  {
    *i=ia->data[index];
    return INTARR_OK;
  }
  else if (ia==NULL)
  {
    return INTARR_BADARRAY;
  }
  else
  {
    return INTARR_BADINDEX;
  }
}

intarr_t* intarr_copy( const intarr_t* ia )
{
  intarr_t* duplicate=malloc(sizeof(intarr_t));
  if (duplicate!=NULL||ia!=NULL)
  {
    duplicate->len=ia->len;
    unsigned int numbytes=(ia->len)*sizeof(intarr_t);
    duplicate->data=malloc(numbytes);
    memcpy(duplicate->data,ia->data,numbytes);
    return duplicate;
  }
  else
  {
    return NULL;
  }
}
