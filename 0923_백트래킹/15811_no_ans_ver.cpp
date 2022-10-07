#include <iostream>
#include <vector>
#include <string>
using namespace std;

//재귀에서는 지역변수를 활용한다면 매 함수마다 매개변수로 값을 넘겨주어 불필요한 메모리 낭비가 일어날 수도 있기에 전역변수로 선언해요!

vector<int> store_used_alphabet; //사용된 알파벳을 저장할 벡터
vector<string> words(3);
vector<int> alphabet_to_number(26, -1);
vector<bool> used_number(10, false);

long long wordToNumber(string &word)
{                                           // word를 숫자로 바꾸는 함수
    long long num = 0;                      //받는 수가 18자리까지 가능하므로
    for (int i = 0; i < word.length(); i++) //해당 단어의 길이만큼
    {
        num = num * 10 + alphabet_to_number[word[i] - 'A']; // alphabet_to_number에 들어간 수들은 전부 일의 자리니까 이런식으로 10씩 곱해줘서 하나의 숫자로 만든다.
    }
    return num;
}

void checkUsedAlphabet()
{                                                //알파벳을 숫자로 바꾼 결과를 저장하는 벡터와 사용된 알파벳을 저장하는 벡터 만드는 함수
    vector<bool> check_used_alphabet(26, false); // false값으로 초기화. false 면 아직 사용 안됐다는 의미.

    for (int i = 0; i < 3; i++) //마찬가지로 3개의 단어가 있으므로 3까지 반복
    {
        for (int j = 0; j < words[i].length(); j++) //단어 하나만 보는 for문
        {

            if (!check_used_alphabet[words[i][j] - 'A']) //만약 이 알파벳이 사용된 적이 없다면
            {
                check_used_alphabet[words[i][j] - 'A'] = true;    //이제 사용되었으니 true값으로 만들고
                store_used_alphabet.push_back(words[i][j] - 'A'); //사용된 문자를 저장한다.
                //문자는 아스키코드값으로 인식되는데, 문자의 첫번째 시작인 'A'를 빼줘서 int로 만든다.
            }
        }
    }
}

bool backtracking(int cnt)
{
    // ans가 없도록 수정한 버전입니다.

    if (cnt == store_used_alphabet.size())
    {                                                                                  //한번의 bactracking마다 알파벳 하나에 숫자가 할당되므로 store_used_alphabet 벡터의 사이즈와 bactracking의 level이 같으면 모든 알파벳에 숫자가 할당된 것
        if (wordToNumber(words[0]) + wordToNumber(words[1]) == wordToNumber(words[2])) //만약 조건이 성립하면,
        {
            return true; // true 리턴
        }
        return false; //조건이 성립하지 않았다.
    }

    for (int i = 0; i < 10; i++)
    {                        //알파벳에 차례로 숫자 할당
        if (!used_number[i]) //초기에는 전부 false, 사용된 적 없다는 뜻이다.
        {

            used_number[i] = true; // i는 이미 특정 문자와 매칭됐다는 소리다.
            alphabet_to_number[store_used_alphabet[cnt]] = i;
            //입력받은 단어의 스펠링이 저장되어있는 vector(store_used_alphabet)를 사용해서
            //그 알파벳의 위치(얘를 들어 A는 첫번째이므로 0, Z는 마지막이므로 25)에 순차적으로 0부터 9까지 넣어서 확인하는 방법이다.

            if (backtracking(cnt + 1)) //만약 ans가 true를 리턴받으면 조건 성립하는 숫자가 있다는 소리니까
            {
                return true; // true를 리턴
            }

            used_number[i] = false;                            //새롭게 다시 사용할것이기 때문에 초기화.
            alphabet_to_number[store_used_alphabet[cnt]] = -1; //마찬가지로 다시 사용할 것이기 때문에 초기화.
        }
    }
    return false;
}

/*
 * 1. main에서 단어를 입력받아 checkUsedAlphabet함수로 사용된 알파벳 체크
 * 2. backtrackig함수로 알파벳에 차례로 숫자를 할당하고
 * 3. 모든 알파벳에 숫자가 할당 되었을 때
 * 4. 복면산 조건을 만족하는지 확인 -> 조건을 만족하면 YES 출력하고 종료
 */
int main()
{

    for (int i = 0; i < 3; i++) // 3개의 문자를 받는다고 정해져있으니 3개까지 받는다.
    {
        cin >> words[i]; // 3개의 단어를 넣어준다.
    }
    checkUsedAlphabet(); //입력받은 알파벳을 저장함

    cout << (backtracking(0) ? "YES" : "NO"); //조건 만족하면 yes, 틀리면 no 출력.

    return 0;
}