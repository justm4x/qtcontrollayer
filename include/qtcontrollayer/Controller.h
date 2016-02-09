#ifndef Controller_h__
#define Controller_h__

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(const QString & name, QObject * parent = 0);
    virtual ~Controller();

private slots:
    virtual void onPropertyChanged() {};

public:
    template <typename T, typename ... Args>
        T * registerProperty(const QString & name, const QString & displayName, Args... args)
    {
        T * property = new T(name, displayName, args...);
        connect(property, &QObjProperty::changed, this, &Controller::onPropertyChanged);
        return property;
    }
};
#endif // Controller_h__