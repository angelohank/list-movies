#include "mainscreencontrol.h"

#include <QDebug>

constexpr const char* URL = "http://api.tvmaze.com/search/shows?q=girls";

MainScreenControl::MainScreenControl( QObject* parent ) :
    QObject( parent ),
    _sessionDescription( "Em alta" ),
    _controller( new MovieController() ){}

void MainScreenControl::doStart() {

    //isolar em function loadMovies
    QObject::connect( &_requester, &NetworkRequester::requestFinished, this, &MainScreenControl::moviesConverter );

    //TODO tratar filtro aqui e a url em si fica no backend
    _requester.makeRequest( QUrl( URL ) );

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

void MainScreenControl::moviesConverter( const QByteArray& data ) {
    QList<MovieModel*> movies = _controller->moviesConverter( data );
}

QList<MovieModel*> MainScreenControl::search(const QString& filter) {
    return {};
}
