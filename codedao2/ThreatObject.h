#pragma once
#ifndef _THREAT_OBJECT_H_
#define _THREAT_OBJECT_H_

#include"BaseObject.h"
#include"commonFuntion.h"

#define WIDTH_THREAT 90
#define HEIGHT_THREAT 75

class ThreatObject : public BaseObject {

public:
	ThreatObject();
	~ThreatObject();

	void set_x_(const int& x) { x_ = x; }
	void set_y_(const int& y) { y_ = y; }
	int get_x_() const { return x_; }
	int get_y_() const { return y_; }
	void Show(SDL_Renderer* des);
	void HandleMove(const int& x_border, const int& y_border);
	void HandleEvent(SDL_Event events);
	void Reset(const int& y_border);
private:
	int x_;
	int y_;

};

#endif // !_THREAT_OBJECT_H_
