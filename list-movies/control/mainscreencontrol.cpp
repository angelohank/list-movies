#include "mainscreencontrol.h"

#include <QDebug>

constexpr const char* URL = "http://api.tvmaze.com/search/shows?q=girls";

MainScreenControl::MainScreenControl( QObject* parent ) :
    QObject( parent ),
    _movies( {} ),
    _sessionDescription( "Em alta" ),
    _controller( new MovieController() ){}

void MainScreenControl::loadInitialMovies() {
    QObject::connect( &_requester, &NetworkRequester::requestFinished, this, &MainScreenControl::moviesConverter );

    //TODO tratar filtro aqui e a url em si fica no backend
    _requester.makeRequest( QUrl( URL ) );

}

void MainScreenControl::doStart() {
    loadInitialMovies();
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

int MainScreenControl::qtMovies() const {
    return _movies.size();
}

void MainScreenControl::moviesConverter( const QByteArray& data ) {
    _movies = _controller->moviesConverter( data );
    emit qtMoviesChanged();
}

QList<MovieModel*> MainScreenControl::search( const QString& filter ) {
    setSessionDescription( "Resultados" );
    return {};
}
