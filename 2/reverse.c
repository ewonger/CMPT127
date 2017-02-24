void reverse( int arr[],unsigned int len)
{
  int i, k;
  int n=len;

  for( i=0; i<len/2; i++)
  {
    k=arr[i];
    arr[i]=arr[n-1];
    arr[n-1]=k;
    n--;
  }
}
