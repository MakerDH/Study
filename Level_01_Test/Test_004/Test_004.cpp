// Test_004.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves);
void Clear_result(vector<int> &_result);

int main()
{
    vector<vector<int>> _board = { {0, 0, 0, 0, 0},
                                   {0, 0, 1, 0, 3},
                                   {0, 2, 5, 0, 1},
                                   {4, 2, 4, 4, 2},
                                   {3, 5, 1, 3, 1} };
       

    vector<int> _moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

    std::cout << "result : " << solution(_board, _moves);
}

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer;
    vector<int> result;

    //해당 위치에 숫자를 뽑아서 벡터에 저장
    //m == moves , h == board horizontal , v == board vertical
    for (int m = 0; m < moves.size(); ++m) 
    {
        for (int h = 0; h < board.size(); ++h)
        {
            if (board[h][moves[m] - 1] != 0)
            {
                result.push_back(board[h][moves[m] - 1]);
                board[h][moves[m] - 1] = 0;
                break;
            }
        }
    }
    
    //같은 숫자 제거 전 갯수
    answer = result.size();

    //제거 제귀함수
    Clear_result(result);       
    
    //제거전 - 제거후 == 제거된 수
    return answer - result.size();
}

void Clear_result(vector<int> &_result) 
{
    //같은 숫자가 연달아 나오는 것을 제거
    //제거 후에도 연달아 나오는 경우를 제귀 함수로 제거함
    for (int i = 0; i < _result.size(); ++i) 
    {
        if (_result[i] == _result[i + 1] && i + 1 < _result.size())
        {
            //뒤에 부터 참조해야 벡터가 당겨지는 경우를 방지할 수 있다.
            /*
            ex Correct
            original index [1, 2, 3, 4] => [ 1, 2, 4 ] => [ 1, 4 ]
                     index [1, 2, 3, 4] => [ 1, 2, 3 ] => [ 1, 2 ]
                     value {4, 2, 2, 5} => { 4, 2, 5 } => { 4, 5 }
            */
            /*
            ex Wrong
            original index [1, 2, 3, 4] => [ 1, 3, 4 ] => [ 1, 3 ]
                     index [1, 2, 3, 4] => [ 1, 2, 3 ] => [ 1, 2 ]
                     value {4, 2, 2, 5} => { 4, 2, 5 } => { 4, 2 }
            */
            _result.erase(_result.begin() + i + 1);
            _result.erase(_result.begin() + i );

            Clear_result(_result);
            break;
        }
    }
    return ;


    //for (vector<int>::iterator itr = _result.begin(); itr != _result.end(); ++itr)
    //{
    //    //if (itr == _result[i + 1])

    //    cout << *itr << ", " << *(itr+1) << endl;
    //}
}
