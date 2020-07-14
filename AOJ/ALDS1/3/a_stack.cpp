#include <bits/stdc++.h>
using namespace std;

// 再帰
int eval(stack<string> formula)
{
    string str = formula.top();
    formula.pop();
    if (str == "+" || str == "-" || str == "*")
    {
        int right = eval(formula);
        int left = eval(formula);
        if (str == "+")
        {
            return right + left;
        }
        else if (str == "-")
        {
            return left - right;
        }
        else if (str == "*")
        {
            return right * left;
        }
    }
    return stoi(str);
}

int main()
{
    stack<string> formula;
    string s;
    getline(cin, s);

    stringstream ss;
    ss << s;
    string str;
    while (ss >> str)
    {
        formula.push(str);
    }
    cout << eval(formula) << endl;
    return 0;
}

// C 的な書き方
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int top, S[1000];

// void push(int x)
// {
//     S[++top] = x;
// }

// int pop()
// {
//     top--;
//     return S[top + 1];
// }

// int main()
// {
//     int a, b;
//     top = 0;

//     char s[100];

//     while (scanf("%s", s) != EOF)
//     {
//         char str = s[0];
//         if (str == '+' || str == '-' || str == '*')
//         {
//             int right = pop();
//             int left = pop();
//             if (str == '+')
//             {
//                 push(right + left);
//             }
//             else if (str == '-')
//             {
//                 push(left - right);
//             }
//             else if (str == '*')
//             {
//                 push(right * left);
//             }
//         }
//         else
//         {
//             push(atoi(s));
//         }
//     }
//     printf("%d\n", pop());
// }