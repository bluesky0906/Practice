#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> r.at(i);

    int minimum = r.at(0);
    int profit = r.at(1) - r.at(0);
    for (int i = 2; i < n; i++)
    {
        minimum = min(minimum, r.at(i - 1));
        profit = max(profit, r.at(i) - minimum);
    }
    cout << profit << endl;
}