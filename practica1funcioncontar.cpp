#include <iostream>
using namespace std;
#include <stdlib.h>

// Declaraciones de funciones
void entradaVariables(int &n,int &x);
void generarVectorOG(int *V, int n, int x);
void generarVectorVpeor(int *V, int n, int x);
void generarVectorVmejor(int *V, int n, int x);
int Contar(int *V, int n, int x);
int ContarVectorSinX(int *V, int n, int x);

int main() {
  int n , x;
  entradaVariables(n, x);  // Obtiene valores de n y x del usuario
  int *V = new int[n];  // Crea un array dinámico de tamaño n

  generarVectorOG(V, n,x);  // Genera y muestra el vector original
  generarVectorVpeor(V, n, x);  // Genera y muestra el vector para el peor caso
  generarVectorVmejor(V, n, x);  // Genera y muestra el vector para el mejor caso

  delete[] V;  // Libera la memoria asignada dinámicamente

  return 0;
}

// Función para obtener los valores de n y x del usuario
void entradaVariables(int &n,int &x){
  cout << endl;
  cout << "Ingresa el valor de x:";
  cin >> x;
  cout << "Ingresa el valor de n:";
  cin >> n;
}

// Función para generar y mostrar el vector original
void generarVectorOG(int *V, int n, int x) {
  // Llena el vector con valores de 1 a n
  for (int i = 1; i <= n; i++) {
    V[i] = i;
  }
  cout << endl << "Vector OG:" << endl;
  // Muestra el vector
  for (int i = 1; i <= n; i++) {
    cout << V[i] << " ";
  }
  cout << endl << endl;

  // Cuenta las ocurrencias de x en el vector
  int respuestaOG = Contar(V, n, x);
  cout << "En el vector OG: " << x << " aparece " << respuestaOG << " vez." << endl;
}

// Función para generar y mostrar el vector del peor caso (todos los elementos son x)
void generarVectorVpeor(int *V, int n, int x) {
  // Llena el vector con x
  for (int i = 1; i <= n; i++) {
    V[i] = x;
  }
  cout << endl << "Vector Caso Peor:" << endl;
  // Muestra el vector
  for (int i = 1; i <= n; i++) {
    cout << V[i] << " ";
  }
  cout << endl << endl;

  // Cuenta las ocurrencias de x en el vector
  int respuestaVpeor = Contar(V, n, x);
  cout << "En el caso peor: " << x << " aparece " << respuestaVpeor << " veces." << endl;
}

// Función para generar y mostrar el vector del mejor caso (x no aparece)
void generarVectorVmejor(int *V, int n, int x) {
  // Llena el vector con valores de 1 a n, omitiendo x
  for (int i = 1; i <= n; i++) {
    if (i != x) {
      V[i] = i;
    }
  }

  cout << endl << "Vector Caso Mejor:" << endl;
  // Muestra el vector, omitiendo la posición x
  for (int i = 1; i <= n; i++) {
    if (i != x){
      cout << V[i] << " ";
    }
  }
  cout << endl << endl;

  // Cuenta las ocurrencias de x en el vector (que deberían ser 0)
  int respuestaVmejor = ContarVectorSinX(V, n, x);
  cout << "En el caso mejor: " << x << " aparece " << respuestaVmejor << " veces." << endl;
}

// Función para contar las ocurrencias de x en el vector
int Contar(int *V, int n, int x) {
  int nveces = 0;
  for (int i = 1; i <= n; i++) {
    if (V[i] == x) {
      nveces++;
    }
  }
  return nveces;
}

// Función para contar las ocurrencias de x en el vector (siempre retorna 0)
int ContarVectorSinX(int *V, int n, int x) {
  int nveces = 0;
  for (int i = 1; i <= n; i++) {
    if (V[i] == x) {
      nveces = nveces + 0;  // Esta línea no tiene efecto, nveces siempre será 0
    }
  }
  return nveces;
}
