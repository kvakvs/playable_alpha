#pragma once

#include <cstdio>
#include <cstdlib>

#define paASSERT(COND) if (!(COND)) {\
    std::fprintf(stderr, "ASSERTION: %s\n", #COND);\
    std::abort(); \
  }
