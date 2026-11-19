#include "Administrator.h"
#include "Zgloszenie.h"

Administrator::Administrator(int id, const std::string& imie,
                             const std::string& nazwisko)
    : PracownikSystemu(id, imie, nazwisko) {}

// Administrator nadzoruje caly system, wiec ma dostep do kazdego zgloszenia.
bool Administrator::czyMaDostep(const Zgloszenie& /*zgloszenie*/) const {
    return true;
}
