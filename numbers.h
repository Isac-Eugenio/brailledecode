// numbers.h
#pragma once
// ou use #ifndef NUMBERS_H ... #define NUMBERS_H ... #endif se preferir

// Biblioteca de caracteres numéricos do Braille padrão (A-J com prefixo de número)

namespace Numbers {

    // Representações binárias dos números de 1 a 0 (baseados nas letras A-J)
    constexpr const char* bit[10] = {
        "100000", "110000", "100100", "100110", "100010", // 1-5 (A-E)
        "110100", "110110", "110010", "010100", "010110"  // 6-9, 0 (F-J)
    };

    // Caracteres numéricos correspondentes
    constexpr char character[10] = {
        '1', '2', '3', '4', '5',
        '6', '7', '8', '9', '0'
    };

}
