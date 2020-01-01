#include <ctgmath>
#include <SFML/Audio.hpp>
#include "StateLvl1.hpp"
#include "Player.hpp"
#include "Bailiff.hpp"
#include "Poele.hpp"
#include <sstream>
#include "Definition.hpp"
#include "sprite_manipulation.hpp"
#include "StateScoreboard.hpp"
#include <iostream>
#include <array>

namespace Gengine
{
    StateLvl1::StateLvl1(GameDataRef data) : _data(data)
    {
    }

    void StateLvl1::Init()
    {
	this->_data->assets.LoadTexturesFromFile(STAGE_R_PATH);
	this->_background.setTexture(this->_data->assets.GetTexture("Background-Galaxy"));

	this->_stars.setTexture(this->_data->assets.GetTexture("Stars"));
	this->_stars.setOrigin(this->_stars.getTexture()->getSize().x / 2, this->_stars.getTexture()->getSize().y / 2);
	this->_stars.setPosition(WIDTH / 2, HEIGHT / 2);

	this->_house.setTexture(this->_data->assets.GetTexture("House"));
	this->_house.setOrigin(this->_house.getTexture()->getSize().x / 2, this->_house.getTexture()->getSize().y / 2);
	this->_house.setPosition(WIDTH / 2, HEIGHT / 2);

	this->_data->assets.LoadFont("font", "ressources/stage/font.ttf");
	this->_score.setFont(_data->assets.GetFont("font"));

	this->_player = new Player("Player", this->_data->assets.GetTexture("Papa"), this->_data->assets.GetTexture("Arm"));
	this->_player->setPosition(WIDTH / 2, HEIGHT / 2  - this->_player->getDistance());
	this->_player->getSprite().setOrigin(this->_player->getSprite().getGlobalBounds().width / 2, this->_player->getSprite().getGlobalBounds().height / 2);

	this->_buffer[0].loadFromFile("Audio/Fabien.wav");
	this->_sound[0].setBuffer(this->_buffer[0]);
	this->_buffer[1].loadFromFile("Audio/Linda.wav");
        this->_sound[1].setBuffer(this->_buffer[1]);
	this->_buffer[2].loadFromFile("Audio/Moussa.wav");
        this->_sound[2].setBuffer(this->_buffer[2]);
	this->_buffer[3].loadFromFile("Audio/Raja.wav");
        this->_sound[3].setBuffer(this->_buffer[3]);
    }

    GameObject *StateLvl1::getPlayer()
    {
	for(size_t i = 0; i < this->_objectList.size(); i++) {
	    if (this->_objectList[i].getType() == "Player") {
		return (&this->_objectList[i]);
	    }
	}
		return (nullptr);
    }

