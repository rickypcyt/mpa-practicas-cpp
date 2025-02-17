#include <iostream>
using namespace std;

// Función que cuenta cuántas veces aparece 'num' en el arreglo
int contarOcurrencias(int arr[], int tam, int num) {
    int nveces = 0;  // Inicializamos el contador en 0
    for (int i = 0; i < tam; i++) {  
        if (arr[i] == num) {  // Si encontramos el número en el arreglo
            nveces++;  // Aumentamos el contador
        }
    }
    return nveces;  // Retornamos cuántas veces aparece
}

int main() {
    int numeros[] = {1, 3, 4, 3, 2, 3, 5, 3, 6};  // Arreglo con números
    int tamaño = sizeof(numeros) / sizeof(numeros[0]);  // Calculamos el tamaño del arreglo
    int numeroBuscado = 3;  // Número que queremos contar

    // Llamamos a la función y guardamos el resultado en 'nveces'
    int nveces = contarOcurrencias(numeros, tamaño, numeroBuscado);

    // Imprimimos el resultado
    cout << "El número " << numeroBuscado << " aparece " << nveces << " veces en el arreglo." << endl;

    return 0;
}
