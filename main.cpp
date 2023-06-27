
#include <iostream>
#include "Observer.h"
#include "Device.h"

int main() {

    Device dev1;
    Device dev2;
    
    Observer * observer = new Observer();

    dev1.AttachToObserver(observer);
    dev2.AttachToObserver(observer);

    std::thread calculations_dev1([&dev1](){
        dev1.Activate();
    });

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(2));


    std::thread calculations_dev2([&dev2](){
        dev2.Activate();
    });

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(3));

    dev1.Deactivate();
    dev2.Deactivate();

    calculations_dev1.join();
    calculations_dev2.join();

    dev2.DetachFromObserver();
    dev1.DetachFromObserver();

    std::cout << std::endl << "Msg number is " << observer->GetMessageCnt() << std::endl;

    return EXIT_SUCCESS;
}

