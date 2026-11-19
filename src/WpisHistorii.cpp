#include "WpisHistorii.h"

WpisHistorii::WpisHistorii(const Date& data_utworzenia,
                           const std::string& opis_zmiany,
                           PracownikSystemu* autor)
    : data_utworzenia_(data_utworzenia),
      opis_zmiany_(opis_zmiany),
      autor_(autor) {}

Date WpisHistorii::getData() const { return data_utworzenia_; }
std::string WpisHistorii::getOpisZmiany() const { return opis_zmiany_; }
PracownikSystemu* WpisHistorii::getAutor() const { return autor_; }
