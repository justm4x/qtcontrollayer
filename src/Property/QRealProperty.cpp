#include "../../include/qtcontrollayer/QRealProperty.h"

namespace
{
    template <typename _Float> bool qSafeFuzzyCompare(_Float a, _Float b)
    {
        return (qFuzzyIsNull(a) && qFuzzyIsNull(b)) || qFuzzyCompare(a, b);
    }
}

QRealProperty::QRealProperty(const QString & name, const QString & displayName, qreal value, qreal minimum, qreal maximum, const QString & format, QObject * parent /*= 0*/)
    : QObjProperty(name, displayName, parent)
    , _normalizedValue(normalize(value, minimum, maximum))
    , _defaultValue(_normalizedValue)
    , _minimum(minimum)
    , _maximum(maximum)
    , _format(format)
{
    connect(this, &QRealProperty::normalizedValueChanged, this, &QObjProperty::changed);
    connect(this, &QRealProperty::normalizedValueChanged, this, &QRealProperty::valueChanged);
    connect(this, &QRealProperty::normalizedValueChanged, this, &QObjProperty::displayValueChanged);
    connect(this, &QRealProperty::formatChanged, this, &QObjProperty::displayValueChanged);
}

QRealProperty::~QRealProperty()
{

}

qreal QRealProperty::value() const
{
    return unnormalize(_normalizedValue, _minimum, _maximum);
}

void QRealProperty::setValue(qreal value)
{
    setNormalizedValue(normalize(value, _minimum, _maximum));
}

qreal QRealProperty::defaultValue() const
{
    return _defaultValue;
}

qreal QRealProperty::normalizedValue() const
{
    return _normalizedValue;
}

void QRealProperty::setNormalizedValue(qreal value)
{
    value = qBound(0.0, value, 1.0);
    if (qSafeFuzzyCompare(_normalizedValue, value) == false)
    {
        _normalizedValue = value;
        emit normalizedValueChanged();
    }
}

qreal QRealProperty::minimum() const
{
    return _minimum;
}

void QRealProperty::setMinimum(qreal minimum)
{
    if (qSafeFuzzyCompare(_minimum, minimum) == false)
    {
        _minimum = minimum;
        emit minimumChanged();
    }
}

qreal QRealProperty::maximum() const
{
    return _maximum;
}

void QRealProperty::setMaximum(qreal maximum)
{
    if (qSafeFuzzyCompare(_maximum, maximum))
    {
        _maximum = maximum;
        emit maximumChanged();
    }
}

QString QRealProperty::displayValue() const
{
    return QString::asprintf(_format.toUtf8().constData(), value());
}

QString QRealProperty::format() const
{
    return _format;
}

void QRealProperty::setFormat(const QString & format)
{
    if (_format != format)
    {
        _format = format;
        emit formatChanged();
    }
}

qreal QRealProperty::normalize(qreal value, qreal minimum, qreal maximum)
{
    return (value - minimum) / (maximum - minimum);
}

qreal QRealProperty::unnormalize(qreal normalizedValue, qreal minimum, qreal maximum)
{
    return minimum + (normalizedValue * (maximum - minimum));
}
