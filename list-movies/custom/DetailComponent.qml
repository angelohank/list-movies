import QtQuick 2.15

Rectangle {
    id: root

    width: 50
    height: 50

    property var modelData: undefined
    property string negativeAverage: "#b12b2c"
    property string positiveAverage: "#159d23"

    function generosToString() {

        if( root.modelData != undefined ) {
            var generos = ""

            for( var i = 0; i < root.modelData.show.generos.length; i++ ) {
                generos += root.modelData.show.generos[i]

                if ( i < root.modelData.show.generos.length - 1) {
                    generos += ", "
                }
            }
            return generos
        }
    }

    Column {
        id: container
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Rectangle {
            id: imageContainer

            height: parent.height * 0.5
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter

            Image {
                source: root.modelData.show.imagem
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
            }
        }

        Column {
            id: detailsContainer

            height: parent.height - imageContainer.height
            width: parent.width
            spacing: 8

            Text {
                id: average

                width: parent.width

                font {
                    pixelSize: 12
                    bold: true
                }

                anchors.left: parent.left
                text: root.modelData.show.average
                color: root.modelData.show.average > 6 ? positiveAverage : negativeAverage
            }

            Text {
                id: nome
                width: parent.width

                font {
                    pixelSize: 20
                    bold: true
                }

                anchors.left: parent.left
                text: root.modelData.show.nome
            }

            Text {
                id: generos
                text: root.generosToString()
                font.pixelSize: 10
            }

            Text {
                id: descricao

                width: parent.width

                font {
                    pixelSize: 12
                }

                anchors.left: parent.left
                text: root.modelData.show.descricao
                wrapMode: Text.WordWrap
                //todo deixar sempre alinhado
            }
        }
    }
}
