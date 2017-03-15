#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
extern const int ScreenWidth;
extern const int ScreenHeight;

class ScreenManager
{
private:
    static ScreenManager *s_instance;
    ScreenManager();
public:
    ~ScreenManager();
    static ScreenManager *instance() {
        if (!s_instance) {
            s_instance = new ScreenManager;
        }
        return s_instance;
    }
    // static int screenWidth() {
    //     return 1920;
    // }
    // static int screenHeight() {
    //     return 1080;
    // }
};
#endif