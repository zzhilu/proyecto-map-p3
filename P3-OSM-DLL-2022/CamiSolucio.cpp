#include "pch.h"
#include "CamiSolucio.h"

CamiSolucio::CamiSolucio()
{
    m_coords.push_back({ 41.4928803, 2.1452381 });
    m_coords.push_back({ 41.4929072, 2.1452474 });
    m_coords.push_back({ 41.4933070, 2.1453852 });
    m_coords.push_back({ 41.4939882, 2.1456419 });
}

std::vector<Coordinate> CamiSolucio::getCamiCoords()
{
    return m_coords;
}
CamiSolucio::CamiSolucio(
    const std::vector<Coordinate>& coords)
{
    m_coords = coords;
}