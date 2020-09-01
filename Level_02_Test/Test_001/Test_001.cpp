// Test_001.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Compare_SkillTree(string _skill, string _skilltree);
int solution(string skill, vector<string> skill_trees);

int main()
{
    string skill = "CBD";
    vector<string> skilltrees{ "BACDE", "CBADF", "AECB", "BDA" ,"A","B" ,"C" };

    cout << solution(skill, skilltrees);

    //cout << Compare_SkillTree("CBD", "BACDE") << endl;
    //cout << Compare_SkillTree("CBD", "BDA") << endl;   
    //cout << Compare_SkillTree("CBD", "AECB");
    //cout << Compare_SkillTree("CBD", "B");
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    //선행 스킬의 크기가 1일때 전부 가능
    if (1 == skill.size()) {
        return skill_trees.size();
    }

    //스킬 트리 허용 가능 갯수 측정
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        if (Compare_SkillTree(skill, skill_trees[i]))
            ++answer;
    }


    return answer;
}

bool Compare_SkillTree(string _skill, string _skilltree) 
{
    //선행 스킬 크기와 같은 vector s를 -1 초기화
    vector<int> s ( _skill.size(), -1 );


    //스킬 트리에서 선행 스킬이 사용된 차례를 vector s에 저장
    for (int i = 0; i < _skill.size(); ++i) 
    {
        for (int j = 0; j < _skilltree.size(); ++j)
        {
            if (_skill[i] == _skilltree[j]) 
            {
                s[i] = j;
            }
        }        
    }   

    //cout << "[";
    //for (int i = 0; i < s.size(); ++i)
    //{
    //    cout << s[i]<<",";
    //}
    //cout << "]";


    //제한 조건에 따라 선행 스킬이 사용된 차례가 오름차순이 아니거나 앞선 선행 스킬사용되지 않았을 경우를 판정
    //앞서 선행 스킬의 크기가 1일때는 예외 처리 했기 때문에 1부터 시작
    for (int i = 1; i < s.size(); ++i)
    {
        if(-1 != s[i])
            if (-1 == s[i - 1] || s[i - 1] > s[i])
            {
                return false;
            }        
    }

    return true;
}




//출처: 프로그래머스 코딩 테스트 연습, https ://programmers.co.kr/learn/challenges