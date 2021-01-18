int silnia_rek(int n, int acc)
{
  if(n == 0)
    return acc;
  else
    return silnia_rek(n - 1, n * acc);
}

int silnia(int n)
{
  return silnia_rek(n, 1);
}

