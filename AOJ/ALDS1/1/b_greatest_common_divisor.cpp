#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    int r = x % y;
    if (r == 0)
        return y;
    return gcd(y, r);
}
int main()
{
    int x, y;
    cin >> x >> y;
    if (x < y)
    {
        swap(x, y);
    }
    cout << gcd(x, y) << endl;
}