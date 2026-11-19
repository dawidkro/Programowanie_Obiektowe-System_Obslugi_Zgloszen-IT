#pragma once
#include <string>
enum class Priorytet {
    NISKI,
    SREDNI,
    WYSOKI,
    BARDZO_WYSOKI
};

std::string priorytetNaTekst(Priorytet priorytet);
