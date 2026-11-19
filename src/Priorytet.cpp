#include "Priorytet.h"

std::string priorytetNaTekst(Priorytet priorytet) {
    switch (priorytet) {
        case Priorytet::NISKI:
            return "Niski";
        case Priorytet::SREDNI:
            return "Sredni";
        case Priorytet::WYSOKI:
            return "Wysoki";
        case Priorytet::BARDZO_WYSOKI:
            return "Bardzo wysoki";
    }
    return "Nieznany";
}
