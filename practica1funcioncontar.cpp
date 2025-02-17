#include <iostream>
using namespace std;
#include <stdlib.h>

void entradaVariables(int &n,int &x);
void generarVectorOG(int *V, int n, int x);
void generarVectorVpeor(int *V, int n, int x);
void generarVectorVmejor(int *V, int n, int x);
int Contar(int *V, int n, int x);
int ContarVectorSinX(int *V, int n, int x);

int main() {
  int n , x;
  entradaVariables(n, x);
  int *V = new int[n];

  generarVectorOG(V, n,x);

  generarVectorVpeor(V, n, x);
  generarVectorVmejor(V, n, x);

  delete[] V;  // Liberar memoria

  return 0;
}

void entradaVariables(int &n,int &x){
  cout << endl;
  cout << "Ingresa el valor de x:";
  cin >> x;

  cout << "Ingresa el valor de n:";
  cin >> n;
}

void generarVectorOG(int *V, int n, int x) {
  for (int i = 1; i <= n; i++) {
    V[i] = i;
  }
  cout << endl;

  cout << "Vector OG:" << endl;

  for (int i = 1; i <= n; i++) {
    cout << V[i] << " ";
  }
  cout << endl;
  cout << endl;

    int respuestaOG = Contar(V, n, x);

  cout << "En el vector OG: " << x << " aparece " << respuestaOG << " vez."
       << endl;

}

void generarVectorVpeor(int *V, int n, int x) {
  for (int i = 1; i <= n; i++) {
    V[i] = x;
  }
  cout << endl;

  cout << "Vector Caso Peor:" << endl;

  for (int i = 1; i <= n; i++) {
    cout << V[i] << " ";
  }
  cout << endl;
  cout << endl;

  int respuestaVpeor = Contar(V, n, x);

  cout << "En el caso peor: " << x << " aparece " << respuestaVpeor << " veces."
       << endl;

}

// tiene que ser que x sea omitido o sea que si i == x then omit x o i mas
void generarVectorVmejor(int *V, int n, int x) {

  for (int i = 1; i <= n; i++) {
    if (i != x) {
      V[i] = i;
    }
  }

  cout << endl;

  cout << "Vector Caso Mejor:" << endl;

  for (int i = 1; i <= n; i++) {
    if (i != x){
    cout << V[i] << " ";
    }
  }
  cout << endl;
  cout << endl;

  // Llamamos a la función Contar con el nuevo arreglo
    int respuestaVmejor = ContarVectorSinX(V, n, x);  // Usamos result, no V
  cout << "En el caso peor: " << x << " aparece " << respuestaVmejor << " veces."
       << endl;
}

int Contar(int *V, int n, int x) {
  int nveces;
  int i;

  // nveces = cuantas veces aparece x en el vector
  nveces = 0;

  for (i = 1; i <= n; i++) {
    if (V[i] == x) {
      nveces++;
    }
  }
  return nveces;
}

int ContarVectorSinX(int *V, int n, int x) {
  int nveces;
  int i;

  // nveces = cuantas veces aparece x en el vector
  nveces = 0;

  for (i = 1; i <= n; i++) {
    if (V[i] == x) {
      nveces = nveces +0;
    }
  }
  return nveces;
}