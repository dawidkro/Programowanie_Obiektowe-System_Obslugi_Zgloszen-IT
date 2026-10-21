#pragma once
#include <string>

class Date {
private:
    std::string dataTekst;

public:
    Date(const std::string& dataTekst = "2026-01-01");
    std::string toString() const;
};
