#include "pa.h"

#ifdef PLATFORM_UNIX
int main(int /*argc*/, char * /*argv*/ [])
#else
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#endif
{
  pa::Game g;
  g.run();

  return 0;
}
