// letters.h
#pragma once
// ou use #ifndef LETTERS_H ... #endif se preferir compatibilidade máxima

// Biblioteca de caracteres alfabéticos do Braille padrão

namespace Letters {

    // Representação binária dos caracteres de A a Z no padrão Braille
    constexpr const char* bit[26] = {
        "100000", "110000", "100100", "100110", "100010", // A-E
        "110100", "110110", "110010", "010100", "010110", // F-J
        "101000", "111000", "101100", "101110", "101010", // K-O
        "111100", "111110", "111010", "011100", "011110", // P-T
        "101001", "111001", "010111", "101101", "101111", // U-Y
        "101011"                                           // Z
    };

    // Caracteres correspondentes em texto (letras minúsculas)
    constexpr char character[26] = {
        'a', 'b', 'c', 'd', 'e',
        'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y',
        'z'
    };

}
