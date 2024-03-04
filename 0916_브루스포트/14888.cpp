#include <iostream>

using namespace std;

int n;
int oper[4];
int numlist[11];
int Max = -1000000001, Min = 1000000001; //무조건 바뀔 수밖에 없는 값들

void getAnswer(int result, int num)
{
    if (num == n)
    { //계산 끝남
        Min = min(result, Min);
        Max = max(result, Max);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (oper[i] == 0)
            continue;
        oper[i]--;
        switch (i)
        {
        case 0:
            getAnswer(result + numlist[num], num + 1);
            break;

        case 1:
            getAnswer(result - numlist[num], num + 1);
            break;

        case 2:
            getAnswer(result * numlist[num], num + 1);
            break;

        case 3:
            getAnswer(result / numlist[num], num + 1);
            break;
        }
        oper[i]++;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> numlist[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    }

    getAnswer(numlist[0], 1);
    cout << Max << "\n"
         << Min;

    return 0;
}