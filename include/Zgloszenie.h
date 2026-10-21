#pragma once
#include <string>
#include <vector>
#include "Status.h"
#include "Priorytet.h"
#include "KategoriaProblemu.h"
#include "Komentarz.h"
#include "WpisHistorii.h"
#include "PracownikSystemu.h"
#include "Zglaszajacy.h"
#include "Technik.h"
#include "Administrator.h"

class Zgloszenie {
private:
    int id;
    std::string opis;
    Status status;
    Priorytet priorytet;

    KategoriaProblemu kategoria;
    Zglaszajacy* zglaszajacy;         
    Technik* technik; 
    std::vector<Komentarz> komentarze;
    std::vector<WpisHistorii> historia;

    void dodajWpisHistorii(const std::string& opis, PracownikSystemu* autor);

public:
    Zgloszenie(int id, const std::string& opis, Priorytet priorytet,
               const KategoriaProblemu& kategoria, Zglaszajacy* zglaszajacy);

    std::vector<WpisHistorii> pobierzHistorieWpisow() const;
    std::vector<Komentarz> pobierzKomentarze() const;

    bool przypiszTechnika(Administrator* admin, Technik* technik);
    bool dodajKomentarz(const std::string& tresc, PracownikSystemu* autor);
    bool zmienStatus(PracownikSystemu* autor, Status status);

    int getId() const;
    Status getStatus() const;
    std::string getOpis() const;
    KategoriaProblemu getKategoria() const;
    Priorytet getPriorytet() const;
    Technik* getTechnik() const;
    Zglaszajacy* getZglaszajacy() const;
};
