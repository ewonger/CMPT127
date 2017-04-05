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
  int i=0,k=0,index;
  double htopleft,htopright,hbotleft,hbotright;
  if (r>0)
  {
    for (i=y-r;i<y+r;i++)
    {
      if (i>=0)
      {
      for (k=x-r;k<=x+r;k++)
      {
        if (k>=0)
        {
        index=k+i*cols;
        htopleft=hypot(k-0.5-x,i-0.5-y);
        htopright=hypot(k+0.5-x,i+0.5-y);
        hbotleft=hypot(k-0.5-x,i+0.5-y);
        hbotright=hypot(k+0.5-x,i-0.5-y);
        if (index<0||index>cols*rows||k>=cols)
        {
          break;
        }
        if (htopleft<r||htopright<r||hbotleft<r||hbotright<r)
        {
          img[index]=color;
        }
        }
      }
      }
    }
  }
}
