#pragma once
#include <string>

class KategoriaProblemu {
private:
    std::string nazwa;

public:
    KategoriaProblemu(const std::string& nazwa);
    std::string getNazwa() const;
};
