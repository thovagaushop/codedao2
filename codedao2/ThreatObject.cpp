#include "ThreatObject.h"

ThreatObject::ThreatObject() {
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_THREAT;
	rect_.h = HEIGHT_THREAT;

	x_ = 0;
	y_ = 0;
}

ThreatObject::~ThreatObject(){

}

void ThreatObject::Show(SDL_Renderer* des) {
	BaseObject::Render(des);
}

void ThreatObject::HandleMove(const int& x_border, const int& y_border) {
	rect_.y += y_;
	if (rect_.y > SCREEN_HEIGHT) {
		rect_.y = -50;
		int rand_x = rand() % 400;
		if (rand_x > SCREEN_WIDTH) {
			rand_x = SCREEN_WIDTH * 0.3;
		}
		rect_.x = rand_x;
	}
}

void ThreatObject::HandleEvent(SDL_Event events) {

}

void ThreatObject::Reset(const int& y_border) {
	rect_.y = y_border;
	int rand_x = rand() % 400;
	if (rand_x > SCREEN_WIDTH) {
		rand_x = SCREEN_WIDTH * 0.3;
	}
	rect_.x = rand_x;


}