#pragma once
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder
{
private:
	// a map container from the STL holding pairs of String and Texture
	std::map<std::string, sf::Texture> m_Textures;

	// a pointer of the same type as the class itself (1 and only instance)
	static TextureHolder* m_s_Instance;

public:
	TextureHolder();
	static Texture& GetTexture(string const& filename);

};
