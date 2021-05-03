#pragma once
#ifndef BULLET_H
#define BULLET_H
#include "BaseObject.h"
#include "CommonFuntion.h"

const int BULLET_WIDTH = 15;
const int BULLET_HEIGHT = 15;
const int BULLET_SPEED = 10;

// class Bullet : public BaseObject {
// public:
// 	Bullet();
// 	~Bullet();

// 	void set_x_(const int& x) { x_ = x; }
// 	void set_y_(const int& y) { y_ = y; }
// 	int get_x_() const { return x_; }
// 	int get_y_() const { return y_; }

// 	void set_is_move(const bool& ismove) { is_move_ = ismove; }
// 	bool get_is_move() const { return is_move_; } 

// 	void HandleEvents(SDL_Event events, SDL_Renderer* screen);
// 	void Move(const int x_border, const int y_border);
	

// private:
// 	int x_;
// 	int y_;
// 	bool is_move_;
// };

class Bullet: public BaseObject, public PooledObject {
private:
public:
	Bullet(){}
	~Bullet(){}

	void update(float dt){
		this.setPosition(x, y - BULLET_SPEED * dt/1000);
		if (y <= -rect_.h / 2) onDestroy();
	}
};

#endif // !BULLET_H_
