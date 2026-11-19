#include "KategoriaProblemu.h"

KategoriaProblemu::KategoriaProblemu(const std::string& nazwa)
    : nazwa_(nazwa) {}

std::string KategoriaProblemu::getNazwa() const {
    return nazwa_;
}
