#include <stdio.h>

int InRectangle( float pt[2], float rect[4] )
{
  if ((pt[1]<=rect[3]&&pt[1]>=rect[1]) && (pt[0]<=rect[2]&&pt[0]>=rect[0]))
  {
    return 1;
  }
  else if ((pt[1]>=rect[3]&&pt[1]<=rect[1]) && (pt[0]>=rect[2]&&pt[0]<=rect[0]))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
