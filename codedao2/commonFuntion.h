#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

#include <Windows.h>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event; 

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BPP = 32;
const int FRAME_TIME = 20;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

typedef struct Input {
	int left, right, up, down;
};

namespace SDLCommonFuntion {
	bool CheckCollide(const SDL_Rect& obj1, const SDL_Rect& obj2);
}

template <typename T>
class ObjectPool{
	vector<T*> pooledObjects;
	vector<T*> activeObjects;
public:
	ObjectPool(){}
	~ObjectPool(){
		for (int i = 0; i < activeObjects.size(); i++){
			delete activeObjects[i];
		)
		for (int i = 0; i < pooledObjects.size(); i++){
			delete pooledObjects[i];
		}
		activeObjects.clear();
		pooledObjects.clear();
	}

	T* pop(){
		T *object;
		if (pooledObjects.size() == 0){
			object = new T();
			object->setPool(this);
		}
		else object = pooledObject.pop_back();
		activeObjects.push_back(object);
		return object;
	}

	void push(T* item){
		for (int i = 0; i < activeObjects.size(); i++){
			if (item == activeObjects[i]){
				activeObjects.erase(i);
				break;
			}
		}
		pooledObjects.push_back(item);
	}

	void reset(){
		for (int i = 0; i < activeObjects.size(); i++){
			pooledObjects.push_back(activeObjects[i]);
		}
		activeObjects.clear();
	}

	vector<T*> getActiveObjects(){
		return activeObjects;
	}
};

class PooledObject{
private:
	ObjectPool<PooledObject> *pool;
public:
	void setPool(ObjectPool<PooledObject> *pool){
		this->pool = pool;
	}

	void onDestroy(){
		this->pool->push(this);
	}
};

#endif