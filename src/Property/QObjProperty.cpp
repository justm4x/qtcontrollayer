#include "../../include/qtcontrollayer/QObjProperty.h"

QObjProperty::QObjProperty(QObject * parent /*= 0*/)
    : QObject(parent)
{
    Q_ASSERT(false && "Should not be called");
}

QObjProperty::QObjProperty(const QString & name, const QString & displayName, QObject * parent /*= 0*/)
    : QObject(parent)
    , _enabled(true)
    , _displayName(displayName)
{
    setObjectName(name);
}

QObjProperty::~QObjProperty()
{

}

bool QObjProperty::enabled() const
{
    return _enabled;
}

void QObjProperty::setEnabled(bool enabled)
{
    if (_enabled != enabled)
    {
        _enabled = enabled;
        emit enabledChanged();
    }
}

QString QObjProperty::displayName() const
{
    return _displayName;
}

QString QObjProperty::displayValue() const
{
    return "[QObjProperty]: " + _displayName;
}

