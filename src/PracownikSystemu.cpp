#include "PracownikSystemu.h"

PracownikSystemu::PracownikSystemu(int id, const std::string& imie, const std::string& nazwisko)
    : id(id), imie(imie), nazwisko(nazwisko) {}

int PracownikSystemu::getId() const { return id; }
std::string PracownikSystemu::getImie() const { return imie; }
std::string PracownikSystemu::getNazwisko() const { return nazwisko; }
