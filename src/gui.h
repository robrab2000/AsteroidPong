//
//  gui.h
//  effingRidiculousPong
//
//  Created by Robert Homewood on 10/04/2017.
//
//

#ifndef gui_h
#define gui_h

#include "ScoreManager.h"

#include <stdio.h>

class gui {
public:
    void setup(ScoreManager*);
    void update();
    void draw();
    bool startGame();
};

#endif /* gui_h */
