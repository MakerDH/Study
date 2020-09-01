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
    vector<string> skilltrees{ "BACDE", "CBADF", "AECB", "BDA" };

    cout << solution(skill, skilltrees);

    //cout << "Hello World! " << Compare_SkillTree("CBD", "BACDE") << endl;
    //cout << "Hello World! " << Compare_SkillTree("CBD", "CD") << endl;

}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    //선행 스킬의 크기가 1일때 전부 가능
    if (1 == skill.size()) {
        return skill_trees.size();
    }

    //스킬 트리의 크기가 1일때 가능
    for (int i = skill_trees.size()-1; i > 0; --i) {
        if (1 == skill_trees[i].size()) {
            skill_trees.erase(skill_trees.begin() + i);
            ++answer;
        }
    }


    for (int i = 0; i < skill_trees.size(); ++i) 
    {        
        if (Compare_SkillTree(skill, skill_trees[i]))
            ++answer;
    }


    return answer;
}

bool Compare_SkillTree(string _skill, string _skilltree) {

    for (int i = 0; i < _skilltree.size(); ++i)
    {
        for (int j = 1; j < _skill.size(); ++j)
        {
            if (_skilltree[i] == _skill[j])
            {
                for (int t = i + 1; t < _skilltree.size(); ++t)
                {
                    for (int s = j - 1; s >= 0; --s)
                    {
                        if (_skill[s] == _skilltree[t])
                        {
                            return false;
                        }
                    }
                }
            }
        }

    }
    return true;
}



//지문을 잘못 이해해
//"BDA" 같이 순서만 지킨다면 가능 한 코드가 되었습니다.