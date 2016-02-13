#include "../../include/qtcontrollayer/TwoStateProperty.h"

TwoStateProperty::TwoStateProperty(QObject * parent /*= 0*/)
    : QObjProperty(parent)
{

}

TwoStateProperty::TwoStateProperty(const QString & name, const QString & displayName, bool state, const QStringList & strings, QObject * parent /*= 0*/)
    : QObjProperty(name, displayName, parent)
    , _state(state)
    , _defaultState(state)
    , _strings(strings)
{
    connect(this, &TwoStateProperty::stateChanged, this, &TwoStateProperty::changed);
}

TwoStateProperty::~TwoStateProperty()
{
}

bool TwoStateProperty::state() const
{
    return _state;
}

void TwoStateProperty::setState(bool state)
{
    if (_state != state)
    {
        _state = state;
        emit stateChanged();
    }
}

QString TwoStateProperty::displayValue() const
{
    return _strings.isEmpty() ? "" : _strings[static_cast<int>(_state)];
}
