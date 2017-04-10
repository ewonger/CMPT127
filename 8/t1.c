#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "point_array.h"

void point_array_init( point_array_t* pa )
{
	if (pa == NULL)
  {
		return;
	}
	pa->points = malloc(sizeof(point_t));
	pa->len=0;
	pa->reserved=0;
}

void point_array_reset( point_array_t* pa ){
	if (pa == NULL)
  {
		return;
	}
	free(pa);
	pa->len=0;
	pa->reserved=0;
}

int point_array_append( point_array_t* pa, point_t* p )
{
	if (pa->points == NULL)
  {
		return 1;
	}
	pa->points=(point_t*)realloc(pa->points,(pa->len+1)*sizeof(point_t));
	pa->len++;
	if (pa->points==NULL)
  {
		return 1;
	}
	return 0;
}

int point_array_remove( point_array_t* pa, unsigned int i )
{
	if (pa==NULL||i>=pa->len)
  {
		return 1;
	}
	pa->points[i] = pa->points[pa->len-1];
	pa->points = realloc(pa->points,sizeof(point_t)*(pa->len-1));
	pa->len--;
	return 0;
}
