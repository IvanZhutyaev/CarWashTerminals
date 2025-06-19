/****************************************************************************
** Meta object code from reading C++ file 'QtQrCodeQuickItem.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt-qrcode/quickitem/QtQrCodeQuickItem.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtQrCodeQuickItem.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QtQrCodeQuickItemE_t {};
} // unnamed namespace

template <> constexpr inline auto QtQrCodeQuickItem::qt_create_metaobjectdata<qt_meta_tag_ZN17QtQrCodeQuickItemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QtQrCodeQuickItem",
        "dataChanged",
        "",
        "data",
        "marginChanged",
        "margin",
        "backgroundChanged",
        "background",
        "foregroundChanged",
        "foreground"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dataChanged'
        QtMocHelpers::SignalData<void(const QByteArray &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 3 },
        }}),
        // Signal 'marginChanged'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Signal 'backgroundChanged'
        QtMocHelpers::SignalData<void(const QBrush &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QBrush, 7 },
        }}),
        // Signal 'foregroundChanged'
        QtMocHelpers::SignalData<void(const QBrush &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QBrush, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'data'
        QtMocHelpers::PropertyData<QByteArray>(3, QMetaType::QByteArray, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'margin'
        QtMocHelpers::PropertyData<float>(5, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'background'
        QtMocHelpers::PropertyData<QColor>(7, QMetaType::QColor, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'foreground'
        QtMocHelpers::PropertyData<QColor>(9, QMetaType::QColor, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QtQrCodeQuickItem, qt_meta_tag_ZN17QtQrCodeQuickItemE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QtQrCodeQuickItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QtQrCodeQuickItemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QtQrCodeQuickItemE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QtQrCodeQuickItemE_t>.metaTypes,
    nullptr
} };

void QtQrCodeQuickItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QtQrCodeQuickItem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dataChanged((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->marginChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->backgroundChanged((*reinterpret_cast< std::add_pointer_t<QBrush>>(_a[1]))); break;
        case 3: _t->foregroundChanged((*reinterpret_cast< std::add_pointer_t<QBrush>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QtQrCodeQuickItem::*)(const QByteArray & )>(_a, &QtQrCodeQuickItem::dataChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QtQrCodeQuickItem::*)(int )>(_a, &QtQrCodeQuickItem::marginChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QtQrCodeQuickItem::*)(const QBrush & )>(_a, &QtQrCodeQuickItem::backgroundChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QtQrCodeQuickItem::*)(const QBrush & )>(_a, &QtQrCodeQuickItem::foregroundChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QByteArray*>(_v) = _t->data(); break;
        case 1: *reinterpret_cast<float*>(_v) = _t->margin(); break;
        case 2: *reinterpret_cast<QColor*>(_v) = _t->background(); break;
        case 3: *reinterpret_cast<QColor*>(_v) = _t->foreground(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setData(*reinterpret_cast<QByteArray*>(_v)); break;
        case 1: _t->setMargin(*reinterpret_cast<float*>(_v)); break;
        case 2: _t->setBackground(*reinterpret_cast<QColor*>(_v)); break;
        case 3: _t->setForeground(*reinterpret_cast<QColor*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QtQrCodeQuickItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtQrCodeQuickItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QtQrCodeQuickItemE_t>.strings))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int QtQrCodeQuickItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
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
void QtQrCodeQuickItem::dataChanged(const QByteArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QtQrCodeQuickItem::marginChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QtQrCodeQuickItem::backgroundChanged(const QBrush & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QtQrCodeQuickItem::foregroundChanged(const QBrush & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
