#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> vs;

long long cont = 0;

vs merge(vs &v, const vs &left, const vs &right)
{

  vs temp; // Vetor auxiliar

  int i = 0; // Iterador esquerda
  int j = 0; // Iterador Direita

  // Enquanto tiver elementos nos dois lados
  while (i < left.size() && j < right.size())
  {
    if (left[i] > right[j])
    {
      temp.push_back(left[i]);
      i++;
    }
    else
    {
      cont += (left.size() - i);
      temp.push_back(right[j]);
      j++;
    }
  }

  // Enquanto só tiver elementos na esquerda
  while (i < left.size())
  {
    temp.push_back(left[i]);
    i++;
  }

  // Enquanto só tiver elementos na direita
  while (j < right.size())
  {
    // do the same for the right
    temp.push_back(right[j]);
    j++;
  }

  v = temp;
  return v;
}

vs merge_sort(vs &a)
{
  if (a.size() == 1) // Caso base -> se n=1 o vetor já está ordenado
    return a;

  // Divssão
  vs::iterator mid = a.begin() + (a.size() / 2); // Iterador é um ponteiro apontando para o meio

  // Conquista
  vs left(a.begin(), mid);
  vs right(mid, a.end());

  left = merge_sort(left);
  right = merge_sort(right);

  // Combinação
  return merge(a, left, right);
}

void print(vs v)
{
  for (int i = 0; i != v.size(); i++)
  {
    cout << v[i] << ",";
  }
  cout << endl
       << endl;
}

int main()
{
  int n;
  cin >> n;

  while (!cin.eof() && n > 0)
  {
    vs a(n);
    cont = 0;
    for (int i = n-1; i >= 0; i--)
    {
      string matricula;
      cin >> matricula;
      a[i] = matricula;
    }
    a = merge_sort(a);

    cout << cont << endl;

    cin >> n;
  }

  return 0;
}