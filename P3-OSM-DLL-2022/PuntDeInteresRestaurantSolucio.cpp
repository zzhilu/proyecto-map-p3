#include "pch.h"
#include "PuntDeInteresRestaurantSolucio.h"

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio(
    Coordinate coord,
    std::string name,
    std::string cuisine,
    bool wheelchair
) : PuntDeInteresBase(coord, name),
    m_cuisine(cuisine),
    m_wheelchair(wheelchair)
{
}

std::string PuntDeInteresRestaurantSolucio::getName()
{
    return PuntDeInteresBase::getName();
}

unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
    if (m_cuisine == "pizza" && m_wheelchair)
        return 0x7FFFD4;

    if (m_cuisine == "chinese")
        return 0x00FFFF;

    if (m_wheelchair)
        return 0x5D3FD3;

    return PuntDeInteresBase::getColor();
}
