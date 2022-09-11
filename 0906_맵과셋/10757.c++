#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 1e4 + 1;

void calculate(string a, string b)
{
    int carry = 0, i = 0;
    int num[SIZE];
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end()); //일의 자리수부터 계산할거라 역순해줌.

    for (; i < b.length(); i++)
    {
        num[i] = ((a[i] - '0') + (b[i] - '0') + carry) % 10;
        carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
    }

    for (; i < a.length(); i++) // i는 b.length() 부터 시작함
    {
        num[i] = ((a[i] - '0') + carry) % 10;
        carry = ((a[i] - '0') + carry) / 10;
    }

    if (carry) //만약 마지막 carry가 1이라면
    {
        num[i++] = 1; //이제 i에는 결과값의 자릿수가 들어가 있다.
    }

    while (i--)
    { //거꾸로 출력
        cout << num[i];
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    if (a.length() < b.length())
    {
        a.swap(b); //이제 a에 무조건 더 큰 수가 들어간다
    }
    calculate(a, b);

    return 0;
}