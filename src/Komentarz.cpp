#include "Komentarz.h"

Komentarz::Komentarz(const std::string& tresc, const Date& dataUtworzenia, PracownikSystemu* autor)
    : tresc(tresc), dataUtworzenia(dataUtworzenia), autor(autor) {}

std::string Komentarz::getTresc() const { return tresc; }
Date Komentarz::getData() const { return dataUtworzenia; }
PracownikSystemu* Komentarz::getAutor() const { return autor; }
