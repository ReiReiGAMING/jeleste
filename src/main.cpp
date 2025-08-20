#include <raylib.h>
#include <string>
#include <iostream>
#include <fstream>


#define PLAYER_WIDTH 14*5
#define PLAYER_HEIGHT 20*5

#define SPIKE_WIDTH  17
#define SPIKE_HEIGHT 9

#define COIN_WIDTH 20
#define COIN_HEIGHT 20 

#define screenCenterX (1920 / 2)
#define screenCenterY (1080 / 2)

bool MuteSound = false; // Global variable to control sound muting
bool PauseGame = false; // Global variable to control game pause
bool OptionsMenu = false; // Global variable to control options menu
bool CanMove = true; // Global variable to control player movement
bool Died = false; // Global variable to track if the player has died
bool MainMenu = true; // Global variable to control main menu state

bool CanShift = false; //  Not unlocked yet

const char text_resume_game[] = "Resume Game";
const char text_options[] = "Options";
const char text_exit_game[] = "Exit Game";
const char text_return_menu[] = "Return to Main Menu";
int FontSize_Pause = 70;
int textw_resume_game = MeasureText(text_resume_game, FontSize_Pause);
int textw_options = MeasureText(text_options, FontSize_Pause);
int textw_exit_game = MeasureText(text_exit_game, FontSize_Pause);

int text_resume_game_x = screenCenterX - textw_resume_game;
int text_resume_game_y = screenCenterY - FontSize_Pause / 2;

int pause_menu_option = 0; // Variable to track the selected pause menu option

int resx = 400;
int resy = 400;
int resrx = 1;
int resry = 1;


Font Alagard;


int FrameCount_Pause = 0;


int main()
{
     
    
    // Initialization    
    int roomx = 1;
    int roomy = 1;

    
    Color BGCOLOR = { 25, 44, 65, 255};

    

    InitWindow (1920, 1080, "Jeleste");

         InitAudioDevice(); // Initialize audio device if needed

        Sound music =  LoadSound("rsc/mainsong.wav" ); // Load sound if needed

        

       

    SetTargetFPS(60);
    //ToggleFullscreen();
    HideCursor(); // Hide the mouse cursor for a cleaner look

    // Textures and fonts can be loaded here if needed

    Texture2D player = LoadTexture("rsc/Player-Idle-Right.png");
    Texture2D player_right = LoadTexture("rsc/Player-Idle-Right.png");
    Texture2D player_left = LoadTexture("rsc/Player-Idle-Left.png");

    // Main Menu textures

    Texture2D Happy_Merchant = LoadTexture("rsc/Happy_merchant.png");
    
    // Textures of Spikes / Enemies can be loaded here if needed

    Texture2D spike = LoadTexture("rsc/Spike.png");
    Texture2D spike_right = LoadTexture("rsc/Spike_right.png");
    Texture2D spike_left = LoadTexture("rsc/Spike_left.png");
    Texture2D spike_down = LoadTexture("rsc/Spike_down.png");
    Texture2D spike_wide = LoadTexture("rsc/SpikeWide.png");
    Texture2D spike_wide_right = LoadTexture("rsc/SpikeWide_right.png");
    Texture2D spike_wide_left = LoadTexture ("rsc/SpikeWide_left.png");
    Texture2D spike_wide_down = LoadTexture ("rsc/SpikeWide_down.png");

    Texture2D coin_rh_1 = LoadTexture("rsc/coin_1.png");
    Texture2D coin_rh_2 = LoadTexture("rsc/coin_2.png");
    Texture2D coin_rh_3 = LoadTexture("rsc/coin_3.png");
    Texture2D coin_rh_4 = LoadTexture("rsc/coin_4.png");
    Texture2D coin_rh_5 = LoadTexture("rsc/coin_5.png");
    Texture2D coin_rh_6 = LoadTexture("rsc/coin_6.png");
    Texture2D coin_rh_7 = LoadTexture("rsc/coin_7.png");
    Texture2D coin_rh_8 = LoadTexture("rsc/coin_8.png");

    Rectangle player_hitbox = (Rectangle){0, 0, PLAYER_WIDTH*0.8, PLAYER_HEIGHT*0.8}; // Player hitbox for collision detection

    Alagard = LoadFont("rsc/alagard.ttf"); // Load the Alagard font

    // Add all room objects to an array for easy access
int* rooms[6] = {

};



 //   SetExitKey(KEY_NULL); // Disable default exit key (ESC) to handle it manually



    //Game loop
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BGCOLOR);
        
        if (MainMenu)
        {
            DrawTextureEx(coin_menu_1,Vector2{50,-100},0,40,WHITE);
        }

        EndDrawing();

   

    }
    CloseWindow();
    CloseAudioDevice(); // Close audio device if it was initialized
    

}
