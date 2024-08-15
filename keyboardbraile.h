/**
 * - Projeto Bibloteca keyboardbraile
 * 
 * - Sobre o arquivo:
 * 
 *   . Nome: keyboardbraile.h
 *   . Objetivo do Arquivo: Definições dos objetos e metodos da bibloteca
 * 
 * - Autores :
 *  
 *   . Isac Eugenio da Silva Santos
 * 
 * - Objetivo:
 * 
 *   . Uma bibloteca que converta uma sequencia binaria seguindo o alfabeto Braille em texto
 * 
 * - Informações sobre essa versão:
 * 
 *   . Data: 14/08/2024s
 *   . Versão: 1.0.1
 *   . Atualização: Adicionado a função getNumberCharacters() para impressão numerica
 */

//******************************** Inicio do Programa **************************************** */

//Definições padrão do sistema

#ifndef KEYBOARDBRAILLE_H
#define KEYBOARDBRAILLE_H

//Chamando as funçoes padrões da Arduino

#include "Arduino.h"

//************************ Inicio da classe ************************************************************** */

// Cria um objeto onde está as propiedades da bibloteca

class KeyboardBraille {

  // ****************************** Funções Publica ********************************************************

  // As funçoes e dados que o usuario terá acesso 

  public:
    
    KeyboardBraille(int pin0, int pin1, int pin2, int pin3, int pin4, int pin5);   // Função principal da classe
    String read(), numberActivate = "001111", numberDecimal = "010000";            // Função de leitura do array de botões
    char getCharacters(), getletters(int letter), getNumberCharacters(); // Funções que imprimem a letra para usuario
    void begin(), reset();                                                         // Função de inicializão e reset dos dados

  // ********************** Fim das Funções Pública ********************************************************** */

  // ******************************* Funções Particulares ****************************************************
  
  // As funçoes e dados restrito ao Usuario

  private:

    int buttonPins[6]; // Array para Armazenar os pinos dos botões para facilitar a manipulação
    String binString;  // String que retorna a sequencia binaria dos botões

    const String bitletters[26] = // Array binario que segue o padrão em Braille
    {
      
      "100000", "110000", "100100", "100110", "100010", // de A a E
      "110100", "110110", "110010", "010100", "010110", // de F a J
      "101000", "111000", "101100", "101110", "101010", // de K a O
      "111100", "111110", "111010", "011100", "011110", // de P a T
      "101001", "111001", "010111", "101101", "101111", // de U a Y
                          "101011" // Z

    }; // fim do Array

    const String bitSpecialCharacters[9] = {};

    const char charletters[26] = // Array de caracteres do alfabeto
    {
       'A', 'B', 'C', 'D', 'E',  // de A a E
       'F', 'G', 'H', 'I', 'J',  // de F a J
       'K', 'L', 'M', 'N', 'O',  // de K a o
       'P', 'Q', 'R', 'S', 'T',  // de P a T
       'U', 'V', 'W', 'X', 'y',  // de U a Y
                 'z'             // de U a Y

    }; // fim do Array

    const char charNumbers[10] = 
    {
       '1', '2', '3', '4', '5',  // de 1 a 5
       '6', '7', '8', '9', '0'   // de 6 a 9 mais 0 = j

    }; // fim do Array
    
    const char charSpecialCharacters[9] = {}; //Adições Futuras

   // ******************************* Fim das Funções Particulares ****************************************************
   
}; 

//******************************************* Fim da classe ************************************************************ */


#endif //Fim das definições Padrões

//***************************************** Inicio do Programa ********************************************************** */

