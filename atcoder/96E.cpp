#include <iostream>

using namespace std;
 
typedef long long ll;
ll MOD;
ll N;

ll qp(ll q,ll n,ll mod = MOD) {
  ll ans = 1,now = q % mod;
  while(n)
    {
      if(n & 1) ans = ans * now % mod;
      now = now * now % mod;
      n >>= 1;
    }
  return ans;
}

const int maxn = 3000+10;
ll f[maxn][maxn],c[maxn][maxn];
void getC()
{
  for(int i=1;i<maxn;++i) c[0][i]=0;
  for(int i=0;i<maxn;++i) c[i][0]=1;
  for(int i=1;i<maxn;++i)
    for(int j=1;j<=i;++j)
      c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
}
void getF()
{
  f[1][1]=1,f[1][2]=0;
  for(int i=1;i<maxn;++i) f[i][0]=1;
  for(int i=2;i<maxn-1;++i)
    for(int k=1;k<=i;++k)
      f[i][k]=(f[i-1][k]*(1+k)+f[i-1][k-1])%MOD;
}
int main()
{
  cin>>N>>MOD;
  getC();getF();
  ll ans=0;
  ll q=-1;
  ll tmp=0;
  for(int j=1;j<=N;++j)
    {
      q=-q;
      tmp=0;
      for(int k=0;k<=j;++k)
        {
	  tmp=(tmp+(f[j][k])*qp(2,(N-j)*k)%MOD)%MOD;
        }
      tmp=(tmp*(qp(2,qp(2,(N-j),MOD-1)))-1)%MOD;
      ans=(ans+q*c[N][j]*tmp%MOD)%MOD;
      (ans+=MOD)%=MOD;
    }
  ll tot=qp(2,qp(2,N,MOD-1))-1;
  ans=(tot-ans);
  ((ans%=MOD)+=MOD)%=MOD;
  cout<<ans<<endl;
  return 0;
}
