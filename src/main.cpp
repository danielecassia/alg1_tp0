#include <iostream>
#include <vector>
#include <chrono>

#include "fibonacci.cpp"

#define debug(x) cout << #x << " = " << x<< endl
#define SECONDS 15 // Limite de tempo em segundos
#define MAX 10000000000 // Valor máximo para a busca binária iterativa
#define MAXR 50 // Valor máximo para a busca binária recursiva

// Função para medir o tempo de execução de Fibonacci
int time(ll m, ll (*fibonacci)(ll)){
    auto start = chrono::steady_clock::now(); // Captura o tempo de início
    fibonacci(m); // Chama a função Fibonacci
    auto end = chrono::steady_clock::now(); // Captura o tempo de término
    chrono::duration<double> duracao = end - start; // Calcula a duração da execução
    return duracao.count(); // Retorna a duração em segundos
}

int main() {
    //teste para fib iterativo
    ll l=0LL, r=MAX; // Inicialização dos limites para busca binária iterativa
    while(l<r){
        ll m = (l+r)/2; // Calcula o ponto médio
        int t = time(m, fib); // Mede o tempo de execução para Fibonacci iterativo
        if(t >= SECONDS){
            r = m; // Atualiza o limite superior
        } else {
            l = m+1; // Atualiza o limite inferior
        }
    }
    std::cout << "Quantidade de números gerados (iterativo): "<< l-1 << endl; // Imprime o resultado da busca

    //teste para fib recursivo
    l=0LL, r=MAXR; // Inicialização dos limites para busca binária recursiva
    while(l<r){
        ll m = (l+r)/2; // Calcula o ponto médio
        int t = time(m, fibR); // Mede o tempo de execução para Fibonacci recursivo
        if(t >= SECONDS){
            r = m; // Atualiza o limite superior
        } else {
            l = m+1; // Atualiza o limite inferior
        }
    }
    std::cout << "Quantidade de números gerados (recursivo): "<< l-1 << endl; // Imprime o resultado da busca
    // return 0;
}
