/**
 * - Projeto Bibloteca brailledecode
 * 
 * - Sobre o arquivo:
 * 
 *   . Nome: printLetters
 *   . Objetivo do Arquivo: Arquivo exemplo da bibloteca onde printa a letra correspodente
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
 *   . Data: 31/07/2024
 *   . Versão: 1.0.0
 */

//************************************ INICIO DO PROGRAMA ************************************* */

#include "brailledecode.h" // Chamando a bibloteca brailledecode

#define OK 2               // Botão para confirmação 
#define res 3             // Botão para resetar os botões da célula
 

BrailleDecode key(4,5,6,7,8,9);
//******************* Inicio do Setup ******************************************************** */

void setup() // setup
{ 
  pinMode(res,INPUT_PULLUP); // Define o Botão Ok como pull-up
  pinMode(OK,INPUT_PULLUP);  // Define o Botão reset como pull-up
  Serial.begin(115200);      // Ativa a Serial com a velocidade 115200 bits
  while(!Serial) continue;   // Verifica se a serial ativou caso não ele reinicia a serial
  key.begin();               // Inicia os botões

}

//******************* Fim do Setup ******************************************************** */

//******************* Inicio do Loop ****************************************************** */

void loop() //loop
{

  key.read(); //Inicia a Leitura dos botões

  if(!digitalRead(OK)) // Se o Botão OK for pressionado 
  {
    if(key.getCharacters() != '0')Serial.print(key.getCharacters()); // se a sequencia de botão for compativel printa a letra correspondente
    else Serial.println("code braile not found"); // Caso não printa não encontrado
    key.reset(); // reseta todos os botões
    Serial.println(); // pula linha 

  }
  
  if(!digitalRead(res))key.reset(); // se reset for pressionado ele reseta os botões

  delay(100); // delay para estabilizar o sistema

}

//******************* Fim do Loop ****************************************************** */

//************************************ FIM DO PROGRAMA ************************************* */