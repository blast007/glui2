/***************************************************************
 
 GLUI 2 - OpenGL User Interface Library 2
 Copyright 2011 Core S2 - See License.txt for details
 
 This source file is developed and maintained by:
 + Jeremy Bridon jbridon@cores2.com
 
 File: g2Dialog.cpp/h
 Desc: A wrapper for the host operating-system's generic dialog
 boxes. For Windows we use "MessageBox(...)", for OSX we use
 "CreateStandardAlert(...)", but for Linux we just use the
 command line (because who knows which GUI they are on?). Note
 that we are opening a Modal that may or may not halt the
 calling thread (can't get unified behavior for now) and may
 or may not act as a modal vs. standard window.
 
***************************************************************/

// Inclusion guard
#ifndef __G2DIALOG_H__
#define __G2DIALOG_H__

#include "g2Utilities.h"

// The enumeration of dialog types
enum g2DialogType
{
    g2DialogType_Open = 0,
    g2DialogType_Save,
    g2DialogType_Notification,
};

// Define the cross-platform responses
enum g2DialogResult
{
    g2DialogResult_OK,
    g2DialogResult_Cancel,
};

class g2Dialog
{
public:
    
    // Dialog constructor creates either an open or a save dialog
    __g2EXPORT g2Dialog(g2DialogType Type, const char* Message);
    
    // Destructor explicitly takes down any open modals
    __g2EXPORT ~g2Dialog();
    
    // Show the dialog
    __g2EXPORT void Show();
    
    // The user's choice is given; if the result is a save
    // or open event, and the given result reference pointer is not null
    // then the given pointer is allocated a buffer of the user's content
    // and must be deleted explicitly by the user
    __g2EXPORT g2DialogResult GetInput(char** result = NULL);
    
private:
    
    // Dialog type
    g2DialogType Type;
    
    // User's choice
    g2DialogResult Selection;
    
    // Maximum input/output/message length
    static const int MaxBufferLength = 1024;
    
    // Message buffer
    char MessageBuffer[MaxBufferLength];
    
    // Result (user input) buffer
    char ResultBuffer[MaxBufferLength];
};

// End of inclusion guard
#endif
