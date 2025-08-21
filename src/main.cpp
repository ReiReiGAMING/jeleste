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

// animation control variables

int frame_f_start;
int frame_main_menu_coin;

// Main Menu images

int main_coin_pozx = screenCenterX - 400;
float main_coin_pozy = screenCenterY + 800;

int main_coin_accel_x= 0;
int main_coin_accel_y = 0;


const char text_resume_game[] = "Resume Game";
const char text_options[] = "Options";
const char text_exit_game[] = "Exit Game";
const char text_return_menu[] = "Return to Main Menu";
const char text_credits_creator[] = "Game Created by Rei";
int FontSize_Pause = 70;
int textw_resume_game = MeasureText(text_resume_game, FontSize_Pause);
int textw_options = MeasureText(text_options, FontSize_Pause);
int textw_exit_game = MeasureText(text_exit_game, FontSize_Pause);
int textw_credits_creator = MeasureText(text_credits_creator, FontSize_Pause);

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

    // Animations very hot area 😳😳😳

    Texture2D coin = LoadTexture("rsc/coin.png");

    Texture2D coin_rh_1 = LoadTexture("rsc/coin_rh_1.png");
    Texture2D coin_rh_2 = LoadTexture("rsc/coin_rh_2.png");
    Texture2D coin_rh_3 = LoadTexture("rsc/coin_rh_3.png");
    Texture2D coin_rh_4 = LoadTexture("rsc/coin_rh_4.png");
    Texture2D coin_rh_5 = LoadTexture("rsc/coin_rh_5.png");
    Texture2D coin_rh_6 = LoadTexture("rsc/coin_rh_6.png");
    Texture2D coin_rh_7 = LoadTexture("rsc/coin_rh_7.png");
    Texture2D coin_rh_8 = LoadTexture("rsc/coin_rh_8.png");

    Texture2D coin_rv_1 = LoadTexture("rsc/coin_rv_1.png");
    Texture2D coin_rv_2 = LoadTexture("rsc/coin_rv_2.png");
    Texture2D coin_rv_3 = LoadTexture("rsc/coin_rv_3.png");
    Texture2D coin_rv_4 = LoadTexture("rsc/coin_rv_4.png");
    Texture2D coin_rv_5 = LoadTexture("rsc/coin_rv_5.png");
    Texture2D coin_rv_6 = LoadTexture("rsc/coin_rv_6.png");
    Texture2D coin_rv_7 = LoadTexture("rsc/coin_rv_7.png");
    Texture2D coin_rv_8 = LoadTexture("rsc/coin_rv_8.png");

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
            if (frame_f_start <= 101)
            {
                ClearBackground(BLACK);
                DrawTextEx (Alagard, text_credits_creator, Vector2 {(float)screenCenterX - MeasureText(text_credits_creator,70)/2, (float)screenCenterY-35}, 70, 1, WHITE);
            }
            else {

   if (frame_f_start >= 101 && frame_f_start < 229)
{
    int cycleFrame = (frame_f_start - 101) % 16;   // 0–31 → one loop
    int frameIndex = cycleFrame / 2;               // 0–7 → pick texture

    switch (frameIndex)
    {
        case 0: DrawTextureEx(coin_rv_1, { (float)main_coin_pozx, (float)main_coin_pozy }, 0, 40, WHITE); break;
        case 1: DrawTextureEx(coin_rv_2, { (float)main_coin_pozx, (float)main_coin_pozy }, 0, 40, WHITE); break;
        case 2: DrawTextureEx(coin_rv_3, { (float)main_coin_pozx, (float)main_coin_pozy }, 0, 40, WHITE); break;
        case 3: DrawTextureEx(coin_rv_4, { (float)main_coin_pozx, (float)main_coin_pozy }, 0, 40, WHITE); break;
        case 4: DrawTextureEx(coin_rv_5, { (float)main_coin_pozx, (float)main_coin_pozy }, 0, 40, WHITE); break;
        case 5: DrawTextureEx(coin_rv_6, { (float)main_coin_pozx, (float)main_coin_pozy }, 0, 40, WHITE); break;
        case 6: DrawTextureEx(coin_rv_7, { (float)main_coin_pozx, (float)main_coin_pozy }, 0, 40, WHITE); break;
        case 7: DrawTextureEx(coin_rv_8, { (float)main_coin_pozx, (float)main_coin_pozy }, 0, 40, WHITE); break;
    }
}

        if (frame_f_start >= 229)
        {
            DrawTextureEx(coin, Vector2 {(float)main_coin_pozx, (float)main_coin_pozy}, 0, 40, WHITE);
            if (frame_f_start >= 250)
            {
                if (main_coin_pozx != 20 )
                main 
            }
        }


                if (main_coin_pozy != screenCenterY - 400)
                main_coin_pozy -= 20;

            }
            frame_f_start +=1;
        }
        
        DrawText(std::to_string(frame_f_start).c_str(), 10, 40, 20, WHITE);

        EndDrawing();

   

    }
    CloseWindow();
    CloseAudioDevice(); // Close audio device if it was initialized
    

}
