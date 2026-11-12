#pragma once

#include "PuntDeInteresBase.h"
#include <string>

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{
private:
    std::string m_cuisine;
    bool m_wheelchair;

public:
    PuntDeInteresRestaurantSolucio(
        Coordinate coord,
        std::string name,
        std::string cuisine,
        bool wheelchair
    );

    std::string getName() override;
    unsigned int getColor() override;
};
