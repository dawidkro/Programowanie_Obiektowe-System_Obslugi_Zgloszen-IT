#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "Administrator.h"
#include "KategoriaProblemu.h"
#include "Komentarz.h"
#include "PracownikSystemu.h"
#include "Priorytet.h"
#include "Status.h"
#include "SystemHelpdesk.h"
#include "Technik.h"
#include "WpisHistorii.h"
#include "Zglaszajacy.h"
#include "Zgloszenie.h"

namespace {

struct Demo {
    Zglaszajacy* jan;
    Zglaszajacy* ewa;
    Technik* anna;
    Technik* piotr;
    Administrator* admin;
    int drukarka_id;
    int vpn_id;
    int excel_id;
};

template <typename T>
T* zarejestruj(SystemHelpdesk& system, int id, const std::string& imie,
               const std::string& nazwisko) {
    auto pracownik = std::make_unique<T>(id, imie, nazwisko);
    T* wskaznik = pracownik.get();
    if (!system.dodajPracownika(std::move(pracownik))) {
        return nullptr;
    }
    return wskaznik;
}

std::string pelneImie(const PracownikSystemu* pracownik) {
    if (pracownik == nullptr) {
        return "(brak)";
    }
    return pracownik->getImie() + " " + pracownik->getNazwisko();
}

std::string numer(int zgloszenie_id) {
    return "#" + std::to_string(zgloszenie_id);
}

void naglowek(const std::string& tytul) {
    std::cout << "\n" << std::string(70, '=') << "\n"
              << tytul << "\n"
              << std::string(70, '=') << "\n";
}

void wypiszWynik(const std::string& operacja, bool wynik,
                 const std::string& uwaga = "") {
    std::cout << (wynik ? "  [OK]         " : "  [ODRZUCONO]  ") << operacja;
    if (!uwaga.empty()) {
        std::cout << "  (" << uwaga << ")";
    }
    std::cout << "\n";
}

void wypiszBrakZgloszenia() {
    std::cout << "    Nie znaleziono zgloszenia o tym ID wsrod Twoich "
                 "zgloszen.\n";
}

void wypiszZgloszenia(const std::vector<Zgloszenie>& zgloszenia) {
    if (zgloszenia.empty()) {
        std::cout << "    (brak zgloszen)\n";
    }
    for (const auto& zgloszenie : zgloszenia) {
        std::cout << "    " << numer(zgloszenie.getId()) << " | "
                  << statusNaTekst(zgloszenie.getStatus()) << " | "
                  << priorytetNaTekst(zgloszenie.getPriorytet()) << " | "
                  << zgloszenie.getKategoria().getNazwa() << " | "
                  << zgloszenie.getOpis() << " | technik: "
                  << pelneImie(zgloszenie.getTechnik()) << "\n";
    }
}

void wypiszHistorie(const std::vector<WpisHistorii>& historia) {
    for (const auto& wpis : historia) {
        std::cout << "    " << wpis.getData().toString() << " | "
                  << pelneImie(wpis.getAutor()) << " | "
                  << wpis.getOpisZmiany() << "\n";
    }
}

void wypiszKomentarze(const std::vector<Komentarz>& komentarze) {
    if (komentarze.empty()) {
        std::cout << "    (brak komentarzy)\n";
    }
    for (const auto& komentarz : komentarze) {
        std::cout << "    " << komentarz.getData().toString() << " | "
                  << pelneImie(komentarz.getAutor()) << ": "
                  << komentarz.getTresc() << "\n";
    }
}

int sprobujUtworzyc(SystemHelpdesk& system, Zglaszajacy* zglaszajacy,
                    const std::string& opis, Priorytet priorytet,
                    const std::string& kategoria,
                    const std::string& uwaga = "") {
    int id = system.stworzZgloszenie(zglaszajacy, opis, priorytet,
                                     KategoriaProblemu(kategoria));
    bool wynik = id != SystemHelpdesk::NIEPOPRAWNE_ID;
    std::string operacja = pelneImie(zglaszajacy) + ": \"" + opis + "\" [" +
                           kategoria + ", " + priorytetNaTekst(priorytet) +
                           "]";
    if (wynik) {
        operacja += " -> " + numer(id);
    }
    wypiszWynik(operacja, wynik, uwaga);
    return id;
}

void sprobujPrzydzielic(SystemHelpdesk& system, Administrator* admin,
                        int zgloszenie_id, const PracownikSystemu* komu,
                        const std::string& uwaga = "") {
    bool wynik = system.przydzielZgloszenie(zgloszenie_id, admin,
                                            komu->getId());
    wypiszWynik(pelneImie(admin) + ": " + numer(zgloszenie_id) + " -> " +
                    pelneImie(komu),
                wynik, uwaga);
}

void sprobujZmienicStatus(SystemHelpdesk& system, int zgloszenie_id,
                          Status status, PracownikSystemu* pracownik,
                          const std::string& uwaga = "") {
    bool wynik = system.zmienStatusZgloszenia(zgloszenie_id, status,
                                              pracownik);
    wypiszWynik(pelneImie(pracownik) + ": " + numer(zgloszenie_id) +
                    " -> " + statusNaTekst(status),
                wynik, uwaga);
}

void sprobujDodacKomentarz(SystemHelpdesk& system, int zgloszenie_id,
                           PracownikSystemu* autor, const std::string& tresc,
                           const std::string& uwaga = "") {
    bool wynik = system.dodajKomentarz(zgloszenie_id, autor, tresc);
    wypiszWynik(pelneImie(autor) + " komentuje " + numer(zgloszenie_id) +
                    ": \"" + tresc + "\"",
                wynik, uwaga);
}

void pokazListe(const SystemHelpdesk& system, PracownikSystemu* pracownik,
                const std::string& rola) {
    std::cout << "  " << rola << " " << pelneImie(pracownik) << ":\n";
    wypiszZgloszenia(system.pobierzListeZgloszen(pracownik));
}

void pokazStatus(const SystemHelpdesk& system, int zgloszenie_id,
                 PracownikSystemu* pracownik) {
    std::cout << "  " << pelneImie(pracownik) << " sprawdza status "
              << numer(zgloszenie_id) << ":\n";
    Status status = Status::NOWE;
    if (system.sprawdzStatusZgloszenia(zgloszenie_id, pracownik, status)) {
        std::cout << "    Status: " << statusNaTekst(status) << "\n";
    } else {
        wypiszBrakZgloszenia();
    }
}

void pokazKomentarze(const SystemHelpdesk& system, int zgloszenie_id,
                     PracownikSystemu* pracownik) {
    std::cout << "  " << pelneImie(pracownik) << " czyta komentarze do "
              << numer(zgloszenie_id) << ":\n";
    std::vector<Komentarz> komentarze;
    if (system.pobierzKomentarze(zgloszenie_id, pracownik, komentarze)) {
        wypiszKomentarze(komentarze);
    } else {
        wypiszBrakZgloszenia();
    }
}

Demo przygotujSystem(SystemHelpdesk& system) {
    naglowek("Przygotowanie: uzytkownicy i kategorie problemow");
    Demo demo{zarejestruj<Zglaszajacy>(system, 1, "Jan", "Kowalski"),
              zarejestruj<Zglaszajacy>(system, 2, "Ewa", "Wisniewska"),
              zarejestruj<Technik>(system, 10, "Anna", "Nowak"),
              zarejestruj<Technik>(system, 11, "Piotr", "Zielinski"),
              zarejestruj<Administrator>(system, 100, "Marek", "Lewandowski"),
              SystemHelpdesk::NIEPOPRAWNE_ID,
              SystemHelpdesk::NIEPOPRAWNE_ID,
              SystemHelpdesk::NIEPOPRAWNE_ID};
    system.dodajKategorie(KategoriaProblemu("Sprzet"));
    system.dodajKategorie(KategoriaProblemu("Oprogramowanie"));
    system.dodajKategorie(KategoriaProblemu("Siec"));

    std::cout << "  Zglaszajacy:   " << pelneImie(demo.jan) << ", "
              << pelneImie(demo.ewa) << "\n"
              << "  Technicy:      " << pelneImie(demo.anna) << " (ID "
              << demo.anna->getId() << "), " << pelneImie(demo.piotr)
              << " (ID " << demo.piotr->getId() << ")\n"
              << "  Administrator: " << pelneImie(demo.admin) << "\n"
              << "  Kategorie:     Sprzet, Oprogramowanie, Siec\n";
    return demo;
}

void demoUs1(SystemHelpdesk& system, Demo& demo) {
    naglowek("US1: Zglaszajacy tworzy zgloszenie");
    demo.drukarka_id = sprobujUtworzyc(
        system, demo.jan, "Drukarka w pokoju 214 nie drukuje",
        Priorytet::WYSOKI, "Sprzet");
    demo.vpn_id = sprobujUtworzyc(system, demo.jan,
                                  "Brak polaczenia z VPN z domu",
                                  Priorytet::BARDZO_WYSOKI, "Siec");
    demo.excel_id = sprobujUtworzyc(
        system, demo.ewa, "Excel zawiesza sie przy otwieraniu pliku",
        Priorytet::SREDNI, "Oprogramowanie");
    sprobujUtworzyc(system, demo.ewa, "Nowe krzeslo do biura",
                    Priorytet::NISKI, "Meble",
                    "kategorii nie ma w systemie");

    std::cout << "  Nowe zgloszenia maja status Nowe i brak technika:\n";
    wypiszZgloszenia(system.pobierzListeZgloszen(demo.admin));
    std::cout << "  Historia " << numer(demo.drukarka_id)
              << " zaraz po utworzeniu:\n";
    wypiszHistorie(system.pobierzHistorieWpisow(demo.drukarka_id));
}

void demoUs2(SystemHelpdesk& system, const Demo& demo) {
    naglowek("US2: Administrator przydziela zgloszenie technikowi");
    sprobujPrzydzielic(system, demo.admin, demo.drukarka_id, demo.anna);
    sprobujPrzydzielic(system, demo.admin, demo.vpn_id, demo.anna);
    sprobujPrzydzielic(system, demo.admin, demo.excel_id, demo.piotr);
    sprobujPrzydzielic(system, demo.admin, demo.excel_id, demo.jan,
                       "Jan nie jest technikiem");
    sprobujPrzydzielic(system, demo.admin, 99, demo.piotr,
                       "zgloszenie nie istnieje");

    std::cout << "  Przydzielone zgloszenia sa na liscie technika:\n";
    pokazListe(system, demo.anna, "Technik");
}

void demoUs3(SystemHelpdesk& system, const Demo& demo) {
    naglowek("US3: Technik zmienia status zgloszenia");
    int id = demo.drukarka_id;
    sprobujZmienicStatus(system, id, Status::W_TRAKCIE, demo.anna);
    sprobujZmienicStatus(system, id, Status::OCZEKUJE, demo.anna);
    sprobujZmienicStatus(system, id, Status::W_TRAKCIE, demo.anna);
    sprobujZmienicStatus(system, id, Status::ROZWIAZANE, demo.anna);
    sprobujZmienicStatus(system, demo.excel_id, Status::W_TRAKCIE,
                         demo.piotr);

    std::cout << "  Proby niedozwolone:\n";
    sprobujZmienicStatus(system, demo.vpn_id, Status::W_TRAKCIE, demo.piotr,
                         "Piotr nie jest przypisany do zgloszenia");
    sprobujZmienicStatus(system, demo.vpn_id, Status::ROZWIAZANE, demo.anna,
                         "przejscie Nowe -> Rozwiazane jest niedozwolone");
    sprobujZmienicStatus(system, id, Status::W_TRAKCIE, demo.anna,
                         "zgloszenia rozwiazanego nie mozna wznowic");

    std::cout << "  Regula z US2 - rozwiazanego zgloszenia nie da sie "
                 "przydzielic:\n";
    sprobujPrzydzielic(system, demo.admin, id, demo.piotr,
                       "zgloszenie ma status Rozwiazane");
}

void demoUs4(SystemHelpdesk& system, const Demo& demo) {
    naglowek("US4: Dodawanie komentarzy (kazdy, kto ma dostep do zgloszenia)");
    sprobujDodacKomentarz(system, demo.drukarka_id, demo.anna,
                          "Wymieniono beben, drukarka dziala.");
    sprobujDodacKomentarz(system, demo.drukarka_id, demo.jan,
                          "Potwierdzam, drukarka drukuje. Dziekuje!");
    sprobujDodacKomentarz(system, demo.vpn_id, demo.admin,
                          "Pilne - VPN jest potrzebny do pracy zdalnej.");
    sprobujDodacKomentarz(system, demo.excel_id, demo.piotr,
                          "Naprawiam instalacje pakietu Office.");

    std::cout << "  Proby niedozwolone:\n";
    sprobujDodacKomentarz(system, demo.drukarka_id, demo.piotr, "Moge pomoc?",
                          "Piotr nie jest przypisany do zgloszenia");
    sprobujDodacKomentarz(system, demo.drukarka_id, demo.ewa, "A moje?",
                          "to nie jest zgloszenie Ewy");
    sprobujDodacKomentarz(system, demo.excel_id, demo.piotr, "",
                          "pusty komentarz");
}

void demoUs5(const SystemHelpdesk& system, const Demo& demo) {
    naglowek("US5: Lista zgloszen (technik - swoje, administrator - "
             "wszystkie)");
    pokazListe(system, demo.anna, "Technik");
    pokazListe(system, demo.piotr, "Technik");
    pokazListe(system, demo.admin, "Administrator");
}

void demoUs6(const SystemHelpdesk& system, const Demo& demo) {
    naglowek("US6: Historia wpisow zgloszenia (audit log)");
    for (int id : {demo.drukarka_id, demo.excel_id}) {
        std::cout << "  Zgloszenie " << numer(id) << ":\n";
        wypiszHistorie(system.pobierzHistorieWpisow(id));
    }
}

void demoUs7(const SystemHelpdesk& system, const Demo& demo) {
    naglowek("US7: Zglaszajacy sprawdza status swojego zgloszenia");
    pokazStatus(system, demo.drukarka_id, demo.jan);
    pokazStatus(system, demo.vpn_id, demo.jan);
    pokazStatus(system, demo.drukarka_id, demo.ewa);
    pokazStatus(system, 99, demo.jan);
}

void demoUs8(const SystemHelpdesk& system, const Demo& demo) {
    naglowek("US8: Zglaszajacy wyswietla komentarze do swojego zgloszenia");
    pokazKomentarze(system, demo.drukarka_id, demo.jan);
    pokazKomentarze(system, demo.excel_id, demo.ewa);
    pokazKomentarze(system, demo.drukarka_id, demo.ewa);
}

}

int main() {
    SystemHelpdesk system;
    Demo demo = przygotujSystem(system);

    demoUs1(system, demo);
    demoUs2(system, demo);
    demoUs3(system, demo);
    demoUs4(system, demo);
    demoUs5(system, demo);
    demoUs6(system, demo);
    demoUs7(system, demo);
    demoUs8(system, demo);
    return 0;
}

