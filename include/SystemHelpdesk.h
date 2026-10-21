#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Zgloszenie.h"
#include "KategoriaProblemu.h"
#include "PracownikSystemu.h"
#include "Zglaszajacy.h"
#include "Technik.h"
#include "Administrator.h"
#include "Priorytet.h"
#include "Status.h"
#include "WpisHistorii.h"

class SystemHelpdesk {
private:
    std::vector<Zgloszenie> zgloszenia;
    std::vector<KategoriaProblemu> kategorie;
    std::vector<std::unique_ptr<PracownikSystemu>> pracownicy;

public:
    SystemHelpdesk() = default;

    int stworzZgloszenie(Zglaszajacy* zglaszajacy, const std::string& opis,
                         Priorytet priorytet, const KategoriaProblemu& kategoria);
    bool przydzielZgloszenie(int zgloszenieId, Administrator* admin, int technikId);
    bool dodajKomentarz(int zgloszenieId, PracownikSystemu* autor, const std::string& tresc);
    bool zmienStatusZgloszenia(int zgloszenieId, Status status, PracownikSystemu* pracownik);

    std::vector<Zgloszenie> pobierzListeZgloszen(PracownikSystemu* pracownik) const;
    std::vector<WpisHistorii> pobierzHistorieWpisow(int zgloszenieId) const;
    bool sprawdzStatusZgloszenia(int zgloszenieId, PracownikSystemu* pracownik, Status& status) const;
};
