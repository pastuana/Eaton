//
// Created by pastu on 22.06.2023.
//

#ifndef EATON_OBSERVER_H
#define EATON_OBSERVER_H

#include <mutex>
#include <iostream>

class Observer{
public:
    Observer();
    void Update();

    unsigned int GetMessageCnt() const;
private:
    std::mutex mutex;
    unsigned int m_MessageCounter = 0;
};

#endif //EATON_OBSERVER_H
