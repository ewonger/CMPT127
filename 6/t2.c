#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <string.h> // for memset()
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "intarr.h"

int intarr_save_json( intarr_t* ia, const char* filename )
{
  int i=0;
	if (ia != NULL)
  {
		FILE* f=fopen(filename,"w");
		if (f!= NULL)
    {
			fprintf(f,"[");
			for (i=0; i<ia->len; i++)
      {
				if (i == ia->len-1)
        {
					fprintf(f," %d ",ia->data[i]);
				}
				else{
					fprintf(f," %d,",ia->data[i]);
				}
			}
		fprintf(f,"]");
		fclose(f);
		return 0;
		}
	}
	return 1;
}

intarr_t* intarr_load_json( const char* filename )
{
  int num;
  char arr[100];
	FILE* f=fopen(filename, "r");
	if (f==NULL)
  {
		return NULL;
	}
	intarr_t* load=intarr_create(0);
	fscanf(f,"%c ",&num);
	while (fgets(arr,100,f))
  {
		if (arr[0] == ']'||sscanf(arr,"%d",&num)!=1)
    {
			break;
		}
		intarr_push(load,num);
	}
	fclose(f);
	return load;
}
