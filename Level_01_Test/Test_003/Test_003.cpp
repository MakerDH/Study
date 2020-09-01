// Test_003.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve);

int main()
{
    //std::cout << solution(5, vector<int> {2, 4}, vector<int> {1, 3, 5});
    //std::cout << solution(5, vector<int> {2, 4}, vector<int> {3});
    //std::cout << solution(3, vector<int> {3}, vector<int> {1});
    std::cout << solution(10, vector<int> {3,4,5,7,8}, vector<int> {3,4,5,7});
    

    return 0;
}


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    for (int i = 0; i < lost.size(); ++i)
    {
        for (int j = 0; j < reserve.size() ; ++j)
        {
            if (reserve[j] == lost[i])
            {
                lost.erase(lost.begin()+i);
                reserve.erase(reserve.begin()+j);
                --i;
                --j;
                break;
            }
        }
    }

    for (int i = 0; i < lost.size(); ++i)
    {
        for (int j = 0; j < reserve.size(); ++j)
        {
            if (reserve[j] + 1 == lost[i] || reserve[j] - 1 == lost[i])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                --i;
                --j;
                break;
            }
        }
    }

    answer = n - lost.size();

    return answer;
}


//출처: 프로그래머스 코딩 테스트 연습, https ://programmers.co.kr/learn/challenges