#include "Administrator.h"
#include "Zgloszenie.h"

Administrator::Administrator(int id, const std::string& imie, const std::string& nazwisko)
    : PracownikSystemu(id, imie, nazwisko) {}

// TODO (polimorfizm, US4): administrator ma dostep do wszystkich zgloszen.
bool Administrator::czyMaDostep(const Zgloszenie& /*zgloszenie*/) const {
    return false;
}
