#ifndef QObjProperty_h__
#define QObjProperty_h__

#include <QObject>

class QObjProperty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(QString displayName READ displayName NOTIFY displayNameChanged)
    Q_PROPERTY(QString displayValue READ displayValue NOTIFY displayValueChanged)
public:
    explicit QObjProperty(QObject * parent = 0);
    explicit QObjProperty(const QString & name, const QString & displayName, QObject * parent = 0);

signals:
    void changed();
    void enabledChanged();
    void displayNameChanged();
    void displayValueChanged();

public:
    bool enabled() const;
    void setEnabled(bool enabled);

    QString displayName() const;
    virtual QString displayValue() const = 0 {}

private:
    bool _enabled;
    QString _displayName;
};
#endif // QObjProperty_h__