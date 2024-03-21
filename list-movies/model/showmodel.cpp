#include "showmodel.h"

ShowModel::ShowModel()
{}

ShowModel::ShowModel(const QString& nome, const QString& imagem, const QString& descricao) :
    _nome( nome ),
    _imagem( imagem ),
    _descricao( descricao ) {}

double ShowModel::average() const {
    return _average;
}

void ShowModel::setAverage( const double average ) {
    _average = average;
    emit averageChanged();
}

QString ShowModel::nome() const {
    return _nome;
}

void ShowModel::setNome( const QString& nome ) {
    _nome = nome;
    emit nomeChanged();
}

QString ShowModel::imagem() const {
    return _imagem;
}

void ShowModel::setImagem( const QString& path ) {
    _imagem = path;
    emit imagemChanged();
}

QString ShowModel::descricao() const {
    return _descricao;
}

void ShowModel::setDescricao(const QString& descricao) {
    _descricao = descricao;
    emit descricaoChanged();
}

QList<QString> ShowModel::generos() const {
    return _generos;
}

void ShowModel::setGeneros( const QList<QString>& generos) {
    _generos = generos;
}
