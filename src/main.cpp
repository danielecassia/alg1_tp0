#include <iostream>
#include <vector>
#include <chrono>

// #include "quicksorts.cpp"
#include "fibonacci.cpp"

#define debug(x) cout << #x << " = " << x<< endl
#define SECONDS 15
#define MAX 10000000000
#define MAXR 50



int time(ll m, ll (*fibonacci)(ll)){
    auto start = chrono::steady_clock::now();
    fibonacci(m);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> duracao = end - start;
    return duracao.count();
}

int main() {
    //debug
    // int seconds = time(MAX, fib);
    // debug(seconds);
    // return 0;

    //teste para fib iterativo
    ll l=0LL, r=MAX;
    while(l<r){
        ll m = (l+r)/2;
        int t = time(m, fib);
        if(t >= SECONDS){
            r = m;
        } else {
            l = m+1;
        }
    }
    std::cout << "Quantidade de números gerados (iterativo): "<< l-1 << endl;

    //teste para fib recursivo
    l=0LL, r=MAXR;
    while(l<r){
        ll m = (l+r)/2;
        int t = time(m, fibR);
        if(t >= SECONDS){
            r = m;
        } else {
            l = m+1;
        }
    }
    std::cout << "Quantidade de números gerados (recursivo): "<< l-1 << endl;
    // return 0;
}
