#pragma once
#include <string>

class Zgloszenie;

class PracownikSystemu {
public:
    PracownikSystemu(int id, const std::string& imie,
                     const std::string& nazwisko);
    virtual ~PracownikSystemu() = default;

    virtual bool czyMaDostep(const Zgloszenie& zgloszenie) const = 0;

    int getId() const;
    std::string getImie() const;
    std::string getNazwisko() const;

private:
    int id_;
    std::string imie_;
    std::string nazwisko_;
};
