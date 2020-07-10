#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, a, count = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (is_prime(a))
        {
            count++;
        }
    }
    cout << count << endl;
}