#include "TextureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

// nullptr initialization to hold address of texture
TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	// assert ??
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(string const& filename)
{
	// get a reference to m_Textures using m_s_Instance ptr
	// auto will be map<string, Texture>
	auto& m = m_s_Instance->m_Textures;

	// an iterator to hold a key-value pair and search for it with the filename passed
	auto keyValuePair = m.find(filename);

	if (keyValuePair != m.end())
	{
		// if a match is found, return the texture (2nd value of map)
		return keyValuePair->second;
	}
	else
	{
		// if no filename match is found, create a new key-value pair using filename
		auto& texture = m[filename];

		// then load the texture from the file
		texture.loadFromFile(filename);

		// return the texture
		return texture;
	}
}