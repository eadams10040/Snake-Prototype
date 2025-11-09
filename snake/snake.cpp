#include "snake.h"
#include "SSDL.h"

// *********************Snake sprite*************************

//constructors

Snake::Snake() : m_snake_width{30}, m_snake_height{30}, m_x_coord{SSDL_GetWindowWidth() / 2}, m_y_coord{SSDL_GetWindowHeight() / 2}, m_speed{3}, m_sprite{}, m_dir{STOP}
{
    SSDL_SetSpriteImage (m_sprite, SSDL_LoadImage("snake.png"));
    SSDL_SetSpriteSize(m_sprite, m_snake_width, m_snake_height);
    SSDL_SetSpriteOffset (m_sprite, m_snake_width / 2, m_snake_height / 2);
    SSDL_SetSpriteLocation(m_sprite, m_x_coord, m_y_coord);
}

Snake::Snake(int snake_width, int snake_height, int x_coord, int y_coord, int speed, SSDL_Sprite sprite, direction dir) : m_snake_width{snake_width}, m_snake_height{snake_height}, m_x_coord{x_coord}, m_y_coord{y_coord}, m_speed{speed}, m_sprite{sprite}, m_dir{dir}
{}

// accessors

int Snake::snake_width() const
{
    return m_snake_width;
}

int Snake::snake_height() const
{
    return m_snake_height;
}

int Snake::x_coord() const
{
    return m_x_coord;
}

int Snake::y_coord() const
{
    return m_y_coord;
}

int Snake::speed() const
{
    return m_speed;
}

direction Snake::dir() const
{
    return m_dir;
}

SSDL_Sprite& Snake::sprite()
{
    return m_sprite;
}

// mutators

void Snake::set_snake_width(const int snake_width)
{
    m_snake_width = snake_width;
}

void Snake::set_snake_height(const int snake_height)
{
    m_snake_height = snake_height;
}

void Snake::set_x_coord(const int x_coord)
{
    m_x_coord = x_coord;
}

void Snake::set_y_coord(const int y_coord)
{
    m_y_coord = y_coord;
}

void Snake::set_speed(const int speed)
{
    m_speed = speed;
}

void Snake::set_sprite(SSDL_Sprite sprite)
{
    m_sprite = sprite;
}

void Snake::set_dir(const direction dir)
{
    m_dir = dir;
}

// *****************Apple sprite******************************

// constructors

Apple::Apple() : m_apple_width{30}, m_apple_height{30}, m_x_coord{200}, m_y_coord{200}, m_sprite{}
{
    SSDL_SetSpriteImage (m_sprite, SSDL_LoadImage("apple2.png"));
    SSDL_SetSpriteSize(m_sprite, m_apple_width, m_apple_height);
    SSDL_SetSpriteOffset (m_sprite, m_apple_width / 2, m_apple_height / 2);
    SSDL_SetSpriteLocation(m_sprite, m_x_coord, m_y_coord); 
}

Apple::Apple(int apple_width, int apple_height, int x_coord, int y_coord, SSDL_Sprite sprite) : m_apple_width{apple_width}, m_apple_height{apple_height}, m_x_coord{x_coord}, m_y_coord{y_coord}, m_sprite{sprite}
{}

//Accessors
int Apple::apple_width() const
{
    return m_apple_width;
}

int Apple::apple_height() const
{
    return m_apple_height;
}

int Apple::x_coord() const
{
    return m_x_coord;
}

int Apple::y_coord() const
{
    return m_y_coord;
}

SSDL_Sprite& Apple::sprite()
{
    return m_sprite;
}

// Mutators
void Apple::set_apple_width(const int apple_width)
{
    m_apple_width = apple_width;
}

void Apple::set_apple_height(const int apple_height)
{
    m_apple_height = apple_height;
}

void Apple::set_x_coord(const int x_coord)
{
    m_x_coord = x_coord;
}

void Apple::set_y_coord(const int y_coord)
{
    m_y_coord = y_coord;
}

void Apple::set_sprite(SSDL_Sprite sprite)
{
    m_sprite = sprite;
}

// *************************game class**************************

// constructors

Game::Game() : m_window_width{1000}, m_window_height{700}, m_running{false}, m_score{0}
{}

Game::Game(int window_width, int window_height, bool running, int score) : m_window_width{window_width}, m_window_height{window_height}, m_running{running}, m_score{score}
{}

// accessors

int Game::window_width() const
{
    return m_window_width;
}

int Game::window_height() const
{
    return m_window_height;
}

bool Game::running() const
{
    return m_running;
}

int Game::score() const
{
    return m_score;
}

// Mutators

void Game::set_window_width(const int window_width)
{
    m_window_width = window_width;
}

void Game::set_window_height(const int window_height)
{
    m_window_height = window_height;
}

void Game::set_running(const bool running)
{
    m_running = running;
}

void Game::set_score(const int score)
{
    m_score = score;
}





Coord::Coord() : m_x{0}, m_y{0}
{}

Coord::Coord(int x, int y) : m_x{x}, m_y{y}
{}

int Coord::x() const
{
    return m_x;
}

int Coord::y() const
{
    return m_y;
}

void Coord::set_x(const int x)
{
    m_x = x;
}

void Coord::set_y(const int y)
{
    m_y = y;
}
