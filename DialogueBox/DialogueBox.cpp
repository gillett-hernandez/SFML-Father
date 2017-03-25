#include "../DialogueBox/DialogueBox.hpp"
#include "../ScreenManager/ScreenManager.hpp"
DialogueBox *DialogueBox::s_instance = nullptr;
DialogueBox *window_ref = nullptr;

static const bool debug = false;
static const int padding = 4;
#define boxHeight ScreenManager::screenHeight()*.33333

DialogueBox::DialogueBox() {
    this->setPosition(0,ScreenManager::screenHeight()-boxHeight);
    this->setSize(sf::Vector2f(ScreenManager::screenWidth(),boxHeight));
    this->setFillColor(sf::Color::Black);
    // case sensitive
    this->font.loadFromFile("Fonts/FUTRFW.TTF");
    
    this->text.setFont(font);
    this->text.setCharacterSize(boxHeight/8);
    this->text.setStyle(sf::Text::Regular);
    this->text.setOutlineColor(sf::Color::Blue);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(sf::Vector2f(padding,
        this->getPosition().y+padding+(this->text.getCharacterSize()/8)));
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
    sf::Vector2f position = this->getPosition();
    sf::Vector2f size = this->getSize();
    auto bottom = position.y+size.y;
    auto right = position.x+size.x;
    // loop through the entire new string
    for (std::string::size_type i = 0; i < newString.size(); ++i) {
        // get the xy position of the character at index i
        sf::Vector2f v2 = this->text.findCharacterPos(i);
        // if the character is past the screen padding
        if (v2.x > right-padding) {
            //loop throuhg in reverse and find a white space character
            for (std::string::size_type j = i; j > 0; j--) {
                // replace the white space with a new line
                if (newString[j] == ' ') {
                    newString[j] = '\n';
                    // break out of the loop
                    break;
                }
            }
            // set the text string to the new string
            this->text.setString(newString);
        }
    }
    for (std::string::size_type i = 0; i < newString.size(); ++i) {
        sf::Vector2f v2 = this->text.findCharacterPos(i);
        // if the character is past the screen bottom
        if (v2.y > bottom-padding-this->text.getCharacterSize()) {
            // create the next page out of the string that is too far
            std::string newPage = newString.substr(i, newString.size()-i);
            // trim the extraneous characters from newString
            newString.erase(i, newString.size()-i);
            // set the member variable queue to newPage
            this->queue = newPage;
            // set the text to new string.
            this->text.setString(newString);
            // break out of the loop
            break;
        } else {
            // if there are no trailing characters, set member variable newPage to an empty string
            // this is so the dialoge box knows that it's rendered all of the text.
            this->queue = "";
        }
    }
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
    if (this->queue.size() > 1) {
        this->setString(this->queue);
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