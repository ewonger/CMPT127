#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

int intarr_save_json( intarr_t* ia, const char* filename )
{
	if (ia == NULL)
	{
		return 1;
	}
	FILE* f= fopen(filename,"w");
	if (f == NULL)
	{
		return 1;
	}
	fprintf(f,"[\n");
	for (int i=0; i<ia->len; i++)
		{
			fprintf(f," %d\n",ia->data[i]);
		}
	fprintf(f,"]");
	fclose(f);
	return 0;
}

intarr_t* intarr_load_json( const char* filename ){
	FILE* f = fopen(filename, "r");
	if (f == NULL)
	{
		return NULL;
	}
	intarr_t* newarr = intarr_create(0);
	int num;
	fscanf(f,"%c ",&num);
	char array[100];
	while (fgets(array,100,f))
	{
		if (array[0] == ']' || sscanf(array,"%d",&num)!=1)
		{
			break;
		}
		intarr_push(newarr,num);
	}
	fclose(f);
	return newarr;
}
