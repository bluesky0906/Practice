#include <bits/stdc++.h>
using namespace std;

typedef struct p
{
    string name;
    int time;
} P;

// queueを使う
// int main()
// {
//     int n, q;
//     cin >> n >> q;

//     queue<P> process;

//     for (int i = 0; i < n; i++)
//     {
//         string n;
//         int t;
//         cin >> n >> t;
//         P p;
//         p.name = n;
//         p.time = t;
//         process.push(p);
//     }
//     int sum_time = 0;
//     while (!process.empty())
//     {
//         P p = process.front();
//         process.pop();
//         if (p.time > q)
//         {
//             p.time -= q;
//             sum_time += q;
//             process.push(p);
//         }
//         else
//         {
//             sum_time += p.time;
//             cout << p.name << " " << sum_time << endl;
//         }
//     }
// }

// 配列
#define LEN 100005
P Q[LEN + 1];
int head, tail, n;

void enqueue(P x)
{
    Q[tail] = x;
    tail = (tail + 1) % LEN;
}

P dequeue()
{
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
}

int main()
{
    int elaps = 0, c;
    int i, q;
    P u;
    scanf("%d %d", &n, &q);

    for (i = 1; i <= n; i++)
    {
        string s;
        int t;
        cin >> s >> t;
        Q[i].name = s;
        Q[i].time = t;
    }
    head = 1;
    tail = n + 1;
    while (head != tail)
    {
        P p = dequeue();
        if (p.time > q)
        {
            p.time -= q;
            elaps += q;
            enqueue(p);
        }
        else
        {
            elaps += p.time;
            cout << p.name << " " << elaps << endl;
        }
    }
    return 0;
}