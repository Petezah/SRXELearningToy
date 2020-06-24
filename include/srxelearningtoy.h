
#ifndef _SRXELEARNINGTOY_H_
#define _SRXELEARNINGTOY_H_

class IDisplay;

class SRXELearningToy
{
public:
    SRXELearningToy(IDisplay* pDisplay);
    void Run();

private:
    IDisplay* _display;
};

#endif
