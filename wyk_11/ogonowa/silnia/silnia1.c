int silnia(int n)
{
  if(n == 0)
    return 1;
  else
    return n * silnia(n - 1);
}

