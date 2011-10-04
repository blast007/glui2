/***************************************************************
 
 GLUI 2 - OpenGL User Interface Library 2
 Copyright 2011 Core S2 - See License.txt for details
 
 This source file is developed and maintained by:
 + Jeremy Bridon jbridon@cores2.com
 
 File: g2Slider.cpp/h
 Desc: Slider bar implementation. Note that the user must
 explicitly drag the button, and thus the "InController(...)"
 function only checks the drag button (which is internally
 rendered here, and not a derivative of g2Button).
 
***************************************************************/

// Inclusion guard
#ifndef __G2SLIDER_H__
#define __G2SLIDER_H__

#include "g2Controller.h"
#include "g2Label.h"

class g2Slider : public g2Controller
{
public:
    
    // Progress bar constructor
    g2Slider(g2Controller* Parent, g2Theme* MainTheme);
    
    // Add a live variable; pass NULL (or leave blank) to disconect
    void SetLiveVariable(float* LiveValue = NULL);
    
    // Set the min / max bounds of the progress bar; defaults to [0.0, 1.0]
    void SetBounds(float Lower, float Upper);
    
    // Set the current progress of this progress bar; accepts
    // values from 0 to 1 (floats)
    void SetProgress(float Progress);
    
    // Return the current progress
    float GetProgress();
    
    // Set the width of the button in pixels
    void SetWidth(int Width);
    
protected:
    
    // Render
    void Render();
    
    // Keep moving the controller based on the user's dragging
    void MouseDrag(int x, int y);
    
    // Used when releasing a drag
    void MouseClick(g2MouseButton button, g2MouseClick state, int x, int y);
    
    // Get the mouse position; used for drag icon placement
    void MouseHover(int x, int y);
    
    // Define controller geometry
    bool InController(int x, int y);
    
private:
    
    // Min / max bounds
    float MinBound, MaxBound;
    
    // Current progress
    float Progress;
    
    // Actively dragging
    bool IsDragging;
    
    // Width of the controller
    int Width;
    
    // Live value
    float* LiveValue;
    
};

// End of inclusion guard
#endif
