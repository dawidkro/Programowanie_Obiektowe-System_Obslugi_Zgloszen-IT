#include "Status.h"

std::string statusNaTekst(Status status) {
    switch (status) {
        case Status::NOWE:
            return "Nowe";
        case Status::W_TRAKCIE:
            return "W trakcie";
        case Status::OCZEKUJE:
            return "Oczekuje";
        case Status::ROZWIAZANE:
            return "Rozwiazane";
    }
    return "Nieznany";
}
