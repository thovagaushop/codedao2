#include "bullet.h"

Bullet::Bullet() {
	x_ = 0;
	y_ = 0;
	is_move_ = false;
}

Bullet::~Bullet() {


}

void Bullet::HandleEvents(SDL_Event events, SDL_Renderer* screen) {

}

void Bullet::Move(const int x_border, const int y_border) {

	rect_.y -= 5;
	if (rect_.y < 0) {
		is_move_ = false;
	}

}
