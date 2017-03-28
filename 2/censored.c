#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] )
{
  int ch;
  int found=0;
  int i=0, n=0;
  char tempArr[128]={0};

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
        if (strcmp(argv[n],tempArr)==0)
        {
          printf("CENSORED");
          found=1;
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
