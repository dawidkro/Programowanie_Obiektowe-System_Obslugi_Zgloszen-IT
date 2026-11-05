#include "Technik.h"
#include "Zgloszenie.h"

Technik::Technik(int id, const std::string& imie, const std::string& nazwisko)
    : PracownikSystemu(id, imie, nazwisko) {}

// TODO (polimorfizm, US4): technik ma dostep tylko do zgloszen przydzielonych jemu.
//      Porownaj technika zgloszenia (zgloszenie.getTechnik()) z tym obiektem (this).
//      Przy implementacji odkomentuj nazwe parametru.
bool Technik::czyMaDostep(const Zgloszenie& /*zgloszenie*/) const {
    return false;
}
