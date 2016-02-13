#ifndef QIntProperty_h__
#define QIntProperty_h__

#include "QObjProperty.h"

class QIntProperty : public QObjProperty
{
    Q_OBJECT
    Q_PROPERTY(qint32 value READ value WRITE setValue NOTIFY valueChanged);
    Q_PROPERTY(qint32 defaultValue READ defaultValue NOTIFY defaultValueChanged);
    Q_PROPERTY(qint32 minimum READ minimum WRITE setMinimum NOTIFY minimumChanged);
    Q_PROPERTY(qint32 maximum READ maximum WRITE setMaximum NOTIFY maximumChanged);
    Q_PROPERTY(QStringList strings READ strings NOTIFY stringsChanged);
public:
    explicit QIntProperty(QObject * parent = 0);
    explicit QIntProperty(const QString & name, const QString & displayName, qint32 value, qint32 minimum, qint32 maximum, const QStringList & strings = QStringList(), QObject * parent = 0);
    virtual ~QIntProperty();

signals:
    void valueChanged();
    void defaultValueChanged();
    void minimumChanged();
    void maximumChanged();
    void stringsChanged();

public:
    qint32 value() const;
    void setValue(qint32 value);

    qint32 defaultValue() const;

    qint32 minimum() const;
    void setMinimum(qint32 minimum);

    qint32 maximum() const;
    void setMaximum(qint32 maximum);

    QStringList strings() const;

    virtual QString displayValue() const override;

private:
    qint32 _value;
    qint32 _defaultValue;
    qint32 _minimum;
    qint32 _maximum;
    QStringList _strings;
};
#endif // QIntProperty_h__