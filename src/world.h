#pragma once

#include "types.h"
#include "debug.h"

#include <vector>

namespace pa {

class Graphics;
class Cell;

class World
{
private:
  upair_t m_size;
  std::vector<Cell *> m_cells;

  size_t get_index(upair_t pos) const {
    return pos.x + pos.y * m_size.x;
  }
  size_t get_index(uint32_t x, uint32_t y) const {
    return x + y * m_size.x;
  }

public:
  World(upair_t sz): m_size(sz) {
    m_cells.resize(sz.get_area());
    std::fill(m_cells.begin(), m_cells.end(), nullptr);
  }
  ~World() {
  }

  Cell &get(upair_t pos) {
    paASSERT(pos.x <= m_size.x);
    paASSERT(pos.y <= m_size.y);
    return *m_cells[get_index(pos)];
  }
  //void set(upair_t pos, const Cell &new_value);
  void generate();
  void render(Graphics *g);
};

} // ns pa
