#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define INF (int)1e9
#define FOR(x, n) for (int x = 0; x < n; x++)
#define REP(n) FOR(_, n)
#define vec vector
typedef long long ll;

using namespace std;

void init() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

////////////////////////////////////////////////////////////////////////////////////////////////////

unordered_map<int, int> m;
int arr[1000001];

int main() {
    init();

    int n; cin >> n;
    FOR(i, n) {
        int res;
        cin >> res;
        ++arr[res];
    }

    int longest = 0;
    int count = 0;

    FOR(i, 2001) {
        if(arr[i]){
            for (int j = i; j < 2001;j++) {
              if (i == j && arr[i]) m[i + j] += (arr[i] / 2);
              else if (arr[i] && arr[j]) m[i + j] += min(arr[i], arr[j]);
            }
        }
    }

    for (auto const& [key, val] : m) {
        if (val > longest) {
            longest = val;
            count = 1;
        } else if (val == longest) {
            count++;
        }
    }

    cout << longest << ' ' << count;
}
