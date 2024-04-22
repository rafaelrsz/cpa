#include <iostream>

using namespace std;

int chamadas = 0;

int fibo(int n)
{
  chamadas++;
  if (n == 0)
    return 0;

  if (n == 1)
    return 1;

  return fibo(n - 1) + fibo(n - 2);
}

int main()
{

  int n;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int j;
    cin >> j;
    chamadas = 0;
    int fib = fibo(j);
    cout << "fib(" << j << ") = " << chamadas-1 << " calls = " << fib << endl;
  }

  return 0;
}