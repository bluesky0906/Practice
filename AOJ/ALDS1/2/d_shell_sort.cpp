#include <bits/stdc++.h>
using namespace std;

int cnt;

void print_vector(vector<int> A, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A.at(i) << endl;
    }
}

void insertion_sort(vector<int> &A, int N, int g)
{
    int i, j, v;
    for (i = g; i < N; i++)
    {
        v = A.at(i);
        j = i - g;
        while (j >= 0 && A.at(j) > v)
        {
            A.at(j + g) = A.at(j);
            j -= g;
            cnt++;
        }
        A.at(j + g) = v;
    }
}

void shell_sort(vector<int> &A, int N)
{
    cnt = 0;
    vector<int> G;
    for (int g = 1; g <= N;)
    {
        G.push_back(g);
        g = 3 * g + 1;
    }

    int m = G.size();
    cout << m << endl;
    for (int i = m - 1; i >= 0; i--)
    {
        if (i != m - 1)
            cout << " ";
        cout << G.at(i);
        if (i == 0)
            cout << endl;
        insertion_sort(A, N, G.at(i));
    }
    cout << cnt << endl;
}

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A.at(i);

    shell_sort(A, N);

    print_vector(A, N);
}