#include <stdio.h>

int InRectangle( float pt[2], float rect[4] )
{
  int flagx=0,flagy=0;

  if (rect[2]>rect[0])
  {
    if (rect[3]>rect[1])
    {
      if (pt[1]>=rect[1]&&pt[1]<=rect[3])
      {
        printf("y=1\n");
        flagy=1;
      }
      if (pt[0]<=rect[2]&&pt[0]>=rect[0])
      {
        printf("x=1\n");
        flagx=1;
      }
    }
    else if (rect[3]<rect[1])
    {
      if (pt[1]>=rect[3]&&pt[1]<=rect[1])
      {
        printf("y=1\n");
        flagy=1;
      }
      if (pt[0]<=rect[2]&&pt[0]>=rect[0])
      {
        printf("x=1\n");
        flagx=1;
      }
    }
  }
  else if (rect[2]<rect[0])
  {
    if (rect[3]>rect[1])
    {
      if (pt[1]>=rect[1]&&pt[1]<=rect[3])
      {
        printf("y=1\n");
        flagy=1;
      }
      if (pt[0]<=rect[0]&&pt[0]>=rect[2])
      {
        printf("x=1\n");
        flagx=1;
      }
    }
    else if (rect[3]<rect[1])
    {
      if (pt[1]>=rect[3]&&pt[1]<=rect[1])
      {
        printf("y=1\n");
        flagy=1;
      }
      if (pt[0]<=rect[0]&&pt[0]>=rect[2])
      {
        printf("x=1\n");
        flagx=1;
      }
    }
  }
  if (flagx==1 && flagy==1)
  {
    printf("returned 1");
    return 1;
  }
  else
  {
    printf("returned 0");
    return 0;
  }
}
