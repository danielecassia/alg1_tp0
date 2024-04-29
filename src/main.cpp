#include <iostream>
#include <vector>
#include <chrono>

#include "fibonacci.cpp"

#define debug(x) cout << #x << " = " << x<< endl
#define SECONDS 15
#define MIN 3221874000 // Valor mínimo para a busca binária iterativa
#define MAX 100000000000 // Valor máximo para a busca binária iterativa 
#define MAXR 51 // Valor máximo para a busca binária recursiva

// Função para medir o tempo de execução de Fibonacci
float time(ll m, ll (*fibonacci)(ll)){
    auto start = chrono::steady_clock::now(); // Captura o tempo de início
    fibonacci(m); // Chama a função Fibonacci
    auto end = chrono::steady_clock::now(); // Captura o tempo de término
    chrono::duration<double> duracao = end - start; // Calcula a duração da execução
    return duracao.count(); // Retorna a duração em segundos
}

int main() { 
    //teste para fib iterativo
    ll l=MIN, r=MAX; // Inicialização dos limites para busca binária iterativa
    auto startI = chrono::steady_clock::now(); // Captura o tempo de início
    while(l<r){
        ll m = (l+r)/2; // Calcula o ponto médio
        int t = time(m, fib); // Mede o tempo de execução para Fibonacci iterativo
        if(t >= SECONDS){
            r = m; // Atualiza o limite superior
        } else {
            l = m+1; // Atualiza o limite inferior
        }
    }
    auto endI = chrono::steady_clock::now(); // Captura o tempo de término
    chrono::duration<double> duracaoI = endI - startI; // Calcula a duração da execução
    cout << "Quantidade de números gerados (iterativo): "<< l-1 << endl; // Imprime o resultado da busca
    cout << "tempo: "<< duracaoI.count() << endl; 
    cout << " ---------------------------------------------- " << endl;

    //teste para fib recursivo
    l=30LL, r=MAXR; // Inicialização dos limites para busca binária recursiva
    auto startR = chrono::steady_clock::now(); // Captura o tempo de início
    while(l<r){
        ll m = trunc((l+r)/2); // Calcula o ponto médio
        float t = time(m, fibR); // Mede o tempo de execução para Fibonacci recursivo
        cout << " Fib de "<< m << " = " << t << endl;
        if(t >= SECONDS){
            r = m; // Atualiza o limite superior
        } else {
            l = m+1; // Atualiza o limite inferior
        }
    }
    auto endR = chrono::steady_clock::now(); // Captura o tempo de término
    chrono::duration<double> duracaoR = endR - startR; // Calcula a duração da execução
    cout << "Quantidade de números gerados (recursivo): "<< l-1 << endl; // Imprime o resultado da busca
    cout << "tempo: "<< duracaoR.count() << endl;
    cout << " ---------------------------------------------- " << endl;

    return 0;
}
