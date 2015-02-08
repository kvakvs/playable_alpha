#pragma once

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

public:
  Cell() {
  }
  virtual ~Cell();

  virtual bool is_passable() = 0;
  virtual bool is_see_through() = 0;
};

} // ns pa
