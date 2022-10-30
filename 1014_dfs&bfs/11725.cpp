#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;

vector<int> tree[MAX];
int p1[MAX];
bool visited[MAX];

void findAns(int m)
{
    visited[m] = true;

    for (int i = 0; i < tree[m].size(); i++)
    {
        int next = tree[m][i];
        if (visited[next] == 0)
        {
            p1[next] = m;
            findAns(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, dot1, dot2;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> dot1 >> dot2;
        tree[dot1].push_back(dot2);
        tree[dot2].push_back(dot1);
    }

    findAns(1); // vector을 매개함수로 보내려니까 잘 안됨... MAX 때문인 것 같음

    for (int i = 1; i < n; i++)
    {
        cout << p1[i + 1] << "\n";
    }
    return 0;
}