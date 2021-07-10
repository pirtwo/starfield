#ifndef STAR_H_INCLUDE
#define STAR_H_INCLUDE

#include <SFML/Graphics.hpp>

class Star : public sf::Drawable
{
public:
    float speed;
    float radius;
    sf::Color color;
    sf::Vector2f velocity;
    sf::Vector2f position;
    sf::CircleShape shape;

    Star(
        float radius,
        float speed,
        sf::Color color,
        sf::Vector2f position,
        sf::Vector2f velocity);

    virtual void draw(
        sf::RenderTarget &target,
        sf::RenderStates states) const;

    void update();
    sf::Vector2f getPos() const;
};

#endif