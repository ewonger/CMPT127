#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] )
{
  int ch;
  int found=0;
  int len2, k=0, i=0, count=0, n=0;
  int word=0, last;
  char tempArr[128];
  char newArr[128];

  while (EOF!=(ch=getchar()))
  {
    if ((ch>=65 && ch<=90) || (ch>=97 && ch<=122) || (ch==39))
    {
      tempArr[i]=ch;
      i++;
    }
    else
    {
      found=0;
      for (n=1;n<argc;n++)
      {
        if (strcmp(tempArr,argv[n])==0)
        {
          found=1;
          printf("CENSORED");
        }
      }
      if(found==0)
      {
        printf("%s",tempArr);
      }
      printf("%c",ch);
      memset(tempArr,0,128);
      i=0;
    }
  }
  return 0;
}
