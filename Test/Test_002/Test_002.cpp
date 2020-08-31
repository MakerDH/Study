

#include <iostream>

#include <vector>

using namespace std;

vector<int> solution(vector<int> answers);

int main()
{
    //vector<int> answers{ 1,3,2,4,2 };
    //vector<int> answers{ 1,2,3,4,5 };
    vector<int> answers{ 2,3,9,9,9,2,3,9,9,9 };

    vector<int> debug = solution(answers);

    for (int i = 0; debug.size(); ++i) {
        cout << debug[0]<<endl;
    }

    return 0;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> a{ 1,2,3,4,5 };
    int count_a = 0;

    vector<int> b{ 2,1,2,3,2,4,2,5 };
    int count_b = 0;

    vector<int> c{ 3,3,1,1,2,2,4,4,5,5 };
    int count_c = 0;

    //각각의 점수를 계산합니다.
    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == a[i % a.size()])
        {
            ++count_a;
        }

        if (answers[i] == b[i % b.size()])
        {
            ++count_b;
        }

        if (answers[i] == c[i % c.size()])
        {
            ++count_c;
        }
    }

    //각 수험생 번호 순서에 따라 점수를 저장합니다
    vector<int> original{ count_a,count_b,count_c };

    //점수를 내림차순으로 저장합니다.
    vector<int> temp{ count_a,count_b,count_c };

    for (int i = 0; i < temp.size(); ++i) {
        for (int j = 0; j < temp.size() - 1; ++j) {
            if (temp[j] < temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    //점수에 따라 수험생 번호를 정렬 합니다.
    for (int i = 0; i < temp.size(); ++i) {
        for (int j = 0; j < original.size(); ++j) {
            if (temp[i] == original[j] && original[j] != 0)
                answer.push_back(j + 1);
        }
    }

    //단일 최고 점수만 남기거나, 2, 3명의 공동 최고 점수를 저장합니다.
    if (temp[0] == temp[1]) {
        if (temp[1] == temp[2]) {
            answer.erase(answer.begin() + 3, answer.end());
        }
        else {
            answer.erase(answer.begin() + 2, answer.end());
        }
    }
    else {
        answer.erase(answer.begin() + 1, answer.end());
    }

    return answer;
}

//출처: 프로그래머스 코딩 테스트 연습, https ://programmers.co.kr/learn/challenges