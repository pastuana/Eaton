//
// Created by pastu on 27.06.2023.
//
#include "Device.h"

Device::Device()
{
    m_deviceName = generateUniqueName("Device");
    m_isActive = false;
}

Device::~Device()
{
    delete m_observer;
}

void Device::AttachToObserver( Observer * observer)
{
    if (observer)
    {
        m_observer = observer;
        std::cout << m_deviceName << " is attached to observer" << std::endl;
    }
}

void Device::DetachFromObserver( )
{
    if (m_isActive)
    {
        m_isActive = false;
    }
    m_observer = nullptr;
    std::cout << m_deviceName << " is detached from observer" << std::endl;
}

void Device::Activate()
{
    m_isActive = true;
    std::cout << "Device " << m_deviceName << " is Active" << std::endl;
    Computation(rand()%5 + 1);
}

void Device::Deactivate()
{
    m_isActive = false;

    std::cout << "Device " << m_deviceName << " is Deactived" << std::endl;
}

void Device::Notify () const
{
    if (m_observer)
    {
        std::cout << "Notify" << std::endl;
        m_observer->Update();
    }
}


void Device::Computation( const unsigned int computationTime )
{
    while (m_isActive)
    {
        std::cout << "Device " << m_deviceName << " starting computations in thread." << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(computationTime));
        Notify();

        std::cout << "Device " << m_deviceName << " completed computations in thread in "
             << computationTime << " seconds." << std::endl;

    }
}


std::string Device::generateUniqueName(const std::string & baseName)
{
    // static counter for index of unique name
    static int cnt = 0;
    return baseName + "_" + std::to_string(cnt++);
}

