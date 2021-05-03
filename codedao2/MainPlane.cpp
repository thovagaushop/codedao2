#include"MainPlane.h"

// MainPlane::MainPlane() {
// }

// MainPlane::~MainPlane() {

// }

// void MainPlane::Show(SDL_Renderer* des)
// {
// 	BaseObject::render(des);
// }

// void MainPlane::HandleEvents(SDL_Event events, SDL_Renderer* screen) {
// 	if (events.type == SDL_KEYDOWN) {
// 		switch (events.key.keysym.sym)
// 		{
// 		case SDLK_UP:
// 			y_ = -PLAYER_SPEED; 
// 			break;
// 		case SDLK_DOWN:
// 			y_ = PLAYER_SPEED;
// 			break;
// 		case SDLK_RIGHT:
// 			x_ = PLAYER_SPEED;
// 			break;
// 		case SDLK_LEFT:
// 			x_ = -PLAYER_SPEED;
// 			break;
// 		default: break;
// 		}
// 	}
// 	else if (events.type == SDL_KEYUP) {
// 		switch (events.key.keysym.sym)
// 		{
// 		case SDLK_UP:
// 			y_ = 0;
// 			break;
// 		case SDLK_DOWN:
// 			y_ = 0;
// 			break;
// 		case SDLK_RIGHT:
// 			x_ = 0;
// 			break;
// 		case SDLK_LEFT:
// 			x_ = 0;
// 			break;
// 		default: break;
// 		}
// 	}
// 	else if (events.type == SDL_MOUSEBUTTONDOWN) {
// 		Bullet* p_bullet = new Bullet();
// 		if (events.button.button == SDL_BUTTON_LEFT) {
// 			Bullet* p_bullet = new Bullet();
// 			p_bullet->loadTexture("img//Bullet.png", screen); 
// 			p_bullet->setPosition(this->rect_.x + PLANE_WIDTH / 2 - 5, rect_.y);
// 			p_bullet->set_x_(20);
// 			p_bullet->set_is_move(true);

// 			p_bullet_list_.push_back(p_bullet);
// 		}

// 	}
// 	else if (events.type == SDL_MOUSEBUTTONUP) {

// 	}
// 	else {
// 		//Todo
// 	}
// }


// void MainPlane::Move() {
// 	rect_.x += x_;
// 	if (rect_.x < 0 || rect_.x + rect_.w > SCREEN_WIDTH) {
// 		rect_.x -= x_;
// 	}
// 	rect_.y += y_;
// 	if (rect_.y < 0 || rect_.y + rect_.h > SCREEN_HEIGHT) {
// 		rect_.y -= y_;
// 	}
// }


// void MainPlane::HandleBullet(SDL_Renderer* des) {
// 	for (int i = 0; i < p_bullet_list_.size(); i++) {
// 		Bullet* p_bullet = p_bullet_list_.at(i);
// 		if (p_bullet != NULL) {
// 			if (p_bullet->get_is_move() == true) {
// 				p_bullet->Move(SCREEN_WIDTH, SCREEN_HEIGHT);
// 				p_bullet->render(des);
// 			}
// 			else {
// 				p_bullet_list_.erase(p_bullet_list_.begin() + i);
// 				if (p_bullet != NULL) {
// 					delete p_bullet;
// 					p_bullet = NULL;
// 				}
// 			}
// 		}

// 	}
// }

// void MainPlane::removeBullet(const int& idx){
// 	for (int i = 0; i < p_bullet_list_.size(); i++) {
// 		if (idx < p_bullet_list_.size()) {
// 			Bullet* p_bullet = p_bullet_list_.at(idx);
// 			p_bullet_list_.erase(p_bullet_list_.begin() + idx);

// 			if (p_bullet != NULL) {
// 				delete p_bullet;
// 				p_bullet = NULL;
// 			}
// 		}
		
// 	}
// }
 



