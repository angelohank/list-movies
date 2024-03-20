#include "networkrequester.h"

#include <QEventLoop>

NetworkRequester::NetworkRequester( QObject *parent ) :
    QObject( parent ) {}

void NetworkRequester::makeRequest( const QUrl& url ) {
    QNetworkRequest request( url );

    QNetworkReply* response = manager.get( request );

    QEventLoop eventLoop;
    QObject::connect( &manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit())  );
    eventLoop.exec();

    if( !response ) {
        qDebug() << response->error();
        return;
    }

    emit requestFinished( response->readAll() );
    delete( response );
}
