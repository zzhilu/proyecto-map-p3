
#include "pch.h"
#include "MapaSolucio.h"

MapaSolucio::MapaSolucio()
{
    Coordinate coordBotiga = { 41.4918606, 2.1465411 };
    Coordinate coordRestaurant = { 41.4902204, 2.1406477 };

    m_botiga = new PuntDeInteresBotigaSolucio(
        coordBotiga,
        "La Millor Pastisseria",
        "bakery",
        "",
        false
    );

    m_restaurant = new PuntDeInteresRestaurantSolucio(
        coordRestaurant,
        "El Millor Restaurant",
        "regional",
        true
    );
}

MapaSolucio::~MapaSolucio()
{
    delete m_botiga;
    delete m_restaurant;
}

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis)
{
    pdis.push_back(m_botiga);
    pdis.push_back(m_restaurant);
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins)
{
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
}
