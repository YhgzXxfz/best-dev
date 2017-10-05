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

int dfs(int curr, vector<int>& visited, unordered_map<int, int>& init, unordered_map<int, unordered_set<int>>& graph) {
    if (visited[curr]) return 0;
    visited[curr] = true;
    
    int sum = init[curr];
    for (auto neighbor : graph[curr]) {
        sum += dfs(neighbor, visited, init, graph);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    vector<vector<int>> input;
    string line;
    cin.ignore();
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
    
    unordered_map<int, int> init;
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < N; ++i) {
        init[i] = input[i][0];
        for (int j = 1; j < input[i].size(); ++j) {
            graph[i].insert(input[i][j]);
        
        }
    }
    
    vector<int> result(N);
    for (int i = 0; i < N; ++i) {
        vector<int> visited(N,0);
        int curr = dfs(i, visited, init, graph);
        result[i] = curr;
    }

    cout << *max_element(result.begin(), result.end());
    return 0;
    
}
