#pragma once

#include <exception>
#include <string>

struct exception : std::exception {
    const std::string reason;
    exception(const std::string r = "unknown exception") : reason(r) { ; }
    const char *what() const noexcept { return reason.c_str(); }
};
