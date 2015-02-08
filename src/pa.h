#pragma once

#define PA_APPNAME "Playable Alpha"
#define PA_VERSION "0.0.1"

namespace pa {

class Graphics;
class World;

class Game {
protected:
  friend class Graphics;

  static Game *m_game;
  Graphics *m_gfx = nullptr;
  World *m_world = nullptr;

  static bool frame_func();
  static bool render_func();

  void init_game();

public:
  Game();
  ~Game();

  void run();
};


} // ns pa
