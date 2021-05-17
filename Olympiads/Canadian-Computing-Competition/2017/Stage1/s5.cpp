#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)

constexpr int MAXN = 1e5 + 5e4 + 10;
constexpr int MAXM = 410;
constexpr int INF = 0x3f3f3f3f;

int A [MAXN], L [MAXN], MOV [MAXN], POS [MAXN], AC [MAXM];
vector <int> L2 [MAXN];
vector <int> B [MAXN];

int get (int pos){
  int n = L[pos];
  int sz = (int) L2[n].size();
  int idx = (POS[pos] - MOV[n] % sz + sz) % sz;
  int ANS = A[L2[n][idx]];
  //DEBUG(ANS);
  return ANS;
}

int main (){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  memset(A, 0, sizeof(A));
  memset(L, 0, sizeof(L));
  memset(MOV, 0, sizeof(MOV));
  memset(POS, 0, sizeof(POS));
  memset(AC, 0, sizeof(AC));

  int N, M, Q, N_SQ;
  cin >> N >> M >> Q;

  for (int i = 0; i < N; ++i){
    cin >> L[i];
    --L[i], L2[L[i]].push_back(i);
    POS[i] = (int) L2[L[i]].size() - 1;
  }

  for (int i = 0; i < N; ++i){
    cin >> A[i];
  }

  N_SQ = sqrt(N);

  for (int i = 0; i < N; i += N_SQ){
    int small = min(N - 1, i + N_SQ - 1);

    for (int j = i; j <= small; ++j){
      AC[i / N_SQ] += A[j];
      int n1 = L[j], chc2 = i / N_SQ;
      if (B[n1].empty() || B[n1].back() / N_SQ != chc2){
        B[n1].push_back(j);
      }
      else {
        B[n1][B[n1].size() - 1] = j;
      }
    }
  }

  while (Q--){
    int type;
    cin >> type;

    if (type == 1){
      int left, right; 
      cin >> left >> right;

      --left, --right;
      int ans = 0;

      while (left % N_SQ != 0 && left <= right ){
        ans += get (left), ++left;
      }

      while (right % N_SQ != N_SQ - 1 && right >= left){
        ans += get(right), --right;
      }

      while (left <= right){
        ans += AC[left / N_SQ], left += N_SQ;
      }

      cout << ans << "\n";
    }
    else if (type == 2){
      int pos, pos_size;
      cin >> pos;

      --pos;
      pos_size = (int) B[pos].size();
      // DEBUG(MOV[pos]);

      for (int i = 0; i < pos_size; ++i){
        int current = get(B[pos][i]);
        AC[B[pos][i] / N_SQ] -= current;
        // DEBUG(AC[B[pos][i] / N_SQ]); 
        AC[B[pos][(i + 1) % pos_size]/ N_SQ] += current;
        // DEBUG(AC[B[pos][(i + 1) % B[pos].size()] / N_SQ] );
      }
      ++MOV[pos];
    }
  }
}
