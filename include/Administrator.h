#pragma once
#include "PracownikSystemu.h"

class Administrator : public PracownikSystemu {
public:
    Administrator(int id, const std::string& imie, const std::string& nazwisko);
    bool czyMaDostep(const Zgloszenie& zgloszenie) const override;
};
