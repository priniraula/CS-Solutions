#include <iostream>
#include <vector>

int main(){
  std::string inp;
  std::cin >> inp;
  int sz=(int)inp.size();
  if (sz==2){
    if(inp[0]==inp[1]){
      std::cout << 1<< " " << 2<< "\n";
    }
    else{
      std::cout << -1 << " " << -1 << "\n";
    }
  }
  else {
    bool yes=0;
    int idx1=-1,idx2=-1;
    for (int i=1; i<=sz-1; ++i){
      char a=inp[i-1], b=inp[i], c=inp[i+1];
      if((a==c || a==b) && !yes){
        yes=1;
        idx1=i;
        idx2=i+2;
        break;
      }
    }
    std::cout << idx1 <<" "<< idx2 << "\n";
  }
}
