#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "intarr.h"

int intarr_save_binary( intarr_t* ia, const char* filename )
{
  if (ia== NULL)
  {
    return 1;
  }
  FILE * f = fopen(filename,"w");
  if (f == NULL)
  {
    return 1;
  }
  if (fwrite(ia->data,sizeof(int),ia->len,f) != ia->len)
  {
    return 1;
  }
  fclose(f);
  return 0;

}

intarr_t* intarr_load_binary( const char* filename )
{
  struct stat buf;
  int file = stat(filename,&buf);
  if (file == -1)
  {
    return NULL;
  }
  if (filename == NULL)
  {
    return NULL;
  }

  FILE * f = fopen(filename,"r");
  fseek(f,0,SEEK_END);
  int len = (ftell(f))/(sizeof(int));
  if ( f == NULL)
  {
    return NULL;
  }
  if (len < 0)
  {
    return NULL;
  }
  intarr_t *newarr;
  newarr = intarr_create(len);
  fseek(f,0,SEEK_SET);
  if (fread(newarr->data,sizeof(int),len,f) !=len)
  {
    return NULL;
  }
  fclose(f);
  return newarr;
}
