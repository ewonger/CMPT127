#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <string.h> // for memset()
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "intarr.h"

int intarr_save_binary( intarr_t* ia, const char* filename )
{
  if (ia!=NULL);
  {
    FILE* f = fopen( filename, "w" );
    if (f!=NULL)
    {
      fwrite( &ia->len, sizeof(intarr_t),1,f);
      fwrite( ia->data, sizeof(intarr_t), ia->len, f );
      printf("%d\n",ia->len);
      fclose( f );
      return 0;
    }
  }
  return 1;
}

intarr_t* intarr_load_binary( const char* filename )
{
  FILE* f=fopen(filename,"r");
  if (f!=NULL);
  {
    intarr_t* newarr=malloc(sizeof(intarr_t));
    fread(&newarr->len,sizeof(intarr_t),1, f);
    newarr->data=malloc((newarr->len)*sizeof(intarr_t));
    fclose( f );
    return newarr;
  }
  return NULL;
}
