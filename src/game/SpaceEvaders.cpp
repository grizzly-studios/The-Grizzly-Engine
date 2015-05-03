//
//  SpaceEvaders.cpp
//  The Grizzly Engine
//
//  Created by William Poynter on 28/04/2015.
//  Copyright (c) 2015 Grizzly Studios. All rights reserved.
//

#include "SpaceEvaders.h"

using namespace gs;
using namespace gs::se;

SpaceEvaders::SpaceEvaders(int argc, char** argv) : Game::Game(argc, argv) {}

SpaceEvaders::~SpaceEvaders() {}

void SpaceEvaders::setupScreens() {
    /* Create everything for view */

    IGameScreenShPtr gameScreen(new GameScreen(styleManager, spriteFactory));
    IMenuScreenShPtr menuScreen(new MenuScreen(styleManager));
    IPausedScreenShPtr pausedScreen(new PausedScreen(styleManager));
    ILoadingScreenShPtr loadingScreen(new LoadingScreen(styleManager));
    IIntroScreenShPtr introScreen(new IntroScreen(styleManager, eventManager));
    IGameOverScreenShPtr gameOverScreen(new GameOverScreen(styleManager));
    IGameWonScreenShPtr gameWonScreen(new GameWonScreen(styleManager));
    ICreditsScreenShPtr creditsScreen(new CreditsScreen(styleManager));
    /* Menu Screens */
    view->addScreen(menuScreen);
    view->addScreen(creditsScreen);
    /* In Game Screens */
    view->addScreen(gameScreen);
    view->addScreen(pausedScreen);
    view->addScreen(gameOverScreen);
    view->addScreen(gameWonScreen);
    /* Other Screens */
    view->addScreen(loadingScreen);
    view->addScreen(introScreen);
}

void SpaceEvaders::setupListeners() {
    /* Setup the event listeners */
    //IScreenShPtr gameScreen = view->getScreen(GAME_SCREEN);
    IScreenShPtr gameScreen = view->getScreen(typeid(GameScreen));
    //IScreenShPtr gameOverScreen = view->getScreen(GAMEOVER_SCREEN);
    IScreenShPtr gameOverScreen = view->getScreen(typeid(GameOverScreen));
    //IScreenShPtr gameWonScreen = view->getScreen(GAMEWON_SCREEN);
    IScreenShPtr gameWonScreen = view->getScreen(typeid(GameWonScreen));
    
    eventManager->addListener(ENTITY_MOVED_EVENT, MAKE_EVENT_LISTENER(gameScreen));
    eventManager->addListener(ENTITY_CREATED_EVENT, MAKE_EVENT_LISTENER(gameScreen));
    eventManager->addListener(ENTITY_DELETED_EVENT, MAKE_EVENT_LISTENER(gameScreen));
    eventManager->addListener(CHANGE_PLAYER_DIRECTION_EVENT, MAKE_EVENT_LISTENER(logic));
    eventManager->addListener(GAME_START_EVENT, MAKE_EVENT_LISTENER(logic));
    eventManager->addListener(GAME_END_EVENT, MAKE_EVENT_LISTENER(logic));
    eventManager->addListener(GAME_END_EVENT, MAKE_EVENT_LISTENER(gameScreen));
    eventManager->addListener(MENU_ACTION_EVENT, MAKE_EVENT_LISTENER(view));
    eventManager->addListener(SCORE_CHANGED_EVENT, MAKE_EVENT_LISTENER(gameScreen));
    eventManager->addListener(SCORE_CHANGED_EVENT, MAKE_EVENT_LISTENER(gameOverScreen));
    eventManager->addListener(SCORE_CHANGED_EVENT, MAKE_EVENT_LISTENER(gameWonScreen));
}