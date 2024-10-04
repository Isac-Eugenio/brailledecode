/**
 * - Projeto Bibloteca brailledecode
 * 
 * - Sobre o arquivo:
 * 
 *   . Nome: printNumbers.ino
 *
 *   . Objetivo do Arquivo: Exemplo para lib, adição numerica no codigo
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
 *   . Versão: 1.0.1
 * 
 */



#include "brailledecode.h" // Chamando a bibloteca brailledecode

#define Ok 10  // Botão para confirmação
#define res 11 // Botão para resetar os botões das células

BrailleDecode key(4, 5, 6, 7, 8, 9); // Definindo a pinagem dos botões

//******************* Inicio do Setup ******************************************************** */

void setup() // setup
{
   pinMode(Ok, INPUT_PULLUP); // Define o Botão Ok como pull-up
   pinMode(res, INPUT_PULLUP); // Define o Botão reset como pull-up

   Serial.begin(115200); // Ativa a Serial com a velocidade 115200 bits

   while(!Serial) continue; // Verifica se a serial ativou caso não ele reinicia a serial

   key.begin(); // Inicia os botões

} // fim do setup()

//******************* Fim do Setup ******************************************************** */

//******************* Inicio do Loop ****************************************************** */

void loop() //loop
{
  key.read(); //Inicia a Leitura dos botões

  if(!digitalRead(Ok)) // Se o Botão OK for pressionado
  {
    if(key.getCharacters() != '*' && key.getCharacters() != '$') // se a sequencia de botôes pressionado
    {                                                           //for compativel, printa a letra correspondente
                                                                
     Serial.println(""); // Pula linha
     Serial.print("LETRA: "); //print de texto complemetar
     Serial.println(key.getCharacters()); // printa o caracter compativel 
     Serial.println(""); // Pula linha

    }
  
    else if(key.getCharacters() == '$') // verifica se o modo numerico foi ativo
    {
      Serial.println(""); // Pula linha
      Serial.println("MODO NUMERICO ATIVO: "); //print de texto complemetar
      Serial.println(""); // Pula linha

      key.reset(); // reseta todos os botões
      while(true) // iniciar um novo loop
      {
        key.read(); // reseta todos os botões
        if(!digitalRead(Ok)) // verifica novamente o botao de confirmação
        {
          if(key.getNumberCharacters() != '*') // se a sequencia de botôes pressionado
          {                                   // for compativel, printa a letra correspondente
          
            Serial.print("NUMERO: "); //print de texto complemetar
            Serial.println(key.getNumberCharacters()); //Printa o caracter numerico compativel

            Serial.println(""); // Pula linha
            Serial.println("SAINDO DO MODO NUMERICO: "); //print de texto complemetar
            Serial.println(""); // Pula linha

            break; // interrompe o loop secundário
          }
        }

        else if(!digitalRead(res))  // se reset for pressionado ele interrompe o loop secundario

        {
          break;  // interrompe o loop secundário
        }
        
        delay(100); // delay para estabilizar o sistema

      }
    }

    else if(key.getCharacters() == '*' && key.getCharacters() != '$') Serial.println("code braile not found"); // Caso não, 
   // printa não encontrado
    key.reset(); // reseta todos os botões
  }

  else if(!digitalRead(res)) key.reset(); // se reset for pressionado ele reseta os botões

  delay(100);  // delay para estabilizar o sistema


} // fim do loop()
  
//******************* Fim do Loop ****************************************************** */

//************************************ FIM DO PROGRAMA ************************************* */
  
