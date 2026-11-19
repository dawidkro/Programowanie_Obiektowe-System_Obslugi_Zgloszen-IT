#pragma once
#include <string>
enum class Status {
    NOWE,
    W_TRAKCIE,
    OCZEKUJE,
    ROZWIAZANE
};

std::string statusNaTekst(Status status);
