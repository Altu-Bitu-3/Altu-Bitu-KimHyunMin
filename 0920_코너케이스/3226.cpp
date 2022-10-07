#include <iostream>
#include <string>

using namespace std;

int cost()
{
    int cost, hh, mm, dd, end_h, end_m;

    scanf("%2d:%2d %d", &hh, &mm, &dd); //이부분 고민을 했는데 형식이 정해져 있어서 이 방법이 제일 간편해 보였습니다

    end_h = hh + (mm + dd) / 60;
    end_m = (mm + dd) % 60;

    if (hh == 6 && end_h == 7) //중간에 낀 경우
    {
        return (end_m)*10 + (dd - end_m) * 5;
    }
    else if (hh == 18 && end_h == 19)
    {
        return (end_m)*5 + (dd - end_m) * 10;
    }
    if (hh >= 7 && hh <= 18)
    {
        return dd * 10;
    }

    return dd * 5;

    return cost;
}

int main()
{
    int n, total_cost = 0;
    cin >> n;
    while (n--)
    {
        total_cost += cost();
    }

    cout << total_cost;
    return 0;
}