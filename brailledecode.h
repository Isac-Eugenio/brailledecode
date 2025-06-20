/**
 * Projeto: Biblioteca BrailleDecode
 * 
 * Sobre o arquivo:
 *   - Nome: brailledecode.h
 *   - Objetivo: Definições da interface da biblioteca para conversão de padrões Braille em texto
 * 
 * Autor:
 *   - Isac Eugenio
 * 
 * Descrição:
 *   - Esta biblioteca converte uma sequência binária, baseada no padrão Braille, em texto legível.
 *   - Desenvolvida para uso com Arduino.
 * 
 * Informações da versão:
 *   - Data: 20/06/2025
 *   - Versão: 2.0.1
 */

#pragma once
// Ou use #ifndef BRAILLEDECODE_H ... #define ... #endif para compatibilidade máxima

#include <Arduino.h>  // Funções padrão do Arduino

// Classe principal da biblioteca
class BrailleDecode {

public:
    // Construtor
    BrailleDecode(const int buttonPins[6]);

    // Métodos públicos acessíveis ao usuário
    String read();                 // Lê o estado dos botões e retorna a sequência binária
    char decodeCharacter();       // Decodifica um caractere do alfabeto
    char decodeNumber();          // Decodifica um caractere numérico
    void reset();                 // Reinicializa os estados internos

    // (Opcional) Decodifica uma letra específica pelo índice - ainda não implementado
    char decodeLetter(int letterIndex);

private:
    int _buttonPins[6];   // Pinos conectados aos botões físicos
    String _binString;    // Armazena a sequência binária atual

};
