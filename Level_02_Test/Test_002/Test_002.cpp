// Test_002.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    vector<string> splits;

    int copyStartIndex = 2;

    //대괄호 제거
    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] == '}' && s[i + 1] == ',' && s[i + 2] == '{')
        {
            //string str_temp = s.substr(copyStartIndex, i - copyStartIndex);
            splits.push_back(s.substr(copyStartIndex, i - copyStartIndex) + ",");
            copyStartIndex = i + 3;
        }

        if (s[i] == '}' && s[i + 1] == '}')
        {
            splits.push_back(s.substr( copyStartIndex , i - copyStartIndex ) + ",");
        }
    }

    vector<vector<int>> _answer(splits.size());
    //대괄호 분류를 따르면서 콤마 제거 및 char->int 형변환 
    int int_temp = -1;    
    for (int i = 0; i < splits.size(); ++i)
    {
        copyStartIndex = 0;
        for (int j = 0; j < splits[i].size(); ++j)
        {
            if (splits[i][j] == ',')
            {
                int_temp = stoi(splits[i].substr(copyStartIndex, j - copyStartIndex));
                _answer[i].push_back(int_temp);

                copyStartIndex = j + 1;
                int_temp = -1;
            }
        }
    }

    //가장 적은 원소의 집합 부터 원소가 중복되지 않게 차례대로 재구성 하면 정답이 됨
    //항상 원소를 1개 가지는 집합을 차례로 넣게 하기 위해 이전에 넣었던 원소를 다른 집합에서도 지우는 과정을 추가
    /*
    * 아래와 같은 과정을 거침
    튜플 표현 집합{{2},{2,1},{2,1,3},{2,1,3,4}}, 튜플 집합 {}
    튜플 표현 집합{{},{1},{1,3},{1,3,4}},        튜플 집합 {2}
    튜플 표현 집합{{},{},{3},{3,4}},             튜플 집합 {2,1}
    튜플 표현 집합{{},{},{},{4}},                튜플 집합 {2,1,3}
    튜플 표현 집합{{},{},{},{}},                 튜플 집합 {2,1,3,4}
    */
    vector<int> answer;
    int_temp = 1;
    for (int i = 0; answer.size() < _answer.size(); ++i)
    {               
        if (1 == _answer[i].size())
        {              
            int_temp = _answer[i][0];
            answer.push_back(_answer[i][0]);                       

            for (int x = 0; x < _answer.size(); ++x) {
                for (int y = 0; y < _answer[x].size(); ++y) {
                    if (_answer[x][y] == int_temp) {
                        _answer[x].erase(_answer[x].begin() + y);
                        i = -1;
                    }
                }
            }
        }
    }
    
    return answer;
}


int main()
{   
    string a = "{{2},{2,1},{2,1,3},{2,1,3,4}}"; //result : [2, 1, 3, 4]
    string b = "{{1,2,3},{2,1},{1,2,4,3},{2}}"; //result : [2, 1, 3, 4]
    string c = "{{20,111},{111}}";              //result : [111, 20]
    string d = "{{123}}";                       //result : [123]
    string e = "{{4,2,3},{3},{2,3,4,1},{2,3}}"; //result : [3, 2, 4, 1]

    vector<int> _solution = solution(e);

    for (int i = 0; i < _solution.size(); ++i)
    {
        cout << _solution[i] << endl;
    }
    

    std::cout << "Hello World!\n";
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

/*vector<int> solution(string s)
{
    vector<string> splits;

    int copyStartIndex = 2;

    //대괄호 제거
    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] == '}' && s[i + 1] == ',' && s[i + 2] == '{')
        {
            string str_temp = s.substr(copyStartIndex, i - copyStartIndex);
            splits.push_back(s.substr(copyStartIndex, i - copyStartIndex));
            copyStartIndex = i + 3;
        }

        if (s[i] == '}' && s[i + 1] == '}')
        {
            splits.push_back(s.substr( copyStartIndex , i - copyStartIndex ));
        }
    }

    for (int i = 0; i < splits.size(); ++i)
    {
        if (1 == splits[i].size()) 
        {
            cout << splits[i] << endl;
        }
    }

    vector<vector<int>> _answer(splits.size());

    int int_temp = -1;

    for (int i = 0; i < splits.size(); ++i)
    {
        for (int j = 0; j < splits[i].size(); ++j)
        {
            if (splits[i][j] == ',')
            {
                int_temp = stoi(splits[i].substr(copyStartIndex, i - copyStartIndex));
                _answer[i].push_back(int_temp);

                copyStartIndex = i + 1;
                int_temp = -1;
            }
        }
    }

    vector<int> answer;

    return answer;
}*/




//출처: 프로그래머스 코딩 테스트 연습, https ://programmers.co.kr/learn/challenges