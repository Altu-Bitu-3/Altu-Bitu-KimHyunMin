#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct employee
{
    int doc, oral;
};

bool cmp(const employee &a, const employee &b)
{
    return a.doc < b.doc; //오름차순 정렬
}

int select(vector<employee> &arr, int n)
{
    int pass = 1, margin = arr[0].oral; //서류 평가 1등의 oral을 margin에 저장
    for (int i = 1; i < n; i++)
    {
        if (arr[i].oral < margin)
        { // margin보다 oral순위가 높으면
            pass++;
            margin = arr[i].oral; //얘가 1등이라 생각하고 margin 초기화
        }
    }
    return pass;
}

int main()
{
    int t, n;
    cin >> t;
    vector<employee> arr(0);

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arr.resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j].doc >> arr[j].oral;
        }

        sort(arr.begin(), arr.end(), cmp);
        cout << select(arr, n) << "\n";
    }

    return 0;
}