#include <iostream>
#include <list>
#include <string>

using namespace std;

//삽입과 삭제를 자유자제로 하려면 리스트가 유용하다고 판단

list<char> pwd;
list<char>::iterator it;

void findPassword()
{
    string input;
    pwd.clear();
    it = pwd.begin();

    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '<' && it != pwd.begin())
        {
            it--;
        }
        else if (input[i] == '>' && it != pwd.end())
        {
            it++;
        }
        else if (input[i] == '-' && it != pwd.begin())
        {
            it = pwd.erase(--it);
        }
        else if (input[i] != '<' && input[i] != '>' && input[i] != '-') //그냥 else로 해버리면 위에서 &&으로 조건을 줘버려서 계속 틀린 답이 나온다. <어ㅣ >가 그대로 입력됨
        {
            pwd.insert(it, input[i]);
        }
    }
}

int main()
{
    int L;
    cin >> L;

    while (L--)
    { // L을 다시 사용할 일 없다
        findPassword();
        for (it = pwd.begin(); it != pwd.end(); it++)
        {
            cout << *it;
        }
        cout << "\n";
    }

    return 0;
}