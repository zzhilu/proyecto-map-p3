#pragma once

#include "CamiBase.h"
#include <vector>

class CamiSolucio : public CamiBase
{
private:
    std::vector<Coordinate> m_coords;

public:
    CamiSolucio();
    explicit CamiSolucio(const std::vector<Coordinate>& coords);

    std::vector<Coordinate> getCamiCoords() override;
};
