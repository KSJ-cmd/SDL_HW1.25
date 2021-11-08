#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include<vector>
#include"TextureManager.h"
#include"GameObject.h"
#include"Player.h"

class Game {
public:
static Game* Instance();
	~Game();

  bool Init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void Update();
	bool running();
	void handleEvents();
	void clean();

  void quit() {m_bRunning = false;}
	SDL_Renderer* getRenderer() const;

private:
	Game();
  static Game* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;

  std::vector<GameObject*> m_gameObjects;

	//� �Ʒ� Ŭ� �
	// SDL_Texture* m_pTexture;
	// SDL_Rect m_sourceRectangle;
	// SDL_Rect m_destinationRectangle;

};
#endif // !__GAME_H__