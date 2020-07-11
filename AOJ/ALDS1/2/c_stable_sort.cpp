#include <bits/stdc++.h>
using namespace std;

struct Card
{
    string value;
    string suit;

    bool operator==(const Card &c) const
    {
        return (value == c.value &&
                suit == c.suit);
    }
};

void print_vector(vector<Card> A, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A.at(i).suit << A.at(i).value;
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;
}

vector<Card> bubble_sort(vector<Card> A, int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (A.at(j - 1).value > A.at(j).value)
            {
                count++;
                swap(A.at(j), A.at(j - 1));
            }
        }
    }
    return A;
}

vector<Card> selection_sort(vector<Card> A, int N)
{
    int count = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int minj = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A.at(minj).value > A.at(j).value)
            {
                minj = j;
            }
        }
        if (i != minj)
            count++;
        swap(A.at(i), A.at(minj));
    }
    return A;
}

// O(n^4)
// bool is_stable(vector<Card> A, vector<Card> B, int N)
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = i + 1; j < N; j++)
//         {
//             for (int a = 0; a < N; a++)
//             {
//                 for (int b = a + 1; b < N; b++)
//                 {
//                     if (A.at(i).value == A.at(j).value &&
//                         A.at(i) == B.at(b) && A.at(j) == B.at(a))
//                         return false;
//                 }
//             }
//         }
//     }
//     return true;
// }

// O(N) bubbleはstableなので、bubbleと比較
bool is_stable(vector<Card> B, vector<Card> C, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (B.at(i).suit != C.at(i).suit)
            return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    vector<Card> A(N);
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        A.at(i).value = s.at(1);
        A.at(i).suit = s.at(0);
    }

    vector<Card> B = bubble_sort(A, N);
    print_vector(B, N);
    cout << "Stable" << endl;

    vector<Card> C = selection_sort(A, N);
    print_vector(C, N);
    if (is_stable(B, C, N))
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }
}