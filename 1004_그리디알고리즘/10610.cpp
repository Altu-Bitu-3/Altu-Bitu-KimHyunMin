#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 30의 배수 조건
//  1. 0으로 끝나야하고
//  2. 각 자리수 총합이 3의 배수

int check(string &n)
{
    if (n[n.length() - 1] != '0')
    {
        return 1;
    }
    long long sum = 0;
    for (auto i : n)
    {
        sum += i - '0';
    }
    if (sum % 3 == 0)
        return 0;
    else
        return 1;
}

int main()
{
    string n;
    cin >> n;
    //내림차순으로 정리
    sort(n.begin(), n.end(), greater<char>());
    if (check(n))
    {
        cout << -1;
    }
    else
        cout << n;

    return 0;
}