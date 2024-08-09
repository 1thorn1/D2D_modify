#pragma once

class Vector3
{
public:
    float x, y, z;

    Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& other) const
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator*(float scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 operator-() const
    {
        return Vector3(-x, -y, -z);
    }

    static float Dot(const Vector3& a, const Vector3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
};

Vector3 Reflect(const Vector3& velocity, const Vector3& normal)
{
    float dotProduct = Vector3::Dot(-velocity, normal);
    return velocity + normal * (2 * dotProduct);
}

