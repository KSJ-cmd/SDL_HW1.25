#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams)
    :SDLGameObject(pParams) {}
  void Player::draw() {
      SDLGameObject::draw();
  }
   void Player::update() {
       handleInput();
       //m_position.setX(m_position.getX()+1);
       m_currentFrame = ((SDL_GetTicks() / 100) % 6);
       SDLGameObject::update();
   }
   void Player::clean(){}
   
   void Player::handleInput() {
       if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
           std::cout << "Right" << std::endl;
           m_velocity.setX(2);
       }
       if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
           std::cout << "Left" << std::endl;
           m_velocity.setX(-2);
       }
       if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
           std::cout << "Up" << std::endl;
           m_velocity.setY(-2);
       }
       if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
           std::cout << "Down" << std::endl;
           m_velocity.setY(2);
       }

   }