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

constexpr int MAXN = 1e3 + 7;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

vector <pair <int, int> > graph [MAXN];
int N, M, dist[MAXN];

void go (int source){
  memset(dist, INF, sizeof(dist));
  priority_queue<int, vector<int>, greater<int>> Q;
  dist[source] = 0;
  Q.push(source);

  while(!Q.empty()){
    int curr = Q.top();
    Q.pop();

    for (auto &i: graph[curr]){
      int vertex = i.first, weight = i.second;
      if (dist[vertex] > dist[curr] + weight){
        dist[vertex] = dist[curr] + weight;
        Q.push(vertex);
      }
    }
  }
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < M; ++i){
    int start, end, weight;
    cin >> start >> end >> weight;
    graph[start].push_back({end, weight});
    graph[end].push_back({start, weight});
  }

  go(1);

  for (int i = 1; i <= N; ++i){
    if (dist[i] == INF){
      cout << -1 << "\n";
    }
    else {
      cout << dist[i] << "\n";
    }
  }
}
