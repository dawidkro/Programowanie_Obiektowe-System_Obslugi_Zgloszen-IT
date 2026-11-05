#include "Date.h"

Date::Date(const std::string& dataTekst) : dataTekst(dataTekst) {}

std::string Date::toString() const {
    return dataTekst;
}
