#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void josepuhs(queue<int> &q, vector<int> &result, int n, int k)
{
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        q.push(i); //이제 q에 1~n까지 숫자가 들어가있다.
    }

    while (n--)
    {
        for (int i = 0; i < k - 1; i++)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp); //맨 앞에 있는 숫자를 뒤로 넘긴다.
        }
        result[j++] = q.front();
        q.pop(); // 3번째 값을 삭제.
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    queue<int> q;
    vector<int> result(n);

    josepuhs(q, result, n, k);

    cout << "<";
    for (int i = 0; i < n - 1; i++)
    {
        cout << result[i] << ", ";
    }
    cout << result[n - 1] << ">";

    return 0;
}