#pragma once

#include <stdint.h>

namespace pa {

template <typename ComponentType>
class Pair
{
public:
  ComponentType m_x, m_y;

  Pair(): m_x(0), m_y(0) {
  }
  Pair(const Pair &other): m_x(other.m_x), m_y(other.m_y) {
  }
  Pair(ComponentType x, ComponentType y): m_x(x), m_y(y) {
  }

  ~Pair() {
  }

  ComponentType get_area() const {
    return m_x * m_y;
  }
};

typedef Pair<int32_t> ipair_t;
typedef Pair<uint32_t> upair_t;

} // ns pa
