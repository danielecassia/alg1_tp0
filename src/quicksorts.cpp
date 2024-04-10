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
void QuicksortRECURSIVO(vector<int> &V, int n) {
    Ordena(0, n - 1, V);
}
// Quicksort Recursivo com Inserção
void QuicksortRECURSIVOI(vector<int> &V, int n) {
    Ordena(0, n - 1, V);
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
void QuicksortNRecursivo(vector<int> &V, int n) {
    queue<pair<int, int>> q;
    q.push(make_pair(0, n - 1));
    int i, j;
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        i = t.first, j = t.second;
        int x = V[(i + j) / 2];  // pivo x
        do {
            while (x > V[i]) {
                i++;
            }
            while (x < V[j]) {
                j--;
            }
            if (i <= j) {
                swap(V[i], V[j]);
                i++;
                j--;
            }
        } while (i <= j);

        if (t.first < j) q.push(make_pair(t.first, j));
        if (i < t.second) q.push(make_pair(i, t.second));
        
    }
}

// Quicksort Não Recursivo com Inserção
void QuicksortNRecursivoI(vector<int> &V, int n) {
    queue<pair<int, int>> q;
    q.push(make_pair(0, n - 1));
    int i, j;
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        i = t.first, j = t.second;
        int x = V[(i + j) / 2];  // pivo x
        if (j - i + 1 > INSERTION_THRESHOLD) {
            do {
                while (x > V[i]) {
                    i++;
                }
                while (x < V[j]) {
                    j--;
                }
                if (i <= j) {
                    swap(V[i], V[j]);
                    i++;
                    j--;
                }
            } while (i <= j);

            if (t.first < j) q.push(make_pair(t.first, j));
            if (i < t.second) q.push(make_pair(i, t.second));
        }  
        else {
            InsertionSort(V, t.first, t.second);
        }
    }
}
  
  