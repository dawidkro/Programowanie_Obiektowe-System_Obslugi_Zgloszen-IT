#include "SystemHelpdesk.h"

int SystemHelpdesk::stworzZgloszenie(Zglaszajacy* /*zglaszajacy*/, const std::string& /*opis*/,
                                     Priorytet /*priorytet*/,
                                     const KategoriaProblemu& /*kategoria*/) {
    return -1;
}
bool SystemHelpdesk::przydzielZgloszenie(int /*zgloszenieId*/, Administrator* /*admin*/,
                                         int /*technikId*/) {
    return false;
}


bool SystemHelpdesk::dodajKomentarz(int /*zgloszenieId*/, PracownikSystemu* /*autor*/,
                                    const std::string& /*tresc*/) {
    return false;
}

bool SystemHelpdesk::zmienStatusZgloszenia(int /*zgloszenieId*/, Status /*status*/,
                                           PracownikSystemu* /*pracownik*/) {
    return false;
}

std::vector<Zgloszenie> SystemHelpdesk::pobierzListeZgloszen(PracownikSystemu* /*pracownik*/) const {
    return {};
}


std::vector<WpisHistorii> SystemHelpdesk::pobierzHistorieWpisow(int /*zgloszenieId*/) const {
    return {};
}


bool SystemHelpdesk::sprawdzStatusZgloszenia(int /*zgloszenieId*/, PracownikSystemu* /*pracownik*/,
                                             Status& /*status*/) const {
    return false;
}
