#pragma once
#include <string>
#include "Date.h"
#include "PracownikSystemu.h"

class Komentarz {
public:
    Komentarz(const std::string& tresc, const Date& data_utworzenia,
              PracownikSystemu* autor);

    std::string getTresc() const;
    Date getData() const;
    PracownikSystemu* getAutor() const;

private:
    std::string tresc_;
    Date data_utworzenia_;
    PracownikSystemu* autor_;
};
