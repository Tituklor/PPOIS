/// @file Vector3D.cpp
/// @brief Реализация класса трехмерного вектора
/// @date 2025
/// @version 1.0

#include "Vector3D.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace
{
    constexpr double kZeroLengthThreshold = 1e-12;
}

constexpr double Vector3D::kEpsilon;

Vector3D::Vector3D()
        : startX_(0.0),
          startY_(0.0),
          startZ_(0.0),
          endX_(0.0),
          endY_(0.0),
          endZ_(0.0)
{
}

Vector3D::Vector3D(double startX, double startY, double startZ,
                   double endX, double endY, double endZ)
        : startX_(startX),
          startY_(startY),
          startZ_(startZ),
          endX_(endX),
          endY_(endY),
          endZ_(endZ)
{
}

double Vector3D::GetStartX() const { return startX_; }
double Vector3D::GetStartY() const { return startY_; }
double Vector3D::GetStartZ() const { return startZ_; }

double Vector3D::GetEndX() const { return endX_; }
double Vector3D::GetEndY() const { return endY_; }
double Vector3D::GetEndZ() const { return endZ_; }

void Vector3D::SetStart(double x, double y, double z)
{
    startX_ = x;
    startY_ = y;
    startZ_ = z;
}

void Vector3D::SetEnd(double x, double y, double z)
{
    endX_ = x;
    endY_ = y;
    endZ_ = z;
}

double Vector3D::GetDirectionX() const
{
    return endX_ - startX_;
}

double Vector3D::GetDirectionY() const
{
    return endY_ - startY_;
}

double Vector3D::GetDirectionZ() const
{
    return endZ_ - startZ_;
}

double Vector3D::GetLength() const
{
    const double dx = GetDirectionX();
    const double dy = GetDirectionY();
    const double dz = GetDirectionZ();

    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

Vector3D Vector3D::operator+(const Vector3D& rhs) const
{
    return Vector3D(
            0.0,
            0.0,
            0.0,
            GetDirectionX() + rhs.GetDirectionX(),
            GetDirectionY() + rhs.GetDirectionY(),
            GetDirectionZ() + rhs.GetDirectionZ());
}

Vector3D& Vector3D::operator+=(const Vector3D& rhs)
{
    const Vector3D result = *this + rhs;
    *this = result;
    return *this;
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const
{
    return Vector3D(
            0.0,
            0.0,
            0.0,
            GetDirectionX() - rhs.GetDirectionX(),
            GetDirectionY() - rhs.GetDirectionY(),
            GetDirectionZ() - rhs.GetDirectionZ());
}

Vector3D& Vector3D::operator-=(const Vector3D& rhs)
{
    const Vector3D result = *this - rhs;
    *this = result;
    return *this;
}

double Vector3D::operator*(const Vector3D& rhs) const
{
    const double dx = GetDirectionX();
    const double dy = GetDirectionY();
    const double dz = GetDirectionZ();

    const double rhsDx = rhs.GetDirectionX();
    const double rhsDy = rhs.GetDirectionY();
    const double rhsDz = rhs.GetDirectionZ();

    return dx * rhsDx + dy * rhsDy + dz * rhsDz;
}

Vector3D Vector3D::Cross(const Vector3D& rhs) const
{
    const double dx = GetDirectionX();
    const double dy = GetDirectionY();
    const double dz = GetDirectionZ();

    const double rhsDx = rhs.GetDirectionX();
    const double rhsDy = rhs.GetDirectionY();
    const double rhsDz = rhs.GetDirectionZ();

    const double crossX = dy * rhsDz - dz * rhsDy;
    const double crossY = dz * rhsDx - dx * rhsDz;
    const double crossZ = dx * rhsDy - dy * rhsDx;

    return Vector3D(0.0, 0.0, 0.0, crossX, crossY, crossZ);
}

Vector3D Vector3D::operator*(double scalar) const
{
    return Vector3D(
            0.0,
            0.0,
            0.0,
            GetDirectionX() * scalar,
            GetDirectionY() * scalar,
            GetDirectionZ() * scalar);
}

Vector3D& Vector3D::operator*=(double scalar)
{
    const Vector3D result = *this * scalar;
    *this = result;
    return *this;
}

Vector3D Vector3D::operator/(double scalar) const
{
    if (std::abs(scalar) < kZeroLengthThreshold)
    {
        throw std::invalid_argument("Division by zero scalar in Vector3D::operator/.");
    }

    return *this * (1.0 / scalar);
}

Vector3D& Vector3D::operator/=(double scalar)
{
    if (std::abs(scalar) < kZeroLengthThreshold)
    {
        throw std::invalid_argument("Division by zero scalar in Vector3D::operator/=.");
    }

    const Vector3D result = *this / scalar;
    *this = result;
    return *this;
}

double Vector3D::operator^(const Vector3D& rhs) const
{
    const double lengthProduct = GetLength() * rhs.GetLength();
    if (lengthProduct < kZeroLengthThreshold)
    {
        throw std::invalid_argument("Cosine is undefined for zero-length vector.");
    }

    return (*this * rhs) / lengthProduct;
}

bool Vector3D::operator==(const Vector3D& rhs) const
{
    return std::abs(GetLength() - rhs.GetLength()) < kEpsilon;
}

bool Vector3D::operator!=(const Vector3D& rhs) const
{
    return !(*this == rhs);
}

bool Vector3D::operator>(const Vector3D& rhs) const
{
    return GetLength() - rhs.GetLength() > kEpsilon;
}

bool Vector3D::operator>=(const Vector3D& rhs) const
{
    return *this > rhs || *this == rhs;
}

bool Vector3D::operator<(const Vector3D& rhs) const
{
    return rhs > *this;
}

bool Vector3D::operator<=(const Vector3D& rhs) const
{
    return rhs >= *this;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& vector)
{
    out << "Start(" << vector.GetStartX()
        << ", " << vector.GetStartY()
        << ", " << vector.GetStartZ()
        << ") End(" << vector.GetEndX()
        << ", " << vector.GetEndY()
        << ", " << vector.GetEndZ() << ')';
    return out;
}

std::istream& operator>>(std::istream& in, Vector3D& vector)
{
    double startX;
    double startY;
    double startZ;
    double endX;
    double endY;
    double endZ;

    in >> startX >> startY >> startZ >> endX >> endY >> endZ;
    if (in)
    {
        vector.SetStart(startX, startY, startZ);
        vector.SetEnd(endX, endY, endZ);
    }

    return in;
}
