#include "mainscreencontrol.h"

#include <QObject>
#include <QDebug>
#include <QList>

constexpr const char* EM_ALTA = "EM ALTA";

MainScreenControl::MainScreenControl( QObject* parent ) :
    QObject( parent ),
    _movie( nullptr ),
    _initialMovies( {} ),
    _movies( {} ),
    _sessionDescription( EM_ALTA ),
    _controller( new MovieController() ){}

void MainScreenControl::loadInitialMovies() {    
    _initialMovies =_controller->searchInitialMovies();
}

QList<QObject*> MainScreenControl::moviesToObject( QList<MovieModel*> movies ) const {
    QList<QObject*> movieObjects = {};

    for( MovieModel* movie : _movies ) {
        QObject* object = qobject_cast<QObject*>( movie );

        if( object ) {
            movieObjects.append( movie );
        }
    }

    return movieObjects;
}

void MainScreenControl::doStart() {
    setSessionDescription( EM_ALTA );

    if( _initialMovies.size() < 1 ) {
        loadInitialMovies();
    }

    setMovies( _initialMovies );
    emit movies( moviesToObject( _initialMovies ) );
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

void MainScreenControl::search( const QString& filter ) {
    setSessionDescription( "Resultados" );
    _movies = _controller->searchWithParamns( filter );

    QList<QObject*> movieObjects = moviesToObject( _movies );

    emit movies( movieObjects );
}

QList<MovieModel*> MainScreenControl::movieList() const {
    return _movies;
}

void MainScreenControl::selectedMovie( const int index ) {
    qDebug() << index;

    _movie = movieList().at( index );

    QObject* movieObject = qobject_cast<QObject*>( _movie );

    emit showDetail( movieObject );
}

void MainScreenControl::setMovies( QList<MovieModel*>& movies) {
    _movies = movies;
    emit moviesChanged();
}
