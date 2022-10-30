#include <iostream>
#include <vector>

using namespace std;

void flipSwitch(int switchNum, int sex, int givenNum, vector<int> &swit)
{
    //남자인 경우
    if (sex == 1)
    {
        for (int i = givenNum; i <= switchNum; i += givenNum)
        {

            swit[i - 1] = 1 - swit[i - 1];
        }
    }
    //여자인 경우
    else
    {
        int left = givenNum - 1, right = left;
        swit[left] = 1 - swit[left];
        while (swit[left] == swit[right])
        {
            swit[left] = 1 - swit[left];
            swit[right] = 1 - swit[right];
            left--;
            right++;
            if (left < 0 || right >= switchNum)
                break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, sex, num;

    cin >> n; //스위치 개수
    vector<int> swit(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> swit[i];
    }

    cin >> m; //학생수

    while (m--)
    {
        cin >> sex >> num;
        flipSwitch(n, sex, num, swit);
    }
    for (int i = 0; i < n; i++)
    {
        cout << swit[i] << " ";
        if ((i + 1) % 20 == 0)
        {
            cout << '\n';
        }
    }
    return 0;
}