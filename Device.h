//
// Created by pastu on 22.06.2023.
//

#ifndef EATON_DEVICE_H
#define EATON_DEVICE_H

#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include <mutex>
#include "Observer.h"


class Device{
public:
    Device();
    ~Device();

    void AttachToObserver( Observer * observer);

    void DetachFromObserver( );

    void Activate();

    void Deactivate();

private:
    std::string m_deviceName;
    bool m_isActive;
    bool m_isAttached;
    Observer* m_observer;

    void Notify () const;

    void Computation( const unsigned int computationTime );

    std::string generateUniqueName(const std::string & baseName);
};

#endif //EATON_DEVICE_H
