#include <iostream>
#include <vector>

using namespace std;

int findAns(int n, int m, vector<int> &lamp)
{
    int l = 0;
    int r = n;
    bool flag = 0;
    while (l <= r)
    {
        //주석단 부분은 블로그 참고 전에 쓴 식... 이렇게 하면 계속해서 시간초과가 뜨는데 뭐가 문제인지 모르겠음
        /*
        int mid = (l + r) / 2;
        if (lamp[0] > mid || n - lamp[m - 1] > mid) //좌우로 어둠이 생기는 경우
        {
            l = mid + 1; //불빛을 키워야한다 mid보다 1 커짐
            continue;
        }
        for (; i < m - 1; i++)
        {
            if (lamp[i + 1] - lamp[i] > mid * 2) //가로등 사이 간격보다 mid*2 가 작으면 가로등 사이에 어두운 부분 생김
            {
                l = mid + 1;
                i = m; //여기서 continue를 하려 했는데 이중이라 while문 다음으로 넘어가는게 아님... 따라서 따로 이 조건을 성립했다는 증거가 필요함
            }
        }
        //여기까지 내려오면 위 사항 모두 해당하지 않으므로
        if (i == m)
            r = mid - 1;
        */
        int mid = (l + r) / 2;
        bool flag = 0;
        if (lamp[0] > mid || n - lamp[m - 1] > mid) //좌우로 어둠이 생기는 경우
            flag = 1;
        for (int i = 0; i < m - 1; i++)
        {
            if (lamp[i + 1] - lamp[i] > mid * 2) //가로등 사이 간격보다 mid*2 가 작으면 가로등 사이에 어두운 부분 생김
                flag = 1;
        }
        //여기까지 내려오면 위 사항 모두 해당하지 않으므로
        if (!flag)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> lamp(m, 0); // m개의 램프 위치 저장
    for (int i = 0; i < m; i++)
    {
        cin >> lamp[i];
    }
    cout << findAns(n, m, lamp);

    return 0;
}

// https://codecollector.tistory.com/1209
//위에 주석단 부분이 계속 오류가 떠서 해당 블로그 참고하였습니다. flag 사용하는 것을 참고했어요.