#pragma once

#include "types.h"

#include <vector>

namespace pa {

class Cell;

class World
{
private:
  upair_t m_size;
  std::vector<Cell *> m_cells;

public:
  World(upair_t sz): m_size(sz) {
    m_cells.resize(sz.get_area());
  }
  ~World() {
  }
};

} // ns pa
