#include "../DialogueBox/DialogueBox.hpp"
#include "../ScreenManager/ScreenManager.hpp"
DialogueBox *DialogueBox::s_instance = nullptr;
DialogueBox *window_ref = nullptr;

static const bool debug = false;
static const int padding = 32;
static const int boxHeight = ScreenHeight*.33333;

DialogueBox::DialogueBox() {
    this->setPosition(0,ScreenHeight-boxHeight);
    this->setSize(sf::Vector2f(ScreenWidth,boxHeight));
    this->setFillColor(sf::Color::Black);

    this->font.loadFromFile("Fonts/futrfw.ttf");
    
    this->text.setFont(font);
    this->text.setCharacterSize(boxHeight/8);
    this->text.setStyle(sf::Text::Regular);
    this->text.setOutlineColor(sf::Color::Blue);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(sf::Vector2f(padding,this->getPosition().y+padding));
}

DialogueBox::~DialogueBox() {

}

void DialogueBox::show(std::string string) {
    this->setString(string);
    this->text.setFillColor(sf::Color::White);
    this->setFillColor(sf::Color::Black);
}

void DialogueBox::hide() {
    this->text.setFillColor(sf::Color::Transparent);
    this->setFillColor(sf::Color::Transparent);
}

void DialogueBox::setString(std::string newString) {
    this->text.setString(newString);
    //std::string str = this->text.getString();

    // loop through the entire new string
    for (std::string::size_type i = 0; i < newString.size(); ++i) {
        // get the xy position of the character at index i
        sf::Vector2f v2 = this->text.findCharacterPos(i);
        // if the character is past the screen padding
        if (v2.y > ScreenHeight-padding) {
            std::string newPage = newString.substr(i, newString.size()-i);
            newString.erase(i, newString.size()-i);
            this->nextPage = newPage;
            break;
        } else {
            this->nextPage = "";
        }
        if (v2.x > ScreenWidth-padding) {
            for (std::string::size_type j = i; j > 0; j--) {
                if (newString[j] == ' ') {
                    newString[j] = '\n';
                    break;
                }
            }
            this->text.setString(newString);
        }
    }
    std::cout << "nextPage count " << this->nextPage.size() << std::endl;
}

void DialogueBox::upPressed() {
    if (debug) {
        std::cout << "DialogueBox::upPressed" << std::endl;
    }
}
void DialogueBox::downPressed() {
    if (debug) {
        std::cout << "DialogueBox::downPressed" << std::endl;
    }
    if (this->nextPage.size() > 1) {
        this->currentPage++;
        this->setString(this->nextPage);
    } else {
        //this->setString("");
        this->hide();
    }
}
void DialogueBox::leftPressed() {
    if (debug) {
        std::cout << "DialogueBox::leftPressed" << std::endl;
    }
}
void DialogueBox::rightPressed() {
    if (debug) {
        std::cout << "DialogueBox::rightPressed" << std::endl;
    }
}

void DialogueBox::upReleased() {
    if (debug) {
        std::cout << "DialogueBox::upReleased" << std::endl;
    }
}
void DialogueBox::downReleased() {
    if (debug) {
        std::cout << "DialogueBox::downReleased" << std::endl;
    }
}
void DialogueBox::leftReleased() {
    if (debug) {
        std::cout << "DialogueBox::leftReleased" << std::endl;
    }
}
void DialogueBox::rightReleased() {
    if (debug) {
        std::cout << "DialogueBox::rightReleased" << std::endl;
    }
}

void DialogueBox::up() {
    if (debug) {
        std::cout << "DialogueBox::up" << std::endl;
    }
}
void DialogueBox::down() {
    if (debug) {
        std::cout << "DialogueBox::down" << std::endl;
    }
}
void DialogueBox::left() {
    if (debug) {
        std::cout << "DialogueBox::left" << std::endl;
    }
}
void DialogueBox::right() {
    if (debug) {
        std::cout << "DialogueBox::right" << std::endl;
    }
}

void DialogueBox::enterPressed() {
    if (debug) {
        std::cout << "DialogueBox::enterPressed" << std::endl;
    }   
}

void DialogueBox::drawToWindow(sf::RenderWindow &window_ref) {
    window_ref.draw(*this);
    window_ref.draw(this->text);
}