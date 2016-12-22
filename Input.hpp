#ifndef INPUT_STRUCT_H
#define INPUT_STRUCT_H
struct INPUT_STRUCT {
        bool up;
        bool down;
        bool left;
        bool right;
        bool upPressed;
        bool downPressed;
        bool leftPressed;
        bool rightPressed;
        bool upReleased;
        bool downReleased;
        bool leftReleased;
        bool rightReleased;
    };
typedef INPUT_STRUCT InputStruct;
#endif