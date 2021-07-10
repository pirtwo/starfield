#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>

/* 
    returns a random float number between [n,m)
*/
float randFloat(float m, float n)
{
    return m + (n - m) * (rand() / (RAND_MAX + 1.f));
}

/*
    calculates distance between point a and point b
*/
float calcDist(sf::Vector2f a, sf::Vector2f b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}