	void StateLvl1::HandleInput()
	{
	sf::Event event;

	// this->_play_button.setTexture(this->_data->assets.GetTexture("Button"));
	//         this->_play_button.setPosition(1700 - this->_play_button.getGlobalBounds().width,
	//                                                                                 650 - _play_button.getGlobalBounds().height);

	while (_data->window.pollEvent(event))
	{
	    if (sf::Event::Closed == event.type)
		this->_data->window.close();
	    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->_player->extend_arm();
		double xMouseCenter = this->_data->input.GetMousePosition(this->_data->window).x - this->_player->getArm().getPosition().x;
		double yMouseCenter = this->_data->input.GetMousePosition(this->_data->window).y - this->_player->getArm().getPosition().y;
		double zMouseCenter = sqrt(pow(xMouseCenter, 2) + pow(yMouseCenter, 2));

		double angle = asin(xMouseCenter / zMouseCenter) * 180 / M_PI;

		float currentTime = this->_clockFire.getElapsedTime().asSeconds();

		if (currentTime > 1) {
		    //int j = 0;
		    //for (std::vector<Bailiff>::iterator it = this->_objectList.begin(); it != this->_objectList.end(); ++it) {
		    //double angleBailiff = (*it).getAngle() * 180 / M_PI;

//			if ((angle - angleBailiff < 5 && angle - angleBailiff > -5) && (*it).getDistance() < 800) {

		    Poele *poele = new Poele(this->_data->assets.GetTexture("Poele"), this->_player->getArm().getPosition().x, this->_player->getArm().getPosition().y,
					     this->_data->input.GetMousePosition(this->_data->window).x, this->_data->input.GetMousePosition(this->_data->window).y);
			    poele->getSprite().setPosition(this->_player->getArm().getPosition().x, this->_player->getArm().getPosition().y);
			    poele->getSprite().setOrigin(poele->getSprite().getGlobalBounds().width / 2, poele->getSprite().getGlobalBounds().height / 2);

			    this->_poeleList.push_back(*poele);

//			    this->_objectList.erase(this->_objectList.begin() + j);
//			    this->_score.setScore(this->_score.getScore() + 100);
//			    break;
//			}
//		    }
		    this->_clockFire.restart();
		}
	    }
	}
    }

    void StateLvl1::Update(float dt)
    {
	rotateSprite(this->_stars, this->_clock, 0.1f, 0.1f);

	int xMouseCenter = this->_data->input.GetMousePosition(this->_data->window).x - (WIDTH / 2);
	int yMouseCenter = this->_data->input.GetMousePosition(this->_data->window).y - (HEIGHT / 2);
	int zMouseCenter = sqrt(pow(xMouseCenter, 2) + pow(yMouseCenter, 2));

	this->_player->getSprite().setPosition(
	    WIDTH / 2 + (xMouseCenter * this->_player->getDistance()) / zMouseCenter,
	    HEIGHT / 2 + (yMouseCenter * this->_player->getDistance()) / zMouseCenter);

	this->_score.update();
	this->_player->update(_data->window);

	rotateSprite(this->_stars, this->_clock, 0.1f, 0.1f);

	// APPARITION DES MOBS
	float currentTime = this->_clockSpawn.getElapsedTime().asSeconds();
	if (this->_score.getScore() <= 0) {
        _data->machine.AddState(StateRef(new StateScoreboard(_data)));
    }
	if (currentTime > LVL1_SPEED) {

	    this->_sound[rand() % 4].play();

	    Bailiff *bailiff = new Bailiff("Bailiff", this->_data->assets.GetTexture("Bailiff"));
	    bailiff->setPosition(rand() % WIDTH, rand() % HEIGHT);
	    bailiff->getSprite().setOrigin(bailiff->getSprite().getGlobalBounds().width / 2, bailiff->getSprite().getGlobalBounds().height / 2);

	    int posx = bailiff->getSprite().getPosition().x - (WIDTH / 2);
	    int posy = bailiff->getSprite().getPosition().y - (HEIGHT / 2);
	    int posz = sqrt(pow(posx, 2) + pow(posy, 2));
	    int newPosx = (posx * bailiff->getDistance()) / posz;
	    int newPosy = (posy * bailiff->getDistance()) / posz;
	    bailiff->getSprite().setPosition(WIDTH / 2 + newPosx, HEIGHT / 2 + newPosy);

	    this->_objectList.push_back(*bailiff);

	    this->_clockSpawn.restart();
	}

	// AVANCEMENT DES MOBS
	currentTime = this->_clockTic.getElapsedTime().asSeconds();

        if (currentTime > 0.05) {
	    for (std::vector<Bailiff>::iterator it = this->_objectList.begin(); it != this->_objectList.end(); ++it) {
		(*it).reduceDistance();

		if ((*it).getDistance() < 100) {
		    this->_score.setScore(this->_score.getScore() - 500);
		    if (this->_score.getScore() <= 0) {
			_data->machine.AddState(StateRef(new StateScoreboard(_data)));
			//this->_data->machine.RemoveState();
		    }
		} else {
		    int posx = (*it).getSprite().getPosition().x - (WIDTH / 2);
		    int posy = (*it).getSprite().getPosition().y - (HEIGHT / 2);
		    int posz = sqrt(pow(posx, 2) + pow(posy, 2));
		    int newPosx = (posx * (*it).getDistance()) / posz;
		    int newPosy = (posy * (*it).getDistance()) / posz;

		    (*it).getSprite().setPosition(WIDTH / 2 + newPosx, HEIGHT / 2 + newPosy);
		}
	    }
	    for (std::vector<Poele>::iterator it = this->_poeleList.begin(); it != this->_poeleList.end(); ++it) {
                (*it).augmentDistance();

                if ((*it).getDistance() > 1000) {

                    this->_score.setScore(this->_score.getScore() - 50);
		    this->_poeleList.erase(it);
		    break;
		    if (this->_score.getScore() <= 0) {
                        _data->machine.AddState(StateRef(new StateScoreboard(_data)));
                        //this->_data->machine.RemoveState();
                    }
                } else {
		    int posx = (*it).getSprite().getPosition().x - (WIDTH / 2);
                    int posy = (*it).getSprite().getPosition().y - (HEIGHT / 2);
                    int posz = sqrt(pow(posx, 2) + pow(posy, 2));
                    int newPosx = (posx * (*it).getDistance()) / posz;
                    int newPosy = (posy * (*it).getDistance()) / posz;

                    (*it).getSprite().setPosition(WIDTH / 2 + newPosx, HEIGHT / 2 + newPosy);

		    // int posx = (*it).getSprite().getPosition().x - (*it).getOriginPosition().x;
		    // int posy = (*it).getSprite().getPosition().y - (*it).getOriginPosition().y;
		    // int posz = sqrt(pow(posx, 2) + pow(posy, 2));
		    // if (posz == 0) {
		    // 	int posx = this->_data->input.GetMousePosition(this->_data->window).x - (*it).getOriginPosition().x;
		    // 	int posy = this->_data->input.GetMousePosition(this->_data->window).y - (*it).getOriginPosition().y;
		    // 	posz = sqrt(pow(posx, 2) + pow(posy, 2));
		    // }

		    // int newPosx = posx * ((*it).getDistance()) / (*it).getSprite().getPosition().x;
		    // int newPosy = posy * ((*it).getDistance()) / (*it).getSprite().getPosition().y;

		    // // int newPosx = ((*it).getDistance()) * posz;
		    // // int newPosy = ((*it).getDistance()) * posz;

		    // (*it).getSprite().setPosition((*it).getSprite().getPosition().x + newPosx, (*it).getSprite().getPosition().y + newPosy);

		    int lock = 0;
                    for (std::vector<Bailiff>::iterator itB = this->_objectList.begin(); itB != this->_objectList.end(); ++itB) {
		    	if (is_colliding((*itB).getSprite(), (*it).getSprite())) {
		    	    this->_objectList.erase(itB);
		    	    this->_poeleList.erase(it);
		    	    this->_score.setScore(this->_score.getScore() + 10);
		    	    lock = 1;
		    	    break;
		    	}
                    }
		    if (lock == 1)
		    	break;

		}
	    }
	    this->_clockTic.restart();
	 }
    }

    void StateLvl1::Draw(float dt)
    {
	this->_data->window.clear(sf::Color::Blue);
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_stars);
	this->_data->window.draw(this->_house);
	this->_player->draw(this->_data->window);
	for (std::vector<Bailiff>::iterator it = this->_objectList.begin() ; it != this->_objectList.end(); ++it) {
	    this->_data->window.draw((*it).getSprite());
	}
	for (std::vector<Poele>::iterator it = this->_poeleList.begin() ; it != this->_poeleList.end(); ++it) {
            this->_data->window.draw((*it).getSprite());
        }
	this->_score.display(_data->window);
	this->_data->window.display();
    }
}
