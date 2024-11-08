#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;    

    map<int, int> num_of_num; // ������ ����. key�� �����̰� value�� �����̴�.
    int number = 0;    

    // s <= e �� �� ���� s, e�� �޾Ƽ� s <= x <= e �� ���� x �� ���̺� ���� ���� ���� ����.
    vector<pair<int, int>> btw_se; // s�� e ���̿� �ִ� (between s, e) ���� x�� �� ���ڰ� ���� Ƚ���� pair ����.
    for (const int& s : starts) {
       
        for (int i = 1; i <= e; i++) {
            for (int j = 1; j <= e; j++) {
                number = i * j;
                if (number > e ) break;
                if (number < s) continue;

                auto iter = num_of_num.find(number);
                if (iter == num_of_num.end())
                {
                    // ���� ��� �߰�, second�� 1.                    
                    num_of_num.insert({ number, 1 });
                }
                else
                {
                    // �ִ� ��� second ����                    
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