#pragma once
#include <string>
#include "Date.h"
#include "PracownikSystemu.h"

class Komentarz {
private:
    std::string tresc;
    Date dataUtworzenia;
    PracownikSystemu* autor;

public:
    Komentarz(const std::string& tresc, const Date& dataUtworzenia, PracownikSystemu* autor);

    std::string getTresc() const;
    Date getData() const;
    PracownikSystemu* getAutor() const;
};
