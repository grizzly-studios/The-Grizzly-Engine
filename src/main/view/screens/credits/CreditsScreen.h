/* 
 * File:   CreditsScreen.h
 * Author: Will Poynter
 *
 * Created on April 5, 2015, 11:44 AM
 */

#ifndef CREDITSSCREEN_H
#define	CREDITSSCREEN_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "../../../util/Logger.h"
#include "../../StyleManager.h"

#include "../../../app/GameState.h"
#include "../../../event/GameStateChangedEvent.h"
#include "../../../event/IEventManager.hpp"
#include "ICreditsScreen.h"
#include "../../../app/Globals.h"


namespace gs {

class CreditsScreen : public ICreditsScreen {
public:
	CreditsScreen();
	CreditsScreen(IStyleManagerShPtr);
	virtual ~CreditsScreen();
	
	void update();
	void render(RenderWindowShPtr);
	
private:
	IStyleManagerShPtr styleManager;
	sf::Texture logoTex;
	sf::Image logoImg;

	//Screen objects
	sf::Sprite logo;
	std::list<sf::Text> nameTexts;
	std::list<sf::Text> titleTexts;
	std::list<sf::RectangleShape> nameBorders;
	std::list<sf::RectangleShape> titleBorders;
};

}

#endif	/* CREDITSSCREEN_H */

