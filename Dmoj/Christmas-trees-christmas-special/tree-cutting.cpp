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

int matrix[12][12];
int dista[12][12];
int tree[12][12];

vector <pair <int,int> > highestTrees;
pair <int, int> START, END;

int x_add, y_add;

double findDist (pair<int, int> other){
  double a = (START.first - other.first) * (START.first - other.first);
  double b = (START.second - other.second) * (START.second - other.second);
  return a + b;
}

void assign (int i) {
	if (i == 0) {
		x_add = 1;
		y_add = 0;
	}
	else if (i == 1) {
		x_add = -1;
		y_add = 0;
	}
	else if (i == 2) {
		x_add = 0;
		y_add = 1;
	}
	else if (i == 3) {
		x_add = 0;
		y_add = -1;
	}
	else {
		x_add = 0;
		y_add = 0;
	}
}

int main (){
  for (int x = 0; x < 12; x++) {
    for (int y = 0; y < 12; y++) {
      matrix[x][y] = dista[x][y] = tree[x][y] = INF;
    }	
	}

  int r, c, biggest_tree = 0;
  double smallest_distance = 1000;
  char ch, blank;

  cin >> r >> c;
	
  for (int x = 1; x <= r; x++){
    for (int y = 1; y <= c; y++){
      scanf(" %c", &ch);

      if (ch == 'X'){
        START = {x, y};
        matrix[x][y] = dista[x][y] = tree[x][y] = 0;
      }
      else if (ch == '.') {
        matrix[x][y] = 0;
      }
      else if (ch - '0' >= 0 && ch - '0' < 10){
        matrix[x][y] = ch - '0';
        if (matrix[x][y] > biggest_tree){
          biggest_tree = matrix[x][y];
          highestTrees.clear();
          highestTrees.push_back({x, y});
        }
        else if (matrix[x][y] == biggest_tree) {
          highestTrees.push_back({x, y});
        }
      }
    }
  }

  for (auto &i: highestTrees){
    int dist = findDist(i);
    if (smallest_distance > dist){
      smallest_distance = dist;
      END = {i.first, i.second};
    }
  }

	queue <pair<int,int>> Q;
  Q.push({START.first, START.second});

  while (!Q.empty()){
    int x = Q.front().first;
    int y = Q.front().second;
  
    Q.pop();
      
    for (int i = 0; i < 4; i++){
      int t = 0;
      assign(i);
    
      if (matrix[x + x_add][y + y_add] != 0) {
        t = 1;
      }

      int x1 = x + x_add;
      int y1 = y + y_add;
    
      if (matrix[x1][y1] != INF && tree[x][y] + matrix[x1][y1] < tree[x1][y1]){
        dista[x1][y1] = dista[x][y] + t;
        Q.push({x1, y1});
        tree[x1][y1] = tree[x][y] + matrix[x1][y1];
      }
      else if (matrix[x1][y1] != INF && tree[x][y] + matrix[x1][y1] == tree[x1][y1]) {
        dista[x1][y1] = min(dista[x1][y1], dista[x][y] + t);
        tree[x1][y1] = tree[x][y] + matrix[x1][y1];
      }
    }
  }

	cout << dista[END.first][END.second] - 1 << endl;
}
