/****************************************************************************
** Meta object code from reading C++ file 'engine.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IPS4MCO/engine/engine.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engine.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6EngineE_t {};
} // unnamed namespace

template <> constexpr inline auto Engine::qt_create_metaobjectdata<qt_meta_tag_ZN6EngineE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Engine",
        "showInitialization",
        "",
        "state",
        "text",
        "showError",
        "error",
        "showWaiting",
        "showSession",
        "showQR",
        "showCollection",
        "showWallet",
        "showPaymentLoading",
        "showPaymentError",
        "setQR",
        "qr_string",
        "setPressedButtons",
        "buttons",
        "setUIConfig",
        "config",
        "balanceChanged",
        "balance",
        "timeChanged",
        "time",
        "pauseTimeChanged",
        "pause_time",
        "discountfixChanged",
        "discountfix",
        "discountaccChanged",
        "discountacc",
        "depositChanged",
        "deposit",
        "dateChanged",
        "date",
        "colbalanceChanged",
        "colbalance",
        "colcashChanged",
        "colcash",
        "isPauseFreeChanged",
        "ispause_free",
        "loggedInChanged",
        "currentBalanceChanged",
        "loginMessageChanged",
        "registrationMessageChanged",
        "cppSetButtons",
        "cppClerButtonStateQr",
        "cppClerButtonStateWallet",
        "cppSendPayment",
        "value",
        "back_screen",
        "setBalance",
        "setTime",
        "setPauseTime",
        "setDiscountfix",
        "dicountfix",
        "setDiscountacc",
        "dicountacc",
        "setDeposit",
        "setDate",
        "setColbalance",
        "setColcash",
        "setIsPauseFree",
        "showPersonalAccount",
        "hidePersonalAccount",
        "tEvent",
        "delayTimerSlot",
        "reconnectTimerSlot",
        "initTimerSlot",
        "paymentBankHandler",
        "showSessionLocal",
        "updateBalance",
        "amount",
        "accountManager",
        "AccountManager*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'showInitialization'
        QtMocHelpers::SignalData<void(int, QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'showInitialization'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'showError'
        QtMocHelpers::SignalData<void(int, QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'showError'
        QtMocHelpers::SignalData<void(int)>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Signal 'showWaiting'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showSession'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'showQR'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showCollection'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showWallet'
        QtMocHelpers::SignalData<void(int)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'showPaymentLoading'
        QtMocHelpers::SignalData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'showPaymentError'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'setQR'
        QtMocHelpers::SignalData<void(QString)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 15 },
        }}),
        // Signal 'setPressedButtons'
        QtMocHelpers::SignalData<void(int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Signal 'setUIConfig'
        QtMocHelpers::SignalData<void(QJsonObject)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonObject, 19 },
        }}),
        // Signal 'balanceChanged'
        QtMocHelpers::SignalData<void(int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 21 },
        }}),
        // Signal 'timeChanged'
        QtMocHelpers::SignalData<void(QString)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 23 },
        }}),
        // Signal 'pauseTimeChanged'
        QtMocHelpers::SignalData<void(QString)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Signal 'discountfixChanged'
        QtMocHelpers::SignalData<void(int)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 27 },
        }}),
        // Signal 'discountaccChanged'
        QtMocHelpers::SignalData<void(int)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 29 },
        }}),
        // Signal 'depositChanged'
        QtMocHelpers::SignalData<void(int)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 31 },
        }}),
        // Signal 'dateChanged'
        QtMocHelpers::SignalData<void(QString)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 33 },
        }}),
        // Signal 'colbalanceChanged'
        QtMocHelpers::SignalData<void(int)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 35 },
        }}),
        // Signal 'colcashChanged'
        QtMocHelpers::SignalData<void(int)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 37 },
        }}),
        // Signal 'isPauseFreeChanged'
        QtMocHelpers::SignalData<void(bool)>(38, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 39 },
        }}),
        // Signal 'loggedInChanged'
        QtMocHelpers::SignalData<void()>(40, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentBalanceChanged'
        QtMocHelpers::SignalData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loginMessageChanged'
        QtMocHelpers::SignalData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'registrationMessageChanged'
        QtMocHelpers::SignalData<void()>(43, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'cppSetButtons'
        QtMocHelpers::SlotData<void(int)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'cppClerButtonStateQr'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'cppClerButtonStateWallet'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'cppSendPayment'
        QtMocHelpers::SlotData<void(int, int)>(47, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 48 }, { QMetaType::Int, 49 },
        }}),
        // Slot 'setBalance'
        QtMocHelpers::SlotData<void(int)>(50, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 21 },
        }}),
        // Slot 'setTime'
        QtMocHelpers::SlotData<void(QString)>(51, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 23 },
        }}),
        // Slot 'setPauseTime'
        QtMocHelpers::SlotData<void(QString)>(52, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Slot 'setDiscountfix'
        QtMocHelpers::SlotData<void(int)>(53, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 54 },
        }}),
        // Slot 'setDiscountacc'
        QtMocHelpers::SlotData<void(int)>(55, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 56 },
        }}),
        // Slot 'setDeposit'
        QtMocHelpers::SlotData<void(int)>(57, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 31 },
        }}),
        // Slot 'setDate'
        QtMocHelpers::SlotData<void(QString)>(58, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 33 },
        }}),
        // Slot 'setColbalance'
        QtMocHelpers::SlotData<void(int)>(59, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 35 },
        }}),
        // Slot 'setColcash'
        QtMocHelpers::SlotData<void(int)>(60, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 37 },
        }}),
        // Slot 'setIsPauseFree'
        QtMocHelpers::SlotData<void(bool)>(61, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 39 },
        }}),
        // Slot 'showPersonalAccount'
        QtMocHelpers::SlotData<void()>(62, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'hidePersonalAccount'
        QtMocHelpers::SlotData<void()>(63, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'tEvent'
        QtMocHelpers::SlotData<void()>(64, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'delayTimerSlot'
        QtMocHelpers::SlotData<void()>(65, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'reconnectTimerSlot'
        QtMocHelpers::SlotData<void()>(66, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'initTimerSlot'
        QtMocHelpers::SlotData<void()>(67, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'paymentBankHandler'
        QtMocHelpers::SlotData<void(int)>(68, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'showSessionLocal'
        QtMocHelpers::SlotData<void()>(69, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'updateBalance'
        QtMocHelpers::MethodData<void(int)>(70, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 71 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'balance'
        QtMocHelpers::PropertyData<int>(21, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 14),
        // property 'time'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'pause_time'
        QtMocHelpers::PropertyData<QString>(25, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable, 16),
        // property 'discountfix'
        QtMocHelpers::PropertyData<int>(27, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 17),
        // property 'discountacc'
        QtMocHelpers::PropertyData<int>(29, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 18),
        // property 'deposit'
        QtMocHelpers::PropertyData<int>(31, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 19),
        // property 'date'
        QtMocHelpers::PropertyData<QString>(33, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 20),
        // property 'colbalance'
        QtMocHelpers::PropertyData<int>(35, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 21),
        // property 'colcash'
        QtMocHelpers::PropertyData<int>(37, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 22),
        // property 'ispause_free'
        QtMocHelpers::PropertyData<bool>(39, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable, 23),
        // property 'accountManager'
        QtMocHelpers::PropertyData<AccountManager*>(72, 0x80000000 | 73, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Engine, qt_meta_tag_ZN6EngineE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Engine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6EngineE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6EngineE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6EngineE_t>.metaTypes,
    nullptr
} };

void Engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Engine *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->showInitialization((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->showInitialization((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->showError((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->showError((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->showWaiting(); break;
        case 5: _t->showSession((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->showQR(); break;
        case 7: _t->showCollection(); break;
        case 8: _t->showWallet((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->showPaymentLoading((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->showPaymentError(); break;
        case 11: _t->setQR((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->setPressedButtons((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->setUIConfig((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 14: _t->balanceChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->timeChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->pauseTimeChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->discountfixChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->discountaccChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->depositChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->dateChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->colbalanceChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->colcashChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->isPauseFreeChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 24: _t->loggedInChanged(); break;
        case 25: _t->currentBalanceChanged(); break;
        case 26: _t->loginMessageChanged(); break;
        case 27: _t->registrationMessageChanged(); break;
        case 28: _t->cppSetButtons((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->cppClerButtonStateQr(); break;
        case 30: _t->cppClerButtonStateWallet(); break;
        case 31: _t->cppSendPayment((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 32: _t->setBalance((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->setTime((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 34: _t->setPauseTime((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->setDiscountfix((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 36: _t->setDiscountacc((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 37: _t->setDeposit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 38: _t->setDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->setColbalance((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 40: _t->setColcash((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 41: _t->setIsPauseFree((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 42: _t->showPersonalAccount(); break;
        case 43: _t->hidePersonalAccount(); break;
        case 44: _t->tEvent(); break;
        case 45: _t->delayTimerSlot(); break;
        case 46: _t->reconnectTimerSlot(); break;
        case 47: _t->initTimerSlot(); break;
        case 48: _t->paymentBankHandler((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 49: _t->showSessionLocal(); break;
        case 50: _t->updateBalance((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int , QString )>(_a, &Engine::showInitialization, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int , QString )>(_a, &Engine::showError, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)()>(_a, &Engine::showWaiting, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::showSession, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)()>(_a, &Engine::showQR, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)()>(_a, &Engine::showCollection, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::showWallet, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::showPaymentLoading, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)()>(_a, &Engine::showPaymentError, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(QString )>(_a, &Engine::setQR, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::setPressedButtons, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(QJsonObject )>(_a, &Engine::setUIConfig, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::balanceChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(QString )>(_a, &Engine::timeChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(QString )>(_a, &Engine::pauseTimeChanged, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::discountfixChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::discountaccChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::depositChanged, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(QString )>(_a, &Engine::dateChanged, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::colbalanceChanged, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(int )>(_a, &Engine::colcashChanged, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)(bool )>(_a, &Engine::isPauseFreeChanged, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)()>(_a, &Engine::loggedInChanged, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)()>(_a, &Engine::currentBalanceChanged, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)()>(_a, &Engine::loginMessageChanged, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (Engine::*)()>(_a, &Engine::registrationMessageChanged, 27))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountManager* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->balance(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->time(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->pause_time(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->discountfix(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->discountacc(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->deposit(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->date(); break;
        case 7: *reinterpret_cast<int*>(_v) = _t->colbalance(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->colcash(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->ispause_free(); break;
        case 10: *reinterpret_cast<AccountManager**>(_v) = _t->accountManager(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBalance(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setTime(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setPauseTime(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setDiscountfix(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setDiscountacc(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setDeposit(*reinterpret_cast<int*>(_v)); break;
        case 6: _t->setDate(*reinterpret_cast<QString*>(_v)); break;
        case 7: _t->setColbalance(*reinterpret_cast<int*>(_v)); break;
        case 8: _t->setColcash(*reinterpret_cast<int*>(_v)); break;
        case 9: _t->setIsPauseFree(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Engine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Engine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6EngineE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Engine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 51)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 51;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Engine::showInitialization(int _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 2
void Engine::showError(int _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 4
void Engine::showWaiting()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Engine::showSession(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void Engine::showQR()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Engine::showCollection()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Engine::showWallet(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void Engine::showPaymentLoading(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void Engine::showPaymentError()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Engine::setQR(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void Engine::setPressedButtons(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void Engine::setUIConfig(QJsonObject _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void Engine::balanceChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}

// SIGNAL 15
void Engine::timeChanged(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void Engine::pauseTimeChanged(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}

// SIGNAL 17
void Engine::discountfixChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void Engine::discountaccChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1);
}

// SIGNAL 19
void Engine::depositChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1);
}

// SIGNAL 20
void Engine::dateChanged(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 20, nullptr, _t1);
}

// SIGNAL 21
void Engine::colbalanceChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 21, nullptr, _t1);
}

// SIGNAL 22
void Engine::colcashChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 22, nullptr, _t1);
}

// SIGNAL 23
void Engine::isPauseFreeChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 23, nullptr, _t1);
}

// SIGNAL 24
void Engine::loggedInChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void Engine::currentBalanceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void Engine::loginMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void Engine::registrationMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}
QT_WARNING_POP
