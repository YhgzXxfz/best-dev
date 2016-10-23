

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

using namespace std;

void dfs(unordered_map<string, vector<string>>& doors, string curr, int depth, int& max_depth);

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    string A, B;
    unordered_map<string, vector<string>> doors;
    vector<pair<string, string>> entries;
    for (int i = 0; i < N; ++i) {
        cin >> A >> B;
        doors[A].push_back(B);
        entries.push_back(make_pair(A, B));
    }
    
    int max_depth = 0;
    for (auto& curr : entries) {
        dfs(doors, curr.first, 1, max_depth);
    }
    
    cout << max_depth << endl;
    
    
    return 0;
}

void dfs(unordered_map<string, vector<string>>& doors, string curr, int depth, int& max_depth) {
    if (depth > max_depth) max_depth = depth;
    if (doors.find(curr) == doors.end()) return ;
    
    auto list = doors[curr];
    for (auto& candidate : list) {
        dfs(doors, candidate, depth+1, max_depth);
    }
}

