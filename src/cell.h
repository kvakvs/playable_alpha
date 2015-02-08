#pragma once

#include "biome.h"

namespace pa {

namespace cell {
  typedef enum {
    Empty,
    Diggable,
    Hewable,
    Invulnerable,
    Liquid,
    Vegetation,
  } class_t;
} // ns cell

class Cell
{
protected:
  cell::class_t m_class = cell::Empty;
  biome::type_t m_biome = biome::Sky;

public:
  Cell() {}
  //Cell(const Cell &other) = default;

  Cell(cell::class_t cls, biome::type_t bi)
    : m_class(cls), m_biome(bi) {
  }
  //~Cell();

  bool is_passable() const {
    return m_class == cell::Empty || m_class == cell::Liquid;
  }

  bool is_see_through() const {
    return m_class == cell::Empty || m_class == cell::Liquid;
  }
};

} // ns pa
