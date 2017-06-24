#ifndef DIALOGUEBOX_H
#define DIALOGUEBOX_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Input/Input.hpp"
#include "../FatherDrawable.hpp"

class DialogueBox: public sf::RectangleShape, public InputListener, public FatherDrawable {
private:
    DialogueBox();
    static DialogueBox *s_instance;
    sf::Font font;
    sf::Text text;
    std::string queue;
    void setString(std::string);
    void hide();
public:
    ~DialogueBox();
    static DialogueBox *instance() {
        if (!s_instance) {
            s_instance = new DialogueBox;
        }
        return s_instance;
    }
    void show(std::string string);

    void upPressed() override;
    void downPressed() override;
    void leftPressed() override;
    void rightPressed() override;

    void upReleased() override;
    void downReleased() override;
    void leftReleased() override;
    void rightReleased() override;
    
    void up() override;
    void down() override;
    void left() override;
    void right() override;

    void enterPressed() override;

    void drawToWindow(sf::RenderWindow &windowRef) override;
};
#endif