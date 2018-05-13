#include <iostream>

#define ll long long
using namespace std;
const int N = 1e5+10;
const int mod = 1e9+9;
char str[N];
ll n, a, b, k, ans;
ll pow_mod(ll x, ll n){  
    ll ans=1;  
    while(n>0){
      cout << n << endl;
      cout << ans << endl;
      cout << x << endl;
      cout << "NEXT" << endl;
        if(n&1)ans=ans*x;  
        x=x*x;  
        n>>=1;  
    }  
    return ans;  
}
int main() {
  cout << pow_mod(3, 20);
}
