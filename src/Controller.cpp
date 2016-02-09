#include "../include/qtcontrollayer/Controller.h"

Controller::Controller(const QString & name, QObject * parent /*= 0*/)
    : QObject(parent)
{
    setObjectName(name);
}

Controller::~Controller()
{
}

