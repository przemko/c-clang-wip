int silnia_iter(int n, int acc)
{
  while(n > 0)
  {
    acc = acc * n;
    n = n - 1;
  }
  return acc;
}

int silnia(int n)
{
  return silnia_iter(n, 1);
}

