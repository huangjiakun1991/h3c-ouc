/****************************************************************************
** Meta object code from reading C++ file 'Gh3c.h'
**
** Created: Fri Apr 20 14:15:14 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Gh3c.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gh3c.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gh3c[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,    6,    5,    5, 0x0a,
      62,    5,    5,    5, 0x0a,
      76,    5,    5,    5, 0x0a,
      84,    5,    5,    5, 0x0a,
      97,    5,    5,    5, 0x0a,
     105,    5,    5,    5, 0x0a,
     119,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Gh3c[] = {
    "Gh3c\0\0reason\0"
    "iconActivated(QSystemTrayIcon::ActivationReason)\0"
    "remember(int)\0login()\0disconnect()\0"
    "about()\0userchanged()\0showtime()\0"
};

const QMetaObject Gh3c::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Gh3c,
      qt_meta_data_Gh3c, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gh3c::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gh3c::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gh3c::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gh3c))
        return static_cast<void*>(const_cast< Gh3c*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Gh3c::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 1: remember((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: login(); break;
        case 3: disconnect(); break;
        case 4: about(); break;
        case 5: userchanged(); break;
        case 6: showtime(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
