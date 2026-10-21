#pragma once
#include "PracownikSystemu.h"

class Technik : public PracownikSystemu {
public:
    Technik(int id, const std::string& imie, const std::string& nazwisko);
    bool czyMaDostep(const Zgloszenie& zgloszenie) const override;
};
