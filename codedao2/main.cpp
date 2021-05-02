#include<vector>
#include"commonFuntion.h"
#include"BaseObject.h"
#include"MainPlane.h"
#include"ThreatObject.h"




BaseObject g_background;

bool InitData() {
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0) return false;

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	g_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (g_window == NULL) {
		success = false;
	}
	else {
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_screen == NULL) {
			success = false;
		}
		else {
			SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
			int imgFlags = IMG_INIT_PNG;
			if (!IMG_Init(imgFlags) && imgFlags) {
				success = false;
			}

		}
	}
	return success;
}

bool LoadBackground() {
	bool ret = g_background.LoadImg("img//BG.png", g_screen);
	if (ret == false) return false;

	return ret;
}

void close() {
	g_background.Free();
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	IMG_Quit();
	SDL_Quit();

}


int main(int argc, char* argv[]) {
	if (InitData() == false) return -1;
	if (LoadBackground() == false) return -1;
	

	MainPlane p_player;
	p_player.LoadImg("img//DI.PNG", g_screen);
	p_player.SetRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT - HEIGHT_MAIN_PLANE - 10);
	
	
	ThreatObject* p_threat = new ThreatObject();
	p_threat->LoadImg("img//Threat2.png", g_screen);
	p_threat->SetRect(0, -50);
	p_threat->set_y_(3);


	bool is_Quit = false; 
	while (!is_Quit) {
		while (SDL_PollEvent(&g_event) != 0) {
			if (g_event.type == SDL_QUIT) {
				is_Quit = true;
			}

			p_player.HandleEvents(g_event, g_screen);
		}
		


		SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
		SDL_RenderClear(g_screen);

		g_background.Render(g_screen, NULL);

		p_player.Move();
		p_player.HandleBullet(g_screen);
		p_player.Show(g_screen);
		
		p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
		p_threat->Show(g_screen);



		
		bool is_collide = SDLCommonFuntion::CheckCollide(p_player.GetRect(), p_threat->GetRect());
		if (is_collide == true) {
			MessageBox(NULL, L"Game over", NULL, NULL);
			break;
		}

		std::vector<Bullet*> bullet_list = p_player.GetBulletList();
		for (int k = 0; k < bullet_list.size(); k++) {
			Bullet* p_bullet = bullet_list.at(k);
			if (p_bullet != NULL) {
				bool ret_collide = SDLCommonFuntion::CheckCollide(p_bullet->GetRect(), p_threat->GetRect());
				if (ret_collide == true) {
					p_threat->Reset(-50);
					p_player.removeBullet(k);
				}
			}
		}


		SDL_RenderPresent(g_screen);
		SDL_Delay(15);
	}
	
	delete p_threat;
	close();
	return 0;
}