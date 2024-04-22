#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> vs;

void insertionSort(vs &arr, int max)
{
  if (arr.size() <= 1)
    return;

  for (int i = 1; i <= arr.size(); i++)
  {
    if (max <= 0)
      return;

    string elemento = arr[i - 1];
    int pos = 0, j = 0;
    // Achar o menor no "range"
    for (int k = i; k < min((int)arr.size(), (i + max)); k++)
    {
      if (arr[k] < elemento)
      {
        elemento = arr[k];
        pos = k;
        j = k - 1;
      }
    }

    // Mover elemento
    while (j >= 0 && arr[j] > elemento)
    {
      arr[j + 1] = arr[j];
      j--;

      // Decrementar range disponivel
      max--;
    }

    arr[j + 1] = elemento;
  }
}

void printv(vs a)
{
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main()
{
  int n, maxt, cont;

  cin >> n >> maxt;
  cont = 1;
  while (!(n == maxt && n == 0))
  {
    vs a;
    a.assign(n, "");

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    cout << "Instancia " << cont << endl;
    insertionSort(a, maxt);
    printv(a);

    cin >> n >> maxt;
    cont++;
  }

  return 0;
}