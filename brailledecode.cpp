/ **
 * - Projeto: Biblioteca BrailleDecode
 * 
 * - Sobre o Arquivo:
 *   . Nome: brailedecode.cpp
 *   . Objetivo: Definir as funcionalidades das funções declaradas no cabeçalho .h
 * 
 * - Autor:
 *   . Isac Eugenio da Silva Santos
 * 
 * - Objetivo Geral:
 *   . Converter uma sequência binária representando caracteres Braille em texto
 * 
 * - Informações da Versão:
 *   . Data: 14/08/2024
 *   . Versão: 2.0.0
 *   . Atualização: Adicionada a função decodeNumber() para suporte numérico
 */

// ******************************** INÍCIO DO PROGRAMA ******************************************

#include "brailledecode.h"           // Cabeçalho principal da biblioteca
#include "Arduino.h"                 // Funções do Arduino
#include "letters.h"                 // Arrays binários do alfabeto
#include "numbers.h"                 // Arrays binários dos números
#include "specialcharacters.h"      // Arrays de caracteres especiais

// ******************************** VARIÁVEIS GLOBAIS ********************************************

static bool statePins[6] = {0};     // Estados dos botões

// ******************************** IMPLEMENTAÇÃO DAS FUNÇÕES ***********************************

BrailleDecode::BrailleDecode(const int buttonPins[6])
{
    for (int i = 0; i < 6; i++)
    {
        _buttonPins[i] = buttonPins[i];
        pinMode(_buttonPins[i], INPUT_PULLUP);
        statePins[i] = 0;
    }
}

String BrailleDecode::read()
{
    _binString = "";

    for (int i = 0; i < 6; i++)
    {
        if (!digitalRead(_buttonPins[i]))
        {
            statePins[i] = 1;
        }

        _binString += (statePins[i] ? '1' : '0');
    }

    return _binString;
}

char BrailleDecode::decodeCharacter()
{
    String currentBin = read();

    for (int i = 0; i < 26; i++)
    {
        if (currentBin == Letters::bit[i])
        {
            reset();
            return Letters::character[i];
        }
    }

    if (currentBin == SpecialCharacters::NumberActivate)
    {
        reset();
        return '$';
    }

    reset();
    return '*'; // Caractere não reconhecido
}

char BrailleDecode::decodeNumber()
{
    String currentBin = read();

    for (int i = 0; i < 10; i++)
    {
        if (currentBin == Numbers::bit[i])
        {
            reset();
            return Numbers::character[i];
        }
    }

    reset();
    return '*'; // Número não reconhecido
}

void BrailleDecode::reset()
{
    _binString = "";

    for (int i = 0; i < 6; i++)
    {
        statePins[i] = 0;
    }
}

// ******************************** FIM DO PROGRAMA *********************************************
