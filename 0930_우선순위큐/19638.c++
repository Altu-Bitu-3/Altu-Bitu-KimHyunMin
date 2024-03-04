#include <iostream>
#include <queue>

using namespace std;

int result(int h, int t, priority_queue<int> &q)
{
    int magic = 0, highest = 0; // magic는  센티가 마법을 사용한 횟수, highest는 가장 키가 큰 거인

    while (magic < t)
    {
        highest = q.top(); //가장 큰 애가 들어감(우선순위 큐 때문)
        if (highest == 1 || highest < h)
        {
            break;
        }

        q.pop();
        q.push(highest / 2);
        magic++;
    }
    return magic;
}

//이제 마법이 끝난 후

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, h, t, temp;
    cin >> n >> h >> t;

    priority_queue<int> q;

    while (n--)
    {
        cin >> temp;
        q.push(temp);
    }

    int magic = result(h, t, q);

    if (q.top() >= h)
    {
        cout << "NO\n"
             << q.top() << "\n";
    }
    else
    {
        cout << "YES\n"
             << magic << "\n";
    }

    return 0;
}