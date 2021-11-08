#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<vector>
#include<list>
#include<memory>
//#include"Nation.h"

#include"Game.h"
#include"TextureManager.h"
#include"Player.h"
#include"Enemy.h"
#include"InputHandler.h"
#include"Ball.h"
#include"Map.h"

Game* Game::s_pInstance = 0;

Game* Game::Instance()
{
	if (s_pInstance == 0) {
		s_pInstance = new Game();
	}
	return s_pInstance;
}

Game::Game()
{
	
}
Game::~Game() {
	
	m_gameObjects.clear();
	m_gameObjects.shrink_to_fit();
	std::cout << "Game end" << std::endl;
}
bool Game::Init(const char* title, int xpos, int ypos, int width, int height, int flags){
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    m_pWindow =SDL_CreateWindow(title, xpos,  ypos,  width,  height,  flags);
	if (m_pWindow != 0) {
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		TextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer);
		TextureManager::Instance()->load("images/main_play_place_0.png", "BG_main", m_pRenderer);


		m_gameObjects.push_back(new SDLGameObject(new LoaderParams(0, 0, 1600, 900, "BG_main")));
		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(400, 400, 128, 82, "animate")));
		Ball* ball = new Ball(new LoaderParams(400, 400, 128, 82, "animate"));
		ball->SetMoveStrategy(new MoveXY());
		m_gameObjects.push_back(ball);
		Ball* ball2 = new Ball(new LoaderParams(400, 400, 128, 82, "animate"));
		ball2->SetDrawStrategy(new Angle());
		m_gameObjects.push_back(ball2);
		m_gameObjects.push_back(new Map(new LoaderParams(100, 100, 128, 82, "")));


	}
    else{
      return false;
    }
  }
  else {
    return false;
  }
  m_bRunning = true;
  return true;
}

void Game::Update() {
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	for (std::vector<GameObject*>::iterator iter = m_gameObjects.begin(); iter != m_gameObjects.end(); iter++) {
		(*iter)->update();
	}
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	
	/*for (std::list<Image*> i : Image::g_Surfaces) {
		for (Image* image : i) {
			
			SDL_Texture* m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, image->GetSurface());
			SDL_RenderCopy(m_pRenderer, m_pTexture, image->Size(), image->Position());
			SDL_Delay(10);
			image->MovePos();
		}
	}*/

	for (std::vector<GameObject*>::iterator iter = m_gameObjects.begin(); iter != m_gameObjects.end(); iter++) {
		(*iter)->draw();
	}

	SDL_RenderPresent(m_pRenderer);
}

bool Game::running() {
	return m_bRunning;
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
}

void Game::clean() {
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

SDL_Renderer* Game::getRenderer() const
{
	return m_pRenderer;
}

// void Game::ResetTexture()
// {
// 	for (std::list<Image*> i : Image::g_Surfaces) {
// 		std::cout << "list size: " << i.size() << std::endl;
// 		for (Image* image : i) {
// 			delete image;
// 		}
// 	}
// 	Image::g_Surfaces.clear();

// 	//Image::g_renderer.clear();
// }
