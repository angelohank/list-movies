#include "moviemodel.h"

MovieModel::MovieModel() :
    _nota(0.00),
    _nome(""),
    _imagem(""),
    _descricao(""),
    _genero("") {}

double MovieModel::nota() const {
    return _nota;
}

void MovieModel::setNota(const double nota) {
    _nota = nota;
}

QString MovieModel::nome() const {
    return _nome;
}

void MovieModel::setNome(const QString &nome) {
    _nome = nome;
}

QString MovieModel::imagem() const {
    return _imagem;
}

void MovieModel::setImagem(const QString &path) {
    _imagem = path;
}

QString MovieModel::descricao() const {
    return _descricao;
}

QString MovieModel::genero() const {
    return _genero;
}

void MovieModel::setGenero(const QString &genero) {
    _genero = genero;
}
