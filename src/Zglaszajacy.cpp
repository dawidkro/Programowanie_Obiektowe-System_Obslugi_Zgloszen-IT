#include "Zglaszajacy.h"
#include "Zgloszenie.h"

Zglaszajacy::Zglaszajacy(int id, const std::string& imie, const std::string& nazwisko)
    : PracownikSystemu(id, imie, nazwisko) {}


bool Zglaszajacy::czyMaDostep(const Zgloszenie& /*zgloszenie*/) const {
    return false;
}
