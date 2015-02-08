#include "graphics.h"
#include "pa.h"

#include <hge.h>

namespace pa {

Graphics::Graphics() {
  m_hge = hgeCreate(HGE_VERSION);
  m_hge->System_SetState(HGE_FRAMEFUNC, Game::frame_func);
  m_hge->System_SetState(HGE_RENDERFUNC, Game::render_func);
  m_hge->System_SetState(HGE_TITLE, PA_APPNAME " v" PA_VERSION);

  // Run in windowed mode
  // Default window size is 800x600
  m_hge->System_SetState(HGE_WINDOWED, true);
  m_hge->System_SetState(HGE_USESOUND, false);

  if (!m_hge->System_Initiate()) {
#ifdef PLATFORM_UNIX
    fprintf(stderr, "Error: %s\n", m_hge->System_GetErrorMessage());
#else
    MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
#endif
  }
}

Graphics::~Graphics() {
  m_hge->System_Shutdown();
  m_hge->Release();
}

} // ns pa
