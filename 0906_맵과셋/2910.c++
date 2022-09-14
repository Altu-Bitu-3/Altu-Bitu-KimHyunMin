#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> order; //순서를 저장

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)                   //같으면 가만히 둬야함
        return order[a.first] < order[b.first]; // first에는 m의 key값이 들어있고 그 key 값의 순서가 저장된 따라서 들어온 순서대로 정렬하겠다는 의미
    return a.second > b.second;
}

int main()
{
    map<int, int> frq; // key: 등장한 숫자,value: 빈도수
    int n, m, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        {
            cin >> m;
            frq[m]++;

            if (order[m] == 0)
            {                     //처음 들어옴
                order[m] = i + 1; // 순서 저장
            }
        }
    }

    vector<pair<int, int>> vec(frq.begin(), frq.end());
    sort(vec.begin(), vec.end(), cmp);

    for (auto it : vec)
    {
        int i = it.second; // i에 빈도수 저장
        while (i--)
        {
            cout << it.first << " ";
        }
    }

    return 0;
}