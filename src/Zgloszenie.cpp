#include "Zgloszenie.h"

#include <ctime>


namespace {

std::string aktualnaData() {
    std::time_t teraz = std::time(nullptr);
    char bufor[20];
    std::strftime(bufor, sizeof(bufor), "%Y-%m-%d %H:%M", std::localtime(&teraz));
    return bufor;
}

[[maybe_unused]] std::string nazwaStatusu(Status status) {
    switch (status) {
        case Status::NOWE:       return "NOWE";
        case Status::W_TRAKCIE:  return "W_TRAKCIE";
        case Status::OCZEKUJE:   return "OCZEKUJE";
        case Status::ROZWIAZANE: return "ROZWIAZANE";
    }
    return "?";
}

} 


Zgloszenie::Zgloszenie(int id, const std::string& opis, Priorytet priorytet,
                       const KategoriaProblemu& kategoria, Zglaszajacy* zglaszajacy)
    : id(id), opis(opis), status(Status::NOWE), priorytet(priorytet),
      kategoria(kategoria), zglaszajacy(zglaszajacy), technik(nullptr) {

    dodajWpisHistorii("Utworzono zgłoszenie", zglaszajacy);
}
void Zgloszenie::dodajWpisHistorii(const std::string& opisZmiany, PracownikSystemu* autor) {
    historia.emplace_back(Date(aktualnaData()), opisZmiany, autor);
}

std::vector<WpisHistorii> Zgloszenie::pobierzHistorieWpisow() const { return historia; }
std::vector<Komentarz> Zgloszenie::pobierzKomentarze() const { return komentarze; }

int Zgloszenie::getId() const { return id; }
Status Zgloszenie::getStatus() const { return status; }
std::string Zgloszenie::getOpis() const { return opis; }
KategoriaProblemu Zgloszenie::getKategoria() const { return kategoria; }
Priorytet Zgloszenie::getPriorytet() const { return priorytet; }
Technik* Zgloszenie::getTechnik() const { return technik; }
Zglaszajacy* Zgloszenie::getZglaszajacy() const { return zglaszajacy; }


bool Zgloszenie::przypiszTechnika(Administrator* /*admin*/, Technik* /*nowyTechnik*/) {
    return false;
}


bool Zgloszenie::dodajKomentarz(const std::string& /*tresc*/, PracownikSystemu* /*autor*/) {
    return false;
}

bool Zgloszenie::zmienStatus(PracownikSystemu* /*autor*/, Status /*nowyStatus*/) {
    return false;
}
