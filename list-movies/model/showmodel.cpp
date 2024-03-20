#include "showmodel.h"

ShowModel::ShowModel()
{}

double ShowModel::average() const {
    return _average;
}

void ShowModel::setAverage( const double average ) {
    _average = average;
}

QString ShowModel::nome() const {
    return _nome;
}

void ShowModel::setNome( const QString& nome ) {
    _nome = nome;
}

QString ShowModel::imagem() const {
    return _imagem;
}

void ShowModel::setImagem( const QString& path ) {
    _imagem = path;
}

QString ShowModel::descricao() const {
    return _descricao;
}

QList<QString> ShowModel::generos() const {
    return _generos;
}

void ShowModel::setGeneros( const QList<QString>& generos) {
    _generos = generos;
}
