// Test_001.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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

    //���� ��ų�� ũ�Ⱑ 1�϶� ���� ����
    if (1 == skill.size()) {
        return skill_trees.size();
    }

    //��ų Ʈ�� ��� ���� ���� ����
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        if (Compare_SkillTree(skill, skill_trees[i]))
            ++answer;
    }


    return answer;
}

bool Compare_SkillTree(string _skill, string _skilltree) 
{
    //���� ��ų ũ��� ���� vector s�� -1 �ʱ�ȭ
    vector<int> s ( _skill.size(), -1 );


    //��ų Ʈ������ ���� ��ų�� ���� ���ʸ� vector s�� ����
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


    //���� ���ǿ� ���� ���� ��ų�� ���� ���ʰ� ���������� �ƴϰų� �ռ� ���� ��ų������ �ʾ��� ��츦 ����
    //�ռ� ���� ��ų�� ũ�Ⱑ 1�϶��� ���� ó�� �߱� ������ 1���� ����
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




//��ó: ���α׷��ӽ� �ڵ� �׽�Ʈ ����, https ://programmers.co.kr/learn/challenges