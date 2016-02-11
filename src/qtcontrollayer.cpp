#include "../include/qtcontrollayer/qtcontrollayer.h"

#include <QtQml>

#include "../include/qtcontrollayer/Controller.h"
#include "../include/qtcontrollayer/QObjProperty.h"
#include "../include/qtcontrollayer/QIntProperty.h"

void qtcontrollayer::registerTypes()
{
    qmlRegisterUncreatableType<Controller>("QtControlLayer", 1, 0, "Controller", "Can not be created from Qml");
    qmlRegisterType<QObjProperty>("QtControlLayer", 1, 0, "QObjProperty");
    qmlRegisterType<QIntProperty>("QtControlLayer", 1, 0, "QIntProperty");
}