#include "SystemHelpdesk.h"

#include <utility>

namespace {

bool czyDostepne(const Zgloszenie* zgloszenie,
                 const PracownikSystemu* pracownik) {
    return zgloszenie != nullptr && pracownik != nullptr &&
           pracownik->czyMaDostep(*zgloszenie);
}

} 

bool SystemHelpdesk::dodajPracownika(
    std::unique_ptr<PracownikSystemu> pracownik) {
    if (pracownik == nullptr ||
        znajdzPracownika(pracownik->getId()) != nullptr) {
        return false;
    }
    pracownicy_.push_back(std::move(pracownik));
    return true;
}

bool SystemHelpdesk::dodajKategorie(const KategoriaProblemu& kategoria) {
    if (kategoria.getNazwa().empty() ||
        czyKategoriaIstnieje(kategoria.getNazwa())) {
        return false;
    }
    kategorie_.push_back(kategoria);
    return true;
}

int SystemHelpdesk::stworzZgloszenie(Zglaszajacy* zglaszajacy,
                                     const std::string& opis,
                                     Priorytet priorytet,
                                     const KategoriaProblemu& kategoria) {
    if (zglaszajacy == nullptr || opis.empty() ||
        !czyKategoriaIstnieje(kategoria.getNazwa())) {
        return NIEPOPRAWNE_ID;
    }
    int id = nastepne_id_;
    ++nastepne_id_;
    zgloszenia_.emplace_back(id, opis, priorytet, kategoria, zglaszajacy);
    return id;
}

bool SystemHelpdesk::przydzielZgloszenie(int zgloszenie_id,
                                         Administrator* admin,
                                         int technik_id) {
    Zgloszenie* zgloszenie = znajdzZgloszenie(zgloszenie_id);
    auto* technik = dynamic_cast<Technik*>(znajdzPracownika(technik_id));
    if (zgloszenie == nullptr || technik == nullptr) {
        return false;
    }
    return zgloszenie->przypiszTechnika(admin, technik);
}

bool SystemHelpdesk::dodajKomentarz(int zgloszenie_id,
                                    PracownikSystemu* autor,
                                    const std::string& tresc) {
    Zgloszenie* zgloszenie = znajdzZgloszenie(zgloszenie_id);
    if (!czyDostepne(zgloszenie, autor)) {
        return false;
    }
    return zgloszenie->dodajKomentarz(tresc, autor);
}

bool SystemHelpdesk::zmienStatusZgloszenia(int zgloszenie_id, Status status,
                                           PracownikSystemu* pracownik) {
    Zgloszenie* zgloszenie = znajdzZgloszenie(zgloszenie_id);
    if (zgloszenie == nullptr) {
        return false;
    }
    Technik* technik = zgloszenie->getTechnik();
    if (technik == nullptr || technik != pracownik) {
        return false;
    }
    return zgloszenie->zmienStatus(pracownik, status);
}

std::vector<Zgloszenie> SystemHelpdesk::pobierzListeZgloszen(
    PracownikSystemu* pracownik) const {
    std::vector<Zgloszenie> wynik;
    for (const auto& zgloszenie : zgloszenia_) {
        if (czyDostepne(&zgloszenie, pracownik)) {
            wynik.push_back(zgloszenie);
        }
    }
    return wynik;
}

std::vector<WpisHistorii> SystemHelpdesk::pobierzHistorieWpisow(
    int zgloszenie_id) const {
    const Zgloszenie* zgloszenie = znajdzZgloszenie(zgloszenie_id);
    if (zgloszenie == nullptr) {
        return {};
    }
    return zgloszenie->pobierzHistorieWpisow();
}

bool SystemHelpdesk::sprawdzStatusZgloszenia(int zgloszenie_id,
                                             PracownikSystemu* pracownik,
                                             Status& status) const {
    const Zgloszenie* zgloszenie = znajdzZgloszenie(zgloszenie_id);
    if (!czyDostepne(zgloszenie, pracownik)) {
        return false;
    }
    status = zgloszenie->getStatus();
    return true;
}

bool SystemHelpdesk::pobierzKomentarze(
    int zgloszenie_id, PracownikSystemu* pracownik,
    std::vector<Komentarz>& komentarze) const {
    const Zgloszenie* zgloszenie = znajdzZgloszenie(zgloszenie_id);
    if (!czyDostepne(zgloszenie, pracownik)) {
        return false;
    }
    komentarze = zgloszenie->pobierzKomentarze();
    return true;
}

Zgloszenie* SystemHelpdesk::znajdzZgloszenie(int zgloszenie_id) {
    for (auto& zgloszenie : zgloszenia_) {
        if (zgloszenie.getId() == zgloszenie_id) {
            return &zgloszenie;
        }
    }
    return nullptr;
}

const Zgloszenie* SystemHelpdesk::znajdzZgloszenie(int zgloszenie_id) const {
    for (const auto& zgloszenie : zgloszenia_) {
        if (zgloszenie.getId() == zgloszenie_id) {
            return &zgloszenie;
        }
    }
    return nullptr;
}

PracownikSystemu* SystemHelpdesk::znajdzPracownika(int pracownik_id) const {
    for (const auto& pracownik : pracownicy_) {
        if (pracownik->getId() == pracownik_id) {
            return pracownik.get();
        }
    }
    return nullptr;
}

bool SystemHelpdesk::czyKategoriaIstnieje(const std::string& nazwa) const {
    for (const auto& kategoria : kategorie_) {
        if (kategoria.getNazwa() == nazwa) {
            return true;
        }
    }
    return false;
}

