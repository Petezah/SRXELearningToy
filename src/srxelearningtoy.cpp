
#include "idisplay.h"
#include "srxelearningtoy.h"

extern "C" {
#include "ugui.h"
}

#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 136

struct GuiContainer
{
    UG_GUI gui;
};

std::unique_ptr<SRXELearningToy> SRXELearningToy::s_instance;
SRXELearningToy* SRXELearningToy::Instance()
{
    if (SRXELearningToy::s_instance == nullptr)
    {
        SRXELearningToy::s_instance = std::make_unique<SRXELearningToy>();
    }
    return SRXELearningToy::s_instance.get();
}

void SRXELearningToy::Initialize(IDisplay* pDisplay)
{
    _display = pDisplay;
    _gui = std::make_unique<GuiContainer>();
    UG_Init(&_gui->gui, [](UG_S16 x, UG_S16 y, UG_COLOR c) {
        SRXELearningToy::Instance()->_display->SetPixel(x, y, c);
        }, SCREEN_WIDTH, SCREEN_HEIGHT);

    // TEST
    UG_FontSelect(&FONT_4X6);
    UG_SetForecolor(0xFF);
    UG_PutString(10, 10, (char*)"Hello, World!");
}

void SRXELearningToy::Run()
{

}
