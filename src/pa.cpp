#include "pa.h"
#include "world.h"
#include "graphics.h"

#include <hge.h>

namespace pa {

Game *Game::m_game = nullptr;

Game::Game()
{
  m_game = this;
  m_gfx = new Graphics;

  init_game();
}

Game::~Game()
{
  delete m_gfx;
}

void Game::init_game()
{
  m_world = new World(upair_t(512, 256));
}

void Game::run()
{
  m_gfx->m_hge->System_Start();
}

// static
bool Game::frame_func()
{
  auto hge = m_game->m_gfx->m_hge;
  if (hge->Input_GetKeyState(HGEK_ESCAPE)) {
    return true;
  }

  return false;
}

// static
bool Game::render_func()
{
  m_game->m_world->render(m_game->m_gfx);
  return false;
}


} // ns pa

