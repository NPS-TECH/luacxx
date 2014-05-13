#ifndef LUA_CXX_QOBJECTSLOT_HEADER
#define LUA_CXX_QOBJECTSLOT_HEADER

#include <QObject>
#include <QMetaObject>
#include <QMetaMethod>
#include <memory>
#include <unordered_set>

#include "qobject.hpp"

namespace lua {

class QObjectSlot : public QObject
{
    QMetaMethod _signal;
    lua::reference _slot;
public:
    QObjectSlot(QObject* const parent, const QMetaMethod& signal, const lua::reference& slot);

    int qt_metacall(QMetaObject::Call call, int id, void **arguments);

    virtual ~QObjectSlot();

    static void disconnect(QObjectSlot* const slot);
    static void connect(QObjectSlot* const slot);
};

} // namespace lua

#endif // LUA_CXX_QOBJECTSLOT_HEADER