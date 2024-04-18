import QtQuick 2.15

MouseArea {
    id: root

    property string pressedColor: "#870000"
    property string unpressedColor: "#B50000"
    property string src: ""


    Rectangle {
        id: button

        anchors.fill: parent

        radius: 8
        color: unpressedColor

        Image {
            anchors.centerIn: parent
            source: root.src
            fillMode: Image.PreserveAspectFit
            height: parent.height * 0.6
            width: parent.width * 0.6
        }
    }

    onContainsPressChanged: {
        button.color = root.containsPress ? pressedColor : unpressedColor
    }
}


