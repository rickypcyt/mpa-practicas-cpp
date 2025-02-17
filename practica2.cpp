#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void EntradaSemillaElementos(int &semilla, int &n, int i);
void Insercion(int *V, int n, int &posInicial, int &posFinal);
void TiempoEjecucion(void (*func)());
void Posiciones(int &posInicial, int &posFinal, int &semilla, int i, int *V, int n);

void Posiciones(int &posInicial, int &posFinal, int &semilla, int i, int *V, int n){
    cout << "Posiciones inicial y final:\n";
    cout << "Inicial:";
    cin >> posInicial;
    cout << "Final:";
    cin >> posFinal;
    cout << "Vector sin Ordenar:\n";
    srand(semilla);
    for (int i = 1; i < n; i++) {  // Empezamos desde 0
        V[i] = rand();
    }
    for (int i = posInicial; i <= posFinal; i++) {
        if (i > posInicial) cout << ",";
        cout << V[i];  
    }
    cout << "\n";
}

void TiempoEjecucion(void (*func)()){
    clock_t tinicio, tfin;
    double tiempo;
    tinicio = clock(); // almacenamos el instante actual
    func();  // Llamamos a la función que mide el tiempo
    tfin = clock(); // almacenamos el instante actual
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000; // resultado en milisegundos
    cout << "El tiempo de ejecucion en ms es " << tiempo << endl;
}

// ordena ascendementemente un Vector V de tamano n
void Insercion(int *V, int n, int &posInicial, int &posFinal){
    cout << "Ordenado:";
    int j, x;
    for (int i = 2; i < n; i++){  // Empezamos desde 1
        x = V[i];
        j = i - 1;
        while (j >= 0 && V[j] > x){  // Comparamos V[j] con x
            V[j + 1] = V[j];  // Movemos los elementos hacia la derecha
            j = j - 1;
        }
        V[j + 1] = x;  // Colocamos el valor de x en su posición correcta
    }
    // Imprimimos el arreglo ordenado
    for (int i = posInicial; i <= posFinal; i++) {
        if (i > posInicial) cout << ",";
        cout << V[i];  
    }
    cout << "\n";
}

void EntradaSemillaElementos(int &semilla, int &n, int i){
    cout << "Introduce semilla: ";
    cin >> semilla;
    cout << "Introduce total de elementos a generar: ";
    cin >> n;
}

int main()
{
    int semilla, n, i;
    EntradaSemillaElementos(semilla, n, i);
    int *V = new int[n+1];  // Ajuste para que el arreglo tenga tamaño n (no n+1)

    int posInicial, posFinal;
    Posiciones(posInicial, posFinal, semilla, i, V, n);
    Insercion(V, n, posInicial, posFinal);

    delete[] V;  // Liberamos la memoria
    return 0;
}
