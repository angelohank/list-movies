import QtQuick 2.15

Row {
    id: root

    spacing: 10

    Rectangle {
        id: textField
        height: 30
        width: 240
        radius: 8
        color: "#DCDCDC"
    }

    ButtonCustom {
        id: searchButton

        height: textField.height
        width: textField.height

        onClicked: {
            //TODO: realizar filtro
        }
    }
}
