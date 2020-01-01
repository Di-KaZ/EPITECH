#include "AssetManager.hpp"

namespace Gengine
{
	void AssetManager::Loadtexture(const std::string &name, const std::string &filepath)
	{
		sf::Texture texture;

		if (texture.loadFromFile(filepath)) {
			this->_textures[name] = texture;
		}
	}

	sf::Texture &AssetManager::GetTexture(const std::string &name)
	{
		return (this->_textures.at(name));
	}
	void AssetManager::LoadFont(const std::string &name, const std::string &filepath)
	{
		sf::Font font;

		if (font.loadFromFile(filepath)) {
			this->_fonts[name] = font;
		}
	}

	sf::Font &AssetManager::GetFont(const std::string &name)
	{
		return (this->_fonts.at(name));
	}

	void AssetManager::LoadTexturesFromFile(const std::string &filepath)
	{
		std::ifstream file(filepath);
		std::string line;
		size_t i = 0;
		sf::Texture texture;

		if (!file)
			exit (EXIT_FAILURE);
		while (std::getline(file, line)) {
			for (; i < line.size() && line.at(i) != ' '; i += 1);
			if (texture.loadFromFile(line.substr(i + 1))) {
				this->_textures[line.substr(0, i)] = texture;
				std::cout << "[LOADING TEXTURE] : name \"" << line.substr(0, i) << "\" path : "
				<< "\"" << line.substr(i + 1) << "\"" << std::endl;
			}
			else {
					std::cout << "could not load texture :" << line.substr(i + 1) << std::endl;
			}
			i = 0;
		}
	}
}