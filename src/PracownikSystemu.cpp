#include "PracownikSystemu.h"

PracownikSystemu::PracownikSystemu(int id, const std::string& imie,
                                   const std::string& nazwisko)
    : id_(id), imie_(imie), nazwisko_(nazwisko) {}

int PracownikSystemu::getId() const { return id_; }
std::string PracownikSystemu::getImie() const { return imie_; }
std::string PracownikSystemu::getNazwisko() const { return nazwisko_; }
