#pragma once
#ifndef BULLET_H_
#define BULLET_H_
#include "BaseObject.h"


#define WIDTH_BULLET 15
#define HEIGHT_BULLET 15;


class Bullet : public BaseObject {
public:
	Bullet();
	~Bullet();


	void set_x_(const int& x) { x_ = x; }
	void set_y_(const int& y) { y_ = y; }
	int get_x_() const { return x_; }
	int get_y_() const { return y_; }

	void set_is_move(const bool& ismove) { is_move_ = ismove; }
	bool get_is_move() const { return is_move_; } 

	void HandleEvents(SDL_Event events, SDL_Renderer* screen);
	void Move(const int x_border, const int y_border);
	

	//void setWidthHeight(const int& width, const int& height) { rect_.w = width; rect_.h = height; }

private:
	int x_;
	int y_;
	bool is_move_;
};
#endif // !BULLET_H_
