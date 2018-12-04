#ifndef QSTRING_PROPERTY_H
#define QSTRING_PROPERTY_H

#include "QObjProperty.h"

class QStringProperty : public QObjProperty
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit QStringProperty(QObject *parent = nullptr);
    explicit QStringProperty(const QString &name, const QString &displayName, QObject *parent = nullptr);

signals:
    void valueChanged();

public:
    QString value() const;
    void setValue(const QString &value);

private:
    QString _value;
};

#endif // QSTRING_PROPERTY_H__
