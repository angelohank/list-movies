#include "mainscreencontrol.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

MainScreenControl::MainScreenControl( QObject* parent ) :
    QObject( parent ),
    _sessionDescription( "Em alta" ){}

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

QString MainScreenControl::sessionDescription() const {
    return _sessionDescription;
}

void MainScreenControl::setSessionDescription( const QString &sessionDescription ) {
    if( _sessionDescription == sessionDescription ) {
        return;
    }

    _sessionDescription = sessionDescription;
    emit sessionDescriptionChanged();
}
