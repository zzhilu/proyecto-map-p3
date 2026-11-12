#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"

PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio(
    Coordinate coord,
    std::string name,
    std::string shop,
    std::string openingHours,
    bool wheelchair
) : PuntDeInteresBase(coord, name),
    m_shop(shop),
    m_openingHours(openingHours),
    m_wheelchair(wheelchair)
{
}

std::string PuntDeInteresBotigaSolucio::getName()
{
    return PuntDeInteresBase::getName();
}

unsigned int PuntDeInteresBotigaSolucio::getColor()
{
    if (m_shop == "supermarket")
        return 0xDFFF00;

    if (m_shop == "tobacco")
        return 0xFF7F50;

    if (m_shop == "bakery")
    {
        const bool isOpenFromSixToTen =
            m_openingHours.find("06:00-22:00") != std::string::npos ||
            m_openingHours.find("06:00 - 22:00") != std::string::npos;

        if (isOpenFromSixToTen && m_wheelchair)
            return 0x4CBB17;

        return 0xFA8072;
    }

    return 0xFFEA00;
}
