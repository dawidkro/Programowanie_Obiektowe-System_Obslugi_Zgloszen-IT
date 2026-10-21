#pragma once
#include <string>
#include "Date.h"
#include "PracownikSystemu.h"

class WpisHistorii {
private:
    Date dataUtworzenia;
    std::string opisZmiany;
    PracownikSystemu* autor;

public:
    WpisHistorii(const Date& dataUtworzenia, const std::string& opisZmiany, PracownikSystemu* autor);

    Date getData() const;
    std::string getOpisZmiany() const;
    PracownikSystemu* getAutor() const;
};
