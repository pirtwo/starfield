#include <SFML/Graphics.hpp>
#include <Star.h>
#include <helper.h>

Star::Star(
    float radius,
    float speed,
    sf::Color color,
    sf::Vector2f pos,
    sf::Vector2f velocity)
{
    this->speed = speed;
    this->radius = radius;
    this->velocity = velocity;
    this->color = color;
    this->color.a = 1;

    this->shape = sf::CircleShape(radius);
    this->shape.setOrigin(sf::Vector2f(radius / 2, radius / 2));
    this->shape.setPosition(pos);
    this->shape.setFillColor(this->color);
}

void Star::update()
{
    // fade in
    this->color.a += this->color.a + 5 < 255 ? 3 : 0;

    // accelrate
    this->velocity.x *= this->speed;
    this->velocity.y *= this->speed;

    // update color
    this->shape.setFillColor(this->color);

    // move
    this->shape.move(this->velocity);
}

void Star::draw(
    sf::RenderTarget &target,
    sf::RenderStates states) const
{
    // find star previous position to draw a drag
    sf::Vertex v1(this->shape.getPosition());
    sf::Vertex v2(this->shape.getPosition() - this->velocity);
    v1.color = this->color;
    v2.color = this->color;
    sf::Vertex line[] = {v1, v2};

    target.draw(line, 2, sf::Lines);
    target.draw(this->shape);
}

sf::Vector2f Star::getPos() const
{
    return this->shape.getPosition();
}