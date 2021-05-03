#pragma once
#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H

#include "BaseObject.h"
#include "CommonFuntion.h"

const int THREAT_WIDTH = 90;
const int THREAT_HEIGHT = 75;
const int THREAT_SPEED = 100;

// class ThreatObject : public BaseObject {

// public:
// 	ThreatObject();
// 	~ThreatObject();

// 	void set_x_(const int& x) { x_ = x; }
// 	void set_y_(const int& y) { y_ = y; }
// 	int get_x_() const { return x_; }
// 	int get_y_() const { return y_; }
// 	void Show(SDL_Renderer* des);
// 	void HandleMove(const int& x_border, const int& y_border);
// 	void HandleEvent(SDL_Event events);
// 	void Reset(const int& y_border);
// private:
// 	int x_;
// 	int y_;

// };

class ThreatObject: public BaseObject, public PooledObject{
private:
	int health;
	int point;
public:
	ThreatObject(){
		health = 0;
		point = 0;
	}
	~ThreatObject(){}

	void reset(SDL_Renderer* screen){
		int r = (int)floor((float)rand() / RAND_MAX * 5);
		string path = "img//Threat" + to_string(r) + "png";
		loadTexture(path, screen);
		health = r + 1;
		point = health * 2;
	}

	void update(float dt){
		this->setPosition(x, y + THREAT_SPEED * dt/1000);
		if (y > SCREEN_HEIGHT - rect_.h/2f) onDestroy();
	}

	void onHit(){
		if (--health <= 0){ 
			onDestroy();
			return true;
		}
		else return false;
	}
};

#endif // !_THREAT_OBJECT_H_
