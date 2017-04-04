#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void draw_rectangle( uint8_t array[],
		          unsigned int cols,
		          unsigned int rows,
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color )
{
  int i=0,k=0,index;

  if (rect_width!=0||rect_height!=0)
  {
    if (rect_width<0||rect_height<0)
    {
      if (rect_width<0)
      {
        rect_width=rect_width*-1;
      }
      if (rect_height<0)
      {
        rect_height=rect_height*-1;
      }
      for (i=y-rect_height+1;i<=y;i++)
      {
        if (i<0)
        {
          i=0;
        }
        for (k=x-rect_width+1;k<=x;k++)
        {
          if (k<0)
          {
            k=0;
          }
          index=k+i*cols;
          if (k==cols)
          {
            break;
          }
          if (i==y-rect_height+1||i==y||k==x-rect_width+1||k==x)
          {
            array[index]=color;
						printf("(%d,%d)\n",k,i);
          }
        }
      }
    }
    else if (rect_width>0&&rect_height>0)
    {
      for (i=y;i<=y+rect_height-1;i++)
      {
        if (i<0)
        {
          i=0;
        }
        for (k=x;k<=x+rect_width-1;k++)
        {
          if (k<0)
          {
            k=0;
          }
          index=k+i*cols;
          if (k==cols)
          {
            break;
          }
          if (i==y||i==y+rect_height-1||k==x||k==x+rect_width-1)
          {
            array[index]=color;
						printf("(%d,%d)\n",k,i);
          }
        }
      }
    }
  }
}
