// specialcharacters.h
#pragma once
// ou use #ifndef SPECIALCHARACTERS_H ... #define ... #endif

// Biblioteca de caracteres especiais do Braille padrão

namespace SpecialCharacters {

    // Prefixo para indicar modo numérico (⠼)
    constexpr const char* NumberActivate = "001111";

    // Representação do ponto decimal (.)
    constexpr const char* NumberDecimal  = "010000";

    // Prefixo para letras maiúsculas (⠠)
    constexpr const char* UpperCase      = "000001";

}
