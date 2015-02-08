#pragma once

#include <stdint.h>

namespace pa {

template <typename ComponentType>
class Pair
{
public:
  ComponentType x, y;

  Pair(): x(0), y(0) {
  }
  Pair(const Pair &other): x(other.x), y(other.y) {
  }
  Pair(ComponentType xx, ComponentType yy): x(xx), y(yy) {
  }

  ~Pair() {
  }

  ComponentType get_area() const {
    return x * y;
  }
};

typedef Pair<int32_t> ipair_t;
typedef Pair<uint32_t> upair_t;

} // ns pa
