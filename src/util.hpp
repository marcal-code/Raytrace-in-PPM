#pragma once

#include <cmath>
#include <iostream>

namespace util {

struct Vec2 {

    float x;
    float y;

    Vec2(float x, float y) 
        : x(x), y(y) {}

    Vec2 operator+(const Vec2 &vec) const;
    Vec2 operator-(const Vec2 &vec) const;
    Vec2 operator*(float scalar) const;
    Vec2 operator/(float scalar) const;
};

struct Vec3 {

    float x;
    float y;
    float z;

    Vec3(float x, float y, float z) 
        : x(x), y(y), z(z) {}

    Vec3(const Vec2 &vec2, float z)
        : x(vec2.x), y(vec2.y), z(z) {}

    static float dot(const Vec3 &vec1, const Vec3 &vec2);
    static Vec3 normalize(const Vec3 &vec);

    float magnitude() const;

    Vec3 operator+(const Vec3 &vec) const;
    Vec3 operator-(const Vec3 &vec) const;
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;

    void print() const;
};

struct Color {

    float r;
    float g;
    float b;

    Color() :r(0), g(0), b(0) {}

    Color(float red, float green, float blue) 
        :r(red), g(green), b(blue) {}

    Color(const Vec3 &vec3)
        :r(vec3.x), g(vec3.y), b(vec3.z) {}

    static Color convertRGB(const Color &color);
    static Color convert0to1(const Color &color);

    Color operator+(float scalar) const;
    Color operator-(float scalar) const;
    Color operator*(float scalar) const;
    Color operator/(float scalar) const;
};

} // namespace util

