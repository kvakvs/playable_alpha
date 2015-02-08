#include "world.h"
#include "cell.h"

#include <stddef.h>

namespace pa {

void World::set(upair_t pos, const Cell &new_value)
{
  paASSERT(pos.x <= m_size.x);
  paASSERT(pos.y <= m_size.y);

  size_t index = get_index(pos);
  m_cells[index] = new_value;
}

void World::generate()
{
  for (uint32_t y = 0; y < m_size.y; ++y) {
    for (uint32_t x = 0; x < m_size.x; ++x) {
      size_t index = get_index(x, y);

      Cell nc(cell::Empty, biome::Dirt);

      m_cells[index] = nc;
    }
  }
}


} // ns pa
