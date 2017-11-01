#define LOCALEXEC true

#include <ctime>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <sstream>
#include <iterator>

#if !LOCALEXEC
    #include "exercise.hpp"
#endif
using namespace std;

const bool DEB = false;

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}


#if LOCALEXEC
  int main (int argc, char * argv[]) {
#else
  ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
  void ContestExerciseImpl::main() {
#endif

    std::ios::sync_with_stdio(false);
    clock_t start = clock();

    

      int M, T, N, V;
      cin >> M >> T;
      vector<pair<int, int>> coins;
      for (int i = 0; i < T; ++i) {
          cin >> N >> V;
          coins.push_back(make_pair(N, V));
      }
      
      vector<int> dp(M+1, 1000);
      dp[0] = 0;
      for (auto coin : coins) {
          int n = coin.first, v = coin.second;
          
          for (int i = M; i >= v; --i) {
              for (int k = 1; k <= n; ++k) {
                  if (i >= k*v) {
                      dp[i] = min(dp[i], k+dp[i-k*v]);
                  }
              }
          }
      }
      
      if (dp[M] == 1000) cout << "IMPOSSIBLE";
      else cout << dp[M];
      
      
      if (DEB) {
          cout << "****** solving: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;
    }

#if LOCALEXEC
    return 0;
#endif
    
}

