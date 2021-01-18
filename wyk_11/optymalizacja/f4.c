int g(int n);

int f(int n)
{
  if(n == 0)
    return 0;
  else
    return g(n) + f(n - 1);
}

