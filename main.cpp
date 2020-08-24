#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std; //Para no tener que escribir siempre std::


void incrementa(int *variable) {
  (*variable)++;
}

int main() {
  
  int * apuntador = NULL;
  cout << apuntador << endl;
  
  
  int mi_numero = 50;
  apuntador = &mi_numero;
  cout << *apuntador << endl;
  //printf("\n%p\n", &mi_numero);

  double arreglo[50];
  cout << arreglo << endl;
  cout << &arreglo[1] << endl;
  cout << &arreglo[2] << endl;
  scanf("%*c");
  
  //Ya junciona :3
  int numero = 5;
  incrementa(&numero);
  cout << numero << endl;

  


  //printf("Hola mundo!\n");
  cout << "Hola mundo!\n" << "Cuantos alumnos son: "; //cout: console out
  int alumnos = 0;
  
  //scanf("%i%*c", &alumnos);
  cin >> alumnos;//cin: console in

  cout << "Somos " << alumnos << "\n";
  float promedio = 95.5;
  cout << promedio << endl; //endl: end line

  //cerr: console error

  return 0;
}