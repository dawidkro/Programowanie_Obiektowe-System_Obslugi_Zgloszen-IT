#include "Date.h"

#include <ctime>

Date::Date(const std::string& data_tekst) : data_tekst_(data_tekst) {}

Date Date::teraz() {
    std::time_t czas = std::time(nullptr);
    char bufor[20] = {};
    std::strftime(bufor, sizeof(bufor), "%Y-%m-%d %H:%M:%S",
                  std::localtime(&czas));
    return Date(bufor);
}

std::string Date::toString() const {
    return data_tekst_;
}
