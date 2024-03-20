#include "mainscreencontrol.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

void MainScreenControl::doStart() {
    QNetworkAccessManager manager;
    QUrl url("http://api.tvmaze.com/search/shows?q=girls");


    QNetworkRequest request(url);
    QNetworkReply* response = manager.get(request);

    QByteArray data;

    QObject::connect(response, &QNetworkReply::finished, [&]() {
        data = response->readAll();

        qDebug() << data;
    });

    QNetworkReply::NetworkError erro = response->error();
    qDebug() << response;

    qDebug() << data;
}
