#include <QGuiApplication>

#include <QDebug>

#include <QQuickView>

#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQmlContext>

#include "source_api.h"

using namespace simula;
using namespace dc;

static SourceAPI *s_dcapi = nullptr;

static QObject *source_api_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    //QCoreApplication::arguments()

    if (!s_dcapi) {
        auto api = new SourceAPI("Publisher.Socket.socket(PUB)", "tcp://127.0.0.1:1234");


        return api;
    } else
        return s_dcapi;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterSingletonType<SourceAPI>(
        "com.unet.distributedcommunications", 1, 0, "SourceAPI",
        source_api_provider
    );

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
