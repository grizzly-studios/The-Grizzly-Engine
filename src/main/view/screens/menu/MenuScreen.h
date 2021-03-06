/* 
 * File:   MenuScreen.h
 * Author: williampoynter
 *
 * Created on October 12, 2014, 9:00 AM
 */

#ifndef MENUSCREEN_H
#define	MENUSCREEN_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "IMenuScreen.h"

#include "../../../util/Logger.h"
#include "../../StyleManager.h"

namespace gs {

class MenuScreen : public IMenuScreen {
public:
	MenuScreen();
	MenuScreen(IStyleManagerShPtr);
	virtual ~MenuScreen();
	
	void update();
	void render(RenderWindowShPtr);
	
	void setMenuPos(int);
	void moveMenuPos(int);
	int getMenuPos();
	void setSelected(MenuItem);
	MenuItem getSelected();
private:
	IStyleManagerShPtr styleManager;
	int menuPos;
	MenuItem selected;
};

}

#endif	/* MENUSCREEN_H */

