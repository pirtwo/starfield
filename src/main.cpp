#include <SFML/Graphics.hpp>
#include <Star.h>
#include <helper.h>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "STARFIELD");
    window.setFramerateLimit(60);

    sf::Clock clock;
    vector<Star> starField = {};
    float speed = 1.05;
    const int starNum = 500;
    const float bound = window.getSize().x / 1.5;
    const sf::Color color(255, 255, 255, 200);
    const sf::Vector2f center(
        window.getSize().x / 2,
        window.getSize().y / 2);

    srand(time(NULL));

    for (int i = 0; i < starNum; i++)
    {
        sf::Vector2f pos(
            randFloat(0, window.getSize().x),
            randFloat(0, window.getSize().y));

        sf::Vector2f vel(
            (pos.x - center.x) / window.getSize().x,
            (pos.y - center.y) / window.getSize().y);

        Star star(randFloat(1.0, 2.0), speed, color, pos, vel);
        starField.push_back(star);
    }

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (sf::Event::KeyReleased)
            {
                if (e.key.code == sf::Keyboard::W)
                {
                    speed += 0.01;
                }
                if (e.key.code == sf::Keyboard::S)
                {
                    speed -= 0.01;
                }
            }

            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        // modify speed every 5 sec
        if (clock.getElapsedTime().asMilliseconds() > 5000)
        {
            speed += randFloat(-0.01, 0.01);
            speed = speed < 1.03 || speed > 1.1 ? 1.05 : speed;
            clock.restart();
        }

        for (int i = 0; i < starNum; i++)
        {
            auto star = &starField[i];

            // reset if star gose out of bounds
            if (calcDist(star->getPos(), center) > bound)
            {
                sf::Vector2f pos(
                    randFloat(0, window.getSize().x),
                    randFloat(0, window.getSize().y));

                sf::Vector2f vel(
                    (pos.x - center.x) / window.getSize().x,
                    (pos.y - center.y) / window.getSize().y);

                star->color.a = 0;
                star->velocity = vel;
                star->shape.setPosition(pos);
            }

            star->speed = speed;
            star->update();
            window.draw(*star);
        }

        window.display();
    }

    return EXIT_SUCCESS;
}