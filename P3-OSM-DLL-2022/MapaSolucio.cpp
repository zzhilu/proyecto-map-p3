#include "pch.h"
#include "MapaSolucio.h"
#include "Util.h"
#include <set>

MapaSolucio::MapaSolucio()
{
    Coordinate coordBotiga = { 41.4918606, 2.1465411 };
    Coordinate coordRestaurant = { 41.4902204, 2.1406477 };

    m_botiga = new PuntDeInteresBotigaSolucio(coordBotiga, "La Millor Pastisseria", "bakery", "", false);
    m_restaurant = new PuntDeInteresRestaurantSolucio(coordRestaurant, "El Millor Restaurant", "regional", true);
    m_cami = new CamiSolucio();
}

MapaSolucio::~MapaSolucio()
{
    delete m_botiga;
    delete m_restaurant;
    delete m_cami;
}

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis)
{
    pdis.push_back(m_botiga);
    pdis.push_back(m_restaurant);
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins)
{
    camins.push_back(m_cami);
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
    m_nodes.clear();
    m_pdisDades.clear();
    m_caminsRefs.clear();

    std::vector<DadesPdi> candidatsPdi;
    std::set<std::string> nodesDeCami;

    // Primer guardem tots els nodes. Els ways poden referenciar nodes que
    // apareguin en qualsevol posicio del vector d'elements XML.
    for (XmlElement& element : xmlElements)
    {
        if (element.id_element != "node")
            continue;

        DadesPdi dades = {};

        for (const PAIR_ATTR_VALUE& atribut : element.atributs)
        {
            if (atribut.first == "id")
                dades.id = atribut.second;
            else if (atribut.first == "lat")
                dades.coord.lat = std::stod(atribut.second);
            else if (atribut.first == "lon")
                dades.coord.lon = std::stod(atribut.second);
        }

        for (CHILD_NODE& fill : element.fills)
        {
            if (fill.first != "tag")
                continue;

            const std::pair<std::string, std::string> tag = Util::kvDeTag(fill.second);

            if (tag.first == "name")
                dades.name = tag.second;
            else if (tag.first == "shop")
                dades.shop = tag.second;
            else if (tag.first == "amenity")
                dades.amenity = tag.second;
            else if (tag.first == "cuisine")
                dades.cuisine = tag.second;
            else if (tag.first == "opening_hours")
                dades.openingHours = tag.second;
            else if (tag.first == "wheelchair")
                dades.wheelchair = (tag.second == "yes");
        }

        if (dades.id.empty())
            continue;

        m_nodes[dades.id] = dades.coord;

        if (!dades.name.empty())
            candidatsPdi.push_back(dades);
    }

    // Despres guardem unicament els ways que tenen el tag highway, mantenint
    // l'ordre original de les referencies nd.
    for (XmlElement& element : xmlElements)
    {
        if (element.id_element != "way")
            continue;

        std::vector<std::string> refs;
        bool esHighway = false;

        for (CHILD_NODE& fill : element.fills)
        {
            if (fill.first == "nd")
            {
                for (const PAIR_ATTR_VALUE& atribut : fill.second)
                {
                    if (atribut.first == "ref")
                    {
                        refs.push_back(atribut.second);
                        break;
                    }
                }
            }
            else if (fill.first == "tag")
            {
                const std::pair<std::string, std::string> tag = Util::kvDeTag(fill.second);
                if (tag.first == "highway")
                    esHighway = true;
            }
        }

        if (!esHighway)
            continue;

        m_caminsRefs.push_back(refs);
        nodesDeCami.insert(refs.begin(), refs.end());
    }

    // Un punt d'interes es un node amb name que no forma part d'un highway.
    for (const DadesPdi& candidat : candidatsPdi)
    {
        if (nodesDeCami.find(candidat.id) == nodesDeCami.end())
            m_pdisDades.push_back(candidat);
    }
}
