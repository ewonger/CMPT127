#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <string.h> // for memset()
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "intarr.h"

int intarr_save_binary( intarr_t* ia, const char* filename )
{
  if (ia!=NULL&&filename!=NULL);
  {
    FILE* f = fopen( filename, "w" );
    if (f!=NULL)
    {
      fwrite( &ia->len, sizeof(int),1,f);
      fwrite( ia->data, sizeof(int), ia->len, f );
      fclose( f );
      return 0;
    }
  }
  return 1;
}

intarr_t* intarr_load_binary( const char* filename )
{
  int len;
  if (filename!=NULL)
  {
  FILE* f=fopen(filename,"r");
  if (f!=NULL)
  {
    intarr_t* newarr;
    newarr=malloc(sizeof(intarr_t));
    fread(&newarr->len,sizeof(int),1,f);
    newarr->data=malloc(newarr->len*sizeof(int));
    fread(newarr->data,sizeof(int),newarr->len,f);
    fclose( f );
    return newarr;
  }
}
  return NULL;
}
