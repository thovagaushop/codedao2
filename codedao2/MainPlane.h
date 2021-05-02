#pragma once
#ifndef MAIN_PLANE_H_
#define MAIN_PLANE_H_

#include <vector>
#include"commonFuntion.h"
#include"BaseObject.h"
#include"Bullet.h"


#define WIDTH_MAIN_PLANE 90
#define HEIGHT_MAIN_PLANE 75

#define PLAYER_SPEED 10

class MainPlane : public BaseObject {
public:
	MainPlane();
	~MainPlane();

	enum FlyType {
		FLY_RIGHT = 0,
		FLY_LEFT = 1,
	};
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void HandleEvents(SDL_Event events, SDL_Renderer* screen);
	void Move();
	void set_bullet_list(std::vector<Bullet*> bullet_list) { p_bullet_list_ = bullet_list; }
	std::vector<Bullet*> GetBulletList() const { return p_bullet_list_; }
	void HandleBullet(SDL_Renderer* des);
	void removeBullet(const int& idx);


private:
	float x_;
	float y_;

	std::vector<Bullet*> p_bullet_list_;
};
#endif // !MAIN_PLANE_H_
