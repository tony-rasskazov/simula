#ifndef EXECUTOR_API_H
#define EXECUTOR_API_H

#include <QObject>

namespace nzmqt {
    class ZMQContext;
    class ZMQSocket;
}

namespace simula {

namespace dc {

class ExecutorAPI : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString stringValue READ stringValue WRITE setStringValue NOTIFY stringValueChanged)
    Q_PROPERTY(double realValue READ realValue WRITE setRealValue NOTIFY realValueChanged)
    Q_PROPERTY(int intValue READ intValue WRITE setIntValue NOTIFY intValueChanged)
    Q_PROPERTY(bool boolValue READ boolValue WRITE setBoolValue NOTIFY boolValueChanged)

    static quint64 s_msg_counter;

public:
    explicit ExecutorAPI(QObject *parent = 0);

    void setStringValue(const QString &sv);
    QString stringValue() const;

    void setRealValue(double rv);
    double realValue() const;

    void setIntValue(int iv);
    int intValue() const;

    void setBoolValue(bool bv);
    bool boolValue() const;

    Q_INVOKABLE int doSomething(int i);

    Q_INVOKABLE void publishString(const QString &s);
    Q_INVOKABLE void publishInt(int i);
    Q_INVOKABLE void publishReal(double d);
    Q_INVOKABLE void publishBool(bool b);

    Q_INVOKABLE int parseAndSet(const QList<QByteArray> &message);

signals:
    void stringValueChanged();
    void realValueChanged();
    void intValueChanged();
    void boolValueChanged();

    void pingReceived(const QList<QByteArray>& message);


protected slots:
    void messageReceived(const QList<QByteArray>& message);

private:


    nzmqt::ZMQContext* _zmq_context;
    nzmqt::ZMQSocket* _zmq_socket;

    QString _stringValue;
    double _realValue;
    int _intValue;
    int _boolValue;

};
}
}
#endif // EXECUTOR_API_H
