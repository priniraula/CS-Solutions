#include <iostream>
#include <cmath>
#include <vector>

int main(){
  int N, sum=0;
  std::cin >> N;
  std::vector<int> a(N);
  for(auto &i: a){
    std::cin >> i;
    sum+=i;
  }
  int mid=std::round((double)sum/N);
  int cost=0;
  for (auto &i: a){
    cost+=((i-mid)*(i-mid));
  }
  std::cout << cost << "\n";
}
