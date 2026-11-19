#pragma once
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

class Zgloszenie {
public:
    Zgloszenie(int id, const std::string& opis, Priorytet priorytet,
               const KategoriaProblemu& kategoria, Zglaszajacy* zglaszajacy);

    std::vector<WpisHistorii> pobierzHistorieWpisow() const;
    std::vector<Komentarz> pobierzKomentarze() const;

    bool przypiszTechnika(Administrator* admin, Technik* technik);
    bool dodajKomentarz(const std::string& tresc, PracownikSystemu* autor);
    bool zmienStatus(PracownikSystemu* autor, Status nowy_status);

    int getId() const;
    Status getStatus() const;
    std::string getOpis() const;
    KategoriaProblemu getKategoria() const;
    Priorytet getPriorytet() const;
    Technik* getTechnik() const;
    Zglaszajacy* getZglaszajacy() const;

private:
    void dodajWpisHistorii(const std::string& opis_zmiany,
                           PracownikSystemu* autor);
    bool czyPrzejscieDozwolone(Status nowy_status) const;

    int id_;
    std::string opis_;
    Status status_;
    Priorytet priorytet_;
    KategoriaProblemu kategoria_;
    Zglaszajacy* zglaszajacy_;
    Technik* technik_;
    std::vector<Komentarz> komentarze_;
    std::vector<WpisHistorii> historia_;
};
