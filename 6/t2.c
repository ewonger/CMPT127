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
			fprintf(f,"[\n");
			for (i=0; i<ia->len; i++)
      {
				if (i == ia->len-1)
        {
					fprintf(f," %d\n",ia->data[i]);
				}
				else{
					fprintf(f," %d,\n",ia->data[i]);
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
  char arr[1000];
	FILE* f=fopen(filename, "r");
	if (f==NULL)
  {
		return NULL;
	}
	intarr_t* createarr=intarr_create(0);
	fscanf(f,"%d ",&num);
	while (fgets(arr,100,f))
  {
		if (arr[0] == ']'||scanf(arr,"%d",&num)!=1)
    {
			break;
		}
		intarr_push(createarr,num);
	}
	fclose(f);
	return createarr;
}
