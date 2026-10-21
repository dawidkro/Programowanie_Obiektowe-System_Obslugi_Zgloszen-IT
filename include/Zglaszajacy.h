#pragma once
#include "PracownikSystemu.h"

class Zglaszajacy : public PracownikSystemu {
public:
    Zglaszajacy(int id, const std::string& imie, const std::string& nazwisko);
    bool czyMaDostep(const Zgloszenie& zgloszenie) const override;
};
