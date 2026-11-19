#pragma once
#include <string>

class KategoriaProblemu {
public:
    explicit KategoriaProblemu(const std::string& nazwa);

    std::string getNazwa() const;

private:
    std::string nazwa_;
};
