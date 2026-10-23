1. Jako Zgłaszający
chcę stworzyć zgłoszenie z opisem problemu, priorytetem i kategorią,
aby Administrator mógł je ocenić, a następnie zdecydować, komu je przydzielić.

Kryterium akceptacji: tworzy się nowe zgłoszenie z unikalnym ID, opisem problemu, priorytetem i kategorią. Ma status „Nowe” i nie jest przypisane do żadnego technika. Do historii zgłoszenia dodawany jest wpis o jego utworzeniu (data i autor).



2. Jako Administrator
chcę przydzielić zgłoszenie wybranemu technikowi,
aby Technik wiedział, jakimi zgłoszeniami ma się zajmować.

Kryterium akceptacji: zgłoszenie zostaje przypisane do wybranego technika i pojawia się na liście jego zgłoszeń. Przydzielenie jest zapisywane w historii (data i autor). Nie da się przydzielić zgłoszenia, które ma status „Rozwiązane”.



3. Jako Technik
chcę zmienić status zgłoszenia i dodać do niego komentarz,
aby rejestrować postępy pracy i poinformować Zgłaszającego/Administratora, że zgłoszenie jest rozwiązane.

Kryterium akceptacji: status może zmienić tylko technik przypisany do zgłoszenia. Dozwolone są wyłącznie poprawne przejścia (Nowe → W trakcie; W trakcie → Oczekuje; Oczekuje -> W trakcie; W trakcie → Rozwiązane; Oczekuje -> Rozwiązane), a niedozwolone przejście jest odrzucane. Każda zmiana statusu automatycznie tworzy wpis w historii z datą, autorem i opisem zmiany. Dodany komentarz zapisuje się przy zgłoszeniu.



4. Jako Technik/Administrator
chcę wyświetlić listę zgłoszeń,
aby zobaczyć, co jest do zrobienia.

Kryterium akceptacji: system zwraca zgłoszenia, każde z ID, statusem, priorytetem, kategorią i opisem. Technik widzi tylko zgłoszenia przypisane do siebie, a Administrator widzi wszystkie.



5. Jako Technik/Administrator
chcę wyświetlić historię wpisów danego zgłoszenia,
aby kontrolować postępy prac i przypomnieć sobie, jak wyglądała praca nad zgłoszeniem.

Kryterium akceptacji: system wyświetla wszystkie wpisy historii wybranego zgłoszenia w kolejności chronologicznej, każdy z datą, autorem i opisem zmiany.



6. Jako Zgłaszający
chcę sprawdzić status mojego zgłoszenia,
aby wiedzieć, na jakim etapie są prace nad zgłoszeniem.

Kryterium akceptacji: po podaniu ID system wyświetla status zgłoszenia. Jeśli zgłoszenie o tym ID nie istnieje albo nie należy do tego zgłaszającego, system wyświetla odpowiedni komunikat.
