#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;    

    map<int, int> num_of_num;
    int number = 0;    

    // s <= e �� �� ���� s, e�� �޾Ƽ� s <= x <= e �� ���� x �� ���̺� ���� ���� ���� ����.
    vector<pair<int, int>> btw_se;
    for (const int& s : starts) {
        for (int i = s; i <= e; i++) {
            for (int j = s; j <= e; j++) {
                number = i * j;
                if (number > e) break;
                if (num_of_num.find(number) == num_of_num.end())
                {
                    // ���� ��� �߰�, second�� 1.
                    num_of_num.insert({ number, 1 });
                }
                else
                {
                    // �ִ� ��� second ����
                    num_of_num.find(number)->second++;
                }
            }
        }

        for (int i = s; i <= e; i++) {
            auto iter = num_of_num.find(i);
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