#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include <QObject>
class MovieModel : public QObject {
public:
    MovieModel();

    double nota() const;
    void setNota( const double nota );

    QString nome() const;
    void setNome( const QString& nome );

    QString imagem() const;
    void setImagem( const QString& path );

    QString descricao() const;
    void setDescricao( const QString& descricao );

    QString genero() const;
    void setGenero( const QString& genero );

private:
    double _nota;
    QString _nome;
    QString _imagem;
    QString _descricao;
    QString _genero;
};

#endif // MOVIEMODEL_H
