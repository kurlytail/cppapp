#ifndef __COMPANY_H__
#define __COMPANY_H__

#include <string>

namespace stocklib {

class Company {

private:
  const std::string _tickerSymbol;

public:
  Company(const std::string &tickerSymbol) : _tickerSymbol(tickerSymbol) {}

  const auto getTickerSymbol() { return _tickerSymbol; }
};

} // namespace stocklib

#endif