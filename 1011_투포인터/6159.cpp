#include <iostream>
#include <vector>

using namespace std;

int findMate(int size, vector<int> &cow)
{
    int count = 0;
    for (int i = 0; i < cow.size(); i++)
    {
        for (int j = i + 1; j < cow.size(); j++)
        {
            if (cow[i] + cow[j] <= size)
                count++;
        }
    }
    return count;
}

int main()
{
    int n, s;
    cin >> n >> s;

    vector<int> cow(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> cow[i];
    }

    cout << findMate(s, cow);

    return 0;
}