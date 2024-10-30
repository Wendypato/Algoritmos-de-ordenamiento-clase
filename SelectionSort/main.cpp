#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& vec) {
    int n = vec.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; //Almacenamos el indice del elemento minimo encontrado

        //Buscamos el elemento minimo en el subarreglo no ordenado
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j; //Actualiza el indice del minimo
            }
        }


        if (minIndex != i) {
            int temp = vec[i];
            vec[i] = vec[minIndex];
            vec[minIndex] = temp;
        }
    }
}

void printArray(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {64, 25, 12, 22, 11};

    cout << "Array original: ";
    printArray(vec);

    selectionSort(vec);

    cout << "Array ordenado: ";
    printArray(vec);

    return 0;
}
