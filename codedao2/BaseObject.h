#pragma once
#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include "CommonFuntion.h"

class BaseObject {
public:
	BaseObject();
	~BaseObject();

	//Transformation
	void setPosition(float x, float y);
	float getPositionX();
	float getPositionY();
	void setContentSize(int width, int height);

	//Renderer
	SDL_Rect getRect() const { return rect_; }
	bool loadTexture(std::string path, SDL_Renderer* screen);
	void render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
	void free();

	//Logic
	virtual void update(float dt){}

protected:
	float x, float y;
	SDL_Texture* texture;
	SDL_Rect rect_;
};
#endif // !BASE_OBJECT_H_
