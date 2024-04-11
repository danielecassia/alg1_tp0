#include <iostream>
#include <algorithm>


using namespace std;
typedef long long ll;

// TODO: ajustar o código para dado um tempo n, em segundos, eu retorne quantos número da se3quencia é possível gerar
ll fibR(ll n){
    if(n <= 1) return n;
    return fibR(n-1) + fibR(n-2);
}

ll fib(ll n){
    ll a=0,b=1,c=0,i=0;
    if(n ==0) return a;
    for(i=2;i<=n;i++){
        c = a+b;
        a = b;
        b = c;
    }
    return b;
}


