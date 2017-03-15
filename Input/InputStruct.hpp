#ifndef INPUT_STRUCT_H
#define INPUT_STRUCT_H
struct INPUT_STRUCT {
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
        bool upPressed = false;
        bool downPressed = false;
        bool leftPressed = false;
        bool rightPressed = false;
        bool upReleased = false;
        bool downReleased = false;
        bool leftReleased = false;
        bool rightReleased = false;
        bool enterPressed = false;
    };
typedef INPUT_STRUCT InputStruct;
#endif