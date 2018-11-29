#ifndef Controller_h__
#define Controller_h__

#include <QObject>
#include "QObjProperty.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(const QString & name, QObject * parent = nullptr);
    virtual ~Controller();

private slots:
    virtual void onPropertyChanged() {}

public:
    void registerController(Controller * controller);

    template <typename T, typename ... Args>
        T * createProperty(const QString & name, const QString & displayName, Args... args)
    {
        T * property = new T(name, displayName, args...);
        property->setParent(this);
        connect(property, &QObjProperty::changed, this, &Controller::onPropertyChanged);
        return property;
    }

    Q_INVOKABLE QObjProperty * getProperty(const QString & path);
};
#endif // Controller_h__
