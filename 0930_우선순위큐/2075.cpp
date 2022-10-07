#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있기 때문에, 입력값을 모두 저장해서 N번째 큰수를 계산하면 메모리 초과가 발생한다.
 * 최소 힙을 만들어서 상위 n개만 저장하여 heap[0]을 현재까지의 N번째 큰수로 유지하자!
 */
//멋진 아이디어... 처음에는 입력받는 구조를 활용해야한다고 생각했는데 단순하게 우선순위큐를 사용하면 되는 문제.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); //입출력을 빠르게 해준다

    int n, input;                                   // n은 입력받는 값의 가로 세로, input은 입력받을 값들
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙, 비교함수 처리가 정렬이랑 반대 5번째로 큰 수를 뽑아야 하므로..

    cin >> n;         //입력 받기
    int size = n * n; // n*n꼴의 배열 모양
    while (size--)    // size는 다시 쓸 일 없으므로 --로 처리해준다.
    {

        //입력
        cin >> input;

        //연산
        pq.push(input); //우선순위큐에 입력받은 값을 넣어준다
        if (pq.size() > n)
        {             //최소 힙의 크기가 n 을 넘어가면 가장 작은 값 삭제
            pq.pop(); // 가장 작은 값 삭제된다
        }
    }

    //출력
    cout << pq.top(); //이렇게 되면 맨 위에 n개중 가장 작은 값이 나온다
    return 0;
}