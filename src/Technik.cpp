#include "Technik.h"
#include "Zgloszenie.h"

Technik::Technik(int id, const std::string& imie, const std::string& nazwisko)
    : PracownikSystemu(id, imie, nazwisko) {}


bool Technik::czyMaDostep(const Zgloszenie& /*zgloszenie*/) const {
    return false;
}
