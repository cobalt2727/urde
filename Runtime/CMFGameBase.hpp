#pragma once

#include "Runtime/CIOWin.hpp"

namespace urde {

class CMFGameBase : public CIOWin {
public:
  explicit CMFGameBase(const char* name) : CIOWin(name) {}
};

class CMFGameLoaderBase : public CIOWin {
public:
  explicit CMFGameLoaderBase(const char* name) : CIOWin(name) {}
};

} // namespace urde
