/***************************************************************
 
 GLUI 2 - OpenGL User Interface Library 2
 Copyright 2011 Core S2 - See License.txt for details
 
 This source file is developed and maintained by:
 + Jeremy Bridon jbridon@cores2.com
 
***************************************************************/

#include "g2Slider.h"

g2Slider::g2Slider(g2Controller* Parent, g2Theme* MainTheme)
: g2Controller(Parent, MainTheme)
{
    // Allocate text and set initial position
    // Note that we are registereting to this button, not the root-parent
    Label = new g2Label(this, MainTheme);
    Label->SetPos(5, 5);
    Label->SetColor(0, 0, 0);
    Label->SetText("Undefined...");
}

const g2Label* g2Slider::GetLabel()
{
    // Return the label we are working on
    return Label;
}

void g2Slider::Render()
{
    // Draw something simple
    int pX, pY;
    GetPos(&pX, &pY);
    
    // Draw based on the current state
    if(GetDisabled())
        DrawComponent(pX, pY, g2Theme_Button_Disabled);
    else if(GetControllerState() == g2ControllerState_Pressed)
        DrawComponent(pX, pY, g2Theme_Button_Pressed);
    else
        DrawComponent(pX, pY, g2Theme_Button);
}

bool g2Slider::InController(int x, int y)
{
    // Current GUI position and size
    int pX, pY, width, height;
    GetPos(&pX, &pY);
    GetTheme()->GetComponentSize(g2Theme_Button, &width, &height);
    
    // Are we in it?
    if(x >= pX && x <= pX + width && y >= pY && y <= pY + height)
        return true;
    else
        return false;
}
