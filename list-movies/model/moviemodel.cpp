#include "moviemodel.h"

MovieModel::MovieModel() :
    _show( nullptr ) {}

double MovieModel::score() const {
    return _score;
}

void MovieModel::setScore( const double score ) {
    _score = score;
}

ShowModel *MovieModel::show() const {
    return _show;
}

void MovieModel::setShow( ShowModel* show ) {
    _show = show;
}

