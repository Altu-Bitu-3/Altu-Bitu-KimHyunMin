#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i = 0;
    cin >> n;

    vector<int> v(n);
    deque<int> dq;

    for (i = 0; i < n; i++)
    {
        cin >> v[i]; // while 끝나면 i에 n-1 들어있음
    }

    //함수로 따로 하려했는데 그러면 전달 인수도 많아지고 오히려 코드가 복잡해질 것 같아서 int에 넣었습니다.
    // 11866번처럼 void 함수로 인자를 여러개 보내는게 맞을까요?

    int card = 1;

    while (i--)
    {
        switch (v[i])
        {
        case 1:
            dq.push_front(card);
            break;
        case 2:
        {
            int tmp = dq.front();
            dq.pop_front();
            dq.push_front(card);
            dq.push_front(tmp);
            break;
        }
        case 3:
            dq.push_back(card);
            break;
        }
        card++;
    }

    for (i = 0; i < n; i++)
    {
        cout << dq[i] << " ";
    }

    return 0;
}