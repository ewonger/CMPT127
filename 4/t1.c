#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void draw_circle( uint8_t img[],
                  unsigned int cols,
                  unsigned int rows,
		              int x,
		              int y,
		              int r,
		              uint8_t color );
{
  unsigned int i=0,k=0,index,left=x-r-1,right=x+r,top=y-r-1,bottom=y+r;

  for (i=top;i<bottom;i++)
  {
    for (k=left;k<right;k++)
    {
      index=k+i*cols;
      array[index]=color;
    }
  }
}
