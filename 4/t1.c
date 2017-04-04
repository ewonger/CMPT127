#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void draw_circle( uint8_t img[],
                  unsigned int cols,
                  unsigned int rows,
		              int x,
		              int y,
		              int r,
		              uint8_t color )
{
  int i=0,k=0,index,left=x-r,right=x+r,top=y-r,bottom=y+r;
  double htopleft,htopright,hbotleft,hbotright;
  if (r>0)
  {
    if (left<0)
    {
      left=0;
    }
    if (top<0)
    {
      top=0;
    }
    for (i=top;i<=bottom;i++)
    {
      if (i>rows)
      {
        break;
      }
      for (k=left;k<=right;k++)
      {

        index=k+i*cols;
        htopleft=hypot(k-0.5-x,i-0.5-y);
        htopright=hypot(k+0.5-x,i+0.5-y);
        hbotleft=hypot(k-0.5-x,i+0.5-y);
        hbotright=hypot(k+0.5-x,i-0.5-y);
        printf("%d %d %d\n",i,k,cols);
        if (k==cols||k==2*cols)
        {
          break;
        }
        else
        {
          if (htopleft<r||htopright<r||hbotleft<r||hbotright<r)
          {
            img[index]=color;
          }
        }
      }
    }
  }
}
