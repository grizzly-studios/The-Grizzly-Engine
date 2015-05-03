/* 
 * File:   Application.h
 * Author: williampoynter
 *
 * Created on September 25, 2013, 1:11 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include <memory>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../event/EventManager.h"
#include "../event/GameStateChangedEvent.h"

#include "../logic/Logic.h"

#include "../view/View.h"

namespace gs {

typedef std::shared_ptr<sf::RenderWindow> RenderWindowShPtr;

class Game {
public:
	Game(int argc, char** argv);
	virtual ~Game();

	void init();
	void run();
    
protected:
    virtual void setupScreens() =0;
    virtual void setupListeners() =0;
	
	IEventManagerPtr eventManager;
    IStyleManagerShPtr styleManager;
    ISpriteFactoryShPtr spriteFactory;
	ILogicPtr logic;
	IViewPtr view;
	bool flush;
	unsigned int FR;
	unsigned int AL;
	unsigned int WIDTH, HEIGHT;
	sf::ContextSettings settings;
	RenderWindowShPtr window;
	sf::Clock *clock;
};

}

#endif	/* APPLICATION_H */

