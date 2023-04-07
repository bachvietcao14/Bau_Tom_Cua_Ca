#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <bits/stdc++.h>


using namespace std;

//**************************************************************
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
const string WINDOW_TITLE = "Keyboard in SDL";
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void TTF();
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);
SDL_Texture* loadText(SDL_Renderer* renderer, std::string text, TTF_Font* font, SDL_Color color);
const string a[6]={"photos/naipro.png","photos/baupro.png","photos/meopro.png","photos/capro.png","photos/cuapro.png","photos/tompro.png"};
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
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_value - min_value + 1) + min_value;  // tÃƒ ¡Ã‚ ºÃ‚ ¡o ra giÃƒÆ’Ã‚ ¡ trÃƒ ¡Ã‚ »Ã¢â‚¬ ¹ ngÃƒ ¡Ã‚ ºÃ‚ «u nhiÃƒÆ’Ã‚ ªn trong phÃƒ ¡Ã‚ ºÃ‚ ¡m vi tÃƒ ¡Ã‚ »Ã‚ « min_value Ãƒâ€žÃ¢â‚¬ËœÃƒ ¡Ã‚ ºÃ‚ ¿n max_value
    }
    return arr;
}

//**************************************************************
int main(int argc, char* argv[])
{

    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    TTF();
    SDL_Color textColor = { 255, 255, 255 };
    TTF_Font* font = TTF_OpenFont("bach.ttf", 100);
    TTF_Font* font1 = TTF_OpenFont("bach.ttf", 30);
    unsigned int score=10000;
    SDL_Rect rect1={730,125,70,70};
    SDL_Rect rect2={805,125,70,70};
    SDL_Rect rect3={765,200,70,70};
    SDL_Rect rectpoint={285,150,100,100};

    bool quit = 0;
        SDL_Event event;
    while(!quit){
    bool checkPlay=0;
    unsigned int x1=0,x2=0,x3=0,x4=0,x5=0,x6=0;
        while(!checkPlay){
    string datnai=to_string(x1);
    string datbau=to_string(x2);
    string datmeo=to_string(x3);
    string datca=to_string(x4);
    string datcua=to_string(x5);
    string dattom=to_string(x6);

    SDL_Texture* point = loadText(renderer,to_string(score),font , textColor);
    SDL_Texture* nai1   = loadText(renderer,to_string(x1),font1 , textColor);
    SDL_Texture* bau1   = loadText(renderer,to_string(x2),font1 , textColor);
    SDL_Texture* meo1 = loadText(renderer,to_string(x3),font1 , textColor);
    SDL_Texture* ca1 = loadText(renderer,to_string(x4),font1 , textColor);
    SDL_Texture* cua1 = loadText(renderer,to_string(x5),font1 , textColor);
    SDL_Texture* tom1 = loadText(renderer,to_string(x6),font1 , textColor);
    SDL_Rect rx1={220,557,(int)(datnai.size())*28,30};
    SDL_Rect rx2={740,557,(int)(datbau.size())*28,30};
    SDL_Rect rx3={1240,557,(int)(datmeo.size())*28,30};
    SDL_Rect rx4={220,820,(int)(datca.size())*28,30};
    SDL_Rect rx5={740,820,(int)(datcua.size())*28,30};
    SDL_Rect rx6={1240,820,(int)(dattom.size())*28,30};
    SDL_Texture* bg=loadTexture("photos/pg.jpg",renderer);
    SDL_RenderCopy(renderer,bg,NULL,NULL);
    SDL_RenderCopy(renderer,point,NULL,&rectpoint);
    SDL_RenderCopy(renderer,nai1,NULL,&rx1);
    SDL_RenderCopy(renderer,bau1,NULL,&rx2);
    SDL_RenderCopy(renderer,meo1,NULL,&rx3);
    SDL_RenderCopy(renderer,ca1,NULL,&rx4);
    SDL_RenderCopy(renderer,cua1,NULL,&rx5);
    SDL_RenderCopy(renderer,tom1,NULL,&rx6);
    SDL_RenderPresent(renderer);

            while(SDL_PollEvent(&event)) {
                if(event.type == SDL_QUIT){
                    quitSDL(window,renderer);
                    TTF_Quit();
                    return 0;
                }
                if(event.type==SDL_KEYDOWN&&event.key.keysym.sym==SDLK_ESCAPE){
                    quitSDL(window,renderer);
                    TTF_Quit();
                    return 0;
                }

                if(event.type == SDL_MOUSEBUTTONDOWN){
                       if(event.button.button == SDL_BUTTON_LEFT){
                        int x, y;
                        SDL_GetMouseState(&x, &y);

                         //SDL_Rect playRect = {270, 330, 450, 40 };
                        if((x >= 72 && x <= 520)&&( y >= 520 && y <= 585)&&score>0) {x1+=1000;
                        score-=1000;}
                       else if((x >= 1087 && x <=1370 )&&( y >= 185 && y <= 250))checkPlay=true;
                       else if((x >= 570 && x <=1080 )&&( y >= 520 && y <= 585)&&score>0){x2+=1000;
                       score-=1000;}
                        else if((x >= 1087 && x <=1530 )&&( y >= 520 && y <= 585)&&score>0){x3+=1000;
                        score-=1000;}
                        else if((x >= 72 && x <=520 )&&( y >= 813 && y <= 840)&&score>0){x4+=1000;
                        score-=1000;}
                        else if((x >= 570 && x <=1080 )&&( y >= 813 && y <= 840)&&score>0){x5+=1000;
                        score-=1000;}
                        else if((x >= 1087 && x <=1370 )&&( y >= 813 && y <= 840)&&score>0){x6+=1000;
                        score-=1000;}
                        else if((x >= 187 && x <=400 )&&( y >= 334 && y <= 538)&&x1>0){x1-=1000;
                        score+=1000;}
                        else if((x >= 700 && x <=900 )&&( y >= 334 && y <= 538)&&x2>0){x2-=1000;
                        score+=1000;}
                        else if((x >= 1200 && x <=1415 )&&( y >= 334 && y <= 538)&&x3>0){x3-=1000;
                        score+=1000;}
                        else if((x >= 187 && x <=400 )&&( y >= 600 && y <= 800)&&x4>0){x4-=1000;
                        score+=1000;}
                        else if((x >= 700 && x <=900 )&&( y >= 600 && y <= 800)&&x5>0){x5-=1000;
                        score+=1000;}
                        else if((x >= 1200 && x <=1415 )&&( y >= 600 && y <= 800)&&x6>0){x6-=1000;
                        score+=1000;}


                    }

            }
            }

         SDL_DestroyTexture(point);
         SDL_DestroyTexture(nai1);
         SDL_DestroyTexture(bau1);
         SDL_DestroyTexture(meo1);
         SDL_DestroyTexture(ca1);
         SDL_DestroyTexture(cua1);
         SDL_DestroyTexture(tom1);
        }




    // render graphics
    int* k=create_random_array(3,1,6);
    int b[3]={k[0],k[1],k[2]};
    SDL_Delay(10);
    SDL_Texture* xucxac1=loadTexture(xucxac(a,b[0]),renderer);
    SDL_Texture* xucxac2=loadTexture(xucxac(a,b[1]),renderer);
    SDL_Texture* xucxac3=loadTexture(xucxac(a,b[2]),renderer);
    SDL_RenderCopy(renderer,xucxac1,NULL,&rect1);
    SDL_RenderCopy(renderer,xucxac2,NULL,&rect2);
    SDL_RenderCopy(renderer,xucxac3,NULL,&rect3);
    map<int,int> congdiem;
    for (auto r:b){congdiem[r]++;}
    for (auto k:congdiem){

        score=score+ (k.second+1)*thang(x1,x2,x3,x4,x5,x6,k.first);
    }
    SDL_RenderPresent(renderer);
    if(score!=0){bool tieptuc=true;
    while(tieptuc){
    while(SDL_PollEvent(&event)) {
                    if(event.type == SDL_QUIT){
                    quitSDL;
                    TTF_Quit();
                    return 0;
                }
                    if(event.type == SDL_MOUSEBUTTONDOWN){
                       if(event.button.button == SDL_BUTTON_LEFT){
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        if((x >= 681 && x <= 900)&&( y >= 67 && y <= 300)) {tieptuc=false;}
                       }
                    }
    }
    }
    }
    SDL_DestroyTexture(xucxac1);
    SDL_DestroyTexture(xucxac2);
    SDL_DestroyTexture(xucxac3);
    SDL_RenderClear(renderer);
    if(score==0)quit=1;
    }
    SDL_RenderClear(renderer);


    // Your code here

    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}




//*****************************************************
// CÃ¡c hÃ m chung vá» khá»Ÿi táº¡o vÃ  huá»· SDL
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
    // Táº¡o surface tá»« chuá»—i vÄƒn báº£n
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == NULL) {
        std::cerr << "Unable to create surface from text! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return NULL;
    }

    // Táº¡o texture tá»« surface vÃ  tráº£ vá»
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
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    //   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thÃ´ng thÆ°á»ng cháº¡y vá»›i mÃ´i trÆ°á»ng bÃ¬nh thÆ°á»ng á»Ÿ nhÃ
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi cháº¡y á»Ÿ mÃ¡y thá»±c hÃ nh WinXP á»Ÿ trÆ°á»ng (mÃ¡y áº£o)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
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
        SDL_Delay(50);
    }
}
//**************************************************************

