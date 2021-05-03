#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "MainPlane.h"
#include "Bullet.h"
#include "ThreatObject"
#include "commonFuntion.h";

const int MIN_DELAY_BETWEEN_THREAT = 1000;
const int MAX_DELAY_BETWEEN_THREAT = 100;
const int TIME_TO_DECREASE_DELAY = 2
const int DELAY_DECREASE_EACH_TIME = 5;

class GameManager{
    ObjectPool<Bullet> bulletPool;
    ObjectPool<ThreatObject> threatPool;
    MainPlane plane;
    int state;
    int points;
    SDL_Renderer* g_screen;
public:
    const int STATE_WAIT = -1;
    const int STATE_READY = 0;
    const int STATE_RUN = 1;
    const int STATE_END = 2;

    GameManager(SDL_Renderer* g_screen): g_screen(g_sreen){}

    void initGame(){
        state = GameManager::STATE_WAIT;
        srand(time(NULL));
        
        //preload plane
        plane = MainPlane(this);
        plane.loadTexture("img//DI.PNG", g_screen);

        //preload menu
        resetGame();
    }

    void resetGame(){
        state = GameManager::STATE_READY;
        plane.resetGame();
        bulletPool.reset();
        threatPool.reset();
    }

    void startGame(){
        state = GameManager::STATE_RUN;

    }

    void endGame(){
        state = GameManager::STATE_END;
    }

    void handleEvent(SDL_Event event){
        switch(state){
            case GameManager::STATE_WAIT: break;
            case GameManager::STATE_READY: 
                if (event.type == SDL_KEYUP){
                    if (event.key.keysym.sym == SDLK_RETURN) startGame();
                }
                break;
            case GameManager::STATE_RUN: break;
                switch(event.type){
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT)
                            plane.onControlDown(event.key.keysym.sym);
                        else if (event.key.keysym.sym == SDLK_SPACE)
                            plane.onStartShooting();
                        break;
                    case SDL_KEYUP:
                        if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT)
                            plane.onControlUp(event.key.keysym.sym);
                        else if (event.key.keysym.sym == SDLK_SPACE)
                            plane.onStopShooting();
                        break;
                }
            case GameManager::STATE_END: 
                if (event.type == SDL_KEYUP){
                    if (event.key.keysym.sym == SDLK_RETURN) resetGame();
                }
                break;
        }
    }

    void update(float dt){
        switch(state){
            case GameManager::STATE_WAIT: break;
            case GameManager::STATE_READY: break;
            case GameManager::STATE_RUN:
                //update positions
                plane.update(dt);
                vector<Bullet*> bullets;
                vector<ThreatObject*> threats;
                bullets = bulletPool.getActiveObjects();
                for (int i = 0; i < bullets.size(); i++) bullets[i].update(dt);
                threats = threatPool.getActiveObjects();
                for (int i = 0; i < threats.size(); i++) threats[i].update(dt);
                
                //detect collision bullets - threats
                bullets = bulletPool.getActiveObjects();
                threats = threatPool.getActiveObjects();
                for (int i = 0; i < bullets.size(); i++){
                    for (int j = 0; j < threats.size(); j++){
                        Bullet *bullet = bullets[i];
                        ThreatObject *threat = threats[i];
                        if (SDLCommonFuntion::CheckCollide(bullet->getRect(), threat->getRect())){
                            bullet->onDestroy();
                            if (threat->onHit()){
                                points += threat->point;
                            };
                            break;
                        }
                    }
                }

                //detect collision threats - plane
                threats = threatPool.getActiveObjects();
                for (int i = 0; i < threats.size(); i++){
                    ThreatObject *threat = threats[i];
                    if (SDLCommonFuntion::CheckCollide(threat->getRect(), plane->getRect())){
                        endGame();
                    }
                }

                break;
            case GameManager::STATE_END: break;
        }
    }

    void render(){
        switch(state){
            case GameManager::STATE_WAIT: break;
            case GameManager::STATE_READY: break;
                plane.render(g_screen);
            case GameManager::STATE_RUN:
                plane.render(g_screen);
                vector<Bullet*> bullets = bulletPool.getActiveObjects();
                for (int i = 0; i < bullets.size(); i++){
                    bullets[i]->render(g_screen);
                }
                vector<ThreatObject*> threats = threatPool.getActiveObjects();
                for (int i = 0; i < threats.size(); i++){
                    threats[i]->render(g_screen);
                }
                break;
            case GameManager::STATE_END:
                break;
    }

    void spawnBullet(float x, float y){
        Bullet* bullet = bulletPool.pop();
        bullet->setPosition(x, y);
    }

    void spawnThreat(){
        
    }
};

#endif