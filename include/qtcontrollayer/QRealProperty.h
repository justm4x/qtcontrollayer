#ifndef QRealProperty_h__
#define QRealProperty_h__

#include "QObjProperty.h"

class QRealProperty : public QObjProperty
{
    Q_OBJECT
    Q_PROPERTY(qreal value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(qreal defaultValue READ defaultValue NOTIFY defaultValueChanged)
    Q_PROPERTY(qreal normalizedValue READ normalizedValue WRITE setNormalizedValue NOTIFY normalizedValueChanged)
    Q_PROPERTY(qreal minimum READ minimum WRITE setMinimum NOTIFY minimumChanged)
    Q_PROPERTY(qreal maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
    Q_PROPERTY(QString format READ format WRITE setFormat NOTIFY formatChanged)
public:
    explicit QRealProperty(const QString & name, const QString & displayName, qreal value, qreal minimum, qreal maximum, const QString & format, QObject * parent = 0);
    virtual ~QRealProperty();

signals:
    void valueChanged();
    void defaultValueChanged();
    void normalizedValueChanged();
    void minimumChanged();
    void maximumChanged();
    void formatChanged();

public:
    qreal value() const;
    void setValue(qreal value);

    qreal defaultValue() const;

    qreal normalizedValue() const;
    void setNormalizedValue(qreal value);

    qreal minimum() const;
    void setMinimum(qreal minimum);

    qreal maximum() const;
    void setMaximum(qreal maximum);

    QString format() const;
    void setFormat(const QString & format);

    virtual QString displayValue() const override;

private:
    static qreal normalize(qreal value, qreal minimum, qreal maximum);
    static qreal unnormalize(qreal normalizedValue, qreal minimum, qreal maximum);

private:
    qreal _normalizedValue;
    qreal _defaultValue;
    qreal _minimum;
    qreal _maximum;
    QString _format;
};
#endif // QRealProperty_h__