//
// Created by pastu on 27.06.2023.
//
#include "Observer.h"
Observer::Observer() : m_MessageCounter (0)
{

};

void Observer::Update()
{
    std::lock_guard<std::mutex> lock(mutex);
    std::cout << "Observer received an update." << std::endl;
    m_MessageCounter++;
}

unsigned int Observer::GetMessageCnt() const
{
    return m_MessageCounter;
}

