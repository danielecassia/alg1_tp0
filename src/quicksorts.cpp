#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue> 

using namespace std;

/*
$$$$$$\                                          $$\     $$\                     
\_$$  _|                                         $$ |    \__|                    
  $$ |  $$$$$$$\   $$$$$$$\  $$$$$$\   $$$$$$\ $$$$$$\   $$\  $$$$$$\  $$$$$$$\  
  $$ |  $$  __$$\ $$  _____|$$  __$$\ $$  __$$\\_$$  _|  $$ |$$  __$$\ $$  __$$\ 
  $$ |  $$ |  $$ |\$$$$$$\  $$$$$$$$ |$$ |  \__| $$ |    $$ |$$ /  $$ |$$ |  $$ |
  $$ |  $$ |  $$ | \____$$\ $$   ____|$$ |       $$ |$$\ $$ |$$ |  $$ |$$ |  $$ |
$$$$$$\ $$ |  $$ |$$$$$$$  |\$$$$$$$\ $$ |       \$$$$  |$$ |\$$$$$$  |$$ |  $$ |
\______|\__|  \__|\_______/  \_______|\__|        \____/ \__| \______/ \__|  \__|
*/         

const int INSERTION_THRESHOLD = 30;
                                                                        
void InsertionSort(vector<int> &V, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = V[i];
        int j = i - 1;
        while (j >= left && V[j] > key) {
            V[j + 1] = V[j];
            --j;
        }
        V[j + 1] = key;
    }
}


/*
 $$$$$$\            $$\           $$\                                      $$\     
$$  __$$\           \__|          $$ |                                     $$ |    
$$ /  $$ |$$\   $$\ $$\  $$$$$$$\ $$ |  $$\  $$$$$$$\  $$$$$$\   $$$$$$\ $$$$$$\   
$$ |  $$ |$$ |  $$ |$$ |$$  _____|$$ | $$  |$$  _____|$$  __$$\ $$  __$$\\_$$  _|  
$$ |  $$ |$$ |  $$ |$$ |$$ /      $$$$$$  / \$$$$$$\  $$ /  $$ |$$ |  \__| $$ |    
$$ $$\$$ |$$ |  $$ |$$ |$$ |      $$  _$$<   \____$$\ $$ |  $$ |$$ |       $$ |$$\ 
\$$$$$$ / \$$$$$$  |$$ |\$$$$$$$\ $$ | \$$\ $$$$$$$  |\$$$$$$  |$$ |       \$$$$  |
 \___$$$\  \______/ \__| \_______|\__|  \__|\_______/  \______/ \__|        \____/ 
     \___|                                                                         
*/                                                                                       

/*
  _____                          _           
 |  __ \                        (_)           
 | |__) |___  ___ _   _ _ __ ___ ___   _____  
 |  _  // _ \/ __| | | | '__/ __| \ \ / / _ \ 
 | | \ \  __/ (__| |_| | |  \__ \ |\ V / (_) |
 |_|  \_\___|\___|\__,_|_|  |___/_| \_/ \___/ 
*/
void Particao(int Esq, int Dir, int *i, int *j, vector<int> &A) {
    int x, w;
    *i = Esq, *j = Dir;
    x = A[(*i + *j) / 2];  // pivo x
    do {
        while (x > A[*i]) {
            (*i)++;
        }
        while (x < A[*j]) {
            (*j)--;
        }
        if (*i <= *j) {
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, vector<int> &A) {
    int i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Ordena(Esq, j, A);
    if (i < Dir) Ordena(i, Dir, A);
}
void OrdenaI(int Esq, int Dir, vector<int> &A) {
    int i, j;
    if (Dir - Esq + 1 > INSERTION_THRESHOLD) {
        Particao(Esq, Dir, &i, &j, A);
        if (Esq < j) Ordena(Esq, j, A);
        if (i < Dir) Ordena(i, Dir, A);
    }
    else {
        InsertionSort(A, Esq, Dir);
    }

}

// Quicksort Recursivo

vector<int> QuicksortRecursivoPuro(const vector<int> arr) {
    vector<int> sorted = arr;
    Ordena(0, sorted.size() - 1, sorted);
    return sorted;
}

// Quicksort Recursivo com Inserção

vector<int> QuicksortRecursivoOrdenacaoInsercao(const vector<int> arr) {
    vector<int> sorted = arr;
    OrdenaI(0, sorted.size() - 1, sorted);
    return sorted;
}

/*
  _   _               _____                          _            
 | \ | | /\/         |  __ \                        (_)           
 |  \| | __ _  ___   | |__) |___  ___ _   _ _ __ ___ ___   _____  
 | . ` |/ _` |/ _ \  |  _  // _ \/ __| | | | '__/ __| \ \ / / _ \ 
 | |\  | (_| | (_) | | | \ \  __/ (__| |_| | |  \__ \ |\ V / (_) |
 |_| \_|\__,_|\___/  |_|  \_\___|\___|\__,_|_|  |___/_| \_/ \___/  
*/                                                                                                                           
// Quicksort Não Recursivo
vector<int> QuicksortNaoRecursivoPuro(const vector<int> arr) {
    vector<int> sorted = arr;
    queue<pair<int, int>> q;
    q.push(make_pair(0, sorted.size() - 1));
    int i, j;
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        i = t.first, j = t.second;
        int x = sorted[(i + j) / 2]; 
        do {
            while (x > sorted[i]) {
                i++;
            }
            while (x < sorted[j]) {
                j--;
            }
            if (i <= j) {
                swap(sorted[i], sorted[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (t.first < j) q.push(make_pair(t.first, j));
        if (i < t.second) q.push(make_pair(i, t.second));
    }
    return sorted;
}

// Quicksort Não Recursivo com Inserção

vector<int> QuicksortNaoRecursivoOrdenacaoInsercao(const vector<int> arr) {
    vector<int> sorted = arr;
    queue<pair<int, int>> q;
    q.push(make_pair(0, sorted.size() - 1));
    int i, j;
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        i = t.first, j = t.second;
        int x = sorted[(i + j) / 2];  
        if (j - i + 1 > INSERTION_THRESHOLD) {
            do {
                while (x > sorted[i]) {
                    i++;
                }
                while (x < sorted[j]) {
                    j--;
                }
                if (i <= j) {
                    swap(sorted[i], sorted[j]);
                    i++;
                    j--;
                }
            } while (i <= j);
            if (t.first < j) q.push(make_pair(t.first, j));
            if (i < t.second) q.push(make_pair(i, t.second));
        }  
        else {
            InsertionSort(sorted, t.first, t.second);
        }
    }
    return sorted;
}
  
  