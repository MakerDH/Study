#include <iostream>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

long long solution(int a, int b);

int main()
{
    //case 3 ,5
    cout << solution(3, 5) << endl;

}

long long solution(int a, int b) {
    long long answer = 0;

    int big, small;

    if (a > b) {
        big = a;
        small = b;
    }
    else {
        big = b;
        small = a;
    }

    for (int i = small; i <= big; ++i)
    {
        answer += i;
    }

    return answer;
}

//��ó: ���α׷��ӽ� �ڵ� �׽�Ʈ ����, https ://programmers.co.kr/learn/challenges