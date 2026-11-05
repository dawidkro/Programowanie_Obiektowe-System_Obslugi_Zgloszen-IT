#include "KategoriaProblemu.h"

KategoriaProblemu::KategoriaProblemu(const std::string& nazwa) : nazwa(nazwa) {}

std::string KategoriaProblemu::getNazwa() const {
    return nazwa;
}
