// 没屌用
#include <iostream>
#include <vector>
using namespace std;

const int MOD=1e9+7;
const int MAXN=1e5+10;

int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main(){
  int H, W, A, B;
  cin>>H>>W>>A>>B;
  if(H==A){
    cout << 0 << "\n";
  }
  else{
    vis[1][1]=1;
    for (int i=0; i<A; ++i){
      for (int j=0; j<B; ++j){
        vis[H-i][W-j]=1;
      }
    }
    for (int i=1; i<=H; ++i){
      for (int j=1; j<=W; ++j){
        if (vis[i][j]) grid[i][j]=0;
        else if(i==1||j==1) grid[i][j]=1;
        else grid[i][j]=(grid[i-1][j]+grid[i][j-1])%MOD;
      }
    }
    cout<< grid[H][W]%MOD << "\n";
  }
}
