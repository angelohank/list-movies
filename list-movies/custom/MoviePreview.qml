import QtQuick 2.15

MouseArea {
    id: root
    height: 70
    width: 240

    signal selected

    onClicked: {
        root.selected()
    }

    property string src: ""
    property string name: ""
    property string average: ""

    Rectangle {
        id: externalContainer

        anchors.fill: parent
        color: "#B50000"

        Row {
            id: internalContainer
            anchors.fill: parent
            spacing: 10

            Rectangle {
                id: imageContainer

                width: parent.width * 0.4
                height: parent.height
                color: "transparent"

                Image {
                    source: root.src
                    anchors {
                        fill: parent
                        margins: 10
                    }

                    fillMode: Image.PreserveAspectCrop
                }
            }

            Rectangle {
                id: detailContainer

                width: parent.width - ( imageContainer.width + container.spacing )
                height: parent.height
                color: "transparent"

                Column {

                    anchors.fill: parent
                    spacing: 8

                    Text {
                        id: name
                        text: root.name
                        width: detailContainer.width
                        font {
                            bold: true
                            pixelSize: 15
                        }
                        anchors {
                            right: parent.right
                            topMargin: 10
                        }

                        rightPadding: 10
                        wrapMode: Text.WordWrap
                    }

                    //TODO criar um retangulo em volta da avaliacao para ficar mais bonito
                    Text {
                        id: average
                        text: root.average > 0 ? root.average : "Não avaliado"
                        font.pixelSize: 15
                        anchors.right: parent.right
                        rightPadding: 10
                    }
                }
            }
        }
    }
}

