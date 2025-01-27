// SolucionParalela_LopezGomez.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

using namespace std;

#define N 1000
#define chunk 100
#define mostrar 11

void imprimeArreglo(float *d);

int main()
{
    cout << "|-------------------------------------------|" << endl;
    cout << "|       Sumando Arreglos en Paralelo!       |" << endl;
    cout << "|-------------------------------------------|\n" << endl;

    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i + 10;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

        cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << endl;
        imprimeArreglo(a);
        cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << endl;
        imprimeArreglo(b);
        cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << endl;
        imprimeArreglo(c);
}

void imprimeArreglo(float *d) 
{
    for (int x = 0; x < mostrar; x++)
        cout << d[x] << " - ";
    cout << endl;
}

