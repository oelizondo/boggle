//
//  main.cpp
//  boogle
//
//  Created by Oscar Elizondo on 11/20/15.
//  Copyright © 2015 Oscar Elizondo. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

char boggleMat[6][6] = {{ ';' }};
char matRepuesto[6][6] = {{ ';' }};
int numDeJuegos;

void resetMat() {
  
  for (int i = 0; i < 6; i++) {
    
    for (int j = 0; j < 6; j++) {
      
      boggleMat[i][j] = matRepuesto[i][j];
      
    }
    
  }

}

int buscaLetra(string sPalabra, int iCol, int iReng, int contador) {
  
  if (contador < sPalabra.length()) {
    
    char sSuplente = sPalabra[contador];
    
    for (int i = iCol-1; i <= iCol+1; i++) {
      
      for (int j = iReng-1; j <= iReng+1; j++) {
        
        if (boggleMat[i][j] == sSuplente) {
          
          boggleMat[i][j] = ';';

          int breaker = buscaLetra(sPalabra, i, j, contador+1);
          
          if (breaker != 0) { return breaker; }
          
          else { boggleMat[i][j] = sSuplente; }

        }

      }

    }
    
    return 0;

  }
  
  else { return 1; }
  
}

int recorreMatriz(string sPalabra) {

  for (int i = 1; i < 5; i++) {
    
    for (int j = 1; j < 5; j++) {
      
      if (boggleMat[i][j] == sPalabra[0]) {
        
        boggleMat[i][j] = ';';
        
        int breaker = buscaLetra(sPalabra, i, j, 1);
        
        if (breaker != 0) { return breaker; }
        
        else { boggleMat[i][j] = sPalabra[0]; }

      }
      
    }
    
  }

  return 0;
  
}


void iniciarJuego() {

  int cantPalabras;
  char chInput;
  string sPalabra;
  string arrPalabras[20];
  
  cin >> numDeJuegos;
  
  for (int juegos = 1; juegos <= numDeJuegos; juegos++) {
    
    int puntos = 0;

    for (int i = 1; i < 5; i++){
      
      for (int j = 1; j < 5; j++){
        
        cin >> chInput;
        boggleMat[i][j] = chInput;
        matRepuesto[i][j] = chInput;

      }
      
    }

    cin >> cantPalabras;
  
    for (int i = 0; i < cantPalabras; i++) {
      
      cin >> sPalabra;
      arrPalabras[i] = sPalabra;
      
    }
    
    for (int i = 0; i < cantPalabras; i++) {
      
      int puntuacion = recorreMatriz(arrPalabras[i]);
      
      if (puntuacion > 0) {
        
        switch (arrPalabras[i].length()) {
          case 3:
            puntos++;
            break;
          case 4:
            puntos++;
            break;
          case 5:
            puntos += 2;
            break;
          case 6:
            puntos += 3;
            break;
          case 7:
            puntos += 5;
            break;
          default:
            puntos += 11;
            break;
        }
      }
      
      resetMat();
    }
    
    cout << "Game " << juegos << ": " << puntos << endl;
    
  }

}

int main () {
  
  iniciarJuego();

  return 0;
}












