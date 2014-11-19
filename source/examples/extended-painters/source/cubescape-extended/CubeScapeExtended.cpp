#include <extended-painters/cubescape-extended/CubeScapeExtended.h>

#include <reflectionzeug/Property.h>

CubeScapeExtended::CubeScapeExtended(gloperate::ResourceManager & resourceManager)
: CubeScape(resourceManager)
{
    addProperty<int> (std::string("numcubes"),  dynamic_cast<CubeScape*>(this), &CubeScape::numberOfCubes, &CubeScape::setNumberOfCubes);
    addProperty<bool>(std::string("animation"), dynamic_cast<CubeScape*>(this), &CubeScape::animation,     &CubeScape::setAnimation);
    auto texture = addProperty<std::string>(std::string("texture"), this, &CubeScapeExtended::texture,     &CubeScapeExtended::setTexture);
    std::vector<std::string> textures{ {"1.png", "2.png" , "3.png" , "4.png"} };
    texture->setOption("choices", textures);
}

CubeScapeExtended::~CubeScapeExtended()
{
}

std::string CubeScapeExtended::texture() const
{
    return m_texture;
}

void CubeScapeExtended::setTexture(const std::string & texture)
{
    m_texture = texture;
}
