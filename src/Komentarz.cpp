#include "Komentarz.h"

Komentarz::Komentarz(const std::string& tresc, const Date& data_utworzenia,
                     PracownikSystemu* autor)
    : tresc_(tresc), data_utworzenia_(data_utworzenia), autor_(autor) {}

std::string Komentarz::getTresc() const { return tresc_; }
Date Komentarz::getData() const { return data_utworzenia_; }
PracownikSystemu* Komentarz::getAutor() const { return autor_; }
