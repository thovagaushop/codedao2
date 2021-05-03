#include <vector>
#include "CommonFuntion.h"
#include "BaseObject.h"
#include "MainPlane.h"
#include "ThreatObject.h"
#include "GameManager.h"

bool InitData() {
	int ret = SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER);
	if (ret < 0) return false;

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	g_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(g_window) {
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if(g_screen) {
			SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
			int imgFlags = IMG_INIT_PNG|IMG_INIT_JPG;
			if (IMG_Init(imgFlags) || !imgFlags) {
				return true;
			}
		}
	}
	return false;
}

void Close() {
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* argv[]) {
	//init window, screen, image
	if (InitData() == false) return -1;
	//init background - a base object
	BaseObject g_background;
	if (!g_background.loadTexture("img//BG.png", g_screen)) return -1;
	g_background.setContentSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	float deltaTime = 0;
	
	GameManager gameManager(g_screen);
	gameManager.initGame();
	bool running = true;
	while(running){
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime += (NOW - LAST) * 1000 / (float)SDL_GetPerformanceFrequency();

		//handle events
		while (SDL_PollEvent(&g_event) != 0){
			if (g_event.type == SDL_QUIT){
				running = false;
			}

			gameManager.handleEvent(g_event);
		}

		//logic
		while(deltaTime > FRAME_TIME){
			gameManager.update(FRAME_TIME);
			deltaTime -= FRAME_TIME;
		}

		//render
		SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
		SDL_RenderClear(g_screen);
		g_background.render(g_screen, NULL);
		gameManager.render();
		SDL_RenderPresent(g_screen);
	}

	//init player's plane
	// MainPlane p_player;
	// p_player.loadTexture("img//DI.PNG", g_screen);
	// p_player.setPosition(SCREEN_WIDTH / 2 - PLANE_WIDTH / 2, SCREEN_HEIGHT - PLANE_HEIGHT - 10);
	
	// ThreatObject* p_threat = new ThreatObject();
	// p_threat->loadTexture("img//Threat.png", g_screen);
	// p_threat->setPosition(0, -50);
	// p_threat->set_y_(3);

	// bool is_Quit = false; 
	// while (!is_Quit) {
	// 	while (SDL_PollEvent(&g_event) != 0) {
	// 		if (g_event.type == SDL_QUIT) {
	// 			is_Quit = true;
	// 		}

	// 		p_player.HandleEvents(g_event, g_screen);
	// 	}

	// 	SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
	// 	SDL_RenderClear(g_screen);

	// 	g_background.render(g_screen, NULL);

	// 	p_player.Move();
	// 	p_player.HandleBullet(g_screen);
	// 	p_player.Show(g_screen);
		
	// 	p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
	// 	p_threat->Show(g_screen);
		
	// 	bool is_collide = SDLCommonFuntion::CheckCollide(p_player.getRect(), p_threat->getRect());
	// 	if (is_collide == true) {
	// 		MessageBox(NULL, L"Game over", NULL, NULL);
	// 		break;
	// 	}

	// 	std::vector<Bullet*> bullet_list = p_player.GetBulletList();
	// 	for (int k = 0; k < bullet_list.size(); k++) {
	// 		Bullet* p_bullet = bullet_list.at(k);
	// 		if (p_bullet != NULL) {
	// 			bool ret_collide = SDLCommonFuntion::CheckCollide(p_bullet->getRect(), p_threat->getRect());
	// 			if (ret_collide == true) {
	// 				p_threat->Reset(-50);
	// 				p_player.removeBullet(k);
	// 			}
	// 		}
	// 	}


	// 	SDL_RenderPresent(g_screen);
	// 	SDL_Delay(15);
	// }
	
	// delete p_threat;

	//free memory
	Close();
	return 0;
}