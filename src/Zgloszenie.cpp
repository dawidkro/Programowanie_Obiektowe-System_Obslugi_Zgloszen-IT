#include "Zgloszenie.h"

Zgloszenie::Zgloszenie(int id, const std::string& opis, Priorytet priorytet,
                       const KategoriaProblemu& kategoria,
                       Zglaszajacy* zglaszajacy)
    : id_(id),
      opis_(opis),
      status_(Status::NOWE),
      priorytet_(priorytet),
      kategoria_(kategoria),
      zglaszajacy_(zglaszajacy),
      technik_(nullptr) {
    dodajWpisHistorii("Utworzono zgloszenie", zglaszajacy);
}

std::vector<WpisHistorii> Zgloszenie::pobierzHistorieWpisow() const {
    return historia_;
}

std::vector<Komentarz> Zgloszenie::pobierzKomentarze() const {
    return komentarze_;
}

bool Zgloszenie::przypiszTechnika(Administrator* admin, Technik* technik) {
    if (admin == nullptr || technik == nullptr ||
        status_ == Status::ROZWIAZANE) {
        return false;
    }
    technik_ = technik;
    dodajWpisHistorii("Przydzielono technikowi: " + technik->getImie() + " " +
                          technik->getNazwisko(),
                      admin);
    return true;
}

bool Zgloszenie::dodajKomentarz(const std::string& tresc,
                                PracownikSystemu* autor) {
    if (autor == nullptr || tresc.empty()) {
        return false;
    }
    komentarze_.emplace_back(tresc, Date::teraz(), autor);
    return true;
}

bool Zgloszenie::zmienStatus(PracownikSystemu* autor, Status nowy_status) {
    if (autor == nullptr || !czyPrzejscieDozwolone(nowy_status)) {
        return false;
    }
    std::string opis_zmiany = "Zmiana statusu: " + statusNaTekst(status_) +
                              " -> " + statusNaTekst(nowy_status);
    status_ = nowy_status;
    dodajWpisHistorii(opis_zmiany, autor);
    return true;
}

int Zgloszenie::getId() const { return id_; }
Status Zgloszenie::getStatus() const { return status_; }
std::string Zgloszenie::getOpis() const { return opis_; }
KategoriaProblemu Zgloszenie::getKategoria() const { return kategoria_; }
Priorytet Zgloszenie::getPriorytet() const { return priorytet_; }
Technik* Zgloszenie::getTechnik() const { return technik_; }
Zglaszajacy* Zgloszenie::getZglaszajacy() const { return zglaszajacy_; }

void Zgloszenie::dodajWpisHistorii(const std::string& opis_zmiany,
                                   PracownikSystemu* autor) {
    historia_.emplace_back(Date::teraz(), opis_zmiany, autor);
}

bool Zgloszenie::czyPrzejscieDozwolone(Status nowy_status) const {
    switch (status_) {
        case Status::NOWE:
            return nowy_status == Status::W_TRAKCIE;
        case Status::W_TRAKCIE:
            return nowy_status == Status::OCZEKUJE ||
                   nowy_status == Status::ROZWIAZANE;
        case Status::OCZEKUJE:
            return nowy_status == Status::W_TRAKCIE ||
                   nowy_status == Status::ROZWIAZANE;
        case Status::ROZWIAZANE:
            return false;
    }
    return false;
}
