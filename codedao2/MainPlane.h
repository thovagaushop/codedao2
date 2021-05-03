#pragma once
#ifndef MAIN_PLANE_H
#define MAIN_PLANE_H

#include <vector>
#include "CommonFuntion.h"
#include "BaseObject.h"

const int PLANE_WIDTH = 90
const int PLANE_HEIGHT = 75
const int PLANE_SPEED = 10;
const int DELAY_BETWEEN_BULLET = 0.5;

// #define PLAYER_SPEED 10

// class MainPlane : public BaseObject {
// public:
// 	MainPlane();
// 	~MainPlane();

// 	enum FlyType {
// 		FLY_RIGHT = 0,
// 		FLY_LEFT = 1,
// 	};
	
// 	void Show(SDL_Renderer* des);
// 	void HandleEvents(SDL_Event events, SDL_Renderer* screen);
// 	void Move();
// 	void set_bullet_list(std::vector<Bullet*> bullet_list) { p_bullet_list_ = bullet_list; }
// 	std::vector<Bullet*> GetBulletList() const { return p_bullet_list_; }
// 	void HandleBullet(SDL_Renderer* des);
// 	void removeBullet(const int& idx);

// private:
// 	float x_;
// 	float y_;

// 	std::vector<Bullet*> p_bullet_list_;
// };

class MainPlane: public BaseObject {
	GameManager *gameManager;
	vector<SDLKey> controlBuffer;
	bool isShooting;
	float shootTimer;
public:
	MainPlane(GameManager *gameManager): gameManager(gameManager){
		controlBuffer.clear();
		isShooting = false;
	}
	~MainPlane(){}

	void resetGame(){
		this.isShooting = false;
		this->controlBuffer.clear();
		this->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT - rect_.h/2 - 5);
	}

	void onControlDown(SDLKey key){
		bool contain = false;
		for (int i = 0; i < controlBuffer.size(); i++){
			if (controlBuffer[i] == key){
				contain = true; break;
			}
		}
		if (!contain){
			controlBuffer.push_back(key);
		}
	}

	void onControlUp(SDLKey key){
		int index = -1;
		for (int i = 0; i < controlBuffer.size(); i++){
			if (controlBuffer[i] == key){
				index = i; break;
			}
		}
		if (index != -1){
			controlBuffer.erase(index);
		}
	}

	void onStartShooting(){
		if (!isShooting){
			isShooting = true;
			onShoot();
			shootTimer = DELAY_BETWEEN_BULLET * 1000;
		}
	}
	
	void onStopShooting(){
		if (isShooting){
			isShooting = false;
		}
	}

	void onShoot(){
		gameManager->spawnBullet(x, y - rect_.h/2f);
	}

	void update(float dt){
		float deltaX = 0.0f;
		if (controlBuffer.size() > 0){
			switch(controlBuffer[0]){
				case SDLK_RIGHT:
					deltaX = PLANE_SPEED * dt/1000;
					break;
				case SDLK_LEFT:
					deltaX = -PLANE_SPEED * dt/1000;
					break;
			}
		}
		float _x = x + deltaX;
		if (_x < rect_.w/2f) _x = rect_.w/2f;
		if (_x > SCREEN_WIDTH - rect_.w/2f) _x = SCREEN_WIDTH - rect_.w/2f;

		if (isShooting){
			shootTimer -= dt;
			if (shootTimer <= 0){
				shooTimer += DELAY_BETWEEN_BULLET * 1000;
				onShoot();
			}
		}
	}
}

#endif // !MAIN_PLANE_H_
