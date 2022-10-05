#include <iostream>
#include <queue>

using namespace std;

void result(int h, int t, priority_queue<int> &q)
{
    int magic = 0, highest = 0; // magic는  센티가 마법을 사용한 횟수, highest는 가장 키가 큰 거인

    while (magic < t)
    {
        highest = q.top(); //가장 큰 애가 들어감(우선순위 큐 때문)
        if (highest == 1)
            break;
        if (highest >= h) //만약 가장 큰 애가 센티 이상이면
        {
            q.pop();
            q.push(highest / 2);
            magic++;
        }
        else //센티가 더 크면
        {
            cout << "YES\n"
                 << magic << "\n";
            return;
        }
    }

    //이제 마법이 끝난 후

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
}

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

    result(h, t, q);

    return 0;
}