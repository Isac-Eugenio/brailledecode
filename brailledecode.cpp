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

static bool statePins[6] = {0}; // Array para Armazenar os Estado dos Botões permanentemente


BrailleDecode::BrailleDecode(int pin0, int pin1, int pin2, int pin3, int pin4, int pin5) // Chamada da função principal do código
{    
     // Move a pinagem dos botões para um array global, assim sendo possivel ser usado em outras funções

     buttonPins[0] = pin0; // Move o  pino 0 para o a posição 0 do array
     buttonPins[1] = pin1; // Move o  pino 1 para o a posição 1 do array
     buttonPins[2] = pin2; // Move o  pino 2 para o a posição 3 do array
     buttonPins[3] = pin3; // Move o  pino 4 para o a posição 5 do array
     buttonPins[4] = pin4; // Move o  pino 6 para o a posição 6 do array
     buttonPins[5] = pin5; // Move o  pino 7 para o a posição 7 do array
}

// fim da função principal

void BrailleDecode::begin() // Função de inicialização 
{
     for(int i = 0; i < 6; i++)pinMode(buttonPins[i], INPUT_PULLUP); // definindo todos os botões como pull-up
}

String BrailleDecode::read() // Função de leitura dos botões que retorna o array binario
{
  binString = ""; // Variavel de armazenamento do array binario

     for(int i = 0; i < 6; i++) //Verifica os 6 botões citado no array da pinagem
     {
         if(!digitalRead(buttonPins[i]))statePins[i] = 1; //Verifica se o botão X foi pressionado se sim ele retorna 1
         binString += (statePins[i] ? '1' : '0');         // Concatenua o sinal do botao na string
     }
  
     return binString; // Retorna a String com array binario do botão

}

char BrailleDecode::getNumberCharacters() // Função de impresssão do caractere numerioco definido 
{    

     for(int i = 0; i < 10; i++)         // Verifica todos os array de A a j arrays binario bitletters
     {
          if(read() == bitletters[i])   // Confirma se há algum array binario compativel com  o read()
          {
               return charNumbers[i];  //  retorna o caractere numerico de acordo com indice
               break;                 // Se encontrado ele interrompe o loop para otimização
          }
                 
     }
  
     return '*';                   // Se não for encontrado nem um array compativel a função retornará 0 

     reset();  // Reseta todos os Botões
     
} 

// Fim da Função getCharacters()

char BrailleDecode::getCharacters() // Função de impresssão do caractere alfabetico definido
{    
    
     for(int i = 0; i < 26; i++)     // Verifica todos os 26 arrays binario do bitletters
     {
        if(read() == bitletters[i]) // Confirma se há algum array binario compativel com  o read() 
        {
          return charletters[i];   //  retorna o caractere alfabetico de acordo com indice
          break;                  // Se encontrado ele interrompe o loop para otimização
        }
        else if(read() == numberActivate)return '$';
     }
     return '*';                // Se não for encontrado nem um array compativel a função retornará 0

     reset(); // Reseta todos os Botões

}

// Fim da Função getCharacters()

char BrailleDecode::getletters(int letters) // Função de printagem manual do caractere do alfabeto
{
   return charletters[letters]; // retorna o caracter
}

void BrailleDecode::reset() // Função para resetar os estado de todos os botões
{   
     binString = "";          // reseta a string de armazenamento (Por segurança)
     for(int i = 0; i < 6; i++)statePins[i] = 0; // Reseta o estado de todos os botões

}

// Fim da função reset()

//******************************** FIM DO PROGRAMA ****************************************** */
