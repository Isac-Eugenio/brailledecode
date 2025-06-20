/**
 * - Projeto Bibloteca brailledecode
 * 
 * - Sobre o arquivo:
 * 
 *   . Nome: brailledecode.h
 *   . Objetivo do Arquivo: Definições dos objetos e metodos da bibloteca
 * 
 * - Autores :
 *   . Este arquivo define a interface da biblioteca BrailleDecode.
 *   . Responsável por converter uma sequência binária, baseada no padrão Braille, em texto legível.
 *   . Desenvolvido para uso com Arduino.
 *
 *   . Autor principal:
 *   . Isac Eugenio
 * 
 * - Objetivo:
 * 
 *   . Uma bibloteca que converta uma sequencia binaria seguindo o alfabeto Braille em texto
 * 
 * - Informações sobre essa versão:
 * 
 *   . Data: 20/06/2025
 *   . Versão: 2.0.1
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

    BrailleDecode(const int buttonPins[6]); // Construtor principal da classe
    String readBinarySequence();             // Lê o estado dos botões e retorna a sequência binária
    char decodeCharacter();                  // Decodifica e retorna o caractere correspondente
    char decodeLetter(int letterIndex);      // Decodifica e retorna a letra correspondente ao índice
    char decodeNumber();                     // Decodifica e retorna o número correspondente
    void resetState();                       // Reinicializa os dados internos

  // ********************** Fim das Funções Pública ********************************************************** */

  // ******************************* Funções Particulares ****************************************************
  
  // As funçoes e dados restrito ao Usuario

  private:

    int _buttonPins[6]; // Array para Armazenar os pinos dos botões para facilitar a manipulação
    String _binString;  // String que retorna a sequencia binaria dos botões

   // ******************************* Fim das Funções Particulares ****************************************************
   
}; 

//******************************************* Fim da classe ************************************************************ */


#endif //Fim das definições Padrões

//***************************************** Inicio do Programa ********************************************************** */
