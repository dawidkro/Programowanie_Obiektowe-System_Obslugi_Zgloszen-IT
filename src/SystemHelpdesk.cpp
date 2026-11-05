#include "SystemHelpdesk.h"

// Wszystkie metody w tym pliku sa do zrobienia (odkomentuj nazwy parametrow).
//
// W prawie kazdej trzeba najpierw znalezc zgloszenie o podanym id: przejdz petla
// po wektorze zgloszenia i porownaj getId(). Jesli zrobicie z tego osobna metode
// prywatna (np. znajdzZgloszenie), dopiszcie ja tez w .h i na diagramie klas.
//
// Zanim napiszecie main.cpp, brakuje jeszcze w SystemHelpdesk.h (i na diagramie klas):
//   - metod do wpuszczenia do systemu ludzi i kategorii, np.
//     dodajPracownika(std::unique_ptr<PracownikSystemu>) i dodajKategorie(...),
//   - pobierzKomentarze(zgloszenieId, pracownik) dla US7 - jest na diagramie klas,
//     ale nie ma jej w .h (dopiszcie typ zwracany: std::vector<Komentarz>).

// TODO (US1): nadaj nowe id (np. liczba zgloszen + 1), dodaj Zgloszenie do wektora
//             zgloszenia i zwroc jego id. Status NOWE i wpis "utworzono" robi juz konstruktor.
int SystemHelpdesk::stworzZgloszenie(Zglaszajacy* /*zglaszajacy*/, const std::string& /*opis*/,
                                     Priorytet /*priorytet*/,
                                     const KategoriaProblemu& /*kategoria*/) {
    return -1;
}

// TODO (US2): znajdz zgloszenie; w wektorze pracownicy znajdz pracownika o technikId
//             i sprawdz, czy to Technik (dynamic_cast<Technik*>); nie ma takiego -> false.
//             Zwroc wynik zgloszenie.przypiszTechnika(admin, technik).
bool SystemHelpdesk::przydzielZgloszenie(int /*zgloszenieId*/, Administrator* /*admin*/,
                                         int /*technikId*/) {
    return false;
}

// TODO (US3): znajdz zgloszenie; jesli autor nie ma do niego dostepu
//             (autor->czyMaDostep(zgloszenie)) -> false; zwroc wynik
//             zgloszenie.dodajKomentarz(tresc, autor).
bool SystemHelpdesk::dodajKomentarz(int /*zgloszenieId*/, PracownikSystemu* /*autor*/,
                                    const std::string& /*tresc*/) {
    return false;
}

// TODO (US3, dokladnie jak na diagramie sekwencji):
//   1. Znajdz zgloszenie (nie ma -> false).
//   2. Jesli zgloszenie.getTechnik() != pracownik -> false   (alt [else]).
//   3. Zwroc wynik zgloszenie.zmienStatus(pracownik, status).
bool SystemHelpdesk::zmienStatusZgloszenia(int /*zgloszenieId*/, Status /*status*/,
                                           PracownikSystemu* /*pracownik*/) {
    return false;
}

// TODO (US4, polimorfizm): zwroc te zgloszenia, przy ktorych
//             pracownik->czyMaDostep(z) daje true. Technik dostanie swoje, administrator wszystkie.
std::vector<Zgloszenie> SystemHelpdesk::pobierzListeZgloszen(PracownikSystemu* /*pracownik*/) const {
    return {};
}

// TODO (US5): znajdz zgloszenie i zwroc jego pobierzHistorieWpisow(); nie ma -> pusty wektor.
std::vector<WpisHistorii> SystemHelpdesk::pobierzHistorieWpisow(int /*zgloszenieId*/) const {
    return {};
}

// TODO (US6): znajdz zgloszenie; nie istnieje albo pracownik nie ma dostepu -> false;
//             w przeciwnym razie wpisz jego status do parametru status i zwroc true.
bool SystemHelpdesk::sprawdzStatusZgloszenia(int /*zgloszenieId*/, PracownikSystemu* /*pracownik*/,
                                             Status& /*status*/) const {
    return false;
}
