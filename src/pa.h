#pragma once

#include <hge.h>

#define PA_APPNAME "Playable Alpha"
#define PA_VERSION "0.0.1"

namespace pa {

class World;

class Game {
private:
  HGE *m_hge = nullptr;
  static Game *m_game;
  World *m_world = nullptr;

  static bool frame_func();

  void init_game();
public:
  Game();
  ~Game();

  void run();
};


} // ns pa
