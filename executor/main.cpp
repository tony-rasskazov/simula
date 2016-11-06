#include <QGuiApplication>

#include <QDebug>

#include <QQuickView>

#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQmlContext>

#include "executor_api.h"

using namespace simula;
using namespace dc;


static simula::dc::ExecutorAPI *s_dcapi = nullptr;

static QObject *executor_api_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    if (!s_dcapi)
        return new ExecutorAPI();
    else
        return s_dcapi;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterSingletonType<ExecutorAPI>(
        "com.unet.distributedcommunications", 1, 0, "ExecutorAPI",
        executor_api_provider
    );

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
