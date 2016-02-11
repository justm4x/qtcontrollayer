#include "../include/qtcontrollayer/Controller.h"
#include "../include/qtcontrollayer/QObjProperty.h"

Controller::Controller(const QString & name, QObject * parent /*= 0*/)
    : QObject(parent)
{
    setObjectName(name);
}

Controller::~Controller()
{
}

QObjProperty * Controller::getProperty(const QString & path)
{
    QStringList stringList = path.split('/', QString::SkipEmptyParts);
    QObject * parent = this;
    for (int i = 0; i < stringList.count() - 1; ++i)
    {
        parent = parent->findChild<Controller *>(stringList[i], Qt::FindDirectChildrenOnly);
        if (parent == 0)
        {
            return 0;
        }
    }
    QObjProperty * p = parent->findChild<QObjProperty *>(stringList.last());
    return p;
}

void Controller::registerController(Controller * controller)
{
    controller->setParent(this);
}

