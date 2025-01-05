#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <cmath>
using namespace std;

// Declaración de funciones
void merge(vector<int>& arr, int left, int mid, int right);
void mergeSort(vector<int>& arr, int left, int right);
void printList(const vector<int>& arr);
int calculateSimilarityScore(const vector<int>& left, const vector<int>& right);
void diferencia(const vector<int>& arr, const vector<int>& arr2); 

int main() {

    vector<int> arrderecha; //array dinámico valores de la izquierda
    vector<int> arrizquierda;    //array  dinámico  valores de la derecha
    string inputLine;

    cout << "Introduce las líneas con dos números separados por espacio. Escribe 'fin' para terminar:" << endl;

    //bucle para insertar los vectores a través desde la terminal
    while (true) {
        getline(cin, inputLine);
        if (inputLine == "fin") break; //cuando se escribe fin el bucle termian de leer

        int izquierda, derecha;
        if (sscanf(inputLine.c_str(), "%d %d", &izquierda, &derecha) == 2) {
            arrizquierda.push_back(izquierda);
            arrderecha.push_back(derecha);
        } else {
            cerr << "Línea inválida. Asegúrate de ingresar dos números por línea." << endl;
        }
    }

    //Mostrar los resultados antes de ordenar
    cout << "Valores de la izquierda antes de ordenar:" << endl;
    printList(arrizquierda);

    cout << "Valores de la derecha antes de ordenar:" << endl;
    printList(arrderecha);

    //Se ordena con el algoritmo demergeSort
    mergeSort(arrizquierda, 0, arrizquierda.size() - 1);
    mergeSort(arrderecha, 0, arrderecha.size() - 1);

    //SE muestran los resultados después de ordenar
    cout << "Valores de la izquierda después de ordenar:" << endl;
    printList(arrizquierda);

    cout << "Valores de la derecha después de ordenar:" << endl;
    printList(arrderecha);
    
    //Calculamos y mostramos la diferencia con la funcion diferencia
    diferencia(arrizquierda, arrderecha);

   
    //calculamos y mostramos el similarity score
    int similarityScore = calculateSimilarityScore(arrizquierda, arrderecha);
    cout << "La puntuación de similitud es: " << similarityScore << endl;

    return 0;
}

//función merge, fusiona dos subarrays ordenados en un vector
void merge(vector<int>& arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //arrays temporales
    vector<int> L(n1);

    vector<int> R(n2);

    //se guardan los datos en estos arrays

    for (i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    //y ahora lo que se hace es combinar los arrays temporales con el array original

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    //se copian los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    //se copian los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

//función mergeSort, implementa el algoritmo de ordenamiento por mezcla
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar las dos mitades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Fusionar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

//función printList, para imprimir los elementos de un vector
void printList(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

//función  para calcular la puntuación de similitud
int calculateSimilarityScore(const vector<int>& left, const vector<int>& right) {
    //se cuentan las ocurrencias de cada número en el array de la derecha
    unordered_map<int, int> frequencyMap;
    for (int num : right) {
        frequencyMap[num]++;
    }

    //y ahora con las anteriores ocurrencias calculas su puntuacion de similitud
    
    int similarityScore = 0;
    for (int num : left) {
        if (frequencyMap.find(num) != frequencyMap.end()) {
            similarityScore += num * frequencyMap[num];
        }
    }

    return similarityScore;
}

//función diferencia, calcula la diferencia entre dos vectores
void diferencia(const vector<int>& arr, const vector<int>& arr2) {

    if (arr.size() != arr2.size()) {
        std::cerr << "Error: Los vectores tienen tamaños diferentes. No se puede calcular la diferencia." << std::endl;
        return;
    }


    int suma = 0;
    int total = 0;


    std::cout << "Diferencias absolutas entre los vectores:" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        suma = abs(arr2[i] - arr[i]);
        total += suma;
        std::cout << "Diferencia[" << i << "] = |" << arr2[i] << " - " << arr[i] << "| = " << suma << std::endl;
    }

    std::cout << "\nLa suma total de diferencias es: " << total << std::endl;
}

