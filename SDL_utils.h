#ifndef SDL_UTILS_H_INCLUDED
#define SDL_UTILS_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<bits/stdc++.h>



using namespace std;

//**************************************************************
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void TTF();
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);
SDL_Texture* loadText(SDL_Renderer* renderer, std::string text, TTF_Font* font, SDL_Color color);
string xucxac(const string a[],int b);
int* create_random_array(int size, int min_value, int max_value);
int thang(int x1,int x2,int x3,int x4,int x5,int x6,int k);



#endif // SDL_UTILS_H_INCLUDED
