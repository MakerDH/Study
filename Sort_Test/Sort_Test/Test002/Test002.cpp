// Test002.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    vector<pair<float, int>> temp(numbers.size());// (numbers.begin(), numbers.end());

    vector<vector<pair<float, int>>> aaa(10);      cout << aaa.size();    cout << endl; cout << endl;

    for (int i = 0; i < temp.size(); ++i)
    {
        temp[i].first = temp[i].second = numbers[i];
       cout << numbers.size() << i << ":" << temp[i].first << "," << temp[i].second << endl;

        if (0 == temp[i].second || 
            10 == temp[i].second || 
            100 == temp[i].second || 
            1000 == temp[i].second)
        {
//            temp[i].first = 0 == temp[i].second ? 0 : 1001-temp[i].second;
            //temp[i].first = temp[i].second == 100 ? 1001 : temp[i].second;
            temp[i].first = 1000 == temp[i].second ? 1
                            : 100 == temp[i].second ? 2
                            : 10 == temp[i].second ? 3 : 0;
            
            aaa[0].push_back(temp[i]);
            continue;
        }
        else 


        if (temp[i].second < 10)
        {
            temp[i].first = (float) temp[i].second * 1111;
        }
        else if (temp[i].second < 100)
        {
            //temp[i].first = temp[i].second * 100 + ((int)temp[i].second / 10)*11;
            temp[i].first = temp[i].second * 100 + temp[i].second;
        }
        else if (temp[i].second < 1000)
        {
            temp[i].first = temp[i].second * 10 + ((int)temp[i].second / 100) ;
        }
            
        aaa[(int)temp[i].first / 1000].push_back(temp[i]);

       

    }cout << aaa.size();
    cout << "--------------------------------------------------------------------" << endl;
    for (int i = 0; i < aaa.size(); ++i)
    {
        sort(aaa[i].begin(), aaa[i].end());

        for (int j = 0; j < aaa[i].size(); ++j)
        {

            answer = to_string(aaa[i][j].second) + answer;
            
            cout << i << "><" << j << ":" << aaa[i][j].first << ", " << aaa[i][j].second << endl;
            //cout << aaa[i][j].first << ", ";
        }
        cout << endl;
    }

    /* sort(temp.begin(), temp.end());

     cout << endl;
     for (int i = 0; i < temp.size(); ++i)
     {
         cout << temp[i].first << ", " << temp[i].second << endl;
     }*/
    if (answer[0] == '0')answer = "0";
    cout << answer;
    return answer;
}


int main()
{
    vector<int> case1 = 
    {
        1000, 1, 12, 133,10,0,100,
        //2, 21, 210,
        //3,326,33,330, 332, 331, 334, 335, 333, 337, 339, 338, 336,
        //4, 40, 443,
       // 55, 554, 50,
       // 667, 6, 66,
        //79, 7,
       //8,88,889,
        //9,97, 979, 980, 982, 981, 984, 98,985, 983, 987, 989, 988, 986, 99
    };

    vector<int> case2 = { 3, 30, 34, 5, 9 };
    vector<int> case3 = { 5};

    vector<int> case4 = { 40, 403 };
    vector<int> case5 = { 1, 11, 111, 1111 };
    vector<int> case6 = { 0, 0, 0, 0, 0, 0 };

    vector<int> case7 = { 2, 20, 200 };
    vector<int> case8 = {0, 0, 70};
      vector<int> case9 = {0, 0, 0, 1000};
      vector<int> case10 = {0, 0, 1000, 0};
     vector<int> case11 = { 1000, 0, 0}; 
     vector<int> case12 = { 12, 121};
     vector<int> case13 = { 21, 212};
     vector<int> case14 = { 11, 12, 10};
     vector<int> case15 = { 0, 0, 0, 1};
     vector<int> case16 = { 1, 2, 3, 1, 1, 3};
     vector<int> case17 = {1, 2, 21, 21}; 

    std::cout << "Hello World!\n";

    solution(case7);
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
//string solution(vector<int> numbers) {
//    string answer = "";
//
//    vector<pair<float, int>> temp(numbers.size());// (numbers.begin(), numbers.end());
//
//    vector<vector<pair<float, int>>> aaa(10);      cout << aaa.size();    cout << endl; cout << endl;
//
//    for (int i = 0; i < temp.size(); ++i)
//    {   
//        temp[i].first = temp[i].second = numbers[i];
//
//        //1~9 > //10~99 > //100~999
//        while(temp[i].first >= 10)
//        {
//            temp[i].first = temp[i].first / 10;
//        }
//       // cout << i << ":" << temp[i].first<<endl;
//        for (int j = 0; j < aaa.size(); ++j)
//        {
//            if (j == 0 && (0 == temp[i].first || 1000 == temp[i].second))
//            {
//                aaa[j].push_back(temp[i]);
//                
//            }
//            else if (j <= temp[i].first && temp[i].first < j + 1)
//            {                
//                cout <<j << ":" << temp[i].first << ", " << temp[i].second << endl;
//
//                if (temp[i].second < 10)
//                {
//                    temp[i].first = temp[i].second * 111;
//                }
//                else if(temp[i].second < 100)
//                {
//                    temp[i].first = temp[i].second * 10 +j;
//                }
//                else if(temp[i].second < 1000)
//                {
//                    temp[i].first = temp[i].second;
//                }
//
//                //if (100 <= temp[i].first)
//                //{
//                //    temp[i].first = ((int)temp[i].first % 100) / 10;
//                //}
//                //else if (10 <= temp[i].first )
//                //{
//                //    temp[i].first = (int)temp[i].first % 10;
//                //}
//
//                
//                aaa[j].push_back(temp[i]); 
//                break;
//            }
//        }
//
//    }cout << aaa.size();
//    cout <<"--------------------------------------------------------------------"<< endl;
//    for (int i = 0; i < aaa.size(); ++i)
//    {
//        sort(aaa[i].begin(), aaa[i].end());
//
//        for (int j = 0; j < aaa[i].size(); ++j)
//        {
//
//            answer = to_string(aaa[i][j].second) + answer;
//            cout<<i<<"><"<<j<<":" << aaa[i][j].first << ", " << aaa[i][j].second << endl;
//            //cout << aaa[i][j].first << ", ";
//        }
//        cout << endl;
//    }
//
//   /* sort(temp.begin(), temp.end());
//
//    cout << endl;
//    for (int i = 0; i < temp.size(); ++i)
//    {
//        cout << temp[i].first << ", " << temp[i].second << endl;
//    }*/
//
//    cout << answer;
//    return answer;
//}
