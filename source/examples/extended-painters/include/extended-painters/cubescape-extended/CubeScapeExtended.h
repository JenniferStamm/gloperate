#pragma once

#include <basic-painters/cubescape/CubeScape.h>

#include <reflectionzeug/PropertyGroup.h>
#include <reflectionzeug/Color.h>

#include <extended-painters/extended_painters_api.h>

class EXTENDED_PAINTERS_API CubeScapeExtended : public CubeScape, public reflectionzeug::PropertyGroup
{
public:
	CubeScapeExtended(gloperate::ResourceManager & resourceManager);
	virtual ~CubeScapeExtended();
    std::string texture() const;
    void setTexture(const std::string & texture);
    reflectionzeug::Color color() const;
    void setColor(const reflectionzeug::Color & color);
protected:
    std::string m_texture;
    reflectionzeug::Color m_color;
};
