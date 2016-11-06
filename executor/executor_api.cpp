#include "executor_api.h"

#include <QDebug>

#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include <QDateTime>

#include "../3rdparty/nzmqt/nzmqt.hpp"



using namespace nzmqt;


class ZPack: public QList<QByteArray> {
public:
    explicit ZPack(int id, const QString &topic, QString data): QList<QByteArray>() {
        append(topic.toLocal8Bit());
        append(QString("%1:%2:%3[%4]")
                .arg(topic)
                .arg(id)
                .arg(QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODate))
                .arg(data).toLocal8Bit());

    }

    explicit ZPack(int id, const QString &topic, int data): QList<QByteArray>() {
        append(topic.toLocal8Bit());
        append(QString("%1:%2:%3[%4]")
                .arg(topic)
                .arg(id)
                .arg(QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODate))
                .arg(data).toLocal8Bit());

    }


    explicit ZPack(int id, const QString &topic, double data): QList<QByteArray>() {
        append(topic.toLocal8Bit());
        append(QString("%1:%2:%3[%4]")
                .arg(topic)
                .arg(id)
                .arg(QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODate))
                .arg(data).toLocal8Bit());

    }

    explicit ZPack(int id, const QString &topic, bool data): QList<QByteArray>() {
        append(topic.toLocal8Bit());
        append(QString("%1:%2:%3[%4]")
                .arg(topic)
                .arg(id)
                .arg(QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODate))
                .arg(data).toLocal8Bit());

    }

};


using namespace simula;

using namespace dc;

quint64 ExecutorAPI::s_msg_counter = 0;

ExecutorAPI::ExecutorAPI(QObject *parent)
    : QObject(parent)
    , _stringValue()
    , _realValue(0.0)
    , _intValue(0)
    , _boolValue(false)
{
    qDebug() << "DistributedCommunicationAPI class instantiated";

    try {
        _zmq_context = createDefaultContext(this);
        _zmq_context->start();


        _zmq_socket = _zmq_context->createSocket(ZMQSocket::TYP_SUB, this);
        _zmq_socket->setObjectName("Publisher.Socket.socket(PUB)");
        connect(_zmq_socket, SIGNAL(messageReceived(const QList<QByteArray>&)), SLOT(messageReceived(const QList<QByteArray>&)));

        _zmq_socket->subscribeTo("tst");
        _zmq_socket->connectTo("tcp://127.0.0.1:1234");

    } catch (std::exception& ex) {
        qWarning() << ex.what();
        exit(-1);
    }
}

void ExecutorAPI::setStringValue(const QString &sv) {
    qDebug() << "DistributedCommunicationAPI recv string" << sv;
    if (sv != _stringValue) {
        _stringValue = sv;
        emit stringValueChanged();
    }
    publishString(sv);
}

QString ExecutorAPI::stringValue() const {
    return _stringValue;
}


void ExecutorAPI::setRealValue(double rv) {
    qDebug() << "DistributedCommunicationAPI recv double" << rv;
    if (rv != _realValue) {
        _realValue = rv;
        emit realValueChanged();
    }
    publishReal(rv);
}

double ExecutorAPI::realValue() const {
    return _realValue;
}


void ExecutorAPI::setIntValue(int iv) {
    qDebug() << "DistributedCommunicationAPI recv int" << iv;
    if (iv != _intValue) {
        _intValue = iv;
        emit intValueChanged();
    }
    publishInt(iv);
}

int ExecutorAPI::intValue() const {
    return _intValue;
}

void ExecutorAPI::setBoolValue(bool bv) {
    qDebug() << "DistributedCommunicationAPI recv bool" << bv;
    if (bv != _boolValue) {
        _boolValue = bv;
        emit boolValueChanged();
    }
    publishBool(bv);
}

bool ExecutorAPI::boolValue() const {
    return _boolValue;
}

int ExecutorAPI::doSomething(int i)
{
    qDebug() << "DistributedCommunicationAPI::doSomething()" << i;
    return i;
}

void ExecutorAPI::publishString(const QString &s)
{
//    ZPack msg(++s_msg_counter, "tst", s);
//    _zmq_socket->sendMessage(msg);
//    qDebug() << "publishString" << msg;
}

void ExecutorAPI::publishInt(int i)
{
//    ZPack msg(++s_msg_counter, "tst", i);
//    _zmq_socket->sendMessage(msg);
//    qDebug() << "publishString" << msg;
}

void ExecutorAPI::publishReal(double d)
{
//    ZPack msg(++s_msg_counter, "tst", d);
//    _zmq_socket->sendMessage(msg);
//    qDebug() << "publishString" << msg;
}

void ExecutorAPI::publishBool(bool b)
{
//    ZPack msg(++s_msg_counter, "tst", b);
//    _zmq_socket->sendMessage(msg);
    //    qDebug() << "publishString" << msg;
}

int ExecutorAPI::parseAndSet(const QList<QByteArray> &message)
{
    foreach (QByteArray ba, message) {
        qDebug() << "ExecutorAPI.mesage> " << ba;

    }

    QByteArray head = (message.count() >= 2) ? message.at(1) : "";
    qDebug() << "ExecutorAPI.mesage.head> " << head;

    QRegularExpression re("(?<inx>\\d+)\\\|(?<timestamp>\\S+)\\\[(?<value>.*)\\\]");

    QRegularExpressionMatch match = re.match(head);

    int inx = -1;
    QString ts("[unknown]");
    QString sval("notype:null");
    if (match.hasMatch()) {
        inx = match.captured("inx").toInt();
        ts = match.captured("timestamp");
        sval = match.captured("value");
    }

    QRegularExpression val_re("^(?<type>\\S+):(?<value>.*)$");
    QRegularExpressionMatch vmatch = val_re.match(sval);

    QString type("");
    QString value("");
    if (vmatch.hasMatch()) {
        type = vmatch.captured("type");
        value = vmatch.captured("value");
    }

    if (type == "string") {
        setStringValue(value);
    } else  if (type == "double") {
        setRealValue(value.toDouble());

    } else  if (type == "int") {
        setIntValue(value.toInt());

    } else  if (type == "bool") {
        setBoolValue(value == "true");

    } else {
        qDebug() << "Unknown type" << type << "value" <<  value;
    }
}


void ExecutorAPI::messageReceived(const QList<QByteArray> &message)
{
    qDebug() << "ExecutorAPI> " << message;

    parseAndSet(message);
/*
    if (message.first() == "string")

    if (message.first() == "real")
        setRealValue(message.last().toDouble());
*/
    //emit pingReceived(message);
}


