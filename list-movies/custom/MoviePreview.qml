import QtQuick 2.15

MouseArea {
    id: root
    height: 70
    width: 240

    signal selected

    onClicked: {
        //TODO implementar
    }

    property string src: ""
    property string name: "Nome"
    property string average: "average"

    Rectangle {
        id: externalContainer

        anchors.fill: parent
        color: "#e0dbff"

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
                        font {
                            bold: true
                            pixelSize: 18
                        }
                        anchors.right: parent.right
                        rightPadding: 10
                    }

                    Text {
                        id: average
                        text: root.average
                        font.pixelSize: 15
                        anchors.right: parent.right
                        rightPadding: 10
                    }
                }
            }
        }
    }
}

