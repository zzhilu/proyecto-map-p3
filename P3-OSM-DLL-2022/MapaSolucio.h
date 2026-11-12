#pragma once

#include "MapaBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"

class MapaSolucio : public MapaBase
{
private:
    PuntDeInteresBotigaSolucio* m_botiga;
    PuntDeInteresRestaurantSolucio* m_restaurant;
    CamiSolucio* m_cami;

public:
    MapaSolucio();
    ~MapaSolucio();

    void getPdis(std::vector<PuntDeInteresBase*>& pdis) override;
    void getCamins(std::vector<CamiBase*>& camins) override;
    void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;
};
