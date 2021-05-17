#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, l;
  cin >> n >> l;
  vector<string> s (n);
  for (auto &i: s) cin >> i;
  sort(s.begin(), s.end());
  for (auto &i: s) cout << i;
  cout << "\n";
}
