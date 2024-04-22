#include <iostream>

using namespace std;

// Contador para contar as trocas de posição esq - dir
int cont = 0;

void merge(int *a, int left, int mid, int right)
{
  // Vetor auxiliar pois é utilizado o mesmo ponteiro para vetor esquerda e vetor direita
  int* aux = new int[right + 1];
  int i = left;
  int j = mid + 1;
  int k = 0;

  // Enquanto houver elementos em ambos os arranjos
  while (i <= mid && j <= right)
  {
    if (a[i] <= a[j])
      aux[k++] = a[i++];
    else
    {
      cont += (mid - i);
      aux[k++] = a[j++];
    }
  }

  // Caso os elementos de r tenham acabado, mas de l não
  while (i <= mid)
    aux[k++] = a[i++];

  // Caso os elementos de l tenham acabado, mas de r não
  while (j <= right)
    aux[k++] = a[j++];

  // Passando os valores de aux para o vetor principal
  while (k >= 0)
  {
    a[k + left] = aux[k];
    k--;
  }

  delete aux;
}

// Chamar como merge_sort(a, 0, n - 1);
void merge_sort(int *a, int left, int right)
{
  if (left < right)
  {
    int mid = (right + left) / 2;

    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
  }
}

void printv(int* a, int n){
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  
}

int main()
{
  int n = 1;

  while (cin >> n && n)
  {
    int *v = new int[n];

    for (int i = 0; i < n; ++i)
    {
      cin >> v[i];
    }
    cont = 0;

    merge_sort(v, 0, n-1);

    if (cont % 2 != 0)
      cout << "Marcelo" << endl;
    else
      cout << "Carlos" << endl;

    delete v;
  }

  return 0;
}