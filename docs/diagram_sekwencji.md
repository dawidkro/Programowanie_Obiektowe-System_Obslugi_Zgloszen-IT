# Diagram sekwencji – zmiana statusu zgłoszenia

**Przypadek użycia:** 4. Zmień status zgłoszenia (User Story 3), aktor: Technik.
**Pliki:** `docs/diagramy/diagram_sekwencji.png`, `docs/diagramy/diagram_sekwencji.vpd`

**Cel:** Diagram pokazuje, jak system obsługuje zmianę statusu zgłoszenia przez technika:
ścieżkę główną (zmiana statusu i automatyczny wpis do historii) oraz dwie ścieżki
alternatywne (zmiany próbuje dokonać nieprzypisany pracownik albo przejście statusu
jest niedozwolone).

**Przebieg komunikatów:**
1. Technik wywołuje `zmienStatusZgloszenia(zgloszenieId, status, pracownik)` na `:SystemHelpdesk`.
2. System pobiera przypisanego technika metodą `getTechnik()` obiektu `:Zgloszenie`
   i otrzymuje `technik : Technik`.
3. `alt [technik == pracownik]` – system wywołuje `zmienStatus(pracownik, status)` na `:Zgloszenie`:
   - `alt [przejście dozwolone]` – zgłoszenie zmienia status i wywołuje swoją prywatną metodę
     `dodajWpisHistorii(opis, autor)`, która tworzy nowy obiekt `:WpisHistorii` konstruktorem
     `WpisHistorii(dataUtworzenia, opisZmiany, autor)`. Zgłoszenie zwraca `sukces : bool (true)`,
     a system zwraca technikowi `wynik : bool (true)`.
   - `[else]` – przejście niedozwolone (np. NOWE → ROZWIAZANE): zgłoszenie zwraca
     `sukces : bool (false)`, a system zwraca `wynik : bool (false)`.
4. `[else]` – pracownik nie jest technikiem przypisanym do zgłoszenia: system od razu zwraca
   `wynik : bool (false)`, a zgłoszenie nie jest zmieniane.

Komunikaty zwrotne są narysowane dla wszystkich metod zwracających wartość. Metoda
`dodajWpisHistorii` zwraca `void`, więc nie ma komunikatu zwrotnego.
