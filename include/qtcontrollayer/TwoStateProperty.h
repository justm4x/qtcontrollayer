#include "QObjProperty.h"

class TwoStateProperty : public QObjProperty
{
    Q_OBJECT
    Q_PROPERTY(bool state READ state WRITE setState NOTIFY stateChanged);
public:
    explicit TwoStateProperty(QObject * parent = 0);
    explicit TwoStateProperty(const QString & name, const QString & displayName, bool state, const QStringList & strings, QObject * parent = 0);
    virtual ~TwoStateProperty();

public:
    bool state() const;
    void setState(bool state);

    virtual QString displayValue() const override;

signals:
    void stateChanged();

private:
    bool _state;
    bool _defaultState;
    QStringList _strings;
};