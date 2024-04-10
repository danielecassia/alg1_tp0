#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "quicksorts.cpp"

// Função para gerar um conjunto de números aleatórios
std::vector<int> gerarNumerosAleatorios(int tamanho) {
    std::vector<int> numeros(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        numeros[i] = rand() % 1000000; // Gerando números entre 0 e 999999
    }
    return numeros;
}

// Função para calcular o tempo de execução de uma determinada estratégia de ordenação
void calcularTempoOrdenacao(std::vector<int>& numeros, void (*funcaoOrdenacao)(std::vector<int>&, int)) {
    auto inicio = std::chrono::steady_clock::now();
    funcaoOrdenacao(numeros, numeros.size());
    auto fim = std::chrono::steady_clock::now();
    std::chrono::duration<double> duracao = fim - inicio;
    std::cout << "Tempo de execucao: " << duracao.count() << " segundos" << std::endl;
}

int main() {
    srand(time(0)); // Inicializando a semente do gerador de números aleatórios com o tempo atual

    // Gerar 50 conjuntos de 10.000 números aleatórios
    const int NUM_CONJUNTOS = 50;
    const int TAMANHO_CONJUNTO = 10000000;
    std::vector<std::vector<int>> conjuntos;
    for (int i = 0; i < NUM_CONJUNTOS; ++i) {
        conjuntos.push_back(gerarNumerosAleatorios(TAMANHO_CONJUNTO));
    }

    // Aplicar as diferentes estratégias de ordenação e calcular os tempos de execução
    std::cout << "Quicksort Recursivo:" << std::endl;
    for (int i = 0; i < NUM_CONJUNTOS; ++i) {
        std::cout << "Conjunto " << i + 1 << ": ";
        calcularTempoOrdenacao(conjuntos[i], QuicksortRECURSIVO);
    }

    std::cout << std::endl;

    std::cout << "Quicksort Não Recursivo:" << std::endl;
    for (int i = 0; i < NUM_CONJUNTOS; ++i) {
        std::cout << "Conjunto " << i + 1 << ": ";
        calcularTempoOrdenacao(conjuntos[i], QuicksortNRecursivo);
    }

    std::cout << "Quicksort Recursivo com Inserção:" << std::endl;
    for (int i = 0; i < NUM_CONJUNTOS; ++i) {
        std::cout << "Conjunto " << i + 1 << ": ";
        calcularTempoOrdenacao(conjuntos[i], QuicksortRECURSIVO);
    }

    std::cout << std::endl;

    std::cout << "Quicksort Não Recursivo com Inserção:" << std::endl;
    for (int i = 0; i < NUM_CONJUNTOS; ++i) {
        std::cout << "Conjunto " << i + 1 << ": ";
        calcularTempoOrdenacao(conjuntos[i], QuicksortNRecursivo);
    }

    return 0;
}
