/**
 * Projeto: Biblioteca BrailleDecode
 * 
 * Arquivo: printLetters.ino
 * Objetivo: Exemplo de uso da biblioteca BrailleDecode para imprimir letras do alfabeto Braille
 * 
 * Autor: Isac Eugenio da Silva Santos
 * 
 * Data: 31/07/2024
 * Versão: 1.0.0
 */

//************************************ INÍCIO DO PROGRAMA *************************************/

#include "brailledecode.h"  // Inclusão da biblioteca BrailleDecode

#define OK   2   // Pino do botão de confirmação
#define RES  3   // Pino do botão de reset

const int pinos[6] = {4, 5, 6, 7, 8, 9}; // Pinos conectados aos botões da célula Braille
BrailleDecode key(pinos);               // Instância da classe BrailleDecode

//************************************ CONFIGURAÇÃO INICIAL ***********************************/

void setup()
{ 
    pinMode(RES, INPUT_PULLUP); // Configura botão de reset como entrada pull-up
    pinMode(OK, INPUT_PULLUP);  // Configura botão OK como entrada pull-up
    Serial.begin(115200);       // Inicializa comunicação serial

    while (!Serial);            // Aguarda ativação da porta serial (útil para placas como Leonardo)
}

//************************************ LOOP PRINCIPAL *****************************************/

void loop()
{
    key.read(); // Lê o estado atual dos botões

    if (!digitalRead(OK)) // Se o botão OK for pressionado
    {
        char letra = key.decodeCharacter(); // Decodifica a letra atual

        if (letra != '*')
        {
            Serial.print(letra); // Imprime a letra correspondente
        }
        else
        {
            Serial.println("Codigo Braille não reconhecido."); // Mensagem de erro
        }

        key.reset();       // Reseta os estados dos botões
        Serial.println();  // Pula linha
        delay(300);        // Evita múltiplas leituras no mesmo clique
    }

    if (!digitalRead(RES))
    {
        key.reset();       // Reset manual via botão
        Serial.println("Reset realizado.");
        delay(300);        // Debounce
    }

    delay(100); // Delay para estabilidade geral
}

//************************************ FIM DO PROGRAMA ***************************************/
