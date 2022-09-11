#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t, n, sum = 1;
    string ignore, kind;

    cin >> t;

    map<string, int> m; // key: 의상 종류, value: 의상 종류으 개수

    while (t--)
    {
        sum = 1;
        m.clear(); //이 둘은 재활용되기 때문에 반드시 초기화해줘야한다. sum은 곱하기로 계산되기 때문에 1
        cin >> n;
        while (n--)
        {
            cin >> ignore >> kind; //옷 이름은 중요하지 않아서 무시
            m[kind]++;
        }
        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            sum *= iter->second + 1;
        }
        cout << sum - 1 << "\n"; //전부 벗는 경우 뺌
    }

    return 0;
}