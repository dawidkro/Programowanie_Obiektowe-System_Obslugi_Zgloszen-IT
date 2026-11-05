#include "Zglaszajacy.h"
#include "Zgloszenie.h"

Zglaszajacy::Zglaszajacy(int id, const std::string& imie, const std::string& nazwisko)
    : PracownikSystemu(id, imie, nazwisko) {}

// TODO (polimorfizm, US6, US7): zglaszajacy ma dostep tylko do wlasnych zgloszen.
//      Porownaj autora zgloszenia (zgloszenie.getZglaszajacy()) z tym obiektem (this).
bool Zglaszajacy::czyMaDostep(const Zgloszenie& /*zgloszenie*/) const {
    return false;
}
