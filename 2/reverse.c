void reverse( int arr[],unsigned int len)
{
  int i, k;

  for( i=0; i<len/2; i++)
  {
    k=arr[i];
    arr[i]=arr[len-1];
    arr[len-1]=k;
  }
}
