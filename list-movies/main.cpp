#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <control/mainscreencontrol.h>
#include <control/detailscreencontrol.h>
#include <model/moviemodel.h>
#include <model/showmodel.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<MainScreenControl>("MainScreenControl", 1 ,0, "MainScreenControl");
    qmlRegisterType<DetailScreenControl>("DetailScreenControl", 1 ,0, "DetailScreenControl");

    qmlRegisterType<MovieModel*>("MovieModel", 1 ,0, "MovieModel");
    qmlRegisterType<ShowModel*>("ShowModel", 1 ,0, "ShowModel");

    engine.load(url);

    return app.exec();
}
