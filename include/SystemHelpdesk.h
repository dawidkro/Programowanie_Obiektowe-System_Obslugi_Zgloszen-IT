#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Administrator.h"
#include "KategoriaProblemu.h"
#include "Komentarz.h"
#include "PracownikSystemu.h"
#include "Priorytet.h"
#include "Status.h"
#include "Technik.h"
#include "WpisHistorii.h"
#include "Zglaszajacy.h"
#include "Zgloszenie.h"

class SystemHelpdesk {
public:
    static constexpr int NIEPOPRAWNE_ID = -1;

    SystemHelpdesk() = default;

    bool dodajPracownika(std::unique_ptr<PracownikSystemu> pracownik);
    bool dodajKategorie(const KategoriaProblemu& kategoria);

    int stworzZgloszenie(Zglaszajacy* zglaszajacy, const std::string& opis,
                         Priorytet priorytet,
                         const KategoriaProblemu& kategoria);
    bool przydzielZgloszenie(int zgloszenie_id, Administrator* admin,
                             int technik_id);
    bool dodajKomentarz(int zgloszenie_id, PracownikSystemu* autor,
                        const std::string& tresc);
    bool zmienStatusZgloszenia(int zgloszenie_id, Status status,
                               PracownikSystemu* pracownik);

    std::vector<Zgloszenie> pobierzListeZgloszen(
        PracownikSystemu* pracownik) const;
    std::vector<WpisHistorii> pobierzHistorieWpisow(int zgloszenie_id) const;
    bool sprawdzStatusZgloszenia(int zgloszenie_id,
                                 PracownikSystemu* pracownik,
                                 Status& status) const;
    bool pobierzKomentarze(int zgloszenie_id, PracownikSystemu* pracownik,
                           std::vector<Komentarz>& komentarze) const;

private:
    Zgloszenie* znajdzZgloszenie(int zgloszenie_id);
    const Zgloszenie* znajdzZgloszenie(int zgloszenie_id) const;
    PracownikSystemu* znajdzPracownika(int pracownik_id) const;
    bool czyKategoriaIstnieje(const std::string& nazwa) const;

    std::vector<Zgloszenie> zgloszenia_;
    std::vector<KategoriaProblemu> kategorie_;
    std::vector<std::unique_ptr<PracownikSystemu>> pracownicy_;
    int nastepne_id_ = 1;
};
