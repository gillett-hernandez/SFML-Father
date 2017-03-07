#include "Info.hpp"

std::string Info::getInfo() {
    return this->info;
}

void Info::setInfo(std::string info) {
    this->info = info;
}

Info::Info() {
    this->info = std::string("No info available.");
}

Info::~Info() {
}