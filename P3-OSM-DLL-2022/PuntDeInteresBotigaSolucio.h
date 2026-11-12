#pragma once

#include "PuntDeInteresBase.h"
#include <string>

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase
{
private:
    std::string m_shop;
    std::string m_openingHours;
    bool m_wheelchair;

public:
    PuntDeInteresBotigaSolucio(
        Coordinate coord,
        std::string name,
        std::string shop,
        std::string openingHours,
        bool wheelchair
    );

    std::string getName() override;
    unsigned int getColor() override;
};
