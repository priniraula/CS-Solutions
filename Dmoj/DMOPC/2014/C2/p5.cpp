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

constexpr int MAXN = 1e9 + 7;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

vector <vector <int> > graph;
vector <double> dist;

int V = 0, E = 0;

void bfs (){
  dist[1] = 1;

  for (int i = 1; i <= V; ++i){
    double res = (double)(dist[i] / graph[i].size());
    if (graph[i].empty()){
      cout << dist[i] << "\n";
      continue;
    }

    for (auto &j: graph[i]){
      dist[j] += res;
    }
  }
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> V >> E; 
  graph.resize(V + 1); 

  for (int i = 0; i < E; ++i){
    int s, e; cin >> s >> e;
    graph[s].push_back(e);
  }

  dist.resize(V + 1);
  cout << setprecision(10) << fixed << "\n";

  bfs();
}
