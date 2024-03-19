import QtQuick 2.15

MouseArea {
    id: root

    property string pressedColor: "#6959CD"
    property string unpressedColor: "#836FFF"

    Rectangle {
        id: button

        anchors.fill: parent

        radius: 8
        color: unpressedColor

        //TODO: adicionar icone
        Image {
            anchors.centerIn: parent
        }
    }

    onContainsPressChanged: {
        button.color = root.containsPress ? pressedColor : unpressedColor
    }
}


