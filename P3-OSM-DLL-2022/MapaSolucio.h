#pragma once

#include "MapaBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"
#include <map>
#include <string>
#include <vector>

class MapaSolucio : public MapaBase
{
private:
    PuntDeInteresBotigaSolucio* m_botiga;
    PuntDeInteresRestaurantSolucio* m_restaurant;
    CamiSolucio* m_cami;

    struct DadesPdi
    {
        std::string id;
        Coordinate coord;
        std::string name;
        std::string shop;
        std::string amenity;
        std::string cuisine;
        std::string openingHours;
        bool wheelchair;
    };

    // Estructures internes emplenades per parsejaXmlElements (Tasca 7).
    std::map<std::string, Coordinate> m_nodes;
    std::vector<DadesPdi> m_pdisDades;
    std::vector<std::vector<std::string>> m_caminsRefs;
    std::vector<PuntDeInteresBase*> m_pdisReals;
    std::vector<CamiBase*> m_caminsReals;
    bool m_xmlCarregat = false;

public:
    MapaSolucio();
    ~MapaSolucio();

    void getPdis(std::vector<PuntDeInteresBase*>& pdis) override;
    void getCamins(std::vector<CamiBase*>& camins) override;
    void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;
};
