#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double pi = 3.14159;

int main()
{
  double raio;

  cin >> raio;

  cout << fixed << setprecision(4);

  cout << "A=" << pi * (pow(raio, 2)) << endl;

  return 0;
}
