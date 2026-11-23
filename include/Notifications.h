
#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <iostream>
#include <string>

using namespace std;

class NotificationService {
public:
    virtual void sendNotification(string message) = 0;

    virtual ~NotificationService() {}
};

class EmailNotification : public NotificationService {
public:
    void sendNotification(string message) override {
        cout << "[EMAIL] " << message << endl;
    }
};

class SMSNotification : public NotificationService {
public:
    void sendNotification(string message) override {
        cout << "[SMS] " << message << endl;
    }
};


class PushNotification : public NotificationService {
public:
    void sendNotification(string message) override {
        cout << "[PUSH] " << message << endl;
    }
};

#endif







