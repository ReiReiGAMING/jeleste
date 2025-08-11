#include <raylib.h>
#include <string>

#define PLAYER_WIDTH 14*5
#define PLAYER_HEIGHT 20*5

#define SPIKE_WIDTH  17
#define SPIKE_HEIGHT 9

#define COIN_WIDTH 32 
#define COIN_HEIGHT 32 

#define screenCenterX (1920 / 2)
#define screenCenterY (1080 / 2)

bool MuteSound = false; // Global variable to control sound muting
bool PauseGame = false; // Global variable to control game pause
bool OptionsMenu = false; // Global variable to control options menu
bool CanMove = true; // Global variable to control player movement
bool Died = false; // Global variable to track if the player has died

bool CanShift = false; //  Not unlocked yet

const char text_resume_game[] = "Resume Game";
const char text_options[] = "Options";
const char text_exit_game[] = "Exit Game";
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
    int room1obj[10][5] =
    {
        {1, 350, 700, 1670, 50},
        {2, 50, 700, 250, 30},
        {1, 300, 400, 50, 350},
        {1, 0, 350, 1620, 50},
        {1, 1870, 0, 50, 700},
        {1, 300, 0, 1620, 50},
        {1, 0, 0, 50, 1080},
        {1, 10, 1030, 1920, 50},
        {2, 1800, 500, 70, 30},
        {2, 50, 150, 70, 30}
    };
    int room1move[20][4] = {
        {1, 600, 665, 0}, // 1 = spike, x, y, rotation
        {4, 700, 400, 0},
        {1, 800, 665, 0},
        {1, 1100, 665, 0},
        {4, 1200, 400, 0},
        {1, 1300, 665, 0},
        {4, 1350, 50, 0},
        {5, 1100, 315, 0},
        {4, 950, 50, 0},
        {5, 700, 315, 0},
        {4, 550, 50, 0},
        {9, 100, 100, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int room2obj[10][5] =
    {
        {1, 0, 1030, 1920, 50},
        {1, 0, 0, 50, 750},
        {1, 0, 0, 1920, 50},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int room2move[20][5] = { {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0} };
    int room3obj[10][5] =
    {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int room3move[20][5] = { {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0} };
    int room4obj[10][5] =
    {
        {1, 0, 0, 50, 1080},
        {2, 200, 1030, 100, 30},
        {1, 300, 1030, 1720, 50},
        {1, 0, 0, 1920, 50},
        {1, 1870, 350, 50, 730},
        {1, 300, 350, 1620, 50},
        {1, 0, 700, 1570, 50},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int room4move[20][5] = { {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0} };
    int room5obj[10][5] =
    {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int room5move[20][5] = { {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0} };
    int room6obj[10][5] =
    {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int room6move[20][5] = { {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0} };

    int ballx = 400;
    int bally = 600;
    int prevbally = 400;
    int prevballx = 400;
    int vy = 10;
    int ay = 0;
    int vx = 0;
    int ax = 0;
    int shift = 0;
    int yframe = 0;
    std::string LastKeyPressed = "None";
    
    Color BGCOLOR = { 86, 0, 105, 255};

    

    InitWindow (1920, 1080, "Tower Game");

         InitAudioDevice(); // Initialize audio device if needed

        Sound music =  LoadSound("rsc/mainsong.wav" ); // Load sound if needed

        

       

    SetTargetFPS(60);
    //ToggleFullscreen();
    HideCursor(); // Hide the mouse cursor for a cleaner look

    // Textures and fonts can be loaded here if needed

    Texture2D player = LoadTexture("rsc/Player-Idle-Right.png");
    Texture2D player_right = LoadTexture("rsc/Player-Idle-Right.png");
    Texture2D player_left = LoadTexture("rsc/Player-Idle-Left.png");
    
    // Textures of Spikes / Enemies can be loaded here if needed

    Texture2D spike = LoadTexture("rsc/Spike.png");
    Texture2D spike_right = LoadTexture("rsc/Spike_right.png");
    Texture2D spike_left = LoadTexture("rsc/Spike_left.png");
    Texture2D spike_down = LoadTexture("rsc/Spike_down.png");
    Texture2D spike_wide = LoadTexture("rsc/SpikeWide.png");
    Texture2D spike_wide_right = LoadTexture("rsc/SpikeWide_right.png");
    Texture2D spike_wide_left = LoadTexture ("rsc/SpikeWide_left.png");
    Texture2D spike_wide_down = LoadTexture ("rsc/SpikeWide_down.png");

    Texture2D coin_menu_1 = LoadTexture("rsc/coin_1.png");
    Texture2D coin_menu_2 = LoadTexture("rsc/coin_2.png");
    Texture2D coin_menu_3 = LoadTexture("rsc/coin_3.png");
    Texture2D coin_menu_4 = LoadTexture("rsc/coin_4.png");
    Texture2D coin_menu_5 = LoadTexture("rsc/coin_5.png");
    Texture2D coin_menu_6 = LoadTexture("rsc/coin_6.png");
    Texture2D coin_menu_7 = LoadTexture("rsc/coin_7.png");
    Texture2D coin_menu_8 = LoadTexture("rsc/coin_8.png");

    Rectangle source = (Rectangle){0, 0, PLAYER_WIDTH, PLAYER_HEIGHT};

    Alagard = LoadFont("rsc/alagard.ttf"); // Load the Alagard font

    // Add all room objects to an array for easy access
int* rooms[6] = {
    (int*)room1obj,
    (int*)room2obj,
    (int*)room3obj,
    (int*)room4obj,
    (int*)room5obj,
    (int*)room6obj
};

int* roomEnemies[6] = {
    (int*)room1move,
    (int*)room2move,
    (int*)room3move,
    (int*)room4move,
    (int*)room5move,
    (int*)room6move
};

    SetExitKey(KEY_NULL); // Disable default exit key (ESC) to handle it manually



    //Game loop
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BGCOLOR);
        Rectangle playerRect = { (float)ballx, (float)bally, (float)PLAYER_WIDTH, (float)PLAYER_HEIGHT };
        
        source = (Rectangle){0, 0, 14, 20};
        Rectangle dest = (Rectangle){(float)ballx, (float)bally, PLAYER_WIDTH, PLAYER_HEIGHT};

        if(!IsSoundPlaying(music) && MuteSound == false)  // Check if sound is not playing and not muted
        { // Check if sound is not playing and not muted{
            PlaySound(music); // Play sound if not already playing
        }

        FrameCount_Pause+=2;
        shift += 1;
        yframe += 1;
        // 1. Event handling
        prevbally = bally;
        prevballx = ballx; // <-- Add this line

        if (IsKeyPressed(KEY_ESCAPE)) {
            if (OptionsMenu)
            {
                OptionsMenu = false; // Disable options menu
                FrameCount_Pause = 0;
            }
            else
            {
            PauseGame = !PauseGame; // Toggle pause state
            FrameCount_Pause = 0; // Reset frame count when pausing
            pause_menu_option = 0;
            }
        }


        if (!PauseGame)
        {
        if(IsKeyDown(KEY_RIGHT)){
            ballx += 15;
            LastKeyPressed = "Right";
            player = player_right;      
        }
        if(IsKeyDown(KEY_LEFT)){
            ballx -= 15;
            LastKeyPressed = "Left";
            player = player_left;
        }
        if(IsKeyDown(KEY_SPACE) && vy == 0){
            ay = -35;
        } 
        if(IsKeyPressed(KEY_R)) 
        {
            ballx = 400;
            bally = 400;
            vy = 10;
            ay = 0;
        }
        if(IsKeyPressed(KEY_F11)) 
        {
            LastKeyPressed = "F11";
            ToggleFullscreen();
        }
        if(IsKeyPressed(KEY_LEFT_SHIFT) && CanShift)
        {
            if (shift > 60)
            {
            
            if (IsKeyDown (KEY_LEFT))
            {
                ax = -14;
                shift = 0;
            }
            else if (IsKeyDown (KEY_UP) )
            {
                ay = -50;
                shift = 0;
            }
            else if (IsKeyDown (KEY_RIGHT) )
            {
                ax = 14;
                shift = 0;
            }

            
        }
        }

        if (IsKeyPressed(KEY_M))
        {
            MuteSound = !MuteSound;
            if (MuteSound)
            {
                StopSound(music); // Stop sound if muted
            }
            else
            {
                PlaySound(music); // Play sound if unmuted
            }
        }

        if (LastKeyPressed == "Left")
        {

        }

       if (abs(ax) > 0 )
       {
        if (ax > 0)
        ax -= 2;
        else if ( ax < 0)
        ax += 2;
       }
       else if ( ax == 1 || ax == -1)
        ax = 0;
       if ( abs(vx) > 0)
       {
        if ( vx > 0)
        vx -= 2;
        else if ( vx < 0 )
        vx += 2;
       }
       else if ( vx == 1 || vx == -1)
       vx = 0;
        // Apply acceleration to velocity
        vy += ay;
        vx += ax;
        // Apply gravity if not on the ground
        if (bally < GetScreenHeight() - 20) ay = 3;
        else ay = 0;

        // Update position
        bally += vy;
        ballx += vx;

        // Clamp position and reset velocity if on the ground
        if (ballx < 0 && roomx == 1);
        else if (ballx < 0) {
            roomx -= 1;
            ballx = GetScreenWidth() - PLAYER_WIDTH;
        }
        if (ballx > GetScreenWidth() - PLAYER_WIDTH && roomx == 3) ballx = GetScreenWidth() - PLAYER_WIDTH;
        else if (ballx > GetScreenWidth() - PLAYER_WIDTH) {
            roomx += 1;
            ballx = 0;
        }
      
       
        // Use yframe > 5 as a debounce to prevent rapid room transitions when the player touches the screen edge.
        if (bally <= 0 && yframe > 5 && roomy < 2) { // Only go up if not at top room
            roomy += 1;
            bally = GetScreenHeight() - PLAYER_HEIGHT - 1;
            yframe = 0;
        }
        if (bally >= GetScreenHeight() - PLAYER_HEIGHT && yframe > 5 && roomy > 1) { // Only go down if not at bottom room
            roomy -= 1;
            bally = 1;
            yframe = 0;
        }
        if (bally > GetScreenHeight() - PLAYER_HEIGHT && roomy == 1) {
            bally = GetScreenHeight() - PLAYER_HEIGHT;
            vy = 0;
        }

    }

int currentRoomIdx = (roomx - 1) + (roomy - 1) * 3; // Adjust if your room layout is different
int (*currentRoomObj)[5] = nullptr;
int (*currentRoomEnemy)[4] = nullptr;
if (currentRoomIdx >= 0 && currentRoomIdx < 6) {
    currentRoomObj = (int(*)[5])rooms[currentRoomIdx];
    currentRoomEnemy = (int(*)[4])roomEnemies[currentRoomIdx];
}

// Now you can use currentRoomEnemy in both update and draw sections

    for (int i = 0; i < 20; i++)
    {
        if (currentRoomObj[i][0] < 1) continue; // Skip inactive objects

        int pType = currentRoomObj[i][0];
        int pX = currentRoomObj[i][1];
        int pY = currentRoomObj[i][2];
        int pW = currentRoomObj[i][3];
        int pH = currentRoomObj[i][4];

        // Collisions for type 1 (full block)
        if (pType == 1)
        {
            // Only land if falling and coming from above
            if (
                prevbally + PLAYER_HEIGHT <= pY &&
                bally + PLAYER_HEIGHT >= pY &&
                ballx + PLAYER_WIDTH > pX && ballx < pX + pW &&
                vy > 0
            )
            {
                bally = pY - PLAYER_HEIGHT;
                vy = 0;
            }

            // Prevent going up through the platform from below
            if (
                prevbally >= pY + pH &&
                bally <= pY + pH &&
                ballx + PLAYER_WIDTH > pX && ballx < pX + pW &&
                vy < 0
            )
            {
                bally = pY + pH;
                vy = -1;
            }

            // Prevent going through the platform from the left side
            if (
                ballx > pX - PLAYER_WIDTH && ballx < pX + pW
                && prevbally + PLAYER_HEIGHT > pY && prevbally < pY + pH
                && prevballx + PLAYER_WIDTH <= pX && ballx + PLAYER_WIDTH > pX
            )
            {
                ballx = pX - PLAYER_WIDTH;
                vx = 0;
            }

            // Prevent going through the platform from the right side
            if (
                prevballx >= pX + pW &&
                ballx <= pX + pW &&
                bally + PLAYER_HEIGHT > pY && bally < pY + pH
            )
            {
                ballx = pX + pW;
                vx = 0;
            }
        }

        // Collisions for type 2 (only from above)
        if (pType == 2)
        {
            // Only land if falling and coming from above
            if (
                prevbally + PLAYER_HEIGHT <= pY &&
                bally + PLAYER_HEIGHT >= pY &&
                ballx + PLAYER_WIDTH > pX && ballx < pX + pW &&
                vy > 0
            )
            {
                bally = pY - PLAYER_HEIGHT;
                vy = 0;
            }
            // No other collision directions for type 2!
        }
    }

                DrawTexturePro(player, source, dest, (Vector2){0, 0}, 0, WHITE);
       
        // Draw platforms for the current room
        if (currentRoomObj) {
            for (int i = 0; i < 10; i++) {
                if (currentRoomObj[i][0] == 1) {
                    DrawRectangle(currentRoomObj[i][1], currentRoomObj[i][2], currentRoomObj[i][3], currentRoomObj[i][4], GREEN);
                }
                if (currentRoomObj[i][0] == 2) {
                    DrawRectangle(currentRoomObj[i][1], currentRoomObj[i][2], currentRoomObj[i][3], currentRoomObj[i][4], BLUE);
                }
            }
        }


    for (int i = 0; i <= 19; i++)
    {
        if (currentRoomEnemy[i][0] < 1) continue; // Skip inactive objects

        int pType = currentRoomEnemy[i][0];
        int pX = currentRoomEnemy[i][1];
        int pY = currentRoomEnemy[i][2];
        int pR = currentRoomEnemy[i][3];

        if (pType == 1) // Example for a spike enemy
        {
            // Check if player collides with the spike
            
            Rectangle spikeRect = { (float)pX + (float)SPIKE_WIDTH, (float)pY+(float)SPIKE_HEIGHT+10, (float)SPIKE_WIDTH*2, (float)SPIKE_HEIGHT };
          DrawTextureEx(
                spike, (Vector2){(float)pX, (float)pY}, (float)pR, 1, WHITE
            );

            //DrawRectangleRec(playerRect, GREEN);
            //DrawRectangleRec(spikeRect, RED);

            if (CheckCollisionRecs(playerRect, spikeRect))
            {
               Died = true;
            }
        }

        if (pType == 2) // Spike 90* Clockwise
        {
            // Check if player collides with the spike
            Rectangle spikeRect = { (float)pX+(float)SPIKE_WIDTH, (float)pY+(float)SPIKE_HEIGHT+10,(float)SPIKE_HEIGHT , (float)SPIKE_WIDTH*2 };

            DrawTextureEx(
                spike_left, (Vector2){(float)pX, (float)pY}, (float)pR, 1, WHITE
            );

            //DrawRectangleRec(playerRect, GREEN);
            //DrawRectangleRec(spikeRect, RED);

             if (CheckCollisionRecs(playerRect, spikeRect))
            {
               Died = true;
            }
        
        }
        if (pType == 3) // Spike 90* Counterclockwise
        {
            // Check if player collides with the spike
            Rectangle spikeRect = { (float)pX + (float)SPIKE_WIDTH-SPIKE_HEIGHT, (float)pY+(float)SPIKE_HEIGHT+10, (float)SPIKE_HEIGHT, (float)SPIKE_WIDTH*2};
            DrawTextureEx(
                spike_right, (Vector2){(float)pX, (float)pY}, (float)pR, 1, WHITE
            );

            //DrawRectangleRec(playerRect, GREEN);
            //DrawRectangleRec(spikeRect, RED);

             if (CheckCollisionRecs(playerRect, spikeRect))
            {
               Died = true;
            }
        
        }

        if (pType == 4) // Upside down spike enemy
        {
            // Check if player collides with the upside down spike
            Rectangle upsideDownSpikeRect = { (float)pX + (float)SPIKE_WIDTH, (float)pY+(float)SPIKE_HEIGHT, (float)SPIKE_WIDTH*2, (float)SPIKE_HEIGHT };

            DrawTextureEx(
                spike_down , (Vector2){(float)pX, (float)pY}, (float)pR, 1, WHITE
            );

            //DrawRectangleRec(playerRect, GREEN);
            //DrawRectangleRec(upsideDownSpikeRect, RED);

            if (CheckCollisionRecs(playerRect, upsideDownSpikeRect))
            {
               Died = true;
            }
        }

        if (pType == 5) // Example for a wide spike enemy
        {
            // Check if player collides with the wide spike
            Rectangle wideSpikeRect = { (float)pX + (float)SPIKE_WIDTH, (float)pY+(float)SPIKE_HEIGHT+7, (float)SPIKE_WIDTH*2*4-4, (float)SPIKE_HEIGHT-7 };

            DrawTextureEx(
                spike_wide, (Vector2){(float)pX, (float)pY}, (float)pR, 1, WHITE
            );

            //DrawRectangleRec(playerRect, GREEN);
            //DrawRectangleRec(wideSpikeRect, RED);

            if (CheckCollisionRecs(playerRect, wideSpikeRect))
            {
                Died = true;
            }
        }

        if (pType == 6)
        {

            Rectangle wideSpikeRect = { (float)pX + (float)SPIKE_WIDTH, (float)pY+(float)SPIKE_HEIGHT+7, (float) SPIKE_HEIGHT, (float)SPIKE_WIDTH*2*4-4 };
            DrawTextureEx(
                spike_wide_left, (Vector2){(float)pX, (float)pY}, (float)pR, 1, WHITE // left
            );

            DrawRectangleRec(wideSpikeRect, RED);

            if (CheckCollisionRecs(playerRect, wideSpikeRect))
            {
                Died = true;
            }

        }

        if (pType == 7)
        {

            Rectangle wideSpikeRect = { (float)pX + 7, (float)pY+(float)SPIKE_HEIGHT+7, (float) SPIKE_HEIGHT, (float)SPIKE_WIDTH*2*4-4 };
            DrawTextureEx(
                spike_wide_right, (Vector2){(float)pX, (float)pY}, (float)pR, 1, WHITE // left
            );

            DrawRectangleRec(wideSpikeRect, RED);

            if (CheckCollisionRecs(playerRect, wideSpikeRect))
            {
                Died = true;
            }

        }

        if (pType == 8 )

        {
            Rectangle wideSpikeRect = { (float)pX + (float)SPIKE_WIDTH, (float)pY+(float)SPIKE_HEIGHT, (float)SPIKE_WIDTH*2*4-4, (float)SPIKE_HEIGHT };
            DrawTextureEx(
                spike_wide_down, (Vector2){(float)pX, (float)pY}, (float)pR, 1, WHITE
            );

            DrawRectangleRec(wideSpikeRect, RED);

            if (CheckCollisionRecs(playerRect, wideSpikeRect))
            {
                Died = true;
            }
        }

        if ( pType == 9 ) // Coin For ability or other bullshit
        {
            
            if (!CanShift && roomy == 1 && roomx == 1) // Only show coin in room 1,1 if shift ability is not enabled

            {

            Rectangle abilityCoinRect = { (float)pX, (float)pY, (float)COIN_WIDTH, (float)COIN_HEIGHT };

            DrawRectangleRec(abilityCoinRect, YELLOW);

            DrawTextureEx(
                coin_menu_1, (Vector2){(float)pX - 16, (float)pY - 16}, 0, 2, WHITE
            );

            if (CheckCollisionRecs(playerRect, abilityCoinRect))
            {
                LastKeyPressed = "Coin Collected!";
                CanShift = true; // Enable the shift ability
            }

            }
        }
        if ( pType == 10 )
        {
            if ( roomy == 1 && roomx == 1)
            {
                Rectangle RespawnZone = { (float)pX, (float)pY-(float)PLAYER_HEIGHT, (float)PLAYER_WIDTH*3, (float)PLAYER_HEIGHT };
            }
        }

    }
    if (Died)
    {
        PauseGame = true; // Pause the game when the player dies
    }

    if ( PauseGame )
    {
        if (!Died)
    {
        Rectangle pauseRect = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };


        DrawRectangleRec(pauseRect, Fade(BLACK, 0.5f));

        Vector2 coinPos = { screenCenterX - 1280/2, -150 };
        float coinScale = 40.0f;

        // Show each coin frame for 5 frames, in order
       if (FrameCount_Pause >= 0 && FrameCount_Pause < 4)
{
    DrawTextureEx(coin_menu_1, coinPos, 0, coinScale, WHITE);
}
else if (FrameCount_Pause >= 4 && FrameCount_Pause < 8)
{
    DrawTextureEx(coin_menu_2, coinPos, 0, coinScale, WHITE);
}
else if (FrameCount_Pause >= 8 && FrameCount_Pause < 12)
{
    DrawTextureEx(coin_menu_3, coinPos, 0, coinScale, WHITE);
}
else if (FrameCount_Pause >= 12 && FrameCount_Pause < 16)
{
    DrawTextureEx(coin_menu_4, coinPos, 0, coinScale, WHITE);
}
else if (FrameCount_Pause >= 16 && FrameCount_Pause < 20)
{
    DrawTextureEx(coin_menu_5, coinPos, 0, coinScale, WHITE);
}
else if (FrameCount_Pause >= 20 && FrameCount_Pause < 24)
{
    DrawTextureEx(coin_menu_6, coinPos, 0, coinScale, WHITE);
}
else if (FrameCount_Pause >= 24 && FrameCount_Pause < 28)
{
    DrawTextureEx(coin_menu_7, coinPos, 0, coinScale, WHITE);
}
else if (FrameCount_Pause >= 28 && FrameCount_Pause < 32)
{
    DrawTextureEx(coin_menu_8, coinPos, 0, coinScale, WHITE);
}
else if (FrameCount_Pause >= 32)

{
    DrawTextureEx(coin_menu_1, coinPos, 0, coinScale, WHITE);

    if (!OptionsMenu)

    {

    Rectangle text_resume_game_outline = { (float)screenCenterX - MeasureText(text_resume_game, FontSize_Pause)/2 - 15, (float)text_resume_game_y-150-10, (float)MeasureText(text_resume_game, FontSize_Pause) + 30, (float)FontSize_Pause + 20 };
    Rectangle text_options_outline = { (float)screenCenterX - MeasureText(text_options, FontSize_Pause)/2 - 15, (float)text_resume_game_y-10, (float)MeasureText(text_options, FontSize_Pause) + 30, (float)FontSize_Pause + 20 };
    Rectangle text_exit_game_outline = { (float)screenCenterX - MeasureText(text_exit_game, FontSize_Pause)/2 - 15, (float)text_resume_game_y+150-10, (float)MeasureText(text_exit_game, FontSize_Pause) + 30, (float)FontSize_Pause + 20 };

    DrawTextEx(Alagard, text_resume_game, Vector2{(float)screenCenterX - MeasureText(text_resume_game, 70)/2, (float)text_resume_game_y-150} , FontSize_Pause, 1, BLACK);
    DrawTextEx(Alagard, text_options, Vector2{(float)screenCenterX - MeasureText(text_options, 70)/2, (float)text_resume_game_y} , FontSize_Pause, 1, BLACK);
    DrawTextEx(Alagard, text_exit_game, Vector2{(float)screenCenterX - MeasureText(text_exit_game, 70)/2, (float)text_resume_game_y+150} , FontSize_Pause, 1, BLACK);
    

    if (pause_menu_option == 1) {
        if (IsKeyPressed(KEY_ENTER)) {
            PauseGame = false; // Resume the game
            continue;
        }
        DrawRectangleRec(text_resume_game_outline, Fade (WHITE, 0.25f));
    } else if (pause_menu_option == 2) {
        DrawRectangleRec(text_options_outline, Fade (WHITE, 0.25f));
        if (IsKeyPressed(KEY_ENTER)) {
            FrameCount_Pause = 0;
            OptionsMenu = true; // Enable options menu
        }
      
    } else if (pause_menu_option == 3) {
        DrawRectangleRec(text_exit_game_outline, Fade (WHITE, 0.25f));
        if (IsKeyPressed(KEY_ENTER)) {
            CloseWindow(); // Exit the game
            return 0; // Exit the main loop
        }
    }

    if (IsKeyPressed(KEY_DOWN)) {
        pause_menu_option++;
        if (pause_menu_option > 3) pause_menu_option = 1; // Loop back to the first option
    } else if (IsKeyPressed(KEY_UP)) {
        pause_menu_option--;
        if (pause_menu_option < 1) pause_menu_option = 3; // Loop back to the last option
    }
    }
}
    else if (OptionsMenu)
    {
        
    }



}
    else if (Died)
    {
        Rectangle pauseRect = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
        DrawRectangleRec(pauseRect, Fade(BLACK, 0.8f));
        DrawTextEx(Alagard, "You Died!", Vector2{(float)screenCenterX - MeasureText("You Died!", 70)/2, (float)screenCenterY - 50} , 70, 1, RED);
        DrawTextEx(Alagard, "Press Enter to respawn", Vector2{(float)screenCenterX - MeasureText("Press Enter to respawn", 50)/2, (float)screenCenterY + 50} , 50, 1, WHITE);
        StopSound(music); // Stop the music when the player dies
        if (IsKeyPressed(KEY_ENTER)) {
            Died = false; // Reset death state
            PauseGame = false; // Resume the game
            ballx = resx; // Reset player position
            bally = resy;
            roomx = resrx;
            roomy = resry;
            vy = 10; // Reset player velocity
            ay = 0;
            vx = 0;
            ax = 0;
 
        }
    }



    }

        // Debug larp

        EndDrawing();

   
    }

    CloseWindow();
    CloseAudioDevice(); // Close audio device if it was initialized
    UnloadTexture(player);  
    UnloadTexture(player_right);
    UnloadTexture(player_left);
}