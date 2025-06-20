/**
 * - Projeto Bibloteca brailledecode
 * 
 * - Sobre o arquivo:
 * 
 *   . Nome: brailledecode.h
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
 *   . Versão: 2.0.0
 *   . Atualização: Adicionado a função getNumberCharacters() para impressão numerica
 */

//******************************** Inicio do Programa **************************************** */

//Definições padrão do sistema

#ifndef BRAILLEDECODE_H
#define BRAILLEDECODE_H

//Chamando as funçoes padrões da Arduino

#include "Arduino.h"

//******************************** Fim das Definições Padrões **************************************** */

//************************ Inicio da classe ************************************************************** */

// Cria um objeto onde está as propiedades da bibloteca

class BrailleDecode {

  // ****************************** Funções Publica ********************************************************

  // As funçoes e dados que o usuario terá acesso 

  public:
    
    BrailleDecode(const int pins[6]); // Função principal da classe
    String read();    // Função de leitura do array de botões
    char getCharacters(), getletters(int letter), getNumberCharacters(); // Funções que imprimem a letra para usuario
    void reset();                                    // Função de inicializão e reset dos dados

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

    }; // fim do Arra

   // ******************************* Fim das Funções Particulares ****************************************************
   
}; 

//******************************************* Fim da classe ************************************************************ */


#endif //Fim das definições Padrões

//***************************************** Inicio do Programa ********************************************************** */
