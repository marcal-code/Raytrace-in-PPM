
#include "util.hpp"

#include <cmath>
#include <iostream>

namespace util {

// Vec2
Vec2 Vec2::operator+(const Vec2 &vec) const {
    return Vec2(x + vec.x, y + vec.y);
}

Vec2 Vec2::operator-(const Vec2 &vec) const {
    return Vec2(x - vec.x, y - vec.y);
}

Vec2 Vec2::operator*(float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(float scalar) const {
    return Vec2(x / scalar, y / scalar);
}

// Vec3
float Vec3::dot(const Vec3 &vec1, const Vec3 &vec2) {
    return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

float Vec3::magnitude() const {
    return std::sqrt((x * x) + (y * y) + (z * z));
}

Vec3 Vec3::normalize(const Vec3 &vec) {

    float mag = vec.magnitude();

    if (mag != 0.0)
        return vec * (1.0 / mag);

    return vec;
}

Vec3 Vec3::operator+(const Vec3 &vec) const {
    return (Vec3(x + vec.x, y + vec.y, z + vec.z));
}

Vec3 Vec3::operator-(const Vec3 &vec) const {
    return Vec3(x - vec.x, y - vec.y, z - vec.z);
}

Vec3 Vec3::operator*(float scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar); 
}

Vec3 Vec3::operator/(float scalar) const {
    if (scalar == 0) return *this;
    return Vec3(x / scalar, y / scalar, z / scalar); 
}

void Vec3::print() const {
    std::cout << "( " << x << ", " << y << ", " << z << " )";
}

// Color
Color Color::convertRGB(const Color &color) {

    Color c;
    c.r = std::max(0.0f, color.r * 255.0f);
    c.g = std::max(0.0f, color.g * 255.0f);
    c.b = std::max(0.0f, color.b * 255.0f);

    return c;
}

Color Color::convert0to1(const Color &color) {

    Color c;

    c.r = color.r / 255.0f;
    c.g = color.g / 255.0f;
    c.b = color.b / 255.0f;

    return c;
}

Color Color::operator+(float scalar) const {
    return Color(r + scalar, g + scalar, b + scalar);
}

Color Color::operator-(float scalar) const {
    return Color(r - scalar, g - scalar, b - scalar);
}

Color Color::operator*(float scalar) const {
    return Color(r * scalar, g * scalar, b * scalar);
}

Color Color::operator/(float scalar) const {
    return Color(r / scalar, g / scalar, b / scalar);
}

} // namespace util
