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

		rect_height=rect_height+1;
		rect_width=rect_width+1;
    for (i=y-rect_height;i<=y;i++)
    {
			if (i>=0)
			{
      	for (k=x-rect_width;k<=x;k++)
      	{
        	index=k+i*cols;
					if (index<0||index>cols*rows||k>=cols)
					{
						break;
					}
					if (k>=0)
					{
        		if (i==y-rect_height||i==y||k==x-rect_width||k==x)
        		{
          		array[index]=color;
        		}
					}
				}
    	}
  	}
	}
  else if (rect_width>0&&rect_height>0)
  {
		rect_height=rect_height-1;
		rect_width=rect_width-1;
    for (i=y;i<=y+rect_height;i++)
    {
			if (i>=0)
			{
      	for (k=x;k<=x+rect_width;k++)
      	{
        	index=k+i*cols;
					if (index<0||index>cols*rows||k>=cols)
					{
						break;
					}
					if (k>=0)
					{
        		if (i==y||i==y+rect_height||k==x||k==x+rect_width)
        		{
          		array[index]=color;
        		}
			  	}
      	}
			}
    }
  }
}
