#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

namespace Gengine
{
	class AssetManager {
		public:
			AssetManager(){}
			~AssetManager(){}
			void Loadtexture(const std::string &name, const std::string &filepath);
			void LoadTexturesFromFile(const std::string &filepath);
			sf::Texture &GetTexture(const std::string &name);
			void LoadFont(const std::string &name, const std::string &filepath);
			sf::Font &GetFont(const std::string &name);
		private:
			std::map<std::string, sf::Texture> _textures;
			std::map<std::string, sf::Font> _fonts;
	};
}