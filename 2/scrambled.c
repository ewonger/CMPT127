int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
  int i;
  int k=0;
  int n[100];

  for ( i=0; i<100; i++)
  {
    n[i]=0;
  }
  for ( i=0; i<len; i++)
  {
    n[a[i]]++;
    n[b[i]]--;
  }
  for ( i=0; i<100; i++)
  {
    if (n[i]==1)
    {
      k++;
    }
  }
  if (k!=0)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
