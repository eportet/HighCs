// InputHandling.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef INPUTHANDLING_H
#define INPUTHANDLING_H

class InvalidInput
{
public:
    InvalidInput(const char* in_ptr): msg_ptr(in_ptr) {}
    const char* const msg_ptr;
private:
    InvalidInput();
};

#endif //
