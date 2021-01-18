int silnia(int n)
{
  if(n == 0)
    return 1;
  else
    return n * silnia(n - 1);
}

// silnia(5) = 5 * silnia(4)
//           = 5 * 4 * silnia(3)
//           = 5 * 4 * 3 * silnia(2)
//           = 5 * 4 * 3 * 2 * silnia(1)
//           = 5 * 4 * 3 * 2 * 1 * silnia(0)
//           = 5 * 4 * 3 * 2 * 1 * 1
//           = 5 * 4 * 3 * 2 * 1
//           = 5 * 4 * 3 * 2
//           = 5 * 4 * 6
//           = 5 * 24
//           = 120

