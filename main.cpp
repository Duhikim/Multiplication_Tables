#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;    

    map<int, int> num_of_num; // 숫자의 개수. key는 숫자이고 value는 개수이다.
    int number = 0;    

    // s <= e 인 두 정수 s, e를 받아서 s <= x <= e 인 정수 x 중 테이블에 가장 많이 나온 숫자.
    vector<pair<int, int>> btw_se; // s와 e 사이에 있는 (between s, e) 숫자 x와 그 숫자가 나온 횟수의 pair 선언.
    for (const int& s : starts) {
       
        for (int i = 1; i <= e; i++) {
            for (int j = 1; j <= e; j++) {
                number = i * j;
                if (number > e ) break;
                if (number < s) continue;

                auto iter = num_of_num.find(number);
                if (iter == num_of_num.end())
                {
                    // 없는 경우 추가, second는 1.                    
                    num_of_num.insert({ number, 1 });
                }
                else
                {
                    // 있는 경우 second 증가                    
                    iter->second++;                    
                }
            }
        }        

        for (auto iter = num_of_num.begin(); iter != num_of_num.end(); iter++)
        {
            btw_se.push_back({ iter->first, iter->second });
        }
        
        int max_key, max_val = -1;
        for (const pair<int, int> xpair : btw_se) {
            if (xpair.second > max_val) {
                max_key = xpair.first;
                max_val = xpair.second;
            }
            else if (xpair.second == max_val) {
                max_key = (xpair.first < max_key) ? xpair.first : max_key;
            }
        }        
        answer.push_back(max_key);
        btw_se.clear();
        num_of_num.clear();
    }  

    return answer;
}

int main() {
    int e;
    vector<int> starts;
    vector<int> expected;
    vector<int> results;

    e = 8;
    starts = { 1, 3, 7 };
    expected = { 6, 6, 8 };
    results = solution(e, starts);
    if (expected == results) cout << "Correct!" << '\n';
    else cout << "Wrong.." << '\n';

    return 0;
}