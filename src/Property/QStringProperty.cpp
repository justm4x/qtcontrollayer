#include "../../include/qtcontrollayer/QStringProperty.h"

QStringProperty::QStringProperty(QObject *parent /*= nullptr*/)
    : QObjProperty(parent)
{
}

QStringProperty::QStringProperty(const QString &name, const QString &displayName, QObject * parent /*= nullptr*/)
    : QObjProperty(name, displayName, parent)
{
    connect(this, &QStringProperty::valueChanged, this, &QObjProperty::changed);
    connect(this, &QStringProperty::valueChanged, this, &QStringProperty::displayValueChanged);
}

QString QStringProperty::value() const
{
    return _value;
}

void QStringProperty::setValue(const QString &value)
{
    if (_value != value)
    {
        _value = value;
        emit valueChanged();
    }
}
