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

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    string A, B;
    unordered_map<string, unordered_set<string>> graph;
    unordered_set<string> all;
    for (int i = 0; i < N; ++i) {
        cin >> A >> B;
        graph[A].insert(B);
        all.insert(A); all.insert(B);
    }
    
    unordered_map<string, int> indegrees;
    for (auto entry : graph) {
        for (auto neighbor : entry.second) {
            ++indegrees[neighbor];
        }
    }
    
    queue<string> zero_degrees;
    for (auto door : all) {
        if (indegrees.find(door) == indegrees.end()) zero_degrees.push(door);
    }
    
    int max_depth = 1;
    while (!indegrees.empty()) {
        int len = zero_degrees.size();
        for (int i = 0; i < len; ++i) {
            string curr = zero_degrees.front();
            zero_degrees.pop();
            
            for (auto neighbor : graph[curr]) {
                --indegrees[neighbor];
                if (indegrees[neighbor] == 0) {
                    indegrees.erase(neighbor);
                    zero_degrees.push(neighbor);
                }
            }
        }
        max_depth++;
    }
    
    cout << max_depth << endl;
    
    return 0;
}
