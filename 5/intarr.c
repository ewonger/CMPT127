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
  return INTARR_BADINDEX;
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
  return INTARR_BADINDEX;
}

intarr_t* intarr_copy( const intarr_t* ia )
{
  intarr_t* duplicate=malloc(sizeof(intarr_t));
  if (duplicate!=NULL&&ia!=NULL)
  {
    duplicate->len=ia->len;
    unsigned int numbytes=(ia->len)*sizeof(intarr_t);
    duplicate->data=malloc(numbytes);
    memcpy(duplicate->data,ia->data,numbytes);
    return duplicate;
  }
  return NULL;
}

intarr_result_t intarr_sort( intarr_t* ia )
{
  int i=0,k,swap,minindex;
  if (ia!=NULL)
  {
    for (i=0;i<(ia->len)-1;i++)
    {
      minindex=i;
      for (k=i+1;k<ia->len;k++)
      {
        if (ia->data[k]<ia->data[minindex])
        {
          minindex=k;
        }
      }
      if (minindex!=i)
      {
        swap=ia->data[i];
        ia->data[i]=ia->data[minindex];
        ia->data[minindex]=swap;
      }
    }
    return INTARR_OK;
  }
  return INTARR_BADARRAY;
}

intarr_result_t intarr_find( intarr_t* ia, int target, int* i )
{
  int k=0;
  if (ia!=NULL)
  {
    for (k=0;k<ia->len;k++)
    {
      if (ia->data[k]==target&&i!=NULL)
      {
        i=&k;
        return INTARR_OK;
      }
    }
    return INTARR_NOTFOUND;
  }
  return INTARR_BADARRAY;
}

intarr_result_t intarr_push( intarr_t* ia, int val )
{
  if (ia!=NULL)
  {
    intarr_t* temp=malloc(sizeof(intarr_t));
    temp->len=ia->len;
    temp->data=malloc(ia->len*sizeof(intarr_t));
    memcpy(temp->data,ia->data,ia->len*sizeof(intarr_t));
    ia->data=malloc((ia->len+1)*sizeof(intarr_t));
    ia->len=(ia->len)+1;
    memcpy(ia->data,temp->data,temp->len*sizeof(intarr_t));
    free(temp);
    ia->data[(ia->len)-1]=val;
    if (ia->data[ia->len-1]==val)
    {
      return INTARR_OK;
    }
    return INTARR_BADALLOC;
  }
  return INTARR_BADARRAY;
}

intarr_result_t intarr_pop( intarr_t* ia, int* i )
{
  if (ia!=NULL)
  {
    if (ia->len>0&&i!=NULL)
    {
      intarr_t* temp=malloc(sizeof(intarr_t));
      temp->len=ia->len;
      temp->data=malloc(ia->len*sizeof(intarr_t));
      memcpy(temp->data,ia->data,ia->len*sizeof(intarr_t));
      ia->data=malloc((ia->len-1)*sizeof(intarr_t));
      ia->len=ia->len-1;
      memcpy(ia->data,temp->data,(temp->len-1)*sizeof(intarr_t));
      free(temp);
      i=&ia->data[ia->len-1];
      return INTARR_OK;
    }
    return INTARR_BADINDEX;
  }
  return INTARR_BADARRAY;
}

intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen )
{
  if (ia!=NULL)
  {
    if (ia->len>newlen)
    {
      intarr_t* temp=malloc(sizeof(intarr_t));
      temp->len=ia->len;
      temp->data=malloc(ia->len*sizeof(intarr_t));
      memcpy(temp->data,ia->data,ia->len*sizeof(intarr_t));
      ia->data=malloc((newlen)*sizeof(intarr_t));
      if (ia->data==NULL)
      {
        return INTARR_BADALLOC;
      }
      ia->len=newlen;
      memcpy(ia->data,temp->data,(newlen)*sizeof(intarr_t));
      free(temp);
      return INTARR_OK;
    }
    else if (ia->len<newlen)
    {
      intarr_t* temp=malloc(sizeof(intarr_t));
      temp->len=ia->len;
      temp->data=malloc(ia->len*sizeof(intarr_t));
      memcpy(temp->data,ia->data,ia->len*sizeof(intarr_t));
      ia->data=malloc((newlen)*sizeof(intarr_t));
      if (ia->data==NULL)
      {
        return INTARR_BADALLOC;
      }
      ia->len=newlen;
      memcpy(ia->data,temp->data,(newlen)*sizeof(intarr_t));
      free(temp);
      return INTARR_OK;
    }
  }
  return INTARR_BADARRAY;
}

intarr_t* intarr_copy_subarray( intarr_t* ia,
                        				unsigned int first,
                        				unsigned int last )
{
  if (ia!=NULL&&first<ia->len&&last<ia->len&&first<last)
  {
    int newarrlen=last-first+1,i=0,k;
    intarr_t* newarr=malloc(sizeof(intarr_t));
    if (newarr==NULL)
    {
      return NULL;
    }
    newarr->len=newarrlen;
    newarr->data=malloc(newarrlen*sizeof(intarr_t));
    for (i=0,k=first;i<newarrlen;i++,k++)
    {
      newarr->data[i]=ia->data[k];
    }
    return newarr;
  }
  return NULL;
}
