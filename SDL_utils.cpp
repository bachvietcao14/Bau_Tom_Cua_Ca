#include "SDL_utils.h"
#include <bits/stdc++.h>
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer){
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr){
        cout<<"Unable to  load image " << path << " SDL_image Error: "
        << IMG_GetError() << endl;
    }
    else{
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(newTexture == nullptr)
            cout<<"Unable to create texture from " << path << " SDL Error: "
                << SDL_GetError()<< endl;
                SDL_FreeSurface( loadedSurface);
    }
    return newTexture;
}
SDL_Texture* loadText(SDL_Renderer* renderer, std::string text, TTF_Font* font, SDL_Color color) {
    // Tạo surface từ chuỗi văn bản
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == NULL) {
        std::cerr << "Unable to create surface from text! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return NULL;
    }

    // Tạo texture từ surface và trả về
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void TTF(){
    if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		exit(1);
	}
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
string xucxac(const string a[],int b){
  if (b==1)return a[0];
    else if(b==2)return a[1];
     else if (b==3)return a[2];
     else if(b==4)return a[3];
     else if(b==5)return a[4];
     else return a[5];

    }
int thang(int x1,int x2,int x3,int x4,int x5,int x6,int k){
    if(k==1)return x1;
    else if (k==2)return x2;
    else if (k==3)return x3;
    else if (k==4)return x4;
    else if (k==5)return x5;
    else if (k==6)return x6;
}

int* create_random_array(int size, int min_value, int max_value) {
    srand(time(nullptr));
    int* arr = new int[size];  // tÃ¡ÂºÂ¡o mÃ¡Â»â„¢t mÃ¡ÂºÂ£ng Ã„â€˜Ã¡Â»â„¢ng
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_value - min_value + 1) + min_value;  // tÃ¡ÂºÂ¡o ra giÃƒÂ¡ trÃ¡Â»â€¹ ngÃ¡ÂºÂ«u nhiÃƒÂªn trong phÃ¡ÂºÂ¡m vi tÃ¡Â»Â« min_value Ã„â€˜Ã¡ÂºÂ¿n max_value
    }
    return arr;
}
