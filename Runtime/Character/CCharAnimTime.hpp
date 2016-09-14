#ifndef __URDE_CCHARANIMTIME_HPP__
#define __URDE_CCHARANIMTIME_HPP__

#include "IOStreams.hpp"

namespace urde
{

class CCharAnimTime
{
public:
    enum class EType
    {
        NonZero,
        ZeroIncreasing,
        ZeroSteady,
        ZeroDecreasing,
        Infinity
    };
private:
    float x0_time = 0.f;
    EType x4_type = EType::ZeroSteady;
public:
    CCharAnimTime() = default;
    CCharAnimTime(CInputStream& in)
        : x0_time(in.readFloatBig()),
          x4_type(EType(in.readUint32Big())) {}
    CCharAnimTime(float time)
        : x0_time(time),
          x4_type(x0_time != 0.f ? EType::NonZero : EType::ZeroSteady) {}

    CCharAnimTime(EType type, const float& t)
    : x0_time(t)
    , x4_type(type)
    {
    }

    static CCharAnimTime Infinity();
    operator float() const {return x0_time;}

    bool EqualsZero() const;
    bool EpsilonZero() const;
    bool GreaterThanZero() const;
    bool operator ==(const CCharAnimTime& other) const;
    bool operator !=(const CCharAnimTime& other) const;
    bool operator>=(const CCharAnimTime& other);
    bool operator<=(const CCharAnimTime& other);
    bool operator >(const CCharAnimTime& other) const;
    bool operator <(const CCharAnimTime& other) const;
    CCharAnimTime& operator*=(const CCharAnimTime& other);
    CCharAnimTime& operator+=(const CCharAnimTime& other);
    CCharAnimTime operator+(const CCharAnimTime& other);
    CCharAnimTime& operator-=(const CCharAnimTime& other);
    CCharAnimTime operator-(const CCharAnimTime& other);
    CCharAnimTime operator*(const CCharAnimTime& other);
    CCharAnimTime operator*(const float& other);
    float operator/(const CCharAnimTime& other);
};
}

#endif // __URDE_CCHARANIMTIME_HPP__
