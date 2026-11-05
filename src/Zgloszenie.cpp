#include "Zgloszenie.h"

#include <ctime>

// Funkcje pomocnicze widoczne tylko w tym pliku. To nie sa metody klasy,
// wiec nie musza byc na diagramie klas.
namespace {

// Biezaca data i godzina jako tekst, np. "2026-11-05 21:53".
std::string aktualnaData() {
    std::time_t teraz = std::time(nullptr);
    char bufor[20];
    std::strftime(bufor, sizeof(bufor), "%Y-%m-%d %H:%M", std::localtime(&teraz));
    return bufor;
}

// Nazwa statusu do opisow w historii. Przyda sie w zmienStatus().
[[maybe_unused]] std::string nazwaStatusu(Status status) {
    switch (status) {
        case Status::NOWE:       return "NOWE";
        case Status::W_TRAKCIE:  return "W_TRAKCIE";
        case Status::OCZEKUJE:   return "OCZEKUJE";
        case Status::ROZWIAZANE: return "ROZWIAZANE";
    }
    return "?";
}

}  // namespace

// ============================================================ gotowe

Zgloszenie::Zgloszenie(int id, const std::string& opis, Priorytet priorytet,
                       const KategoriaProblemu& kategoria, Zglaszajacy* zglaszajacy)
    : id(id), opis(opis), status(Status::NOWE), priorytet(priorytet),
      kategoria(kategoria), zglaszajacy(zglaszajacy), technik(nullptr) {
    // US1: utworzenie od razu trafia do historii (stad krotnosc 1..* na diagramie klas)
    dodajWpisHistorii("Utworzono zgłoszenie", zglaszajacy);
}

// Jak na diagramie sekwencji: tworzy nowy WpisHistorii (data, opis zmiany, autor).
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

// ============================================================ do zrobienia
// Przy implementacji odkomentuj nazwy parametrow. Uwaga na nazwy: pola klasy
// nazywaja sie juz status i technik, dlatego parametry maja inne nazwy
// (inaczej "status = status" nic by nie zmienilo).

// TODO (US2):
//   1. Jesli zgloszenie ma status ROZWIAZANE -> return false.
//   2. Ustaw pole technik na nowyTechnik.
//   3. Dopisz wpis do historii o przydzieleniu (autor: admin).
//   4. return true.
bool Zgloszenie::przypiszTechnika(Administrator* /*admin*/, Technik* /*nowyTechnik*/) {
    return false;
}

// TODO (US3):
//   1. (opcjonalnie) pusty tekst -> return false.
//   2. Dodaj do wektora komentarze nowy Komentarz z trescia, data aktualnaData() i autorem.
//   3. return true.
bool Zgloszenie::dodajKomentarz(const std::string& /*tresc*/, PracownikSystemu* /*autor*/) {
    return false;
}

// TODO (US3, logika biznesowa, przebieg jak na diagramie sekwencji):
//   1. Sprawdz, czy przejscie z obecnego status na nowyStatus jest dozwolone:
//      NOWE->W_TRAKCIE, W_TRAKCIE->OCZEKUJE, OCZEKUJE->W_TRAKCIE,
//      W_TRAKCIE->ROZWIAZANE, OCZEKUJE->ROZWIAZANE. Kazde inne -> return false.
//   2. Zapamietaj stary status i ustaw nowy.
//   3. Dopisz wpis do historii, np. "Zmiana statusu: NOWE -> W_TRAKCIE"
//      (uzyj nazwaStatusu() z gory pliku), autor: autor.
//   4. return true.
bool Zgloszenie::zmienStatus(PracownikSystemu* /*autor*/, Status /*nowyStatus*/) {
    return false;
}
