#include "source_api.h"

#include <QDebug>

#include <QDateTime>

#include "../3rdparty/nzmqt/nzmqt.hpp"

using namespace nzmqt;


class ZPack: public QList<QByteArray> {
public:
    ZPack(int id, const QString &topic, const QString &data): QList<QByteArray>() {
        append(topic.toLocal8Bit());
        append(QString("%1|%2[string:%3]")
                .arg(id)
                .arg(QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODate))
                .arg(data).toLocal8Bit());

    }
    ZPack(int id, const QString &topic, int data): QList<QByteArray>() {
        append(topic.toLocal8Bit());
        append(QString("%1|%2[int:%3]")
                .arg(id)
                .arg(QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODate))
                .arg(data).toLocal8Bit());

    }
    ZPack(int id, const QString &topic, double data): QList<QByteArray>() {
        append(topic.toLocal8Bit());
        append(QString("%1|%2[double:%3]")
                .arg(id)
                .arg(QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODate))
                .arg(data).toLocal8Bit());

    }
    ZPack(int id, const QString &topic, bool data): QList<QByteArray>() {
        append(topic.toLocal8Bit());
        append(QString("%1|%2[bool:%3]")
                .arg(id)
                .arg(QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODate))
                .arg(data ? "true" : "false")
                .toLocal8Bit());

    }
};


using namespace simula;

using namespace dc;

quint64 SourceAPI::s_msg_counter = 0;

SourceAPI::SourceAPI(const QString &apiObjectName, const QString &bindTo)
    : QObject(nullptr)
    , _stringValue("")
    , _realValue(0.0)
    , _intValue(0)
    , _boolValue(false)
{

    qDebug() << "Instantiating DistributedCommunicationAPI Publisher";

    try {
        _zmq_context = createDefaultContext(this);
        _zmq_context->start();

        _zmq_socket = _zmq_context->createSocket(ZMQSocket::TYP_PUB, this);
        _zmq_socket->setObjectName(apiObjectName);
        _zmq_socket->bindTo(bindTo);

    } catch (std::exception& ex) {
        qWarning() << ex.what();
        exit(-1);
    }
}

SourceAPI::~SourceAPI()
{
    qDebug() << "DistributedCommunicationAPI::~DistributedCommunicationAPI()";
}

void SourceAPI::setStringValue(const QString &sv) {
    qDebug() << "DistributedCommunicationAPI recv string" << sv;
    if (sv != _stringValue) {
        _stringValue = sv;
        emit stringValueChanged();
    }
    publishString(sv);
}

QString SourceAPI::stringValue() const {
    return _stringValue;
}


void SourceAPI::setRealValue(double rv) {
    qDebug() << "DistributedCommunicationAPI recv double" << rv;
    if (rv != _realValue) {
        _realValue = rv;
        emit realValueChanged();
    }
    publishReal(rv);
}

double SourceAPI::realValue() const {
    return _realValue;
}


void SourceAPI::setIntValue(int iv) {
    qDebug() << "DistributedCommunicationAPI recv int" << iv;
    if (iv != _intValue) {
        _intValue = iv;
        emit intValueChanged();
    }
    publishInt(iv);
}

int SourceAPI::intValue() const {
    return _intValue;
}

void SourceAPI::setBoolValue(bool bv) {
    qDebug() << "DistributedCommunicationAPI recv bool" << bv;
    if (bv != _boolValue) {
        _boolValue = bv;
        emit boolValueChanged();
    }
    publishBool(bv);
}

bool SourceAPI::boolValue() const {
    return _boolValue;
}

int SourceAPI::doSomething(int i)
{
    qDebug() << "DistributedCommunicationAPI::doSomething()" << i;
    return i;
}

void SourceAPI::publishString(const QString &s)
{
    ZPack msg(++s_msg_counter, "tst", s);
    _zmq_socket->sendMessage(msg);
    qDebug() << "publishString" << msg;
}

void SourceAPI::publishInt(int i)
{
    ZPack msg(++s_msg_counter, "tst", i);
    _zmq_socket->sendMessage(msg);
    qDebug() << "publishString" << msg;
}

void SourceAPI::publishReal(double d)
{
    ZPack msg(++s_msg_counter, "tst", d);
    _zmq_socket->sendMessage(msg);
    qDebug() << "publishString" << msg;
}

void SourceAPI::publishBool(bool b)
{
    ZPack msg(++s_msg_counter, "tst", b);
    _zmq_socket->sendMessage(msg);
    qDebug() << "publishString" << msg;
}

