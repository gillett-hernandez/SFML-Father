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
    };
typedef INPUT_STRUCT InputStruct;
void clearInput(InputStruct &input) {
    input.upPressed = false;
        input.downPressed = false;
        input.leftPressed = false;
        input.rightPressed = false;

        input.upReleased = false;
        input.downReleased = false;
        input.leftReleased = false;
        input.rightReleased = false;
}
void logForInput(InputStruct &input) {
    if (input.upPressed) {
        std::cout << "upPressed" << std::endl;
    }
    if (input.leftPressed) {
        std::cout << "leftPressed" << std::endl;
    }
    if (input.downPressed) {
        std::cout << "downPressed" << std::endl;
    }
    if (input.rightPressed) {
        std::cout << "downPressed" << std::endl;
    }
    if (input.up) {
        std::cout << "up" << std::endl;
    }
    if (input.left) {
        std::cout << "left" << std::endl;
    }
    if (input.down) {
        std::cout << "down" << std::endl;
    }
    if (input.right) {
        std::cout << "right" << std::endl;
    }
    if (input.upReleased) {
        std::cout << "upReleased" << std::endl;
    }
    if (input.leftReleased) {
        std::cout << "leftReleased" << std::endl;
    }
    if (input.rightReleased) {
        std::cout << "rightReleased" << std::endl;
    }
    if (input.downReleased) {
        std::cout << "downReleased" << std::endl;
    }
}
#endif