int fibonacci(int n)
{
  int acc = 1;
  while(n > 1)
    acc = acc + fibonacci((n--) - 2);
  return acc;
}

// acc = 1 + fibnacci(n - 2) + fibonacci (n - 3) + ... + fibonacci(0)
//     = fibonacci(n)

