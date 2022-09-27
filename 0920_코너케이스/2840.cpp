#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, char> ci;

/*
    - 배열을 ?로 초기화 해주고, 입력대로 처리한다
    - 문제의 경우, 화살표를 고정시키고 바퀴를 돌리는데,
    - 풀 때에는 바퀴를 고정시키고, 화살표를 이동시키는 방식으로 풀었다. (출력시 방향을 바꿔야함)
    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
*/

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int index, int n, vector<char> &wheel) // index에는 현재 화살표의 위치가 있다.
{
    string ans = ""; //공백으로 초기화한 string. 이곳에 결과값이 저장된다.

    for (int i = n; i > 0; i--)
    {
        ans += wheel[(i + index) % n];
        //바퀴는 n개 이므로 n개 만큼 출력. 이때 바퀴형식이므로 index때문에 한바퀴 돌아가는 경우가 잇기 때문에 %n 해줬다.
    }

    return ans;
}

string makeWheel(int n, vector<ci> &record) //바퀴를 만드는 함수
{
    vector<char> wheel(n, '?');           //?로 초기화, 끝까지 어떤 글자인지 모르면 ? 출력
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int index = 0; //화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++)
    {
        int rot = record[i].first; //화살표가 얼마나 이동했는지
        int ch = record[i].second; //이동한 후에 가리키는 문자는 무엇인지

        index = (index + rot) % n; //화살표 이동. n마다 반복되므로 % n 해줌

        if (wheel[index] == ch) //만약 입력된 정보가 일치하면, 즉 !가 아닌경우.
        {
            continue; //문제가 없으므로 계속한다
        }

        // 주의사항 체크
        // 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
        if (wheel[index] != '?' || is_available[ch - 'A'])
        // 1. 이미 위에서 wheel[index] != ch 인게 확정되었는데 ?가 들어있지도 않으므로 !
        // 2. 그 다음으로 이미 사용됐는데 또 다른 공간에 사용되어버리므로 !
        {
            return "!";
        }

        wheel[index] = ch;             //위에서 !가 되는 경우를 전부 걸러줬으므로 ch 대입.
        is_available[ch - 'A'] = true; // 2번 조건을 체크하기 위함
    }

    return arrowStartWheel(index, n, wheel); //!가 아닌 바퀴인 것이 확정. 만들어진 바퀴를 출력하는 함수를 호출
}

int main()
{
    //입력
    int n, k;      // n : 바퀴 칸의 수, k : 바퀴 돌리는 횟수
    cin >> n >> k; //첫째줄에 입력 받음

    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++)   //바퀴를 k번 돌린다
    {
        cin >> record[i].first >> record[i].second;
        //바퀴가 돌아가는 만큼 입력받음.
        //첫번째 입력, record[i].first 에는 글짜가 몇 번 바뀌었는지가 들어가고
        //두번째 입력, record[i].second에는 회전을 멈추었을 때 가리키던 글자가 들어간다.
    }

    //출력
    cout << makeWheel(n, record);
}