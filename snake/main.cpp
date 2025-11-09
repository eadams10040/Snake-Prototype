// Evan Adams
// 9/11/25
// Snake the game made with SSDL
// Credit: "C++ Tutorial 18 - Simple Snake Game (Part 2)" by NVitanovic on Youtube

#include "SSDL.h"
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "snake.h"
#include <vector>
using namespace std;

void render_snake(Snake obj);
void render_apple(Apple obj);
bool isDead(Snake obj);
void playgame();
bool collision(Snake snake, Apple apple);
void move_snake(Snake& snake);
void build_vec(vector<Coord> vec, Snake& obj);
void move_seg(Snake& obj, vector<Coord> coords, int& frames, int& pos);

int main(int argc, char* argv[])
{
    srand(time(0));

    Game game;
   
    SSDL_SetWindowSize(game.window_width(), game.window_height());
     
    playgame();

    return 0;
}

bool isDead(Snake obj)
{
    if ( (obj.x_coord() > SSDL_GetWindowWidth()) || (obj.x_coord() <= 0))
    {
        return true;

    }

    else if ( (obj.y_coord() > SSDL_GetWindowHeight()) || (obj.y_coord() <= 0))
    {
        return true;
        
    }
    
    // if snake head is touching itself
    // return true;

    else
    {
        return false;

    }


}

void render_snake(Snake obj)
{
    SSDL_RenderSprite(obj.sprite());
}

void render_apple(Apple obj)
{
    SSDL_RenderSprite(obj.sprite());
}


void inputs(Snake& obj)
{
    int key_pressed = 0;
    
    if (SSDL_IsKeyPressed(SDLK_UP))
    {
        key_pressed = SDLK_UP;
    }

    if (SSDL_IsKeyPressed(SDLK_DOWN))
    {
        key_pressed = SDLK_DOWN;
    }

    if (SSDL_IsKeyPressed(SDLK_LEFT))
    {
        key_pressed = SDLK_LEFT;
    }

    if (SSDL_IsKeyPressed(SDLK_RIGHT))
    {
        key_pressed = SDLK_RIGHT;
    }

    // use of switch idea from NVitanovic
    switch (key_pressed)
    {
        case (SDLK_UP):

            if (obj.dir() != DOWN)
            {
                obj.set_dir(UP);
            }
            break;

        case (SDLK_DOWN):
            
            if (obj.dir() != UP)
            { 
                obj.set_dir(DOWN);
            }
            break;

        case (SDLK_LEFT):

            if (obj.dir() != RIGHT)
            {
                obj.set_dir(LEFT);
            }
            break;

        case (SDLK_RIGHT):

            if (obj.dir() != LEFT)
            {
                obj.set_dir(RIGHT);
            }
            break;

        default:
            break;
    }

}

// use of switch idea from NVitanovic
void move_snake(Snake& obj)
{
    switch(obj.dir())
    {
        case UP:
            obj.set_y_coord(obj.y_coord() - obj.speed());
            break;

        case DOWN:
            obj.set_y_coord(obj.y_coord() + obj.speed());
            break;

        case LEFT:
            obj.set_x_coord(obj.x_coord() - obj.speed());
            break;

        case RIGHT:
            obj.set_x_coord(obj.x_coord() + obj.speed());
            break;

        default:
            break;
    }

    SSDL_SetSpriteLocation(obj.sprite(), obj.x_coord(), obj.y_coord() );

}


bool collision(Snake snake, Apple apple)
{
    double sum_radi = (apple.apple_width() + snake.snake_width());

    double sval = (apple.x_coord() - snake.x_coord() );
    double aval = (apple.y_coord() - snake.y_coord() );

    double distance = (sqrt(sval*sval + aval*aval));

    if (distance < 30)
    {
        return true;
    }
    
    return false;
}

void move_seg(Snake& obj, vector<Coord> coords, int& frames, int& pos)
{
    render_snake(obj);
    SSDL_SetSpriteLocation(obj.sprite(), coords[frames - pos].x(), coords[frames - pos].y());

    
}

void playgame()
{
    vector<Coord> coords;
    vector<Snake> segments;

    Game game;
    game.set_running(true);
    game.set_score(0);

    Snake snake;
    
    Apple start;
    start.random(game.window_width(), game.window_height());
    Apple apple;

    int frames = 0;
    bool follow = false;

    while(SSDL_IsNextFrame() && game.running() == true)
    {
        SSDL_DefaultEventHandler();

        SSDL_RenderClear();

        render_snake(snake);
        render_apple(apple);

        inputs(snake);
        
        move_snake(snake);

        Coord pos(snake.x_coord(), snake.y_coord());
        coords.push_back(pos);
       
        ++frames; 
        int amount = 15;
    

        if (collision(snake, apple))
        {
            apple.random(game.window_width(), game.window_height());

            SSDL_SetSpriteLocation(apple.sprite(), apple.x_coord(), apple.y_coord() );

            game.set_score(game.score() + 1);

            follow = true;

            Snake& seg = snake;

            segments.push_back(seg);
        }
            
        if (follow == true)
        {   
            
                      
            for (Snake& s : segments)
            {
                render_snake(s);
                SSDL_SetSpriteLocation(s.sprite(), coords[frames - amount].x(), coords[frames - amount].y());

                amount += 15;
            }
            
        }

        if (isDead(snake)) 
        {
            game.set_running(false);
        }

        SSDL_SetCursor(0, 0);

        sout << "X Window Width: " << SSDL_GetWindowWidth() << endl;
        sout << "Y Window Height: " << SSDL_GetWindowHeight() << endl;

        sout << "Snake X Coords: " << snake.x_coord() << endl;
        sout << "Snake Y Coords: " << snake.y_coord() << endl;

        sout << "Apple X Coords: " << apple.x_coord() << endl;
        sout << "Apple Y Coords: " << apple.y_coord() << endl;

        sout << "Score: " << game.score() << endl;
    }    
}



