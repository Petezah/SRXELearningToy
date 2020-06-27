
#ifndef _SRXELEARNINGTOY_H_
#define _SRXELEARNINGTOY_H_

#include <memory>

class IDisplay;
struct GuiContainer;

class SRXELearningToy
{
    friend std::unique_ptr<SRXELearningToy> std::make_unique<SRXELearningToy>();

public:
    static SRXELearningToy* Instance();
    void Initialize(IDisplay* pDisplay);
    void Run();

private:
    SRXELearningToy() = default;
    static std::unique_ptr<SRXELearningToy> s_instance;
    IDisplay* _display;
    std::unique_ptr<GuiContainer> _gui;
};

#endif
