//
//  SpaceEvaders.h
//  The Grizzly Engine
//
//  Created by William Poynter on 28/04/2015.
//  Copyright (c) 2015 Grizzly Studios. All rights reserved.
//

#ifndef SpaceEvaders__
#define SpaceEvaders__

#include "../main/app/Application.h"

namespace gs {

namespace se {

class SpaceEvaders : public Game {
public:
    SpaceEvaders(int argc, char** argv);
    virtual ~SpaceEvaders();
    
protected:
    virtual void setupScreens();
    virtual void setupListeners();
};
    
}
    
}

#endif /* defined(SpaceEvaders__) */
