#include "pa.h"

#ifdef __linux
int main(int /*argc*/, char * /*argv*/ [])
#else
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#endif
{
  pa::Game g;
  g.run();

  return 0;
}
