#include "world.h"
#include "cell.h"
#include "graphics.h"

#include <stddef.h>
#include <hge.h>

namespace pa {

//void World::set(upair_t pos, const Cell &new_value)
//{
//  paASSERT(pos.x <= m_size.x);
//  paASSERT(pos.y <= m_size.y);

//  size_t index = get_index(pos);
//  m_cells[index] = new_value;
//}

void World::generate()
{
  for (uint32_t y = 0; y < m_size.y; ++y) {
    for (uint32_t x = 0; x < m_size.x; ++x) {
      size_t index = get_index(x, y);

      Cell *nc = new Cell(cell::Empty, biome::Dirt);

      m_cells[index] = nc;
    }
  }
}

void World::render(Graphics *g)
{
  g->m_hge->Gfx_RenderLine(0.f, 0.f, 800.f, 600.f, ARGB(255, 255, 255, 255));
}


} // ns pa
