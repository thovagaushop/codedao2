#include"BaseObject.h"

BaseObject::BaseObject() {
	texture = NULL;
	x = 0.0f;
	y = 0.0f;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
}

BaseObject::~BaseObject() {
	free();
}

bool BaseObject::loadTexture(std::string path, SDL_Renderer* screen) {
	free();
	SDL_Texture* new_texture = NULL;

	SDL_Surface* load_surface = IMG_Load(path.c_str());
	if (load_surface != NULL) {
		SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
		new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
		if (new_texture != NULL) {
			rect_.w = load_surface->w;
			rect_.h = load_surface->h;
		}
		SDL_FreeSurface(load_surface);
	}
	texture = new_texture;
	return texture != NULL;
}

void setPosition(int x, int y){
	this->x = x;
	this->y = y;
	rect_.x = (int)round(x - rect_.w/2);
	rect_.y = (int)round(y - rect_.h/2);
}

float getPositionX(){
	return x;
}

float getPositionY(){
	return y;
}

void setContentSize(int width, int height){
	rect_.w = width;
	rect_.h = height;
}

void BaseObject::render(SDL_Renderer* des, const SDL_Rect* clip) {
	SDL_Rect renderquad = { rect_.x, rect_.y , rect_.w , rect_.h };
	SDL_RenderCopy(des, texture, clip, &renderquad);
}

void BaseObject::free() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		rect_.w = 0;
		rect_.h = 0;
	}
}
