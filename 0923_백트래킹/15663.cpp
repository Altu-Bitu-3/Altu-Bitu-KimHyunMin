#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;
int n, m;
vector<int> num(SIZE);
vector<bool> check(SIZE);
//재귀함수 사용할 것이므로 전역변수로 넣어줬다...

int result[SIZE];
// vector로 하려 했는데 그렇게 하면 오류가 뜹니다...
// result.insert(cnt,) num[i]) 여기에서 오류가 뜨는데 아마도 num[i]가 const가 아니라 생기는 문제 같음.

void backtracking(int cnt) // cnt :수열의 인덱스
{
    if (cnt == m)
    {
        for (int i = 0; i < cnt; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int last = 0; // 0을 입력받을 일은 없다.
    for (int i = 0; i < num.size(); i++)
    {
        if (!check[i] && num[i] != last)
        {
            result[cnt] = num[i];
            last = result[cnt];
            check[i] = true;
            backtracking(cnt + 1);
            check[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;

    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        num.insert(num.begin() + i, x);
    }

    sort(num.begin(), num.end());

    backtracking(0);
    return 0;
}