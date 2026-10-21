#pragma once
#include <string>

class Zgloszenie;

class PracownikSystemu {
private:
    int id;
    std::string imie;
    std::string nazwisko;

public:
    PracownikSystemu(int id, const std::string& imie, const std::string& nazwisko);
    virtual ~PracownikSystemu() = default;

    virtual bool czyMaDostep(const Zgloszenie& zgloszenie) const = 0;

    int getId() const;
    std::string getImie() const;
    std::string getNazwisko() const;
};
