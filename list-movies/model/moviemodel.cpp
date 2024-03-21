#include "moviemodel.h"

MovieModel::MovieModel() :
    _show( nullptr ) {}

MovieModel::MovieModel( const double score, ShowModel* show ) :
    _score( score ),
    _show( show ) {}

double MovieModel::score() const {
    return _score;
}

void MovieModel::setScore( const double score ) {
    _score = score;
    emit scoreChanged();
}

ShowModel* MovieModel::show() const {
    return _show;
}

void MovieModel::setShow( ShowModel* show ) {
    _show = show;
    emit showChanged();
}

