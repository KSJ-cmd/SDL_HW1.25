#pragma once
#ifndef __BALL_H__
#define __BALL_H__
#include<iostream>
#include"SDL.h"
#include"SDLGameObject.h"


class Ball;

class MoveStrategy {
public:
	virtual void Move(Ball& ball)=0;
	virtual ~MoveStrategy() {};
};
class MoveY : public MoveStrategy {
public:
	void Move(Ball& ball) override;
};
class MoveX : public MoveStrategy {
public:
	void Move(Ball& ball) override;
};
class MoveXY : public MoveStrategy {
public:
	void Move(Ball& ball) override;
};

class DrawStrategy {
public:
	virtual void Draw(Ball& ball) = 0;
};

class Frame :public DrawStrategy {
public:
	virtual void Draw(Ball& ball) override;
};
class Angle :public DrawStrategy {
public:
	virtual void Draw(Ball& ball) override;
};

class Ball :public SDLGameObject {
public:
	Ball(const LoaderParams* pParams);

	virtual ~Ball();
	void Move();
	void SetSpeed(int x, int y);
	void Collision();
	void SetMoveStrategy(MoveStrategy* moveStrategy);
	void SetDrawStrategy(DrawStrategy* DrawStrategy);
	void update();
	void draw();

	void drawAngle();
private:
	std::string name;

	SDL_Texture* texture=nullptr;

	int xSpeed = 0;
	int ySpeed = 0;
	int angle = 0;
	MoveStrategy* moveStrategy = nullptr;
	DrawStrategy* drawStrategy = new Frame();
};

#endif // !__BALL_H__
