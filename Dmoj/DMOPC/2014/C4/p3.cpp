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

constexpr int MAXN = 1005;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

int bonds [MAXN][MAXN];
int atoms [MAXN];

bitset <MAXN> visited;

int atom_num, bond_num;
int hydrogen, carbon;

unsigned long long energy;

void dfs (int vertex) {
	if (visited[vertex]) {
		return;
	}

	visited[vertex] = true;

	if (atoms[vertex] == 1) {
		++hydrogen;
		energy += 413;

		return;
	}
	else if (atoms[vertex] == 4) {
		++carbon;
	
		for (int i = 1; i <= atom_num; ++i) {
			if (!visited[i]) {
				if (bonds[vertex][i] == 2 && atoms[i] == 4) {
					energy += 615;
				} 
				else if (bonds[vertex][i] == 1 && atoms[i] == 4) {
					energy += 346;
				}
			}
		}
	}
	else {
		cout << "Impossible\n";
		exit(0);
	}
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

	cin >> atom_num >> bond_num;

	for (int i = 0; i < bond_num; ++i) {
		int start, end;
		cin >> start >> end;

		++atoms[start];
		++atoms[end];
		++bonds[start][end];
		++bonds[end][start];
	}

	for (int i = 1; i <= atom_num; ++i) {
		if (atoms[i] != 4 && atoms[i] != 1) {
			cout << "Impossible\n";
			return 0;
		}
	}

	visited.set();
	visited.flip();

	for (int i = 1; i <= atom_num; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	cout << energy << "\n";
	cout << "C";

	if (carbon > 1) {
		cout << carbon;
	}

	cout << "H";

	if (hydrogen > 1) {
		cout << hydrogen;
	}

}
