#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <queue>
#include <iterator>

using namespace std;


int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    vector<vector<int>> input;
    string line;
    getline(cin, line);
    for (int i = 0; i < N; ++i) {
        getline(cin, line);
        istringstream iss(line);
        vector<string> temp{istream_iterator<string>{iss}, istream_iterator<string>{}};
        vector<int> vec;
        for (auto s : temp) {
            vec.push_back(stoi(s));
        }
        input.push_back(vec);
    }
    
    unordered_map<int, int> init, indegrees;
    unordered_map<int, unordered_set<int>> graph, cache;
    for (int i = 0; i < N; ++i) {
        init[i] = input[i][0];
        for (int j = 1; j < input[i].size(); ++j) {
            graph[input[i][j]].insert(i);
            cache[i].insert(input[i][j]);
            ++indegrees[i];
        }
    }

    queue<int> zero_degrees;
    for (int i = 0; i < N; ++i) {
        if (input[i].size() == 1) zero_degrees.push(i);
    }

    while (!zero_degrees.empty()) {
        auto curr = zero_degrees.front();
        zero_degrees.pop();
        for (auto neighbor : graph[curr]) {
            for (auto pos : cache[curr]) {
                cache[neighbor].insert(pos);
            }
            --indegrees[neighbor];
            if (indegrees[neighbor] == 0) {
                zero_degrees.push(neighbor);
            }
        }
    }
    
    vector<int> result(N);
    for (int i = 0; i < N; ++i) {
        int sum = init[i];
        for (auto pos : cache[i]) {
            sum += init[pos];
        }
        result[i] = sum;
    }

    cout << *max_element(result.begin(), result.end());
    return 0;
    
}
