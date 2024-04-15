#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll; // Define o tipo de dado "ll" como "long long"

// Função recursiva
ll fibR(ll n){
    if(n <= 1) return n; // Condição de parada para os casos base (0 e 1)
    return fibR(n-1) + fibR(n-2); // Chamadas recursivas para os números de Fibonacci anteriores
}

// Função iterativa 
ll fib(ll n){
    ll a=0,b=1,c=0,i=0; // Inicialização das variáveis para os dois primeiros números de Fibonacci
    if(n == 0) return a; // Trata o caso especial quando n é 0
    for(i=2;i<=n;i++){ // Loop para calcular os números de Fibonacci de forma iterativa
        c = a+b; // Calcula o próximo número de Fibonacci
        a = b; // Atualiza o valor de "a" para o próximo cálculo
        b = c; // Atualiza o valor de "b" para o próximo cálculo
    }
    return b; // Retorna o n-ésimo número de Fibonacci
}
