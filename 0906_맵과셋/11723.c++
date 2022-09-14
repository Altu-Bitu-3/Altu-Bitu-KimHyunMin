#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<int> s, all;

    int m, x;
    string cmd;

    cin >> m;

    for (int i = 1; i <= 20; i++) //매번 for문을 돌리면 시간이 오래 걸려서 미리 저장해둠
    {
        all.insert(i);
    }

    while (m--)
    {
        cin >> cmd;
        if (cmd == "add")
        {
            cin >> x;
            s.insert(x);
        }
        else if (cmd == "remove")
        {
            cin >> x;
            s.erase(x);
        }
        else if (cmd == "check")
        {
            cin >> x;
            cout << s.count(x) << "\n";
        }
        else if (cmd == "toggle")
        {
            cin >> x;
            if (s.count(x))
            {
                s.erase(x);
            }
            else
            {
                s.insert(x);
            }
        }
        else if (cmd == "all")
        {
            s = all;
        }
        else if (cmd == "empty")
        {
            s.clear();
        }
    }

    return 0;
}