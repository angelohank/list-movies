#include "mainscreencontrol.h"

#include <QDebug>
#include "./controller/moviecontroller.h"

MainScreenControl::MainScreenControl( QObject* parent ) :
    QObject( parent ),
    _sessionDescription( "Em alta" ){}

void MainScreenControl::doStart() {
    QObject::connect( &_requester, &NetworkRequester::requestFinished, this, &MainScreenControl::moviesConverter );

    _requester.makeRequest( QUrl( "http://api.tvmaze.com/search/shows?q=girls" ) );

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

void MainScreenControl::moviesConverter( const QByteArray& data ) const {
    QList<MovieModel*> movies = MovieController().moviesConverter( data );

    qDebug() << movies;
}