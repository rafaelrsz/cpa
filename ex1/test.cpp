#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> vs;

long long cont = 0;

vector<string> merge(vector<string> l, vector<string> r)
{
    vector<string> re;

    int i = 0;
    int j = 0;
    while (i != l.size() && j != r.size())
    {
        if (l[i] >= r[j])
        {
            re.push_back(l[i++]);
        }
        else
        {
            cont += (l.size() - i);
            re.push_back(r[j++]);
        }
    }

    while (i != l.size())
        re.push_back(l[i++]);

    while (j != r.size())
        re.push_back(r[j++]);

    return re;
}

vector<string> merge_d(vector<string> &A, int s, int e)
{
    if (s - e == 0)
    {
        vector<string> t;
        t.push_back(A[s]);
        return t;
    }

    int m = (s + e) / 2;

    vector<string> l;
    vector<string> r;
    l = merge_d(A, s, m);
    r = merge_d(A, m + 1, e);

    return merge(l, r);
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

    while (!cin.eof() && n != 0)
    {
        vs a;
        a.assign(n, "");
        cont = 0;
        for (int i = n-1; i >0; i--)
        {
            string matricula;
            cin >> matricula;
            a[i] = matricula;
        }
        a = merge_d(a, 0, n-1);

        cout << cont << endl;

        cin >> n;
    }

    return 0;
}