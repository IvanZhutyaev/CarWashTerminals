/****************************************************************************
** Meta object code from reading C++ file 'accountmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "accountmanager/accountmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accountmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14AccountManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto AccountManager::qt_create_metaobjectdata<qt_meta_tag_ZN14AccountManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AccountManager",
        "loggedInChanged",
        "",
        "currentBalanceChanged",
        "loginMessageChanged",
        "registrationMessageChanged",
        "showPersonalAccount",
        "hidePersonalAccount",
        "registrationStatus",
        "success",
        "message",
        "loginStatus",
        "networkStatusChanged",
        "isOnline",
        "registrationFailed",
        "registerUser",
        "phoneNumber",
        "password",
        "loginUser",
        "logoutUser",
        "checkNetworkStatus",
        "syncData",
        "updateBalance",
        "amount",
        "getTopUpHistory",
        "QVariantList",
        "isLoggedIn",
        "currentBalance",
        "loginMessage",
        "registrationMessage"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'loggedInChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentBalanceChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loginMessageChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'registrationMessageChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showPersonalAccount'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hidePersonalAccount'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'registrationStatus'
        QtMocHelpers::SignalData<void(bool, QString)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 9 }, { QMetaType::QString, 10 },
        }}),
        // Signal 'loginStatus'
        QtMocHelpers::SignalData<void(bool, QString)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 9 }, { QMetaType::QString, 10 },
        }}),
        // Signal 'networkStatusChanged'
        QtMocHelpers::SignalData<void(bool)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 13 },
        }}),
        // Signal 'registrationFailed'
        QtMocHelpers::SignalData<void(const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Slot 'registerUser'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 }, { QMetaType::QString, 17 },
        }}),
        // Slot 'loginUser'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 }, { QMetaType::QString, 17 },
        }}),
        // Slot 'logoutUser'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'checkNetworkStatus'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'syncData'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateBalance'
        QtMocHelpers::SlotData<void(int)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'getTopUpHistory'
        QtMocHelpers::SlotData<QVariantList()>(24, 2, QMC::AccessPublic, 0x80000000 | 25),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'isLoggedIn'
        QtMocHelpers::PropertyData<bool>(26, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'currentBalance'
        QtMocHelpers::PropertyData<QString>(27, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'loginMessage'
        QtMocHelpers::PropertyData<QString>(28, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'registrationMessage'
        QtMocHelpers::PropertyData<QString>(29, QMetaType::QString, QMC::DefaultPropertyFlags, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AccountManager, qt_meta_tag_ZN14AccountManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AccountManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14AccountManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14AccountManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14AccountManagerE_t>.metaTypes,
    nullptr
} };

void AccountManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AccountManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->loggedInChanged(); break;
        case 1: _t->currentBalanceChanged(); break;
        case 2: _t->loginMessageChanged(); break;
        case 3: _t->registrationMessageChanged(); break;
        case 4: _t->showPersonalAccount(); break;
        case 5: _t->hidePersonalAccount(); break;
        case 6: _t->registrationStatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->loginStatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->networkStatusChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->registrationFailed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->registerUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->loginUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: _t->logoutUser(); break;
        case 13: _t->checkNetworkStatus(); break;
        case 14: _t->syncData(); break;
        case 15: _t->updateBalance((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: { QVariantList _r = _t->getTopUpHistory();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)()>(_a, &AccountManager::loggedInChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)()>(_a, &AccountManager::currentBalanceChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)()>(_a, &AccountManager::loginMessageChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)()>(_a, &AccountManager::registrationMessageChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)()>(_a, &AccountManager::showPersonalAccount, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)()>(_a, &AccountManager::hidePersonalAccount, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)(bool , QString )>(_a, &AccountManager::registrationStatus, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)(bool , QString )>(_a, &AccountManager::loginStatus, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)(bool )>(_a, &AccountManager::networkStatusChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (AccountManager::*)(const QString & )>(_a, &AccountManager::registrationFailed, 9))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isLoggedIn(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->currentBalance(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->loginMessage(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->registrationMessage(); break;
        default: break;
        }
    }
}

const QMetaObject *AccountManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14AccountManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AccountManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AccountManager::loggedInChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AccountManager::currentBalanceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AccountManager::loginMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AccountManager::registrationMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AccountManager::showPersonalAccount()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AccountManager::hidePersonalAccount()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void AccountManager::registrationStatus(bool _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void AccountManager::loginStatus(bool _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2);
}

// SIGNAL 8
void AccountManager::networkStatusChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void AccountManager::registrationFailed(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}
QT_WARNING_POP
