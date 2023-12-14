#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

/**
 * @brief Calculates the length of a 2D vector.
 * @param v The input vector.
 * @return The length of the vector.
 */
inline float length(const sf::Vector2f &v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

/**
 * @brief Normalizes a 2D vector.
 * @param v The input vector.
 * @return The normalized vector. If the input vector has zero length, returns a zero vector.
 */
inline sf::Vector2f normalize(const sf::Vector2f &v) {
    float len = length(v);
    if (len <= 0.0f)
        return sf::Vector2f{0, 0};
    else
        return v * (1.0f / len);
}