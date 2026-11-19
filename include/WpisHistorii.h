#pragma once
#include <string>
#include "Date.h"
#include "PracownikSystemu.h"

class WpisHistorii {
public:
    WpisHistorii(const Date& data_utworzenia, const std::string& opis_zmiany,
                 PracownikSystemu* autor);

    Date getData() const;
    std::string getOpisZmiany() const;
    PracownikSystemu* getAutor() const;

private:
    Date data_utworzenia_;
    std::string opis_zmiany_;
    PracownikSystemu* autor_;
};
