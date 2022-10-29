#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 123~987 까지 하나하나 확인해보자
vector<bool> num(1000, false);

// 0 포함된 수 제외, 같은 수 제외
void setNum()
{
    for (int i = 123; i <= 987; i++)
    {
        string temp = to_string(i);
        // 1. 0을 포함한 경우. 두자리, 세자리수에서만 0이 포함됨
        if (temp[0] == '0' || temp[1] == '0' || temp[2] == '0')
            continue;
        // 2. 같은 수를 사용한 경우
        if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2])
            continue;
        num[i] = true;
    }
}

//비교해서 결과값이 일치하는 것들만 남긴다
void compResult(int input, int st, int ba)
{
    string st1 = to_string(input);
    for (int i = 123; i <= 987; i++)
    {
        int compS = 0, compB = 0;
        string st2 = to_string(i);
        if (!num[i])
            continue;
        for (int p = 0; p < 3; p++)
        {
            for (int q = 0; q < 3; q++)
            {
                // 1. 스트라이크인 경우
                if (p == q && st1[p] == st2[q])
                {
                    compS++;
                    continue;
                }
                if (p != q && st1[p] == st2[q])
                {
                    compB++;
                    continue;
                }
            }
        }
        if (st != compS || ba != compB)
        {
            num[i] = false;
            continue;
        }
    }
}

int main()
{
    int N, input, st, ba, count = 0;

    setNum();

    cin >> N;

    while (N--)
    {
        cin >> input >> st >> ba;
        compResult(input, st, ba);
    }

    for (int i = 123; i <= 987; i++)
    {
        if (num[i])
            count++;
    }

    cout << count;

    return 0;
}