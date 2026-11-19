#pragma once
#include <string>

class Date {
public:
    explicit Date(const std::string& data_tekst = "2026-01-01");

    static Date teraz();

    std::string toString() const;

private:
    std::string data_tekst_;
};
