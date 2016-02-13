#include "../../include/qtcontrollayer/QIntProperty.h"

QIntProperty::QIntProperty(QObject * parent /*= 0*/)
    : QObjProperty(parent)
{
}

QIntProperty::QIntProperty(const QString & name, const QString & displayName, qint32 value, qint32 minimum, qint32 maximum, const QStringList & strings /*= QStringList()*/, QObject * parent /*= 0*/)
    : QObjProperty(name, displayName, parent)
    , _value(value)
    , _defaultValue(value)
    , _minimum(minimum)
    , _maximum(maximum)
    , _strings(strings)
{
    connect(this, &QIntProperty::valueChanged, this, &QObjProperty::changed);
    connect(this, &QIntProperty::valueChanged, this, &QIntProperty::displayValueChanged);
    connect(this, &QIntProperty::stringsChanged, this, &QIntProperty::displayValueChanged);
}

QIntProperty::~QIntProperty()
{

}

qint32 QIntProperty::value() const
{
    return _value;
}

void QIntProperty::setValue(qint32 value)
{
    if (_value != value)
    {
        _value = value;
        emit valueChanged();
    }
}

qint32 QIntProperty::defaultValue() const
{
    return _defaultValue;
}

qint32 QIntProperty::minimum() const
{
    return _minimum;
}

void QIntProperty::setMinimum(qint32 minimum)
{
    if (_minimum != minimum)
    {
        _minimum = minimum;
        emit minimumChanged();
    }
}

qint32 QIntProperty::maximum() const
{
    return _maximum;
}

void QIntProperty::setMaximum(qint32 maximum)
{
    if (_maximum != maximum)
    {
        _maximum = maximum;
        emit maximumChanged();
    }
}

QStringList QIntProperty::strings() const
{
    return _strings;
}

QString QIntProperty::displayValue() const
{
    return _strings.isEmpty() ? QString::number(_value) : _strings[_value];
}
