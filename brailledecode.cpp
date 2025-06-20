/**
 * - Projeto Bibloteca brailledecode
 * 
 * - Sobre o arquivo:
 * 
 *   . Nome: brailedecode.cpp
 *   . Objetivo do Arquivo: Adicionando as Propiedades das Funções Definidas no .h
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
 *   . Data: 14/08/2024
 *   . Versão: 2.0.0
 *   . Atualização: Adicionado a função getNumberCharacters() para impressão numerica
 */

//******************************** INICIO DO PROGRAMA ****************************************** */

#include "brailledecode.h" //chamada do Arquivo .h
#include "Arduino.h"        //chamada das funçoes do arduino
#include "letters.h" //chamada do arquivo letters.h que contem os arrays binarios do alfabeto
#include "numbers.h" //chamada do arquivo numbers.h que contem os arrays binarios dos numeros
#include "specialcharacters.h" //chamada do arquivo specialcharacters.h que contem os arrays binarios dos caracteres especiais

//******************************** FIM DA CHAMADA DOS ARQUIVOS ****************************************** */

static bool statePins[6] = {0}; // Array para Armazenar os Estado dos Botões permanentemente

Letters letras; // Instancia da classe Letters para acessar os arrays binarios do alfabeto
Numbers numeros; // Instancia da classe Numbers para acessar os arrays binarios dos numeros
SpecialCharacters especial; // Instancia da classe SpecialCharacters para acessar os arrays binarios dos caracteres especiais


BrailleDecode::BrailleDecode(const int buttonPins[6]) // Chamada da função principal do código
{    
     for(int i = 0; i < 6; i++){
          _buttonPins[i] = buttonPins;
          pinMode(_buttonPins[i], INPUT_PULLUP); // Define os pinos dos botões como entrada com pull-up
          statePins[i] = 0; // Inicializa o estado dos botões como 0 (não pressionado)
     }
}

String BrailleDecode::readBinarySequence() // Função de leitura dos botões que retorna o array binario
{
     _binString = ""; // Variavel de armazenamento do array binario

     for(int i = 0; i < 6; i++) //Verifica os 6 botões citado no array da pinagem
     {
         if(!digitalRead(_buttonPins[i]))statePins[i] = 1; //Verifica se o botão X foi pressionado se sim ele retorna 1
         binString += (statePins[i] ? '1' : '0');         // Concatenua o sinal do botao na string
     }
  
     return binString; // Retorna a String com array binario do botão

}



char BrailleDecode::decodeCharacter() // Função de impresssão do caractere alfabetico definido
{    
    
     for(int i = 0; i < 26; i++)     // Verifica todos os 26 arrays binario do bitletters
     {
        if(readBinarySequence() == letras.bit[i]) // Confirma se há algum array binario compativel com  o read() 
        {
          return letra.characther[i];   //  retorna o caractere alfabetico de acordo com indice
          break;                  // Se encontrado ele interrompe o loop para otimização
        }
        else if(readBinarySequence() == especial.NumberActivate)return '$';
     }
     return '*';                // Se não for encontrado nem um array compativel a função retornará 0

     resetState(); // Reseta todos os Botões

}

void BrailleDecode::resetState() // Função para resetar os estado de todos os botões
{   
     binString = "";          // reseta a string de armazenamento (Por segurança)
     for(int i = 0; i < 6; i++)statePins[i] = 0; // Reseta o estado de todos os botões

}

char BrailleDecode::decodeNumber() // Função de impresssão do caractere numerioco definido 
{    

     for(int i = 0; i < 10; i++)         // Verifica todos os array de A a j arrays binario bitletters
     {
          if(readBinarySequence() == numeros.bit[i])   // Confirma se há algum array binario compativel com  o read()
          {
               return numeros.characther[i];  //  retorna o caractere numerico de acordo com indice
               break;                 // Se encontrado ele interrompe o loop para otimização
          }
                 
     }
  
     return '*';                   // Se não for encontrado nem um array compativel a função retornará 0 

     resetState();  // Reseta todos os Botões
     
} 

// Fim da Função getCharacters()


// Fim da função reset()

//******************************** FIM DO PROGRAMA ****************************************** */