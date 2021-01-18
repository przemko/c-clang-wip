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

// silnia_rek(5, 1) = silnia_rek(4, 5 * 1)
//                  = silnia_rek(3, 4 * 5)
//                  = silnia_rek(2, 3 * 20)
//                  = silnia_rek(1, 2 * 60)
//                  = silnia_rek(0, 1 * 120)
//                  = 120

