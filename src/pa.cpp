#include "pa.h"
#include "world.h"

namespace pa {

Game *Game::m_game = nullptr;

Game::Game()
{
  m_game = this;
  m_hge = hgeCreate(HGE_VERSION);
  m_hge->System_SetState(HGE_FRAMEFUNC, Game::frame_func);
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

  init_game();
}

Game::~Game()
{
  m_hge->System_Shutdown();
  m_hge->Release();
}

void Game::init_game()
{
  m_world = new World(upair_t(512, 256));
}

void Game::run()
{
  m_hge->System_Start();
}

// static
bool Game::frame_func()
{
  if (m_game->m_hge->Input_GetKeyState(HGEK_ESCAPE)) {
    return true;
  }

  return false;
}


} // ns pa

