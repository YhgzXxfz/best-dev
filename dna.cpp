/*******
 * Read input from cin
 * Use cout to output your result.
 * Use:
 *  localPrint( string mystring)
 * to display variable in a dedicated area.
 * ***/
#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"
#include <vector>
#include <unordered_map>

using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void dfs(vector<int>& solution, vector<vector<int>>& result, int start) {
    if (start >= solution.size()) {
        result.push_back(solution);
        return ;
    }
    
    for (int i = start; i < solution.size(); ++i) {
        swap(solution[start], solution[i]);
        dfs(solution, result, start+1);
        swap(solution[start], solution[i]);
    }
}

void construct(string& first, string& second, vector<int> index, int mid, vector<string>& all) {
    for (int i = 0; i <= mid; ++i) {
        first += " " +all[index[i]];
    }
    first.erase(0,1);
    
    for (int i = mid+1; i < index.size(); ++i) {
        second += " " + all[index[i]];
    }
    second.erase(0,1);
}

bool isMatch(vector<string>& all, int mid, vector<int> index, unordered_map<char, char>& mp) {
    string s1, s2;
    for (int i = 0; i <= mid; ++i) s1 += all[index[i]];
    for (int i = mid+1; i < index.size(); ++i) s2 += all[index[i]];
    
    int len1 = s1.size(), len2 = s2.size();
    if (len1 != len2) return false;
    
    for (int i = 0; i < len1; ++i) {
        if (mp[s1[i]] != s2[i]) return false;
    }
    return true;
}

void ContestExerciseImpl::main() {
    int N;
    cin >> N;
    string line;
    vector<string> all;
    int size = 0;
    for (int i = 0; i < N; ++i) {
        cin >> line;
        all.push_back(line);
        size += line.size();
    }
    
    vector<int> indexes(N);
    for (int i = 0; i < N; ++i) {
        indexes[i] = i;
    }
    vector<vector<int>> permutations;
    dfs(indexes, permutations, 0);
    
    unordered_map<char, char> mp;
    mp['A'] = 'T';
    mp['T'] = 'A';
    mp['C'] = 'G';
    mp['G'] = 'C';

    for (auto index : permutations) {
        int len = 0;
        for (int i = 0; i < N; ++i) {
            len += all[index[i]].size();
            if (len > size/2) break;
            if (len == size/2) {
                if (isMatch(all, i, index, mp)) {
                    string first, second;
                    construct(first, second, index, i, all);
                    cout << first + "#" + second;
                    return ;
                }
            }
        }
    }
}