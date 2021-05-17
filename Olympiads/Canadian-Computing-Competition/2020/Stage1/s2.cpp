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
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

constexpr int MAXN = 1e3 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

int N, M;
vector <int> adj [MAXN * MAXN];
bool visited [MAXN * MAXN];

void dfs(int x){
  if (visited[x]){
    return;
  }
  visited[x] = 1;
  for (auto &i: adj[x]){
    dfs(i);
  }
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> M >> N;

  for (int i = 1; i <= M; ++i){
    for (int j = 1; j <= N; ++j){
      int res; cin >> res;
      adj[i * j].push_back(res);
    }
  }

  dfs(1);

  if (visited[N * M]) {
    cout << "yes\n"; 
  }
  else {
    cout << "no\n";
  }
}
