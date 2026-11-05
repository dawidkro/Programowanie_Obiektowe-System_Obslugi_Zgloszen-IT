#include "WpisHistorii.h"

WpisHistorii::WpisHistorii(const Date& dataUtworzenia, const std::string& opisZmiany,
                           PracownikSystemu* autor)
    : dataUtworzenia(dataUtworzenia), opisZmiany(opisZmiany), autor(autor) {}

Date WpisHistorii::getData() const { return dataUtworzenia; }
std::string WpisHistorii::getOpisZmiany() const { return opisZmiany; }
PracownikSystemu* WpisHistorii::getAutor() const { return autor; }
