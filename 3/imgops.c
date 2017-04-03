/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[],
           unsigned int cols,
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[],
        unsigned int cols,
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
}

// Set every pixel to 0 (black)
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  // your code here.
  memset(array,0,cols*rows*sizeof(uint8_t));
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[],
           unsigned int cols,
           unsigned int rows )
{
  // your code here
  int i=0;
  uint8_t* newArr=malloc(cols*rows*sizeof(uint8_t));
  if (newArr!=0)
  {
    for(i=0;i<cols*rows;i++)
    {
      newArr[i]=array[i];
    }
    return newArr;
  }
  else
  {
    return NULL;
  }
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[],
	     unsigned int cols,
	     unsigned int rows )
{
  // your code here
  unsigned int min=array[0], i=0;

  for (i=0;i<cols*rows;i++)
  {
    if (array[i]<=min)
    {
      min=array[i];
    }
  }
  return min;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[],
		 unsigned int cols,
		 unsigned int rows )
{
  // your code here
  unsigned int max=0, i=0;

  for (i=0;i<cols*rows;i++)
  {
    if (array[i]>=max)
    {
      max=array[i];
    }
  }
  return max;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[],
		     unsigned int cols,
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  // your code here
  unsigned int i=0;

  for (i=0;i<cols*rows;i++)
  {
    if (array[i]==pre_color)
    {
      array[i]=post_color;
    }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[],
              unsigned int cols,
              unsigned int rows )
{
  // your code here
  unsigned int i=0, k=0, lastindex, swap, index;

  for (i=0;i<rows;i++)
  {
    for (k=0;k<(cols/2);k++)
    {
      index=k+i*cols;
      lastindex=cols-1-k+i*cols;
      swap=array[index];
      array[index]=array[lastindex];
      array[lastindex]=swap;
    }
  }
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[],
            unsigned int cols,
            unsigned int rows )
{
    // your code here
    unsigned int i=0, k=0, lastindex, swap, index, n=0;

    for (i=0,n=rows-1;i<(rows/2);i++,n--)
    {
      for (k=0;k<cols;k++)
      {
        index=k+i*cols;
        lastindex=k+n*cols;
        swap=array[index];
        array[index]=array[lastindex];
        array[lastindex]=swap;
      }
    }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[],
		   unsigned int cols,
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // your code here
    unsigned int i=0, k=0, index;

    for (i=0;i<rows;i++)
    {
      for (k=0;k<cols;k++)
      {
        index=k+i*cols;
        if (array[index]==color)
        {
          *x=k;
          *y=i;
          return 1;
        }
      }
    }
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade.
void invert( uint8_t array[],
         unsigned int cols,
         unsigned int rows )
{
    // your code here
    unsigned int i=0;
    for (i=0;i<cols*rows;i++)
    {
      array[i]=255-array[i];
    }
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
    // your code here
    unsigned int i=0;
    float num;
    for (i=0;i<cols*rows;i++)
    {
      num=round(array[i]*scale_factor);
      if (num>255)
      {
        array[i]=255;
      }
      else
      {
        array[i]=num;
      }
    }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max().
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
    // your code here
    unsigned int min=array[0],max=0,i=0,num;

    for (i=0;i<cols*rows;i++)
    {
      if (array[i]<min)
      {
        min=array[i];
      }
      if (array[i]>max)
      {
        max=array[i];
      }
    }
    for (i=0;i<cols*rows;i++)
    {
      num=array[i]-min;
      array[i]=num;
    }
    for (i=0;i<cols*rows;i++)
    {
      num=(array[i]*255)/max;
      array[i]=num;
    }
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image
// has an odd number of columns, ignore its rightmost column. If the
// original image has an odd number of rows, ignore its bottom row.
// The value of a pixel at (p,q) in the new image is the average of
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in
// the original image.
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  // your code here
  unsigned int i=0,k=0,index,n=0,num;
  uint8_t* newArr=malloc((cols/2)*(rows/2)*sizeof(uint8_t));
  memset(newArr,0,(cols/2)*(rows/2)*sizeof(uint8_t));

  if (newArr!=0)
  {
    if (rows%2==1)
    {
      rows=rows-1;
    }
    if (cols%2==1)
    {
      cols=cols-1;
    }
    for (i=0;i<rows;i=i+2)
    {
      for (k=0;k<cols;k=k+2)
      {
        index=k+i*cols;
        num=((array[index]+array[(index)+1]+array[(index)+cols]+array[(index)+cols+1])/4);
        newArr[n]=num;
        n++;
      }
    }
    return newArr;
  }
  else
  {
    return NULL;
  }
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.

  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.

  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[],
         unsigned int cols,
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  // your code here
  unsigned int i, k, index;
  //assert right<=cols and bottom <=rows
  if (right==left ||top==bottom)
  {
    return;
  }
  else
  {
    for (i=top;i<bottom;i++)
    {
      for (k=left;k<right;k++)
      {
        index=k+i*cols;
        array[index]=color;
      }
    }
  }
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[],
                    unsigned int cols,
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  // your code here
  unsigned int i=0,k=0,index;
  unsigned long int sum=0;
  //assert right<=cols and bottom <=rows
  if (right==left ||top==bottom)
  {
    return sum;
  }
  else
  {
    for (i=top;i<bottom;i++)
    {
      for (k=left;k<right;k++)
      {
        index=k+i*cols;
        sum=sum+array[index];
      }
    }
    return sum;
  }
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[],
              unsigned int cols,
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  // your code here
  unsigned int i, k, index, n=0;
  uint8_t* newArr=malloc((right-left)*(bottom-top)*sizeof(uint8_t));
  memset(newArr,0,(right-left)*(bottom-top)*sizeof(uint8_t));

  if (newArr>0)
  {
    for (i=top;i<bottom;i++)
    {
      for (k=left;k<right;k++)
      {
        index=k+i*cols;
        newArr[n]=array[index];
        n++;
      }
    }
    return newArr;
  }
  else
  {
    return NULL;
  }
}
