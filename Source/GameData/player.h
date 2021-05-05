#ifndef LOST_IN_SPACE_PLAYER
#define LOST_IN_SPACE_PLAYER

#include "splashkit.h"
#include <vector>

using namespace std;

#define PLAYER_SPEED 1.5
#define PLAYER_ROTATE_SPEED 3
#define SCREEN_BORDER 100

/**
 * Different options for the kind of ship.
 * Adjusts the image used.
 */
enum ship_kind
{
    AQUARII,
    GLIESE,
    PEGASI
};

/**
 * The player data keeps track of all of the information related to the player.
 * 
 * @field   player_sprite       The player's sprite - used to track position and movement
 * @field   score               The current score for the player
 * @field   kind                Current kind of player ship
 * @field   fuel_pct            Handles the drawing of the fuel capacity
 * @field   total_power_ups     The total power ups collected
 * @field   current_power_up    Bitmap to draw the current powerup the user has
 * @field   invincible          Handles the user's infinite health or not
 */
struct player_data
{
    sprite      player_sprite;
    int         score;
    ship_kind   kind;
    double      fuel_pct;
    int         total_power_ups;
    bitmap      current_power_up;
    bool        invincible;
    double      power_up_counter;
};

/**
 * Creates a new player in the centre of the screen with the default ship.
 * 
 * @returns     The new player data
 */
player_data new_player();

/**
 * Draws the player to the screen. 
 * 
 * @param player_to_draw    The player to draw to the screen
 */
void draw_player(const player_data &player_to_draw);


void update_player_camera(player_data &player_to_update);

/**
 * Actions a step update of the player - moving them and adjusting the camera.
 * 
 * @param player_to_update      The player being updated
 */
void update_player(player_data &player_to_update);

/**
 * Read user input and update the player based on this interaction.
 * 
 * @param player    The player to update
 */
void handle_input(player_data &player);

#endif 